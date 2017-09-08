// mobymon.h : main header file for the MOBYMON application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class moby
{
public:
static DCB dcb;
static HANDLE hcom;
static COMMTIMEOUTS commtimeouts;
static char id[200];
static char s0[300],s1[300],s2[300],s3[300],s4[300],s5[300],s6[300],s7[300],s8[300],s9[300];
static char s10[300],s11[300],s12[300],s13[300],s14[300],s15[300],s16[300],s17[300],s18[300],s19[300];
static char s20[300],s21[300],s22[300],s23[300],s24[300],s25[300],s26[300],s27[300],s28[300],s29[300];
static char s30[300],s31[300],s32[300],s33[300],s34[300],s35[300],s36[300],s37[300],s38[300],s39[300];
static char s40[300],s41[300],s42[300],s43[300],s44[300],s45[300],s46[300],s47[300],s48[300],s49[300];
static char s50[300],s51[300],s52[300],s53[300],s54[300],s55[300],s56[300],s57[300],s58[300],s59[300];
static char s60[300],s61[300],s62[300],s63[300],s64[300],s65[300],s66[300],s67[300],s68[300],s69[300];
static char s70[300],s71[300],s72[300],s73[300],s74[300],s75[300],s76[300],s77[300],s78[300],s79[300];
static char s80[300],s81[300],s82[300],s83[300],s84[300],s85[300],s86[300],s87[300],s88[300],s89[300];
static char s90[300],s91[300],s92[300],s93[300],s94[300],s95[300],s96[300],s97[300],s98[300],s99[300];
static char s100[300],s101[300],s102[300],s103[300],s104[300],s105[300],s106[300],s107[300],s108[300],s109[300];
static char s110[300],s111[300],s112[300],s113[300],s114[300],s115[300],s116[300],s117[300],s118[300],s119[300];

static char ready,com_port;
static char ts[30],s[300],enc[5],user_name[100];
static unsigned char b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
static unsigned char b10,b11,b12,b13,b14,b15,b16,b17,b18,b19;
static unsigned char b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30;
static unsigned char bcounter,blocks,f,by[900],state,octet,sequence,no_addr;
static unsigned long system,sender,mob,address,blacklist;
static unsigned int s_pos;
static unsigned char frame,surrounding;
static BOOL blk[70][241],scr[512];
static BOOL comportsetup,logging,debug,base_mon,multi_add,use_exclusive;
static BOOL data_show,hpdata_user_show,hpdata_messaging_show,hpdata_gateway_show,hpdata_mtp1_show,hpdata_ramp_show,hpdata_rnm_show;
static BOOL time_show,grouplist_show,flexlist_show,status_show,esnreq_show;
static BOOL text_show,extpak_show,inforeq_show,live_show,die_show;
static BOOL logingra_show,loginref_show,logoutord_show,roamord_show,flexreq_show;
static BOOL sos_show,sosinfo_show,sosack_show,arealist_show,sosconfast_show,sosconreq_show;
static BOOL addconfast_show,confast_show,cloopoff_show,cloopon_show,discon_show;
static BOOL conord_show,congra_show,addconreq_show,conreq_show;
static BOOL data_ascii_show,hpdata_130_show,extpak_ascii_show,sos_ascii_show,sosinfo_ascii_show;
static BOOL display_traffic_state,ignore_illegal_state,ignore_ok_state,ignore_from_mail_state,ignore_in_mail_state;
static BOOL ignore_no_transfer_state,ignore_congest_state,ignore_error_state,ignore_busy_state;
static BOOL sequence_display,use_ignore,re_display,am_a_server,am_a_terminal;
static BOOL loginreq_show,logout_show,born_show,active_show,inactive_show,roam_show,vicesosrx_show,sosrx_show,info_show,esninfo_show;
static BOOL extconreq_show,conrea_show,lineon_show,lineoff_show,linsel_show;
static BOOL head_rxed,enable_checking,enable_fec;
static BOOL display_mrm,display_ack,display_nak,display_reb,display_res,display_abd,display_atd;
static BOOL display_atl,display_bkd,display_fri,display_svp,display_tst,display_akt,display_abl;
static float total_blocks,bad_blocks,upf[16],dof[16];

public:
unsigned char getchar (void);
BOOL linkcheck (void);
void reset_variables (void);
BOOL valid_head (void);
void mpak (void);
void head (void);
void scramble_sequence (void);
int fec (int);
BOOL fec_correct (int,int,int);
int block (void);
int blockfec (int);
void scramble (int);
void extract_data (void);
void extract_data_add (void);
unsigned char data_strip (int,int);
BOOL getblock (int);
void moby_time (unsigned long int);
void mtime (void);
void display_stub (void);
void send (char);
void hpdata (void);
void data (void);
void extpak (void);
void statusa (void);
void statusb (void);
void esnreq (void);
void sosack (void);
void conreq (void);
void confast (void);
void sosconreq (void);
void sosconfast (void);
void congra (void);
void conord (void);
void discon (void);
void cloopon (void);
void cloopoff (void);
void logingra (void);
void loginref (void);
void logoutord (void);
void die (void);
void live (void);
void roamord (void);
void flexreq (void);
void inforeq (void);
void text (void);
void text_list (void);
void sosinfo (void);
void arealist (void);
void addconreq (void);
void addconfast (void);
void extconreq (void);
void grouplist (void);
void flexlist (void);
void rotate (void);
void sos (void);
void openlogfile (void);
void closelogfile (void);
void write_stub (void);
void blank_line (void);
void decode_mtp1 (char[300]);
void ascii_protocols (char[300],char);
void ascii_protocols_list (char[300],char,char,unsigned long int,unsigned long int,unsigned long int,unsigned long int,unsigned long int,unsigned long int,unsigned long int);
void hex_protocols (char[300],char);
void decode_protocol135 (char[300]);
void decode_nmea_rmc (char[300]);
void decode_nmea_gga (char[300]);
void decode_messaging (char[300]);
BOOL get_identity (unsigned long int);
BOOL ignore (unsigned long int);
BOOL exclusive (unsigned long int);
void esninfo (void);
void loginreq (void);
void logoutmpak (void);
void born (void);
void active (void);
void inactive (void);
void roam (void);
void sosrx (void);
void vicesosrx (void);
void info (void);
void lineon (void);
void lineoff (void);
void conrea (void);
void linsel (void);
void small_frame (void);
void fri (void);
void bkd (void);
void svp (void);
void reb (void);
void abx (void);
void tst (void);
float euro_calc (unsigned int);

#define WM_LISTEN_SOCKET_RESPONSE WM_USER+201
#define WM_SOCKET_SERVER_RX WM_USER+202
#define WM_TERMINAL_RX WM_USER+203
#define PORT_NUM 8076

};

/////////////////////////////////////////////////////////////////////////////
// CMobymonApp:
// See mobymon.cpp for the implementation of this class
//

class CMobymonApp : public CWinApp , public moby
{
public:
	CMobymonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMobymonApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMobymonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
