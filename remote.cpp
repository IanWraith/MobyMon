// remote.cpp : implementation file
//

#include "stdafx.h"
#include "mobymon.h"
#include "remote.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// remote dialog


remote::remote(CWnd* pParent /*=NULL*/)
	: CDialog(remote::IDD, pParent)
{
	//{{AFX_DATA_INIT(remote)
	m_server_name = _T("");
	//}}AFX_DATA_INIT
}


void remote::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(remote)
	DDX_Text(pDX, IDC_EDIT2, m_server_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(remote, CDialog)
	//{{AFX_MSG_MAP(remote)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// remote message handlers

void remote::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void remote::OnOK() 
{
char a;
int b;
// put the CString m_server_name into char s //
CDialog::OnOK();

b=m_server_name.GetLength()-1;
for (a=0;a<=b;a++)
 s[a]=m_server_name.GetAt(a);

s[a]=0;

}
