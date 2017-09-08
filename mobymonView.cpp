// mobymonView.cpp : implementation of the CMobymonView class
//

#include "stdafx.h"
#include "mobymon.h"
#include "mobymonDoc.h"
#include "mobymonView.h"
#include "comselect.h"
#include "remote.h"
#include "man_select.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMobymonView

IMPLEMENT_DYNCREATE(CMobymonView, CScrollView)

BEGIN_MESSAGE_MAP(CMobymonView, CScrollView)
	//{{AFX_MSG_MAP(CMobymonView)
	ON_COMMAND(ID_CONNECT, OnConnect)
	ON_WM_TIMER()
	ON_COMMAND(ID_START_LOGGING, OnStartLogging)
	ON_UPDATE_COMMAND_UI(ID_START_LOGGING, OnUpdateStartLogging)
	ON_COMMAND(ID_END_LOGGING, OnEndLogging)
	ON_UPDATE_COMMAND_UI(ID_END_LOGGING, OnUpdateEndLogging)
	ON_COMMAND(ID_DATA, OnData)
	ON_UPDATE_COMMAND_UI(ID_DATA, OnUpdateData)
	ON_COMMAND(ID_SIGNALQUALITY, OnSignalquality)
	ON_COMMAND(ID_TIME, OnTime)
	ON_UPDATE_COMMAND_UI(ID_TIME, OnUpdateTime)
	ON_COMMAND(ID_FLEXLIST, OnFlexlist)
	ON_UPDATE_COMMAND_UI(ID_FLEXLIST, OnUpdateFlexlist)
	ON_COMMAND(ID_GROUPLIST, OnGrouplist)
	ON_UPDATE_COMMAND_UI(ID_GROUPLIST, OnUpdateGrouplist)
	ON_COMMAND(ID_STATUS, OnStatus)
	ON_UPDATE_COMMAND_UI(ID_STATUS, OnUpdateStatus)
	ON_COMMAND(ID_ESNREQ, OnEsnreq)
	ON_UPDATE_COMMAND_UI(ID_ESNREQ, OnUpdateEsnreq)
	ON_COMMAND(ID_TEXT, OnText)
	ON_UPDATE_COMMAND_UI(ID_TEXT, OnUpdateText)
	ON_COMMAND(ID_EXTPAK, OnExtpak)
	ON_UPDATE_COMMAND_UI(ID_EXTPAK, OnUpdateExtpak)
	ON_COMMAND(ID_INFOREQ, OnInforeq)
	ON_UPDATE_COMMAND_UI(ID_INFOREQ, OnUpdateInforeq)
	ON_COMMAND(ID_DIE, OnDie)
	ON_UPDATE_COMMAND_UI(ID_DIE, OnUpdateDie)
	ON_COMMAND(ID_LIVE, OnLive)
	ON_UPDATE_COMMAND_UI(ID_LIVE, OnUpdateLive)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_LOGINGRA, OnLogingra)
	ON_UPDATE_COMMAND_UI(ID_LOGINGRA, OnUpdateLogingra)
	ON_COMMAND(ID_LOGINREF, OnLoginref)
	ON_UPDATE_COMMAND_UI(ID_LOGINREF, OnUpdateLoginref)
	ON_COMMAND(ID_LOGOUTORD, OnLogoutord)
	ON_UPDATE_COMMAND_UI(ID_LOGOUTORD, OnUpdateLogoutord)
	ON_COMMAND(ID_FLEXREQ, OnFlexreq)
	ON_UPDATE_COMMAND_UI(ID_FLEXREQ, OnUpdateFlexreq)
	ON_COMMAND(ID_ROAMORD, OnRoamord)
	ON_UPDATE_COMMAND_UI(ID_ROAMORD, OnUpdateRoamord)
	ON_COMMAND(ID_HPDATA_GATEWAY, OnHpdataGateway)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_GATEWAY, OnUpdateHpdataGateway)
	ON_COMMAND(ID_HPDATA_MESSAGING, OnHpdataMessaging)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_MESSAGING, OnUpdateHpdataMessaging)
	ON_COMMAND(ID_HPDATA_MTP1, OnHpdataMtp1)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_MTP1, OnUpdateHpdataMtp1)
	ON_COMMAND(ID_HPDATA_RAMP, OnHpdataRamp)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_RAMP, OnUpdateHpdataRamp)
	ON_COMMAND(ID_HPDATA_RNM, OnHpdataRnm)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_RNM, OnUpdateHpdataRnm)
	ON_COMMAND(ID_HPDATA_USER, OnHpdataUser)
	ON_UPDATE_COMMAND_UI(ID_HPDATA_USER, OnUpdateHpdataUser)
	ON_COMMAND(ID_AREALIST, OnArealist)
	ON_UPDATE_COMMAND_UI(ID_AREALIST, OnUpdateArealist)
	ON_COMMAND(ID_SOS, OnSos)
	ON_UPDATE_COMMAND_UI(ID_SOS, OnUpdateSos)
	ON_COMMAND(ID_SOSINFO, OnSosinfo)
	ON_UPDATE_COMMAND_UI(ID_SOSINFO, OnUpdateSosinfo)
	ON_COMMAND(ID_SOSACK, OnSosack)
	ON_UPDATE_COMMAND_UI(ID_SOSACK, OnUpdateSosack)
	ON_COMMAND(ID_SOSCONFAST, OnSosconfast)
	ON_UPDATE_COMMAND_UI(ID_SOSCONFAST, OnUpdateSosconfast)
	ON_COMMAND(ID_SOSCONREQ, OnSosconreq)
	ON_UPDATE_COMMAND_UI(ID_SOSCONREQ, OnUpdateSosconreq)
	ON_COMMAND(ID_ADDCONFAST, OnAddconfast)
	ON_UPDATE_COMMAND_UI(ID_ADDCONFAST, OnUpdateAddconfast)
	ON_COMMAND(ID_CONFAST, OnConfast)
	ON_UPDATE_COMMAND_UI(ID_CONFAST, OnUpdateConfast)
	ON_COMMAND(ID_CLOOPOFF, OnCloopoff)
	ON_UPDATE_COMMAND_UI(ID_CLOOPOFF, OnUpdateCloopoff)
	ON_COMMAND(ID_CLOOPON, OnCloopon)
	ON_UPDATE_COMMAND_UI(ID_CLOOPON, OnUpdateCloopon)
	ON_COMMAND(ID_DISCON, OnDiscon)
	ON_UPDATE_COMMAND_UI(ID_DISCON, OnUpdateDiscon)
	ON_COMMAND(ID_CONORD, OnConord)
	ON_UPDATE_COMMAND_UI(ID_CONORD, OnUpdateConord)
	ON_COMMAND(ID_CONGRA, OnCongra)
	ON_UPDATE_COMMAND_UI(ID_CONGRA, OnUpdateCongra)
	ON_COMMAND(ID_CONREQ, OnConreq)
	ON_UPDATE_COMMAND_UI(ID_CONREQ, OnUpdateConreq)
	ON_COMMAND(ID_ADDCONREQ, OnAddconreq)
	ON_UPDATE_COMMAND_UI(ID_ADDCONREQ, OnUpdateAddconreq)
	ON_COMMAND(ID_DATA_AS_ASCII, OnDataAsAscii)
	ON_UPDATE_COMMAND_UI(ID_DATA_AS_ASCII, OnUpdateDataAsAscii)
	ON_COMMAND(ID_130_DECODE, On130Decode)
	ON_UPDATE_COMMAND_UI(ID_130_DECODE, OnUpdate130Decode)
	ON_COMMAND(ID_DEBUG, OnDebug)
	ON_UPDATE_COMMAND_UI(ID_DEBUG, OnUpdateDebug)
	ON_COMMAND(ID_EXTPAK_ASCII, OnExtpakAscii)
	ON_UPDATE_COMMAND_UI(ID_EXTPAK_ASCII, OnUpdateExtpakAscii)
	ON_COMMAND(ID_SOS_ASCII, OnSosAscii)
	ON_UPDATE_COMMAND_UI(ID_SOS_ASCII, OnUpdateSosAscii)
	ON_COMMAND(ID_SOSINFO_ASCII, OnSosinfoAscii)
	ON_UPDATE_COMMAND_UI(ID_SOSINFO_ASCII, OnUpdateSosinfoAscii)
	ON_COMMAND(ID_TRAFFIC_STATE, OnTrafficState)
	ON_UPDATE_COMMAND_UI(ID_TRAFFIC_STATE, OnUpdateTrafficState)
	ON_COMMAND(ID_IGNORE_BUSY, OnIgnoreBusy)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_BUSY, OnUpdateIgnoreBusy)
	ON_COMMAND(ID_IGNORE_CONGEST, OnIgnoreCongest)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_CONGEST, OnUpdateIgnoreCongest)
	ON_COMMAND(ID_IGNORE_ERROR, OnIgnoreError)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_ERROR, OnUpdateIgnoreError)
	ON_COMMAND(ID_IGNORE_FROM_MAIL, OnIgnoreFromMail)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_FROM_MAIL, OnUpdateIgnoreFromMail)
	ON_COMMAND(ID_IGNORE_ILLEGAL, OnIgnoreIllegal)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_ILLEGAL, OnUpdateIgnoreIllegal)
	ON_COMMAND(ID_IGNORE_IN_MAIL, OnIgnoreInMail)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_IN_MAIL, OnUpdateIgnoreInMail)
	ON_COMMAND(ID_IGNORE_NO_TRANSER, OnIgnoreNoTranser)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_NO_TRANSER, OnUpdateIgnoreNoTranser)
	ON_COMMAND(ID_IGNORE_OK, OnIgnoreOk)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_OK, OnUpdateIgnoreOk)
	ON_COMMAND(ID_HOSTNAME, OnHostname)
	ON_COMMAND(ID_SEQUENCE, OnSequence)
	ON_UPDATE_COMMAND_UI(ID_SEQUENCE, OnUpdateSequence)
	ON_COMMAND(ID_IGNORE_USR, OnIgnoreUsr)
	ON_UPDATE_COMMAND_UI(ID_IGNORE_USR, OnUpdateIgnoreUsr)
	ON_COMMAND(ID_RE_DISPLAY, OnReDisplay)
	ON_UPDATE_COMMAND_UI(ID_RE_DISPLAY, OnUpdateReDisplay)
	ON_COMMAND(ID_HELP, OnHelp)
	ON_COMMAND(ID_REMOTE_CONNECT, OnRemoteConnect)
	ON_UPDATE_COMMAND_UI(ID_REMOTE_CONNECT, OnUpdateRemoteConnect)
	ON_COMMAND(ID_DISCONNECT, OnDisconnect)
	ON_UPDATE_COMMAND_UI(ID_DISCONNECT, OnUpdateDisconnect)
	ON_COMMAND(ID_MON_BASE, OnMonBase)
	ON_UPDATE_COMMAND_UI(ID_MON_BASE, OnUpdateMonBase)
	ON_COMMAND(ID_MON_MOB, OnMonMob)
	ON_UPDATE_COMMAND_UI(ID_MON_MOB, OnUpdateMonMob)
	ON_COMMAND(ID_LOGINREQ, OnLoginreq)
	ON_UPDATE_COMMAND_UI(ID_LOGINREQ, OnUpdateLoginreq)
	ON_COMMAND(ID_LOGOUT, OnLogout)
	ON_UPDATE_COMMAND_UI(ID_LOGOUT, OnUpdateLogout)
	ON_COMMAND(ID_BORN, OnBorn)
	ON_UPDATE_COMMAND_UI(ID_BORN, OnUpdateBorn)
	ON_COMMAND(ID_ACTIVE, OnActive)
	ON_UPDATE_COMMAND_UI(ID_ACTIVE, OnUpdateActive)
	ON_COMMAND(ID_INACTIVE, OnInactive)
	ON_UPDATE_COMMAND_UI(ID_INACTIVE, OnUpdateInactive)
	ON_COMMAND(ID_ROAM, OnRoam)
	ON_UPDATE_COMMAND_UI(ID_ROAM, OnUpdateRoam)
	ON_COMMAND(ID_VICESOSRX, OnVicesosrx)
	ON_UPDATE_COMMAND_UI(ID_VICESOSRX, OnUpdateVicesosrx)
	ON_COMMAND(ID_SOSRX, OnSosrx)
	ON_UPDATE_COMMAND_UI(ID_SOSRX, OnUpdateSosrx)
	ON_COMMAND(ID_INFO, OnInfo)
	ON_UPDATE_COMMAND_UI(ID_INFO, OnUpdateInfo)
	ON_COMMAND(ID_ESNINFO, OnEsninfo)
	ON_UPDATE_COMMAND_UI(ID_ESNINFO, OnUpdateEsninfo)
	ON_COMMAND(ID_EXCONREQ, OnExconreq)
	ON_UPDATE_COMMAND_UI(ID_EXCONREQ, OnUpdateExconreq)
	ON_COMMAND(ID_CONREA, OnConrea)
	ON_UPDATE_COMMAND_UI(ID_CONREA, OnUpdateConrea)
	ON_COMMAND(ID_LINEON, OnLineon)
	ON_UPDATE_COMMAND_UI(ID_LINEON, OnUpdateLineon)
	ON_COMMAND(ID_LINEOFF, OnLineoff)
	ON_UPDATE_COMMAND_UI(ID_LINEOFF, OnUpdateLineoff)
	ON_COMMAND(ID_LINSEL, OnLinsel)
	ON_UPDATE_COMMAND_UI(ID_LINSEL, OnUpdateLinsel)
	ON_COMMAND(ID_EXCLUSIVE_USR, OnExclusiveUsr)
	ON_UPDATE_COMMAND_UI(ID_EXCLUSIVE_USR, OnUpdateExclusiveUsr)
	ON_COMMAND(ID_SINGLE_MAN, OnSingleMan)
	ON_UPDATE_COMMAND_UI(ID_SINGLE_MAN, OnUpdateSingleMan)
	ON_COMMAND(ID_BLACKLIST_CLEAR, OnBlacklistClear)
	ON_UPDATE_COMMAND_UI(ID_BLACKLIST_CLEAR, OnUpdateBlacklistClear)
	ON_COMMAND(ID_FIRMWARE_INFO, OnFirmwareInfo)
	ON_UPDATE_COMMAND_UI(ID_FIRMWARE_INFO, OnUpdateFirmwareInfo)
	ON_COMMAND(ID_ERROR_CHECKING, OnErrorChecking)
	ON_UPDATE_COMMAND_UI(ID_ERROR_CHECKING, OnUpdateErrorChecking)
	ON_COMMAND(ID_FEC, OnFec)
	ON_UPDATE_COMMAND_UI(ID_FEC, OnUpdateFec)
	ON_COMMAND(ID_ABD, OnAbd)
	ON_UPDATE_COMMAND_UI(ID_ABD, OnUpdateAbd)
	ON_COMMAND(ID_ACK, OnAck)
	ON_UPDATE_COMMAND_UI(ID_ACK, OnUpdateAck)
	ON_COMMAND(ID_AKT, OnAkt)
	ON_UPDATE_COMMAND_UI(ID_AKT, OnUpdateAkt)
	ON_COMMAND(ID_ATD, OnAtd)
	ON_UPDATE_COMMAND_UI(ID_ATD, OnUpdateAtd)
	ON_COMMAND(ID_ATL, OnAtl)
	ON_UPDATE_COMMAND_UI(ID_ATL, OnUpdateAtl)
	ON_COMMAND(ID_BKD, OnBkd)
	ON_UPDATE_COMMAND_UI(ID_BKD, OnUpdateBkd)
	ON_COMMAND(ID_FRI, OnFri)
	ON_UPDATE_COMMAND_UI(ID_FRI, OnUpdateFri)
	ON_COMMAND(ID_MRM, OnMrm)
	ON_UPDATE_COMMAND_UI(ID_MRM, OnUpdateMrm)
	ON_COMMAND(ID_REB, OnReb)
	ON_UPDATE_COMMAND_UI(ID_REB, OnUpdateReb)
	ON_COMMAND(ID_RES, OnRes)
	ON_UPDATE_COMMAND_UI(ID_RES, OnUpdateRes)
	ON_COMMAND(ID_SVP, OnSvp)
	ON_UPDATE_COMMAND_UI(ID_SVP, OnUpdateSvp)
	ON_COMMAND(ID_TST, OnTst)
	ON_UPDATE_COMMAND_UI(ID_TST, OnUpdateTst)
	ON_COMMAND(ID_NAK, OnNak)
	ON_UPDATE_COMMAND_UI(ID_NAK, OnUpdateNak)
	ON_COMMAND(ID_ABL, OnAbl)
	ON_UPDATE_COMMAND_UI(ID_ABL, OnUpdateAbl)
	ON_COMMAND(ID_SYSTEM_CHANNELS, OnSystemChannels)
	ON_UPDATE_COMMAND_UI(ID_SYSTEM_CHANNELS, OnUpdateSystemChannels)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)


END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMobymonView construction/destruction

CMobymonView::CMobymonView()
{
strcpy(id,"Not Connected");


}

CMobymonView::~CMobymonView()
{
}

BOOL CMobymonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Scrolling code //
void CMobymonView::OnInitialUpdate()
{
   // ...
   // Implement a GetDocSize( ) member function in 
   // your document class; it returns a CSize.
   SetScrollSizes( MM_TEXT, GetDocument( )->GetDocSize( ) );
}


/////////////////////////////////////////////////////////////////////////////
// CMobymonView drawing

void CMobymonView::OnDraw(CDC* pDC)
{

CMobymonDoc* pDoc = GetDocument();
ASSERT_VALID(pDoc);

pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));

pDC->TextOut(10,10,id,strlen(id));
 
// Print out the display stack //
if (s0[0]>0 && s0[0]<127) pDC->TextOut(10,30,s0,strlen(s0));
if (s1[0]>0 && s1[0]<127) pDC->TextOut(10,47,s1,strlen(s1));
if (s2[0]>0 && s2[0]<127) pDC->TextOut(10,64,s2,strlen(s2));
if (s3[0]>0 && s3[0]<127) pDC->TextOut(10,81,s3,strlen(s3));
if (s4[0]>0 && s4[0]<127) pDC->TextOut(10,98,s4,strlen(s4));
if (s5[0]>0 && s5[0]<127) pDC->TextOut(10,115,s5,strlen(s5));
if (s6[0]>0 && s6[0]<127) pDC->TextOut(10,132,s6,strlen(s6));
if (s7[0]>0 && s7[0]<127) pDC->TextOut(10,149,s7,strlen(s7));
if (s8[0]>0 && s8[0]<127) pDC->TextOut(10,166,s8,strlen(s8));
if (s9[0]>0 && s9[0]<127) pDC->TextOut(10,183,s9,strlen(s9)); 
if (s10[0]>0 && s10[0]<127) pDC->TextOut(10,200,s10,strlen(s10));
if (s11[0]>0 && s11[0]<127) pDC->TextOut(10,217,s11,strlen(s11));
if (s12[0]>0 && s12[0]<127) pDC->TextOut(10,234,s12,strlen(s12));
if (s13[0]>0 && s13[0]<127) pDC->TextOut(10,251,s13,strlen(s13));
if (s14[0]>0 && s14[0]<127) pDC->TextOut(10,268,s14,strlen(s14));  
if (s15[0]>0 && s15[0]<127) pDC->TextOut(10,285,s15,strlen(s15));
if (s16[0]>0 && s16[0]<127) pDC->TextOut(10,302,s16,strlen(s16));
if (s17[0]>0 && s17[0]<127) pDC->TextOut(10,319,s17,strlen(s17));
if (s18[0]>0 && s18[0]<127) pDC->TextOut(10,336,s18,strlen(s18));  
if (s19[0]>0 && s19[0]<127) pDC->TextOut(10,353,s19,strlen(s19));  
if (s20[0]>0 && s20[0]<127) pDC->TextOut(10,370,s20,strlen(s20));
if (s21[0]>0 && s21[0]<127) pDC->TextOut(10,387,s21,strlen(s21));
if (s22[0]>0 && s22[0]<127) pDC->TextOut(10,404,s22,strlen(s22));
if (s23[0]>0 && s23[0]<127) pDC->TextOut(10,421,s23,strlen(s23));
if (s24[0]>0 && s24[0]<127) pDC->TextOut(10,438,s24,strlen(s24));  
if (s25[0]>0 && s25[0]<127) pDC->TextOut(10,455,s25,strlen(s25));
if (s26[0]>0 && s26[0]<127) pDC->TextOut(10,472,s26,strlen(s26));
if (s27[0]>0 && s27[0]<127) pDC->TextOut(10,489,s27,strlen(s27));
if (s28[0]>0 && s28[0]<127) pDC->TextOut(10,506,s28,strlen(s28));  
if (s29[0]>0 && s29[0]<127) pDC->TextOut(10,523,s29,strlen(s29));  
if (s30[0]>0 && s30[0]<127) pDC->TextOut(10,540,s30,strlen(s30));
if (s31[0]>0 && s31[0]<127) pDC->TextOut(10,557,s31,strlen(s31));
if (s32[0]>0 && s32[0]<127) pDC->TextOut(10,574,s32,strlen(s32));
if (s33[0]>0 && s33[0]<127) pDC->TextOut(10,591,s33,strlen(s33));
if (s34[0]>0 && s34[0]<127) pDC->TextOut(10,608,s34,strlen(s34));  
if (s35[0]>0 && s35[0]<127) pDC->TextOut(10,625,s35,strlen(s35));
if (s36[0]>0 && s36[0]<127) pDC->TextOut(10,642,s36,strlen(s36));
if (s37[0]>0 && s37[0]<127) pDC->TextOut(10,659,s37,strlen(s37));
if (s38[0]>0 && s38[0]<127) pDC->TextOut(10,676,s38,strlen(s38));  
if (s39[0]>0 && s39[0]<127) pDC->TextOut(10,693,s39,strlen(s39));  
if (s40[0]>0 && s40[0]<127) pDC->TextOut(10,710,s40,strlen(s40));
if (s41[0]>0 && s41[0]<127) pDC->TextOut(10,727,s41,strlen(s41));
if (s42[0]>0 && s42[0]<127) pDC->TextOut(10,744,s42,strlen(s42));
if (s43[0]>0 && s43[0]<127) pDC->TextOut(10,761,s43,strlen(s43));
if (s44[0]>0 && s44[0]<127) pDC->TextOut(10,778,s44,strlen(s44));  
if (s45[0]>0 && s45[0]<127) pDC->TextOut(10,795,s45,strlen(s45));
if (s46[0]>0 && s46[0]<127) pDC->TextOut(10,812,s46,strlen(s46));
if (s47[0]>0 && s47[0]<127) pDC->TextOut(10,829,s47,strlen(s47));
if (s48[0]>0 && s48[0]<127) pDC->TextOut(10,846,s48,strlen(s48));  
if (s49[0]>0 && s49[0]<127) pDC->TextOut(10,863,s49,strlen(s49));  
if (s50[0]>0 && s50[0]<127) pDC->TextOut(10,880,s50,strlen(s50));
if (s51[0]>0 && s51[0]<127) pDC->TextOut(10,897,s51,strlen(s51));
if (s52[0]>0 && s52[0]<127) pDC->TextOut(10,914,s52,strlen(s52));
if (s53[0]>0 && s53[0]<127) pDC->TextOut(10,931,s53,strlen(s53));
if (s54[0]>0 && s54[0]<127) pDC->TextOut(10,948,s54,strlen(s54));  
if (s55[0]>0 && s55[0]<127) pDC->TextOut(10,965,s55,strlen(s55));
if (s56[0]>0 && s56[0]<127) pDC->TextOut(10,982,s56,strlen(s56));
if (s57[0]>0 && s57[0]<127) pDC->TextOut(10,999,s57,strlen(s57));
if (s58[0]>0 && s58[0]<127) pDC->TextOut(10,1016,s58,strlen(s58));  
if (s59[0]>0 && s59[0]<127) pDC->TextOut(10,1033,s59,strlen(s59));  
if (s60[0]>0 && s60[0]<127) pDC->TextOut(10,1050,s60,strlen(s60));
if (s61[0]>0 && s61[0]<127) pDC->TextOut(10,1067,s61,strlen(s61));
if (s62[0]>0 && s62[0]<127) pDC->TextOut(10,1084,s62,strlen(s62));
if (s63[0]>0 && s63[0]<127) pDC->TextOut(10,1101,s63,strlen(s63));
if (s64[0]>0 && s64[0]<127) pDC->TextOut(10,1118,s64,strlen(s64));  
if (s65[0]>0 && s65[0]<127) pDC->TextOut(10,1135,s65,strlen(s65));
if (s66[0]>0 && s66[0]<127) pDC->TextOut(10,1152,s66,strlen(s66));
if (s67[0]>0 && s67[0]<127) pDC->TextOut(10,1169,s67,strlen(s67));
if (s68[0]>0 && s68[0]<127) pDC->TextOut(10,1186,s68,strlen(s68));  
if (s69[0]>0 && s69[0]<127) pDC->TextOut(10,1203,s69,strlen(s69));  
if (s70[0]>0 && s70[0]<127) pDC->TextOut(10,1220,s70,strlen(s70));
if (s71[0]>0 && s71[0]<127) pDC->TextOut(10,1237,s71,strlen(s71));
if (s72[0]>0 && s72[0]<127) pDC->TextOut(10,1254,s72,strlen(s72));
if (s73[0]>0 && s73[0]<127) pDC->TextOut(10,1271,s73,strlen(s73));
if (s74[0]>0 && s74[0]<127) pDC->TextOut(10,1288,s74,strlen(s74));  
if (s75[0]>0 && s75[0]<127) pDC->TextOut(10,1305,s75,strlen(s75));
if (s76[0]>0 && s76[0]<127) pDC->TextOut(10,1322,s76,strlen(s76));
if (s77[0]>0 && s77[0]<127) pDC->TextOut(10,1339,s77,strlen(s77));
if (s78[0]>0 && s78[0]<127) pDC->TextOut(10,1356,s78,strlen(s78));  
if (s79[0]>0 && s79[0]<127) pDC->TextOut(10,1373,s79,strlen(s79));  
if (s80[0]>0 && s80[0]<127) pDC->TextOut(10,1390,s80,strlen(s80));
if (s81[0]>0 && s81[0]<127) pDC->TextOut(10,1407,s81,strlen(s81));
if (s82[0]>0 && s82[0]<127) pDC->TextOut(10,1424,s82,strlen(s82));
if (s83[0]>0 && s83[0]<127) pDC->TextOut(10,1441,s83,strlen(s83));
if (s84[0]>0 && s84[0]<127) pDC->TextOut(10,1458,s84,strlen(s84));  
if (s85[0]>0 && s85[0]<127) pDC->TextOut(10,1475,s85,strlen(s85));
if (s86[0]>0 && s86[0]<127) pDC->TextOut(10,1492,s86,strlen(s86));
if (s87[0]>0 && s87[0]<127) pDC->TextOut(10,1509,s87,strlen(s87));
if (s88[0]>0 && s88[0]<127) pDC->TextOut(10,1526,s88,strlen(s88));  
if (s89[0]>0 && s89[0]<127) pDC->TextOut(10,1543,s89,strlen(s89));  
if (s90[0]>0 && s90[0]<127) pDC->TextOut(10,1560,s90,strlen(s90));
if (s91[0]>0 && s91[0]<127) pDC->TextOut(10,1577,s91,strlen(s91));
if (s92[0]>0 && s92[0]<127) pDC->TextOut(10,1594,s92,strlen(s92));
if (s93[0]>0 && s93[0]<127) pDC->TextOut(10,1611,s93,strlen(s93));
if (s94[0]>0 && s94[0]<127) pDC->TextOut(10,1628,s94,strlen(s94));  
if (s95[0]>0 && s95[0]<127) pDC->TextOut(10,1645,s95,strlen(s95));
if (s96[0]>0 && s96[0]<127) pDC->TextOut(10,1662,s96,strlen(s96));
if (s97[0]>0 && s97[0]<127) pDC->TextOut(10,1679,s97,strlen(s97));
if (s98[0]>0 && s98[0]<127) pDC->TextOut(10,1696,s98,strlen(s98));  
if (s99[0]>0 && s99[0]<127) pDC->TextOut(10,1713,s99,strlen(s99));  
if (s100[0]>0 && s100[0]<127) pDC->TextOut(10,1730,s100,strlen(s100));
if (s101[0]>0 && s101[0]<127) pDC->TextOut(10,1747,s101,strlen(s101));
if (s102[0]>0 && s102[0]<127) pDC->TextOut(10,1764,s102,strlen(s102));
if (s103[0]>0 && s103[0]<127) pDC->TextOut(10,1781,s103,strlen(s103));
if (s104[0]>0 && s104[0]<127) pDC->TextOut(10,1798,s104,strlen(s104));  
if (s105[0]>0 && s105[0]<127) pDC->TextOut(10,1815,s105,strlen(s105));
if (s106[0]>0 && s106[0]<127) pDC->TextOut(10,1832,s106,strlen(s106));
if (s107[0]>0 && s107[0]<127) pDC->TextOut(10,1849,s107,strlen(s107));
if (s108[0]>0 && s108[0]<127) pDC->TextOut(10,1866,s108,strlen(s108));  
if (s109[0]>0 && s109[0]<127) pDC->TextOut(10,1883,s109,strlen(s109));  
if (s110[0]>0 && s110[0]<127) pDC->TextOut(10,1900,s110,strlen(s110));
if (s111[0]>0 && s111[0]<127) pDC->TextOut(10,1917,s111,strlen(s111));
if (s112[0]>0 && s112[0]<127) pDC->TextOut(10,1934,s112,strlen(s112));
if (s113[0]>0 && s113[0]<127) pDC->TextOut(10,1951,s113,strlen(s113));
if (s114[0]>0 && s114[0]<127) pDC->TextOut(10,1968,s114,strlen(s114));  
if (s115[0]>0 && s115[0]<127) pDC->TextOut(10,1985,s115,strlen(s115));
if (s116[0]>0 && s116[0]<127) pDC->TextOut(10,2002,s116,strlen(s116));
if (s117[0]>0 && s117[0]<127) pDC->TextOut(10,2019,s117,strlen(s117));
if (s118[0]>0 && s118[0]<127) pDC->TextOut(10,2036,s118,strlen(s118));  
if (s119[0]>0 && s119[0]<127) pDC->TextOut(10,2053,s119,strlen(s119));  

}

/////////////////////////////////////////////////////////////////////////////
// CMobymonView printing

BOOL CMobymonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMobymonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
	// TODO: add extra initialization before printing
}

void CMobymonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMobymonView diagnostics

#ifdef _DEBUG
void CMobymonView::AssertValid() const
{
	CView::AssertValid();
}

void CMobymonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMobymonDoc* CMobymonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMobymonDoc)));
	return (CMobymonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMobymonView message handlers

void CMobymonView::OnConnect() 
{
DWORD error;
BOOL fsuccess; 


// Has the COM port already been set up //
if (comportsetup==FALSE) 
 { 
 comselect dlg;
 com_port=0;
 dlgrpt:
 if (dlg.DoModal()==IDOK)
  { 
  // Connect to COM1 //
  if (com_port==1) hcom=CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
  // Connect to COM2 //
  if (com_port==2) hcom=CreateFile("COM2",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
  // Connect to COM3 //
  if (com_port==3) hcom=CreateFile("COM3",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
  // Connect to COM4 //
  if (com_port==4) hcom=CreateFile("COM4",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
  }
 
 // User hasn't selected a COM port //
 if (com_port==0) goto dlgrpt;

 if (hcom==INVALID_HANDLE_VALUE)
  {
  char err[50];
  error=GetLastError();
  sprintf(err,"CreateFile error#%d",error);
  MessageBox(err,"Error !",MB_OK|MB_ICONEXCLAMATION);
  exit(1);
  }

 // Get Default setup //
 fsuccess=GetCommState(hcom,&dcb);

 if (!fsuccess)
  {
  char err[50];
  error=GetLastError();
  sprintf(err,"GetCommState error#%d",error);
  MessageBox(err,"Error !",MB_OK|MB_ICONEXCLAMATION);
  exit(1);
  }

 // Set the comms parameters //
 dcb.BaudRate= CBR_19200;
 dcb.ByteSize= 8;
 dcb.Parity= NOPARITY;
 dcb.StopBits= ONESTOPBIT;
 dcb.fRtsControl= RTS_CONTROL_HANDSHAKE;
 dcb.fInX= FALSE;
 dcb.fOutX= FALSE;
 dcb.fOutxCtsFlow= FALSE;
 // This needs setting or we can get strange errors with NT //
 dcb.fAbortOnError=FALSE;

 fsuccess=SetCommState(hcom,&dcb);

 if (!fsuccess)
  {
  char err[50];
  error=GetLastError();
  sprintf(err,"SetCommState error#%d",error);
  MessageBox(err,"Error !",MB_OK|MB_ICONEXCLAMATION);
  exit(1);
  }

 }
// Clear the TX & RX streams //
fsuccess=PurgeComm(hcom,PURGE_RXCLEAR);

if (!fsuccess)
 {
 char err[50];
 error=GetLastError();
 sprintf(err,"Purge RX error#%d",error);
 MessageBox(err,"Error !",MB_OK|MB_ICONEXCLAMATION);
 exit(1);
 }

fsuccess=PurgeComm(hcom,PURGE_TXCLEAR);

if (!fsuccess)
 {
 char err[50];
 error=GetLastError();
 sprintf(err,"Purge TX error#%d",error);
 MessageBox(err,"Error !",MB_OK|MB_ICONEXCLAMATION);
 exit(1);
 }

// Change the cursor into an hourglass // 
HCURSOR hWait;
hWait=LoadCursor(NULL,IDC_WAIT);
HCURSOR hOldCrsr=SetCursor(hWait);

// Clear All Variables //
reset_variables ();

if (base_mon==TRUE) 
 {
 head_rxed=FALSE;
 send(66);
 }
else 
 {
 head_rxed=TRUE;
 send(77);
 }

// Check the RS232 link //
strcpy(id,"Testing RS232 Link ..");
::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
SendMessage(WM_PAINT,0,0);

if (linkcheck()==FALSE)
 {
 strcpy(id,"ERROR: RS232 Link Failure !");
 ::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
 // Return the cursor to normal //
 ::SetCursor(hOldCrsr);
 // Close the file created for the serial port //
 CloseHandle(hcom);
 return;
 }

if (base_mon==TRUE) strcpy(id,"RS232 Link is OK Now Searching For a Valid Head ");
 else strcpy(id,"Monitoring Mobiles");
::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
SendMessage(WM_PAINT,0,0);

if (valid_head()==FALSE)
 {
 strcpy(id,"ERROR: Not receiving valid Mobitex data !");
 ::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
  // Return the cursor to normal //
 ::SetCursor(hOldCrsr);
 // Close the file created for the serial port //
 CloseHandle(hcom);
 return;
 }

// Only do this if monitoring base side //
if (base_mon==TRUE)
 {
 strcpy(id,"Valid Head Received Radio Link OK ");
 ::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
 SendMessage(WM_PAINT,0,0);
 }

// Return the cursor to normal //
::SetCursor(hOldCrsr);

// Work out the scrambling sequence //
scramble_sequence();

comportsetup=TRUE;

// Set the timer to every 100ms //
SetTimer(1,100,NULL);
ready=1;
}

// This executes with WM_TIMER messages //
void CMobymonView::OnTimer(UINT nIDEvent) 
{
CView::OnTimer(nIDEvent);

if (ready==2)
 {
 ready=1;
 ::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
 }

}


void CMobymonView::OnStartLogging() 
{
logging=TRUE;
openlogfile();
}

void CMobymonView::OnUpdateStartLogging(CCmdUI* pCmdUI) 
{
if (logging) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);
}

void CMobymonView::OnEndLogging() 
{
logging=FALSE;	
closelogfile();
}

void CMobymonView::OnUpdateEndLogging(CCmdUI* pCmdUI) 
{
if (!logging) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);
}

// Should DATA mpaks be shown ? //
void CMobymonView::OnData() 
{
if (data_show==TRUE) data_show=FALSE;
 else data_show=TRUE;
}

void CMobymonView::OnUpdateData(CCmdUI* pCmdUI) 
{
if (data_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should HPDATA (Gateway) mpaks be shown ? //
void CMobymonView::OnHpdataGateway() 
{
if (hpdata_gateway_show==TRUE) hpdata_gateway_show=FALSE;
 else hpdata_gateway_show=TRUE;		
}

void CMobymonView::OnUpdateHpdataGateway(CCmdUI* pCmdUI) 
{
if (hpdata_gateway_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should HPDATA (Messaging) mpaks be shown ? //
void CMobymonView::OnHpdataMessaging() 
{
if (hpdata_messaging_show==TRUE) hpdata_messaging_show=FALSE;
 else hpdata_messaging_show=TRUE;	
}

void CMobymonView::OnUpdateHpdataMessaging(CCmdUI* pCmdUI) 
{
if (hpdata_messaging_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should HPDATA (MTP/1) mpaks be shown ? //
void CMobymonView::OnHpdataMtp1() 
{
if (hpdata_mtp1_show==TRUE) hpdata_mtp1_show=FALSE;
 else hpdata_mtp1_show=TRUE;	
}

void CMobymonView::OnUpdateHpdataMtp1(CCmdUI* pCmdUI) 
{
if (hpdata_mtp1_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should HPDATA (RAMP) mpaks be shown ? //
void CMobymonView::OnHpdataRamp() 
{
if (hpdata_ramp_show==TRUE) hpdata_ramp_show=FALSE;
 else hpdata_ramp_show=TRUE;
}

void CMobymonView::OnUpdateHpdataRamp(CCmdUI* pCmdUI) 
{
if (hpdata_ramp_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should HPDATA (RNM) mpaks be shown ? //
void CMobymonView::OnHpdataRnm() 
{
if (hpdata_rnm_show==TRUE) hpdata_rnm_show=FALSE;
 else hpdata_rnm_show=TRUE;		
}

void CMobymonView::OnUpdateHpdataRnm(CCmdUI* pCmdUI) 
{
if (hpdata_rnm_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);
}

// Should HPDATA (User) mpaks be shown ? //
void CMobymonView::OnHpdataUser() 
{
if (hpdata_user_show==TRUE) hpdata_user_show=FALSE;
 else hpdata_user_show=TRUE;	
}

void CMobymonView::OnUpdateHpdataUser(CCmdUI* pCmdUI) 
{
if (hpdata_user_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should TIME mpaks be shown ? //
void CMobymonView::OnTime() 
{
if (time_show==TRUE) time_show=FALSE;
 else time_show=TRUE;	
}

void CMobymonView::OnUpdateTime(CCmdUI* pCmdUI) 
{
if (time_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);		
}

// Should FLEXLIST mpaks be shown ? //
void CMobymonView::OnFlexlist() 
{
if (flexlist_show==TRUE) flexlist_show=FALSE;
 else flexlist_show=TRUE;			
}

void CMobymonView::OnUpdateFlexlist(CCmdUI* pCmdUI) 
{
if (flexlist_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);
}

// Should GROUPLIST mpaks be shown ? //
void CMobymonView::OnGrouplist() 
{
if (grouplist_show==TRUE) grouplist_show=FALSE;
 else grouplist_show=TRUE;		
}

void CMobymonView::OnUpdateGrouplist(CCmdUI* pCmdUI) 
{
if (grouplist_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should STATUS mpaks be shown ? //
void CMobymonView::OnStatus() 
{
if (status_show==TRUE) status_show=FALSE;
 else status_show=TRUE;	
}

void CMobymonView::OnUpdateStatus(CCmdUI* pCmdUI) 
{
if (status_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);
}

// Should ESNREQ mpaks be shown ? //
void CMobymonView::OnEsnreq() 
{
if (esnreq_show==TRUE) esnreq_show=FALSE;
 else esnreq_show=TRUE;	
}

void CMobymonView::OnUpdateEsnreq(CCmdUI* pCmdUI) 
{
if (esnreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);
}

// Should TEXT mpaks be shown ? //
void CMobymonView::OnText() 
{
if (text_show==TRUE) text_show=FALSE;
 else text_show=TRUE;		
}

void CMobymonView::OnUpdateText(CCmdUI* pCmdUI) 
{
if (text_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should EXTPAK mpaks be shown ? //
void CMobymonView::OnExtpak() 
{
if (extpak_show==TRUE) extpak_show=FALSE;
 else extpak_show=TRUE;		
}

void CMobymonView::OnUpdateExtpak(CCmdUI* pCmdUI) 
{
if (extpak_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);		
}

// Should INFOREQ mpaks be shown ? //
void CMobymonView::OnInforeq() 
{
if (inforeq_show==TRUE) inforeq_show=FALSE;
 else inforeq_show=TRUE;			
}

void CMobymonView::OnUpdateInforeq(CCmdUI* pCmdUI) 
{
if (inforeq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);		
}

// Should DIE mpaks be shown ? //
void CMobymonView::OnDie() 
{
if (die_show==TRUE) die_show=FALSE;
 else die_show=TRUE;			
}

void CMobymonView::OnUpdateDie(CCmdUI* pCmdUI) 
{
if (die_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should LIVE mpaks be shown ? //
void CMobymonView::OnLive() 
{
if (live_show==TRUE) live_show=FALSE;
 else live_show=TRUE;			
}

void CMobymonView::OnUpdateLive(CCmdUI* pCmdUI) 
{
if (live_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should LOGINGRA mpaks be shown ? //
void CMobymonView::OnLogingra() 
{
if (logingra_show==TRUE) logingra_show=FALSE;
 else logingra_show=TRUE;			
}

void CMobymonView::OnUpdateLogingra(CCmdUI* pCmdUI) 
{
if (logingra_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should LOGINREF mpaks be shown ? //
void CMobymonView::OnLoginref() 
{
if (loginref_show==TRUE) loginref_show=FALSE;
 else loginref_show=TRUE;			
}

void CMobymonView::OnUpdateLoginref(CCmdUI* pCmdUI) 
{
if (loginref_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should LOGOUTORD mpaks be shown ? //
void CMobymonView::OnLogoutord() 
{
if (logoutord_show==TRUE) logoutord_show=FALSE;
 else logoutord_show=TRUE;			
}

void CMobymonView::OnUpdateLogoutord(CCmdUI* pCmdUI) 
{
if (logoutord_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Should FLEXREQ mpaks be shown ? //
void CMobymonView::OnFlexreq() 
{
if (flexreq_show==TRUE) flexreq_show=FALSE;
 else flexreq_show=TRUE;			
}

void CMobymonView::OnUpdateFlexreq(CCmdUI* pCmdUI) 
{
if (flexreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Should ROAMORD mpaks be shown ? //
void CMobymonView::OnRoamord() 
{
if (roamord_show==TRUE) roamord_show=FALSE;
 else roamord_show=TRUE;				
}

void CMobymonView::OnUpdateRoamord(CCmdUI* pCmdUI) 
{
if (roamord_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Should AREALIST mpaks be shown ? //
void CMobymonView::OnArealist() 
{
if (arealist_show==TRUE) arealist_show=FALSE;
 else arealist_show=TRUE;	
}

void CMobymonView::OnUpdateArealist(CCmdUI* pCmdUI) 
{
if (arealist_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);		
}

// Should SOS mpaks be shown ? //
void CMobymonView::OnSos() 
{
if (sos_show==TRUE) sos_show=FALSE;
 else sos_show=TRUE;		
}

void CMobymonView::OnUpdateSos(CCmdUI* pCmdUI) 
{
if (sos_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should SOSINFO mpaks be shown ? //
void CMobymonView::OnSosinfo() 
{
if (sosinfo_show==TRUE) sosinfo_show=FALSE;
 else sosinfo_show=TRUE;			
}

void CMobymonView::OnUpdateSosinfo(CCmdUI* pCmdUI) 
{
if (sosinfo_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should SOSACK mpaks be shown ? //
void CMobymonView::OnSosack() 
{
if (sosack_show==TRUE) sosack_show=FALSE;
 else sosack_show=TRUE;			
}

void CMobymonView::OnUpdateSosack(CCmdUI* pCmdUI) 
{
if (sosack_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should SOSCONFAST mpaks be shown ? //
void CMobymonView::OnSosconfast() 
{
if (sosconfast_show==TRUE) sosconfast_show=FALSE;
 else sosconfast_show=TRUE;				
}

void CMobymonView::OnUpdateSosconfast(CCmdUI* pCmdUI) 
{
if (sosconfast_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Should SOSCONREQ mpaks be shown ? //
void CMobymonView::OnSosconreq() 
{
if (sosconreq_show==TRUE) sosconreq_show=FALSE;
 else sosconreq_show=TRUE;					
}

void CMobymonView::OnUpdateSosconreq(CCmdUI* pCmdUI) 
{
if (sosconreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);	
}

// Should ADDCONFAST mpaks be shown ? //
void CMobymonView::OnAddconfast() 
{
if (addconfast_show==TRUE) addconfast_show=FALSE;
 else addconfast_show=TRUE;					
}

void CMobymonView::OnUpdateAddconfast(CCmdUI* pCmdUI) 
{
if (addconfast_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);		
}

// Should CONFAST mpaks be shown ? //
void CMobymonView::OnConfast() 
{
if (confast_show==TRUE) confast_show=FALSE;
 else confast_show=TRUE;						
}

void CMobymonView::OnUpdateConfast(CCmdUI* pCmdUI) 
{
if (confast_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should CLOOPOFF mpaks be shown ? //
void CMobymonView::OnCloopoff() 
{
if (cloopoff_show==TRUE) cloopoff_show=FALSE;
 else cloopoff_show=TRUE;							
}

void CMobymonView::OnUpdateCloopoff(CCmdUI* pCmdUI) 
{
if (cloopoff_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Should CLOOPON mpaks be shown ? //
void CMobymonView::OnCloopon() 
{
if (cloopon_show==TRUE) cloopon_show=FALSE;
 else cloopon_show=TRUE;								
}

void CMobymonView::OnUpdateCloopon(CCmdUI* pCmdUI) 
{
if (cloopon_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Should DISCON mpaks be shown ? //
void CMobymonView::OnDiscon() 
{
if (discon_show==TRUE) discon_show=FALSE;
 else discon_show=TRUE;									
}

void CMobymonView::OnUpdateDiscon(CCmdUI* pCmdUI) 
{
if (discon_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);					
}

// Should CONORD mpaks be shown ? //
void CMobymonView::OnConord() 
{
if (conord_show==TRUE) conord_show=FALSE;
 else conord_show=TRUE;											
}

void CMobymonView::OnUpdateConord(CCmdUI* pCmdUI) 
{
if (conord_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);					
}

// Should CONGRA mpaks be shown ? //
void CMobymonView::OnCongra() 
{
if (congra_show==TRUE) congra_show=FALSE;
 else congra_show=TRUE;											
}

void CMobymonView::OnUpdateCongra(CCmdUI* pCmdUI) 
{
if (congra_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);						
}

// Should CONREQ mpaks be shown ? //
void CMobymonView::OnConreq() 
{
if (conreq_show==TRUE) conreq_show=FALSE;
 else conreq_show=TRUE;											
}

void CMobymonView::OnUpdateConreq(CCmdUI* pCmdUI) 
{
if (conreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);							
}

// Should ADDCONREQ mpaks be shown ? //
void CMobymonView::OnAddconreq() 
{
if (addconreq_show==TRUE) addconreq_show=FALSE;
 else addconreq_show=TRUE;											
}

void CMobymonView::OnUpdateAddconreq(CCmdUI* pCmdUI) 
{
if (addconreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);								
}

// Show the percentage of bad blocks //
void CMobymonView::OnSignalquality() 
{
float bad;
char tmp[100],per[100];

if (total_blocks==0) strcpy(per,"No Blocks have been received yet !");
 else 
 {
 bad=(bad_blocks/total_blocks)*100;
 sprintf(per,"%0.1f",bad);
 strcpy(tmp,"% of Received Blocks Had Errors");
 strcat(per,tmp);
 }

MessageBox(per,"MobyMon",MB_ICONINFORMATION|MB_OK);
}

// Shut down the application //
void CMobymonView::OnAppExit() 
{
if (MessageBox("Do you wish to leave this application?","MobyMon",MB_YESNO|MB_ICONSTOP)==IDYES)
 {
 if (logging) OnEndLogging();	
 if (com_port>0) CloseHandle(hcom);
 ASSERT(AfxGetApp()->m_pMainWnd!=NULL);
 AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
 }
}

// Should DATA mpaks appear as ASCII //
void CMobymonView::OnDataAsAscii() 
{
if (data_ascii_show==TRUE) data_ascii_show=FALSE;
 else data_ascii_show=TRUE;	
}

void CMobymonView::OnUpdateDataAsAscii(CCmdUI* pCmdUI) 
{
if (data_ascii_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);									
}


// Should HPDATA 130 messages be displayed decoded //
void CMobymonView::On130Decode() 
{
if (hpdata_130_show==TRUE) hpdata_130_show=FALSE;
 else hpdata_130_show=TRUE;	
}

void CMobymonView::OnUpdate130Decode(CCmdUI* pCmdUI) 
{
if (hpdata_130_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);										
}


// Should the program be in debug mode //
void CMobymonView::OnDebug() 
{
if (debug==TRUE) debug=FALSE;
 else debug=TRUE;	
	
}

void CMobymonView::OnUpdateDebug(CCmdUI* pCmdUI) 
{
if (debug==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);											
}

// Should EXTPAK's be displayed as ASCII ? //
void CMobymonView::OnExtpakAscii() 
{
if (extpak_ascii_show==TRUE) extpak_ascii_show=FALSE;
 else extpak_ascii_show=TRUE;	
}

void CMobymonView::OnUpdateExtpakAscii(CCmdUI* pCmdUI) 
{
if (extpak_ascii_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);												
}

// Should SOS's be displayed as ASCII ? //
void CMobymonView::OnSosAscii() 
{
if (sos_ascii_show==TRUE) sos_ascii_show=FALSE;
 else sos_ascii_show=TRUE;		
}

void CMobymonView::OnUpdateSosAscii(CCmdUI* pCmdUI) 
{
if (sos_ascii_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);													
}

// Should SOSINFO's be displayed as ASCII ? //
void CMobymonView::OnSosinfoAscii() 
{
if (sosinfo_ascii_show==TRUE) sosinfo_ascii_show=FALSE;
 else sosinfo_ascii_show=TRUE;			
}

void CMobymonView::OnUpdateSosinfoAscii(CCmdUI* pCmdUI) 
{
if (sosinfo_ascii_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);														
}

// Should the MPAK's traffic state be displayed ? //
void CMobymonView::OnTrafficState() 
{
if (display_traffic_state==TRUE) display_traffic_state=FALSE;
 else display_traffic_state=TRUE;				
}

void CMobymonView::OnUpdateTrafficState(CCmdUI* pCmdUI) 
{
if (display_traffic_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);															
}

// Should BUSY state MPAKs be ignored ? //
void CMobymonView::OnIgnoreBusy() 
{
if (ignore_busy_state==TRUE) ignore_busy_state=FALSE;
 else ignore_busy_state=TRUE;				
}

void CMobymonView::OnUpdateIgnoreBusy(CCmdUI* pCmdUI) 
{
if (ignore_busy_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																
}

// Should CONGEST MPAK's be ignored ? //
void CMobymonView::OnIgnoreCongest() 
{
if (ignore_congest_state==TRUE) ignore_congest_state=FALSE;
 else ignore_congest_state=TRUE;					
}

void CMobymonView::OnUpdateIgnoreCongest(CCmdUI* pCmdUI) 
{
if (ignore_congest_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																	
}

// Should ERROR MPAK's be ignored ? //
void CMobymonView::OnIgnoreError() 
{
if (ignore_error_state==TRUE) ignore_error_state=FALSE;
 else ignore_error_state=TRUE;						
}

void CMobymonView::OnUpdateIgnoreError(CCmdUI* pCmdUI) 
{
if (ignore_error_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																		
}

// Should FROM_MAIL MPAK's be ignored ? //
void CMobymonView::OnIgnoreFromMail() 
{
if (ignore_from_mail_state==TRUE) ignore_from_mail_state=FALSE;
 else ignore_from_mail_state=TRUE;							
}

void CMobymonView::OnUpdateIgnoreFromMail(CCmdUI* pCmdUI) 
{
if (ignore_from_mail_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																			
}

// Should ILLEGAL MPAK's be ignored ? //
void CMobymonView::OnIgnoreIllegal() 
{
if (ignore_illegal_state==TRUE) ignore_illegal_state=FALSE;
 else ignore_illegal_state=TRUE;								
}

void CMobymonView::OnUpdateIgnoreIllegal(CCmdUI* pCmdUI) 
{
if (ignore_illegal_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																				
}

// Should IN_MAIL MPAK's be ignored ? //
void CMobymonView::OnIgnoreInMail() 
{
if (ignore_in_mail_state==TRUE) ignore_in_mail_state=FALSE;
 else ignore_in_mail_state=TRUE;									
}

void CMobymonView::OnUpdateIgnoreInMail(CCmdUI* pCmdUI) 
{
if (ignore_in_mail_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																					
}

// Should NO_TRANSFER MPAK's be ignored ? //
void CMobymonView::OnIgnoreNoTranser() 
{
if (ignore_no_transfer_state==TRUE) ignore_no_transfer_state=FALSE;
 else ignore_no_transfer_state=TRUE;										
}

void CMobymonView::OnUpdateIgnoreNoTranser(CCmdUI* pCmdUI) 
{
if (ignore_no_transfer_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																						
}

// Should OK MPAK's be ignored ? //
void CMobymonView::OnIgnoreOk() 
{
if (ignore_ok_state==TRUE) ignore_ok_state=FALSE;
 else ignore_ok_state=TRUE;											
}

void CMobymonView::OnUpdateIgnoreOk(CCmdUI* pCmdUI) 
{
if (ignore_ok_state==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																							
}

// What is this machines Host Name ? //
void CMobymonView::OnHostname() 
{
HOSTENT *host;
int err;
char tmp[200],host_name[100];

err=gethostname(host_name,100); 
host=gethostbyname(host_name);

// Do we have an error ? //
if (host==NULL)
 {
 char ee[30];
 err=WSAGetLastError();
 strcpy(tmp,"Error : ");
 if (err==10003) strcpy(ee,"WSANOTINITIALISED");
 if (err==10050) strcpy(ee,"WSAENETDOWN");
 if (err==11001) strcpy(ee,"WSAHOST_NOT_FOUND");
 if (err==11002) strcpy(ee,"WSATRY_AGAIN");
 if (err==11003) strcpy(ee,"WSANO_RECOVERY");
 if (err==11004) strcpy(ee,"WSANO_DATA");
 if (err==10036) strcpy(ee,"WSAEINPROGRESS");
 if (err==10004) strcpy(ee,"WSAEINTR");
 strcat(tmp,ee);
 }
else
 {
 strcpy(tmp,"This machines address is ");
 strcat(tmp,host->h_name);
 }

MessageBox(tmp,"MobyMon",MB_ICONINFORMATION|MB_OK);	
}

// Does the user want to see sequence numbers ? //
void CMobymonView::OnSequence() 
{
if (sequence_display==TRUE) sequence_display=FALSE;
 else sequence_display=TRUE;												
}

void CMobymonView::OnUpdateSequence(CCmdUI* pCmdUI) 
{
if (sequence_display==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																								
}

// Does the user wish to see RE indicators ? //
void CMobymonView::OnReDisplay() 
{
if (re_display==TRUE) re_display=FALSE;
 else re_display=TRUE;														
}

void CMobymonView::OnUpdateReDisplay(CCmdUI* pCmdUI) 
{
if (re_display==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																										
}

// View Help Files //
void CMobymonView::OnHelp() 
{
::WinHelp(GetSafeHwnd(),"MOBYMON.HLP",HELP_CONTENTS,0);	
}

// Remote Connect //
void CMobymonView::OnRemoteConnect() 
{
remote dlg;

if (dlg.DoModal()==IDOK)
 { 
 
 }
  
}

void CMobymonView::OnUpdateRemoteConnect(CCmdUI* pCmdUI) 
{
if (am_a_terminal==TRUE || am_a_server==TRUE) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);
}

// The user wants to disconnect from a server //
void CMobymonView::OnDisconnect() 
{

}

void CMobymonView::OnUpdateDisconnect(CCmdUI* pCmdUI) 
{
if (am_a_terminal==FALSE || am_a_server==TRUE) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);	
}

// User wants to monitor base stations //
void CMobymonView::OnMonBase() 
{
if (base_mon==FALSE)	
 {
 base_mon=TRUE;
 OnConnect ();
 }	
}

void CMobymonView::OnUpdateMonBase(CCmdUI* pCmdUI) 
{
if (base_mon==FALSE) pCmdUI->SetCheck(0);
 else pCmdUI->SetCheck(1);	
}

// User wants to monitor mobiles //
void CMobymonView::OnMonMob() 
{
if (base_mon==TRUE)	
 {
 base_mon=FALSE;
 strcpy(id,"Monitoring Mobiles");
 ::InvalidateRect(GetSafeHwnd(),NULL,TRUE);
 OnConnect ();
 }
}

void CMobymonView::OnUpdateMonMob(CCmdUI* pCmdUI) 
{
if (base_mon==TRUE) pCmdUI->SetCheck(0);
 else pCmdUI->SetCheck(1);		
}

// Does the user want to see LOGINREQ's //
void CMobymonView::OnLoginreq() 
{
if (loginreq_show==TRUE) loginreq_show=FALSE;
 else loginreq_show=TRUE;	
}

void CMobymonView::OnUpdateLoginreq(CCmdUI* pCmdUI) 
{
if (loginreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);			
}

// Does the user want to see LOGOUT's //
void CMobymonView::OnLogout() 
{
if (logout_show==TRUE) logout_show=FALSE;
 else logout_show=TRUE;		
}

void CMobymonView::OnUpdateLogout(CCmdUI* pCmdUI) 
{
if (logout_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see BORN's //
void CMobymonView::OnBorn() 
{
if (born_show==TRUE) born_show=FALSE;
 else born_show=TRUE;		
}

void CMobymonView::OnUpdateBorn(CCmdUI* pCmdUI) 
{
if (born_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see ACTIVE's //
void CMobymonView::OnActive() 
{
if (active_show==TRUE) active_show=FALSE;
 else active_show=TRUE;		
}

void CMobymonView::OnUpdateActive(CCmdUI* pCmdUI) 
{
if (active_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see INACTIVE's //
void CMobymonView::OnInactive() 
{
if (inactive_show==TRUE) inactive_show=FALSE;
 else inactive_show=TRUE;			
}

void CMobymonView::OnUpdateInactive(CCmdUI* pCmdUI) 
{
if (inactive_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see ROAM's //
void CMobymonView::OnRoam() 
{
if (roam_show==TRUE) roam_show=FALSE;
 else roam_show=TRUE;			
}

void CMobymonView::OnUpdateRoam(CCmdUI* pCmdUI) 
{
if (roam_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see VICESOSRX's //
void CMobymonView::OnVicesosrx() 
{
if (vicesosrx_show==TRUE) vicesosrx_show=FALSE;
 else vicesosrx_show=TRUE;			
}

void CMobymonView::OnUpdateVicesosrx(CCmdUI* pCmdUI) 
{
if (vicesosrx_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see SOSRX's //
void CMobymonView::OnSosrx() 
{
if (sosrx_show==TRUE) sosrx_show=FALSE;
 else sosrx_show=TRUE;				
}

void CMobymonView::OnUpdateSosrx(CCmdUI* pCmdUI) 
{
if (sosrx_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see INFO's //
void CMobymonView::OnInfo() 
{
if (info_show==TRUE) info_show=FALSE;
 else info_show=TRUE;				
}

void CMobymonView::OnUpdateInfo(CCmdUI* pCmdUI) 
{
if (info_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see ESNINFO's //
void CMobymonView::OnEsninfo() 
{
if (esninfo_show==TRUE) esninfo_show=FALSE;
 else esninfo_show=TRUE;					
}

void CMobymonView::OnUpdateEsninfo(CCmdUI* pCmdUI) 
{
if (esninfo_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);				
}

// Does the user want to see EXTCONREQ's //
void CMobymonView::OnExconreq() 
{
if (extconreq_show==TRUE) extconreq_show=FALSE;
 else extconreq_show=TRUE;						
}

void CMobymonView::OnUpdateExconreq(CCmdUI* pCmdUI) 
{
if (extconreq_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);					
}

// Does the user want to see CONREA's //
void CMobymonView::OnConrea() 
{
if (conrea_show==TRUE) conrea_show=FALSE;
 else conrea_show=TRUE;							
}

void CMobymonView::OnUpdateConrea(CCmdUI* pCmdUI) 
{
if (conrea_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);						
}

// Does the user want to see LINEON's //
void CMobymonView::OnLineon() 
{
if (lineon_show==TRUE) lineon_show=FALSE;
 else lineon_show=TRUE;							
}

void CMobymonView::OnUpdateLineon(CCmdUI* pCmdUI) 
{
if (lineon_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);						
}

// Does the user want to see LINEOFF's //
void CMobymonView::OnLineoff() 
{
if (lineoff_show==TRUE) lineoff_show=FALSE;
 else lineoff_show=TRUE;							
}

void CMobymonView::OnUpdateLineoff(CCmdUI* pCmdUI) 
{
if (lineoff_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);						
}

// Does the user want to see LINSELS's //
void CMobymonView::OnLinsel() 
{
if (linsel_show==TRUE) linsel_show=FALSE;
 else linsel_show=TRUE;							
}

void CMobymonView::OnUpdateLinsel(CCmdUI* pCmdUI) 
{
if (linsel_show==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);						
}

// Does the user want to use the IGNORE.USR file ? //
void CMobymonView::OnIgnoreUsr() 
{
if (use_exclusive==FALSE)
 {
 if (use_ignore==TRUE) use_ignore=FALSE;
  else use_ignore=TRUE;													
 }
else AfxMessageBox("IGNORE.USR cannot be used when EXCLUSIVE.USR has been selected.",MB_OK|MB_ICONEXCLAMATION,0);
}

void CMobymonView::OnUpdateIgnoreUsr(CCmdUI* pCmdUI) 
{
if (blacklist!=0) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);		

if (use_ignore==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																									
}

// Does the user want to use the EXCLUSIVE.USR file ? //
void CMobymonView::OnExclusiveUsr() 
{
if (use_ignore==FALSE)
 {
 if (use_exclusive==TRUE) use_exclusive=FALSE;
  else use_exclusive=TRUE;													
 }
else AfxMessageBox("EXCLUSIVE.USR cannot be used when IGNORE.USR has been selected.",MB_OK|MB_ICONEXCLAMATION,0);
}

void CMobymonView::OnUpdateExclusiveUsr(CCmdUI* pCmdUI) 
{
if (blacklist!=0) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);		

if (use_exclusive==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																										
}

// User wishes to monitor a single MAN //
void CMobymonView::OnSingleMan() 
{
man_select dlg;
dlg.DoModal();	
}

void CMobymonView::OnUpdateSingleMan(CCmdUI* pCmdUI) 
{
if (use_ignore==TRUE || use_exclusive==TRUE) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);		
}

// Clear the blacklist //
void CMobymonView::OnBlacklistClear() 
{
if (MessageBox("Do you now wish to monitor all MAN's ?","MobyMon",MB_ICONQUESTION|MB_YESNO)==IDYES)
 blacklist=0;
}

void CMobymonView::OnUpdateBlacklistClear(CCmdUI* pCmdUI) 
{
if (blacklist==0) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);			
}

// Firmware information //
void CMobymonView::OnFirmwareInfo() 
{
unsigned int version,serial;
char f1,f2,c,s1,s2;
char info[200],tmp[100];

PurgeComm(hcom,PURGE_RXCLEAR);

// Send a "V" //
send(86);

// Get the info from the decoder //
vrpt:
f1=getchar();
if (f1!=36) goto vrpt;

f1=getchar();
f2=getchar();
c=getchar();
s1=getchar();
s2=getchar();

version=0;
version=f1<<8;
version=version+f2;

serial=0;
serial=s1<<8;
serial=serial+s2;

sprintf(info,"Decoder Firmware Version %d",version);
sprintf(tmp,"%c",c);
strcat(info,tmp);
sprintf(tmp,"\nDecoder Serial Number %d",serial);
strcat(info,tmp);

AfxMessageBox(info,MB_OK|MB_ICONINFORMATION,0);	
}

void CMobymonView::OnUpdateFirmwareInfo(CCmdUI* pCmdUI) 
{
if (ready==0) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);				
}

// Does the user want to check for errors ? //
void CMobymonView::OnErrorChecking() 
{
if (enable_checking==TRUE) 
 {
 enable_checking=FALSE;
 enable_fec=FALSE;
 }
else 
 {	 
 enable_checking=TRUE;
 enable_fec=TRUE;
 }
}

void CMobymonView::OnUpdateErrorChecking(CCmdUI* pCmdUI) 
{
if (enable_checking==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																										
}

// Does the user want FEC //
void CMobymonView::OnFec() 
{
if (enable_fec==TRUE) enable_fec=FALSE;
 else enable_fec=TRUE;		
}

void CMobymonView::OnUpdateFec(CCmdUI* pCmdUI) 
{
// If you don't have error checking you can't have FEC //
if (enable_checking==FALSE) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);				
if (enable_fec==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																										
}


void CMobymonView::OnAbd() 
{
if (display_abd==FALSE) display_abd=TRUE;
 else display_abd=FALSE;	
}

void CMobymonView::OnUpdateAbd(CCmdUI* pCmdUI) 
{
if (display_abd==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																											
}

void CMobymonView::OnAck() 
{
if (display_ack==FALSE) display_ack=TRUE;
 else display_ack=FALSE;		
}

void CMobymonView::OnUpdateAck(CCmdUI* pCmdUI) 
{
if (display_ack==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnAkt() 
{
if (display_akt==FALSE) display_akt=TRUE;
 else display_akt=FALSE;		
}

void CMobymonView::OnUpdateAkt(CCmdUI* pCmdUI) 
{
if (display_akt==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnAtd() 
{
if (display_atd==FALSE) display_atd=TRUE;
 else display_atd=FALSE;		
}

void CMobymonView::OnUpdateAtd(CCmdUI* pCmdUI) 
{
if (display_atd==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																											
}

void CMobymonView::OnAtl() 
{
if (display_atl==FALSE) display_atl=TRUE;
 else display_atl=FALSE;		
}

void CMobymonView::OnUpdateAtl(CCmdUI* pCmdUI) 
{
if (display_atl==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnBkd() 
{
if (display_bkd==FALSE) display_bkd=TRUE;
 else display_bkd=FALSE;		
}

void CMobymonView::OnUpdateBkd(CCmdUI* pCmdUI) 
{
if (display_bkd==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnFri() 
{
if (display_fri==FALSE) display_fri=TRUE;
 else display_fri=FALSE;		
}

void CMobymonView::OnUpdateFri(CCmdUI* pCmdUI) 
{
if (display_fri==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnMrm() 
{
if (display_mrm==FALSE) display_mrm=TRUE;
 else display_mrm=FALSE;		
}

void CMobymonView::OnUpdateMrm(CCmdUI* pCmdUI) 
{
if (display_mrm==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnReb() 
{
if (display_reb==FALSE) display_reb=TRUE;
 else display_reb=FALSE;		
}

void CMobymonView::OnUpdateReb(CCmdUI* pCmdUI) 
{
if (display_reb==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnRes() 
{
if (display_res==FALSE) display_res=TRUE;
 else display_res=FALSE;		
}

void CMobymonView::OnUpdateRes(CCmdUI* pCmdUI) 
{
if (display_res==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnSvp() 
{
if (display_svp==FALSE) display_svp=TRUE;
 else display_svp=FALSE;		
}

void CMobymonView::OnUpdateSvp(CCmdUI* pCmdUI) 
{
if (display_svp==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnTst() 
{
if (display_tst==FALSE) display_tst=TRUE;
 else display_tst=FALSE;		
}

void CMobymonView::OnUpdateTst(CCmdUI* pCmdUI) 
{
if (display_tst==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnNak() 
{
if (display_nak==FALSE) display_nak=TRUE;
 else display_nak=FALSE;		
}

void CMobymonView::OnUpdateNak(CCmdUI* pCmdUI) 
{
if (display_nak==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																												
}

void CMobymonView::OnAbl() 
{
if (display_abl==FALSE) display_abl=TRUE;
 else display_abl=FALSE;			
}

void CMobymonView::OnUpdateAbl(CCmdUI* pCmdUI) 
{
if (display_abl==TRUE) pCmdUI->SetCheck(1);
 else pCmdUI->SetCheck(0);																													
}

// View Surrounding frequencies //
void CMobymonView::OnSystemChannels() 
{
char info[1000],tmp[100];
int a;

strcpy(info,"System Channels ..\n");

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

AfxMessageBox(info,MB_OK|MB_ICONINFORMATION,0);	
}

void CMobymonView::OnUpdateSystemChannels(CCmdUI* pCmdUI) 
{
if (surrounding==0) pCmdUI->Enable(FALSE);
 else pCmdUI->Enable(TRUE);					
}
