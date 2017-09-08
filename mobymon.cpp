// mobymon.cpp : Defines the class behaviors for the application.
//
#include "stdafx.h"
#include "mobymon.h"
#include "MainFrm.h"
#include "mobymonDoc.h"
#include "mobymonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Other objects //
CFile logout;

// All static variables here //
DCB moby::dcb;
HANDLE moby::hcom;
COMMTIMEOUTS moby::commtimeouts;

char moby::id[200];
char moby::s0[300];
char moby::s1[300];
char moby::s2[300];
char moby::s3[300];
char moby::s4[300];
char moby::s5[300];
char moby::s6[300];
char moby::s7[300];
char moby::s8[300];
char moby::s9[300];
char moby::s10[300];
char moby::s11[300];
char moby::s12[300];
char moby::s13[300];
char moby::s14[300];
char moby::s15[300];
char moby::s16[300];
char moby::s17[300];
char moby::s18[300];
char moby::s19[300];
char moby::s20[300];
char moby::s21[300];
char moby::s22[300];
char moby::s23[300];
char moby::s24[300];
char moby::s25[300];
char moby::s26[300];
char moby::s27[300];
char moby::s28[300];
char moby::s29[300];
char moby::s30[300];
char moby::s31[300];
char moby::s32[300];
char moby::s33[300];
char moby::s34[300];
char moby::s35[300];
char moby::s36[300];
char moby::s37[300];
char moby::s38[300];
char moby::s39[300];
char moby::s40[300];
char moby::s41[300];
char moby::s42[300];
char moby::s43[300];
char moby::s44[300];
char moby::s45[300];
char moby::s46[300];
char moby::s47[300];
char moby::s48[300];
char moby::s49[300];
char moby::s50[300];
char moby::s51[300];
char moby::s52[300];
char moby::s53[300];
char moby::s54[300];
char moby::s55[300];
char moby::s56[300];
char moby::s57[300];
char moby::s58[300];
char moby::s59[300];
char moby::s60[300];
char moby::s61[300];
char moby::s62[300];
char moby::s63[300];
char moby::s64[300];
char moby::s65[300];
char moby::s66[300];
char moby::s67[300];
char moby::s68[300];
char moby::s69[300];
char moby::s70[300];
char moby::s71[300];
char moby::s72[300];
char moby::s73[300];
char moby::s74[300];
char moby::s75[300];
char moby::s76[300];
char moby::s77[300];
char moby::s78[300];
char moby::s79[300];
char moby::s80[300];
char moby::s81[300];
char moby::s82[300];
char moby::s83[300];
char moby::s84[300];
char moby::s85[300];
char moby::s86[300];
char moby::s87[300];
char moby::s88[300];
char moby::s89[300];
char moby::s90[300];
char moby::s91[300];
char moby::s92[300];
char moby::s93[300];
char moby::s94[300];
char moby::s95[300];
char moby::s96[300];
char moby::s97[300];
char moby::s98[300];
char moby::s99[300];
char moby::s100[300];
char moby::s101[300];
char moby::s102[300];
char moby::s103[300];
char moby::s104[300];
char moby::s105[300];
char moby::s106[300];
char moby::s107[300];
char moby::s108[300];
char moby::s109[300];
char moby::s110[300];
char moby::s111[300];
char moby::s112[300];
char moby::s113[300];
char moby::s114[300];
char moby::s115[300];
char moby::s116[300];
char moby::s117[300];
char moby::s118[300];
char moby::s119[300];


char moby::ready=0;
BOOL moby::scr[512];
char moby::ts[30];
char moby::s[300];
unsigned char moby::by[900];

unsigned char moby::b0;
unsigned char moby::b1;
unsigned char moby::b2;
unsigned char moby::b3;
unsigned char moby::b4;
unsigned char moby::b5;
unsigned char moby::b6;
unsigned char moby::b7;
unsigned char moby::b8;
unsigned char moby::b9;
unsigned char moby::b10;
unsigned char moby::b11;
unsigned char moby::b12;
unsigned char moby::b13;
unsigned char moby::b14;
unsigned char moby::b15;
unsigned char moby::b16;
unsigned char moby::b17;
unsigned char moby::b18;
unsigned char moby::b19;
unsigned char moby::b20;
unsigned char moby::b21;
unsigned char moby::b22;
unsigned char moby::b23;
unsigned char moby::b24;
unsigned char moby::b25;
unsigned char moby::b26;
unsigned char moby::b27;
unsigned char moby::b28;
unsigned char moby::b29;
unsigned char moby::b30;


BOOL moby::blk[70][241];
unsigned char moby::octet;
unsigned char moby::sequence;
char moby::enc[5];
char moby::com_port=0;
char moby::user_name[100];
unsigned char moby::f;
unsigned char moby::bcounter;
unsigned char moby::blocks;
unsigned char moby::state;
unsigned long moby::system;
unsigned long moby::sender;
unsigned long moby::mob;
unsigned long moby::address;
unsigned long moby::blacklist=0;
unsigned int moby::s_pos;
unsigned char moby::no_addr;
unsigned char moby::frame;
unsigned char moby::surrounding=0;

float moby::total_blocks;
float moby::bad_blocks;
float moby::upf[16];
float moby::dof[16];

BOOL moby::comportsetup=FALSE;
BOOL moby::logging=FALSE;
BOOL moby::data_show=TRUE;
BOOL moby::hpdata_user_show=TRUE;
BOOL moby::hpdata_mtp1_show=TRUE;
BOOL moby::hpdata_messaging_show=TRUE;
BOOL moby::hpdata_gateway_show=TRUE;
BOOL moby::hpdata_ramp_show=TRUE;
BOOL moby::hpdata_rnm_show=TRUE;
BOOL moby::time_show=TRUE;
BOOL moby::grouplist_show=TRUE;
BOOL moby::flexlist_show=TRUE;
BOOL moby::status_show=TRUE;
BOOL moby::esnreq_show=TRUE;
BOOL moby::text_show=TRUE;
BOOL moby::extpak_show=TRUE;
BOOL moby::inforeq_show=TRUE;
BOOL moby::live_show=TRUE;
BOOL moby::die_show=TRUE;
BOOL moby::logingra_show=TRUE;
BOOL moby::loginref_show=TRUE;
BOOL moby::logoutord_show=TRUE;
BOOL moby::roamord_show=TRUE;
BOOL moby::flexreq_show=TRUE;
BOOL moby::sos_show=TRUE;
BOOL moby::sosack_show=TRUE;
BOOL moby::sosinfo_show=TRUE;
BOOL moby::sosconfast_show=TRUE;
BOOL moby::sosconreq_show=TRUE;
BOOL moby::arealist_show=TRUE;
BOOL moby::addconfast_show=TRUE;
BOOL moby::confast_show=TRUE;
BOOL moby::cloopoff_show=TRUE;
BOOL moby::cloopon_show=TRUE;
BOOL moby::discon_show=TRUE;
BOOL moby::conord_show=TRUE;
BOOL moby::congra_show=TRUE;
BOOL moby::addconreq_show=TRUE;
BOOL moby::conreq_show=TRUE;
BOOL moby::data_ascii_show=FALSE;
BOOL moby::hpdata_130_show=FALSE;
BOOL moby::extpak_ascii_show=FALSE;
BOOL moby::sos_ascii_show=FALSE;
BOOL moby::sosinfo_ascii_show=FALSE;
BOOL moby::display_traffic_state=FALSE;
BOOL moby::ignore_ok_state=FALSE;
BOOL moby::ignore_from_mail_state=FALSE;
BOOL moby::ignore_in_mail_state=FALSE;
BOOL moby::ignore_no_transfer_state=FALSE;
BOOL moby::ignore_illegal_state=FALSE;
BOOL moby::ignore_congest_state=FALSE;
BOOL moby::ignore_error_state=FALSE;
BOOL moby::ignore_busy_state=FALSE;
BOOL moby::debug=FALSE;
BOOL moby::sequence_display=FALSE;
BOOL moby::use_ignore=FALSE;
BOOL moby::use_exclusive=FALSE;
BOOL moby::re_display=FALSE;
BOOL moby::am_a_server=FALSE;
BOOL moby::am_a_terminal=FALSE;
BOOL moby::base_mon=TRUE;
BOOL moby::multi_add=FALSE;
BOOL moby::loginreq_show=TRUE;
BOOL moby::logout_show=TRUE;
BOOL moby::born_show=TRUE;
BOOL moby::active_show=TRUE;
BOOL moby::inactive_show=TRUE;
BOOL moby::roam_show=TRUE;
BOOL moby::vicesosrx_show=TRUE;
BOOL moby::sosrx_show=TRUE;
BOOL moby::info_show=TRUE;
BOOL moby::esninfo_show=TRUE;
BOOL moby::extconreq_show=TRUE;
BOOL moby::conrea_show=TRUE;
BOOL moby::lineon_show=TRUE;
BOOL moby::lineoff_show=TRUE;
BOOL moby::linsel_show=TRUE;
BOOL moby::head_rxed=FALSE;
BOOL moby::enable_checking=TRUE;
BOOL moby::enable_fec=FALSE;
BOOL moby::display_mrm=TRUE;
BOOL moby::display_ack=TRUE;
BOOL moby::display_nak=TRUE;
BOOL moby::display_reb=TRUE;
BOOL moby::display_res=TRUE;
BOOL moby::display_abd=TRUE;
BOOL moby::display_atd=TRUE;
BOOL moby::display_atl=TRUE;
BOOL moby::display_bkd=TRUE;
BOOL moby::display_fri=TRUE;
BOOL moby::display_svp=TRUE;
BOOL moby::display_tst=TRUE;
BOOL moby::display_akt=TRUE;
BOOL moby::display_abl=TRUE;

/////////////////////////////////////////////////////////////////////////////
// CMobymonApp

BEGIN_MESSAGE_MAP(CMobymonApp, CWinApp)
	//{{AFX_MSG_MAP(CMobymonApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMobymonApp construction

CMobymonApp::CMobymonApp()
{
// TODO: add construction code here,
// Place all significant initialization in InitInstance

// Set up the server socket //
WORD wVersionRequested; 
WSADATA wsaData; 
int err; 

wVersionRequested = MAKEWORD(1, 1);  
err = WSAStartup(wVersionRequested, &wsaData); 
if (err!=0) WSACleanup();

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMobymonApp object

CMobymonApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMobymonApp initialization

BOOL CMobymonApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMobymonDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMobymonView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMobymonApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMobymonApp commands

// Get a character from the modem //
unsigned char moby::getchar (void)
{
DWORD NumberOfBytesRead;
unsigned char in=0;
if (ReadFile(hcom,&in,1,&NumberOfBytesRead,NULL)==FALSE)
 {
 DWORD error;
 char err[80];
 error=GetLastError();
 sprintf(err,"Serial RX error#%d",error);
 if (error==ERROR_IO_PENDING) strcpy(err,"Serial RX - ERROR_IO_PENDING");
 if (error==ERROR_INVALID_PARAMETER) strcpy(err,"Serial RX - ERROR_INVALID_PARAMETER");
 if (error==ERROR_INVALID_USER_BUFFER) strcpy(err,"Serial RX - ERROR_INVALID_USER_BUFFER");
 if (error==ERROR_NOT_ENOUGH_MEMORY) strcpy(err,"Serial RX - ERROR_NOT_ENOUGH_MEMORY");
 if (error==ERROR_INVALID_HANDLE) strcpy(err,"Serial RX - ERROR_INVALID_HANDLE");
 AfxMessageBox(err,MB_OK|MB_ICONEXCLAMATION);
 exit(1);
 }	
return in;
}

// Check the RS232 link look for "TUMBLER" //
BOOL moby::linkcheck (void)
{
time_t started,current;

// Set commtime out to 50 ms //
commtimeouts.ReadTotalTimeoutConstant=50;
SetCommTimeouts(hcom,&commtimeouts);

started=time(NULL);

again:
current=time(NULL);
if (current-started>10) return (FALSE);

if (getchar()!=84) goto again;
if (getchar()!=85) goto again;
if (getchar()!=77) goto again;
if (getchar()!=66) goto again;
if (getchar()!=76) goto again;
if (getchar()!=69) goto again;
if (getchar()!=82) goto again;
return (TRUE);
}

// Send a character to the modem //
void moby::send (char tt)
{
DWORD NumberOfBytesRead;
char send[3];

send[0]=tt;
send[1]=0;

// Send the character and look for errors //
if (WriteFile(hcom,&send,1,&NumberOfBytesRead,NULL)==FALSE)
 {
 DWORD error;
 char err[80];
 error=GetLastError();
 sprintf(err,"Send TX error#%d",error);
 if (error==ERROR_IO_PENDING) strcpy(err,"Send TX Error - ERROR_IO_PENDING");
 if (error==ERROR_INVALID_PARAMETER) strcpy(err,"Send TX Error - ERROR_INVALID_PARAMETER");
 if (error==ERROR_INVALID_USER_BUFFER) strcpy(err,"Send TX Error - ERROR_INVALID_USER_BUFFER");
 if (error==ERROR_NOT_ENOUGH_MEMORY) strcpy(err,"Send TX Error - ERROR_NOT_ENOUGH_MEMORY");
 if (error==ERROR_INVALID_HANDLE) strcpy(err,"Send TX Error - ERROR_INVALID_HANDLE");
 AfxMessageBox(err,MB_OK|MB_ICONEXCLAMATION);
 exit(1);
 }
}

// Reset all variables //
void moby::reset_variables (void)
{
unsigned int a;

ready=0;

for (a=0;a<99;a++)
 {
 s0[a]=-127;
 s1[a]=-127;
 s2[a]=-127;
 s3[a]=-127;
 s4[a]=-127;
 s5[a]=-127;
 s6[a]=-127;
 s7[a]=-127;
 s8[a]=-127;
 s9[a]=-127;
 s10[a]=-127;
 s11[a]=-127;
 s12[a]=-127;
 s13[a]=-127;
 s14[a]=-127;
 s15[a]=-127;
 s16[a]=-127;
 s17[a]=-127;
 s18[a]=-127;
 s19[a]=-127; 
 s20[a]=-127;
 s21[a]=-127;
 s22[a]=-127;
 s23[a]=-127;
 s24[a]=-127;
 s25[a]=-127;
 s26[a]=-127;
 s27[a]=-127;
 s28[a]=-127;
 s29[a]=-127; 
 s30[a]=-127;
 s31[a]=-127;
 s32[a]=-127;
 s33[a]=-127;
 s34[a]=-127;
 s35[a]=-127;
 s36[a]=-127;
 s37[a]=-127;
 s38[a]=-127;
 s39[a]=-127; 
 s40[a]=-127;
 s41[a]=-127;
 s42[a]=-127;
 s43[a]=-127;
 s44[a]=-127;
 s45[a]=-127;
 s46[a]=-127;
 s47[a]=-127;
 s48[a]=-127;
 s49[a]=-127; 
 s50[a]=-127;
 s51[a]=-127;
 s52[a]=-127;
 s53[a]=-127;
 s54[a]=-127;
 s55[a]=-127;
 s56[a]=-127;
 s57[a]=-127;
 s58[a]=-127;
 s59[a]=-127; 
 s60[a]=-127;
 s61[a]=-127;
 s62[a]=-127;
 s63[a]=-127;
 s64[a]=-127;
 s65[a]=-127;
 s66[a]=-127;
 s67[a]=-127;
 s68[a]=-127;
 s69[a]=-127; 
 s70[a]=-127;
 s71[a]=-127;
 s72[a]=-127;
 s73[a]=-127;
 s74[a]=-127;
 s75[a]=-127;
 s76[a]=-127;
 s77[a]=-127;
 s78[a]=-127;
 s79[a]=-127; 
 s80[a]=-127;
 s81[a]=-127;
 s82[a]=-127;
 s83[a]=-127;
 s84[a]=-127;
 s85[a]=-127;
 s86[a]=-127;
 s87[a]=-127;
 s88[a]=-127;
 s89[a]=-127; 
 s90[a]=-127;
 s91[a]=-127;
 s92[a]=-127;
 s93[a]=-127;
 s94[a]=-127;
 s95[a]=-127;
 s96[a]=-127;
 s97[a]=-127;
 s98[a]=-127;
 s99[a]=-127; 
 s100[a]=-127;
 s101[a]=-127;
 s102[a]=-127;
 s103[a]=-127;
 s104[a]=-127;
 s105[a]=-127;
 s106[a]=-127;
 s107[a]=-127;
 s108[a]=-127;
 s109[a]=-127; 
 s110[a]=-127;
 s111[a]=-127;
 s112[a]=-127;
 s113[a]=-127;
 s114[a]=-127;
 s115[a]=-127;
 s116[a]=-127;
 s117[a]=-127;
 s118[a]=-127;
 s119[a]=-127; 
 }

f=72;
total_blocks=0.0f;
bad_blocks=0.0f;
surrounding=0;
strcpy(enc,"\n");
}

// Have we got the word "VALID" //
BOOL moby::valid_head (void)
{
time_t current,started;

started=time(NULL);

again:
current=time(NULL);
if (current-started>15) return (FALSE);

if (getchar()!=86) goto again;
if (getchar()!=65) goto again;
if (getchar()!=76) goto again;
if (getchar()!=73) goto again;
if (getchar()!=68) goto again; 
return (TRUE);
}


// This is called when nothing else is happening //
BOOL CMobymonApp::OnIdle(LONG lCount) 
{
if (ready==1)
 {
 // Set commtime out to 10 ms //
 commtimeouts.ReadTotalTimeoutConstant=5;
 SetCommTimeouts(hcom,&commtimeouts);

 b0=getchar();

 // Is it a head //
 if (b0==0xa0 && head_rxed==FALSE) head();
 // Or an MPAK //
 if (b0==176) mpak();

 }	

return CWinApp::OnIdle(lCount);
}

// Deal with a head message //
void moby::head (void)
{
int base=0,area=0,err,ferr,p1=0,l,a;
char tmp[100];
BOOL known=FALSE;

// Remove timeout //
//commtimeouts.ReadTotalTimeoutConstant=0;
//SetCommTimeouts(hcom,&commtimeouts);

b0=getchar();
b1=getchar();
b2=getchar();
b3=getchar();
b4=getchar();

// Work out first head FEC //
if (b2&128) p1=p1+2048;
if (b2&64) p1=p1+1024;
if (b2&32) p1=p1+512;
if (b2&16) p1=p1+256;
if (b2&8) p1=p1+128;
if (b2&4) p1=p1+64;
if (b2&2) p1=p1+32;
if (b2&1) p1=p1+16;
if (b4&128) p1=p1+8;
if (b4&64) p1=p1+4;
if (b4&32) p1=p1+2;
if (b4&16) p1++;
ferr=fec(p1);

// Work out second HEAD FEC //
p1=0;
if (b3&128) p1=p1+2048;
if (b3&64) p1=p1+1024;
if (b3&32) p1=p1+512;
if (b3&16) p1=p1+256;
if (b3&8) p1=p1+128;
if (b3&4) p1=p1+64;
if (b3&2) p1=p1+32;
if (b3&1) p1=p1+16;
if (b4&8) p1=p1+8;
if (b4&4) p1=p1+4;
if (b4&2) p1=p1+2;
if (b4&1) p1++; 
err=fec(p1);
ferr=ferr+err;

// Work out system //
system=0;
if (b1&1) system++;
if (b1&2) system=system+2;
if (b1&4) system=system+4;
if (b1&8) system=system+8;
if (b1&16) system=system+16;
if (b1&32) system=system+32;
if (b1&64) system=system+64;
if (b1&128) system=system+128;
if (b0&1) system=system+256;
if (b0&2) system=system+512;
if (b0&4) system=system+1024;
if (b0&8) system=system+2048;
if (b0&16) system=system+4096; 
if (b0&32) system=system+8192;
if (b0&64) system=system+16384;
if (b0&128) system=system+32768;

// Work out base // 
if (b2&128) base=base+32;
if (b2&64) base=base+16;
if (b2&32) base=base+8;
if (b2&16) base=base+4;
if (b2&8) base=base+2;
if (b2&4) base++;
// Work out area //
if (b2&2) area=area+32;
if (b2&1) area=area+16;
if (b3&128) area=area+8;
if (b3&64) area=area+4;
if (b3&32) area=area+2;
if (b3&16) area++;

if (ferr!=0) 
 {
 strcpy(id,"Bad Head FEC");
 ready=2;
 ::InvalidateRect(NULL,NULL,TRUE);
 send(66); 
 
 if (linkcheck()==FALSE)
  {
  strcpy(id,"RS232 Link Failure !");
  ::InvalidateRect(NULL,NULL,TRUE);
  return;
  }

 if (valid_head()==FALSE)
  {
  strcpy(id,"ERROR: Not receiving valid Mobitex data !");
  ::InvalidateRect(NULL,NULL,TRUE);
  return;
  }

 return;
 }

sprintf(id,"System=%ld",system); 
if (system==41719) strcpy(id,"This network is RAM (UK)"); 
if (system==46131) strcpy(id,"This network is RAM (USA)"); 
if (system==60304) strcpy(id,"This network is Telenor Mobil"); 

// Known base identities //
if (system==60304 && area==1) 
 {
 if (base==1) strcpy(tmp," the area is Østford and the base is at Bjørnåsen.");
 if (base==2) strcpy(tmp," the area is Østford and the base is at Høyås.");
 if (base==3) strcpy(tmp," the area is Østford and the base is at Sprinklerfjell.");
 known=TRUE;
 }

if (system==60304 && area==2) 
 {
 if (base==1) strcpy(tmp," the area is Akershus and the base is at Ullerudflaket.");
 if (base==2) strcpy(tmp," the area is Akershus and the base is at Mistberget.");
 if (base==3) strcpy(tmp," the area is Akershus and the base is at Stangåsen.");
 if (base==4) strcpy(tmp," the area is Akershus and the base is at Sunnås.");
 known=TRUE;
 }

if (system==60304 && area==3) 
 {
 if (base==2) strcpy(tmp," the area is Oslo and the base is at Røverkollen.");
 if (base==3) strcpy(tmp," the area is Oslo and the base is at Tryvann.");
 if (base==4) strcpy(tmp," the area is Oslo and the base is at U2.");
 known=TRUE;
 }

if (system==60304 && area==4) 
 {
 if (base==1) strcpy(tmp," the area is Hedemark and the base is at Bangsberget.");
 known=TRUE;
 }

if (system==60304 && area==5) 
 {
 if (base==2) strcpy(tmp," the area is Oppland and the base is at Korpeberget.");
 known=TRUE;
 }

if (system==60304 && area==6) 
 {
 if (base==1) strcpy(tmp," the area is Buskerud and the base is at Jonsknuten.");
 if (base==2) strcpy(tmp," the area is Buskerud and the base is at Konnerud.");
 if (base==3) strcpy(tmp," the area is Buskerud and the base is at Ringkollen.");
 known=TRUE;
 }

if (system==60304 && area==7) 
 {
 if (base==1) strcpy(tmp," the area is Vestfold and the base is at Hvittingen.");
 if (base==2) strcpy(tmp," the area is Vestfold and the base is at Kamfjordåsen.");
 if (base==3) strcpy(tmp," the area is Vestfold and the base is at Bratthagen.");
 if (base==4) strcpy(tmp," the area is Vestfold and the base is at Frodeåsen.");
 known=TRUE;
 }

if (system==60304 && area==8) 
 {
 if (base==1) strcpy(tmp," the area is Telemark and the base is at Vealøs.");
 known=TRUE;
 }

if (system==60304 && area==9)
 {
 sprintf(tmp," the area is Aust Agder the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==10)
 {
 sprintf(tmp," the area is Vest Agder the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==11) 
 {
 if (base==1) strcpy(tmp," the area is Rogaland and the base is at Lifjell.");
 if (base==2) strcpy(tmp," the area is Rogaland and the base is at Steinsfjell.");
 known=TRUE;
 }

if (system==60304 && area==12) 
 {
 if (base==1) strcpy(tmp," the area is Hordaland and the base is at Katnakken.");
 if (base==2) strcpy(tmp," the area is Hordaland and the base is at Løvstakken.");
 if (base==3) strcpy(tmp," the area is Hordaland and the base is at Gladihaug.");
 known=TRUE;
 }

if (system==60304 && area==14)
 {
 sprintf(tmp," the area is Sogn Og Fjordane the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==15)
 {
 sprintf(tmp," the area is Møre Og Romsdal the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==16)
 {
 if (base==1) strcpy(tmp," the area is Sør Tøndelag the base ID is at Gråkallen.");
 known=TRUE;
 }

if (system==60304 && area==17) 
 {
 if (base==1) strcpy(tmp," the area is Nord Tøndelag and the base is at Forbordfjell.");
 if (base==2) strcpy(tmp," the area is Nord Tøndelag and the base is at Skavlen.");
 known=TRUE;
 }

if (system==60304 && area==18)
 {
 sprintf(tmp," the area is Nordland the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==19)
 {
 sprintf(tmp," the area is Troms the base ID is %d",base);
 known=TRUE;
 }

if (system==60304 && area==20)
 {
 sprintf(tmp," the area is Finnmark the base ID is %d",base);
 known=TRUE;
 }

// Program doesn't know identity //
if (known==FALSE)
 {
 sprintf(tmp," the area ID is %d",area);
 strcat(id,tmp);
 sprintf(tmp," and the base ID is %d",base);
 }

strcat (id,tmp);
l=strlen(id);
for (a=l;a<199;a++) id[a]=32;

ready=2;
head_rxed=TRUE;
}

// Deal with Mpaks //
void moby::mpak (void)
{
unsigned char type,pclass,extern_f,ptype;
int count;

// Remove timeout //
//commtimeouts.ReadTotalTimeoutConstant=0;
//SetCommTimeouts(hcom,&commtimeouts);

// Download the mpak //
count=block();
// Any errors ? //
if (count!=0) 
{
return;
}

frame=0;
if (blk[0][39]==1) frame=16;
if (blk[0][40]==1) frame=frame+8;
if (blk[0][41]==1) frame=frame+4;
if (blk[0][42]==1) frame=frame+2;
if (blk[0][43]==1) frame++;

// User doesn't want to see MRM's //
if (frame==1 && display_mrm==FALSE) frame=0;

// Who is sender // 
mob=0;
if (blk[0][0]==1) mob=8388608;
if (blk[0][1]==1) mob=mob+4194304;
if (blk[0][2]==1) mob=mob+2097152;
if (blk[0][3]==1) mob=mob+1048576;
if (blk[0][4]==1) mob=mob+524288;
if (blk[0][5]==1) mob=mob+262144;
if (blk[0][6]==1) mob=mob+131072;
if (blk[0][7]==1) mob=mob+65536;
if (blk[0][12]==1) mob=mob+32768;
if (blk[0][13]==1) mob=mob+16384;
if (blk[0][14]==1) mob=mob+8192;
if (blk[0][15]==1) mob=mob+4096;
if (blk[0][16]==1) mob=mob+2048; 
if (blk[0][17]==1) mob=mob+1024; 
if (blk[0][18]==1) mob=mob+512; 
if (blk[0][19]==1) mob=mob+256;
if (blk[0][24]==1) mob=mob+128;
if (blk[0][25]==1) mob=mob+64;
if (blk[0][26]==1) mob=mob+32;
if (blk[0][27]==1) mob=mob+16;
if (blk[0][28]==1) mob=mob+8;
if (blk[0][29]==1) mob=mob+4;
if (blk[0][30]==1) mob=mob+2;
if (blk[0][31]==1) mob++;
 
// What is type //
type=0;
if (blk[0][39]==1) type=16;
if (blk[0][40]==1) type=type+8;
if (blk[0][41]==1) type=type+4;
if (blk[0][42]==1) type=type+2;
if (blk[0][43]==1) type++;
 
// How many blocks //
blocks=0;
if (blk[0][60]==1) blocks=128;
if (blk[0][61]==1) blocks=blocks+64;
if (blk[0][62]==1) blocks=blocks+32;   
if (blk[0][63]==1) blocks=blocks+16;
if (blk[0][64]==1) blocks=blocks+8;
if (blk[0][65]==1) blocks=blocks+4;
if (blk[0][66]==1) blocks=blocks+2;
if (blk[0][67]==1) blocks++;

// Who is sender // 
sender=0;
if (blk[0][0+f]==1) sender=8388608;
if (blk[0][1+f]==1) sender=sender+4194304;
if (blk[0][2+f]==1) sender=sender+2097152;
if (blk[0][3+f]==1) sender=sender+1048576;
if (blk[0][4+f]==1) sender=sender+524288;
if (blk[0][5+f]==1) sender=sender+262144;
if (blk[0][6+f]==1) sender=sender+131072;
if (blk[0][7+f]==1) sender=sender+65536;
if (blk[0][12+f]==1) sender=sender+32768;
if (blk[0][13+f]==1) sender=sender+16384;
if (blk[0][14+f]==1) sender=sender+8192;
if (blk[0][15+f]==1) sender=sender+4096;
if (blk[0][16+f]==1) sender=sender+2048; 
if (blk[0][17+f]==1) sender=sender+1024; 
if (blk[0][18+f]==1) sender=sender+512; 
if (blk[0][19+f]==1) sender=sender+256;
if (blk[0][24+f]==1) sender=sender+128;
if (blk[0][25+f]==1) sender=sender+64;
if (blk[0][26+f]==1) sender=sender+32;
if (blk[0][27+f]==1) sender=sender+16;
if (blk[0][28+f]==1) sender=sender+8;
if (blk[0][29+f]==1) sender=sender+4;
if (blk[0][30+f]==1) sender=sender+2;
if (blk[0][31+f]==1) sender++;
 
// Who is addresse // 
address=0;
if (blk[0][36+f]==1) address=8388608;
if (blk[0][37+f]==1) address=address+4194304;
if (blk[0][38+f]==1) address=address+2097152;
if (blk[0][39+f]==1) address=address+1048576;
if (blk[0][40+f]==1) address=address+524288;
if (blk[0][41+f]==1) address=address+262144;
if (blk[0][42+f]==1) address=address+131072;
if (blk[0][43+f]==1) address=address+65536;
if (blk[0][48+f]==1) address=address+32768;
if (blk[0][49+f]==1) address=address+16384;
if (blk[0][50+f]==1) address=address+8192;
if (blk[0][51+f]==1) address=address+4096;
if (blk[0][52+f]==1) address=address+2048; 
if (blk[0][53+f]==1) address=address+1024; 
if (blk[0][54+f]==1) address=address+512; 
if (blk[0][55+f]==1) address=address+256;
if (blk[0][60+f]==1) address=address+128;
if (blk[0][61+f]==1) address=address+64;
if (blk[0][62+f]==1) address=address+32;
if (blk[0][63+f]==1) address=address+16;
if (blk[0][64+f]==1) address=address+8;
if (blk[0][65+f]==1) address=address+4;
if (blk[0][66+f]==1) address=address+2;
if (blk[0][67+f]==1) address++;
 
// Traffic State //
state=0;
if (blk[0][72+f]==1) state=4;
if (blk[0][73+f]==1) state=state+2;
if (blk[0][74+f]==1) state++;  

// Number of valid bytes in last octet //
octet=0;
if (blk[0][37]==1) octet=32;
if (blk[0][38]==1) octet=octet+16;
if (blk[0][48]==1) octet=octet+8;
if (blk[0][49]==1) octet=octet+4;
if (blk[0][50]==1) octet=octet+2;
if (blk[0][51]==1) octet++;

// Sequence Number //
sequence=0;
if (blk[0][52]==1) sequence=8;
if (blk[0][53]==1) sequence=sequence+4;
if (blk[0][54]==1) sequence=sequence+2;
if (blk[0][55]==1) sequence++;

if (frame==1)
 {
 // Should this traffic state be ignored ? //
 if (ignore_ok_state==TRUE && state==0) return;
 if (ignore_from_mail_state==TRUE && state==1) return;
 if (ignore_in_mail_state==TRUE && state==2) return;
 if (ignore_no_transfer_state==TRUE && state==3) return;
 if (ignore_illegal_state==TRUE && state==4) return;
 if (ignore_congest_state==TRUE && state==5) return;
 if (ignore_error_state==TRUE && state==6) return;
 if (ignore_busy_state==TRUE && state==7) return;
 }

if (blk[0][75+f]==1 && frame==1) return;

// To multiple addresses ? //
if (blk[0][77+f]==1) multi_add=TRUE;
 else multi_add=FALSE;
  
// Packet class //
pclass=0;
if (blk[0][84+f]==1) pclass=pclass+2;
if (blk[0][85+f]==1) pclass++;

// EXTERN_F //
extern_f=0;
if (blk[0][86+f]==1) extern_f=1;
 
// Packet type // 
ptype=0;
if (blk[0][87+f]==1) ptype=ptype+16;
if (blk[0][88+f]==1) ptype=ptype+8;
if (blk[0][89+f]==1) ptype=ptype+4;
if (blk[0][90+f]==1) ptype=ptype+2;
if (blk[0][91+f]==1) ptype++; 

// Is this user on the blacklist ? //
if (blacklist!=0 && frame==1) 
 {
 if (sender==blacklist) goto exoop;
 if (address==blacklist) goto exoop;
 return;
 }
if (frame>1 && blacklist!=0)
 {
 if (mob==blacklist) goto exoop;
 return;
 }

// Is this user on the IGNORE.USR ? //
if (use_ignore==TRUE && frame==1)
 {
 if (ignore(sender)==TRUE) return;
 if (ignore(address)==TRUE) return;
 }
if (use_ignore==TRUE && frame>1)
 {
 if (ignore(mob)==TRUE) return;
 }

// Is this user on the EXCLUSIVE.USR list ? //
if (use_exclusive==TRUE && frame==1)
 {
 BOOL se,ad;
 
 se=exclusive(sender);
 ad=exclusive(address);
 if (ad==TRUE || se==TRUE) goto exoop;
 return;
 }
if (use_exclusive==TRUE && frame>1)
 {
 if (exclusive(mob)==TRUE) goto exoop;
 return;
 }
 
exoop:
// MPAK types //
if (frame==1 && pclass==0)
 {
 if (extern_f==0 && ptype==1 && text_show==TRUE && multi_add==FALSE) text();
 if (extern_f==0 && ptype==1 && text_show==TRUE && multi_add==TRUE) text_list();
 if (extern_f==1 && ptype==1 && extpak_show==TRUE) extpak();
 if (ptype==2 && data_show==TRUE) data();
 if (ptype==3 && status_show==TRUE && multi_add==FALSE) statusa();
 if (ptype==3 && status_show==TRUE && multi_add==TRUE) statusb();
 if (ptype==4) hpdata();
 }  

if (frame==1 && pclass==1 && extern_f==0)
 {
 if (ptype==1 && sos_show==TRUE) sos();
 if (ptype==2 && sosinfo_show==TRUE) sosinfo();
 if (ptype==3 && sosack_show==TRUE) sosack();  
 }

if (frame==1 && pclass==2 && extern_f==0)
 {
 if (ptype==1 && conreq_show==TRUE) conreq();
 if (ptype==2 && addconreq_show==TRUE) addconreq();
 if (ptype==3 && congra_show==TRUE) congra();
 if (ptype==4 && conord_show==TRUE) conord();
 if (ptype==5 && conrea_show==TRUE) conrea();
 if (ptype==6 && discon_show==TRUE) discon();;
 if (ptype==7 && cloopon_show==TRUE) cloopon();
 if (ptype==8 && cloopoff_show==TRUE) cloopoff();
 if (ptype==9 && lineon_show==TRUE) lineon();
 if (ptype==10 && lineoff_show==TRUE) lineoff();
 if (ptype==11 && confast_show==TRUE) confast();
 if (ptype==12 && addconfast_show==TRUE) addconfast();
 if (ptype==13 && linsel_show==TRUE) linsel();
 if (ptype==17 && sosconreq_show==TRUE) sosconreq();
 if (ptype==27 && sosconfast_show==TRUE) sosconfast();
 }

if (frame==1 && pclass==2 && extern_f==1 && extconreq_show==TRUE) extconreq();

if (frame==1 && pclass==3 && extern_f==0)
 {
 if (ptype==1) loginreq();
 if (ptype==2 && logingra_show==TRUE) logingra();
 if (ptype==3 && loginref_show==TRUE) loginref();
 if (ptype==4 && loginreq_show==TRUE) logoutmpak();
 if (ptype==5 && logoutord_show==TRUE) logoutord();
 if (ptype==6 && born_show==TRUE) born();
 if (ptype==7 && active_show==TRUE) active();
 if (ptype==8 && inactive_show==TRUE) inactive();
 if (ptype==9 && die_show==TRUE) die();
 if (ptype==10 && live_show==TRUE) live();
 if (ptype==11 && roamord_show==TRUE) roamord();
 if (ptype==12 && roam_show==TRUE) roam();
 if (ptype==13 && vicesosrx_show==TRUE) vicesosrx();
 if (ptype==14 && sosrx_show==TRUE) sosrx();
 if (ptype==15 && grouplist_show==TRUE) grouplist();  
 if (ptype==16 && flexreq_show==TRUE) flexreq();
 if (ptype==17 && flexlist_show==TRUE) flexlist();
 if (ptype==18 && inforeq_show==TRUE) inforeq();
 if (ptype==19 && info_show==TRUE) info();
 if (ptype==20 && time_show==TRUE) mtime(); 
 if (ptype==21 && arealist_show==TRUE) arealist();
 if (ptype==22 && esnreq_show==TRUE) esnreq();
 if (ptype==23 && esninfo_show==TRUE) esninfo();
 } 

// ACK //
if (frame==2 && display_ack==TRUE) small_frame();
// NAK //
if (frame==3 && display_nak==TRUE) small_frame();
// REB //
if (frame==4 && display_reb==TRUE) reb();
// RES //
if (frame==5 && display_res==TRUE) small_frame();
// ABD //
if (frame==6 && display_abd==TRUE) abx();
// ABL //
if (frame==8 && display_abl==TRUE) abx();
// ATD //
if (frame==9 && display_atd==TRUE) small_frame();
// ATT //
if (frame==10) small_frame();
// ATL //
if (frame==11 && display_atl==TRUE) small_frame();
// BKD //
if (frame==12 && display_bkd==TRUE) bkd();
// FRI //
if (frame==14 && display_fri==TRUE) fri();
// SVP //
if (frame==15) svp();
// TST //
if (frame==16 && display_tst==TRUE) tst();
// AKT //
if (frame==17) small_frame();
// AAT //
if (frame==21) small_frame();

}

// Create the scramble sequence //
void moby::scramble_sequence(void)
{
int a;
char stage[11],tmp;

for (a=0;a<11;a++)
 {
 stage[a]=1;
 }
 
for (a=0;a<511;a++)
 {
 tmp=stage[5]^stage[9]; 
 scr[a]=stage[9];
 stage[9]=stage[8];
 stage[8]=stage[7];
 stage[7]=stage[6];
 stage[6]=stage[5];
 stage[5]=stage[4];
 stage[4]=stage[3];
 stage[3]=stage[2];
 stage[2]=stage[1];
 stage[1]=tmp;
 }
a++;
} 

// Check the 12,4 FEC //
int moby::fec (int a)
{
int syndrome,remi,par,pos=0;

// User doesn't want error checking //
if (enable_checking==FALSE) return 0;
 
syndrome=a&3784;
par=0;
if (syndrome&2048) par++;
if (syndrome&1024) par++;
if (syndrome&512) par++;
if (syndrome&256) par++;
if (syndrome&128) par++;
if (syndrome&64) par++;
if (syndrome&32) par++;
if (syndrome&16) par++;
if (syndrome&8) par++;
if (syndrome&4) par++;
if (syndrome&2) par++;
if (syndrome&1) par++; 
remi=par%2;
if (remi!=0) pos=1;
                      
syndrome=a&3380;
par=0;
if (syndrome&2048) par++;
if (syndrome&1024) par++;
if (syndrome&512) par++;
if (syndrome&256) par++;
if (syndrome&128) par++;
if (syndrome&64) par++;
if (syndrome&32) par++;
if (syndrome&16) par++;
if (syndrome&8) par++;
if (syndrome&4) par++;
if (syndrome&2) par++;
if (syndrome&1) par++; 
remi=par%2;
if (remi!=0) pos=pos+2;

syndrome=a&2978;
par=0;
if (syndrome&2048) par++;
if (syndrome&1024) par++;
if (syndrome&512) par++;
if (syndrome&256) par++;
if (syndrome&128) par++;
if (syndrome&64) par++;
if (syndrome&32) par++;
if (syndrome&16) par++;
if (syndrome&8) par++;
if (syndrome&4) par++;
if (syndrome&2) par++;
if (syndrome&1) par++; 
remi=par%2;
if (remi!=0) pos=pos+4;

syndrome=a&1873;
par=0;
if (syndrome&2048) par++;
if (syndrome&1024) par++;
if (syndrome&512) par++;
if (syndrome&256) par++;
if (syndrome&128) par++;
if (syndrome&64) par++;
if (syndrome&32) par++;
if (syndrome&16) par++;
if (syndrome&8) par++;
if (syndrome&4) par++;
if (syndrome&2) par++;
if (syndrome&1) par++; 
remi=par%2;
if (remi!=0) pos=pos+8;

return pos;
}


// FEC check a full block //
int moby::blockfec(int c)
{
BOOL eb;
int e,etotal=0,a=0;

// Check each of the 18 Octets for FEC //
// No.1 //
a=0;
if (blk[c][0]==1) a=a+2048;
if (blk[c][1]==1) a=a+1024;
if (blk[c][2]==1) a=a+512;
if (blk[c][3]==1) a=a+256;
if (blk[c][4]==1) a=a+128;
if (blk[c][5]==1) a=a+64;
if (blk[c][6]==1) a=a+32;
if (blk[c][7]==1) a=a+16;
if (blk[c][8]==1) a=a+8;
if (blk[c][9]==1) a=a+4;
if (blk[c][10]==1) a=a+2;
if (blk[c][11]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(11,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.2 //
a=0;
if (blk[c][12]==1) a=a+2048;
if (blk[c][13]==1) a=a+1024;
if (blk[c][14]==1) a=a+512;
if (blk[c][15]==1) a=a+256;
if (blk[c][16]==1) a=a+128;
if (blk[c][17]==1) a=a+64;
if (blk[c][18]==1) a=a+32;
if (blk[c][19]==1) a=a+16;
if (blk[c][20]==1) a=a+8;
if (blk[c][21]==1) a=a+4;
if (blk[c][22]==1) a=a+2;
if (blk[c][23]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(23,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }
 
// No.3 //
a=0;
if (blk[c][24]==1) a=a+2048;
if (blk[c][25]==1) a=a+1024;
if (blk[c][26]==1) a=a+512;
if (blk[c][27]==1) a=a+256;
if (blk[c][28]==1) a=a+128;
if (blk[c][29]==1) a=a+64;
if (blk[c][30]==1) a=a+32;
if (blk[c][31]==1) a=a+16;
if (blk[c][32]==1) a=a+8;
if (blk[c][33]==1) a=a+4;
if (blk[c][34]==1) a=a+2;
if (blk[c][35]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(35,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }
 
// No.4 //
a=0;
if (blk[c][36]==1) a=a+2048;
if (blk[c][37]==1) a=a+1024;
if (blk[c][38]==1) a=a+512;
if (blk[c][39]==1) a=a+256;
if (blk[c][40]==1) a=a+128;
if (blk[c][41]==1) a=a+64;
if (blk[c][42]==1) a=a+32;
if (blk[c][43]==1) a=a+16;
if (blk[c][44]==1) a=a+8;
if (blk[c][45]==1) a=a+4;
if (blk[c][46]==1) a=a+2;
if (blk[c][47]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(47,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }
 
// No.5 //
a=0;
if (blk[c][48]==1) a=a+2048;
if (blk[c][49]==1) a=a+1024;
if (blk[c][50]==1) a=a+512;
if (blk[c][51]==1) a=a+256;
if (blk[c][52]==1) a=a+128;
if (blk[c][53]==1) a=a+64;
if (blk[c][54]==1) a=a+32;
if (blk[c][55]==1) a=a+16;
if (blk[c][56]==1) a=a+8;
if (blk[c][57]==1) a=a+4;
if (blk[c][58]==1) a=a+2;
if (blk[c][59]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(59,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }
 
// No.6 //
a=0;
if (blk[c][60]==1) a=a+2048;
if (blk[c][61]==1) a=a+1024;
if (blk[c][62]==1) a=a+512;
if (blk[c][63]==1) a=a+256;
if (blk[c][64]==1) a=a+128;
if (blk[c][65]==1) a=a+64;
if (blk[c][66]==1) a=a+32;
if (blk[c][67]==1) a=a+16;
if (blk[c][68]==1) a=a+8;
if (blk[c][69]==1) a=a+4;
if (blk[c][70]==1) a=a+2;
if (blk[c][71]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(71,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.7 //
a=0;
if (blk[c][72]==1) a=a+2048;
if (blk[c][73]==1) a=a+1024;
if (blk[c][74]==1) a=a+512;
if (blk[c][75]==1) a=a+256;
if (blk[c][76]==1) a=a+128;
if (blk[c][77]==1) a=a+64;
if (blk[c][78]==1) a=a+32;
if (blk[c][79]==1) a=a+16;
if (blk[c][80]==1) a=a+8;
if (blk[c][81]==1) a=a+4;
if (blk[c][82]==1) a=a+2;
if (blk[c][83]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(83,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.8 //
a=0;
if (blk[c][84]==1) a=a+2048;
if (blk[c][85]==1) a=a+1024;
if (blk[c][86]==1) a=a+512;
if (blk[c][87]==1) a=a+256;
if (blk[c][88]==1) a=a+128;
if (blk[c][89]==1) a=a+64;
if (blk[c][90]==1) a=a+32;
if (blk[c][91]==1) a=a+16;
if (blk[c][92]==1) a=a+8;
if (blk[c][93]==1) a=a+4;
if (blk[c][94]==1) a=a+2;
if (blk[c][95]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(95,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.9 //
a=0;
if (blk[c][96]==1) a=a+2048;
if (blk[c][97]==1) a=a+1024;
if (blk[c][98]==1) a=a+512;
if (blk[c][99]==1) a=a+256;
if (blk[c][100]==1) a=a+128;
if (blk[c][101]==1) a=a+64;
if (blk[c][102]==1) a=a+32;
if (blk[c][103]==1) a=a+16;
if (blk[c][104]==1) a=a+8;
if (blk[c][105]==1) a=a+4;
if (blk[c][106]==1) a=a+2;
if (blk[c][107]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(107,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.10 //
a=0;
if (blk[c][108]==1) a=a+2048;
if (blk[c][109]==1) a=a+1024;
if (blk[c][110]==1) a=a+512;
if (blk[c][111]==1) a=a+256;
if (blk[c][112]==1) a=a+128;
if (blk[c][113]==1) a=a+64;
if (blk[c][114]==1) a=a+32;
if (blk[c][115]==1) a=a+16;
if (blk[c][116]==1) a=a+8;
if (blk[c][117]==1) a=a+4;
if (blk[c][118]==1) a=a+2;
if (blk[c][119]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(119,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }
                
// No.11 //
a=0;
if (blk[c][120]==1) a=a+2048;
if (blk[c][121]==1) a=a+1024;
if (blk[c][122]==1) a=a+512;
if (blk[c][123]==1) a=a+256;
if (blk[c][124]==1) a=a+128;
if (blk[c][125]==1) a=a+64;
if (blk[c][126]==1) a=a+32;
if (blk[c][127]==1) a=a+16;
if (blk[c][128]==1) a=a+8;
if (blk[c][129]==1) a=a+4;
if (blk[c][130]==1) a=a+2;
if (blk[c][131]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(131,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.12 //
a=0;
if (blk[c][132]==1) a=a+2048;
if (blk[c][133]==1) a=a+1024;
if (blk[c][134]==1) a=a+512;
if (blk[c][135]==1) a=a+256;
if (blk[c][136]==1) a=a+128;
if (blk[c][137]==1) a=a+64;
if (blk[c][138]==1) a=a+32;
if (blk[c][139]==1) a=a+16;
if (blk[c][140]==1) a=a+8;
if (blk[c][141]==1) a=a+4;
if (blk[c][142]==1) a=a+2;
if (blk[c][143]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(143,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.13 //
a=0;
if (blk[c][144]==1) a=a+2048;
if (blk[c][145]==1) a=a+1024;
if (blk[c][146]==1) a=a+512;
if (blk[c][147]==1) a=a+256;
if (blk[c][148]==1) a=a+128;
if (blk[c][149]==1) a=a+64;
if (blk[c][150]==1) a=a+32;
if (blk[c][151]==1) a=a+16;
if (blk[c][152]==1) a=a+8;
if (blk[c][153]==1) a=a+4;
if (blk[c][154]==1) a=a+2;
if (blk[c][155]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(155,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.14 //
a=0;
if (blk[c][156]==1) a=a+2048;
if (blk[c][157]==1) a=a+1024;
if (blk[c][158]==1) a=a+512;
if (blk[c][159]==1) a=a+256;
if (blk[c][160]==1) a=a+128;
if (blk[c][161]==1) a=a+64;
if (blk[c][162]==1) a=a+32;
if (blk[c][163]==1) a=a+16;
if (blk[c][164]==1) a=a+8;
if (blk[c][165]==1) a=a+4;
if (blk[c][166]==1) a=a+2;
if (blk[c][167]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(167,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.15 //
a=0;
if (blk[c][168]==1) a=a+2048;
if (blk[c][169]==1) a=a+1024;
if (blk[c][170]==1) a=a+512;
if (blk[c][171]==1) a=a+256;
if (blk[c][172]==1) a=a+128;
if (blk[c][173]==1) a=a+64;
if (blk[c][174]==1) a=a+32;
if (blk[c][175]==1) a=a+16;
if (blk[c][176]==1) a=a+8;
if (blk[c][177]==1) a=a+4;
if (blk[c][178]==1) a=a+2;
if (blk[c][179]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(179,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.16 //
a=0;
if (blk[c][180]==1) a=a+2048;
if (blk[c][181]==1) a=a+1024;
if (blk[c][182]==1) a=a+512;
if (blk[c][183]==1) a=a+256;
if (blk[c][184]==1) a=a+128;
if (blk[c][185]==1) a=a+64;
if (blk[c][186]==1) a=a+32;
if (blk[c][187]==1) a=a+16;
if (blk[c][188]==1) a=a+8;
if (blk[c][189]==1) a=a+4;
if (blk[c][190]==1) a=a+2;
if (blk[c][191]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(191,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.17 //
a=0;
if (blk[c][192]==1) a=a+2048;
if (blk[c][193]==1) a=a+1024;
if (blk[c][194]==1) a=a+512;
if (blk[c][195]==1) a=a+256;
if (blk[c][196]==1) a=a+128;
if (blk[c][197]==1) a=a+64;
if (blk[c][198]==1) a=a+32;
if (blk[c][199]==1) a=a+16;
if (blk[c][200]==1) a=a+8;
if (blk[c][201]==1) a=a+4;
if (blk[c][202]==1) a=a+2;
if (blk[c][203]==1) a=a+1; 
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(203,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

// No.18 //
a=0;
if (blk[c][204]==1) a=a+2048;
if (blk[c][205]==1) a=a+1024;
if (blk[c][206]==1) a=a+512;
if (blk[c][207]==1) a=a+256;
if (blk[c][208]==1) a=a+128;
if (blk[c][209]==1) a=a+64;
if (blk[c][210]==1) a=a+32;
if (blk[c][211]==1) a=a+16;
if (blk[c][212]==1) a=a+8;
if (blk[c][213]==1) a=a+4;
if (blk[c][214]==1) a=a+2;
if (blk[c][215]==1) a=a+1;
e=fec(a);
if (e!=0)
 {
 eb=fec_correct(215,e,c);
 if (eb==FALSE) etotal=e+etotal; 
 }

total_blocks++;
if (etotal!=0) bad_blocks++;

return etotal;
}

// Correct a fec error in a block //
BOOL moby::fec_correct (int p , int e , int c)
{
BOOL eb=TRUE;

// User doesn't want FEC //
if (enable_fec==FALSE) return FALSE;

// Correct 1 bit errors //
if (e==1)
 {
 if (blk[c][p]==1) blk[c][p]=0;
  else blk[c][p]=1;
 }

if (e==2)
 {
 if (blk[c][p-1]==1) blk[c][p-1]=0;
  else blk[c][p-1]=1;
 }

if (e==4)
 {
 if (blk[c][p-2]==1) blk[c][p-2]=0;
  else blk[c][p-2]=1;
 }

if (e==5)
 {
 if (blk[c][p-4]==1) blk[c][p-4]=0;
  else blk[c][p-4]=1;
 }

if (e==6)
 {
 if (blk[c][p-5]==1) blk[c][p-5]=0;
  else blk[c][p-5]=1;
 }

if (e==7)
 {
 if (blk[c][p-8]==1) blk[c][p-8]=0;
  else blk[c][p-8]=1;
 }

if (e==8)
 {
 if (blk[c][p-3]==1) blk[c][p-3]=0;
  else blk[c][p-3]=1;
 }

if (e==9)
 {
 if (blk[c][p-6]==1) blk[c][p-6]=0;
  else blk[c][p-6]=1;
 }

if (e==10)
 {
 if (blk[c][p-7]==1) blk[c][p-7]=0;
  else blk[c][p-7]=1;
 }

if (e==11)
 {
 if (blk[c][p-9]==1) blk[c][p-9]=0;
  else blk[c][p-9]=1;
 }

if (e==13)
 {
 if (blk[c][p-10]==1) blk[c][p-10]=0;
  else blk[c][p-10]=1;
 }

if (e==14)
 {
 if (blk[c][p-11]==1) blk[c][p-11]=0;
  else blk[c][p-11]=1;
 }

// Uncorrectable errors of more than 1 bit //
if (e==3 || e==12 || e==15) eb=FALSE;

return eb; 
}

// Get a group of blocks //
int moby::block (void)
{
int tmp,err=0,e=0,etotal=0,bad=0;

s_pos=1;
 
if (getblock(0)==FALSE) return(1);
scramble(0);

bcounter=0;
if (blk[0][60]==1) bcounter=128;
if (blk[0][61]==1) bcounter=bcounter+64;
if (blk[0][62]==1) bcounter=bcounter+32;
if (blk[0][63]==1) bcounter=bcounter+16;
if (blk[0][64]==1) bcounter=bcounter+8;
if (blk[0][65]==1) bcounter=bcounter+4;
if (blk[0][66]==1) bcounter=bcounter+2;
if (blk[0][67]==1) bcounter++;


// Error check this block //
etotal=blockfec(0);
if (etotal!=0) bad++;

// If this block is bad don't go any further //
if (bad>0) return 1;

// Load a second block ? //
if (bcounter>1)
 {
 getblock(1);
 scramble(1);
 // Error check this block //
 tmp=blockfec(1); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a third block ? //
if (bcounter>2)
 {
 getblock(2);
 scramble(2);
 // Error check this block //
 tmp=blockfec(2); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourth block ? //
if (bcounter>3)
 {
 getblock(3);
 scramble(3);
 // Error check this block //
 tmp=blockfec(3); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifth block ? //
if (bcounter>4)
 {
 getblock(4);
 scramble(4);
 // Error check this block //
 tmp=blockfec(4); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixth block ? //
if (bcounter>5)
 {
 getblock(5);
 scramble(5);
 // Error check this block //
 tmp=blockfec(5); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a seventh block ? //
if (bcounter>6)
 {
 getblock(6);
 scramble(6);
 // Error check this block //
 tmp=blockfec(6); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a 8th block ? //
if (bcounter>7)
 {
 getblock(7);
 scramble(7);
 // Error check this block //
 tmp=blockfec(7); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a ninth block ? //
if (bcounter>8)
 {
 getblock(8);
 scramble(8);
 // Error check this block //
 tmp=blockfec(8); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a tenth block ? //
if (bcounter>9)
 {
 getblock(9);
 scramble(9);
 // Error check this block //
 tmp=blockfec(9); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a eleventh block ? //
if (bcounter>10)
 {
 getblock(10);
 scramble(10);
 // Error check this block //
 tmp=blockfec(10); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twelve block ? //
if (bcounter>11)
 {
 getblock(11);
 scramble(11);
 // Error check this block //
 tmp=blockfec(11); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirteenth block ? //
if (bcounter>12)
 {
 getblock(12);
 scramble(12);
 // Error check this block //
 tmp=blockfec(12); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourteenth block ? //
if (bcounter>13)
 {
 getblock(13);
 scramble(13);
 // Error check this block //
 tmp=blockfec(13); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fiveteenth block ? //
if (bcounter>14)
 {
 getblock(14);
 scramble(14);
 // Error check this block //
 tmp=blockfec(14); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixteenth block ? //
if (bcounter>15)
 {
 getblock(15);
 scramble(15);
 // Error check this block //
 tmp=blockfec(15); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a seventeenth block ? //
if (bcounter>16)
 {
 getblock(16);
 scramble(16);
 // Error check this block //
 tmp=blockfec(16); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a eighteenth block ? //
if (bcounter>17)
 {
 getblock(17);
 scramble(17);
 // Error check this block //
 tmp=blockfec(17); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a nineteenth block ? //
if (bcounter>18)
 {
 getblock(18);
 scramble(18);
 // Error check this block //
 tmp=blockfec(18); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyth block ? //
if (bcounter>19)
 {
 getblock(19);
 scramble(19);
 // Error check this block //
 tmp=blockfec(19); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyfirst block ? //
if (bcounter>20)
 {
 getblock(20);
 scramble(20);
 // Error check this block //
 tmp=blockfec(20); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentysecond block ? //
if (bcounter>21)
 {
 getblock(21);
 scramble(21);
 // Error check this block //
 tmp=blockfec(21); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentythird block ? //
if (bcounter>22)
 {
 getblock(22);
 scramble(22);
 // Error check this block //
 tmp=blockfec(22); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyfourth block ? //
if (bcounter>23)
 {
 getblock(23);
 scramble(23);
 // Error check this block //
 tmp=blockfec(23); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyfifth block ? //
if (bcounter>24)
 {
 getblock(24);
 scramble(24);
 // Error check this block //
 tmp=blockfec(24); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentysixth block ? //
if (bcounter>25)
 {
 getblock(25);
 scramble(25);
 // Error check this block //
 tmp=blockfec(25); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyseventh block ? //
if (bcounter>26)
 {
 getblock(26);
 scramble(26);
 // Error check this block //
 tmp=blockfec(26); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentyeighth block ? //
if (bcounter>27)
 {
 getblock(27);
 scramble(27);
 // Error check this block //
 tmp=blockfec(27); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a twentynineth block ? //
if (bcounter>28)
 {
 getblock(28);
 scramble(28);
 // Error check this block //
 tmp=blockfec(28); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyth block ? //
if (bcounter>29)
 {
 getblock(29);
 scramble(29);
 // Error check this block //
 tmp=blockfec(29); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyfirst block ? //
if (bcounter>30)
 {
 getblock(30);
 scramble(30);
 // Error check this block //
 tmp=blockfec(30); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtysecond block ? //
if (bcounter>31)
 {
 getblock(31);
 scramble(31);
 // Error check this block //
 tmp=blockfec(31); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtythird block ? //
if (bcounter>32)
 {
 getblock(32);
 scramble(32);
 // Error check this block //
 tmp=blockfec(32); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyfourth block ? //
if (bcounter>33)
 {
 getblock(33);
 scramble(33);
 // Error check this block //
 tmp=blockfec(33); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyfifth block ? //
if (bcounter>34)
 {
 getblock(34);
 scramble(34);
 // Error check this block //
 tmp=blockfec(34); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtysixth block ? //
if (bcounter>35)
 {
 getblock(35);
 scramble(35);
 // Error check this block //
 tmp=blockfec(35); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyseventh block ? //
if (bcounter>36)
 {
 getblock(36);
 scramble(36);
 // Error check this block //
 tmp=blockfec(36); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtyeighth block ? //
if (bcounter>37)
 {
 getblock(37);
 scramble(37);
 // Error check this block //
 tmp=blockfec(37); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a thirtynineth block ? //
if (bcounter>38)
 {
 getblock(38);
 scramble(38);
 // Error check this block //
 tmp=blockfec(38); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyth block ? //
if (bcounter>39)
 {
 getblock(39);
 scramble(39);
 // Error check this block //
 tmp=blockfec(39); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyfirst block ? //
if (bcounter>40)
 {
 getblock(40);
 scramble(40);
 // Error check this block //
 tmp=blockfec(40); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtysecond block ? //
if (bcounter>41)
 {
 getblock(41);
 scramble(41);
 // Error check this block //
 tmp=blockfec(41); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtythird block ? //
if (bcounter>42)
 {
 getblock(42);
 scramble(42);
 // Error check this block //
 tmp=blockfec(42); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyfourth block ? //
if (bcounter>43)
 {
 getblock(43);
 scramble(43);
 // Error check this block //
 tmp=blockfec(43);
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyfifth block ? //
if (bcounter>44)
 {
 getblock(44);
 scramble(44);
 // Error check this block //
 tmp=blockfec(44); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtysixth block ? //
if (bcounter>45)
 {
 getblock(45);
 scramble(45);
 // Error check this block //
 tmp=blockfec(45); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyseventh block ? //
if (bcounter>46)
 {
 getblock(46);
 scramble(46);
 // Error check this block //
 tmp=blockfec(46); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtyeighth block ? //
if (bcounter>47)
 {
 getblock(47);
 scramble(47);
 // Error check this block //
 tmp=blockfec(47); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fourtynineth block ? //
if (bcounter>48)
 {
 getblock(48);
 scramble(48);
 // Error check this block //
 tmp=blockfec(48); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fiftyth block ? //
if (bcounter>49)
 {
 getblock(49);
 scramble(49);
 // Error check this block //
 tmp=blockfec(49); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty first block ? //
if (bcounter>50)
 {
 getblock(50);
 scramble(50);
 // Error check this block //
 tmp=blockfec(50); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty second block ? //
if (bcounter>51)
 {
 getblock(51);
 scramble(51);
 // Error check this block //
 tmp=blockfec(51); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty third block ? //
if (bcounter>52)
 {
 getblock(52);
 scramble(52);
 // Error check this block //
 tmp=blockfec(52); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty fourth block ? //
if (bcounter>53)
 {
 getblock(53);
 scramble(53);
 // Error check this block //
 tmp=blockfec(53); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty fifth block ? //
if (bcounter>54)
 {
 getblock(54);
 scramble(54);
 // Error check this block //
 tmp=blockfec(54); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty sixth block ? //
if (bcounter>55)
 {
 getblock(55);
 scramble(55);
 // Error check this block //
 tmp=blockfec(55); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty seventh block ? //
if (bcounter>56)
 {
 getblock(56);
 scramble(56);
 // Error check this block //
 tmp=blockfec(56); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty eighth block ? //
if (bcounter>57)
 {
 getblock(57);
 scramble(57);
 // Error check this block //
 tmp=blockfec(57); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a fifty nineth block ? //
if (bcounter>58)
 {
 getblock(58);
 scramble(58);
 // Error check this block //
 tmp=blockfec(58); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixtyth block ? //
if (bcounter>59)
 {
 getblock(59);
 scramble(59);
 // Error check this block //
 tmp=blockfec(59); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty first block ? //
if (bcounter>60)
 {
 getblock(60);
 scramble(60);
 // Error check this block //
 tmp=blockfec(60); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty second block ? //
if (bcounter>61)
 {
 getblock(61);
 scramble(61);
 // Error check this block //
 tmp=blockfec(61); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty third block ? //
if (bcounter>62)
 {
 getblock(62);
 scramble(62);
 // Error check this block //
 tmp=blockfec(62); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty fourth block ? //
if (bcounter>63)
 {
 getblock(63);
 scramble(63);
 // Error check this block //
 tmp=blockfec(63); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty fifth block ? //
if (bcounter>64)
 {
 getblock(64);
 scramble(64);
 // Error check this block //
 tmp=blockfec(64); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty sixth block ? //
if (bcounter>65)
 {
 getblock(65);
 scramble(65);
 // Error check this block //
 tmp=blockfec(65); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty seventh block ? //
if (bcounter>66)
 {
 getblock(66);
 scramble(66);
 // Error check this block //
 tmp=blockfec(66); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty eighth block ? //
if (bcounter>67)
 {
 getblock(67);
 scramble(67);
 // Error check this block //
 tmp=blockfec(67); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a sixty nineth block ? //
if (bcounter>68)
 {
 getblock(68);
 scramble(68);
 // Error check this block //
 tmp=blockfec(68); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Load a seventyth block ? //
if (bcounter>69)
 {
 getblock(69);
 scramble(69);
 // Error check this block //
 tmp=blockfec(69); 
 etotal=etotal+tmp;
 if (tmp!=0) bad++;
 }

// Have their been any errors ? //
if (etotal!=0) err=1;

// Check if there have been any errors //
if (etotal!=0 && debug==TRUE) 
 {
 char tmp[20];
 blank_line();
 sprintf(s,"%d",bad);
 sprintf(tmp," of %d",bcounter);
 strcat(s,tmp);
 strcpy(tmp," blocks had a bad CRC");
 strcat(s,tmp);
 rotate();

 // Write to disk //
 if (logging)
  {
  // Put in a blank line //
  strcpy(tmp," ");
  logout.Write(tmp,strlen(tmp));
  logout.Write(enc,1);
  // Write the actual line //
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 }

return err;
}

// Unscramble & deinterleave all blocks //
void moby::scramble (int x)
{
int a,b;
BOOL tmp[241]; 

for (a=0;a<241;a++)
 {
 blk[x][a]=0;
 }
 
if (b0&128) blk[x][0]=1;
if (b0&64) blk[x][1]=1;
if (b0&32) blk[x][2]=1;
if (b0&16) blk[x][3]=1;
if (b0&8) blk[x][4]=1;
if (b0&4) blk[x][5]=1;
if (b0&2) blk[x][6]=1;
if (b0&1) blk[x][7]=1;

if (b1&128) blk[x][8]=1;
if (b1&64) blk[x][9]=1;
if (b1&32) blk[x][10]=1;
if (b1&16) blk[x][11]=1;
if (b1&8) blk[x][12]=1;
if (b1&4) blk[x][13]=1;
if (b1&2) blk[x][14]=1;
if (b1&1) blk[x][15]=1; 

if (b2&128) blk[x][16]=1;
if (b2&64) blk[x][17]=1;
if (b2&32) blk[x][18]=1;
if (b2&16) blk[x][19]=1;
if (b2&8) blk[x][20]=1;
if (b2&4) blk[x][21]=1;
if (b2&2) blk[x][22]=1;
if (b2&1) blk[x][23]=1;

if (b3&128) blk[x][24]=1;
if (b3&64) blk[x][25]=1;
if (b3&32) blk[x][26]=1;
if (b3&16) blk[x][27]=1;
if (b3&8) blk[x][28]=1;
if (b3&4) blk[x][29]=1;
if (b3&2) blk[x][30]=1;
if (b3&1) blk[x][31]=1;

if (b4&128) blk[x][32]=1;
if (b4&64) blk[x][33]=1;
if (b4&32) blk[x][34]=1;
if (b4&16) blk[x][35]=1;
if (b4&8) blk[x][36]=1;
if (b4&4) blk[x][37]=1;
if (b4&2) blk[x][38]=1;
if (b4&1) blk[x][39]=1;

if (b5&128) blk[x][40]=1;
if (b5&64) blk[x][41]=1;
if (b5&32) blk[x][42]=1;
if (b5&16) blk[x][43]=1;
if (b5&8) blk[x][44]=1;
if (b5&4) blk[x][45]=1;
if (b5&2) blk[x][46]=1;
if (b5&1) blk[x][47]=1;

if (b6&128) blk[x][48]=1;
if (b6&64) blk[x][49]=1;
if (b6&32) blk[x][50]=1;
if (b6&16) blk[x][51]=1;
if (b6&8) blk[x][52]=1;
if (b6&4) blk[x][53]=1;
if (b6&2) blk[x][54]=1;
if (b6&1) blk[x][55]=1;

if (b7&128) blk[x][56]=1;
if (b7&64) blk[x][57]=1;
if (b7&32) blk[x][58]=1;
if (b7&16) blk[x][59]=1;
if (b7&8) blk[x][60]=1;
if (b7&4) blk[x][61]=1;
if (b7&2) blk[x][62]=1;
if (b7&1) blk[x][63]=1;

if (b8&128) blk[x][64]=1;
if (b8&64) blk[x][65]=1;
if (b8&32) blk[x][66]=1;
if (b8&16) blk[x][67]=1;
if (b8&8) blk[x][68]=1;
if (b8&4) blk[x][69]=1;
if (b8&2) blk[x][70]=1;
if (b8&1) blk[x][71]=1;

if (b9&128) blk[x][72]=1;
if (b9&64) blk[x][73]=1;
if (b9&32) blk[x][74]=1;
if (b9&16) blk[x][75]=1;
if (b9&8) blk[x][76]=1;
if (b9&4) blk[x][77]=1;
if (b9&2) blk[x][78]=1;
if (b9&1) blk[x][79]=1;

if (b10&128) blk[x][80]=1;
if (b10&64) blk[x][81]=1;
if (b10&32) blk[x][82]=1;
if (b10&16) blk[x][83]=1;
if (b10&8) blk[x][84]=1;
if (b10&4) blk[x][85]=1;
if (b10&2) blk[x][86]=1;
if (b10&1) blk[x][87]=1;    

if (b11&128) blk[x][88]=1;
if (b11&64) blk[x][89]=1;
if (b11&32) blk[x][90]=1;
if (b11&16) blk[x][91]=1;
if (b11&8) blk[x][92]=1;
if (b11&4) blk[x][93]=1;
if (b11&2) blk[x][94]=1;
if (b11&1) blk[x][95]=1;

if (b12&128) blk[x][96]=1;
if (b12&64) blk[x][97]=1;
if (b12&32) blk[x][98]=1;
if (b12&16) blk[x][99]=1;
if (b12&8) blk[x][100]=1;
if (b12&4) blk[x][101]=1;
if (b12&2) blk[x][102]=1;
if (b12&1) blk[x][103]=1;

if (b13&128) blk[x][104]=1;
if (b13&64) blk[x][105]=1;
if (b13&32) blk[x][106]=1;
if (b13&16) blk[x][107]=1;
if (b13&8) blk[x][108]=1;
if (b13&4) blk[x][109]=1;
if (b13&2) blk[x][110]=1;
if (b13&1) blk[x][111]=1;

if (b14&128) blk[x][112]=1;
if (b14&64) blk[x][113]=1;
if (b14&32) blk[x][114]=1;
if (b14&16) blk[x][115]=1;
if (b14&8) blk[x][116]=1;
if (b14&4) blk[x][117]=1;
if (b14&2) blk[x][118]=1;
if (b14&1) blk[x][119]=1;

if (b15&128) blk[x][120]=1;
if (b15&64) blk[x][121]=1;
if (b15&32) blk[x][122]=1;
if (b15&16) blk[x][123]=1;
if (b15&8) blk[x][124]=1;
if (b15&4) blk[x][125]=1;
if (b15&2) blk[x][126]=1;
if (b15&1) blk[x][127]=1;  

if (b16&128) blk[x][128]=1;
if (b16&64) blk[x][129]=1;
if (b16&32) blk[x][130]=1;
if (b16&16) blk[x][131]=1;
if (b16&8) blk[x][132]=1;
if (b16&4) blk[x][133]=1;
if (b16&2) blk[x][134]=1;
if (b16&1) blk[x][135]=1;

if (b17&128) blk[x][136]=1;
if (b17&64) blk[x][137]=1;
if (b17&32) blk[x][138]=1;
if (b17&16) blk[x][139]=1;
if (b17&8) blk[x][140]=1;
if (b17&4) blk[x][141]=1;
if (b17&2) blk[x][142]=1;
if (b17&1) blk[x][143]=1;

if (b18&128) blk[x][144]=1;
if (b18&64) blk[x][145]=1;
if (b18&32) blk[x][146]=1;
if (b18&16) blk[x][147]=1;
if (b18&8) blk[x][148]=1;
if (b18&4) blk[x][149]=1;
if (b18&2) blk[x][150]=1;
if (b18&1) blk[x][151]=1;

if (b19&128) blk[x][152]=1;
if (b19&64) blk[x][153]=1;
if (b19&32) blk[x][154]=1;
if (b19&16) blk[x][155]=1;
if (b19&8) blk[x][156]=1;
if (b19&4) blk[x][157]=1;
if (b19&2) blk[x][158]=1;
if (b19&1) blk[x][159]=1;

if (b20&128) blk[x][160]=1;
if (b20&64) blk[x][161]=1;
if (b20&32) blk[x][162]=1;
if (b20&16) blk[x][163]=1;
if (b20&8) blk[x][164]=1;
if (b20&4) blk[x][165]=1;
if (b20&2) blk[x][166]=1;
if (b20&1) blk[x][167]=1;   

if (b21&128) blk[x][168]=1;
if (b21&64) blk[x][169]=1;
if (b21&32) blk[x][170]=1;
if (b21&16) blk[x][171]=1;
if (b21&8) blk[x][172]=1;
if (b21&4) blk[x][173]=1;
if (b21&2) blk[x][174]=1;
if (b21&1) blk[x][175]=1; 

if (b22&128) blk[x][176]=1;
if (b22&64) blk[x][177]=1;
if (b22&32) blk[x][178]=1;
if (b22&16) blk[x][179]=1;
if (b22&8) blk[x][180]=1;
if (b22&4) blk[x][181]=1;
if (b22&2) blk[x][182]=1;
if (b22&1) blk[x][183]=1;

if (b23&128) blk[x][184]=1;
if (b23&64) blk[x][185]=1;
if (b23&32) blk[x][186]=1;
if (b23&16) blk[x][187]=1;
if (b23&8) blk[x][188]=1;
if (b23&4) blk[x][189]=1;
if (b23&2) blk[x][190]=1;
if (b23&1) blk[x][191]=1;

if (b24&128) blk[x][192]=1;
if (b24&64) blk[x][193]=1;
if (b24&32) blk[x][194]=1;
if (b24&16) blk[x][195]=1;
if (b24&8) blk[x][196]=1;
if (b24&4) blk[x][197]=1;
if (b24&2) blk[x][198]=1;
if (b24&1) blk[x][199]=1; 

if (b25&128) blk[x][200]=1;
if (b25&64) blk[x][201]=1;
if (b25&32) blk[x][202]=1;
if (b25&16) blk[x][203]=1;
if (b25&8) blk[x][204]=1;
if (b25&4) blk[x][205]=1;
if (b25&2) blk[x][206]=1;
if (b25&1) blk[x][207]=1;  

if (b26&128) blk[x][208]=1;
if (b26&64) blk[x][209]=1;
if (b26&32) blk[x][210]=1;
if (b26&16) blk[x][211]=1;
if (b26&8) blk[x][212]=1;
if (b26&4) blk[x][213]=1;
if (b26&2) blk[x][214]=1;
if (b26&1) blk[x][215]=1;

if (b27&128) blk[x][216]=1;
if (b27&64) blk[x][217]=1;
if (b27&32) blk[x][218]=1;
if (b27&16) blk[x][219]=1;
if (b27&8) blk[x][220]=1;
if (b27&4) blk[x][221]=1;
if (b27&2) blk[x][222]=1;
if (b27&1) blk[x][223]=1;

if (b28&128) blk[x][224]=1;
if (b28&64) blk[x][225]=1;
if (b28&32) blk[x][226]=1;
if (b28&16) blk[x][227]=1;
if (b28&8) blk[x][228]=1;
if (b28&4) blk[x][229]=1;
if (b28&2) blk[x][230]=1;
if (b28&1) blk[x][231]=1;

if (b29&128) blk[x][232]=1;
if (b29&64) blk[x][233]=1;
if (b29&32) blk[x][234]=1;
if (b29&16) blk[x][235]=1;
if (b29&8) blk[x][236]=1;
if (b29&4) blk[x][237]=1;
if (b29&2) blk[x][238]=1;
if (b29&1) blk[x][239]=1;

// DeScramble //
a=0;
s_pos--;

descr:
tmp[a]=blk[x][a]^scr[s_pos];
s_pos++;
a++;
if (s_pos==511) s_pos=0;
if (a<241) goto descr;
 
// DeInterleave //
b=0;
for (a=0;a<=239;a++)
 {
 if (a==12) b=1;
 if (a==24) b=2;
 if (a==36) b=3;
 if (a==48) b=4;
 if (a==60) b=5;
 if (a==72) b=6;
 if (a==84) b=7;
 if (a==96) b=8;
 if (a==108) b=9;
 if (a==120) b=10;
 if (a==132) b=11;
 if (a==144) b=12;
 if (a==156) b=13;
 if (a==168) b=14;
 if (a==180) b=15;
 if (a==192) b=16;
 if (a==204) b=17;
 if (a==216) b=18;
 if (a==228) b=19;
 
 blk[x][a]=tmp[b];
 b=b+20;
 }
} 


// Calculate the time //
void moby::moby_time (unsigned long int mm)
{
unsigned long year,md,mt,month,day,hour,minute,temp;
char tmp[10];

temp=mm%1440;
hour=temp/60;
minute=temp%60;

md=mm/1440;
mt=(4291+10*(md-(36525*((100*md+30690)/36525))/100))/10;

year=1984+(100*md+30690)/36525+mt/429;
month=(100*mt)/3061-1-12*(mt/429);
day=mt-(((100*mt)/3061)*3061)/100;

sprintf(ts,"%d",hour); 
// Add a zero //
if (minute<10) sprintf(tmp,":0%d",minute);
 else sprintf(tmp,":%d",minute);
strcat(ts,tmp);
sprintf(tmp," %d",day);
strcat(ts,tmp);
sprintf(tmp,"/%d",month);
strcat(ts,tmp);
sprintf(tmp,"/%d",year);
strcat(ts,tmp);
} 

// Who from & who to //
void moby::display_stub (void)
{
char tmp[200],line1[200],line2[200];

// MRM's //
if (frame==1)
 {
 sprintf(s,"To:%lx",address);
 if (address==1) strcpy(s,"To the Network");
 if (address>1 && address<7) sprintf(s,"To an External Network #%d",address);
 if (address==7) strcpy(s,"To All Terminals");
 if (address>7 && address<21) sprintf(s,"To an External Network #%d",address);
 if (get_identity(address)==TRUE)
  {
  strcpy(s,"To ");
  strcat(s,user_name);
  }

 sprintf(tmp," From:%lx",sender);
 if (sender==1) strcpy(tmp," From the Network");
 if (sender>1 && sender<7) sprintf(tmp," From an External Network #%d",sender);
 if (sender>7 && sender<21) sprintf(tmp," From an External Network #%d",sender); 
 if (get_identity(sender)==TRUE)
  {
  strcpy(tmp," From ");
  strcat(tmp,user_name);
  }

 strcat(s,tmp);
 if (blocks>1) 
  {
  char tmp2[10];
  sprintf(tmp," (%d",blocks);
  strcpy(tmp2," Blocks)");
  strcat(tmp,tmp2);
  strcat(s,tmp);
  }

 // Traffic state //
 if (display_traffic_state==TRUE)
  {
  if (state==0) strcpy(tmp," (OK)");
  if (state==1) strcpy(tmp," (FROM_MAIL)");
  if (state==2) strcpy(tmp," (IN_MAIL)");
  if (state==3) strcpy(tmp," (NO_TRANSFER)");
  if (state==4) strcpy(tmp," (ILLEGAL)");
  if (state==5) strcpy(tmp," (CONGEST)");
  if (state==6) strcpy(tmp," (ERROR)");
  if (state==7) strcpy(tmp," (BUSY)");
  strcat(s,tmp);
  }

 if (sequence_display==TRUE)
  {
  sprintf(tmp," (%d",sequence);
  strcat(s,tmp);
  strcpy(tmp,")");
  strcat(s,tmp);
  }

 if (re_display==TRUE && blk[0][36]==1)
  {
  strcpy(tmp," (RE)");
  strcat(s,tmp);
  }

 // Store the main line //
 strcpy(line1,s);

 // Cope with multiple addresses //
 if (multi_add==TRUE)
  {
  unsigned long man;
  no_addr=0;
  if (blk[0][103+f]==1) no_addr=1;;
  if (blk[0][102+f]==1) no_addr=no_addr+2;
  if (blk[0][101+f]==1) no_addr=no_addr+4;
  if (blk[0][100+f]==1) no_addr=no_addr+8;
  if (blk[0][99+f]==1) no_addr=no_addr+16;
  if (blk[0][98+f]==1) no_addr=no_addr+32;
  if (blk[0][97+f]==1) no_addr=no_addr+64;
  if (blk[0][96+f]==1) no_addr=no_addr+128; 

  // Calculate the first MAN //
  man=0;
  if (blk[0][211]==1) man=1;
  if (blk[0][210]==1) man=man+2;
  if (blk[0][209]==1) man=man+4;
  if (blk[0][208]==1) man=man+8;
  if (blk[0][207]==1) man=man+16;
  if (blk[0][206]==1) man=man+32;
  if (blk[0][205]==1) man=man+64;
  if (blk[0][204]==1) man=man+128;
  if (blk[0][199]==1) man=man+256;
  if (blk[0][198]==1) man=man+512;
  if (blk[0][197]==1) man=man+1024;
  if (blk[0][196]==1) man=man+2048;
  if (blk[0][195]==1) man=man+4096;
  if (blk[0][194]==1) man=man+8192;
  if (blk[0][193]==1) man=man+16384;
  if (blk[0][192]==1) man=man+32768;
  if (blk[0][187]==1) man=man+65536;
  if (blk[0][186]==1) man=man+131072;
  if (blk[0][185]==1) man=man+262144;
  if (blk[0][184]==1) man=man+524288;
  if (blk[0][183]==1) man=man+1048576;
  if (blk[0][182]==1) man=man+2097152;
  if (blk[0][181]==1) man=man+4194304;
  if (blk[0][180]==1) man=man+8388608;
  // Does the user have a name for this ? //
  if (get_identity(man)==TRUE) strcpy (line2,user_name);
   else sprintf(line2,"%x",man);

  // Must have this line //
  strcpy(s,line2);
  rotate();

  // Must have this line //
  strcpy(s,"Also addressed to:");
  rotate();
  }

 // Show the main line //
 strcpy(s,line1);
 rotate();
 }

// Other Frames //
if (frame>1)
 {
 BOOL seq=FALSE;
 sprintf(s,"MOB: %lx",mob);
 if (mob==1) strcpy(s,"To the Network");
 if (mob>1 && mob<7) sprintf(s,"To an External Network #%d",mob);
 if (mob>7 && mob<21) sprintf(s,"To an External Network #%d",mob);
 if (mob==7) strcpy(s,"To All Terminals");
 if (get_identity(mob)==TRUE)
  {
  strcpy(s,"MOB: ");
  strcat(s,user_name);
  }

 if (frame==2) seq=TRUE;
 if (frame==3) seq=TRUE;
 if (frame==4) seq=TRUE;
 if (frame==5) seq=TRUE;
 
 if (sequence_display==TRUE && seq==TRUE)
  {
  sprintf(tmp," (%d",sequence);
  strcat(s,tmp);
  strcpy(tmp,")");
  strcat(s,tmp);
  }

 rotate();
 }

}

// Handle the TIME mpak //
void moby::mtime (void)
{
char line0[300];
unsigned long int t;

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);

blank_line();

strcpy(line0,"TIME ");
strcat(line0,ts);

strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 }
}

// Handle an ACK or NAK frame //
void moby::small_frame (void)
{

blank_line();

if (frame==2) strcpy(s,"<ACK>");
if (frame==3) strcpy(s,"<NAK>");
if (frame==5) strcpy(s,"<RES>");
if (frame==9) strcpy(s,"<ATD>");
if (frame==10) strcpy(s,"<ATT>");
if (frame==11) strcpy(s,"<ATL>");
if (frame==17) strcpy(s,"<AKT>");
if (frame==21) strcpy(s,"<AAT>");

rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }

}

// Handle a FRI Frame //
void moby::fri (void)
{
char line0[80],line1[80],line2[80],line3[80],line4[80],line5[80];
unsigned char ffg,prio,mask,rand_slots,free_slots;
unsigned char max_access,slot_length,max_speech;

blank_line();

strcpy(line0,"<FRI> ");

ffg=0;
if (blk[0][37]==1) ffg=2;
if (blk[0][38]==1) ffg++;
if (ffg==0) strcat(line0,"(Alert) ");
if (ffg==1) strcat(line0,"(Alert + Data) ");
if (ffg==2) strcat(line0,"(Alert + Speech) ");
if (ffg==3) strcat(line0,"(Alert + Speech + Data) ");

prio=0;
if (blk[0][48]==1) prio=4;
if (blk[0][49]==1) prio=prio+2;
if (blk[0][50]==1) prio++;
if (prio==7) strcat(line0,"(Priority Group 4R)");
if (prio==6) strcat(line0,"(Priority Group 4N)");
if (prio==5) strcat(line0,"(Priority Group 3R)");
if (prio==4) strcat(line0,"(Priority Group 3N)");
if (prio==3) strcat(line0,"(Priority Group 2R)");
if (prio==2) strcat(line0,"(Priority Group 2N)");
if (prio==1) strcat(line0,"(Priority Group 1R)");
if (prio==0) strcat(line0,"(Priority Group 1N)");

mask=0;

rand_slots=0;
if (blk[0][72]==1) rand_slots=128;
if (blk[0][73]==1) rand_slots=rand_slots+64;
if (blk[0][74]==1) rand_slots=rand_slots+32;
if (blk[0][75]==1) rand_slots=rand_slots+16;
if (blk[0][76]==1) rand_slots=rand_slots+8;
if (blk[0][77]==1) rand_slots=rand_slots+4;
if (blk[0][78]==1) rand_slots=rand_slots+2;
if (blk[0][79]==1) rand_slots++;
sprintf(line1,"RAND_SLOTS=%d",rand_slots);

free_slots=0;
if (blk[0][84]==1) free_slots=128;
if (blk[0][85]==1) free_slots=free_slots+64;
if (blk[0][86]==1) free_slots=free_slots+32;
if (blk[0][87]==1) free_slots=free_slots+16;
if (blk[0][88]==1) free_slots=free_slots+8;
if (blk[0][89]==1) free_slots=free_slots+4;
if (blk[0][90]==1) free_slots=free_slots+2;
if (blk[0][91]==1) free_slots++;
sprintf(line2,"FREE_SLOTS=%d",free_slots);

max_access=0;
if (blk[0][96]==1) max_access=128;
if (blk[0][97]==1) max_access=max_access+64;
if (blk[0][98]==1) max_access=max_access+32;
if (blk[0][99]==1) max_access=max_access+16;
if (blk[0][100]==1) max_access=max_access+8;
if (blk[0][101]==1) max_access=max_access+4;
if (blk[0][102]==1) max_access=max_access+2;
if (blk[0][103]==1) max_access++;
sprintf(line3,"MAX_ACCESS=%d",max_access);

slot_length=0;
if (blk[0][108]==1) slot_length=128;
if (blk[0][109]==1) slot_length=slot_length+64;
if (blk[0][110]==1) slot_length=slot_length+32;
if (blk[0][111]==1) slot_length=slot_length+16;
if (blk[0][112]==1) slot_length=slot_length+8;
if (blk[0][113]==1) slot_length=slot_length+4;
if (blk[0][114]==1) slot_length=slot_length+2;
if (blk[0][115]==1) slot_length++;
sprintf(line4,"SLOT_LENGTH=%d",slot_length);

max_speech=0;
if (blk[0][120]==1) max_speech=128;
if (blk[0][121]==1) max_speech=max_speech+64;
if (blk[0][122]==1) max_speech=max_speech+32;
if (blk[0][123]==1) max_speech=max_speech+16;
if (blk[0][124]==1) max_speech=max_speech+8;
if (blk[0][125]==1) max_speech=max_speech+4;
if (blk[0][126]==1) max_speech=max_speech+2;
if (blk[0][127]==1) max_speech++;
sprintf(line5,"MAX_SPEECH=%d",max_speech);

strcpy(s,line5);
rotate();
strcpy(s,line4);
rotate();
strcpy(s,line3);
rotate();
strcpy(s,line2);
rotate();
strcpy(s,line1);
rotate();
strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);
 logout.Write(line3,strlen(line3));
 logout.Write(enc,1);
 logout.Write(line4,strlen(line4));
 logout.Write(enc,1);
 logout.Write(line5,strlen(line5));
 logout.Write(enc,1);
 }
}

// Handle a BKD Frame //
void moby::bkd (void)
{
char line0[80],line1[80],line2[80],line3[80],line4[80];
unsigned char timeout;
unsigned int bkdfl,upfreq,dofreq;

blank_line();

strcpy(line0,"<BKD>");

bkdfl=0;
if (blk[0][72]==1) bkdfl=32768;
if (blk[0][73]==1) bkdfl=bkdfl+16384;
if (blk[0][74]==1) bkdfl=bkdfl+8192;
if (blk[0][75]==1) bkdfl=bkdfl+4096;
if (blk[0][76]==1) bkdfl=bkdfl+2048;
if (blk[0][77]==1) bkdfl=bkdfl+1024;
if (blk[0][78]==1) bkdfl=bkdfl+512;
if (blk[0][79]==1) bkdfl=bkdfl+256;
if (blk[0][84]==1) bkdfl=bkdfl+128;
if (blk[0][85]==1) bkdfl=bkdfl+64;
if (blk[0][86]==1) bkdfl=bkdfl+32;
if (blk[0][87]==1) bkdfl=bkdfl+16;
if (blk[0][88]==1) bkdfl=bkdfl+8;
if (blk[0][89]==1) bkdfl=bkdfl+4;
if (blk[0][90]==1) bkdfl=bkdfl+2;
if (blk[0][91]==1) bkdfl++;
sprintf(line1,"BKDFL=%d",bkdfl);

upfreq=0;
if (blk[0][96]==1) upfreq=32768;
if (blk[0][97]==1) upfreq=upfreq+16384;
if (blk[0][98]==1) upfreq=upfreq+8192;
if (blk[0][99]==1) upfreq=upfreq+4096;
if (blk[0][100]==1) upfreq=upfreq+2048;
if (blk[0][101]==1) upfreq=upfreq+1024;
if (blk[0][102]==1) upfreq=upfreq+512;
if (blk[0][103]==1) upfreq=upfreq+256;
if (blk[0][108]==1) upfreq=upfreq+128;
if (blk[0][109]==1) upfreq=upfreq+64;
if (blk[0][110]==1) upfreq=upfreq+32;
if (blk[0][111]==1) upfreq=upfreq+16;
if (blk[0][112]==1) upfreq=upfreq+8;
if (blk[0][113]==1) upfreq=upfreq+4;
if (blk[0][114]==1) upfreq=upfreq+2;
if (blk[0][115]==1) upfreq++;
sprintf(line2,"UPFREQ=%d",upfreq);

dofreq=0;
if (blk[0][120]==1) dofreq=32768;
if (blk[0][121]==1) dofreq=dofreq+16384;
if (blk[0][122]==1) dofreq=dofreq+8192;
if (blk[0][123]==1) dofreq=dofreq+4096;
if (blk[0][124]==1) dofreq=dofreq+2048;
if (blk[0][125]==1) dofreq=dofreq+1024;
if (blk[0][126]==1) dofreq=dofreq+512;
if (blk[0][127]==1) dofreq=dofreq+256;
if (blk[0][132]==1) dofreq=dofreq+128;
if (blk[0][133]==1) dofreq=dofreq+64;
if (blk[0][134]==1) dofreq=dofreq+32;
if (blk[0][135]==1) dofreq=dofreq+16;
if (blk[0][136]==1) dofreq=dofreq+8;
if (blk[0][137]==1) dofreq=dofreq+4;
if (blk[0][138]==1) dofreq=dofreq+2;
if (blk[0][139]==1) dofreq++;
sprintf(line3,"DOFREQ=%d",dofreq);

timeout=0;
if (blk[0][144]==1) timeout=128;
if (blk[0][145]==1) timeout=timeout+64;
if (blk[0][146]==1) timeout=timeout+32;
if (blk[0][147]==1) timeout=timeout+16;
if (blk[0][148]==1) timeout=timeout+8;
if (blk[0][149]==1) timeout=timeout+4;
if (blk[0][150]==1) timeout=timeout+2;
if (blk[0][151]==1) timeout++;
sprintf(line4,"TIMEOUT=%d",timeout);

strcpy(s,line4);
rotate();
strcpy(s,line3);
rotate();
strcpy(s,line2);
rotate();
strcpy(s,line1);
rotate();
strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);
 logout.Write(line3,strlen(line3));
 logout.Write(enc,1);
 logout.Write(line4,strlen(line4));
 logout.Write(enc,1);
 }
}

// Handle an SVP Frame //
void moby::svp (void)
{
unsigned char prio,mask,svptype;
char tmp[80],line0[80];

strcpy(line0,"<SVP> ");

prio=0;
if (blk[0][48]==1) prio=4;
if (blk[0][49]==1) prio=prio+2;
if (blk[0][50]==1) prio++;
if (prio==7) strcat(line0,"(Priority Group 4R)");
if (prio==6) strcat(line0,"(Priority Group 4N)");
if (prio==5) strcat(line0,"(Priority Group 3R)");
if (prio==4) strcat(line0,"(Priority Group 3N)");
if (prio==3) strcat(line0,"(Priority Group 2R)");
if (prio==2) strcat(line0,"(Priority Group 2N)");
if (prio==1) strcat(line0,"(Priority Group 1R)");
if (prio==0) strcat(line0,"(Priority Group 1N)");

mask=0;

svptype=0;
if (blk[0][72]==1) svptype=128;
if (blk[0][73]==1) svptype=svptype+64;
if (blk[0][74]==1) svptype=svptype+32;
if (blk[0][75]==1) svptype=svptype+16;
if (blk[0][76]==1) svptype=svptype+8;
if (blk[0][77]==1) svptype=svptype+4;
if (blk[0][78]==1) svptype=svptype+2;
if (blk[0][79]==1) svptype++;

if (display_svp==TRUE) 
 if (svptype==1 || svptype==2) blank_line();

// Type 1 //
if (svptype==1)
 {
 BOOL rssi_proc;
 char line1[80],line2[80],line3[80],line4[80],line5[80];
 char chline[8][80];
 unsigned int upfreq ,dofreq;
 unsigned char txpow,rssi_period,time_to_next,max_rep,basest,scan_time,bad_base,good_base,better_base,channels;
 int a;

 channels=0;

 txpow=0;
 if (blk[0][84]==1) txpow=128;
 if (blk[0][85]==1) txpow=txpow+64;
 if (blk[0][86]==1) txpow=txpow+32;
 if (blk[0][87]==1) txpow=txpow+16;
 if (blk[0][88]==1) txpow=txpow+8;
 if (blk[0][89]==1) txpow=txpow+4;
 if (blk[0][90]==1) txpow=txpow+2;
 if (blk[0][91]==1) txpow++;
 sprintf(line1,"TXPOW=%d",txpow);
 strcat(line1," dB");

 if (blk[0][103]==1) rssi_proc=TRUE;
  else rssi_proc=FALSE;

 rssi_period=0;
 if (blk[0][108]==1) rssi_period=128;
 if (blk[0][109]==1) rssi_period=rssi_period+64;
 if (blk[0][110]==1) rssi_period=rssi_period+32;
 if (blk[0][111]==1) rssi_period=rssi_period+16;
 if (blk[0][112]==1) rssi_period=rssi_period+8;
 if (blk[0][113]==1) rssi_period=rssi_period+4;
 if (blk[0][114]==1) rssi_period=rssi_period+2;
 if (blk[0][115]==1) rssi_period++;
 a=rssi_period*20;
 sprintf(tmp," RSSI_PERIOD=%d",a);
 if (rssi_proc==TRUE) strcat(tmp," ms CONTINUOUS");
  else strcat(tmp," ms FRAME");
 strcat(line1,tmp);

 time_to_next=0;
 if (blk[0][120]==1) time_to_next=128;
 if (blk[0][121]==1) time_to_next=time_to_next+64;
 if (blk[0][122]==1) time_to_next=time_to_next+32;
 if (blk[0][123]==1) time_to_next=time_to_next+16;
 if (blk[0][124]==1) time_to_next=time_to_next+8;
 if (blk[0][125]==1) time_to_next=time_to_next+4;
 if (blk[0][126]==1) time_to_next=time_to_next+2;
 if (blk[0][127]==1) time_to_next++;
 sprintf(line2,"TIME_TO_NEXT=%d",time_to_next);
 
 max_rep=0;
 if (blk[0][132]==1) max_rep=128;
 if (blk[0][133]==1) max_rep=max_rep+64;
 if (blk[0][134]==1) max_rep=max_rep+32;
 if (blk[0][135]==1) max_rep=max_rep+16;
 if (blk[0][136]==1) max_rep=max_rep+8;
 if (blk[0][137]==1) max_rep=max_rep+4;
 if (blk[0][138]==1) max_rep=max_rep+2;
 if (blk[0][139]==1) max_rep++;
 sprintf(tmp," MAX_REP=%d",max_rep);
 strcat(line2,tmp);

 basest=0;
 if (blk[0][144]==1) basest=128;
 if (blk[0][145]==1) basest=basest+64;
 if (blk[0][146]==1) basest=basest+32;
 if (blk[0][147]==1) basest=basest+16;
 if (blk[0][148]==1) basest=basest+8;
 if (blk[0][149]==1) basest=basest+4;
 if (blk[0][150]==1) basest=basest+2;
 if (blk[0][151]==1) basest++;
 sprintf(line3,"BASEST=%d",basest);

 scan_time=0;
 if (blk[0][156]==1) scan_time=128;
 if (blk[0][157]==1) scan_time=scan_time+64;
 if (blk[0][158]==1) scan_time=scan_time+32;
 if (blk[0][159]==1) scan_time=scan_time+16;
 if (blk[0][160]==1) scan_time=scan_time+8;
 if (blk[0][161]==1) scan_time=scan_time+4;
 if (blk[0][162]==1) scan_time=scan_time+2;
 if (blk[0][163]==1) scan_time++;
 a=scan_time*100;
 sprintf(tmp," SCAN_TIME=%d",a);
 strcat(tmp," ms");
 strcat(line3,tmp);

 bad_base=0;
 if (blk[0][168]==1) bad_base=128;
 if (blk[0][169]==1) bad_base=bad_base+64;
 if (blk[0][170]==1) bad_base=bad_base+32;
 if (blk[0][171]==1) bad_base=bad_base+16;
 if (blk[0][172]==1) bad_base=bad_base+8;
 if (blk[0][173]==1) bad_base=bad_base+4;
 if (blk[0][174]==1) bad_base=bad_base+2;
 if (blk[0][175]==1) bad_base++;
 sprintf(line4,"BAD_BASE=%d",bad_base);

 good_base=0;
 if (blk[0][180]==1) good_base=128;
 if (blk[0][181]==1) good_base=good_base+64;
 if (blk[0][182]==1) good_base=good_base+32;
 if (blk[0][183]==1) good_base=good_base+16;
 if (blk[0][184]==1) good_base=good_base+8;
 if (blk[0][185]==1) good_base=good_base+4;
 if (blk[0][186]==1) good_base=good_base+2;
 if (blk[0][187]==1) good_base++;
 sprintf(tmp," dBuV GOOD_BASE=%d",good_base);
 strcat(line4,tmp);

 better_base=0;
 if (blk[0][192]==1) better_base=128;
 if (blk[0][193]==1) better_base=better_base+64;
 if (blk[0][194]==1) better_base=better_base+32;
 if (blk[0][195]==1) better_base=better_base+16;
 if (blk[0][196]==1) better_base=better_base+8;
 if (blk[0][197]==1) better_base=better_base+4;
 if (blk[0][198]==1) better_base=better_base+2;
 if (blk[0][199]==1) better_base++;
 sprintf(tmp," dBuV BETTER_BASE=%d",better_base);
 strcat(tmp," dBuV");
 strcat(line4,tmp);

 // Includes a channel list also //
 if (bcounter>1)
  {
  channels=0;
  if (blk[1][0]==1) channels=128;
  if (blk[1][1]==1) channels=channels+64;
  if (blk[1][2]==1) channels=channels+32;
  if (blk[1][3]==1) channels=channels+16;
  if (blk[1][4]==1) channels=channels+8;
  if (blk[1][5]==1) channels=channels+4;
  if (blk[1][6]==1) channels=channels+2;
  if (blk[1][7]==1) channels++;

  // Don't do this if in the USA as they use the 900 MHz band //
  if (system!=46131 && channels>0) surrounding=channels;

  sprintf(line5,"Number of channels=%d",channels);
  
  // There must be a first channel //
  upfreq=0;
  if (blk[1][24]==1) upfreq=32768;
  if (blk[1][25]==1) upfreq=upfreq+16384;
  if (blk[1][26]==1) upfreq=upfreq+8192;
  if (blk[1][27]==1) upfreq=upfreq+4096;
  if (blk[1][28]==1) upfreq=upfreq+2048;
  if (blk[1][29]==1) upfreq=upfreq+1024;
  if (blk[1][30]==1) upfreq=upfreq+512;
  if (blk[1][31]==1) upfreq=upfreq+256;
  if (blk[1][36]==1) upfreq=upfreq+128;
  if (blk[1][37]==1) upfreq=upfreq+64;
  if (blk[1][38]==1) upfreq=upfreq+32;
  if (blk[1][39]==1) upfreq=upfreq+16;
  if (blk[1][40]==1) upfreq=upfreq+8;
  if (blk[1][41]==1) upfreq=upfreq+4;
  if (blk[1][42]==1) upfreq=upfreq+2;
  if (blk[1][43]==1) upfreq++;
  dofreq=0;
  if (blk[1][48]==1) dofreq=32768;
  if (blk[1][49]==1) dofreq=dofreq+16384;
  if (blk[1][50]==1) dofreq=dofreq+8192;
  if (blk[1][51]==1) dofreq=dofreq+4096;
  if (blk[1][52]==1) dofreq=dofreq+2048;
  if (blk[1][53]==1) dofreq=dofreq+1024;
  if (blk[1][54]==1) dofreq=dofreq+512;
  if (blk[1][55]==1) dofreq=dofreq+256;
  if (blk[1][60]==1) dofreq=dofreq+128;
  if (blk[1][61]==1) dofreq=dofreq+64;
  if (blk[1][62]==1) dofreq=dofreq+32;
  if (blk[1][63]==1) dofreq=dofreq+16;
  if (blk[1][64]==1) dofreq=dofreq+8;
  if (blk[1][65]==1) dofreq=dofreq+4;
  if (blk[1][66]==1) dofreq=dofreq+2;
  if (blk[1][67]==1) dofreq++;
  sprintf(chline[0],"UPFREQ 1=%d",upfreq);
  sprintf(tmp," DOFREQ 1=%d",dofreq);
  strcat(chline[0],tmp);

  upf[0]=euro_calc(upfreq);
  dof[0]=euro_calc(dofreq);


  if (channels>1)
   {	
  upfreq=0;
   if (blk[1][72]==1) upfreq=32768;
   if (blk[1][73]==1) upfreq=upfreq+16384;
   if (blk[1][74]==1) upfreq=upfreq+8192;
   if (blk[1][75]==1) upfreq=upfreq+4096;
   if (blk[1][76]==1) upfreq=upfreq+2048;
   if (blk[1][77]==1) upfreq=upfreq+1024;
   if (blk[1][78]==1) upfreq=upfreq+512;
   if (blk[1][79]==1) upfreq=upfreq+256;
   if (blk[1][84]==1) upfreq=upfreq+128;
   if (blk[1][85]==1) upfreq=upfreq+64;
   if (blk[1][86]==1) upfreq=upfreq+32;
   if (blk[1][87]==1) upfreq=upfreq+16;
   if (blk[1][88]==1) upfreq=upfreq+8;
   if (blk[1][89]==1) upfreq=upfreq+4;
   if (blk[1][90]==1) upfreq=upfreq+2;
   if (blk[1][91]==1) upfreq++;
   dofreq=0;
   if (blk[1][96]==1) dofreq=32768;
   if (blk[1][97]==1) dofreq=dofreq+16384;
   if (blk[1][98]==1) dofreq=dofreq+8192;
   if (blk[1][99]==1) dofreq=dofreq+4096;
   if (blk[1][100]==1) dofreq=dofreq+2048;
   if (blk[1][101]==1) dofreq=dofreq+1024;
   if (blk[1][102]==1) dofreq=dofreq+512;
   if (blk[1][103]==1) dofreq=dofreq+256;
   if (blk[1][108]==1) dofreq=dofreq+128;
   if (blk[1][109]==1) dofreq=dofreq+64;
   if (blk[1][110]==1) dofreq=dofreq+32;
   if (blk[1][111]==1) dofreq=dofreq+16;
   if (blk[1][112]==1) dofreq=dofreq+8;
   if (blk[1][113]==1) dofreq=dofreq+4;
   if (blk[1][114]==1) dofreq=dofreq+2;
   if (blk[1][115]==1) dofreq++;
   sprintf(chline[1],"UPFREQ 2=%d",upfreq);
   sprintf(tmp," DOFREQ 2=%d",dofreq);
   strcat(chline[1],tmp);
   upf[1]=euro_calc(upfreq);
   dof[1]=euro_calc(dofreq);
   }

  if (channels>2)
   {	
   upfreq=0;
   if (blk[1][120]==1) upfreq=32768;
   if (blk[1][121]==1) upfreq=upfreq+16384;
   if (blk[1][122]==1) upfreq=upfreq+8192;
   if (blk[1][123]==1) upfreq=upfreq+4096;
   if (blk[1][124]==1) upfreq=upfreq+2048;
   if (blk[1][125]==1) upfreq=upfreq+1024;
   if (blk[1][126]==1) upfreq=upfreq+512;
   if (blk[1][127]==1) upfreq=upfreq+256;
   if (blk[1][132]==1) upfreq=upfreq+128;
   if (blk[1][133]==1) upfreq=upfreq+64;
   if (blk[1][134]==1) upfreq=upfreq+32;
   if (blk[1][135]==1) upfreq=upfreq+16;
   if (blk[1][136]==1) upfreq=upfreq+8;
   if (blk[1][137]==1) upfreq=upfreq+4;
   if (blk[1][138]==1) upfreq=upfreq+2;
   if (blk[1][139]==1) upfreq++;
   dofreq=0;
   if (blk[1][144]==1) dofreq=32768;
   if (blk[1][145]==1) dofreq=dofreq+16384;
   if (blk[1][146]==1) dofreq=dofreq+8192;
   if (blk[1][147]==1) dofreq=dofreq+4096;
   if (blk[1][148]==1) dofreq=dofreq+2048;
   if (blk[1][149]==1) dofreq=dofreq+1024;
   if (blk[1][150]==1) dofreq=dofreq+512;
   if (blk[1][151]==1) dofreq=dofreq+256;
   if (blk[1][156]==1) dofreq=dofreq+128;
   if (blk[1][157]==1) dofreq=dofreq+64;
   if (blk[1][158]==1) dofreq=dofreq+32;
   if (blk[1][159]==1) dofreq=dofreq+16;
   if (blk[1][160]==1) dofreq=dofreq+8;
   if (blk[1][161]==1) dofreq=dofreq+4;
   if (blk[1][162]==1) dofreq=dofreq+2;
   if (blk[1][163]==1) dofreq++;
   sprintf(chline[2],"UPFREQ 3=%d",upfreq);
   sprintf(tmp," DOFREQ 3=%d",dofreq);
   strcat(chline[2],tmp);
   upf[2]=euro_calc(upfreq);
   dof[2]=euro_calc(dofreq);
   } 

  if (channels>3)
   {	
   upfreq=0;
   if (blk[1][168]==1) upfreq=32768;
   if (blk[1][169]==1) upfreq=upfreq+16384;
   if (blk[1][170]==1) upfreq=upfreq+8192;
   if (blk[1][171]==1) upfreq=upfreq+4096;
   if (blk[1][172]==1) upfreq=upfreq+2048;
   if (blk[1][173]==1) upfreq=upfreq+1024;
   if (blk[1][174]==1) upfreq=upfreq+512;
   if (blk[1][175]==1) upfreq=upfreq+256;
   if (blk[1][180]==1) upfreq=upfreq+128;
   if (blk[1][181]==1) upfreq=upfreq+64;
   if (blk[1][182]==1) upfreq=upfreq+32;
   if (blk[1][183]==1) upfreq=upfreq+16;
   if (blk[1][184]==1) upfreq=upfreq+8;
   if (blk[1][185]==1) upfreq=upfreq+4;
   if (blk[1][186]==1) upfreq=upfreq+2;
   if (blk[1][187]==1) upfreq++;
   dofreq=0;
   if (blk[1][192]==1) dofreq=32768;
   if (blk[1][193]==1) dofreq=dofreq+16384;
   if (blk[1][194]==1) dofreq=dofreq+8192;
   if (blk[1][195]==1) dofreq=dofreq+4096;
   if (blk[1][196]==1) dofreq=dofreq+2048;
   if (blk[1][197]==1) dofreq=dofreq+1024;
   if (blk[1][198]==1) dofreq=dofreq+512;
   if (blk[1][199]==1) dofreq=dofreq+256;
   if (blk[1][204]==1) dofreq=dofreq+128;
   if (blk[1][205]==1) dofreq=dofreq+64;
   if (blk[1][206]==1) dofreq=dofreq+32;
   if (blk[1][207]==1) dofreq=dofreq+16;
   if (blk[1][208]==1) dofreq=dofreq+8;
   if (blk[1][209]==1) dofreq=dofreq+4;
   if (blk[1][210]==1) dofreq=dofreq+2;
   if (blk[1][211]==1) dofreq++;
   sprintf(chline[3],"UPFREQ 4=%d",upfreq);
   sprintf(tmp," DOFREQ 4=%d",dofreq);
   strcat(chline[3],tmp);
   upf[3]=euro_calc(upfreq);
   dof[3]=euro_calc(dofreq);
   } 

  if (channels>4)
   {	
   upfreq=0;
   if (blk[2][0]==1) upfreq=32768;
   if (blk[2][1]==1) upfreq=upfreq+16384;
   if (blk[2][2]==1) upfreq=upfreq+8192;
   if (blk[2][3]==1) upfreq=upfreq+4096;
   if (blk[2][4]==1) upfreq=upfreq+2048;
   if (blk[2][5]==1) upfreq=upfreq+1024;
   if (blk[2][6]==1) upfreq=upfreq+512;
   if (blk[2][7]==1) upfreq=upfreq+256;
   if (blk[2][12]==1) upfreq=upfreq+128;
   if (blk[2][13]==1) upfreq=upfreq+64;
   if (blk[2][14]==1) upfreq=upfreq+32;
   if (blk[2][15]==1) upfreq=upfreq+16;
   if (blk[2][16]==1) upfreq=upfreq+8;
   if (blk[2][17]==1) upfreq=upfreq+4;
   if (blk[2][18]==1) upfreq=upfreq+2;
   if (blk[2][19]==1) upfreq++;
   dofreq=0;
   if (blk[2][24]==1) dofreq=32768;
   if (blk[2][25]==1) dofreq=dofreq+16384;
   if (blk[2][26]==1) dofreq=dofreq+8192;
   if (blk[2][27]==1) dofreq=dofreq+4096;
   if (blk[2][28]==1) dofreq=dofreq+2048;
   if (blk[2][29]==1) dofreq=dofreq+1024;
   if (blk[2][30]==1) dofreq=dofreq+512;
   if (blk[2][31]==1) dofreq=dofreq+256;
   if (blk[2][36]==1) dofreq=dofreq+128;
   if (blk[2][37]==1) dofreq=dofreq+64;
   if (blk[2][38]==1) dofreq=dofreq+32;
   if (blk[2][39]==1) dofreq=dofreq+16;
   if (blk[2][40]==1) dofreq=dofreq+8;
   if (blk[2][41]==1) dofreq=dofreq+4;
   if (blk[2][42]==1) dofreq=dofreq+2;
   if (blk[2][43]==1) dofreq++;
   sprintf(chline[4],"UPFREQ 5=%d",upfreq);
   sprintf(tmp," DOFREQ 5=%d",dofreq);
   strcat(chline[4],tmp);
   upf[4]=euro_calc(upfreq);
   dof[4]=euro_calc(dofreq);
   } 

  if (channels>5)
   {	
   upfreq=0;
   if (blk[2][48]==1) upfreq=32768;
   if (blk[2][49]==1) upfreq=upfreq+16384;
   if (blk[2][50]==1) upfreq=upfreq+8192;
   if (blk[2][51]==1) upfreq=upfreq+4096;
   if (blk[2][52]==1) upfreq=upfreq+2048;
   if (blk[2][53]==1) upfreq=upfreq+1024;
   if (blk[2][54]==1) upfreq=upfreq+512;
   if (blk[2][55]==1) upfreq=upfreq+256;
   if (blk[2][60]==1) upfreq=upfreq+128;
   if (blk[2][61]==1) upfreq=upfreq+64;
   if (blk[2][62]==1) upfreq=upfreq+32;
   if (blk[2][63]==1) upfreq=upfreq+16;
   if (blk[2][64]==1) upfreq=upfreq+8;
   if (blk[2][65]==1) upfreq=upfreq+4;
   if (blk[2][66]==1) upfreq=upfreq+2;
   if (blk[2][67]==1) upfreq++;
   dofreq=0;
   if (blk[2][72]==1) dofreq=32768;
   if (blk[2][73]==1) dofreq=dofreq+16384;
   if (blk[2][74]==1) dofreq=dofreq+8192;
   if (blk[2][75]==1) dofreq=dofreq+4096;
   if (blk[2][76]==1) dofreq=dofreq+2048;
   if (blk[2][77]==1) dofreq=dofreq+1024;
   if (blk[2][78]==1) dofreq=dofreq+512;
   if (blk[2][79]==1) dofreq=dofreq+256;
   if (blk[2][84]==1) dofreq=dofreq+128;
   if (blk[2][85]==1) dofreq=dofreq+64;
   if (blk[2][86]==1) dofreq=dofreq+32;
   if (blk[2][87]==1) dofreq=dofreq+16;
   if (blk[2][88]==1) dofreq=dofreq+8;
   if (blk[2][89]==1) dofreq=dofreq+4;
   if (blk[2][90]==1) dofreq=dofreq+2;
   if (blk[2][91]==1) dofreq++;
   sprintf(chline[5],"UPFREQ 6=%d",upfreq);
   sprintf(tmp," DOFREQ 6=%d",dofreq);
   strcat(chline[5],tmp);
   upf[5]=euro_calc(upfreq);
   dof[5]=euro_calc(dofreq);
   } 

  if (channels>6)
   {	
   upfreq=0;
   if (blk[2][96]==1) upfreq=32768;
   if (blk[2][97]==1) upfreq=upfreq+16384;
   if (blk[2][98]==1) upfreq=upfreq+8192;
   if (blk[2][99]==1) upfreq=upfreq+4096;
   if (blk[2][100]==1) upfreq=upfreq+2048;
   if (blk[2][101]==1) upfreq=upfreq+1024;
   if (blk[2][102]==1) upfreq=upfreq+512;
   if (blk[2][103]==1) upfreq=upfreq+256;
   if (blk[2][108]==1) upfreq=upfreq+128;
   if (blk[2][109]==1) upfreq=upfreq+64;
   if (blk[2][110]==1) upfreq=upfreq+32;
   if (blk[2][111]==1) upfreq=upfreq+16;
   if (blk[2][112]==1) upfreq=upfreq+8;
   if (blk[2][113]==1) upfreq=upfreq+4;
   if (blk[2][114]==1) upfreq=upfreq+2;
   if (blk[2][115]==1) upfreq++;
   dofreq=0;
   if (blk[2][120]==1) dofreq=32768;
   if (blk[2][121]==1) dofreq=dofreq+16384;
   if (blk[2][122]==1) dofreq=dofreq+8192;
   if (blk[2][123]==1) dofreq=dofreq+4096;
   if (blk[2][124]==1) dofreq=dofreq+2048;
   if (blk[2][125]==1) dofreq=dofreq+1024;
   if (blk[2][126]==1) dofreq=dofreq+512;
   if (blk[2][127]==1) dofreq=dofreq+256;
   if (blk[2][132]==1) dofreq=dofreq+128;
   if (blk[2][133]==1) dofreq=dofreq+64;
   if (blk[2][134]==1) dofreq=dofreq+32;
   if (blk[2][135]==1) dofreq=dofreq+16;
   if (blk[2][136]==1) dofreq=dofreq+8;
   if (blk[2][137]==1) dofreq=dofreq+4;
   if (blk[2][138]==1) dofreq=dofreq+2;
   if (blk[2][139]==1) dofreq++;
   sprintf(chline[6],"UPFREQ 7=%d",upfreq);
   sprintf(tmp," DOFREQ 7=%d",dofreq);
   strcat(chline[6],tmp);
   upf[6]=euro_calc(upfreq);
   dof[6]=euro_calc(dofreq);
   } 

  if (channels>7)
   {	
   upfreq=0;
   if (blk[2][144]==1) upfreq=32768;
   if (blk[2][145]==1) upfreq=upfreq+16384;
   if (blk[2][146]==1) upfreq=upfreq+8192;
   if (blk[2][147]==1) upfreq=upfreq+4096;
   if (blk[2][148]==1) upfreq=upfreq+2048;
   if (blk[2][149]==1) upfreq=upfreq+1024;
   if (blk[2][150]==1) upfreq=upfreq+512;
   if (blk[2][151]==1) upfreq=upfreq+256;
   if (blk[2][156]==1) upfreq=upfreq+128;
   if (blk[2][157]==1) upfreq=upfreq+64;
   if (blk[2][158]==1) upfreq=upfreq+32;
   if (blk[2][159]==1) upfreq=upfreq+16;
   if (blk[2][160]==1) upfreq=upfreq+8;
   if (blk[2][161]==1) upfreq=upfreq+4;
   if (blk[2][162]==1) upfreq=upfreq+2;
   if (blk[2][163]==1) upfreq++;
   dofreq=0;
   if (blk[2][168]==1) dofreq=32768;
   if (blk[2][169]==1) dofreq=dofreq+16384;
   if (blk[2][170]==1) dofreq=dofreq+8192;
   if (blk[2][171]==1) dofreq=dofreq+4096;
   if (blk[2][172]==1) dofreq=dofreq+2048;
   if (blk[2][173]==1) dofreq=dofreq+1024;
   if (blk[2][174]==1) dofreq=dofreq+512;
   if (blk[2][175]==1) dofreq=dofreq+256;
   if (blk[2][180]==1) dofreq=dofreq+128;
   if (blk[2][181]==1) dofreq=dofreq+64;
   if (blk[2][182]==1) dofreq=dofreq+32;
   if (blk[2][183]==1) dofreq=dofreq+16;
   if (blk[2][184]==1) dofreq=dofreq+8;
   if (blk[2][185]==1) dofreq=dofreq+4;
   if (blk[2][186]==1) dofreq=dofreq+2;
   if (blk[2][187]==1) dofreq++;
   sprintf(chline[7],"UPFREQ 8=%d",upfreq);
   sprintf(tmp," DOFREQ 8=%d",dofreq);
   strcat(chline[7],tmp);
   upf[7]=euro_calc(upfreq);
   dof[7]=euro_calc(dofreq);
   } 

  }

 // Does the user want the info displaying ? //
 if (display_svp==TRUE)
  { 
  if (channels>7)
   {
   strcpy(s,chline[7]);
   rotate();
   }

  if (channels>6)
   {
   strcpy(s,chline[6]);
   rotate();
   }

  if (channels>5)
   {
   strcpy(s,chline[5]);
   rotate();
   }

  if (channels>4)
   {
   strcpy(s,chline[4]);
   rotate();
   }

  if (channels>3)
   {
   strcpy(s,chline[3]);
   rotate();
   }

  if (channels>2)
   {
   strcpy(s,chline[2]);
   rotate();
   }

  if (channels>1)
   {
   strcpy(s,chline[1]);
   rotate();
   }

  if (channels>0)
   {
   strcpy(s,chline[0]);
   rotate();
   strcpy(s,line5);
   rotate();
   }
  // Below are always in a Type 1 //
  strcpy(s,line4);
  rotate();
  strcpy(s,line3);
  rotate();
  strcpy(s,line2);
  rotate();
  strcpy(s,line1);
  rotate();
  strcpy(s,line0);
  rotate();
  display_stub();
  ready=2;
  }

 // Write to disk //
 if (logging==TRUE && display_svp==TRUE)
  {
  write_stub();
  logout.Write(line0,strlen(line0));
  logout.Write(enc,1);
  logout.Write(line1,strlen(line1));
  logout.Write(enc,1);
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  if (channels>0)
   {
   logout.Write(line5,strlen(line5));
   logout.Write(enc,1);
   logout.Write(chline[0],strlen(chline[0]));
   logout.Write(enc,1);
   }
  if (channels>1)
   {
   logout.Write(chline[1],strlen(chline[1]));
   logout.Write(enc,1);
   }
  if (channels>2)
   {
   logout.Write(chline[2],strlen(chline[2]));
   logout.Write(enc,1);
   }
  if (channels>3)
   {
   logout.Write(chline[3],strlen(chline[3]));
   logout.Write(enc,1);
   }
  if (channels>4)
   {
   logout.Write(chline[4],strlen(chline[4]));
   logout.Write(enc,1);
   }
  if (channels>5)
   {
   logout.Write(chline[5],strlen(chline[5]));
   logout.Write(enc,1);
   }
  if (channels>6)
   {
   logout.Write(chline[6],strlen(chline[6]));
   logout.Write(enc,1);
   }
  if (channels>7)
   {
   logout.Write(chline[7],strlen(chline[7]));
   logout.Write(enc,1);
   }

  }
 }

// Type 2 //
if (svptype==2)
 {
 char line1[80],line2[80];
 unsigned char chatyp;
 unsigned int upfreq,dofreq;

 chatyp=0;
 if (blk[0][84]==1) chatyp=128;
 if (blk[0][85]==1) chatyp=chatyp+64;
 if (blk[0][86]==1) chatyp=chatyp+32;
 if (blk[0][87]==1) chatyp=chatyp+16;
 if (blk[0][88]==1) chatyp=chatyp+8;
 if (blk[0][89]==1) chatyp=chatyp+4;
 if (blk[0][90]==1) chatyp=chatyp+2;
 if (blk[0][91]==1) chatyp++;
 if (chatyp==1) strcpy(line1,"Local system channel opened");
 if (chatyp==2) strcpy(line1,"Not used (ignore that order)");
 if (chatyp==3) strcpy(line1,"Local system channel closed");
 if (chatyp==4) strcpy(line1,"Access channel opened");
 if (chatyp==5) strcpy(line1,"Access channel closed");

 upfreq=0;
 if (blk[0][96]==1) upfreq=32768;
 if (blk[0][97]==1) upfreq=upfreq+16384;
 if (blk[0][98]==1) upfreq=upfreq+8192;
 if (blk[0][99]==1) upfreq=upfreq+4096;
 if (blk[0][100]==1) upfreq=upfreq+2048;
 if (blk[0][101]==1) upfreq=upfreq+1024;
 if (blk[0][102]==1) upfreq=upfreq+512;
 if (blk[0][103]==1) upfreq=upfreq+256;
 if (blk[0][108]==1) upfreq=upfreq+128;
 if (blk[0][109]==1) upfreq=upfreq+64;
 if (blk[0][110]==1) upfreq=upfreq+32;
 if (blk[0][111]==1) upfreq=upfreq+16;
 if (blk[0][112]==1) upfreq=upfreq+8;
 if (blk[0][113]==1) upfreq=upfreq+4;
 if (blk[0][114]==1) upfreq=upfreq+2;
 if (blk[0][115]==1) upfreq++;
 sprintf(line2,"UPFREQ=%d",upfreq);

 dofreq=0;
 if (blk[0][120]==1) dofreq=32768;
 if (blk[0][121]==1) dofreq=dofreq+16384;
 if (blk[0][122]==1) dofreq=dofreq+8192;
 if (blk[0][123]==1) dofreq=dofreq+4096;
 if (blk[0][124]==1) dofreq=dofreq+2048;
 if (blk[0][125]==1) dofreq=dofreq+1024;
 if (blk[0][126]==1) dofreq=dofreq+512;
 if (blk[0][127]==1) dofreq=dofreq+256;
 if (blk[0][132]==1) dofreq=dofreq+128;
 if (blk[0][133]==1) dofreq=dofreq+64;
 if (blk[0][134]==1) dofreq=dofreq+32;
 if (blk[0][135]==1) dofreq=dofreq+16;
 if (blk[0][136]==1) dofreq=dofreq+8;
 if (blk[0][137]==1) dofreq=dofreq+4;
 if (blk[0][138]==1) dofreq=dofreq+2;
 if (blk[0][139]==1) dofreq++;
 sprintf(tmp," DOFREQ=%d",dofreq);
 strcat (line2,tmp);

 if (display_svp==TRUE)
  {
  strcpy(s,line2);
  rotate();
  strcpy(s,line1);
  rotate();
  strcpy(s,line0);
  rotate();
  display_stub();
  ready=2;
  }

 // Write to disk //
 if (logging && display_svp==TRUE)
  {
  write_stub();
  logout.Write(line0,strlen(line0));
  logout.Write(enc,1);
  logout.Write(line1,strlen(line1));
  logout.Write(enc,1);
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }
 }

}

// Handle a REB Frame //
void moby::reb (void)
{
char line0[80],line1[80];
unsigned int a,bad;

blank_line();

strcpy(line0,"<REB>");

bad=0;
for (a=72;a<=79;a++)
 if (blk[0][a]==1) bad++;

for (a=84;a<=91;a++)
 if (blk[0][a]==1) bad++;

for (a=96;a<=103;a++)
 if (blk[0][a]==1) bad++;

for (a=108;a<=115;a++)
 if (blk[0][a]==1) bad++;

for (a=120;a<=127;a++)
 if (blk[0][a]==1) bad++;

for (a=132;a<=139;a++)
 if (blk[0][a]==1) bad++;

for (a=144;a<=151;a++)
 if (blk[0][a]==1) bad++;

for (a=156;a<=163;a++)
 if (blk[0][a]==1) bad++;

for (a=168;a<=175;a++)
 if (blk[0][a]==1) bad++;

for (a=180;a<=187;a++)
 if (blk[0][a]==1) bad++;

for (a=192;a<=199;a++)
 if (blk[0][a]==1) bad++;

for (a=204;a<=211;a++)
 if (blk[0][a]==1) bad++;

if (bad>1)
 {
 sprintf(line1,"%d",bad);
 strcat(line1," blocks need repeating");
 }
else
 {
 sprintf(line1,"%d",bad);
 strcat(line1," block needs repeating");
 }

strcpy(s,line1);
rotate();
strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 }

}

// Handle an ABD or ABL frame //
void moby::abx (void)
{
char line0[40],line1[80],tmp[80];
unsigned char block_n,numret;

blank_line();

if (frame==6) strcpy(line0,"<ABD>");
if (frame==8) strcpy(line0,"<ABL>");

block_n=0;
if (blk[0][48]==1) block_n=128;
if (blk[0][49]==1) block_n=block_n+64;
if (blk[0][50]==1) block_n=block_n+32;
if (blk[0][51]==1) block_n=block_n+16;
if (blk[0][52]==1) block_n=block_n+8;
if (blk[0][53]==1) block_n=block_n+4;
if (blk[0][54]==1) block_n=block_n+2;
if (blk[0][55]==1) block_n++;
sprintf(line1,"BLOCK N=%d",block_n);

numret=0;
if (blk[0][60]==1) numret=128;
if (blk[0][61]==1) numret=numret+64;
if (blk[0][62]==1) numret=numret+32;
if (blk[0][63]==1) numret=numret+16;
if (blk[0][64]==1) numret=numret+8;
if (blk[0][65]==1) numret=numret+4;
if (blk[0][66]==1) numret=numret+2;
if (blk[0][67]==1) numret++;
sprintf(tmp," NUMRET=%d",numret);
strcat(line1,tmp);

strcpy(s,line1);
rotate();
strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 }

}

// Handle a TST Frame //
void moby::tst (void)
{
char line0[80];
unsigned char prio,mask;

blank_line();

strcpy(line0,"<TST> ");

prio=0;
if (blk[0][48]==1) prio=4;
if (blk[0][49]==1) prio=prio+2;
if (blk[0][50]==1) prio++;
if (prio==7) strcat(line0,"(Priority Group 4R)");
if (prio==6) strcat(line0,"(Priority Group 4N)");
if (prio==5) strcat(line0,"(Priority Group 3R)");
if (prio==4) strcat(line0,"(Priority Group 3N)");
if (prio==3) strcat(line0,"(Priority Group 2R)");
if (prio==2) strcat(line0,"(Priority Group 2N)");
if (prio==1) strcat(line0,"(Priority Group 1R)");
if (prio==0) strcat(line0,"(Priority Group 1N)");

mask=0;

strcpy(s,line0);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 }

}

// Handle the HPDATA mpak //
void moby::hpdata (void)
{
unsigned long int t;
unsigned char pin;
char protocol[40],line0[200];

strcpy(line0,"HPDATA "); 

// If no address list //
if (blk[0][77+f]==0)
 {
 // Work out the mobitex time //
 t=0;
 if (blk[0][127+f]==1) t=1;
 if (blk[0][126+f]==1) t=t+2;
 if (blk[0][125+f]==1) t=t+4;
 if (blk[0][124+f]==1) t=t+8;
 if (blk[0][123+f]==1) t=t+16;
 if (blk[0][122+f]==1) t=t+32;
 if (blk[0][121+f]==1) t=t+64;
 if (blk[0][120+f]==1) t=t+128;
 if (blk[0][115+f]==1) t=t+256;
 if (blk[0][114+f]==1) t=t+512;
 if (blk[0][113+f]==1) t=t+1024;
 if (blk[0][112+f]==1) t=t+2048;
 if (blk[0][111+f]==1) t=t+4096;
 if (blk[0][110+f]==1) t=t+8192;
 if (blk[0][109+f]==1) t=t+16384;
 if (blk[0][108+f]==1) t=t+32768;
 if (blk[0][103+f]==1) t=t+65536;
 if (blk[0][102+f]==1) t=t+131072;
 if (blk[0][101+f]==1) t=t+262144;
 if (blk[0][100+f]==1) t=t+524288;
 if (blk[0][99+f]==1) t=t+1048576;
 if (blk[0][98+f]==1) t=t+2097152;
 if (blk[0][97+f]==1) t=t+4194304;
 if (blk[0][96+f]==1) t=t+8388608; 
 moby_time(t);
 strcat(line0,ts);

 // Work out the protocol ID number //
 pin=0;
 if (blk[0][211]==1) pin=1;
 if (blk[0][210]==1) pin=pin+2;
 if (blk[0][209]==1) pin=pin+4;
 if (blk[0][208]==1) pin=pin+8;
 if (blk[0][207]==1) pin=pin+16;
 if (blk[0][206]==1) pin=pin+32;
 if (blk[0][205]==1) pin=pin+64;
 if (blk[0][204]==1) pin=pin+128;
 if (pin==0) strcpy(protocol," No Protocol Identified");
 if (pin>0 && pin<128) sprintf(protocol," Network Defined Protocol No.%d",pin);
 if (pin>127) sprintf(protocol," User Defined Protocol No.%d",pin);            
 if (pin==1) strcpy(protocol," Gateway Protocol");
 if (pin==3) strcpy(protocol," MTP/1 Protocol");
 if (pin==4) strcpy(protocol," Messaging Protocol");
 if (pin==7) strcpy(protocol," RAMP Protocol");
 if (pin==127) strcpy(protocol," RNM Protocol");  
 strcat(line0,protocol);

 // Does the user want this kind of HPDATA ? //
 if (pin>127 && hpdata_user_show==FALSE) return;
 if (pin==1 && hpdata_gateway_show==FALSE) return;
 if (pin==3 && hpdata_mtp1_show==FALSE) return;
 if (pin==4 && hpdata_messaging_show==FALSE) return;
 if (pin==7 && hpdata_ramp_show==FALSE) return;
 if (pin==127 && hpdata_rnm_show==FALSE) return;
 
 blank_line();

 extract_data();

 // Display any MTP/1 protocol messages //
 if (pin==3)
  {
  decode_mtp1(line0);
  return;
  }

 // Display any Messaging protocol messages //
 if (pin==4)
  {
  decode_messaging(line0);
  return;
  }

 
 // Display any Protocol 135 GGA messages //
 if (pin==135 && by[5]==71 && by[6]==71 && by[7]==65 )
  {
  decode_nmea_gga(line0);
  return;
  }

 // Display any Protocol 151 RMC messages //
 if (pin==151 && by[6]==82 && by[7]==77 && by[8]==67)
  {
  decode_nmea_rmc(line0);
  return;
  }


 // Display all HPDATA (User) messages as ASCII //
 if (pin>127 && hpdata_130_show==TRUE) 
  {
  ascii_protocols(line0,0);
  return;
  }

 hex_protocols(line0,0);

 }
} 

void moby::rotate (void)
{
strcpy(s119,s118);
strcpy(s118,s117);
strcpy(s117,s116);
strcpy(s116,s115);
strcpy(s115,s114);
strcpy(s114,s113);
strcpy(s113,s112);
strcpy(s112,s111); 
strcpy(s111,s110);
strcpy(s110,s109);
strcpy(s109,s108);
strcpy(s108,s107);
strcpy(s107,s106);
strcpy(s106,s105);
strcpy(s105,s104);
strcpy(s104,s103);
strcpy(s103,s102); 
strcpy(s102,s101);
strcpy(s101,s100);
strcpy(s100,s99);
strcpy(s99,s98);
strcpy(s98,s97);
strcpy(s97,s96);
strcpy(s96,s95);
strcpy(s95,s94);
strcpy(s94,s93);
strcpy(s93,s92); 
strcpy(s92,s91);
strcpy(s91,s90);
strcpy(s90,s89);
strcpy(s89,s88);
strcpy(s88,s87);
strcpy(s87,s86);
strcpy(s86,s85);
strcpy(s85,s84);
strcpy(s84,s83);
strcpy(s83,s82); 
strcpy(s82,s81);
strcpy(s81,s80);
strcpy(s80,s79);
strcpy(s79,s78);
strcpy(s78,s77);
strcpy(s77,s76);
strcpy(s76,s75);
strcpy(s75,s74);
strcpy(s74,s73);
strcpy(s73,s72); 
strcpy(s72,s71);
strcpy(s71,s70);
strcpy(s70,s69);
strcpy(s69,s68);
strcpy(s68,s67);
strcpy(s67,s66);
strcpy(s66,s65);
strcpy(s65,s64);
strcpy(s64,s63);
strcpy(s63,s62); 
strcpy(s62,s61);
strcpy(s61,s60);
strcpy(s60,s59);
strcpy(s59,s58);
strcpy(s58,s57);
strcpy(s57,s56);
strcpy(s56,s55);
strcpy(s55,s54);
strcpy(s54,s53);
strcpy(s53,s52); 
strcpy(s52,s51);
strcpy(s51,s50);
strcpy(s50,s49);
strcpy(s49,s48);
strcpy(s48,s47);
strcpy(s47,s46);
strcpy(s46,s45);
strcpy(s45,s44);
strcpy(s44,s43);
strcpy(s43,s42); 
strcpy(s42,s41);
strcpy(s41,s40);
strcpy(s40,s39);
strcpy(s39,s38);
strcpy(s38,s37);
strcpy(s37,s36);
strcpy(s36,s35);
strcpy(s35,s34);
strcpy(s34,s33);
strcpy(s33,s32); 
strcpy(s32,s31);
strcpy(s31,s30); 	
strcpy(s30,s29);
strcpy(s29,s28);
strcpy(s28,s27);
strcpy(s27,s26);
strcpy(s26,s25);
strcpy(s25,s24);
strcpy(s24,s23);
strcpy(s23,s22); 
strcpy(s22,s21);
strcpy(s21,s20);
strcpy(s20,s19);
strcpy(s19,s18);
strcpy(s18,s17);
strcpy(s17,s16);
strcpy(s16,s15);
strcpy(s15,s14);
strcpy(s14,s13);
strcpy(s13,s12);
strcpy(s12,s11);
strcpy(s11,s10);
strcpy(s10,s9);
strcpy(s9,s8);
strcpy(s8,s7);
strcpy(s7,s6);
strcpy(s6,s5);
strcpy(s5,s4);
strcpy(s4,s3);
strcpy(s3,s2);
strcpy(s2,s1);
strcpy(s1,s0);
strcpy(s0,s);

}

// deal with DATA mpaks //
void moby::data (void)
{
unsigned long int t;
char line0[200];

blank_line();

strcpy(line0,"DATA "); 

// If no address list //
if (blk[0][77+f]==0)
 {
 // Work out the mobitex time //
 t=0;
 if (blk[0][127+f]==1) t=1;
 if (blk[0][126+f]==1) t=t+2;
 if (blk[0][125+f]==1) t=t+4;
 if (blk[0][124+f]==1) t=t+8;
 if (blk[0][123+f]==1) t=t+16;
 if (blk[0][122+f]==1) t=t+32;
 if (blk[0][121+f]==1) t=t+64;
 if (blk[0][120+f]==1) t=t+128;
 if (blk[0][115+f]==1) t=t+256;
 if (blk[0][114+f]==1) t=t+512;
 if (blk[0][113+f]==1) t=t+1024;
 if (blk[0][112+f]==1) t=t+2048;
 if (blk[0][111+f]==1) t=t+4096;
 if (blk[0][110+f]==1) t=t+8192;
 if (blk[0][109+f]==1) t=t+16384;
 if (blk[0][108+f]==1) t=t+32768;
 if (blk[0][103+f]==1) t=t+65536;
 if (blk[0][102+f]==1) t=t+131072;
 if (blk[0][101+f]==1) t=t+262144;
 if (blk[0][100+f]==1) t=t+524288;
 if (blk[0][99+f]==1) t=t+1048576;
 if (blk[0][98+f]==1) t=t+2097152;
 if (blk[0][97+f]==1) t=t+4194304;
 if (blk[0][96+f]==1) t=t+8388608; 
 moby_time(t);
 strcat(line0,ts);

 extract_data();

 if (data_ascii_show==TRUE)
  {
  ascii_protocols(line0,1);
  return;
  }

 hex_protocols(line0,1);

 }

}

// Handle STATUS mpak with no address list //
void moby::statusa (void)
{
unsigned long int t;
unsigned char st;
char line[300],tmp[100];

blank_line();

strcpy(s,"STATUS");

// Status byte //
st=0;      
if (blk[0][211]==1) st=1;
if (blk[0][210]==1) st=st+2; 
if (blk[0][209]==1) st=st+4;
if (blk[0][208]==1) st=st+8;  
if (blk[0][207]==1) st=st+16;
if (blk[0][206]==1) st=st+32; 
if (blk[0][205]==1) st=st+64;
if (blk[0][204]==1) st=st+128;
sprintf(tmp," #%x",st);
strcat(s,tmp);
strcpy(tmp," ");
strcat(s,tmp);

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);
strcat(s,ts);

rotate();
strcpy(line,s);

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle STATUS mpak with address list //
void moby::statusb (void)
{
unsigned long int t,add1,add2,add3,add4,add5,add6,add7;
unsigned char st,num;
char line0[300],line1[300],line2[300],line3[300],line4[300],line5[300],line6[300],line7[300],tmp[100];

blank_line();

// Calculate number of addresses //
num=0;
if (blk[0][168]==1) num=128;
if (blk[0][169]==1) num=num+64;
if (blk[0][170]==1) num=num+32;
if (blk[0][171]==1) num=num+16;
if (blk[0][172]==1) num=num+8;
if (blk[0][173]==1) num=num+4;
if (blk[0][174]==1) num=num+2;
if (blk[0][175]==1) num++;

// First address //
add1=0;
if (blk[0][211]==1) add1=1;
if (blk[0][210]==1) add1=add1+2;
if (blk[0][209]==1) add1=add1+4;
if (blk[0][208]==1) add1=add1+8;
if (blk[0][207]==1) add1=add1+16;
if (blk[0][206]==1) add1=add1+32;
if (blk[0][205]==1) add1=add1+64;
if (blk[0][204]==1) add1=add1+128;
if (blk[0][199]==1) add1=add1+256;
if (blk[0][198]==1) add1=add1+512;
if (blk[0][197]==1) add1=add1+1024;
if (blk[0][196]==1) add1=add1+2048;
if (blk[0][195]==1) add1=add1+4096;
if (blk[0][194]==1) add1=add1+8192;
if (blk[0][193]==1) add1=add1+16384;
if (blk[0][192]==1) add1=add1+32768;
if (blk[0][187]==1) add1=add1+65536;
if (blk[0][186]==1) add1=add1+131072;
if (blk[0][185]==1) add1=add1+262144;
if (blk[0][184]==1) add1=add1+524288;
if (blk[0][183]==1) add1=add1+1048576;
if (blk[0][182]==1) add1=add1+2097152;
if (blk[0][181]==1) add1=add1+4194304;
if (blk[0][180]==1) add1=add1+8388608; 

// Second address //
add2=0;
if (blk[1][31]==1) add2=1;
if (blk[1][30]==1) add2=add2+2;
if (blk[1][29]==1) add2=add2+4;
if (blk[1][28]==1) add2=add2+8;
if (blk[1][27]==1) add2=add2+16;
if (blk[1][26]==1) add2=add2+32;
if (blk[1][25]==1) add2=add2+64;
if (blk[1][24]==1) add2=add2+128;
if (blk[1][19]==1) add2=add2+256;
if (blk[1][18]==1) add2=add2+512;
if (blk[1][17]==1) add2=add2+1024;
if (blk[1][16]==1) add2=add2+2048;
if (blk[1][15]==1) add2=add2+4096;
if (blk[1][14]==1) add2=add2+8192;
if (blk[1][13]==1) add2=add2+16384;
if (blk[1][12]==1) add2=add2+32768;
if (blk[1][7]==1) add2=add2+65536;
if (blk[1][6]==1) add2=add2+131072;
if (blk[1][5]==1) add2=add2+262144;
if (blk[1][4]==1) add2=add2+524288;
if (blk[1][3]==1) add2=add2+1048576;
if (blk[1][2]==1) add2=add2+2097152;
if (blk[1][1]==1) add2=add2+4194304;
if (blk[1][0]==1) add2=add2+8388608; 

// Third address //
add3=0;
if (blk[1][67]==1) add3=1;
if (blk[1][66]==1) add3=add3+2;
if (blk[1][65]==1) add3=add3+4;
if (blk[1][64]==1) add3=add3+8;
if (blk[1][63]==1) add3=add3+16;
if (blk[1][62]==1) add3=add3+32;
if (blk[1][61]==1) add3=add3+64;
if (blk[1][60]==1) add3=add3+128;
if (blk[1][55]==1) add3=add3+256;
if (blk[1][54]==1) add3=add3+512;
if (blk[1][53]==1) add3=add3+1024;
if (blk[1][52]==1) add3=add3+2048;
if (blk[1][51]==1) add3=add3+4096;
if (blk[1][50]==1) add3=add3+8192;
if (blk[1][49]==1) add3=add3+16384;
if (blk[1][48]==1) add3=add3+32768;
if (blk[1][43]==1) add3=add3+65536;
if (blk[1][42]==1) add3=add3+131072;
if (blk[1][41]==1) add3=add3+262144;
if (blk[1][40]==1) add3=add3+524288;
if (blk[1][39]==1) add3=add3+1048576;
if (blk[1][38]==1) add3=add3+2097152;
if (blk[1][37]==1) add3=add3+4194304;
if (blk[1][36]==1) add3=add3+8388608; 

// Fourth address //
add4=0;
if (blk[1][103]==1) add4=1;
if (blk[1][102]==1) add4=add4+2;
if (blk[1][101]==1) add4=add4+4;
if (blk[1][100]==1) add4=add4+8;
if (blk[1][99]==1) add4=add4+16;
if (blk[1][98]==1) add4=add4+32;
if (blk[1][97]==1) add4=add4+64;
if (blk[1][96]==1) add4=add4+128;
if (blk[1][91]==1) add4=add4+256;
if (blk[1][90]==1) add4=add4+512;
if (blk[1][89]==1) add4=add4+1024;
if (blk[1][88]==1) add4=add4+2048;
if (blk[1][87]==1) add4=add4+4096;
if (blk[1][86]==1) add4=add4+8192;
if (blk[1][85]==1) add4=add4+16384;
if (blk[1][84]==1) add4=add4+32768;
if (blk[1][79]==1) add4=add4+65536;
if (blk[1][78]==1) add4=add4+131072;
if (blk[1][77]==1) add4=add4+262144;
if (blk[1][76]==1) add4=add4+524288;
if (blk[1][75]==1) add4=add4+1048576;
if (blk[1][74]==1) add4=add4+2097152;
if (blk[1][73]==1) add4=add4+4194304;
if (blk[1][72]==1) add4=add4+8388608; 

// Fifth address //
add5=0;
if (blk[1][139]==1) add5=1;
if (blk[1][138]==1) add5=add5+2;
if (blk[1][137]==1) add5=add5+4;
if (blk[1][136]==1) add5=add5+8;
if (blk[1][135]==1) add5=add5+16;
if (blk[1][134]==1) add5=add5+32;
if (blk[1][133]==1) add5=add5+64;
if (blk[1][132]==1) add5=add5+128;
if (blk[1][127]==1) add5=add5+256;
if (blk[1][126]==1) add5=add5+512;
if (blk[1][125]==1) add5=add5+1024;
if (blk[1][124]==1) add5=add5+2048;
if (blk[1][123]==1) add5=add5+4096;
if (blk[1][122]==1) add5=add5+8192;
if (blk[1][121]==1) add5=add5+16384;
if (blk[1][120]==1) add5=add5+32768;
if (blk[1][115]==1) add5=add5+65536;
if (blk[1][114]==1) add5=add5+131072;
if (blk[1][113]==1) add5=add5+262144;
if (blk[1][112]==1) add5=add5+524288;
if (blk[1][111]==1) add5=add5+1048576;
if (blk[1][110]==1) add5=add5+2097152;
if (blk[1][109]==1) add5=add5+4194304;
if (blk[1][108]==1) add5=add5+8388608; 

// Sixth address //
add6=0;
if (blk[1][175]==1) add6=1;
if (blk[1][174]==1) add6=add6+2;
if (blk[1][173]==1) add6=add6+4;
if (blk[1][172]==1) add6=add6+8;
if (blk[1][171]==1) add6=add6+16;
if (blk[1][170]==1) add6=add6+32;
if (blk[1][169]==1) add6=add6+64;
if (blk[1][168]==1) add6=add6+128;
if (blk[1][163]==1) add6=add6+256;
if (blk[1][162]==1) add6=add6+512;
if (blk[1][161]==1) add6=add6+1024;
if (blk[1][160]==1) add6=add6+2048;
if (blk[1][159]==1) add6=add6+4096;
if (blk[1][158]==1) add6=add6+8192;
if (blk[1][157]==1) add6=add6+16384;
if (blk[1][156]==1) add6=add6+32768;
if (blk[1][151]==1) add6=add6+65536;
if (blk[1][150]==1) add6=add6+131072;
if (blk[1][149]==1) add6=add6+262144;
if (blk[1][148]==1) add6=add6+524288;
if (blk[1][147]==1) add6=add6+1048576;
if (blk[1][146]==1) add6=add6+2097152;
if (blk[1][145]==1) add6=add6+4194304;
if (blk[1][144]==1) add6=add6+8388608; 

// Seventh address //
add7=0;
if (blk[1][211]==1) add7=1;
if (blk[1][210]==1) add7=add7+2;
if (blk[1][209]==1) add7=add7+4;
if (blk[1][208]==1) add7=add7+8;
if (blk[1][207]==1) add7=add7+16;
if (blk[1][206]==1) add7=add7+32;
if (blk[1][205]==1) add7=add7+64;
if (blk[1][204]==1) add7=add7+128;
if (blk[1][199]==1) add7=add7+256;
if (blk[1][198]==1) add7=add7+512;
if (blk[1][197]==1) add7=add7+1024;
if (blk[1][196]==1) add7=add7+2048;
if (blk[1][195]==1) add7=add7+4096;
if (blk[1][194]==1) add7=add7+8192;
if (blk[1][193]==1) add7=add7+16384;
if (blk[1][192]==1) add7=add7+32768;
if (blk[1][187]==1) add7=add7+65536;
if (blk[1][186]==1) add7=add7+131072;
if (blk[1][185]==1) add7=add7+262144;
if (blk[1][184]==1) add7=add7+524288;
if (blk[1][183]==1) add7=add7+1048576;
if (blk[1][182]==1) add7=add7+2097152;
if (blk[1][181]==1) add7=add7+4194304;
if (blk[1][180]==1) add7=add7+8388608; 

// Calculate time //
t=0;
if (blk[2][31]==1) t=1;
if (blk[2][30]==1) t=t+2;
if (blk[2][29]==1) t=t+4;
if (blk[2][28]==1) t=t+8;
if (blk[2][27]==1) t=t+16;
if (blk[2][26]==1) t=t+32;
if (blk[2][25]==1) t=t+64;
if (blk[2][24]==1) t=t+128;
if (blk[2][19]==1) t=t+256;
if (blk[2][18]==1) t=t+512;
if (blk[2][17]==1) t=t+1024;
if (blk[2][16]==1) t=t+2048;
if (blk[2][15]==1) t=t+4096;
if (blk[2][14]==1) t=t+8192;
if (blk[2][13]==1) t=t+16384;
if (blk[2][12]==1) t=t+32768;
if (blk[2][7]==1) t=t+65536;
if (blk[2][6]==1) t=t+131072;
if (blk[2][5]==1) t=t+262144;
if (blk[2][4]==1) t=t+524288;
if (blk[2][3]==1) t=t+1048576;
if (blk[2][2]==1) t=t+2097152;
if (blk[2][1]==1) t=t+4194304;
if (blk[2][0]==1) t=t+8388608; 
moby_time(t);

// Status byte //
st=0;      
if (blk[2][43]==1) st=1;
if (blk[2][42]==1) st=st+2; 
if (blk[2][41]==1) st=st+4;
if (blk[2][40]==1) st=st+8;  
if (blk[2][39]==1) st=st+16;
if (blk[2][38]==1) st=st+32; 
if (blk[2][37]==1) st=st+64;
if (blk[2][36]==1) st=st+128;

// Display Section //
sprintf(line0,"STATUS #%x",st);
strcpy(tmp," ");
strcat(line0,tmp);
strcat(line0,ts);
strcpy(s,line0);
rotate();

// Show line 7 ? //
if (num>6)
 {
 if (get_identity(add7)==TRUE) strcpy(line7,user_name);
  else sprintf(line7,"%x",add7);
 }

// Show line 6 ? //
if (num>5)
 {
 if (get_identity(add6)==TRUE) strcpy(line6,user_name);
  else sprintf(line6,"%x",add6);
 }

// Show line 5 ? //
if (num>4)
 {
 if (get_identity(add5)==TRUE) strcpy(line5,user_name);
  else sprintf(line5,"%x",add5);
 }

// Show line 4 ? //
if (num>3)
 {
 if (get_identity(add4)==TRUE) strcpy(line4,user_name);
  else sprintf(line4,"%x",add4);
 }

// Show line 3 ? //
if (num>2)
 {
 if (get_identity(add3)==TRUE) strcpy(line3,user_name);
  else sprintf(line3,"%x",add3);
 }

// Show line 2 ? //
if (num>1)
 {
 if (get_identity(add2)==TRUE) strcpy(line2,user_name);
  else sprintf(line2,"%x",add2);
 }

// Line1 is always present //
if (get_identity(add1)==TRUE) strcpy(line1,user_name);
 else sprintf(line1,"%x",add1);

display_stub();
ready=2;

if (logging)
 {
 write_stub();
 // Line 1 always present //
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 // Line 2 ? //
 if (num>1)
  {
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }
 // Line 3 ? //
 if (num>2)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }
 // Line 4 ? //
 if (num>3)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }
 // Line 5 ? //
 if (num>4)
  {
  logout.Write(line5,strlen(line5));
  logout.Write(enc,1);
  }
  // Line 6 ? //
 if (num>5)
  {
  logout.Write(line6,strlen(line6));
  logout.Write(enc,1);
  }
  // Line 7 ? //
 if (num>6)
  {
  logout.Write(line7,strlen(line7));
  logout.Write(enc,1);
  }
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 }

}

// Handle ESNREQ mpack //
void moby::esnreq (void)
{
char line[300];
blank_line();
strcpy(s,"ESNREQ");

strcpy(line,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle ESNINFO mpak //
void moby::esninfo (void)
{
char line[300];
unsigned long t;

// Calculate the ESN //
t=0;
if (blk[0][139+f]==1) t=1;
if (blk[0][138+f]==1) t=t+2;
if (blk[0][137+f]==1) t=t+4;
if (blk[0][136+f]==1) t=t+8;
if (blk[0][135+f]==1) t=t+16;
if (blk[0][134+f]==1) t=t+32;
if (blk[0][133+f]==1) t=t+64;
if (blk[0][132+f]==1) t=t+128;
if (blk[0][127+f]==1) t=t+256;
if (blk[0][126+f]==1) t=t+512;
if (blk[0][125+f]==1) t=t+1024;
if (blk[0][124+f]==1) t=t+2048;
if (blk[0][123+f]==1) t=t+4096;
if (blk[0][122+f]==1) t=t+8192;
if (blk[0][121+f]==1) t=t+16384;
if (blk[0][120+f]==1) t=t+32768;
if (blk[0][115+f]==1) t=t+65536;
if (blk[0][114+f]==1) t=t+131072;
if (blk[0][113+f]==1) t=t+262144;
if (blk[0][112+f]==1) t=t+524288;
if (blk[0][111+f]==1) t=t+1048576;
if (blk[0][110+f]==1) t=t+2097152;
if (blk[0][109+f]==1) t=t+4194304;
if (blk[0][108+f]==1) t=t+8388608; 
if (blk[0][103+f]==1) t=t+16777216;
if (blk[0][102+f]==1) t=t+33554432;
if (blk[0][101+f]==1) t=t+67108864;
if (blk[0][100+f]==1) t=t+134217728;
if (blk[0][99+f]==1) t=t+268435456;
if (blk[0][98+f]==1) t=t+536870912;
if (blk[0][97+f]==1) t=t+1073741824;
if (blk[0][96+f]==1) t=t+2147483648; 


blank_line();
sprintf(s,"ESNINFO #%x",t);

strcpy(line,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }

}

// Handle SOSRX mpack //
void moby::sosrx (void)
{
char line[300];
blank_line();
strcpy(s,"SOSRX");

strcpy(line,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle VICESOSRX mpack //
void moby::vicesosrx (void)
{
char line[300];
blank_line();
strcpy(s,"VICESOSRX");

strcpy(line,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle INFO mpack //
void moby::info (void)
{
unsigned char tt,cl;
char tmp[50],line1[300],line2[300],line3[300],line4[300],line5[300];
blank_line();

strcpy(line1,"INFO");

// 2nd Line //
if (blk[0][187]==0) strcpy(line2,"Generate Connection NO ");
 else strcpy(line2,"Generate Connection YES ");
if (blk[0][199]==0) strcat(line2,"Receive Connection NO ");
 else strcat(line2,"Receive Connection YES ");
if (blk[0][211]==0) strcat(line2,"Present Text NO ");
 else strcat(line2,"Present Text YES ");

// 3rd Line //
tt=0;
if (blk[1][24]==1) tt=128;
if (blk[1][25]==1) tt=tt+64;
if (blk[1][26]==1) tt=tt+32;
if (blk[1][27]==1) tt=tt+16;
if (blk[1][28]==1) tt=tt+8;
if (blk[1][29]==1) tt=tt+4;
if (blk[1][30]==1) tt=tt+2;
if (blk[1][31]==1) tt++;
sprintf(line3,"Terminal Type #%d",tt);
tt=0;
if (blk[1][42]==1) tt=2;
if (blk[1][43]==1) tt++;
if (tt==1) strcat(line3," Duplex");
if (tt==2) strcat(line3," Simplex");
tt=0;
if (blk[1][48]==1) tt=128;
if (blk[1][49]==1) tt=tt+64;
if (blk[1][50]==1) tt=tt+32;
if (blk[1][51]==1) tt=tt+16;
if (blk[1][52]==1) tt=tt+8;
if (blk[1][53]==1) tt=tt+4;
if (blk[1][54]==1) tt=tt+2;
if (blk[1][55]==1) tt++;
sprintf(tmp," Power is %d",tt);
strcat(tmp,"W");
strcat(line3,tmp);

// 4th Line //
tt=0;
if (blk[1][60]==1) tt=128;
if (blk[1][61]==1) tt=tt+64;
if (blk[1][62]==1) tt=tt+32;
if (blk[1][63]==1) tt=tt+16;
if (blk[1][64]==1) tt=tt+8;
if (blk[1][65]==1) tt=tt+4;
if (blk[1][66]==1) tt=tt+2;
if (blk[1][67]==1) tt++;
sprintf(line4,"Switch time is %d",tt);
tt=0;
if (blk[1][72]==1) tt=128;
if (blk[1][73]==1) tt=tt+64;
if (blk[1][74]==1) tt=tt+32;
if (blk[1][75]==1) tt=tt+16;
if (blk[1][76]==1) tt=tt+8;
if (blk[1][77]==1) tt=tt+4;
if (blk[1][78]==1) tt=tt+2;
if (blk[1][79]==1) tt++;
sprintf(tmp," FBI #%d",tt);
strcat(line4,tmp);
tt=0;
if (blk[1][89]==1) tt=4;
if (blk[1][90]==1) tt=tt+2;
if (blk[1][91]==1) tt++;
sprintf(tmp," Priority %d",tt);
strcat(line4,tmp);

// 5th Line //
cl=0;
if (blk[1][125]==1) cl=4;
if (blk[1][126]==1) cl=cl+2;
if (blk[1][127]==1) cl++;
sprintf(line5,"Channel Class #%d",cl);
// If class 5 duplex spacing is .. //
if (cl==5)
 {
 unsigned int ds=0;
 if (blk[1][151]==1) ds=1;
 if (blk[1][150]==1) ds=ds+2;
 if (blk[1][149]==1) ds=ds+4;
 if (blk[1][148]==1) ds=ds+8;
 if (blk[1][147]==1) ds=ds+16;
 if (blk[1][146]==1) ds=ds+32;
 if (blk[1][145]==1) ds=ds+64;
 if (blk[1][144]==1) ds=ds+128;
 if (blk[1][139]==1) ds=ds+256;
 if (blk[1][138]==1) ds=ds+512;
 if (blk[1][137]==1) ds=ds+1024;
 if (blk[1][136]==1) ds=ds+2048;
 if (blk[1][135]==1) ds=ds+4096;
 if (blk[1][134]==1) ds=ds+8192;
 if (blk[1][133]==1) ds=ds+16384;
 if (blk[1][132]==1) ds=ds+32768;
 sprintf(tmp," Duplex Spacing %d",ds);
 strcat(tmp," channels");
 strcat(line5,tmp);
 }

// Display section //
strcpy(s,line5);
rotate();

strcpy(s,line4);
rotate();

strcpy(s,line3);
rotate();

strcpy(s,line2);
rotate();

strcpy(s,line1);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);
 logout.Write(line3,strlen(line3));
 logout.Write(enc,1);
 logout.Write(line4,strlen(line4));
 logout.Write(enc,1);
 logout.Write(line5,strlen(line5));
 logout.Write(enc,1);
 }
}

// Open the logging file //
void moby::openlogfile (void)
{
CFileDialog sl(FALSE,"log","*.log",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_PATHMUSTEXIST,"Log files *.log||",NULL);
sl.m_ofn.lpstrTitle="Start logging to disk";

if (sl.DoModal()==IDOK)
 {
 CString logfilename;
 CTime time1=CTime::GetCurrentTime();
 char year[6],hour[5],minute[5],second[5],time[60],zero[5];
 int temp; 

 strcpy(zero,"0");
 
 // Get the day //
 temp=time1.GetDay();
 if (temp==1) strcpy(time,"1st ");
 if (temp==2) strcpy(time,"2nd ");
 if (temp==3) strcpy(time,"3rd ");
 if (temp==4) strcpy(time,"4th ");
 if (temp==5) strcpy(time,"5th ");
 if (temp==6) strcpy(time,"6th ");
 if (temp==7) strcpy(time,"7th ");
 if (temp==8) strcpy(time,"8th ");
 if (temp==9) strcpy(time,"9th ");
 if (temp==10) strcpy(time,"10th ");  
 if (temp==11) strcpy(time,"11th ");
 if (temp==12) strcpy(time,"12th ");
 if (temp==13) strcpy(time,"13th ");
 if (temp==14) strcpy(time,"14th ");
 if (temp==15) strcpy(time,"15th ");
 if (temp==16) strcpy(time,"16th ");
 if (temp==17) strcpy(time,"17th ");
 if (temp==18) strcpy(time,"18th ");
 if (temp==19) strcpy(time,"19th ");
 if (temp==20) strcpy(time,"20th ");  
 if (temp==21) strcpy(time,"21st ");
 if (temp==22) strcpy(time,"22nd ");
 if (temp==23) strcpy(time,"23rd ");
 if (temp==24) strcpy(time,"24th ");
 if (temp==25) strcpy(time,"25th ");
 if (temp==26) strcpy(time,"26th ");
 if (temp==27) strcpy(time,"27th ");
 if (temp==28) strcpy(time,"28th ");
 if (temp==29) strcpy(time,"29th ");
 if (temp==30) strcpy(time,"30th ");
 if (temp==31) strcpy(time,"31st ");
 // Get the month //
 temp=time1.GetMonth();
 if (temp==1) strcat(time,"January "); 
 if (temp==2) strcat(time,"February ");
 if (temp==3) strcat(time,"March ");
 if (temp==4) strcat(time,"April ");
 if (temp==5) strcat(time,"May ");
 if (temp==6) strcat(time,"June ");
 if (temp==7) strcat(time,"July ");
 if (temp==8) strcat(time,"August ");
 if (temp==9) strcat(time,"September ");
 if (temp==10) strcat(time,"October ");
 if (temp==11) strcat(time,"November ");
 if (temp==12) strcat(time,"December ");
 // Get the year //  
 temp=time1.GetYear(); 
 sprintf(year,"%d",temp);
 strcat(time,year);
 strcat(time," at "); 
 // Get the current hour //
 sprintf(hour,"%d",time1.GetHour());
 strcat(time,hour);
 strcat(time,":");
 // Get the current minute //
 sprintf(minute,"%d",time1.GetMinute());
 if (time1.GetMinute()<10) strcat(time,zero);
 strcat(time,minute);
 strcat(time,":");
 // Get the current second //
 sprintf(second,"%d",time1.GetSecond());
 if (time1.GetSecond()<10) strcat(time,zero);
 strcat(time,second);

 logfilename=sl.GetPathName();
 logout.Open(logfilename,CFile::modeCreate|CFile::modeWrite|CFile::shareExclusive,NULL);
 logout.Write("Started logging on ",19);
 logout.Write(time,strlen(time));
 logout.Write(enc,1); 
 logout.Write(enc,1);
 logout.Write(id,strlen(id));
 logout.Write(enc,1);
 }
}

// Close the logging file //
void moby::closelogfile (void)
{
// Close it all down //
CString downtime;
CTime time1=CTime::GetCurrentTime();
char hour[5],minute[5],second[5],time[25],zero[5],info[1000],tmp[100];
float bad;
int a;

// System Channels //
if (surrounding>0)
 {
 strcpy(info,"\nSystem Channels ..\n");
 for (a=0;a<surrounding;a++)
  {
  sprintf(tmp,"Upfreq #%d",a);
  strcat(info,tmp);
  sprintf(tmp," %0.4f",upf[a]);
  strcat(info,tmp);
  sprintf(tmp," MHz Dofreq #%d",a);
  strcat(info,tmp);
  sprintf(tmp," %0.4f",dof[a]);
  strcat(info,tmp);
  strcat(info," MHz\n");
  }
 logout.Write(info,strlen(info)); 
 }

// Stats //
bad=(bad_blocks/total_blocks)*100;
sprintf(info,"\n%0.1f",bad);
strcat(info,"% of blocks received had a bad CRC.");
logout.Write(info,strlen(info)); 

// Ending Time //
strcpy(zero,"0");
// Get the current hour //
sprintf(hour,"%d",time1.GetHour());
strcpy(time,hour);
strcat(time,":");
// Get the current minute //
sprintf(minute,"%d",time1.GetMinute());
if (time1.GetMinute()<10) strcat(time,zero);
strcat(time,minute);
strcat(time,":");
// Get the current second //
sprintf(second,"%d",time1.GetSecond());
if (time1.GetSecond()<10) strcat(time,zero);
strcat(time,second); 

logout.Write("\n\nEnded logging at ",19);
logout.Write(time,strlen(time)); 
logout.Flush();
logout.Close();

}

// Handle TEXT mpak with no address list //
void moby::text (void)
{
unsigned long int t;
char line1[200];

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);
strcpy(line1,"TEXT ");
strcat(line1,ts);

blank_line();

extract_data();

ascii_protocols(line1,1);
}

// Handle TEXT mpak with address list //
void moby::text_list (void)
{
unsigned long int t,add1,add2,add3,add4,add5,add6,add7;
unsigned char num;
char line0[300];

blank_line();

// Calculate number of addresses //
num=0;
if (blk[0][168]==1) num=128;
if (blk[0][169]==1) num=num+64;
if (blk[0][170]==1) num=num+32;
if (blk[0][171]==1) num=num+16;
if (blk[0][172]==1) num=num+8;
if (blk[0][173]==1) num=num+4;
if (blk[0][174]==1) num=num+2;
if (blk[0][175]==1) num++;

// First address //
add1=0;
if (blk[0][211]==1) add1=1;
if (blk[0][210]==1) add1=add1+2;
if (blk[0][209]==1) add1=add1+4;
if (blk[0][208]==1) add1=add1+8;
if (blk[0][207]==1) add1=add1+16;
if (blk[0][206]==1) add1=add1+32;
if (blk[0][205]==1) add1=add1+64;
if (blk[0][204]==1) add1=add1+128;
if (blk[0][199]==1) add1=add1+256;
if (blk[0][198]==1) add1=add1+512;
if (blk[0][197]==1) add1=add1+1024;
if (blk[0][196]==1) add1=add1+2048;
if (blk[0][195]==1) add1=add1+4096;
if (blk[0][194]==1) add1=add1+8192;
if (blk[0][193]==1) add1=add1+16384;
if (blk[0][192]==1) add1=add1+32768;
if (blk[0][187]==1) add1=add1+65536;
if (blk[0][186]==1) add1=add1+131072;
if (blk[0][185]==1) add1=add1+262144;
if (blk[0][184]==1) add1=add1+524288;
if (blk[0][183]==1) add1=add1+1048576;
if (blk[0][182]==1) add1=add1+2097152;
if (blk[0][181]==1) add1=add1+4194304;
if (blk[0][180]==1) add1=add1+8388608; 

// Second address //
add2=0;
if (blk[1][31]==1) add2=1;
if (blk[1][30]==1) add2=add2+2;
if (blk[1][29]==1) add2=add2+4;
if (blk[1][28]==1) add2=add2+8;
if (blk[1][27]==1) add2=add2+16;
if (blk[1][26]==1) add2=add2+32;
if (blk[1][25]==1) add2=add2+64;
if (blk[1][24]==1) add2=add2+128;
if (blk[1][19]==1) add2=add2+256;
if (blk[1][18]==1) add2=add2+512;
if (blk[1][17]==1) add2=add2+1024;
if (blk[1][16]==1) add2=add2+2048;
if (blk[1][15]==1) add2=add2+4096;
if (blk[1][14]==1) add2=add2+8192;
if (blk[1][13]==1) add2=add2+16384;
if (blk[1][12]==1) add2=add2+32768;
if (blk[1][7]==1) add2=add2+65536;
if (blk[1][6]==1) add2=add2+131072;
if (blk[1][5]==1) add2=add2+262144;
if (blk[1][4]==1) add2=add2+524288;
if (blk[1][3]==1) add2=add2+1048576;
if (blk[1][2]==1) add2=add2+2097152;
if (blk[1][1]==1) add2=add2+4194304;
if (blk[1][0]==1) add2=add2+8388608; 

// Third address //
add3=0;
if (blk[1][67]==1) add3=1;
if (blk[1][66]==1) add3=add3+2;
if (blk[1][65]==1) add3=add3+4;
if (blk[1][64]==1) add3=add3+8;
if (blk[1][63]==1) add3=add3+16;
if (blk[1][62]==1) add3=add3+32;
if (blk[1][61]==1) add3=add3+64;
if (blk[1][60]==1) add3=add3+128;
if (blk[1][55]==1) add3=add3+256;
if (blk[1][54]==1) add3=add3+512;
if (blk[1][53]==1) add3=add3+1024;
if (blk[1][52]==1) add3=add3+2048;
if (blk[1][51]==1) add3=add3+4096;
if (blk[1][50]==1) add3=add3+8192;
if (blk[1][49]==1) add3=add3+16384;
if (blk[1][48]==1) add3=add3+32768;
if (blk[1][43]==1) add3=add3+65536;
if (blk[1][42]==1) add3=add3+131072;
if (blk[1][41]==1) add3=add3+262144;
if (blk[1][40]==1) add3=add3+524288;
if (blk[1][39]==1) add3=add3+1048576;
if (blk[1][38]==1) add3=add3+2097152;
if (blk[1][37]==1) add3=add3+4194304;
if (blk[1][36]==1) add3=add3+8388608; 

// Fourth address //
add4=0;
if (blk[1][103]==1) add4=1;
if (blk[1][102]==1) add4=add4+2;
if (blk[1][101]==1) add4=add4+4;
if (blk[1][100]==1) add4=add4+8;
if (blk[1][99]==1) add4=add4+16;
if (blk[1][98]==1) add4=add4+32;
if (blk[1][97]==1) add4=add4+64;
if (blk[1][96]==1) add4=add4+128;
if (blk[1][91]==1) add4=add4+256;
if (blk[1][90]==1) add4=add4+512;
if (blk[1][89]==1) add4=add4+1024;
if (blk[1][88]==1) add4=add4+2048;
if (blk[1][87]==1) add4=add4+4096;
if (blk[1][86]==1) add4=add4+8192;
if (blk[1][85]==1) add4=add4+16384;
if (blk[1][84]==1) add4=add4+32768;
if (blk[1][79]==1) add4=add4+65536;
if (blk[1][78]==1) add4=add4+131072;
if (blk[1][77]==1) add4=add4+262144;
if (blk[1][76]==1) add4=add4+524288;
if (blk[1][75]==1) add4=add4+1048576;
if (blk[1][74]==1) add4=add4+2097152;
if (blk[1][73]==1) add4=add4+4194304;
if (blk[1][72]==1) add4=add4+8388608; 

// Fifth address //
add5=0;
if (blk[1][139]==1) add5=1;
if (blk[1][138]==1) add5=add5+2;
if (blk[1][137]==1) add5=add5+4;
if (blk[1][136]==1) add5=add5+8;
if (blk[1][135]==1) add5=add5+16;
if (blk[1][134]==1) add5=add5+32;
if (blk[1][133]==1) add5=add5+64;
if (blk[1][132]==1) add5=add5+128;
if (blk[1][127]==1) add5=add5+256;
if (blk[1][126]==1) add5=add5+512;
if (blk[1][125]==1) add5=add5+1024;
if (blk[1][124]==1) add5=add5+2048;
if (blk[1][123]==1) add5=add5+4096;
if (blk[1][122]==1) add5=add5+8192;
if (blk[1][121]==1) add5=add5+16384;
if (blk[1][120]==1) add5=add5+32768;
if (blk[1][115]==1) add5=add5+65536;
if (blk[1][114]==1) add5=add5+131072;
if (blk[1][113]==1) add5=add5+262144;
if (blk[1][112]==1) add5=add5+524288;
if (blk[1][111]==1) add5=add5+1048576;
if (blk[1][110]==1) add5=add5+2097152;
if (blk[1][109]==1) add5=add5+4194304;
if (blk[1][108]==1) add5=add5+8388608; 

// Sixth address //
add6=0;
if (blk[1][175]==1) add6=1;
if (blk[1][174]==1) add6=add6+2;
if (blk[1][173]==1) add6=add6+4;
if (blk[1][172]==1) add6=add6+8;
if (blk[1][171]==1) add6=add6+16;
if (blk[1][170]==1) add6=add6+32;
if (blk[1][169]==1) add6=add6+64;
if (blk[1][168]==1) add6=add6+128;
if (blk[1][163]==1) add6=add6+256;
if (blk[1][162]==1) add6=add6+512;
if (blk[1][161]==1) add6=add6+1024;
if (blk[1][160]==1) add6=add6+2048;
if (blk[1][159]==1) add6=add6+4096;
if (blk[1][158]==1) add6=add6+8192;
if (blk[1][157]==1) add6=add6+16384;
if (blk[1][156]==1) add6=add6+32768;
if (blk[1][151]==1) add6=add6+65536;
if (blk[1][150]==1) add6=add6+131072;
if (blk[1][149]==1) add6=add6+262144;
if (blk[1][148]==1) add6=add6+524288;
if (blk[1][147]==1) add6=add6+1048576;
if (blk[1][146]==1) add6=add6+2097152;
if (blk[1][145]==1) add6=add6+4194304;
if (blk[1][144]==1) add6=add6+8388608; 

// Seventh address //
add7=0;
if (blk[1][211]==1) add7=1;
if (blk[1][210]==1) add7=add7+2;
if (blk[1][209]==1) add7=add7+4;
if (blk[1][208]==1) add7=add7+8;
if (blk[1][207]==1) add7=add7+16;
if (blk[1][206]==1) add7=add7+32;
if (blk[1][205]==1) add7=add7+64;
if (blk[1][204]==1) add7=add7+128;
if (blk[1][199]==1) add7=add7+256;
if (blk[1][198]==1) add7=add7+512;
if (blk[1][197]==1) add7=add7+1024;
if (blk[1][196]==1) add7=add7+2048;
if (blk[1][195]==1) add7=add7+4096;
if (blk[1][194]==1) add7=add7+8192;
if (blk[1][193]==1) add7=add7+16384;
if (blk[1][192]==1) add7=add7+32768;
if (blk[1][187]==1) add7=add7+65536;
if (blk[1][186]==1) add7=add7+131072;
if (blk[1][185]==1) add7=add7+262144;
if (blk[1][184]==1) add7=add7+524288;
if (blk[1][183]==1) add7=add7+1048576;
if (blk[1][182]==1) add7=add7+2097152;
if (blk[1][181]==1) add7=add7+4194304;
if (blk[1][180]==1) add7=add7+8388608; 

// Calculate time //
t=0;
if (blk[2][31]==1) t=1;
if (blk[2][30]==1) t=t+2;
if (blk[2][29]==1) t=t+4;
if (blk[2][28]==1) t=t+8;
if (blk[2][27]==1) t=t+16;
if (blk[2][26]==1) t=t+32;
if (blk[2][25]==1) t=t+64;
if (blk[2][24]==1) t=t+128;
if (blk[2][19]==1) t=t+256;
if (blk[2][18]==1) t=t+512;
if (blk[2][17]==1) t=t+1024;
if (blk[2][16]==1) t=t+2048;
if (blk[2][15]==1) t=t+4096;
if (blk[2][14]==1) t=t+8192;
if (blk[2][13]==1) t=t+16384;
if (blk[2][12]==1) t=t+32768;
if (blk[2][7]==1) t=t+65536;
if (blk[2][6]==1) t=t+131072;
if (blk[2][5]==1) t=t+262144;
if (blk[2][4]==1) t=t+524288;
if (blk[2][3]==1) t=t+1048576;
if (blk[2][2]==1) t=t+2097152;
if (blk[2][1]==1) t=t+4194304;
if (blk[2][0]==1) t=t+8388608; 
moby_time(t);

// Display Section //
strcpy(line0,"TEXT ");
strcat(line0,ts);
strcpy(s,line0);
rotate();

blank_line();

extract_data_add();

ascii_protocols_list(line0,1,num,add1,add2,add3,add4,add5,add6,add7);

}

// write who from & who to onto a log file //
void moby::write_stub (void)
{
char tmp[200];

// Put in a blank line //
strcpy(s," ");
logout.Write(s,strlen(s));
logout.Write(enc,1);

// MRM Frame //
if (frame==1)
 {
 sprintf(s,"To:%lx",address);
 if (address==1) strcpy(s,"To the Network");
 if (address>1 && address<7) sprintf(s,"To an External Network #%d",address);
 if (address>7 && address<21) sprintf(s,"To an External Network #%d",address);
 if (address==7) strcpy(s,"To All Terminals");
 if (get_identity(address)==TRUE)
  {
  strcpy(s,"To ");
  strcat(s,user_name);
  }

 sprintf(tmp," From:%lx",sender);
 if (sender==1) strcpy(tmp," From the Network");
 if (sender>1 && sender<7) sprintf(tmp," From an External Network #%d",sender);
 if (sender>7 && sender<21) sprintf(tmp," From an External Network #%d",sender); 
 if (get_identity(sender)==TRUE)
  {
  strcpy(tmp," From ");
  strcat(tmp,user_name);
  }

 strcat(s,tmp);
 if (blocks>1) 
  {
  char tmp2[10];
  sprintf(tmp," (%d",blocks);
  strcpy(tmp2," Blocks)");
  strcat(tmp,tmp2);
  strcat(s,tmp);
  }

 // Traffic state //
 if (display_traffic_state==TRUE)
  {
  if (state==0) strcpy(tmp," (OK)");
  if (state==1) strcpy(tmp," (FROM_MAIL)");
  if (state==2) strcpy(tmp," (IN_MAIL)");
  if (state==3) strcpy(tmp," (NO_TRANSFER)");
  if (state==4) strcpy(tmp," (ILLEGAL)");
  if (state==5) strcpy(tmp," (CONGEST)");
  if (state==6) strcpy(tmp," (ERROR)");
  if (state==7) strcpy(tmp," (BUSY)");
  strcat(s,tmp);
  }

 if (sequence_display==TRUE)
  {
  sprintf(tmp," (%d",sequence);
  strcat(s,tmp);
  strcpy(tmp,")");
  strcat(s,tmp);
  }

 if (re_display==TRUE && blk[0][36]==1)
  {
  strcpy(tmp," (RE)");
  strcat(s,tmp);
  }
 }

if (frame>1)
 {
 BOOL seq=FALSE;
 sprintf(s,"MOB: %lx",mob);
 if (mob==1) strcpy(s,"To the Network");
 if (mob>1 && mob<7) strcpy(s,"To an External Network");
 if (mob==7) strcpy(s,"To All Terminals");
 if (mob>1 && mob<7) sprintf(tmp," From an External Network #%d",mob);
 if (mob>7 && mob<21) sprintf(tmp," From an External Network #%d",mob); 
 if (get_identity(mob)==TRUE)
  {
  strcpy(s,"MOB: ");
  strcat(s,user_name);
  }

 // Does this frame have a sequence number //
 if (frame==2) seq=TRUE;
 if (frame==3) seq=TRUE;
 if (frame==4) seq=TRUE;
 if (frame==5) seq=TRUE;

 if (sequence_display==TRUE && seq==TRUE)
  {
  sprintf(tmp," (%d",sequence);
  strcat(s,tmp);
  strcpy(tmp,")");
  strcat(s,tmp);
  }
 }

logout.Write(s,strlen(s));
logout.Write(enc,1);
}

// Do a blank line //
void moby::blank_line (void)
{
char tmp[3];

// clear the line //
strcpy(tmp," ");

strcpy(s119,s118);
strcpy(s118,s117);
strcpy(s117,s116);
strcpy(s116,s115);
strcpy(s115,s114);
strcpy(s114,s113);
strcpy(s113,s112);
strcpy(s112,s111); 
strcpy(s111,s110);
strcpy(s110,s109);
strcpy(s109,s108);
strcpy(s108,s107);
strcpy(s107,s106);
strcpy(s106,s105);
strcpy(s105,s104);
strcpy(s104,s103);
strcpy(s103,s102); 
strcpy(s102,s101);
strcpy(s101,s100);
strcpy(s100,s99);
strcpy(s99,s98);
strcpy(s98,s97);
strcpy(s97,s96);
strcpy(s96,s95);
strcpy(s95,s94);
strcpy(s94,s93);
strcpy(s93,s92); 
strcpy(s92,s91);
strcpy(s91,s90);
strcpy(s90,s89);
strcpy(s89,s88);
strcpy(s88,s87);
strcpy(s87,s86);
strcpy(s86,s85);
strcpy(s85,s84);
strcpy(s84,s83);
strcpy(s83,s82); 
strcpy(s82,s81);
strcpy(s81,s80);
strcpy(s80,s79);
strcpy(s79,s78);
strcpy(s78,s77);
strcpy(s77,s76);
strcpy(s76,s75);
strcpy(s75,s74);
strcpy(s74,s73);
strcpy(s73,s72); 
strcpy(s72,s71);
strcpy(s71,s70);
strcpy(s70,s69);
strcpy(s69,s68);
strcpy(s68,s67);
strcpy(s67,s66);
strcpy(s66,s65);
strcpy(s65,s64);
strcpy(s64,s63);
strcpy(s63,s62); 
strcpy(s62,s61);
strcpy(s61,s60);
strcpy(s60,s59);
strcpy(s59,s58);
strcpy(s58,s57);
strcpy(s57,s56);
strcpy(s56,s55);
strcpy(s55,s54);
strcpy(s54,s53);
strcpy(s53,s52); 
strcpy(s52,s51);
strcpy(s51,s50);
strcpy(s50,s49);
strcpy(s49,s48);
strcpy(s48,s47);
strcpy(s47,s46);
strcpy(s46,s45);
strcpy(s45,s44);
strcpy(s44,s43);
strcpy(s43,s42); 
strcpy(s42,s41);
strcpy(s41,s40);
strcpy(s40,s39);
strcpy(s39,s38);
strcpy(s38,s37);
strcpy(s37,s36);
strcpy(s36,s35);
strcpy(s35,s34);
strcpy(s34,s33);
strcpy(s33,s32); 
strcpy(s32,s31);
strcpy(s31,s30); 	
strcpy(s30,s29);
strcpy(s29,s28);
strcpy(s28,s27);
strcpy(s27,s26);
strcpy(s26,s25);
strcpy(s25,s24);
strcpy(s24,s23);
strcpy(s23,s22); 
strcpy(s22,s21);
strcpy(s21,s20);
strcpy(s20,s19);
strcpy(s19,s18);
strcpy(s18,s17);
strcpy(s17,s16);
strcpy(s16,s15);
strcpy(s15,s14);
strcpy(s14,s13);
strcpy(s13,s12);
strcpy(s12,s11);
strcpy(s11,s10);
strcpy(s10,s9);
strcpy(s9,s8);
strcpy(s8,s7);
strcpy(s7,s6);
strcpy(s6,s5);
strcpy(s5,s4);
strcpy(s4,s3);
strcpy(s3,s2);
strcpy(s2,s1);
strcpy(s1,s0);
strcpy(s0,tmp);
}

// Handle a SOSACK mpak //
void moby::sosack (void)
{
unsigned long int t;
unsigned char st;
char tmp[20],line1[300];

blank_line();
strcpy(s,"SOSACK");

// Alert Status byte //
st=0;      
if (blk[0][199]==1) st=1;
if (blk[0][198]==1) st=st+2; 
if (blk[0][197]==1) st=st+4;
if (blk[0][196]==1) st=st+8;  
if (blk[0][195]==1) st=st+16;
if (blk[0][194]==1) st=st+32; 
if (blk[0][193]==1) st=st+64;
if (blk[0][192]==1) st=st+128;
sprintf(tmp," #%x",st);
strcat(s,tmp);

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);
strcat(s,ts);

strcpy(line1,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }

}

// Handle a CONREQ mpak //
void moby::conreq (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CONREQ");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);
strcpy(line1,s);

strcpy(s,line1);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CONFAST mpak //
void moby::confast (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CONFAST");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a SOSCONREQ mpak //
void moby::sosconreq (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"SOSCONREQ");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a SOSCONFAST mpak //
void moby::sosconfast (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"SOSCONFAST");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CONGRA mpak //
void moby::congra (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CONGRA");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CONORD mpak //
void moby::conord (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CONORD");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CONREA mpak //
void moby::conrea (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CONREA");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}


// Handle a DISCON mpak //
void moby::discon (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"DISCON");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CLOOPON mpak //
void moby::cloopon (void)
{
unsigned char line;
char tmp[15],line1[300];

blank_line();
strcpy(s,"CLOOPON");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a CLOOPOFF mpak //
void moby::cloopoff (void)
{
unsigned char line;
char line1[300],tmp[100];

blank_line();
strcpy(s,"CLOOPOFF");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a LINEON mpak //
void moby::lineon (void)
{
unsigned char line;
char line1[300],tmp[100];

blank_line();
strcpy(s,"LINEON");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a LINEOFF mpak //
void moby::lineoff (void)
{
unsigned char line;
char line1[300],tmp[100];

blank_line();
strcpy(s,"LINEOFF");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a LINSEL mpak //
void moby::linsel (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"LINSEL");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}


// Handle LOGINREQ mpak //
void moby::loginreq (void)
{
char line1[300],pass[10],let;
unsigned long int t;

blank_line();

// Work out the MAN //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
sprintf(s,"LOGINREQ #%x",t);

// Work out the password //
// Octet 12 //
pass[0]=32;
let=0;
//if (blk[0][204]==1) let=128;
if (blk[0][205]==1) let=let+64;
if (blk[0][206]==1) let=let+32;
if (blk[0][207]==1) let=let+16;
if (blk[0][208]==1) let=let+8;
if (blk[0][209]==1) let=let+4;
if (blk[0][210]==1) let=let+2;
if (blk[0][211]==1) let++;
pass[1]=let;
// Octet 13 //
let=0;
//if (blk[1][0]==1) let=128;
if (blk[1][1]==1) let=let+64;
if (blk[1][2]==1) let=let+32;
if (blk[1][3]==1) let=let+16;
if (blk[1][4]==1) let=let+8;
if (blk[1][5]==1) let=let+4;
if (blk[1][6]==1) let=let+2;
if (blk[1][7]==1) let++;
pass[2]=let;
// Octet 14 //
let=0;
//if (blk[1][12]==1) let=128;
if (blk[1][13]==1) let=let+64;
if (blk[1][14]==1) let=let+32;
if (blk[1][15]==1) let=let+16;
if (blk[1][16]==1) let=let+8;
if (blk[1][17]==1) let=let+4;
if (blk[1][18]==1) let=let+2;
if (blk[1][19]==1) let++;
pass[3]=let;
// Octet 15 //
let=0;
//if (blk[1][24]==1) let=128;
if (blk[1][25]==1) let=let+64;
if (blk[1][26]==1) let=let+32;
if (blk[1][27]==1) let=let+16;
if (blk[1][28]==1) let=let+8;
if (blk[1][29]==1) let=let+4;
if (blk[1][30]==1) let=let+2;
if (blk[1][31]==1) let++;
pass[4]=let;
// Octet 16 //
let=0;
//if (blk[1][36]==1) let=128;
if (blk[1][37]==1) let=let+64;
if (blk[1][38]==1) let=let+32;
if (blk[1][39]==1) let=let+16;
if (blk[1][40]==1) let=let+8;
if (blk[1][41]==1) let=let+4;
if (blk[1][42]==1) let=let+2;
if (blk[1][43]==1) let++;
pass[5]=let;
// Octet 17 //
let=0;
//if (blk[1][48]==1) let=128;
if (blk[1][49]==1) let=let+64;
if (blk[1][50]==1) let=let+32;
if (blk[1][51]==1) let=let+16;
if (blk[1][52]==1) let=let+8;
if (blk[1][53]==1) let=let+4;
if (blk[1][54]==1) let=let+2;
if (blk[1][55]==1) let++;
pass[6]=let;
// Octet 18 //
let=0;
//if (blk[1][60]==1) let=128;
if (blk[1][61]==1) let=let+64;
if (blk[1][62]==1) let=let+32;
if (blk[1][63]==1) let=let+16;
if (blk[1][64]==1) let=let+8;
if (blk[1][65]==1) let=let+4;
if (blk[1][66]==1) let=let+2;
if (blk[1][67]==1) let++;
pass[7]=let;
// Octet 19 //
let=0;
//if (blk[1][72]==1) let=128;
if (blk[1][73]==1) let=let+64;
if (blk[1][74]==1) let=let+32;
if (blk[1][75]==1) let=let+16;
if (blk[1][76]==1) let=let+8;
if (blk[1][77]==1) let=let+4;
if (blk[1][78]==1) let=let+2;
if (blk[1][79]==1) let++;
pass[8]=let;
pass[9]=0;

strcat(s,pass);
strcpy(line1,s);
 
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle LOGOUT mpak //
void moby::logoutmpak (void)
{
char line1[300];
unsigned long int t;

blank_line();

// Work out the MAN //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
sprintf(s,"LOGOUT #%x",t);

strcpy(line1,s);
 
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}


// Handle LOGINGRA mpak //
void moby::logingra (void)
{
char line1[300];
unsigned long int t;

blank_line();

// Work out the MAN //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
sprintf(s,"LOGINGRA #%x",t);

strcpy(line1,s);
 
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle LOGINREF mpak //
void moby::loginref (void)
{
char line1[300];
unsigned long int t;

blank_line();

// Work out the MAN //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
sprintf(s,"LOGINREF #%x",t);

strcpy(line1,s); 

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle LOGOUTORD mpak //
void moby::logoutord (void)
{
char line1[300];
unsigned long int t;

blank_line();

// Work out the MAN //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
sprintf(s,"LOGOUTORD #%x",t);

strcpy(line1,s);
 
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle ROAM mpack //
void moby::roam (void)
{
unsigned long t;
char line1[300];

t=0;
if (blk[0][139+f]==1) t=1;
if (blk[0][138+f]==1) t=t+2;
if (blk[0][137+f]==1) t=t+4;
if (blk[0][136+f]==1) t=t+8;
if (blk[0][135+f]==1) t=t+16;
if (blk[0][134+f]==1) t=t+32;
if (blk[0][133+f]==1) t=t+64;
if (blk[0][132+f]==1) t=t+128;
if (blk[0][127+f]==1) t=t+256;
if (blk[0][126+f]==1) t=t+512;
if (blk[0][125+f]==1) t=t+1024;
if (blk[0][124+f]==1) t=t+2048;
if (blk[0][123+f]==1) t=t+4096;
if (blk[0][122+f]==1) t=t+8192;
if (blk[0][121+f]==1) t=t+16384;
if (blk[0][120+f]==1) t=t+32768;
if (blk[0][115+f]==1) t=t+65536;
if (blk[0][114+f]==1) t=t+131072;
if (blk[0][113+f]==1) t=t+262144;
if (blk[0][112+f]==1) t=t+524288;
if (blk[0][111+f]==1) t=t+1048576;
if (blk[0][110+f]==1) t=t+2097152;
if (blk[0][109+f]==1) t=t+4194304;
if (blk[0][108+f]==1) t=t+8388608; 
if (blk[0][103+f]==1) t=t+16777216;
if (blk[0][102+f]==1) t=t+33554432;
if (blk[0][101+f]==1) t=t+67108864;
if (blk[0][100+f]==1) t=t+134217728;
if (blk[0][99+f]==1) t=t+268435456;
if (blk[0][98+f]==1) t=t+536870912;
if (blk[0][97+f]==1) t=t+1073741824;
if (blk[0][96+f]==1) t=t+2147483648; 

blank_line();
sprintf(s,"ROAM #%x",t);

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle BORN mpack //
void moby::born (void)
{
unsigned long t;
char line1[300];

t=0;
if (blk[0][139+f]==1) t=1;
if (blk[0][138+f]==1) t=t+2;
if (blk[0][137+f]==1) t=t+4;
if (blk[0][136+f]==1) t=t+8;
if (blk[0][135+f]==1) t=t+16;
if (blk[0][134+f]==1) t=t+32;
if (blk[0][133+f]==1) t=t+64;
if (blk[0][132+f]==1) t=t+128;
if (blk[0][127+f]==1) t=t+256;
if (blk[0][126+f]==1) t=t+512;
if (blk[0][125+f]==1) t=t+1024;
if (blk[0][124+f]==1) t=t+2048;
if (blk[0][123+f]==1) t=t+4096;
if (blk[0][122+f]==1) t=t+8192;
if (blk[0][121+f]==1) t=t+16384;
if (blk[0][120+f]==1) t=t+32768;
if (blk[0][115+f]==1) t=t+65536;
if (blk[0][114+f]==1) t=t+131072;
if (blk[0][113+f]==1) t=t+262144;
if (blk[0][112+f]==1) t=t+524288;
if (blk[0][111+f]==1) t=t+1048576;
if (blk[0][110+f]==1) t=t+2097152;
if (blk[0][109+f]==1) t=t+4194304;
if (blk[0][108+f]==1) t=t+8388608; 
if (blk[0][103+f]==1) t=t+16777216;
if (blk[0][102+f]==1) t=t+33554432;
if (blk[0][101+f]==1) t=t+67108864;
if (blk[0][100+f]==1) t=t+134217728;
if (blk[0][99+f]==1) t=t+268435456;
if (blk[0][98+f]==1) t=t+536870912;
if (blk[0][97+f]==1) t=t+1073741824;
if (blk[0][96+f]==1) t=t+2147483648; 

blank_line();
sprintf(s,"BORN #%x",t);

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle ACTIVE mpack //
void moby::active (void)
{
unsigned long t;
char line1[300];

t=0;
if (blk[0][139+f]==1) t=1;
if (blk[0][138+f]==1) t=t+2;
if (blk[0][137+f]==1) t=t+4;
if (blk[0][136+f]==1) t=t+8;
if (blk[0][135+f]==1) t=t+16;
if (blk[0][134+f]==1) t=t+32;
if (blk[0][133+f]==1) t=t+64;
if (blk[0][132+f]==1) t=t+128;
if (blk[0][127+f]==1) t=t+256;
if (blk[0][126+f]==1) t=t+512;
if (blk[0][125+f]==1) t=t+1024;
if (blk[0][124+f]==1) t=t+2048;
if (blk[0][123+f]==1) t=t+4096;
if (blk[0][122+f]==1) t=t+8192;
if (blk[0][121+f]==1) t=t+16384;
if (blk[0][120+f]==1) t=t+32768;
if (blk[0][115+f]==1) t=t+65536;
if (blk[0][114+f]==1) t=t+131072;
if (blk[0][113+f]==1) t=t+262144;
if (blk[0][112+f]==1) t=t+524288;
if (blk[0][111+f]==1) t=t+1048576;
if (blk[0][110+f]==1) t=t+2097152;
if (blk[0][109+f]==1) t=t+4194304;
if (blk[0][108+f]==1) t=t+8388608; 
if (blk[0][103+f]==1) t=t+16777216;
if (blk[0][102+f]==1) t=t+33554432;
if (blk[0][101+f]==1) t=t+67108864;
if (blk[0][100+f]==1) t=t+134217728;
if (blk[0][99+f]==1) t=t+268435456;
if (blk[0][98+f]==1) t=t+536870912;
if (blk[0][97+f]==1) t=t+1073741824;
if (blk[0][96+f]==1) t=t+2147483648; 

blank_line();
sprintf(s,"ACTIVE #%x",t);

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle INACTIVE mpack //
void moby::inactive (void)
{
char line1[300];
blank_line();
strcpy(s,"INACTIVE");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle DIE mpack //
void moby::die (void)
{
char line1[300];
blank_line();
strcpy(s,"DIE");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle LIVE mpack //
void moby::live (void)
{
char line1[300];
blank_line();
strcpy(s,"LIVE");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle ROAMORD mpack //
void moby::roamord (void)
{
char line1[300];
blank_line();
strcpy(s,"ROAMORD");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle FLEXREQ mpack //
void moby::flexreq (void)
{
char line1[300];
blank_line();
strcpy(s,"FLEXREQ");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle INFOREQ mpack //
void moby::inforeq (void)
{
char line1[300];
blank_line();
strcpy(s,"INFOREQ");

strcpy(line1,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle EXTPAK mpaks //
void moby::extpak (void)
{
unsigned long int t;
char line0[200];

strcpy(line0,"EXTPAK "); 

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);
strcat(line0,ts);

extract_data();

if (extpak_ascii_show==TRUE)
 {
 ascii_protocols(line0,0);
 return;
 }
 
hex_protocols(line0,1);
}
 
// Handle SOSINFO mpak //
void moby::sosinfo (void)
{
unsigned long int t;
char line[300];

strcpy(line,"SOSINFO ");

// Work out the mobitex time //
t=0;
if (blk[0][127+f]==1) t=1;
if (blk[0][126+f]==1) t=t+2;
if (blk[0][125+f]==1) t=t+4;
if (blk[0][124+f]==1) t=t+8;
if (blk[0][123+f]==1) t=t+16;
if (blk[0][122+f]==1) t=t+32;
if (blk[0][121+f]==1) t=t+64;
if (blk[0][120+f]==1) t=t+128;
if (blk[0][115+f]==1) t=t+256;
if (blk[0][114+f]==1) t=t+512;
if (blk[0][113+f]==1) t=t+1024;
if (blk[0][112+f]==1) t=t+2048;
if (blk[0][111+f]==1) t=t+4096;
if (blk[0][110+f]==1) t=t+8192;
if (blk[0][109+f]==1) t=t+16384;
if (blk[0][108+f]==1) t=t+32768;
if (blk[0][103+f]==1) t=t+65536;
if (blk[0][102+f]==1) t=t+131072;
if (blk[0][101+f]==1) t=t+262144;
if (blk[0][100+f]==1) t=t+524288;
if (blk[0][99+f]==1) t=t+1048576;
if (blk[0][98+f]==1) t=t+2097152;
if (blk[0][97+f]==1) t=t+4194304;
if (blk[0][96+f]==1) t=t+8388608; 
moby_time(t);
strcat(line,ts);

blank_line();
extract_data();

if (sosinfo_ascii_show==TRUE)
 {
 ascii_protocols(line,0);
 return;
 }

hex_protocols(line,1);
}

// Handle AREALIST mpack //
void moby::arealist (void)
{
char tmp[30],line1[300],line2[300],line3[300],line4[300],line5[300],line6[300];
unsigned char a,command,no_valid,no_invalid,counter;
BOOL area[65],al2,al3,al4,al5,al6;

for (a=0;a<64;a++) area[a]=FALSE;

command=0;
no_valid=0;
counter=0;
al2=FALSE;
al3=FALSE;
al4=FALSE;
al5=FALSE;
al6=FALSE;

strcpy(line3,"");
strcpy(line4,"");
strcpy(line5,"");
strcpy(line6,"");

blank_line();

if (blk[0][168]==1) area[63]=TRUE;
if (blk[0][169]==1) area[62]=TRUE;
if (blk[0][170]==1) area[61]=TRUE;
if (blk[0][171]==1) area[60]=TRUE;
if (blk[0][172]==1) area[59]=TRUE;
if (blk[0][173]==1) area[58]=TRUE;
if (blk[0][174]==1) area[57]=TRUE;
if (blk[0][175]==1) area[56]=TRUE;

if (blk[0][180]==1) area[55]=TRUE;
if (blk[0][181]==1) area[54]=TRUE;
if (blk[0][182]==1) area[53]=TRUE;
if (blk[0][183]==1) area[52]=TRUE;
if (blk[0][184]==1) area[51]=TRUE;
if (blk[0][185]==1) area[50]=TRUE;
if (blk[0][186]==1) area[49]=TRUE;
if (blk[0][187]==1) area[48]=TRUE;

if (blk[0][192]==1) area[47]=TRUE;
if (blk[0][193]==1) area[46]=TRUE;
if (blk[0][194]==1) area[45]=TRUE;
if (blk[0][195]==1) area[44]=TRUE;
if (blk[0][196]==1) area[43]=TRUE;
if (blk[0][197]==1) area[42]=TRUE;
if (blk[0][198]==1) area[41]=TRUE;
if (blk[0][199]==1) area[40]=TRUE;

if (blk[0][204]==1) area[39]=TRUE;
if (blk[0][205]==1) area[38]=TRUE;
if (blk[0][206]==1) area[37]=TRUE;
if (blk[0][207]==1) area[36]=TRUE;
if (blk[0][208]==1) area[35]=TRUE;
if (blk[0][209]==1) area[34]=TRUE;
if (blk[0][210]==1) area[33]=TRUE;
if (blk[0][211]==1) area[32]=TRUE;

if (blk[1][0]==1) area[31]=TRUE;
if (blk[1][1]==1) area[30]=TRUE;
if (blk[1][2]==1) area[29]=TRUE;
if (blk[1][3]==1) area[28]=TRUE;
if (blk[1][4]==1) area[27]=TRUE;
if (blk[1][5]==1) area[26]=TRUE;
if (blk[1][6]==1) area[25]=TRUE;
if (blk[1][7]==1) area[24]=TRUE;

if (blk[1][12]==1) area[23]=TRUE;
if (blk[1][13]==1) area[22]=TRUE;
if (blk[1][14]==1) area[21]=TRUE;
if (blk[1][15]==1) area[20]=TRUE;
if (blk[1][16]==1) area[19]=TRUE;
if (blk[1][17]==1) area[18]=TRUE;
if (blk[1][18]==1) area[17]=TRUE;
if (blk[1][19]==1) area[16]=TRUE;

if (blk[1][24]==1) area[15]=TRUE;
if (blk[1][25]==1) area[14]=TRUE;
if (blk[1][26]==1) area[13]=TRUE;
if (blk[1][27]==1) area[12]=TRUE;
if (blk[1][28]==1) area[11]=TRUE;
if (blk[1][29]==1) area[10]=TRUE;
if (blk[1][30]==1) area[9]=TRUE;
if (blk[1][31]==1) area[8]=TRUE;

if (blk[1][36]==1) area[7]=TRUE;
if (blk[1][37]==1) area[6]=TRUE;
if (blk[1][38]==1) area[5]=TRUE;
if (blk[1][39]==1) area[4]=TRUE;
if (blk[1][40]==1) area[3]=TRUE;
if (blk[1][41]==1) area[2]=TRUE;
if (blk[1][42]==1) area[2]=TRUE;
if (blk[1][43]==1) area[1]=TRUE;

// What is the command ? //
if (blk[1][48]==1) command=128;
if (blk[1][49]==1) command=command+64;
if (blk[1][50]==1) command=command+32;
if (blk[1][51]==1) command=command+16;
if (blk[1][52]==1) command=command+8;
if (blk[1][53]==1) command=command+4;
if (blk[1][54]==1) command=command+2;
if (blk[1][55]==1) command++;

// How many area's are valid ? //
for (a=0;a<64;a++)
 if (area[a]==TRUE) no_valid++;

no_invalid=64-no_valid;

// Special cases //
if (no_valid==0 && command==0)
 {
 strcpy(line2,"Mobile must not operate in any area or roam to any base station.");
 al2=TRUE;
 goto arealstdone;
 }

if (command==0)
 {
 strcpy(line2,"The following are invalid area ID's and must not be used by the terminal");
 al2=TRUE;
 }
else
 {
 strcpy(line2,"The following are not invalid area ID's but may be used , but traffic will be charged at a different fee");
 al2=TRUE;
 }

// Only one invalid //
if (no_invalid==1)
 {
 for (a=0;a<64;a++)
  if (area[a]==FALSE) sprintf(line3,"%d",a);
 al3=TRUE;
 goto arealstdone;
 }

for (a=0;a<64;a++)
 {
 if (area[a]==FALSE)
  {
  if (counter==0) sprintf(tmp,"%d",a);
   else sprintf(tmp," , %d",a);

  if (counter<20)
   {
   strcat(line3,tmp);
   al3=TRUE;
   }

  if (counter>19 && counter<40)
   {
   strcat(line4,tmp);
   al4=TRUE;
   }

  if (counter>39 && counter<60)
   {
   strcat(line5,tmp);
   al5=TRUE;
   }

  if (counter>59)
   {
   strcat(line6,tmp);
   al6=TRUE;
   }

  counter++;
  }

 }

arealstdone:
if (al6==TRUE)
 {
 strcpy(s,line6);
 rotate();
 }

if (al5==TRUE)
 {
 strcpy(s,line5);
 rotate();
 }

if (al4==TRUE)
 {
 strcpy(s,line4);
 rotate();
 }

if (al3==TRUE)
 {
 strcpy(s,line3);
 rotate();
 }

if (al2==TRUE)
 {
 strcpy(s,line2);
 rotate();
 }

strcpy(s,"AREALIST");
strcpy(line1,s);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);

 if (al2==TRUE)
  {
  strcpy(s,line2);
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 if (al3==TRUE)
  {
  strcpy(s,line3);
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 if (al4==TRUE)
  {
  strcpy(s,line4);
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 if (al5==TRUE)
  {
  strcpy(s,line5);
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 if (al6==TRUE)
  {
  strcpy(s,line6);
  logout.Write(s,strlen(s));
  logout.Write(enc,1);
  }

 }
}

// Handle a ADDCONREQ mpak //
void moby::addconreq (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"ADDCONREQ");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a ADDCONFAST mpak //
void moby::addconfast (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"ADDCONFAST");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle a EXTCONREQ mpak //
void moby::extconreq (void)
{
unsigned char line,conid;
char tmp[15],line1[300];

blank_line();
strcpy(s,"EXTCONREQ");

// Line number //
line=0;
if (blk[0][103+f]==1) line++;
if (blk[0][102+f]==1) line=line+2;
if (blk[0][101+f]==1) line=line+4;
if (blk[0][100+f]==1) line=line+8;
if (blk[0][99+f]==1) line=line+16;
if (blk[0][98+f]==1) line=line+32;
if (blk[0][97+f]==1) line=line+64;
if (blk[0][96+f]==1) line=line+128; 
sprintf(tmp," Line#%d",line);
strcat(s,tmp);

// Connection identity //
conid=0;
if (blk[0][115+f]==1) conid++;;
if (blk[0][114+f]==1) conid=conid+2;
if (blk[0][113+f]==1) conid=conid+4;
if (blk[0][112+f]==1) conid=conid+8;
if (blk[0][111+f]==1) conid=conid+16;
if (blk[0][110+f]==1) conid=conid+32;
if (blk[0][109+f]==1) conid=conid+64;
if (blk[0][108+f]==1) conid=conid+128;
sprintf(tmp," Connection Identity#%d",conid);
strcat(s,tmp);

strcpy(line1,s);

rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 strcpy(s,line1);
 logout.Write(s,strlen(s));
 logout.Write(enc,1);
 }
}

// Handle GROUPLIST mpack //
void moby::grouplist (void)
{
unsigned long int man1,man2,man3,man4,man5,man6,man7,man8,man9;
unsigned long int man10,man11,man12,man13,man14,man15,t;
unsigned char man_count;
char line0[300],line1[300],line2[300],line3[300],line4[300],tmp[300];

blank_line();

// Number of MAN's //
man_count=0;
if (blk[0][103+f]==1) man_count++;
if (blk[0][102+f]==1) man_count=man_count+2;
if (blk[0][101+f]==1) man_count=man_count+4;
if (blk[0][100+f]==1) man_count=man_count+8;
if (blk[0][99+f]==1) man_count=man_count+16;
if (blk[0][98+f]==1) man_count=man_count+32;
if (blk[0][97+f]==1) man_count=man_count+64;
if (blk[0][96+f]==1) man_count=man_count+128; 

// 1st Man //
t=0;
if (blk[1][31]==1) t=1;
if (blk[1][30]==1) t=t+2;
if (blk[1][29]==1) t=t+4;
if (blk[1][28]==1) t=t+8;
if (blk[1][27]==1) t=t+16;
if (blk[1][26]==1) t=t+32;
if (blk[1][25]==1) t=t+64;
if (blk[1][24]==1) t=t+128;
if (blk[1][19]==1) t=t+256;
if (blk[1][18]==1) t=t+512;
if (blk[1][17]==1) t=t+1024;
if (blk[1][16]==1) t=t+2048;
if (blk[1][15]==1) t=t+4096;
if (blk[1][14]==1) t=t+8192;
if (blk[1][13]==1) t=t+16384;
if (blk[1][12]==1) t=t+32768;
if (blk[1][7]==1) t=t+65536;
if (blk[1][6]==1) t=t+131072;
if (blk[1][5]==1) t=t+262144;
if (blk[1][4]==1) t=t+524288;
if (blk[1][3]==1) t=t+1048576;
if (blk[1][2]==1) t=t+2097152;
if (blk[1][1]==1) t=t+4194304;
if (blk[1][0]==1) t=t+8388608; 
man1=t;

// 2nd Man //
t=0;
if (blk[1][67]==1) t=1;
if (blk[1][66]==1) t=t+2;
if (blk[1][65]==1) t=t+4;
if (blk[1][64]==1) t=t+8;
if (blk[1][63]==1) t=t+16;
if (blk[1][62]==1) t=t+32;
if (blk[1][61]==1) t=t+64;
if (blk[1][60]==1) t=t+128;
if (blk[1][55]==1) t=t+256;
if (blk[1][54]==1) t=t+512;
if (blk[1][53]==1) t=t+1024;
if (blk[1][52]==1) t=t+2048;
if (blk[1][51]==1) t=t+4096;
if (blk[1][50]==1) t=t+8192;
if (blk[1][49]==1) t=t+16384;
if (blk[1][48]==1) t=t+32768;
if (blk[1][43]==1) t=t+65536;
if (blk[1][42]==1) t=t+131072;
if (blk[1][41]==1) t=t+262144;
if (blk[1][40]==1) t=t+524288;
if (blk[1][39]==1) t=t+1048576;
if (blk[1][38]==1) t=t+2097152;
if (blk[1][37]==1) t=t+4194304;
if (blk[1][36]==1) t=t+8388608; 
man2=t;

// 3rd Man //
t=0;
if (blk[1][103]==1) t=1;
if (blk[1][102]==1) t=t+2;
if (blk[1][101]==1) t=t+4;
if (blk[1][100]==1) t=t+8;
if (blk[1][99]==1) t=t+16;
if (blk[1][98]==1) t=t+32;
if (blk[1][97]==1) t=t+64;
if (blk[1][96]==1) t=t+128;
if (blk[1][91]==1) t=t+256;
if (blk[1][90]==1) t=t+512;
if (blk[1][89]==1) t=t+1024;
if (blk[1][88]==1) t=t+2048;
if (blk[1][87]==1) t=t+4096;
if (blk[1][86]==1) t=t+8192;
if (blk[1][85]==1) t=t+16384;
if (blk[1][84]==1) t=t+32768;
if (blk[1][79]==1) t=t+65536;
if (blk[1][78]==1) t=t+131072;
if (blk[1][77]==1) t=t+262144;
if (blk[1][76]==1) t=t+524288;
if (blk[1][75]==1) t=t+1048576;
if (blk[1][74]==1) t=t+2097152;
if (blk[1][73]==1) t=t+4194304;
if (blk[1][72]==1) t=t+8388608; 
man3=t;

// 4th Man //
t=0;
if (blk[1][139]==1) t=1;
if (blk[1][138]==1) t=t+2;
if (blk[1][137]==1) t=t+4;
if (blk[1][136]==1) t=t+8;
if (blk[1][135]==1) t=t+16;
if (blk[1][134]==1) t=t+32;
if (blk[1][133]==1) t=t+64;
if (blk[1][132]==1) t=t+128;
if (blk[1][127]==1) t=t+256;
if (blk[1][126]==1) t=t+512;
if (blk[1][125]==1) t=t+1024;
if (blk[1][124]==1) t=t+2048;
if (blk[1][123]==1) t=t+4096;
if (blk[1][122]==1) t=t+8192;
if (blk[1][121]==1) t=t+16384;
if (blk[1][120]==1) t=t+32768;
if (blk[1][115]==1) t=t+65536;
if (blk[1][114]==1) t=t+131072;
if (blk[1][113]==1) t=t+262144;
if (blk[1][112]==1) t=t+524288;
if (blk[1][111]==1) t=t+1048576;
if (blk[1][110]==1) t=t+2097152;
if (blk[1][109]==1) t=t+4194304;
if (blk[1][108]==1) t=t+8388608; 
man4=t;

// 5th Man //
t=0;
if (blk[1][175]==1) t=1;
if (blk[1][174]==1) t=t+2;
if (blk[1][173]==1) t=t+4;
if (blk[1][172]==1) t=t+8;
if (blk[1][171]==1) t=t+16;
if (blk[1][170]==1) t=t+32;
if (blk[1][169]==1) t=t+64;
if (blk[1][168]==1) t=t+128;
if (blk[1][163]==1) t=t+256;
if (blk[1][162]==1) t=t+512;
if (blk[1][161]==1) t=t+1024;
if (blk[1][160]==1) t=t+2048;
if (blk[1][159]==1) t=t+4096;
if (blk[1][158]==1) t=t+8192;
if (blk[1][157]==1) t=t+16384;
if (blk[1][156]==1) t=t+32768;
if (blk[1][151]==1) t=t+65536;
if (blk[1][150]==1) t=t+131072;
if (blk[1][149]==1) t=t+262144;
if (blk[1][148]==1) t=t+524288;
if (blk[1][147]==1) t=t+1048576;
if (blk[1][146]==1) t=t+2097152;
if (blk[1][145]==1) t=t+4194304;
if (blk[1][144]==1) t=t+8388608; 
man5=t;

// 6th Man //
t=0;
if (blk[1][211]==1) t=1;
if (blk[1][210]==1) t=t+2;
if (blk[1][209]==1) t=t+4;
if (blk[1][208]==1) t=t+8;
if (blk[1][207]==1) t=t+16;
if (blk[1][206]==1) t=t+32;
if (blk[1][205]==1) t=t+64;
if (blk[1][204]==1) t=t+128;
if (blk[1][199]==1) t=t+256;
if (blk[1][198]==1) t=t+512;
if (blk[1][197]==1) t=t+1024;
if (blk[1][196]==1) t=t+2048;
if (blk[1][195]==1) t=t+4096;
if (blk[1][194]==1) t=t+8192;
if (blk[1][193]==1) t=t+16384;
if (blk[1][192]==1) t=t+32768;
if (blk[1][187]==1) t=t+65536;
if (blk[1][186]==1) t=t+131072;
if (blk[1][185]==1) t=t+262144;
if (blk[1][184]==1) t=t+524288;
if (blk[1][183]==1) t=t+1048576;
if (blk[1][182]==1) t=t+2097152;
if (blk[1][181]==1) t=t+4194304;
if (blk[1][180]==1) t=t+8388608; 
man6=t;

// 7th Man //
t=0;
if (blk[2][31]==1) t=1;
if (blk[2][30]==1) t=t+2;
if (blk[2][29]==1) t=t+4;
if (blk[2][28]==1) t=t+8;
if (blk[2][27]==1) t=t+16;
if (blk[2][26]==1) t=t+32;
if (blk[2][25]==1) t=t+64;
if (blk[2][24]==1) t=t+128;
if (blk[2][19]==1) t=t+256;
if (blk[2][18]==1) t=t+512;
if (blk[2][17]==1) t=t+1024;
if (blk[2][16]==1) t=t+2048;
if (blk[2][15]==1) t=t+4096;
if (blk[2][14]==1) t=t+8192;
if (blk[2][13]==1) t=t+16384;
if (blk[2][12]==1) t=t+32768;
if (blk[2][7]==1) t=t+65536;
if (blk[2][6]==1) t=t+131072;
if (blk[2][5]==1) t=t+262144;
if (blk[2][4]==1) t=t+524288;
if (blk[2][3]==1) t=t+1048576;
if (blk[2][2]==1) t=t+2097152;
if (blk[2][1]==1) t=t+4194304;
if (blk[2][0]==1) t=t+8388608; 
man7=t;

// 8th Man //
t=0;
if (blk[2][67]==1) t=1;
if (blk[2][66]==1) t=t+2;
if (blk[2][65]==1) t=t+4;
if (blk[2][64]==1) t=t+8;
if (blk[2][63]==1) t=t+16;
if (blk[2][62]==1) t=t+32;
if (blk[2][61]==1) t=t+64;
if (blk[2][60]==1) t=t+128;
if (blk[2][55]==1) t=t+256;
if (blk[2][54]==1) t=t+512;
if (blk[2][53]==1) t=t+1024;
if (blk[2][52]==1) t=t+2048;
if (blk[2][51]==1) t=t+4096;
if (blk[2][50]==1) t=t+8192;
if (blk[2][49]==1) t=t+16384;
if (blk[2][48]==1) t=t+32768;
if (blk[2][43]==1) t=t+65536;
if (blk[2][42]==1) t=t+131072;
if (blk[2][41]==1) t=t+262144;
if (blk[2][40]==1) t=t+524288;
if (blk[2][39]==1) t=t+1048576;
if (blk[2][38]==1) t=t+2097152;
if (blk[2][37]==1) t=t+4194304;
if (blk[2][36]==1) t=t+8388608; 
man8=t;

// 9th Man //
t=0;
if (blk[2][103]==1) t=1;
if (blk[2][102]==1) t=t+2;
if (blk[2][101]==1) t=t+4;
if (blk[2][100]==1) t=t+8;
if (blk[2][99]==1) t=t+16;
if (blk[2][98]==1) t=t+32;
if (blk[2][97]==1) t=t+64;
if (blk[2][96]==1) t=t+128;
if (blk[2][91]==1) t=t+256;
if (blk[2][90]==1) t=t+512;
if (blk[2][89]==1) t=t+1024;
if (blk[2][88]==1) t=t+2048;
if (blk[2][87]==1) t=t+4096;
if (blk[2][86]==1) t=t+8192;
if (blk[2][85]==1) t=t+16384;
if (blk[2][84]==1) t=t+32768;
if (blk[2][79]==1) t=t+65536;
if (blk[2][78]==1) t=t+131072;
if (blk[2][77]==1) t=t+262144;
if (blk[2][76]==1) t=t+524288;
if (blk[2][75]==1) t=t+1048576;
if (blk[2][74]==1) t=t+2097152;
if (blk[2][73]==1) t=t+4194304;
if (blk[2][72]==1) t=t+8388608; 
man9=t;

// 10th Man //
t=0;
if (blk[2][139]==1) t=1;
if (blk[2][138]==1) t=t+2;
if (blk[2][137]==1) t=t+4;
if (blk[2][136]==1) t=t+8;
if (blk[2][135]==1) t=t+16;
if (blk[2][134]==1) t=t+32;
if (blk[2][133]==1) t=t+64;
if (blk[2][132]==1) t=t+128;
if (blk[2][127]==1) t=t+256;
if (blk[2][126]==1) t=t+512;
if (blk[2][125]==1) t=t+1024;
if (blk[2][124]==1) t=t+2048;
if (blk[2][123]==1) t=t+4096;
if (blk[2][122]==1) t=t+8192;
if (blk[2][121]==1) t=t+16384;
if (blk[2][120]==1) t=t+32768;
if (blk[2][115]==1) t=t+65536;
if (blk[2][114]==1) t=t+131072;
if (blk[2][113]==1) t=t+262144;
if (blk[2][112]==1) t=t+524288;
if (blk[2][111]==1) t=t+1048576;
if (blk[2][110]==1) t=t+2097152;
if (blk[2][109]==1) t=t+4194304;
if (blk[2][108]==1) t=t+8388608; 
man10=t;

// 11th Man //
t=0;
if (blk[2][175]==1) t=1;
if (blk[2][174]==1) t=t+2;
if (blk[2][173]==1) t=t+4;
if (blk[2][172]==1) t=t+8;
if (blk[2][171]==1) t=t+16;
if (blk[2][170]==1) t=t+32;
if (blk[2][169]==1) t=t+64;
if (blk[2][168]==1) t=t+128;
if (blk[2][163]==1) t=t+256;
if (blk[2][162]==1) t=t+512;
if (blk[2][161]==1) t=t+1024;
if (blk[2][160]==1) t=t+2048;
if (blk[2][159]==1) t=t+4096;
if (blk[2][158]==1) t=t+8192;
if (blk[2][157]==1) t=t+16384;
if (blk[2][156]==1) t=t+32768;
if (blk[2][151]==1) t=t+65536;
if (blk[2][150]==1) t=t+131072;
if (blk[2][149]==1) t=t+262144;
if (blk[2][148]==1) t=t+524288;
if (blk[2][147]==1) t=t+1048576;
if (blk[2][146]==1) t=t+2097152;
if (blk[2][145]==1) t=t+4194304;
if (blk[2][144]==1) t=t+8388608; 
man11=t;

// 12th Man //
t=0;
if (blk[2][211]==1) t=1;
if (blk[2][210]==1) t=t+2;
if (blk[2][209]==1) t=t+4;
if (blk[2][208]==1) t=t+8;
if (blk[2][207]==1) t=t+16;
if (blk[2][206]==1) t=t+32;
if (blk[2][205]==1) t=t+64;
if (blk[2][204]==1) t=t+128;
if (blk[2][199]==1) t=t+256;
if (blk[2][198]==1) t=t+512;
if (blk[2][197]==1) t=t+1024;
if (blk[2][196]==1) t=t+2048;
if (blk[2][195]==1) t=t+4096;
if (blk[2][194]==1) t=t+8192;
if (blk[2][193]==1) t=t+16384;
if (blk[2][192]==1) t=t+32768;
if (blk[2][187]==1) t=t+65536;
if (blk[2][186]==1) t=t+131072;
if (blk[2][185]==1) t=t+262144;
if (blk[2][184]==1) t=t+524288;
if (blk[2][183]==1) t=t+1048576;
if (blk[2][182]==1) t=t+2097152;
if (blk[2][181]==1) t=t+4194304;
if (blk[2][180]==1) t=t+8388608; 
man12=t;

// 13th Man //
t=0;
if (blk[3][31]==1) t=1;
if (blk[3][30]==1) t=t+2;
if (blk[3][29]==1) t=t+4;
if (blk[3][28]==1) t=t+8;
if (blk[3][27]==1) t=t+16;
if (blk[3][26]==1) t=t+32;
if (blk[3][25]==1) t=t+64;
if (blk[3][24]==1) t=t+128;
if (blk[3][19]==1) t=t+256;
if (blk[3][18]==1) t=t+512;
if (blk[3][17]==1) t=t+1024;
if (blk[3][16]==1) t=t+2048;
if (blk[3][15]==1) t=t+4096;
if (blk[3][14]==1) t=t+8192;
if (blk[3][13]==1) t=t+16384;
if (blk[3][12]==1) t=t+32768;
if (blk[3][7]==1) t=t+65536;
if (blk[3][6]==1) t=t+131072;
if (blk[3][5]==1) t=t+262144;
if (blk[3][4]==1) t=t+524288;
if (blk[3][3]==1) t=t+1048576;
if (blk[3][2]==1) t=t+2097152;
if (blk[3][1]==1) t=t+4194304;
if (blk[3][0]==1) t=t+8388608; 
man13=t;

// 14th Man //
t=0;
if (blk[3][67]==1) t=1;
if (blk[3][66]==1) t=t+2;
if (blk[3][65]==1) t=t+4;
if (blk[3][64]==1) t=t+8;
if (blk[3][63]==1) t=t+16;
if (blk[3][62]==1) t=t+32;
if (blk[3][61]==1) t=t+64;
if (blk[3][60]==1) t=t+128;
if (blk[3][55]==1) t=t+256;
if (blk[3][54]==1) t=t+512;
if (blk[3][53]==1) t=t+1024;
if (blk[3][52]==1) t=t+2048;
if (blk[3][51]==1) t=t+4096;
if (blk[3][50]==1) t=t+8192;
if (blk[3][49]==1) t=t+16384;
if (blk[3][48]==1) t=t+32768;
if (blk[3][43]==1) t=t+65536;
if (blk[3][42]==1) t=t+131072;
if (blk[3][41]==1) t=t+262144;
if (blk[3][40]==1) t=t+524288;
if (blk[3][39]==1) t=t+1048576;
if (blk[3][38]==1) t=t+2097152;
if (blk[3][37]==1) t=t+4194304;
if (blk[3][36]==1) t=t+8388608; 
man14=t;

// 15th Man //
t=0;
if (blk[3][103]==1) t=1;
if (blk[3][102]==1) t=t+2;
if (blk[3][101]==1) t=t+4;
if (blk[3][100]==1) t=t+8;
if (blk[3][99]==1) t=t+16;
if (blk[3][98]==1) t=t+32;
if (blk[3][97]==1) t=t+64;
if (blk[3][96]==1) t=t+128;
if (blk[3][91]==1) t=t+256;
if (blk[3][90]==1) t=t+512;
if (blk[3][89]==1) t=t+1024;
if (blk[3][88]==1) t=t+2048;
if (blk[3][87]==1) t=t+4096;
if (blk[3][86]==1) t=t+8192;
if (blk[3][85]==1) t=t+16384;
if (blk[3][84]==1) t=t+32768;
if (blk[3][79]==1) t=t+65536;
if (blk[3][78]==1) t=t+131072;
if (blk[3][77]==1) t=t+262144;
if (blk[3][76]==1) t=t+524288;
if (blk[3][75]==1) t=t+1048576;
if (blk[3][74]==1) t=t+2097152;
if (blk[3][73]==1) t=t+4194304;
if (blk[3][72]==1) t=t+8388608; 
man15=t;

sprintf(line1,"%x",man1);
if (man_count>1)
 {
 sprintf(tmp,",%x",man2);
 strcat(line1,tmp);
 }
if (man_count>2)
 {
 sprintf(tmp,",%x",man3);
 strcat(line1,tmp);
 }
if (man_count>3)
 {
 sprintf(tmp,",%x",man4);
 strcat(line1,tmp);
 }
if (man_count>4) sprintf(line2,"%x",man5);
if (man_count>5)
 {
 sprintf(tmp,",%x",man6);
 strcat(line2,tmp);
 }
if (man_count>6)
 {
 sprintf(tmp,",%x",man7);
 strcat(line2,tmp);
 }
if (man_count>7)
 {
 sprintf(tmp,",%x",man8);
 strcat(line2,tmp);
 }
if (man_count>8) sprintf(line3,"%x",man9);
if (man_count>9)
 {
 sprintf(tmp,",%x",man10);
 strcat(line3,tmp);
 }
if (man_count>10)
 {
 sprintf(tmp,",%x",man11);
 strcat(line3,tmp);
 }
if (man_count>11)
 {
 sprintf(tmp,",%x",man12);
 strcat(line3,tmp);
 }
if (man_count>12) sprintf(line4,"%x",man13);
if (man_count>13)
 {
 sprintf(tmp,",%x",man14);
 strcat(line4,tmp);
 }
if (man_count>14)
 {
 sprintf(tmp,",%x",man15);
 strcat(line4,tmp);
 }


// Display the MANs //
if (man_count>12)
 {
 strcpy(s,line4);
 rotate();
 }

if (man_count>8)
 {
 strcpy(s,line3);
 rotate();
 }

if (man_count>4)
 {
 strcpy(s,line2);
 rotate();
 }
 
// 1st MANs //
strcpy(s,line1);
rotate();

// Top line //
strcpy(s,"GROUPLIST (");
sprintf(tmp,"%d",man_count);
strcat(s,tmp);
strcpy(tmp,")");
strcat(s,tmp);

strcpy(line0,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);

 if (man_count>4)
  {
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }

  if (man_count>8)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }

 if (man_count>12)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }
 }
}

// Handle FLEXLIST mpack //
void moby::flexlist (void)
{
unsigned long int man1,man2,man3,man4,man5,man6,man7,t;
unsigned char man_count;
char line0[300],line1[300],line2[300],tmp[300];

blank_line();

// Number of MAN's //
man_count=0;
if (blk[0][103+f]==1) man_count++;
if (blk[0][102+f]==1) man_count=man_count+2;
if (blk[0][101+f]==1) man_count=man_count+4;
if (blk[0][100+f]==1) man_count=man_count+8;
if (blk[0][99+f]==1) man_count=man_count+16;
if (blk[0][98+f]==1) man_count=man_count+32;
if (blk[0][97+f]==1) man_count=man_count+64;
if (blk[0][96+f]==1) man_count=man_count+128; 

// 1st Man //
t=0;
if (blk[1][31]==1) t=1;
if (blk[1][30]==1) t=t+2;
if (blk[1][29]==1) t=t+4;
if (blk[1][28]==1) t=t+8;
if (blk[1][27]==1) t=t+16;
if (blk[1][26]==1) t=t+32;
if (blk[1][25]==1) t=t+64;
if (blk[1][24]==1) t=t+128;
if (blk[1][19]==1) t=t+256;
if (blk[1][18]==1) t=t+512;
if (blk[1][17]==1) t=t+1024;
if (blk[1][16]==1) t=t+2048;
if (blk[1][15]==1) t=t+4096;
if (blk[1][14]==1) t=t+8192;
if (blk[1][13]==1) t=t+16384;
if (blk[1][12]==1) t=t+32768;
if (blk[1][7]==1) t=t+65536;
if (blk[1][6]==1) t=t+131072;
if (blk[1][5]==1) t=t+262144;
if (blk[1][4]==1) t=t+524288;
if (blk[1][3]==1) t=t+1048576;
if (blk[1][2]==1) t=t+2097152;
if (blk[1][1]==1) t=t+4194304;
if (blk[1][0]==1) t=t+8388608; 
man1=t;

// 2nd Man //
t=0;
if (blk[1][67]==1) t=1;
if (blk[1][66]==1) t=t+2;
if (blk[1][65]==1) t=t+4;
if (blk[1][64]==1) t=t+8;
if (blk[1][63]==1) t=t+16;
if (blk[1][62]==1) t=t+32;
if (blk[1][61]==1) t=t+64;
if (blk[1][60]==1) t=t+128;
if (blk[1][55]==1) t=t+256;
if (blk[1][54]==1) t=t+512;
if (blk[1][53]==1) t=t+1024;
if (blk[1][52]==1) t=t+2048;
if (blk[1][51]==1) t=t+4096;
if (blk[1][50]==1) t=t+8192;
if (blk[1][49]==1) t=t+16384;
if (blk[1][48]==1) t=t+32768;
if (blk[1][43]==1) t=t+65536;
if (blk[1][42]==1) t=t+131072;
if (blk[1][41]==1) t=t+262144;
if (blk[1][40]==1) t=t+524288;
if (blk[1][39]==1) t=t+1048576;
if (blk[1][38]==1) t=t+2097152;
if (blk[1][37]==1) t=t+4194304;
if (blk[1][36]==1) t=t+8388608; 
man2=t;

// 3rd Man //
t=0;
if (blk[1][103]==1) t=1;
if (blk[1][102]==1) t=t+2;
if (blk[1][101]==1) t=t+4;
if (blk[1][100]==1) t=t+8;
if (blk[1][99]==1) t=t+16;
if (blk[1][98]==1) t=t+32;
if (blk[1][97]==1) t=t+64;
if (blk[1][96]==1) t=t+128;
if (blk[1][91]==1) t=t+256;
if (blk[1][90]==1) t=t+512;
if (blk[1][89]==1) t=t+1024;
if (blk[1][88]==1) t=t+2048;
if (blk[1][87]==1) t=t+4096;
if (blk[1][86]==1) t=t+8192;
if (blk[1][85]==1) t=t+16384;
if (blk[1][84]==1) t=t+32768;
if (blk[1][79]==1) t=t+65536;
if (blk[1][78]==1) t=t+131072;
if (blk[1][77]==1) t=t+262144;
if (blk[1][76]==1) t=t+524288;
if (blk[1][75]==1) t=t+1048576;
if (blk[1][74]==1) t=t+2097152;
if (blk[1][73]==1) t=t+4194304;
if (blk[1][72]==1) t=t+8388608; 
man3=t;

// 4th Man //
t=0;
if (blk[1][139]==1) t=1;
if (blk[1][138]==1) t=t+2;
if (blk[1][137]==1) t=t+4;
if (blk[1][136]==1) t=t+8;
if (blk[1][135]==1) t=t+16;
if (blk[1][134]==1) t=t+32;
if (blk[1][133]==1) t=t+64;
if (blk[1][132]==1) t=t+128;
if (blk[1][127]==1) t=t+256;
if (blk[1][126]==1) t=t+512;
if (blk[1][125]==1) t=t+1024;
if (blk[1][124]==1) t=t+2048;
if (blk[1][123]==1) t=t+4096;
if (blk[1][122]==1) t=t+8192;
if (blk[1][121]==1) t=t+16384;
if (blk[1][120]==1) t=t+32768;
if (blk[1][115]==1) t=t+65536;
if (blk[1][114]==1) t=t+131072;
if (blk[1][113]==1) t=t+262144;
if (blk[1][112]==1) t=t+524288;
if (blk[1][111]==1) t=t+1048576;
if (blk[1][110]==1) t=t+2097152;
if (blk[1][109]==1) t=t+4194304;
if (blk[1][108]==1) t=t+8388608; 
man4=t;

// 5th Man //
t=0;
if (blk[1][175]==1) t=1;
if (blk[1][174]==1) t=t+2;
if (blk[1][173]==1) t=t+4;
if (blk[1][172]==1) t=t+8;
if (blk[1][171]==1) t=t+16;
if (blk[1][170]==1) t=t+32;
if (blk[1][169]==1) t=t+64;
if (blk[1][168]==1) t=t+128;
if (blk[1][163]==1) t=t+256;
if (blk[1][162]==1) t=t+512;
if (blk[1][161]==1) t=t+1024;
if (blk[1][160]==1) t=t+2048;
if (blk[1][159]==1) t=t+4096;
if (blk[1][158]==1) t=t+8192;
if (blk[1][157]==1) t=t+16384;
if (blk[1][156]==1) t=t+32768;
if (blk[1][151]==1) t=t+65536;
if (blk[1][150]==1) t=t+131072;
if (blk[1][149]==1) t=t+262144;
if (blk[1][148]==1) t=t+524288;
if (blk[1][147]==1) t=t+1048576;
if (blk[1][146]==1) t=t+2097152;
if (blk[1][145]==1) t=t+4194304;
if (blk[1][144]==1) t=t+8388608; 
man5=t;

// 6th Man //
t=0;
if (blk[1][211]==1) t=1;
if (blk[1][210]==1) t=t+2;
if (blk[1][209]==1) t=t+4;
if (blk[1][208]==1) t=t+8;
if (blk[1][207]==1) t=t+16;
if (blk[1][206]==1) t=t+32;
if (blk[1][205]==1) t=t+64;
if (blk[1][204]==1) t=t+128;
if (blk[1][199]==1) t=t+256;
if (blk[1][198]==1) t=t+512;
if (blk[1][197]==1) t=t+1024;
if (blk[1][196]==1) t=t+2048;
if (blk[1][195]==1) t=t+4096;
if (blk[1][194]==1) t=t+8192;
if (blk[1][193]==1) t=t+16384;
if (blk[1][192]==1) t=t+32768;
if (blk[1][187]==1) t=t+65536;
if (blk[1][186]==1) t=t+131072;
if (blk[1][185]==1) t=t+262144;
if (blk[1][184]==1) t=t+524288;
if (blk[1][183]==1) t=t+1048576;
if (blk[1][182]==1) t=t+2097152;
if (blk[1][181]==1) t=t+4194304;
if (blk[1][180]==1) t=t+8388608; 
man6=t;

// 7th Man //
t=0;
if (blk[2][31]==1) t=1;
if (blk[2][30]==1) t=t+2;
if (blk[2][29]==1) t=t+4;
if (blk[2][28]==1) t=t+8;
if (blk[2][27]==1) t=t+16;
if (blk[2][26]==1) t=t+32;
if (blk[2][25]==1) t=t+64;
if (blk[2][24]==1) t=t+128;
if (blk[2][19]==1) t=t+256;
if (blk[2][18]==1) t=t+512;
if (blk[2][17]==1) t=t+1024;
if (blk[2][16]==1) t=t+2048;
if (blk[2][15]==1) t=t+4096;
if (blk[2][14]==1) t=t+8192;
if (blk[2][13]==1) t=t+16384;
if (blk[2][12]==1) t=t+32768;
if (blk[2][7]==1) t=t+65536;
if (blk[2][6]==1) t=t+131072;
if (blk[2][5]==1) t=t+262144;
if (blk[2][4]==1) t=t+524288;
if (blk[2][3]==1) t=t+1048576;
if (blk[2][2]==1) t=t+2097152;
if (blk[2][1]==1) t=t+4194304;
if (blk[2][0]==1) t=t+8388608; 
man7=t;

sprintf(line1,"%x",man1);
if (man_count>1)
 {
 sprintf(tmp,",%x",man2);
 strcat(line1,tmp);
 }
if (man_count>2)
 {
 sprintf(tmp,",%x",man3);
 strcat(line1,tmp);
 }
if (man_count>3)
 {
 sprintf(tmp,",%x",man4);
 strcat(line1,tmp);
 }
if (man_count>4) sprintf(line2,"%x",man5);
if (man_count>5)
 {
 sprintf(tmp,",%x",man6);
 strcat(line2,tmp);
 }
if (man_count>6)
 {
 sprintf(tmp,",%x",man7);
 strcat(line2,tmp);
 }

// Display the MANs //
if (man_count>4)
 {
 strcpy(s,line2);
 rotate();
 }
 
// 1st MANs //
strcpy(s,line1);
rotate();

// Top line //
strcpy(s,"FLEXLIST (");
sprintf(tmp,"%d",man_count);
strcat(s,tmp);
strcpy(tmp,")");
strcat(s,tmp);

strcpy(line0,s);
rotate();
display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);

 if (man_count>4)
  {
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }
 }
}

// deal with SOS mpaks //
void moby::sos (void)
{
unsigned long int t;
char line0[300];

strcpy(line0,"SOS "); 

// If no address list //
if (blk[0][77+f]==0)
 {
 // Work out the mobitex time //
 t=0;
 if (blk[0][127+f]==1) t=1;
 if (blk[0][126+f]==1) t=t+2;
 if (blk[0][125+f]==1) t=t+4;
 if (blk[0][124+f]==1) t=t+8;
 if (blk[0][123+f]==1) t=t+16;
 if (blk[0][122+f]==1) t=t+32;
 if (blk[0][121+f]==1) t=t+64;
 if (blk[0][120+f]==1) t=t+128;
 if (blk[0][115+f]==1) t=t+256;
 if (blk[0][114+f]==1) t=t+512;
 if (blk[0][113+f]==1) t=t+1024;
 if (blk[0][112+f]==1) t=t+2048;
 if (blk[0][111+f]==1) t=t+4096;
 if (blk[0][110+f]==1) t=t+8192;
 if (blk[0][109+f]==1) t=t+16384;
 if (blk[0][108+f]==1) t=t+32768;
 if (blk[0][103+f]==1) t=t+65536;
 if (blk[0][102+f]==1) t=t+131072;
 if (blk[0][101+f]==1) t=t+262144;
 if (blk[0][100+f]==1) t=t+524288;
 if (blk[0][99+f]==1) t=t+1048576;
 if (blk[0][98+f]==1) t=t+2097152;
 if (blk[0][97+f]==1) t=t+4194304;
 if (blk[0][96+f]==1) t=t+8388608; 
 moby_time(t);
 strcat(line0,ts);

 blank_line();
 extract_data();

 if (sos_ascii_show==TRUE)
 {
 ascii_protocols(line0,0);
 return;
 }

 hex_protocols(line0,1);
 }

}

// Extract data from blocks with no address lists //
void moby::extract_data (void)
{
int a,b;

// Value of the first byte //
by[0]=data_strip(0,211);      
 
// 2nd Block //
if (bcounter>1)
 {
 b=7;
 for (a=1;a<19;a++)
  {
  by[a]=data_strip(1,b);
  b=b+12;
  }
 }

// 3rd block //
if (bcounter>2)
 {
 b=7;
 for (a=19;a<37;a++)
  {
  by[a]=data_strip(2,b);
  b=b+12;
  }
 }

// 4th block //
if (bcounter>3)
 {
 b=7;
 for (a=37;a<55;a++)
  {
  by[a]=data_strip(3,b);
  b=b+12;
  }
 }

// 5th block //
if (bcounter>4)
 {
 b=7;
 for (a=55;a<73;a++)
  {
  by[a]=data_strip(4,b);
  b=b+12;
  }
 }

// 6th block //
if (bcounter>5)
 {
 b=7;
 for (a=73;a<91;a++)
  {
  by[a]=data_strip(5,b);
  b=b+12;
  }
 }

// 7th block //
if (bcounter>6)
 {
 b=7;
 for (a=91;a<109;a++)
  {
  by[a]=data_strip(6,b);
  b=b+12;
  }
 }

// 8th block //
if (bcounter>7)
 {
 b=7;
 for (a=109;a<127;a++)
  {
  by[a]=data_strip(7,b);
  b=b+12;
  }
 }

// 9th block //
if (bcounter>8)
 {
 b=7;
 for (a=127;a<145;a++)
  {
  by[a]=data_strip(8,b);
  b=b+12;
  }
 }

// 10th block //
if (bcounter>9)
 {
 b=7;
 for (a=145;a<163;a++)
  {
  by[a]=data_strip(9,b);
  b=b+12;
  }
 }

// 11th block //
if (bcounter>10)
 {
 b=7;
 for (a=163;a<181;a++)
  {
  by[a]=data_strip(10,b);
  b=b+12;
  }
 }

// 12th block //
if (bcounter>11)
 {
 b=7;
 for (a=181;a<199;a++)
  {
  by[a]=data_strip(11,b);
  b=b+12;
  }
 }

// 13th block //
if (bcounter>12)
 {
 b=7;
 for (a=199;a<217;a++)
  {
  by[a]=data_strip(12,b);
  b=b+12;
  }
 }

// 14th block //
if (bcounter>13)
 {
 b=7;
 for (a=217;a<235;a++)
  {
  by[a]=data_strip(13,b);
  b=b+12;
  }
 }

// 15th block //
if (bcounter>14)
 {
 b=7;
 for (a=235;a<253;a++)
  {
  by[a]=data_strip(14,b);
  b=b+12;
  }
 }

// 16th block //
if (bcounter>15)
 {
 b=7;
 for (a=253;a<271;a++)
  {
  by[a]=data_strip(15,b);
  b=b+12;
  }
 }

// 17th block //
if (bcounter>16)
 {
 b=7;
 for (a=271;a<289;a++)
  {
  by[a]=data_strip(16,b);
  b=b+12;
  }
 }

// 18th block //
if (bcounter>17)
 {
 b=7;
 for (a=289;a<307;a++)
  {
  by[a]=data_strip(17,b);
  b=b+12;
  }
 }

// 19th block //
if (bcounter>18)
 {
 b=7;
 for (a=307;a<325;a++)
  {
  by[a]=data_strip(18,b);
  b=b+12;
  }
 }

// 20th block //
if (bcounter>19)
 {
 b=7;
 for (a=325;a<343;a++)
  {
  by[a]=data_strip(19,b);
  b=b+12;
  }
 }

// 21st block //
if (bcounter>20)
 {
 b=7;
 for (a=343;a<361;a++)
  {
  by[a]=data_strip(20,b);
  b=b+12;
  }
 }

// 22nd block //
if (bcounter>21)
 {
 b=7;
 for (a=361;a<379;a++)
  {
  by[a]=data_strip(21,b);
  b=b+12;
  }
 }

// 23rd block //
if (bcounter>22)
 {
 b=7;
 for (a=379;a<397;a++)
  {
  by[a]=data_strip(22,b);
  b=b+12;
  }
 }

// 24th block //
if (bcounter>23)
 {
 b=7;
 for (a=397;a<415;a++)
  {
  by[a]=data_strip(23,b);
  b=b+12;
  }
 }

// 25th block //
if (bcounter>24)
 {
 b=7;
 for (a=415;a<433;a++)
  {
  by[a]=data_strip(24,b);
  b=b+12;
  }
 }

// 26th block //
if (bcounter>25)
 {
 b=7;
 for (a=433;a<451;a++)
  {
  by[a]=data_strip(25,b);
  b=b+12;
  }
 }

// 27th block //
if (bcounter>26)
 {
 b=7;
 for (a=451;a<469;a++)
  {
  by[a]=data_strip(26,b);
  b=b+12;
  }
 }

// 28th block //
if (bcounter>27)
 {
 b=7;
 for (a=469;a<487;a++)
  {
  by[a]=data_strip(27,b);
  b=b+12;
  }
 }

// 29th block //
if (bcounter>28)
 {
 b=7;
 for (a=487;a<505;a++)
  {
  by[a]=data_strip(28,b);
  b=b+12;
  }
 }

// 30th block //
if (bcounter>29)
 {
 b=7;
 for (a=505;a<523;a++)
  {
  by[a]=data_strip(29,b);
  b=b+12;
  }
 }

// 31st block //
if (bcounter>30)
 {
 b=7;
 for (a=523;a<541;a++)
  {
  by[a]=data_strip(30,b);
  b=b+12;
  }
 }

// 32nd block //
if (bcounter>31)
 {
 b=7;
 for (a=541;a<559;a++)
  {
  by[a]=data_strip(31,b);
  b=b+12;
  }
 }

// 33rd block //
if (bcounter>32)
 {
 b=7;
 for (a=559;a<577;a++)
  {
  by[a]=data_strip(32,b);
  b=b+12;
  }
 }

// 34th block //
if (bcounter>33)
 {
 b=7;
 for (a=577;a<595;a++)
  {
  by[a]=data_strip(33,b);
  b=b+12;
  }
 }

// 35th block //
if (bcounter>34)
 {
 b=7;
 for (a=595;a<613;a++)
  {
  by[a]=data_strip(34,b);
  b=b+12;
  }
 }

// 36th block //
if (bcounter>35)
 {
 b=7;
 for (a=613;a<631;a++)
  {
  by[a]=data_strip(35,b);
  b=b+12;
  }
 }

// 37th block //
if (bcounter>36)
 {
 b=7;
 for (a=631;a<649;a++)
  {
  by[a]=data_strip(36,b);
  b=b+12;
  }
 }

// 38th block //
if (bcounter>37)
 {
 b=7;
 for (a=649;a<667;a++)
  {
  by[a]=data_strip(37,b);
  b=b+12;
  }
 }

// 39th block //
if (bcounter>38)
 {
 b=7;
 for (a=667;a<685;a++)
  {
  by[a]=data_strip(38,b);
  b=b+12;
  }
 }

// 40th block //
if (bcounter>39)
 {
 b=7;
 for (a=685;a<703;a++)
  {
  by[a]=data_strip(39,b);
  b=b+12;
  }
 }

// 41st block //
if (bcounter>40)
 {
 b=7;
 for (a=703;a<721;a++)
  {
  by[a]=data_strip(40,b);
  b=b+12;
  }
 }

// 42nd block //
if (bcounter>41)
 {
 b=7;
 for (a=721;a<739;a++)
  {
  by[a]=data_strip(41,b);
  b=b+12;
  }
 }

// 43rd block //
if (bcounter>42)
 {
 b=7;
 for (a=739;a<757;a++)
  {
  by[a]=data_strip(42,b);
  b=b+12;
  }
 }

// 44th block //
if (bcounter>43)
 {
 b=7;
 for (a=757;a<775;a++)
  {
  by[a]=data_strip(43,b);
  b=b+12;
  }
 }

// 45th block //
if (bcounter>44)
 {
 b=7;
 for (a=775;a<793;a++)
  {
  by[a]=data_strip(44,b);
  b=b+12;
  }
 }

// 46th block //
if (bcounter>45)
 {
 b=7;
 for (a=793;a<811;a++)
  {
  by[a]=data_strip(45,b);
  b=b+12;
  }
 }

// 47th block //
if (bcounter>46)
 {
 b=7;
 for (a=811;a<829;a++)
  {
  by[a]=data_strip(46,b);
  b=b+12;
  }
 }

// 48th block //
if (bcounter>47)
 {
 b=7;
 for (a=829;a<847;a++)
  {
  by[a]=data_strip(47,b);
  b=b+12;
  }
 }

// 49th block //
if (bcounter>48)
 {
 b=7;
 for (a=847;a<865;a++)
  {
  by[a]=data_strip(48,b);
  b=b+12;
  }
 }

// 50th block //
if (bcounter>49)
 {
 b=7;
 for (a=865;a<883;a++)
  {
  by[a]=data_strip(49,b);
  b=b+12;
  }
 }

}

// Extract data from blocks with an address lists //
void moby::extract_data_add (void)
{
int a,b;

// 2nd Block (no data in first block) //
b=36;
for (a=0;a<15;a++)
 {
 by[a]=data_strip(2,b);
 b=b+12;
 }

// 3rd block //
if (bcounter>2)
 {
 b=7;
 for (a=15;a<33;a++)
  {
  by[a]=data_strip(3,b);
  b=b+12;
  }
 }

// 4th block //
if (bcounter>3)
 {
 b=7;
 for (a=33;a<51;a++)
  {
  by[a]=data_strip(4,b);
  b=b+12;
  }
 }

// 5th block //
if (bcounter>4)
 {
 b=7;
 for (a=51;a<69;a++)
  {
  by[a]=data_strip(5,b);
  b=b+12;
  }
 }

// 6th block //
if (bcounter>5)
 {
 b=7;
 for (a=69;a<87;a++)
  {
  by[a]=data_strip(6,b);
  b=b+12;
  }
 }

// 7th block //
if (bcounter>6)
 {
 b=7;
 for (a=87;a<105;a++)
  {
  by[a]=data_strip(7,b);
  b=b+12;
  }
 }

// 8th block //
if (bcounter>7)
 {
 b=7;
 for (a=105;a<123;a++)
  {
  by[a]=data_strip(8,b);
  b=b+12;
  }
 }

// 9th block //
if (bcounter>8)
 {
 b=7;
 for (a=123;a<141;a++)
  {
  by[a]=data_strip(9,b);
  b=b+12;
  }
 }

// 10th block //
if (bcounter>9)
 {
 b=7;
 for (a=141;a<159;a++)
  {
  by[a]=data_strip(10,b);
  b=b+12;
  }
 }

// 11th block //
if (bcounter>10)
 {
 b=7;
 for (a=159;a<177;a++)
  {
  by[a]=data_strip(11,b);
  b=b+12;
  }
 }

// 12th block //
if (bcounter>11)
 {
 b=7;
 for (a=177;a<195;a++)
  {
  by[a]=data_strip(12,b);
  b=b+12;
  }
 }

// 13th block //
if (bcounter>12)
 {
 b=7;
 for (a=195;a<213;a++)
  {
  by[a]=data_strip(13,b);
  b=b+12;
  }
 }

// 14th block //
if (bcounter>13)
 {
 b=7;
 for (a=213;a<231;a++)
  {
  by[a]=data_strip(14,b);
  b=b+12;
  }
 }

// 15th block //
if (bcounter>14)
 {
 b=7;
 for (a=231;a<249;a++)
  {
  by[a]=data_strip(15,b);
  b=b+12;
  }
 }

// 16th block //
if (bcounter>15)
 {
 b=7;
 for (a=249;a<267;a++)
  {
  by[a]=data_strip(16,b);
  b=b+12;
  }
 }

// 17th block //
if (bcounter>16)
 {
 b=7;
 for (a=267;a<285;a++)
  {
  by[a]=data_strip(17,b);
  b=b+12;
  }
 }

// 18th block //
if (bcounter>17)
 {
 b=7;
 for (a=285;a<303;a++)
  {
  by[a]=data_strip(18,b);
  b=b+12;
  }
 }

// 19th block //
if (bcounter>18)
 {
 b=7;
 for (a=303;a<321;a++)
  {
  by[a]=data_strip(19,b);
  b=b+12;
  }
 }

// 20th block //
if (bcounter>19)
 {
 b=7;
 for (a=321;a<339;a++)
  {
  by[a]=data_strip(20,b);
  b=b+12;
  }
 }

// 21st block //
if (bcounter>20)
 {
 b=7;
 for (a=339;a<357;a++)
  {
  by[a]=data_strip(21,b);
  b=b+12;
  }
 }

// 22nd block //
if (bcounter>21)
 {
 b=7;
 for (a=357;a<375;a++)
  {
  by[a]=data_strip(22,b);
  b=b+12;
  }
 }

// 23rd block //
if (bcounter>22)
 {
 b=7;
 for (a=375;a<393;a++)
  {
  by[a]=data_strip(23,b);
  b=b+12;
  }
 }

// 24th block //
if (bcounter>23)
 {
 b=7;
 for (a=393;a<411;a++)
  {
  by[a]=data_strip(24,b);
  b=b+12;
  }
 }

// 25th block //
if (bcounter>24)
 {
 b=7;
 for (a=411;a<429;a++)
  {
  by[a]=data_strip(25,b);
  b=b+12;
  }
 }

// 26th block //
if (bcounter>25)
 {
 b=7;
 for (a=429;a<447;a++)
  {
  by[a]=data_strip(26,b);
  b=b+12;
  }
 }

// 27th block //
if (bcounter>26)
 {
 b=7;
 for (a=447;a<465;a++)
  {
  by[a]=data_strip(27,b);
  b=b+12;
  }
 }

// 28th block //
if (bcounter>27)
 {
 b=7;
 for (a=465;a<483;a++)
  {
  by[a]=data_strip(28,b);
  b=b+12;
  }
 }

// 29th block //
if (bcounter>28)
 {
 b=7;
 for (a=483;a<501;a++)
  {
  by[a]=data_strip(29,b);
  b=b+12;
  }
 }

// 30th block //
if (bcounter>29)
 {
 b=7;
 for (a=501;a<519;a++)
  {
  by[a]=data_strip(30,b);
  b=b+12;
  }
 }

// 31st block //
if (bcounter>30)
 {
 b=7;
 for (a=519;a<537;a++)
  {
  by[a]=data_strip(31,b);
  b=b+12;
  }
 }

// 32nd block //
if (bcounter>31)
 {
 b=7;
 for (a=537;a<555;a++)
  {
  by[a]=data_strip(32,b);
  b=b+12;
  }
 }

// 33rd block //
if (bcounter>32)
 {
 b=7;
 for (a=555;a<573;a++)
  {
  by[a]=data_strip(33,b);
  b=b+12;
  }
 }

// 34th block //
if (bcounter>33)
 {
 b=7;
 for (a=573;a<591;a++)
  {
  by[a]=data_strip(34,b);
  b=b+12;
  }
 }

// 35th block //
if (bcounter>34)
 {
 b=7;
 for (a=591;a<609;a++)
  {
  by[a]=data_strip(35,b);
  b=b+12;
  }
 }

// 36th block //
if (bcounter>35)
 {
 b=7;
 for (a=609;a<627;a++)
  {
  by[a]=data_strip(36,b);
  b=b+12;
  }
 }

// 37th block //
if (bcounter>36)
 {
 b=7;
 for (a=627;a<645;a++)
  {
  by[a]=data_strip(37,b);
  b=b+12;
  }
 }

// 38th block //
if (bcounter>37)
 {
 b=7;
 for (a=645;a<663;a++)
  {
  by[a]=data_strip(38,b);
  b=b+12;
  }
 }

// 39th block //
if (bcounter>38)
 {
 b=7;
 for (a=663;a<681;a++)
  {
  by[a]=data_strip(39,b);
  b=b+12;
  }
 }

// 40th block //
if (bcounter>39)
 {
 b=7;
 for (a=681;a<699;a++)
  {
  by[a]=data_strip(40,b);
  b=b+12;
  }
 }

// 41st block //
if (bcounter>40)
 {
 b=7;
 for (a=699;a<717;a++)
  {
  by[a]=data_strip(41,b);
  b=b+12;
  }
 }

// 42nd block //
if (bcounter>41)
 {
 b=7;
 for (a=717;a<735;a++)
  {
  by[a]=data_strip(42,b);
  b=b+12;
  }
 }

// 43rd block //
if (bcounter>42)
 {
 b=7;
 for (a=735;a<753;a++)
  {
  by[a]=data_strip(43,b);
  b=b+12;
  }
 }

// 44th block //
if (bcounter>43)
 {
 b=7;
 for (a=753;a<771;a++)
  {
  by[a]=data_strip(44,b);
  b=b+12;
  }
 }

// 45th block //
if (bcounter>44)
 {
 b=7;
 for (a=771;a<789;a++)
  {
  by[a]=data_strip(45,b);
  b=b+12;
  }
 }

// 46th block //
if (bcounter>45)
 {
 b=7;
 for (a=789;a<807;a++)
  {
  by[a]=data_strip(46,b);
  b=b+12;
  }
 }

// 47th block //
if (bcounter>46)
 {
 b=7;
 for (a=807;a<825;a++)
  {
  by[a]=data_strip(47,b);
  b=b+12;
  }
 }

// 48th block //
if (bcounter>47)
 {
 b=7;
 for (a=825;a<843;a++)
  {
  by[a]=data_strip(48,b);
  b=b+12;
  }
 }

// 49th block //
if (bcounter>48)
 {
 b=7;
 for (a=843;a<861;a++)
  {
  by[a]=data_strip(49,b);
  b=b+12;
  }
 }

// 50th block //
if (bcounter>49)
 {
 b=7;
 for (a=861;a<879;a++)
  {
  by[a]=data_strip(50,b);
  b=b+12;
  }
 }

}

unsigned char moby::data_strip (int x,int y)
{
unsigned char a=0;
if (blk[x][y]==1) a=1;
y--;
if (blk[x][y]==1) a=a+2; 
y--;
if (blk[x][y]==1) a=a+4;
y--;
if (blk[x][y]==1) a=a+8;  
y--;
if (blk[x][y]==1) a=a+16;
y--;
if (blk[x][y]==1) a=a+32;
y--; 
if (blk[x][y]==1) a=a+64;
y--;
if (blk[x][y]==1) a=a+128;
return a;
}

// Gets a block from the RS232 //
BOOL moby::getblock (int c)
{
b0=getchar();
b1=getchar();
//if (b0==101 && b1==114 && c==1) return (FALSE); 
b2=getchar();
//if (b1==101 && b2==114 && c==1) return (FALSE);
b3=getchar(); 
//if (b2==101 && b3==114 && c==1) return (FALSE);
b4=getchar();
//if (b3==101 && b4==114 && c==1) return (FALSE);
b5=getchar(); 
b6=getchar(); 
b7=getchar(); 
b8=getchar(); 
b9=getchar(); 
b10=getchar();
b11=getchar();
b12=getchar();  
b13=getchar();  
b14=getchar();  
b15=getchar();  
b16=getchar();  
b17=getchar();  
b18=getchar();  
b19=getchar();  
b20=getchar();
b21=getchar();
b22=getchar();  
b23=getchar();  
b24=getchar();  
b25=getchar();  
b26=getchar();  
b27=getchar();  
b28=getchar();  
b29=getchar(); 

if (b28==101 && b29==114 && c==0) return (FALSE);
 else return (TRUE); 
}

// Check if an identity is in the names.usr file //
BOOL moby::get_identity (unsigned long int actual)
{
CFile reader;
unsigned long int rx;
char a=0,tmp[3],buf[100],value[6];
BOOL found=FALSE;


if (!reader.Open("names.usr",CFile::modeRead|CFile::shareExclusive,NULL))
 {
 AfxMessageBox("Error can't find NAMES.USR",MB_OK|MB_ICONEXCLAMATION,0);
 goto lend;
 }

lagain:
for (a=0;a<80;a++)
 {
 reader.Read(tmp,1);
 buf[a]=tmp[0];
 if (tmp[0]==10) break;
 if (tmp[0]==42) goto lend;
 }

// Get the hex value //
value[0]=buf[0];
value[1]=buf[1];
value[2]=buf[2];
value[3]=buf[3];
value[4]=buf[4];
value[5]=buf[5];

// Last digit //
rx=0;
if (value[5]==49) rx=1;
if (value[5]==50) rx=2;
if (value[5]==51) rx=3;
if (value[5]==52) rx=4;
if (value[5]==53) rx=5; 
if (value[5]==54) rx=6;
if (value[5]==55) rx=7;
if (value[5]==56) rx=8;
if (value[5]==57) rx=9;
if (value[5]==65 || value[5]==97) rx=10; 
if (value[5]==66 || value[5]==98) rx=11;
if (value[5]==67 || value[5]==99) rx=12;
if (value[5]==68 || value[5]==100) rx=13;
if (value[5]==69 || value[5]==101) rx=14;
if (value[5]==70 || value[5]==102) rx=15;

// 5th digit //
if (value[4]==49) rx=rx+16;
if (value[4]==50) rx=rx+(2*16);
if (value[4]==51) rx=rx+(3*16);
if (value[4]==52) rx=rx+(4*16);
if (value[4]==53) rx=rx+(5*16);
if (value[4]==54) rx=rx+(6*16);
if (value[4]==55) rx=rx+(7*16);
if (value[4]==56) rx=rx+(8*16);
if (value[4]==57) rx=rx+(9*16);
if (value[4]==65 || value[4]==97) rx=rx+(10*16);
if (value[4]==66 || value[4]==98) rx=rx+(11*16);
if (value[4]==67 || value[4]==99) rx=rx+(12*16);
if (value[4]==68 || value[4]==100) rx=rx+(13*16);
if (value[4]==69 || value[4]==101) rx=rx+(14*16);
if (value[4]==70 || value[4]==102) rx=rx+(15*16);

// 4th digit //
if (value[3]==49) rx=rx+256;
if (value[3]==50) rx=rx+(2*256);
if (value[3]==51) rx=rx+(3*256);
if (value[3]==52) rx=rx+(4*256);
if (value[3]==53) rx=rx+(5*256);
if (value[3]==54) rx=rx+(6*256);
if (value[3]==55) rx=rx+(7*256);
if (value[3]==56) rx=rx+(8*256); 
if (value[3]==57) rx=rx+(9*256);
if (value[3]==65 || value[3]==97) rx=rx+(10*256);
if (value[3]==66 || value[3]==98) rx=rx+(11*256);
if (value[3]==67 || value[3]==99) rx=rx+(12*256);
if (value[3]==68 || value[3]==100) rx=rx+(13*256);
if (value[3]==69 || value[3]==101) rx=rx+(14*256);
if (value[3]==70 || value[3]==102) rx=rx+(15*256);

// 3rd digit //
if (value[2]==49) rx=rx+4096;
if (value[2]==50) rx=rx+(2*4096);
if (value[2]==51) rx=rx+(3*4096);
if (value[2]==52) rx=rx+(4*4096);
if (value[2]==53) rx=rx+(5*4096);
if (value[2]==54) rx=rx+(6*4096);
if (value[2]==55) rx=rx+(7*4096);
if (value[2]==56) rx=rx+(8*4096);
if (value[2]==57) rx=rx+(9*4096);
if (value[2]==65 || value[2]==97) rx=rx+(10*4096);
if (value[2]==66 || value[2]==98) rx=rx+(11*4096);
if (value[2]==67 || value[2]==99) rx=rx+(12*4096);
if (value[2]==68 || value[2]==100) rx=rx+(13*4096);
if (value[2]==69 || value[2]==101) rx=rx+(14*4096);
if (value[2]==70 || value[2]==102) rx=rx+(15*4096);

// 2nd digit //
if (value[1]==49) rx=rx+65536;
if (value[1]==50) rx=rx+(2*65536);
if (value[1]==51) rx=rx+(3*65536);
if (value[1]==52) rx=rx+(4*65536);
if (value[1]==53) rx=rx+(5*65536);
if (value[1]==54) rx=rx+(6*65536);
if (value[1]==55) rx=rx+(7*65536);
if (value[1]==56) rx=rx+(8*65536);
if (value[1]==57) rx=rx+(9*65536);
if (value[1]==65 || value[1]==97) rx=rx+(10*65536);
if (value[1]==66 || value[1]==98) rx=rx+(11*65536);
if (value[1]==67 || value[1]==99) rx=rx+(12*65536);
if (value[1]==68 || value[1]==100) rx=rx+(13*65536);
if (value[1]==69 || value[1]==101) rx=rx+(14*65536);
if (value[1]==70 || value[1]==102) rx=rx+(15*65536);

// 1st digit //
if (value[0]==49) rx=rx+1048576;
if (value[0]==50) rx=rx+(2*1048576);
if (value[0]==51) rx=rx+(3*1048576);
if (value[0]==52) rx=rx+(4*1048576);
if (value[0]==53) rx=rx+(5*1048576);
if (value[0]==54) rx=rx+(6*1048576);
if (value[0]==55) rx=rx+(7*1048576);
if (value[0]==56) rx=rx+(8*1048576);
if (value[0]==57) rx=rx+(9*1048576);
if (value[0]==65 || value[0]==97) rx=rx+(10*1048576);
if (value[0]==66 || value[0]==98) rx=rx+(11*1048576);
if (value[0]==67 || value[0]==99) rx=rx+(12*1048576);
if (value[0]==68 || value[0]==100) rx=rx+(13*1048576);
if (value[0]==69 || value[0]==101) rx=rx+(14*1048576);
if (value[0]==70 || value[0]==102) rx=rx+(15*1048576);

// Do we have a match //
if (actual==rx) 
 {
 // Yes we have a match //
 found=TRUE;
 // Load the user name //
 for (a=0;a<80;a++)
  {
  user_name[a]=buf[a+7];
  if (user_name[a]==10) break;
  }
 // Clear the newline character //
 user_name[a-1]=0;
 user_name[a]=0;
 }
 else goto lagain;

lend:
reader.Close();
return found;
}

// Display all Protocols as ASCII //
void moby::ascii_protocols (char line0[300],char tt)
{
int a;
char tmp[6],line2[300],line3[300];
char line4[300],line5[300],line6[300],line7[300],line8[300],line9[300];

for (a=0;a<299;a++)
 {
 line2[a]=0;
 line3[a]=0;
 line4[a]=0;
 line5[a]=0;
 line6[a]=0;
 line7[a]=0;
 line8[a]=0;
 line9[a]=0;
 } 

if (tt==0) line2[0]=32;
 else 
 {
 if (by[0]>31) line2[0]=by[0];
  else 
  {
  if (by[a]==0) strcpy(tmp,"<NUL>");
  if (by[a]==1) strcpy(tmp,"<SOH>");
  if (by[a]==2) strcpy(tmp,"<STX>");
  if (by[a]==3) strcpy(tmp,"<ETX>");
  if (by[a]==4) strcpy(tmp,"<EOT>");
  if (by[a]==5) strcpy(tmp,"<ENQ>");
  if (by[a]==6) strcpy(tmp,"<ACK>");
  if (by[a]==7) strcpy(tmp,"<BEL>");
  if (by[a]==8) strcpy(tmp,"<BS>");
  if (by[a]==9) strcpy(tmp,"<HT>");
  if (by[a]==10) strcpy(tmp,"<LF>");
  if (by[a]==11) strcpy(tmp,"<VT>");
  if (by[a]==12) strcpy(tmp,"<FF>");
  if (by[a]==13) strcpy(tmp,"<CR>");
  if (by[a]==14) strcpy(tmp,"<SO>");
  if (by[a]==15) strcpy(tmp,"<SI>");
  if (by[a]==16) strcpy(tmp,"<DLE>");
  if (by[a]==17) strcpy(tmp,"<DC1>");
  if (by[a]==18) strcpy(tmp,"<DC2>");
  if (by[a]==19) strcpy(tmp,"<DC3>");
  if (by[a]==20) strcpy(tmp,"<DC4>");
  if (by[a]==21) strcpy(tmp,"<NAK>");
  if (by[a]==22) strcpy(tmp,"<SYN>");
  if (by[a]==23) strcpy(tmp,"<ETB>");
  if (by[a]==24) strcpy(tmp,"<CAN>");
  if (by[a]==25) strcpy(tmp,"<EM>");
  if (by[a]==26) strcpy(tmp,"<SUB>");
  if (by[a]==27) strcpy(tmp,"<ESC>");
  if (by[a]==28) strcpy(tmp,"<FS>");
  if (by[a]==29) strcpy(tmp,"<GS>");
  if (by[a]==30) strcpy(tmp,"<RS>");
  if (by[a]==31) strcpy(tmp,"<US>");
  strcpy(line2,tmp);
  }
 }

// 2nd block //
if (bcounter>1)
 {
 for (a=1;a<19;a++)
  {
  if (bcounter==2 && a==octet+1) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line2,tmp);
  }
 }

// 3rd block //
if (bcounter>2)
 {
 for (a=19;a<37;a++)
  {
  if (bcounter==3 && a==octet+19) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line2,tmp);
  }
 }

// 4th block //
if (bcounter>3)
 {
 for (a=37;a<55;a++)
  {
  if (bcounter==4 && a==octet+37) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line2,tmp);
  }
 }

// 5th Block //
if (bcounter>4)
 {
 for (a=55;a<73;a++)
  {
  if (bcounter==5 && a==octet+55) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line2,tmp);
  }
 }

// 6th block //
if (bcounter>5)
 {
 for (a=73;a<91;a++)
  {
  if (bcounter==6 && a==octet+73) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line3,tmp);
  }
 }

// 7th block //
if (bcounter>6)
 {
 for (a=91;a<109;a++)
  {
  if (bcounter==7 && a==octet+91) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line3,tmp);
  }
 }

// 8th block //
if (bcounter>7)
 {
 for (a=109;a<127;a++)
  {
  if (bcounter==8 && a==octet+109) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line3,tmp);
  }
 }

// 9th block //
if (bcounter>8)
 {
 for (a=127;a<145;a++)
  {
  if (bcounter==9 && a==octet+127) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line3,tmp);
  }
 }

// 10th block //
if (bcounter>9)
 {
 for (a=145;a<163;a++)
  {
  if (bcounter==10 && a==octet+145) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line4,tmp);
  }
 }

// 11th block //
if (bcounter>10)
 {
 for (a=163;a<181;a++)
  {
  if (bcounter==11 && a==octet+163) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line4,tmp);
  }
 }

// 12th block //
if (bcounter>11)
 {
 for (a=181;a<199;a++)
  {
  if (bcounter==12 && a==octet+181) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line4,tmp);
  }
 }

// 13th block //
if (bcounter>12)
 {
 for (a=199;a<217;a++)
  {
  if (bcounter==13 && a==octet+199) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line4,tmp);
  }
 }

// 14th block //
if (bcounter>13)
 {
 for (a=217;a<235;a++)
  {
  if (bcounter==14 && a==octet+217) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line5,tmp);
  }
 }

// 15th block //
if (bcounter>14)
 {
 for (a=235;a<253;a++)
  {
  if (bcounter==15 && a==octet+235) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line5,tmp);
  }
 }

// 16th block //
if (bcounter>15)
 {
 for (a=253;a<271;a++)
  {
  if (bcounter==16 && a==octet+253) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line5,tmp);
  }
 }

// 17th block //
if (bcounter>16)
 {
 for (a=271;a<289;a++)
  {
  if (bcounter==17 && a==octet+271) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line5,tmp);
  }
 }

// 18th block //
if (bcounter>17)
 {
 for (a=289;a<307;a++)
  {
  if (bcounter==18 && a==octet+289) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line6,tmp);
  }
 }

// 19th block //
if (bcounter>18)
 {
 for (a=307;a<325;a++)
  {
  if (bcounter==19 && a==octet+307) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line6,tmp);
  }
 }

// 20th block //
if (bcounter>19)
 {
 for (a=325;a<343;a++)
  {
  if (bcounter==20 && a==octet+325) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line6,tmp);
  }
 }

 // 21st block //
if (bcounter>20)
 {
 for (a=343;a<361;a++)
  {
  if (bcounter==21 && a==octet+343) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line6,tmp);
  }
 }

// 22nd block //
if (bcounter>21)
 {
 for (a=361;a<379;a++)
  {
  if (bcounter==22 && a==octet+361) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line7,tmp);
  }
 }

// 23rd block //
if (bcounter>22)
 {
 for (a=379;a<397;a++)
  {
  if (bcounter==23 && a==octet+379) break;
  if (by[a]>25) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   }
  strcat(line7,tmp);
  }
 }

// 24th block //
if (bcounter>23)
 {
 for (a=397;a<415;a++)
  {
  if (bcounter==24 && a==octet+397) break;
  if (by[a]>25) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   }
  strcat(line7,tmp);
  }
 }

// 25th block //
if (bcounter>24)
 {
 for (a=415;a<433;a++)
  {
  if (bcounter==25 && a==octet+415) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line7,tmp);
  }
 }

// 26th block //
if (bcounter>25)
 {
 for (a=433;a<451;a++)
  {
  if (bcounter==26 && a==octet+433) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line8,tmp);
  }
 }

// 27th block //
if (bcounter>26)
 {
 for (a=451;a<469;a++)
  {
  if (bcounter==27 && a==octet+451) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line8,tmp);
  }
 }

// 28th block //
if (bcounter>27)
 {
 for (a=469;a<487;a++)
  {
  if (bcounter==28 && a==octet+469) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line8,tmp);
  }
 }

// 29th block //
if (bcounter>28)
 {
 for (a=487;a<505;a++)
  {
  if (bcounter==29 && a==octet+487) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line8,tmp);
  }
 }

  // 30th block //
if (bcounter>29)
 {
 for (a=505;a<523;a++)
  {
  if (bcounter==29 && a==octet+505) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
   else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat(line9,tmp);
  }
 }


// Display the ascii protocol msg on screen //
if (bcounter>29)
 {
 strcpy(s,line9);
 rotate();
 }
 
if (bcounter>25)
 {
 strcpy(s,line8);
 rotate();
 }
 
if (bcounter>21)
 {
 strcpy(s,line7);
 rotate();
 }
 
if (bcounter>17)
 {
 strcpy(s,line6);
 rotate();
 }

if (bcounter>13)
 {
 strcpy(s,line5);
 rotate();
 }
 
if (bcounter>9)
 {
 strcpy(s,line4);
 rotate();
 }
 
if (bcounter>5)
 {
 strcpy(s,line3);
 rotate();
 } 

// Line 2 is always present //
strcpy(s,line2);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);

 if (bcounter>5)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }

 if (bcounter>9)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }

 if (bcounter>13)
  {
  logout.Write(line5,strlen(line5));
  logout.Write(enc,1);
  }

 if (bcounter>17)
  {
  logout.Write(line6,strlen(line6));
  logout.Write(enc,1);
  }

 if (bcounter>21)
  {
  logout.Write(line7,strlen(line7));
  logout.Write(enc,1);
  }

 if (bcounter>25)
  {
  logout.Write(line8,strlen(line8));
  logout.Write(enc,1);
  }

 if (bcounter>29)
  {
  logout.Write(line9,strlen(line9));
  logout.Write(enc,1);
  }

 }
 
}

// Display ascii from an mpak with an address list //
void moby::ascii_protocols_list (char line0[300],char tt,char num,unsigned long int add1, unsigned long int add2, unsigned long int add3, unsigned long int add4, unsigned long int add5, unsigned long int add6, unsigned long int add7)
{

}

// Decode & Display HPDATA messaging protocol //
void moby::decode_messaging (char line0[200])
{
int a;
char tmp[200],line1[200],line2[200],line3[200];
char line4[200],line5[200],line6[200],line7[200],line8[200],line9[200];

a=0;
if (by[1]&64) a=a+2;
if (by[1]&32) a++;
if (a==0) sprintf(line1,"Paging Msg ID#%x",by[4]);
if (a==3) sprintf(line1,"Command Msg ID#%x",by[4]);
  
a=0;
if (by[1]&8) a=2;
if (by[1]&4) a++;
if (a==2) 
 {	
 strcpy(tmp," (Manual Response Requested)");
 strcat(line1,tmp);
 }
if (a==1) 
 {	
 strcpy(tmp," (Auto Response Requested)");
 strcat(line1,tmp);
 }
  
// 2nd block always present //
sprintf(line2,"%c",by[10]);
for (a=11;a<19;a++)
 {
 if (bcounter==2 && a==octet+1) break;
 if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
 strcat(line2,tmp);
 }
 
// 3rd block //
if (bcounter>2)
 {
 for (a=19;a<37;a++)
  {
  if (bcounter==3 && a==octet+19) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line2,tmp);
  }
 }

// 4th block //
if (bcounter>3)
 {
 for (a=37;a<55;a++)
  {
  if (bcounter==4 && a==octet+37) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }   
  strcat (line2,tmp);
  }
 }

// 5th Block //
if (bcounter>4)
 {
 for (a=55;a<73;a++)
  {
  if (bcounter==5 && a==octet+55) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line2,tmp);
  }
 }

// 6th block //
if (bcounter>5)
 {
 sprintf(line3,"%c",by[73]);
 for (a=74;a<91;a++)
  {
  if (bcounter==6 && a==octet+73) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line3,tmp);
  }
 }

// 7th block //
if (bcounter>6)
 {
 for (a=91;a<109;a++)
  {
  if (bcounter==7 && a==octet+91) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }   
  strcat (line3,tmp);
  }
 }

// 8th block //
if (bcounter>7)
 {
 for (a=109;a<127;a++)
  {
  if (bcounter==8 && a==octet+109) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line3,tmp);
  }
 }

// 9th block //
if (bcounter>8)
 {
 for (a=127;a<145;a++)
  {
  if (bcounter==9 && a==octet+127) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line3,tmp);
  }
 }

// 10th block //
if (bcounter>9)
 {
 sprintf(line4,"%c",by[145]);
 for (a=146;a<163;a++)
  {
  if (bcounter==10 && a==octet+145) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   } 
  strcat (line4,tmp);
  }
 }

// 11th block //
if (bcounter>10)
 {
 for (a=163;a<181;a++)
  {
  if (bcounter==11 && a==octet+163) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line4,tmp);
  }
 }

// 12th block //
if (bcounter>11)
 {
 for (a=181;a<199;a++)
  {
  if (bcounter==12 && a==octet+181) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }   
  strcat (line4,tmp);
  }
 }

// 13th block //
if (bcounter>12)
 {
 for (a=199;a<217;a++)
  {
  if (bcounter==13 && a==octet+199) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line4,tmp);
  }
 }

// 14th block //
if (bcounter>13)
 {
 sprintf(line5,"%c",by[217]);
 for (a=218;a<235;a++)
  {
  if (bcounter==14 && a==octet+217) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line5,tmp);
  }
 }

// 15th block //
if (bcounter>14)
 {
 for (a=235;a<253;a++)
  {
  if (bcounter==15 && a==octet+235) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line5,tmp);
  }
 }

// 16th block //
if (bcounter>15)
 {
 for (a=253;a<271;a++)
  {
  if (bcounter==16 && a==octet+253) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line5,tmp);
  }
 }

// 17th block //
if (bcounter>16)
 {
 for (a=271;a<289;a++)
  {
  if (bcounter==17 && a==octet+271) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line5,tmp);
  }
 }

// 18th block //
if (bcounter>17)
 {
 sprintf(line6,"%c",by[289]);
 for (a=290;a<307;a++)
  {
  if (bcounter==18 && a==octet+289) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }   
  strcat (line6,tmp);
  }
 }

// 19th block //
if (bcounter>18)
 {
 for (a=307;a<325;a++)
  {
  if (bcounter==19 && a==octet+307) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line6,tmp);
  }
 }

// 20th block //
if (bcounter>19)
 {
 for (a=325;a<343;a++)
  {
  if (bcounter==20 && a==octet+325) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line6,tmp);
  }
 }

// 21st block //
if (bcounter>20)
 {
 for (a=343;a<361;a++)
  {
  if (bcounter==21 && a==octet+343) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line6,tmp);
  }
 }

// 22nd block //
if (bcounter>21)
 {
 sprintf(line7,"%c",by[361]);
 for (a=362;a<379;a++)
  {
  if (bcounter==22 && a==octet+361) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line7,tmp);
  }
 }

// 23rd block //
if (bcounter>22)
 {
 for (a=379;a<397;a++)
  {
  if (bcounter==23 && a==octet+379) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   } 
  strcat (line7,tmp);
  }
 }

// 24th block //
if (bcounter>23)
 {
 for (a=397;a<415;a++)
  {
  if (bcounter==24 && a==octet+397) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   } 
  strcat (line7,tmp);
  }
 }

// 25th block //
if (bcounter>24)
 {
 for (a=415;a<433;a++)
  {
  if (bcounter==25 && a==octet+415) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line7,tmp);
  }
 }

// 26th block //
if (bcounter>25)
 {
 sprintf(line8,"%c",by[433]);
 for (a=434;a<451;a++)
  {
  if (bcounter==26 && a==octet+433) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line8,tmp);
  }
 }

// 27th block //
if (bcounter>26)
 {
 for (a=451;a<469;a++)
  {
  if (bcounter==27 && a==octet+451) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }  
  strcat (line8,tmp);
  }
 }

// 28th block //
if (bcounter>27)
 {
 for (a=469;a<487;a++)
  {
  if (bcounter==28 && a==octet+469) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   }
  strcat (line8,tmp);
  }
 }

// 29th block //
if (bcounter>28)
 {
 for (a=487;a<505;a++)
  {
  if (bcounter==29 && a==octet+487) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   } 
  strcat (line8,tmp);
  }
 }

// 30th block //
if (bcounter>29)
 {
 sprintf(line9,"%c",by[505]);
 for (a=506;a<523;a++)
  {
  if (bcounter==30 && a==octet+505) break;
  if (by[a]>31) sprintf(tmp,"%c",by[a]);
  else
   {
   if (by[a]==0) strcpy(tmp,"<NUL>");
   if (by[a]==1) strcpy(tmp,"<SOH>");
   if (by[a]==2) strcpy(tmp,"<STX>");
   if (by[a]==3) strcpy(tmp,"<ETX>");
   if (by[a]==4) strcpy(tmp,"<EOT>");
   if (by[a]==5) strcpy(tmp,"<ENQ>");
   if (by[a]==6) strcpy(tmp,"<ACK>");
   if (by[a]==7) strcpy(tmp,"<BEL>");
   if (by[a]==8) strcpy(tmp,"<BS>");
   if (by[a]==9) strcpy(tmp,"<HT>");
   if (by[a]==10) strcpy(tmp,"<LF>");
   if (by[a]==11) strcpy(tmp,"<VT>");
   if (by[a]==12) strcpy(tmp,"<FF>");
   if (by[a]==13) strcpy(tmp,"<CR>");
   if (by[a]==14) strcpy(tmp,"<SO>");
   if (by[a]==15) strcpy(tmp,"<SI>");
   if (by[a]==16) strcpy(tmp,"<DLE>");
   if (by[a]==17) strcpy(tmp,"<DC1>");
   if (by[a]==18) strcpy(tmp,"<DC2>");
   if (by[a]==19) strcpy(tmp,"<DC3>");
   if (by[a]==20) strcpy(tmp,"<DC4>");
   if (by[a]==21) strcpy(tmp,"<NAK>");
   if (by[a]==22) strcpy(tmp,"<SYN>");
   if (by[a]==23) strcpy(tmp,"<ETB>");
   if (by[a]==24) strcpy(tmp,"<CAN>");
   if (by[a]==25) strcpy(tmp,"<EM>");
   if (by[a]==26) strcpy(tmp,"<SUB>");
   if (by[a]==27) strcpy(tmp,"<ESC>");
   if (by[a]==28) strcpy(tmp,"<FS>");
   if (by[a]==29) strcpy(tmp,"<GS>");
   if (by[a]==30) strcpy(tmp,"<RS>");
   if (by[a]==31) strcpy(tmp,"<US>");
   } 
  strcat (line9,tmp);
  }
 }

// Display the messaging protocol msg on screen //
if (bcounter>29)
 {
 strcpy(s,line9);
 rotate();
 }
 
if (bcounter>25)
 {
 strcpy(s,line8);
 rotate();
 }
 
if (bcounter>21)
 {
 strcpy(s,line7);
 rotate();
 }
 
if (bcounter>17)
 {
 strcpy(s,line6);
 rotate();
 }

if (bcounter>13)
 {
 strcpy(s,line5);
 rotate();
 }
 
if (bcounter>9)
 {
 strcpy(s,line4);
 rotate();
 }
 
if (bcounter>5)
 {
 strcpy(s,line3);
 rotate();
 } 

// Line 2 is always present //
strcpy(s,line2);
rotate();

// Same with Line 1 //
strcpy(s,line1);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);

 if (bcounter>5)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }

 if (bcounter>9)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }

 if (bcounter>13)
  {
  logout.Write(line5,strlen(line5));
  logout.Write(enc,1);
  }

 if (bcounter>17)
  {
  logout.Write(line6,strlen(line6));
  logout.Write(enc,1);
  }

 if (bcounter>21)
  {
  logout.Write(line7,strlen(line7));
  logout.Write(enc,1);
  }

 if (bcounter>25)
  {
  logout.Write(line8,strlen(line8));
  logout.Write(enc,1);
  }

 if (bcounter>29)
  {
  logout.Write(line9,strlen(line9));
  logout.Write(enc,1);
  }

 }

}

// Decode & Display HPDATA protocol 135 //
void moby::decode_protocol135 (char line0[200])
{
char tmp[200],line1[200];

strcpy(line1,"Position ");

if (bcounter==5 || bcounter==7)
 {
 sprintf(tmp,"%c",by[16]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[17]);
 strcat(line1,tmp);
 sprintf(tmp,".");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[18]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[19]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[21]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[22]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[23]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[25]);
 strcat(line1,tmp);
 sprintf(tmp," ");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[27]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[28]);
 strcat(line1,tmp);
 sprintf(tmp,".");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[29]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[30]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[31]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[33]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[34]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[35]);
 strcat(line1,tmp);
 }

if (bcounter==8)
 {
 sprintf(tmp,"%c",by[16]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[17]);
 strcat(line1,tmp);
 sprintf(tmp,".");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[18]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[19]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[21]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[22]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[23]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[24]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[26]);
 strcat(line1,tmp);

 sprintf(tmp," ");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[28]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[29]);
 strcat(line1,tmp);
 sprintf(tmp,".");
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[30]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[31]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[32]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[34]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[35]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[36]);
 strcat(line1,tmp);
 sprintf(tmp,"%c",by[37]);
 strcat(line1,tmp);

 sprintf(tmp,"%c",by[39]);
 strcat(line1,tmp);
 }

// Display //
strcpy(s,line1);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 }


}

// Decode & Display NMEA RMC GPS data //
void moby::decode_nmea_rmc (char line0[200])
{
char tmp[200],line1[200],line2[200],time[15],lat[30],lon[30],speed[15];
int c=1;

// Find first "," //
rmcomma:
if (by[c]==44) goto rmcommab;
c++;
goto rmcomma;
rmcommab:
c++;

// Get time //
sprintf(time,"%c",by[c]);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
strcpy(tmp,":");
strcat(time,tmp);
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
strcpy(tmp,":");
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);

c=c+4;
// Get latitude //
strcpy(lat,"");
rmclata:
if (by[c]==44) goto rmclatb;
sprintf(tmp,"%c",by[c]);
strcat(lat,tmp);
c++;
goto rmclata;

rmclatb:
c++;
sprintf(tmp,"%c",by[c]);
strcat(lat,tmp);

c=c+3;
// Get longditude //
strcpy(lon,"");
rmclona:
if (by[c]==44) goto rmclonb;
sprintf(tmp,"%c",by[c]);
strcat(lon,tmp);
c++;
goto rmclona;

rmclonb:
c++;
sprintf(tmp,"%c",by[c]);
strcat(lon,tmp);

c=c+2;
// Get speed //
strcpy(speed,"");
rmcspeeda:
if (by[c]==44) goto rmcspeedb;
sprintf(tmp,"%c",by[c]);
strcat(speed,tmp);
c++;
goto rmcspeeda;
rmcspeedb:

// Setup the display //
strcpy(line1,"GPS fix at ");
strcat(line1,time);
strcpy(tmp," (NMEA RMC)");
strcat(line1,tmp);
strcpy(line2,lat);
strcpy(tmp," ");
strcat(line2,tmp);
strcat(line2,lon);
strcpy(tmp," Speed ");
strcat(line2,tmp);
strcat(line2,speed);
strcpy(tmp," Knots");
strcat(line2,tmp);

// Display //
strcpy(s,line2);
rotate();

strcpy(s,line1);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);
 }

}

// Decode & Display NMEA GGA GPS data //
void moby::decode_nmea_gga (char line0[200])
{
char tmp[200],line1[200],line2[200],time[15],lat[30],lon[30],alt[15],sats,type;
int c=1;

// Find first "," //
ggacomma:
if (by[c]==44) goto ggacommab;
c++;
goto ggacomma;
ggacommab:
c++;

// Get time //
sprintf(time,"%c",by[c]);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
strcpy(tmp,":");
strcat(time,tmp);
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
strcpy(tmp,":");
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);
c++;
sprintf(tmp,"%c",by[c]);
strcat(time,tmp);

c=c+2;
// Get latitude //
strcpy(lat,"");
ggalata:
if (by[c]==44) goto ggalatb;
sprintf(tmp,"%c",by[c]);
strcat(lat,tmp);
c++;
goto ggalata;

ggalatb:
c++;
sprintf(tmp,"%c",by[c]);
strcat(lat,tmp);

c=c+3;
// Get longditude //
strcpy(lon,"");
ggalona:
if (by[c]==44) goto ggalonb;
sprintf(tmp,"%c",by[c]);
strcat(lon,tmp);
c++;
goto ggalona;

ggalonb:
c++;
sprintf(tmp,"%c",by[c]);
strcat(lon,tmp);

// Type of fix //
c=c+2;
type=by[c];

// No of Sats in fix //
c=c+2;
sats=by[c];

// Find next "," //
ggalta:
if (by[c]==44) goto ggaltb;
c++;
goto ggalta;
ggaltb:

// And again //
zggalta:
if (by[c]==44) goto zggaltb;
c++;
goto zggalta;
zggaltb:

// Get altitude //
c++;
strcpy(alt,"");
ggasea:
if (by[c]==44) goto ggaseb;
sprintf(tmp,"%c",by[c]);
strcat(alt,tmp);
c++;
goto ggasea;

ggaseb:

// Setup the display //
if (type==0x30) strcpy(line1,"Invalid fix at ");
if (type==0x31) strcpy(line1,"GPS fix at ");
if (type==0x32) strcpy(line1,"DGPS fix at ");

strcat(line1,time);
sprintf(tmp," (%c",sats);
strcat(line1,tmp);
strcpy(tmp," Satellites tracked)");
strcat(line1,tmp);
strcpy(tmp," (NMEA GGA)");
strcat(line1,tmp);
strcpy(line2,lat);
strcpy(tmp," ");
strcat(line2,tmp);
strcat(line2,lon);
strcpy(tmp," ");
strcat(line2,tmp);
strcat(line2,alt);
strcpy(tmp,"M above mean sea level");
strcat(line2,tmp);

// Display //
strcpy(s,line2);
rotate();

strcpy(s,line1);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);
 logout.Write(line2,strlen(line2));
 logout.Write(enc,1);
 }

}

// Decode & Display MTP/1 packets //
void moby::decode_mtp1 (char line0[200])
{
char tmp[200],line1[200],line2[200],line3[200],line4[200],line5[200];
char line6[200],line7[200],line8[200],line9[200],line10[200],line11[200];
char line12[200],line13[200],line14[200],line15[200],line16[200],line17[200];
unsigned char tpdu;
BOOL l2=FALSE;
BOOL l3=FALSE;
BOOL l4=FALSE;
BOOL l5=FALSE;
BOOL l6=FALSE;
BOOL l7=FALSE;
BOOL l8=FALSE;
BOOL l9=FALSE;
BOOL l10=FALSE;
BOOL l11=FALSE;
BOOL l12=FALSE;
BOOL l13=FALSE;
BOOL l14=FALSE;
BOOL l15=FALSE;
BOOL l16=FALSE;
BOOL l17=FALSE;

// determine the TPDU type //
tpdu=0;
if (by[1]&32) tpdu=tpdu+4;
if (by[1]&16) tpdu=tpdu+2;
if (by[1]&8) tpdu++;

if (tpdu==0) strcpy(line1,"DT (Data)");
if (tpdu==1) strcpy(line1,"AK (Acknowledgement)");
if (tpdu==2) strcpy(line1,"CR (Connection Request)");
if (tpdu==3) strcpy(line1,"CC (Connection Confirm)");
if (tpdu==4) strcpy(line1,"DR (Disconnect Request)");
if (tpdu==5) strcpy(line1,"CCAM (Connection Confirm Addressee Modified)");

strcpy(line2,"");

// QB //
if (tpdu==2 || tpdu==3 || tpdu==5 || tpdu==0)
 {
 if (by[1]&128)
  {
  strcpy(tmp,"QB");
  strcat(line2,tmp);
  l2=TRUE;
  }
 }

// ACK-REQ //
if (tpdu==2 || tpdu==5 || tpdu==0 || tpdu==3)
 {
 if (by[1]&64)
  {
  if (!l2) strcpy(tmp,"ACK-REQ");
   else strcpy(tmp," ACK-REQ");
  strcat(line2,tmp);
  l2=TRUE;
  }
 }

// EOT //
if (tpdu==2 || tpdu==5 || tpdu==0 || tpdu==3)
 {
 if (by[1]&4)
  {
  if (!l2) strcpy(tmp,"EOT");
   else strcpy(tmp," EOT");
  strcat(line2,tmp);
  l2=TRUE;
  }
 }

// CLN //
if (by[1]&2) 
 {
 if (!l2) sprintf(tmp,"Tx TSAP-ID#%x",by[3]);
  else sprintf(tmp," Tx TSAP-ID#%x",by[3]);
 strcat(line2,tmp);
 l2=TRUE;
 }

// CON-ID //
 else if (tpdu==2 || tpdu==3 || tpdu==5)
       {
	   if (!l2) sprintf(tmp,"CON-ID#%x",by[3]);
	    else sprintf(tmp," CON-ID#%x",by[3]);
	   strcat(line2,tmp);
	   l2=TRUE;
       }


// CLD //
if (by[1]&1) 
 {
 if (!l2) sprintf(tmp,"Rx TSAP-ID#%x",by[4]);
  else sprintf(tmp," Rx TSAP-ID#%x",by[4]);
 strcat(line2,tmp);
 l2=TRUE;
 }

// TPDU-NR //
if (tpdu==0)
 {
 if (!l2) sprintf(tmp,"TPDU-NR#%x",by[2]);
  else sprintf(tmp," TPDU-NR#%x",by[2]);
 strcat(line2,tmp);
 l2=TRUE;
 }

// CLS //
if (tpdu==2 || tpdu==5 || tpdu==3)
 {
 if (by[2]&128)
  {
  if (!l2) strcpy(tmp,"CLS");
   else strcpy(tmp," CLS");
  strcat(line2,tmp);
  l2=TRUE;
  }
 }

// VER //
if (tpdu==2 || tpdu==5 || tpdu==4 || tpdu==3)
 {
 unsigned char ver=0;

 if (by[2]&64) ver=ver+4;
 if (by[2]&32) ver=ver+2;
 if (by[2]&16) ver++;

 if (!l2) sprintf(tmp,"VER#%x",ver);
  else sprintf(tmp," VER#%x",ver);
 strcat(line2,tmp);
 l2=TRUE;
 }

// ACK-NR //
if (tpdu==1 || tpdu==0)
 {
 unsigned char nr=0;

 if (by[3]&64) nr=nr+4;
 if (by[3]&32) nr=nr+2;
 if (by[3]&16) nr++;

 if (!l2) sprintf(tmp,"ACK-NR#%x",nr);
  else sprintf(tmp," ACK-NR#%x",nr);
 strcat(line2,tmp);
 l2=TRUE;
 }

// SESS //
if (tpdu==2)
 {
 unsigned char ses=0;

 if (by[2]&8) ses=ses+4;
 if (by[2]&4) ses=ses+2;
 if (by[2]&2) ses++;

 if (!l2) sprintf(tmp,"SESS#%x",ses);
  else sprintf(tmp," SESS#%x",ses);
 strcat(line2,tmp);
 l2=TRUE;
 }

// CM //
if (tpdu==2)
 {
 if (by[2]&1)
  {
  if (!l2) strcpy(tmp,"CM");
   else strcpy(tmp," CM");
  strcat(line2,tmp);
  l2=TRUE;
  }
 }

// MAN only for CCAM's //
if (tpdu==5)
 {
 char man[30];

 if (!l2) sprintf(man,"MAN#%x",by[4]);
  else sprintf(man," MAN#%x",by[4]);
 sprintf(tmp,"%x",by[5]);
 strcat(man,tmp);
 sprintf(tmp,"%x",by[6]);
 strcat(man,tmp);
 strcat(line2,man);
 
 l2=TRUE;
 }

// REASON //
if (tpdu==4)
 {
 unsigned char res=0;

 if (by[2]&8) res=res+8;
 if (by[2]&4) res=res+4;
 if (by[2]&2) res=res+2;
 if (by[2]&1) res++;

 if (res==0) strcpy(line3,"Reason not specified");
 if (res==1) strcpy(line3,"Congestion at TSAP");
 if (res==2) strcpy(line3,"Normal disconnect initiated by the session entity");
 if (res==4) strcpy(line3,"Connection refusal at connect request time");
 if (res==5) strcpy(line3,"Connection closed due to previous inactivity timeout");
 if (res==6) strcpy(line3,"No connection established");
 if (res==7) strcpy(line3,"HGA not implimented");
 
 l3=TRUE;
 }

// Display data in the DT , CR , CC  and CCAM TPDU's //
if (tpdu==0 || tpdu==2 || tpdu==3 || tpdu==5)
 {
 int a;
 
 // Do not apply to CCAM's //
 if (tpdu!=5)
  {
  // Assume 2 blocks //
  // are CLN and CLD set //
  if (by[1]&1 && by[1]&2)
   {
   sprintf(line3,"%x",by[6]);
   }
  else
   {
   sprintf(line3,"%x",by[4]);
   sprintf(tmp,",%x",by[5]);
   strcat(line3,tmp);
   sprintf(tmp,",%x",by[6]);
   strcat(line3,tmp);
   }
  }

 for (a=7;a<18;a++)
  {
  if (bcounter==2 && a==octet+1) break;
  sprintf(tmp,",%x",by[a]);
  strcat(line3,tmp);
  }

 l3=TRUE;

 // 3 blocks //
 if (bcounter>2)
  {
  for (a=19;a<37;a++)
   {
   if (bcounter==3 && a==octet+19) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line3,tmp);
   }
  }

 // 4 blocks //
 if (bcounter>3)
  {
  sprintf(line4,"%x",by[37]);
  for (a=38;a<55;a++)
   {
   if (bcounter==4 && a==octet+37) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line4,tmp);
   }
  l4=TRUE;
  }

 // 5 blocks //
 if (bcounter>4)
  {
  for (a=55;a<73;a++)
   {
   if (bcounter==5 && a==octet+55) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line4,tmp);
   }
  }

 // 6 blocks //
 if (bcounter>5)
  {
  sprintf(line5,"%x",by[73]); 
  for (a=74;a<91;a++)
   {
   if (bcounter==6 && a==octet+73) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line5,tmp);
   }
  l5=TRUE;
  }

 // 7 blocks //
 if (bcounter>6)
  {
  for (a=91;a<109;a++)
   {
   if (bcounter==7 && a==octet+91) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line5,tmp);
   }
  }

 // 8 blocks //
 if (bcounter>7)
  {
  sprintf(line6,"%x",by[109]);
  for (a=110;a<127;a++)
   {
   if (bcounter==8 && a==octet+109) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line6,tmp);
   }
  l6=TRUE;
  }

 // 9 blocks //
 if (bcounter>8)
  {
  for (a=127;a<145;a++)
   {
   if (bcounter==9 && a==octet+127) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line6,tmp);
   }
  }

  // 10 blocks //
 if (bcounter>9)
  {
  sprintf(line7,"%x",by[145]);
  for (a=146;a<163;a++)
   {
   if (bcounter==10 && a==octet+145) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line7,tmp);
   }
  l7=TRUE;
  }

 // 11 blocks //
 if (bcounter>10)
  {
  for (a=163;a<181;a++)
   {
   if (bcounter==11 && a==octet+163) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line7,tmp);
   }
  }

 // 12 blocks //
 if (bcounter>11)
  {
  sprintf(line8,"%x",by[181]);
  for (a=182;a<199;a++)
   {
   if (bcounter==12 && a==octet+182) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line8,tmp);
   }
  l8=TRUE;
  }

 // 13 blocks //
 if (bcounter>12)
  {
  for (a=199;a<217;a++)
   {
   if (bcounter==13 && a==octet+199) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line8,tmp);
   }
  }

 // 14 blocks //
 if (bcounter>13)
  {
  sprintf(line9,"%x",by[217]);
  for (a=218;a<235;a++)
   {
   if (bcounter==14 && a==octet+217) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line9,tmp);
   }
  l9=TRUE;
  }

 // 15 blocks //
 if (bcounter>14)
  {
  for (a=235;a<253;a++)
   {
   if (bcounter==15 && a==octet+235) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line9,tmp);
   }
  }

 // 16 blocks //
 if (bcounter>15)
  {
  sprintf(line10,"%x",by[253]);
  for (a=254;a<271;a++)
   {
   if (bcounter==16 && a==octet+253) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line10,tmp);
   }
  l10=TRUE;
  }

 // 17 blocks //
 if (bcounter>16)
  {
  for (a=271;a<289;a++)
   {
   if (bcounter==17 && a==octet+271) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line10,tmp);
   }
  }

 // 18 blocks //
 if (bcounter>17)
  {
  sprintf(line11,"%x",by[289]);
  for (a=290;a<307;a++)
   {
   if (bcounter==18 && a==octet+289) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line11,tmp);
   }
  l11=TRUE;
  }

 // 19 blocks //
 if (bcounter>18)
  {
  for (a=307;a<325;a++)
   {
   if (bcounter==19 && a==octet+307) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line11,tmp);
   }
  }

 // 20 blocks //
 if (bcounter>19)
  {
  sprintf(line12,"%x",by[325]);
  for (a=326;a<343;a++)
   {
   if (bcounter==20 && a==octet+325) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line12,tmp);
   }
  l12=TRUE;
  }

 // 21 blocks //
 if (bcounter>20)
  {
  for (a=343;a<361;a++)
   {
   if (bcounter==21 && a==octet+343) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line12,tmp);
   }
  }

 // 22 blocks //
 if (bcounter>21)
  {
  sprintf(line13,"%x",by[361]);
  for (a=362;a<379;a++)
   {
   if (bcounter==22 && a==octet+361) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line13,tmp);
   }
  l13=TRUE;
  }

 // 23 blocks //
 if (bcounter>22)
  {
  for (a=379;a<397;a++)
   {
   if (bcounter==23 && a==octet+379) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line13,tmp);
   }
  }

 // 24 blocks //
 if (bcounter>23)
  {
  sprintf(line14,"%x",by[397]);
  for (a=398;a<415;a++)
   {
   if (bcounter==24 && a==octet+397) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line14,tmp);
   }
  l14=TRUE;
  }

 // 25 blocks //
 if (bcounter>24)
  {
  for (a=415;a<433;a++)
   {
   if (bcounter==25 && a==octet+415) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line14,tmp);
   }
  }

 // 26 blocks //
 if (bcounter>25)
  {
  sprintf(line15,"%x",by[433]);
  for (a=434;a<451;a++)
   {
   if (bcounter==26 && a==octet+433) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line15,tmp);
   }
  l15=TRUE;
  }

 // 27 blocks //
 if (bcounter>26)
  {
  for (a=451;a<469;a++)
   {
   if (bcounter==27 && a==octet+451) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line15,tmp);
   }
  }

 // 28 blocks //
 if (bcounter>27)
  {
  sprintf(line16,"%x",by[469]);
  for (a=470;a<487;a++)
   {
   if (bcounter==28 && a==octet+469) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line16,tmp);
   }
  l16=TRUE;
  }

 // 29 blocks //
 if (bcounter>28)
  {
  for (a=487;a<505;a++)
   {
   if (bcounter==29 && a==octet+487) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line16,tmp);
   }
  }

 // 30 blocks //
 if (bcounter>29)
  {
  sprintf(line17,"%x",by[505]);
  for (a=506;a<533;a++)
   {
   if (bcounter==30 && a==octet+50) break;
   sprintf(tmp,",%x",by[a]);
   strcat(line17,tmp);
   }
  l17=TRUE;
  }

 }

// Display Section //
if (l17)
 {
 strcpy(s,line17);
 rotate();
 }

if (l16)
 {
 strcpy(s,line16);
 rotate();
 }

if (l15)
 {
 strcpy(s,line15);
 rotate();
 }

if (l14)
 {
 strcpy(s,line14);
 rotate();
 }

if (l13)
 {
 strcpy(s,line13);
 rotate();
 }

if (l12)
 {
 strcpy(s,line12);
 rotate();
 }

if (l11)
 {
 strcpy(s,line11);
 rotate();
 }

if (l10)
 {
 strcpy(s,line10);
 rotate();
 }

if (l9)
 {
 strcpy(s,line9);
 rotate();
 }

if (l8)
 {
 strcpy(s,line8);
 rotate();
 }

if (l7)
 {
 strcpy(s,line7);
 rotate();
 }

if (l6)
 {
 strcpy(s,line6);
 rotate();
 }

if (l5)
 {
 strcpy(s,line5);
 rotate();
 }

if (l4)
 {
 strcpy(s,line4);
 rotate();
 }

if (l3)
 {
 strcpy(s,line3);
 rotate();
 }

strcpy(s,line2);
rotate();

strcpy(s,line1);
rotate();

// Display Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();

 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);

 if (l2)
  {
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }

 if (l3)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }

 if (l4)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }

 if (l5)
  {
  logout.Write(line5,strlen(line5));
  logout.Write(enc,1);
  }

 if (l6)
  {
  logout.Write(line6,strlen(line6));
  logout.Write(enc,1);
  }

 if (l7)
  {
  logout.Write(line7,strlen(line7));
  logout.Write(enc,1);
  }

 if (l8)
  {
  logout.Write(line8,strlen(line8));
  logout.Write(enc,1);
  }

 if (l9)
  {
  logout.Write(line9,strlen(line9));
  logout.Write(enc,1);
  }

 if (l10)
  {
  logout.Write(line10,strlen(line10));
  logout.Write(enc,1);
  }

 if (l11)
  {
  logout.Write(line11,strlen(line11));
  logout.Write(enc,1);
  }

 if (l12)
  {
  logout.Write(line12,strlen(line12));
  logout.Write(enc,1);
  }

 if (l13)
  {
  logout.Write(line13,strlen(line13));
  logout.Write(enc,1);
  }

 if (l14)
  {
  logout.Write(line14,strlen(line14));
  logout.Write(enc,1);
  }

 if (l15)
  {
  logout.Write(line15,strlen(line15));
  logout.Write(enc,1);
  }

 if (l16)
  {
  logout.Write(line16,strlen(line16));
  logout.Write(enc,1);
  }

  if (l17)
  {
  logout.Write(line17,strlen(line17));
  logout.Write(enc,1);
  }


 }


}


// Display all Protocols as HEX //
void moby::hex_protocols (char line0[300],char tt)
{
int a;

char tmp[1],line1[300],line2[300],line3[300],line4[300];
char line5[300],line6[300],line7[300],line8[300],line9[300],line10[300];
char line11[300],line12[300],line13[300],line14[300];

// Is the first byte used ? //
if (tt==1) sprintf (line1,"%x",by[0]); 
 else strcpy(line1,"");

 // 2nd Block //
 if (bcounter>1)
  {
  for (a=1;a<19;a++)
   {
   if (bcounter==2 && a==octet+1) break;
   if (tt==0 && a==1) sprintf (tmp,"%x",by[a]); 
    else sprintf(tmp,",%x",by[a]);
   strcat (line1,tmp);
   }
  }


 // Third block //
 if (bcounter>2)
  {
  for (a=19;a<37;a++)
   {
   if (bcounter==3 && a==octet+19) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line1,tmp);
   }
  }

 // 4th block //
 if (bcounter>3)
  {
  sprintf(line2,"%x",by[37]);
  for (a=38;a<55;a++)
   {
   if (bcounter==4 && a==octet+37) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line2,tmp);
   }
  }

 // 5th block //
 if (bcounter>4)
  {
  for (a=55;a<73;a++)
   {
   if (bcounter==5 && a==octet+55) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line2,tmp);
   }
  }

 // 6th block //
 if (bcounter>5)
  {
  sprintf(line3,"%x",by[73]);
  for (a=74;a<91;a++)
   {
   if (bcounter==6 && a==octet+73) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line3,tmp);
   }
  }

 // 7th block //
 if (bcounter>6)
  {
  for (a=91;a<109;a++)
   {
   if (bcounter==7 && a==octet+91) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line3,tmp);
   }
  }

 // 8th block //
 if (bcounter>7)
  {
  sprintf(line4,"%x",by[109]);
  for (a=110;a<127;a++)
   {
   if (bcounter==8 && a==octet+109) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line4,tmp);
   }
  }

  // 9th block //
 if (bcounter>8)
  {
  for (a=127;a<145;a++)
   {
   if (bcounter==9 && a==octet+127) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line4,tmp);
   }
  }

 // 10th block //
 if (bcounter>9)
  {
  sprintf(line5,"%x",by[145]);
  for (a=146;a<163;a++)
   {
   if (bcounter==10 && a==octet+145) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line5,tmp);
   }
  }

  // 11th block //
 if (bcounter>10)
  {
  for (a=163;a<181;a++)
   {
   if (bcounter==11 && a==octet+163) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line5,tmp);
   }
  }

 // 12th block //
 if (bcounter>11)
  {
  sprintf(line6,"%x",by[181]);
  for (a=182;a<199;a++)
   {
   if (bcounter==12 && a==octet+181) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line6,tmp);
   }
  }

  // 13th block //
 if (bcounter>12)
  {
  for (a=199;a<217;a++)
   {
   if (bcounter==13 && a==octet+199) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line6,tmp);
   }
  }

 // 14th block //
 if (bcounter>13)
  {
  sprintf(line7,"%x",by[217]);
  for (a=218;a<235;a++)
   {
   if (bcounter==14 && a==octet+217) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line7,tmp);
   }
  }

  // 15th block //
 if (bcounter>14)
  {
  for (a=235;a<253;a++)
   {
   if (bcounter==15 && a==octet+235) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line7,tmp);
   }
  }

 // 16th block //
 if (bcounter>15)
  {
  sprintf(line8,"%x",by[253]);
  for (a=254;a<271;a++)
   {
   if (bcounter==16 && a==octet+253) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line8,tmp);
   }
  }

  // 17th block //
 if (bcounter>16)
  {
  for (a=271;a<289;a++)
   {
   if (bcounter==17 && a==octet+271) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line8,tmp);
   }
  }

 // 18th block //
 if (bcounter>17)
  {
  sprintf(line9,"%x",by[289]);
  for (a=290;a<307;a++)
   {
   if (bcounter==18 && a==octet+289) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line9,tmp);
   }
  }

  // 19th block //
 if (bcounter>18)
  {
  for (a=307;a<325;a++)
   {
   if (bcounter==19 && a==octet+307) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line9,tmp);
   }
  }

 // 20th block //
 if (bcounter>19)
  {
  sprintf(line10,"%x",by[325]);
  for (a=326;a<343;a++)
   {
   if (bcounter==20 && a==octet+325) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line10,tmp);
   }
  }

  // 21st block //
 if (bcounter>20)
  {
  for (a=343;a<361;a++)
   {
   if (bcounter==21 && a==octet+343) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line10,tmp);
   }
  }

 // 22nd block //
 if (bcounter>21)
  {
  sprintf(line11,"%x",by[361]);
  for (a=362;a<379;a++)
   {
   if (bcounter==22 && a==octet+361) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line11,tmp);
   }
  }

  // 23rd block //
 if (bcounter>22)
  {
  for (a=379;a<397;a++)
   {
   if (bcounter==23 && a==octet+379) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line11,tmp);
   }
  }

 // 24th block //
 if (bcounter>23)
  {
  sprintf(line12,"%x",by[397]);
  for (a=398;a<415;a++)
   {
   if (bcounter==24 && a==octet+397) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line12,tmp);
   }
  }

  // 25th block //
 if (bcounter>24)
  {
  for (a=415;a<433;a++)
   {
   if (bcounter==25 && a==octet+415) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line12,tmp);
   }
  }

 // 26th block //
 if (bcounter>25)
  {
  sprintf(line13,"%x",by[433]);
  for (a=434;a<451;a++)
   {
   if (bcounter==26 && a==octet+433) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line13,tmp);
   }
  }

  // 27th block //
 if (bcounter>26)
  {
  for (a=451;a<469;a++)
   {
   if (bcounter==27 && a==octet+451) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line13,tmp);
   }
  }

 // 28th block //
 if (bcounter>27)
  {
  sprintf(line14,"%x",by[469]);
  for (a=470;a<487;a++)
   {
   if (bcounter==28 && a==octet+470) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line14,tmp);
   }
  }

  // 29th block //
 if (bcounter>28)
  {
  for (a=487;a<505;a++)
   {
   if (bcounter==29 && a==octet+487) break;
   sprintf (tmp,",%x",by[a]);   
   strcat (line14,tmp);
   }
  }

 
// Line 14 //
if (bcounter>27)
 {
 strcpy(s,line14);
 rotate();
 }

// Line 13 //
if (bcounter>25)
 {
 strcpy(s,line13);
 rotate();
 }

// Line 12 //
if (bcounter>23)
 {
 strcpy(s,line12);
 rotate();
 }

// Line 11 //
if (bcounter>21)
 {
 strcpy(s,line11);
 rotate();
 }

// Line 10 //
if (bcounter>19)
 {
 strcpy(s,line10);
 rotate();
 }

// Line 9 //
if (bcounter>17)
 {
 strcpy(s,line9);
 rotate();
 }

// Line 8 //
if (bcounter>15)
 {
 strcpy(s,line8);
 rotate();
 }

// Line 7 //
if (bcounter>13)
 {
 strcpy(s,line7);
 rotate();
 }

// Line 6 //
if (bcounter>11)
 {
 strcpy(s,line6);
 rotate();
 }


// Line 5 //
if (bcounter>9)
 {
 strcpy(s,line5);
 rotate();
 }

// Line 4 //
if (bcounter>7)
 {
 strcpy(s,line4);
 rotate();
 }

// Line 3 //
if (bcounter>5)
 {
 strcpy(s,line3);
 rotate();
 }

// Line 2 //
if (bcounter>3)
 {
 strcpy(s,line2);
 rotate();
 }


// First line //
strcpy(s,line1);
rotate();

// Top line //
strcpy(s,line0);
rotate();

display_stub();
ready=2;

// Write to disk //
if (logging)
 {
 write_stub();
 logout.Write(line0,strlen(line0));
 logout.Write(enc,1);
 logout.Write(line1,strlen(line1));
 logout.Write(enc,1);

 if (bcounter>3)
  {
  logout.Write(line2,strlen(line2));
  logout.Write(enc,1);
  }

 if (bcounter>5)
  {
  logout.Write(line3,strlen(line3));
  logout.Write(enc,1);
  }

 if (bcounter>7)
  {
  logout.Write(line4,strlen(line4));
  logout.Write(enc,1);
  }

 if (bcounter>9)
  {
  logout.Write(line5,strlen(line5));
  logout.Write(enc,1);
  }

 if (bcounter>11)
  {
  logout.Write(line6,strlen(line6));
  logout.Write(enc,1);
  }

 if (bcounter>13)
  {
  logout.Write(line7,strlen(line7));
  logout.Write(enc,1);
  }

 if (bcounter>15)
  {
  logout.Write(line8,strlen(line8));
  logout.Write(enc,1);
  }

 if (bcounter>17)
  {
  logout.Write(line9,strlen(line9));
  logout.Write(enc,1);
  }

 if (bcounter>19)
  {
  logout.Write(line10,strlen(line10));
  logout.Write(enc,1);
  }

 if (bcounter>21)
  {
  logout.Write(line11,strlen(line11));
  logout.Write(enc,1);
  }

 if (bcounter>23)
  {
  logout.Write(line12,strlen(line12));
  logout.Write(enc,1);
  }

  if (bcounter>25)
  {
  logout.Write(line13,strlen(line13));
  logout.Write(enc,1);
  }

 if (bcounter>27)
  {
  logout.Write(line14,strlen(line14));
  logout.Write(enc,1);
  }

 }
}

// Check if an identity is in the ignore.usr file //
BOOL moby::ignore (unsigned long int actual)
{
CFile i_read;
unsigned long int rx;
char a=0,tmp[3],buf[100],value[6];
BOOL ignore=FALSE;


if (!i_read.Open("ignore.usr",CFile::modeRead,NULL))
 {
 AfxMessageBox("Error can't find IGNORE.USR",MB_OK|MB_ICONEXCLAMATION,0);
 goto iend;
 }

iagain:
for (a=0;a<80;a++)
 {
 i_read.Read(tmp,1);
 buf[a]=tmp[0];
 if (tmp[0]==10) break;
 if (tmp[0]==42) goto iend;
 }

// Get the hex value //
value[0]=buf[0];
value[1]=buf[1];
value[2]=buf[2];
value[3]=buf[3];
value[4]=buf[4];
value[5]=buf[5];

// Last digit //
rx=0;
if (value[5]==49) rx=1;
if (value[5]==50) rx=2;
if (value[5]==51) rx=3;
if (value[5]==52) rx=4;
if (value[5]==53) rx=5; 
if (value[5]==54) rx=6;
if (value[5]==55) rx=7;
if (value[5]==56) rx=8;
if (value[5]==57) rx=9;
if (value[5]==65 || value[5]==97) rx=10; 
if (value[5]==66 || value[5]==98) rx=11;
if (value[5]==67 || value[5]==99) rx=12;
if (value[5]==68 || value[5]==100) rx=13;
if (value[5]==69 || value[5]==101) rx=14;
if (value[5]==70 || value[5]==102) rx=15;

// 5th digit //
if (value[4]==49) rx=rx+16;
if (value[4]==50) rx=rx+(2*16);
if (value[4]==51) rx=rx+(3*16);
if (value[4]==52) rx=rx+(4*16);
if (value[4]==53) rx=rx+(5*16);
if (value[4]==54) rx=rx+(6*16);
if (value[4]==55) rx=rx+(7*16);
if (value[4]==56) rx=rx+(8*16);
if (value[4]==57) rx=rx+(9*16);
if (value[4]==65 || value[4]==97) rx=rx+(10*16);
if (value[4]==66 || value[4]==98) rx=rx+(11*16);
if (value[4]==67 || value[4]==99) rx=rx+(12*16);
if (value[4]==68 || value[4]==100) rx=rx+(13*16);
if (value[4]==69 || value[4]==101) rx=rx+(14*16);
if (value[4]==70 || value[4]==102) rx=rx+(15*16);

// 4th digit //
if (value[3]==49) rx=rx+256;
if (value[3]==50) rx=rx+(2*256);
if (value[3]==51) rx=rx+(3*256);
if (value[3]==52) rx=rx+(4*256);
if (value[3]==53) rx=rx+(5*256);
if (value[3]==54) rx=rx+(6*256);
if (value[3]==55) rx=rx+(7*256);
if (value[3]==56) rx=rx+(8*256); 
if (value[3]==57) rx=rx+(9*256);
if (value[3]==65 || value[3]==97) rx=rx+(10*256);
if (value[3]==66 || value[3]==98) rx=rx+(11*256);
if (value[3]==67 || value[3]==99) rx=rx+(12*256);
if (value[3]==68 || value[3]==100) rx=rx+(13*256);
if (value[3]==69 || value[3]==101) rx=rx+(14*256);
if (value[3]==70 || value[3]==102) rx=rx+(15*256);

// 3rd digit //
if (value[2]==49) rx=rx+4096;
if (value[2]==50) rx=rx+(2*4096);
if (value[2]==51) rx=rx+(3*4096);
if (value[2]==52) rx=rx+(4*4096);
if (value[2]==53) rx=rx+(5*4096);
if (value[2]==54) rx=rx+(6*4096);
if (value[2]==55) rx=rx+(7*4096);
if (value[2]==56) rx=rx+(8*4096);
if (value[2]==57) rx=rx+(9*4096);
if (value[2]==65 || value[2]==97) rx=rx+(10*4096);
if (value[2]==66 || value[2]==98) rx=rx+(11*4096);
if (value[2]==67 || value[2]==99) rx=rx+(12*4096);
if (value[2]==68 || value[2]==100) rx=rx+(13*4096);
if (value[2]==69 || value[2]==101) rx=rx+(14*4096);
if (value[2]==70 || value[2]==102) rx=rx+(15*4096);

// 2nd digit //
if (value[1]==49) rx=rx+65536;
if (value[1]==50) rx=rx+(2*65536);
if (value[1]==51) rx=rx+(3*65536);
if (value[1]==52) rx=rx+(4*65536);
if (value[1]==53) rx=rx+(5*65536);
if (value[1]==54) rx=rx+(6*65536);
if (value[1]==55) rx=rx+(7*65536);
if (value[1]==56) rx=rx+(8*65536);
if (value[1]==57) rx=rx+(9*65536);
if (value[1]==65 || value[1]==97) rx=rx+(10*65536);
if (value[1]==66 || value[1]==98) rx=rx+(11*65536);
if (value[1]==67 || value[1]==99) rx=rx+(12*65536);
if (value[1]==68 || value[1]==100) rx=rx+(13*65536);
if (value[1]==69 || value[1]==101) rx=rx+(14*65536);
if (value[1]==70 || value[1]==102) rx=rx+(15*65536);

// 1st digit //
if (value[0]==49) rx=rx+1048576;
if (value[0]==50) rx=rx+(2*1048576);
if (value[0]==51) rx=rx+(3*1048576);
if (value[0]==52) rx=rx+(4*1048576);
if (value[0]==53) rx=rx+(5*1048576);
if (value[0]==54) rx=rx+(6*1048576);
if (value[0]==55) rx=rx+(7*1048576);
if (value[0]==56) rx=rx+(8*1048576);
if (value[0]==57) rx=rx+(9*1048576);
if (value[0]==65 || value[0]==97) rx=rx+(10*1048576);
if (value[0]==66 || value[0]==98) rx=rx+(11*1048576);
if (value[0]==67 || value[0]==99) rx=rx+(12*1048576);
if (value[0]==68 || value[0]==100) rx=rx+(13*1048576);
if (value[0]==69 || value[0]==101) rx=rx+(14*1048576);
if (value[0]==70 || value[0]==102) rx=rx+(15*1048576);

// Do we have a match //
if (actual==rx) ignore=TRUE;
 else goto iagain;

iend:
i_read.Close();
return ignore;
}

// Check if an identity is in the exclusive.usr file //
BOOL moby::exclusive (unsigned long int actual)
{
CFile i_read;
unsigned long int rx;
char a=0,tmp[3],buf[100],value[6];
BOOL ignore=FALSE;


if (!i_read.Open("exclusive.usr",CFile::modeRead,NULL))
 {
 AfxMessageBox("Error can't find EXCLUSIVE.USR",MB_OK|MB_ICONEXCLAMATION,0);
 goto eend;
 }

eagain:
for (a=0;a<80;a++)
 {
 i_read.Read(tmp,1);
 buf[a]=tmp[0];
 if (tmp[0]==10) break;
 if (tmp[0]==42) goto eend;
 }

// Get the hex value //
value[0]=buf[0];
value[1]=buf[1];
value[2]=buf[2];
value[3]=buf[3];
value[4]=buf[4];
value[5]=buf[5];

// Last digit //
rx=0;
if (value[5]==49) rx=1;
if (value[5]==50) rx=2;
if (value[5]==51) rx=3;
if (value[5]==52) rx=4;
if (value[5]==53) rx=5; 
if (value[5]==54) rx=6;
if (value[5]==55) rx=7;
if (value[5]==56) rx=8;
if (value[5]==57) rx=9;
if (value[5]==65 || value[5]==97) rx=10; 
if (value[5]==66 || value[5]==98) rx=11;
if (value[5]==67 || value[5]==99) rx=12;
if (value[5]==68 || value[5]==100) rx=13;
if (value[5]==69 || value[5]==101) rx=14;
if (value[5]==70 || value[5]==102) rx=15;

// 5th digit //
if (value[4]==49) rx=rx+16;
if (value[4]==50) rx=rx+(2*16);
if (value[4]==51) rx=rx+(3*16);
if (value[4]==52) rx=rx+(4*16);
if (value[4]==53) rx=rx+(5*16);
if (value[4]==54) rx=rx+(6*16);
if (value[4]==55) rx=rx+(7*16);
if (value[4]==56) rx=rx+(8*16);
if (value[4]==57) rx=rx+(9*16);
if (value[4]==65 || value[4]==97) rx=rx+(10*16);
if (value[4]==66 || value[4]==98) rx=rx+(11*16);
if (value[4]==67 || value[4]==99) rx=rx+(12*16);
if (value[4]==68 || value[4]==100) rx=rx+(13*16);
if (value[4]==69 || value[4]==101) rx=rx+(14*16);
if (value[4]==70 || value[4]==102) rx=rx+(15*16);

// 4th digit //
if (value[3]==49) rx=rx+256;
if (value[3]==50) rx=rx+(2*256);
if (value[3]==51) rx=rx+(3*256);
if (value[3]==52) rx=rx+(4*256);
if (value[3]==53) rx=rx+(5*256);
if (value[3]==54) rx=rx+(6*256);
if (value[3]==55) rx=rx+(7*256);
if (value[3]==56) rx=rx+(8*256); 
if (value[3]==57) rx=rx+(9*256);
if (value[3]==65 || value[3]==97) rx=rx+(10*256);
if (value[3]==66 || value[3]==98) rx=rx+(11*256);
if (value[3]==67 || value[3]==99) rx=rx+(12*256);
if (value[3]==68 || value[3]==100) rx=rx+(13*256);
if (value[3]==69 || value[3]==101) rx=rx+(14*256);
if (value[3]==70 || value[3]==102) rx=rx+(15*256);

// 3rd digit //
if (value[2]==49) rx=rx+4096;
if (value[2]==50) rx=rx+(2*4096);
if (value[2]==51) rx=rx+(3*4096);
if (value[2]==52) rx=rx+(4*4096);
if (value[2]==53) rx=rx+(5*4096);
if (value[2]==54) rx=rx+(6*4096);
if (value[2]==55) rx=rx+(7*4096);
if (value[2]==56) rx=rx+(8*4096);
if (value[2]==57) rx=rx+(9*4096);
if (value[2]==65 || value[2]==97) rx=rx+(10*4096);
if (value[2]==66 || value[2]==98) rx=rx+(11*4096);
if (value[2]==67 || value[2]==99) rx=rx+(12*4096);
if (value[2]==68 || value[2]==100) rx=rx+(13*4096);
if (value[2]==69 || value[2]==101) rx=rx+(14*4096);
if (value[2]==70 || value[2]==102) rx=rx+(15*4096);

// 2nd digit //
if (value[1]==49) rx=rx+65536;
if (value[1]==50) rx=rx+(2*65536);
if (value[1]==51) rx=rx+(3*65536);
if (value[1]==52) rx=rx+(4*65536);
if (value[1]==53) rx=rx+(5*65536);
if (value[1]==54) rx=rx+(6*65536);
if (value[1]==55) rx=rx+(7*65536);
if (value[1]==56) rx=rx+(8*65536);
if (value[1]==57) rx=rx+(9*65536);
if (value[1]==65 || value[1]==97) rx=rx+(10*65536);
if (value[1]==66 || value[1]==98) rx=rx+(11*65536);
if (value[1]==67 || value[1]==99) rx=rx+(12*65536);
if (value[1]==68 || value[1]==100) rx=rx+(13*65536);
if (value[1]==69 || value[1]==101) rx=rx+(14*65536);
if (value[1]==70 || value[1]==102) rx=rx+(15*65536);

// 1st digit //
if (value[0]==49) rx=rx+1048576;
if (value[0]==50) rx=rx+(2*1048576);
if (value[0]==51) rx=rx+(3*1048576);
if (value[0]==52) rx=rx+(4*1048576);
if (value[0]==53) rx=rx+(5*1048576);
if (value[0]==54) rx=rx+(6*1048576);
if (value[0]==55) rx=rx+(7*1048576);
if (value[0]==56) rx=rx+(8*1048576);
if (value[0]==57) rx=rx+(9*1048576);
if (value[0]==65 || value[0]==97) rx=rx+(10*1048576);
if (value[0]==66 || value[0]==98) rx=rx+(11*1048576);
if (value[0]==67 || value[0]==99) rx=rx+(12*1048576);
if (value[0]==68 || value[0]==100) rx=rx+(13*1048576);
if (value[0]==69 || value[0]==101) rx=rx+(14*1048576);
if (value[0]==70 || value[0]==102) rx=rx+(15*1048576);

// Do we have a match //
if (actual==rx) ignore=TRUE;
 else goto eagain;

eend:
i_read.Close();
return ignore;
}

// Calculate the frequency from the channel number //
float moby::euro_calc (unsigned int ch)
{
float f;

f=380.0f+(ch*0.0125f);

return (f);
}