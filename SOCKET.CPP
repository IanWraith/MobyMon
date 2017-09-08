#include "stdafx.h"
#include "socket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// QSocket

#define SET_ERROR_VARS() SetErrorVars(__FILE__, __LINE__)     

QSocket::QSocket(BOOL create_socket)
  : CurrentStatus(UNINITIALIZED), ReceiveWindow(0), 
   ReceiveMessage(0), RawSendData(0), RawSendDataLength(0)
{   
	if (create_socket)
	{
		if (Start())
		{
	    	CurrentStatus = DISCONNECTED;
		}
	}
}

QSocket::~QSocket()
{
	Disconnect();
	// cleanup with winsock dll
}


/////////////////////////////////////////////////////////////////////////////
// QSocket message handlers



BOOL QSocket::Start()
{                       
   	if (!Socket())
    {
   		SET_ERROR_VARS();
   		ErrorString = "Unable to open a new socket.";
   		CurrentStatus = ERRORSTATE;
		DisplayError();
   		return FALSE;
    }                     

	return TRUE;
}               

int QSocket::SetErrorVars(char *file, int line) 
{              
	int err = GetLastError();
	
	char *str_buffer = ErrorString.GetBuffer(200);
	                           
	sprintf(str_buffer, "Error: %d -- %s %d", err, file, line);
	CurrentStatus = ERRORSTATE;
	// our status just changed
	// send message if we are sending to another window
	DisplayError();
	if (ReceiveWindow)
	{
		ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
 										(LPARAM)0);
	}
	
    return err;
}               
 
void QSocket::DisplayError()
{
	AfxMessageBox(ErrorString,MB_OK|MB_ICONSTOP);
}

BOOL QSocket::Disconnect(void)
{

	// allow socket related messages to be processed 
	// before disconnect
	for (;;)
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) && msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) )
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}                         
		else
		{
			break;
		}
	}

	// We don't just call CSocket::Close() because we want to 
	// disable non-blocking mode before the closesocket() is 
	// called in the CAsyncSocket::Close().
	// We disable the non-blocking mode so that when we have
	// linger on we will block rather than return a WSAEWOULDBLOCK.
	unsigned long nbIO = 0;
	CancelBlockingCall();
	AsyncSelect(0);
	
	// disable non-blocking mode
	ioctlsocket(m_hSocket, FIONBIO, &nbIO);   

	CAsyncSocket::Close();
	m_hSocket = INVALID_SOCKET;

 	return TRUE;
}

void QSocket::Linger(void)
{
	int what = 0;
	struct linger sL;
	sL.l_onoff = 1;
	sL.l_linger = 30;

	what = SetSockOpt(SO_LINGER, (char *)&sL, sizeof(sL));

	if (what == SOCKET_ERROR)
	{
		SET_ERROR_VARS();
	}
}

BOOL QSocket::SetReceiveTarget(CWnd *window, UINT message)
{                           
	// sets who to send all received data to
	ReceiveWindow = window;
	ReceiveMessage = message;               
	
	// clear receive buffer as the data must be left over
	ReceiveLines.RemoveAll();
	RemainingReceive = "";

	// setup AsyncSelect
	switch (CurrentStatus)
	{
		case CONNECTED:
		    if (!AsyncSelect(FD_READ | FD_WRITE | FD_CLOSE ))
    		{       
   				SET_ERROR_VARS();
	   			return FALSE; 	
		    }
			break;

		case LISTENING:
		    if (!AsyncSelect(FD_ACCEPT ))
    		{       
   				SET_ERROR_VARS();
	   			return FALSE; 	
		    }
			break;

		default:
		    if (!AsyncSelect(FD_CONNECT | FD_CLOSE ))
    		{       
   				SET_ERROR_VARS();
	   			return FALSE; 	
		    }
			break;
	}

	return TRUE;
}

void QSocket::Send(const CString& data)
{
	if (data.GetLength() == 0)
	{
		return;
	}

	BOOL send_buffer_empty = SendLines.IsEmpty();

	SendLines.AddTail(data);
	
	if (send_buffer_empty)
	{
		int amt = SendLines.GetHead().GetLength();
		
 		amt = CAsyncSocket::Send(SendLines.GetHead(), amt, 0);	
		if (amt == SOCKET_ERROR)
		{
			int error = GetLastError();
			if (error != WSAEWOULDBLOCK && error != WSAEINPROGRESS)
			{
				SET_ERROR_VARS();
			}
		}                      
		else
		{
			if (amt == SendLines.GetHead().GetLength())
			{
				SendLines.RemoveHead();
			}
			else
			{
				// only part of line was sent leave rest for later
				const char *head = SendLines.GetHead();
				strcpy((char *)head, head+amt);
			}
		}
	}
}

void QSocket::WaitUntilSendBufferEmpty()
{
	// Pump messages until all lines sent
	while(!SendLines.IsEmpty() && RawSendDataLength)
	{
		for (;;)
		{
			MSG msg;
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}                         
			else
			{
				break;
			}
		}
	}
}

void QSocket::SendRaw(const void *data, const int dataLen)
{
	char *sdata = new char[RawSendDataLength + dataLen];
	memcpy(sdata, RawSendData, RawSendDataLength);
	memcpy(sdata+RawSendDataLength, data, dataLen);
	delete RawSendData;
	RawSendData = sdata;

	RawSendDataLength += dataLen;

	while(RawSendDataLength > 0)
	{
		int amt_sent = CAsyncSocket::Send((char *)RawSendData, RawSendDataLength, 0);
		if (amt_sent == SOCKET_ERROR)
		{
			int error = GetLastError();
			if (error != WSAEWOULDBLOCK && error != WSAEINPROGRESS)
			{
				SET_ERROR_VARS();
			}
			break;
		}
		else
		{
			RawSendDataLength -= amt_sent;
			memcpy(RawSendData, RawSendData+amt_sent, RawSendDataLength);
		}
	}

}

void QSocket::AddToReceive(const char *buffer, int amt)
{
	char temp[SOCK_BLOCK_SIZE+1];
	
	int cur_pos = 0;
	while (cur_pos < amt)
	{
		char *lf = strchr(buffer+cur_pos, '\n');
		int length;
					
		if (lf)
		{
			length = lf-buffer-cur_pos+1;
		}
		else
		{
			length = amt - cur_pos;
		}
					
		strncpy(temp, buffer+cur_pos, length);
		temp[length] = 0;            
		
		if (lf)
		{				                  
			// we have a linefeed so add string
			if (RemainingReceive.IsEmpty())
			{
				ReceiveLines.AddTail(temp);
			}                            
			else
			{
				ReceiveLines.AddTail(RemainingReceive+temp);
				RemainingReceive.Empty();
			}
 		}
 		else
 		{
 			// we don't have a linefeed so add to RemainingReceive
 			// for future use
 			RemainingReceive += temp;
 		}
 		cur_pos += length;
	}
}
				
CString QSocket::GetLine(void)
{                                            
	if (ReceiveWindow)
	{
		// we are in the wrong mode to use GetLine()
		return "";
	}

	while(CurrentStatus == CONNECTED && ReceiveLines.IsEmpty())
	{
 		char temp[SOCK_BLOCK_SIZE+1];
	 	int amt = Receive(temp, SOCK_BLOCK_SIZE, 0);
 		if (amt == SOCKET_ERROR)
	 	{                                              
 				SET_ERROR_VARS();
	 	}
		else if (amt == 0)
		{
			OnClose(0);
		}
 		else
	 	{   
			temp[amt] = 0; 
			// add to buffer we are using GetLine() mode
			AddToReceive(temp, amt);
  		}
	}

	if (!ReceiveLines.IsEmpty())
	{       
		return ReceiveLines.RemoveHead();
	}
	else
	{
		return "";
	}
} 

BOOL QSocket::Listen(int back_log /* = 5 */)
{
	if (ReceiveWindow != NULL)
	{
		// receiving callbacks when status changes so setup AsyncSelect
	    if (!AsyncSelect(FD_ACCEPT))
    	{       
   			SET_ERROR_VARS();
	   		return FALSE; 	
    	}
	}

	if (!CAsyncSocket::Listen(back_log))
	{                                          
		SET_ERROR_VARS();
		return FALSE;
	}
	
	CurrentStatus = LISTENING;

	return TRUE;
}

QSocket *QSocket::Accept()
{
	QSocket *return_socket = new QSocket(FALSE);

	// do not get the address of remote end. 
	if (!CSocket::Accept(*return_socket, NULL, NULL))
	{
		delete return_socket;
		return_socket = 0;
		SET_ERROR_VARS();
	}

	return_socket->CurrentStatus = CONNECTED;
	return return_socket;
}

void QSocket::OnReceive(int error)
{
 	// Ready to read
 	char temp[SOCK_BLOCK_SIZE+1];
 	int amt = CAsyncSocket::Receive(temp, SOCK_BLOCK_SIZE, 0);

 	if (amt == SOCKET_ERROR)
 	{                                              
 		error = GetLastError();
 		if (error != WSAEWOULDBLOCK && error != WSAEINPROGRESS)
 		{
 			SET_ERROR_VARS();
 		}
 	}
 	else
 	{   
		temp[amt] = 0; 
 		if (ReceiveWindow)
 		{                                               
 			// send to window
 			ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)amt,
 								(LPARAM)(LPSTR)temp);
 		}
 		else
 		{
 			// add to buffer we are using GetLine() mode
			AddToReceive(temp, amt);
		}
  	}
 	
}

void QSocket::OnWrite(int error)
{
	// Ready to write
	if (RawSendDataLength)
	{
		while(RawSendDataLength > 0)
		{
			int amt_sent = CAsyncSocket::Send((char *)RawSendData, RawSendDataLength, 0);
			if (amt_sent == SOCKET_ERROR)
			{
				int error = GetLastError();
				if (error != WSAEWOULDBLOCK && error != WSAEINPROGRESS)
				{
					SET_ERROR_VARS();
				}
				break;
			}
			else
			{
				RawSendDataLength -= amt_sent;
				memcpy(RawSendData, RawSendData+amt_sent, RawSendDataLength);
			}
		}
	} 
	else if (!SendLines.IsEmpty())
	{
		int amt = SendLines.GetHead().GetLength();
		
		amt = CAsyncSocket::Send(SendLines.GetHead(), amt, 0);	
		if (amt == SOCKET_ERROR)
		{
			int error = GetLastError();
			if (error != WSAEWOULDBLOCK && error != WSAEINPROGRESS)
			{
				SET_ERROR_VARS();
			}
		}                      
		else
		{
			if (amt == SendLines.GetHead().GetLength())
			{
				SendLines.RemoveHead();
			}
			else
			{
				// only part of line was sent leave rest for later
				const char *head = SendLines.GetHead();
				strcpy((char *)head, head+amt);
			}
		}
	}
}

void QSocket::OnAccept(int error)
{
	// Connection request has arrived
	if (CurrentStatus != LISTENING)
	{
		ErrorString = "FD_RACCEPT when not in status LISTENING";
		ASSERT(FALSE); 				
	}   
	else
	{
		if (error == 0)
		{
			QSocket *new_socket = Accept();

			if (new_socket)
			{
				if (ReceiveWindow)
				{
					ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)NewSocketAccepted,
									(LPARAM)new_socket);
				}
				else
				{
					ErrorString = "Received Async FD_ACCEPT without a target to get new QSocket";
					ASSERT(FALSE);
				}
			}
		}                             
		else
 		{
			char *str_buffer = ErrorString.GetBuffer(200);
	                           
			sprintf(str_buffer, "Error: %d -- %s %d", error, __FILE__, __LINE__);
			CurrentStatus = ERRORSTATE;
			// our status just changed
			// send message if we are sending to another window
			DisplayError();
			if (ReceiveWindow)
			{
				ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
									(LPARAM)0);
			}
 		}
 	}
}

void QSocket::OnConnect(int error)
{
 	// Completed connection
 	if (CurrentStatus != CONNECTING)
 	{
 		ErrorString = "FD_CONNECT received when not in status CONNECTING"; 				
 	}   
 	else
 	{
 		if (error == 0)
 		{
		    if (!AsyncSelect(FD_READ | FD_WRITE | FD_CLOSE ))
			{       
				SET_ERROR_VARS();
				return; 	
			}
			CurrentStatus = CONNECTED;
			// our status just changed
			// send message if we are sending to another window
			if (ReceiveWindow)
			{
				ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
									(LPARAM)0);
			}
		}                             
		else
		{
			char *str_buffer = ErrorString.GetBuffer(200);
	                           
			sprintf(str_buffer, "Error: %d -- %s %d", error, __FILE__, __LINE__);
			CurrentStatus = ERRORSTATE;
			// our status just changed
			// send message if we are sending to another window
			DisplayError();
			if (ReceiveWindow)
			{
				ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
									(LPARAM)0);
			}
		}
	}
}

void QSocket::OnClose(int error)
{
	// Socket closed
	CurrentStatus = DISCONNECTED;
	// our status just changed
	// send message if we are sending to another window
	if (ReceiveWindow)
	{
		ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
									(LPARAM)0);
	}
}

BOOL QSocket::ConnectHelper(const SOCKADDR* lpSockAddr, int nSockAddrLen)
{
  	CurrentStatus = CONNECTING;

    if (!AsyncSelect(FD_CONNECT))
    {       
   		SET_ERROR_VARS();
   		return FALSE; 	
    }

	if (connect(m_hSocket, lpSockAddr, nSockAddrLen) == SOCKET_ERROR)
	{
		int err = GetLastError();
		if (err != WSAEWOULDBLOCK)
		{
			SET_ERROR_VARS();
			return FALSE;
		}
	}                    
	else
	{
	    if (!AsyncSelect(FD_READ | FD_WRITE | FD_CLOSE ))
    	{       
   			SET_ERROR_VARS();
   			return FALSE; 	
	    }
	    
		CurrentStatus = CONNECTED;
		if (ReceiveWindow)
		{
			ReceiveWindow->SendMessage(ReceiveMessage, (WPARAM)SocketStatusChanged,
										(LPARAM)0);
		}
 	}
    
	return TRUE;
}

