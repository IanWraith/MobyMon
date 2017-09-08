// mobymonView.h : interface of the CMobymonView class
//
/////////////////////////////////////////////////////////////////////////////

//class CMobymonView : public CView , public moby
class CMobymonView : public CScrollView , public moby
{

protected: // create from serialization only
	CMobymonView();
	DECLARE_DYNCREATE(CMobymonView)

// Attributes
public:
	CMobymonDoc* GetDocument();
	// Scrolling code below //
	void OnInitialUpdate ();


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMobymonView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMobymonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMobymonView)
	afx_msg void OnConnect();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStartLogging();
	afx_msg void OnUpdateStartLogging(CCmdUI* pCmdUI);
	afx_msg void OnEndLogging();
	afx_msg void OnUpdateEndLogging(CCmdUI* pCmdUI);
	afx_msg void OnData();
	afx_msg void OnUpdateData(CCmdUI* pCmdUI);
	afx_msg void OnHpdataMpt1();
	afx_msg void OnUpdateHpdataMpt1(CCmdUI* pCmdUI);
	afx_msg void OnSignalquality();
	afx_msg void OnTime();
	afx_msg void OnUpdateTime(CCmdUI* pCmdUI);
	afx_msg void OnFlexlist();
	afx_msg void OnUpdateFlexlist(CCmdUI* pCmdUI);
	afx_msg void OnGrouplist();
	afx_msg void OnUpdateGrouplist(CCmdUI* pCmdUI);
	afx_msg void OnStatus();
	afx_msg void OnUpdateStatus(CCmdUI* pCmdUI);
	afx_msg void OnEsnreq();
	afx_msg void OnUpdateEsnreq(CCmdUI* pCmdUI);
	afx_msg void OnText();
	afx_msg void OnUpdateText(CCmdUI* pCmdUI);
	afx_msg void OnExtpak();
	afx_msg void OnUpdateExtpak(CCmdUI* pCmdUI);
	afx_msg void OnInforeq();
	afx_msg void OnUpdateInforeq(CCmdUI* pCmdUI);
	afx_msg void OnDie();
	afx_msg void OnUpdateDie(CCmdUI* pCmdUI);
	afx_msg void OnLive();
	afx_msg void OnUpdateLive(CCmdUI* pCmdUI);
	afx_msg void OnAppExit();
	afx_msg void OnLogingra();
	afx_msg void OnUpdateLogingra(CCmdUI* pCmdUI);
	afx_msg void OnLoginref();
	afx_msg void OnUpdateLoginref(CCmdUI* pCmdUI);
	afx_msg void OnLogoutord();
	afx_msg void OnUpdateLogoutord(CCmdUI* pCmdUI);
	afx_msg void OnFlexreq();
	afx_msg void OnUpdateFlexreq(CCmdUI* pCmdUI);
	afx_msg void OnRoamord();
	afx_msg void OnUpdateRoamord(CCmdUI* pCmdUI);
	afx_msg void OnHpdataGateway();
	afx_msg void OnUpdateHpdataGateway(CCmdUI* pCmdUI);
	afx_msg void OnHpdataMessaging();
	afx_msg void OnUpdateHpdataMessaging(CCmdUI* pCmdUI);
	afx_msg void OnHpdataMtp1();
	afx_msg void OnUpdateHpdataMtp1(CCmdUI* pCmdUI);
	afx_msg void OnHpdataRamp();
	afx_msg void OnUpdateHpdataRamp(CCmdUI* pCmdUI);
	afx_msg void OnHpdataRnm();
	afx_msg void OnUpdateHpdataRnm(CCmdUI* pCmdUI);
	afx_msg void OnHpdataUser();
	afx_msg void OnUpdateHpdataUser(CCmdUI* pCmdUI);
	afx_msg void OnArealist();
	afx_msg void OnUpdateArealist(CCmdUI* pCmdUI);
	afx_msg void OnSos();
	afx_msg void OnUpdateSos(CCmdUI* pCmdUI);
	afx_msg void OnSosinfo();
	afx_msg void OnUpdateSosinfo(CCmdUI* pCmdUI);
	afx_msg void OnSosack();
	afx_msg void OnUpdateSosack(CCmdUI* pCmdUI);
	afx_msg void OnSosconfast();
	afx_msg void OnUpdateSosconfast(CCmdUI* pCmdUI);
	afx_msg void OnSosconreq();
	afx_msg void OnUpdateSosconreq(CCmdUI* pCmdUI);
	afx_msg void OnAddconfast();
	afx_msg void OnUpdateAddconfast(CCmdUI* pCmdUI);
	afx_msg void OnConfast();
	afx_msg void OnUpdateConfast(CCmdUI* pCmdUI);
	afx_msg void OnCloopoff();
	afx_msg void OnUpdateCloopoff(CCmdUI* pCmdUI);
	afx_msg void OnCloopon();
	afx_msg void OnUpdateCloopon(CCmdUI* pCmdUI);
	afx_msg void OnDiscon();
	afx_msg void OnUpdateDiscon(CCmdUI* pCmdUI);
	afx_msg void OnConord();
	afx_msg void OnUpdateConord(CCmdUI* pCmdUI);
	afx_msg void OnCongra();
	afx_msg void OnUpdateCongra(CCmdUI* pCmdUI);
	afx_msg void OnConreq();
	afx_msg void OnUpdateConreq(CCmdUI* pCmdUI);
	afx_msg void OnAddconreq();
	afx_msg void OnUpdateAddconreq(CCmdUI* pCmdUI);
	afx_msg void OnDataAsAscii();
	afx_msg void OnUpdateDataAsAscii(CCmdUI* pCmdUI);
	afx_msg void On130Decode();
	afx_msg void OnUpdate130Decode(CCmdUI* pCmdUI);
	afx_msg void OnDebug();
	afx_msg void OnUpdateDebug(CCmdUI* pCmdUI);
	afx_msg void OnExtpakAscii();
	afx_msg void OnUpdateExtpakAscii(CCmdUI* pCmdUI);
	afx_msg void OnSosAscii();
	afx_msg void OnUpdateSosAscii(CCmdUI* pCmdUI);
	afx_msg void OnSosinfoAscii();
	afx_msg void OnUpdateSosinfoAscii(CCmdUI* pCmdUI);
	afx_msg void OnTrafficState();
	afx_msg void OnUpdateTrafficState(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreBusy();
	afx_msg void OnUpdateIgnoreBusy(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreCongest();
	afx_msg void OnUpdateIgnoreCongest(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreError();
	afx_msg void OnUpdateIgnoreError(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreFromMail();
	afx_msg void OnUpdateIgnoreFromMail(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreIllegal();
	afx_msg void OnUpdateIgnoreIllegal(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreInMail();
	afx_msg void OnUpdateIgnoreInMail(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreNoTranser();
	afx_msg void OnUpdateIgnoreNoTranser(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreOk();
	afx_msg void OnUpdateIgnoreOk(CCmdUI* pCmdUI);
	afx_msg void OnHostname();
	afx_msg void OnSequence();
	afx_msg void OnUpdateSequence(CCmdUI* pCmdUI);
	afx_msg void OnIgnoreUsr();
	afx_msg void OnUpdateIgnoreUsr(CCmdUI* pCmdUI);
	afx_msg void OnReDisplay();
	afx_msg void OnUpdateReDisplay(CCmdUI* pCmdUI);
	afx_msg void OnHelp();
	afx_msg void OnRemoteConnect();
	afx_msg void OnUpdateRemoteConnect(CCmdUI* pCmdUI);
	afx_msg void OnDisconnect();
	afx_msg void OnUpdateDisconnect(CCmdUI* pCmdUI);
	afx_msg void OnMonBase();
	afx_msg void OnUpdateMonBase(CCmdUI* pCmdUI);
	afx_msg void OnMonMob();
	afx_msg void OnUpdateMonMob(CCmdUI* pCmdUI);
	afx_msg void OnLoginreq();
	afx_msg void OnUpdateLoginreq(CCmdUI* pCmdUI);
	afx_msg void OnLogout();
	afx_msg void OnUpdateLogout(CCmdUI* pCmdUI);
	afx_msg void OnBorn();
	afx_msg void OnUpdateBorn(CCmdUI* pCmdUI);
	afx_msg void OnActive();
	afx_msg void OnUpdateActive(CCmdUI* pCmdUI);
	afx_msg void OnInactive();
	afx_msg void OnUpdateInactive(CCmdUI* pCmdUI);
	afx_msg void OnRoam();
	afx_msg void OnUpdateRoam(CCmdUI* pCmdUI);
	afx_msg void OnVicesosrx();
	afx_msg void OnUpdateVicesosrx(CCmdUI* pCmdUI);
	afx_msg void OnSosrx();
	afx_msg void OnUpdateSosrx(CCmdUI* pCmdUI);
	afx_msg void OnInfo();
	afx_msg void OnUpdateInfo(CCmdUI* pCmdUI);
	afx_msg void OnEsninfo();
	afx_msg void OnUpdateEsninfo(CCmdUI* pCmdUI);
	afx_msg void OnExconreq();
	afx_msg void OnUpdateExconreq(CCmdUI* pCmdUI);
	afx_msg void OnConrea();
	afx_msg void OnUpdateConrea(CCmdUI* pCmdUI);
	afx_msg void OnLineon();
	afx_msg void OnUpdateLineon(CCmdUI* pCmdUI);
	afx_msg void OnLineoff();
	afx_msg void OnUpdateLineoff(CCmdUI* pCmdUI);
	afx_msg void OnLinsel();
	afx_msg void OnUpdateLinsel(CCmdUI* pCmdUI);
	afx_msg void OnExclusiveUsr();
	afx_msg void OnUpdateExclusiveUsr(CCmdUI* pCmdUI);
	afx_msg void OnSingleMan();
	afx_msg void OnUpdateSingleMan(CCmdUI* pCmdUI);
	afx_msg void OnBlacklistClear();
	afx_msg void OnUpdateBlacklistClear(CCmdUI* pCmdUI);
	afx_msg void OnFirmwareInfo();
	afx_msg void OnUpdateFirmwareInfo(CCmdUI* pCmdUI);
	afx_msg void OnErrorChecking();
	afx_msg void OnUpdateErrorChecking(CCmdUI* pCmdUI);
	afx_msg void OnFec();
	afx_msg void OnUpdateFec(CCmdUI* pCmdUI);
	afx_msg void OnAbd();
	afx_msg void OnUpdateAbd(CCmdUI* pCmdUI);
	afx_msg void OnAck();
	afx_msg void OnUpdateAck(CCmdUI* pCmdUI);
	afx_msg void OnAkt();
	afx_msg void OnUpdateAkt(CCmdUI* pCmdUI);
	afx_msg void OnAtd();
	afx_msg void OnUpdateAtd(CCmdUI* pCmdUI);
	afx_msg void OnAtl();
	afx_msg void OnUpdateAtl(CCmdUI* pCmdUI);
	afx_msg void OnBkd();
	afx_msg void OnUpdateBkd(CCmdUI* pCmdUI);
	afx_msg void OnFri();
	afx_msg void OnUpdateFri(CCmdUI* pCmdUI);
	afx_msg void OnMrm();
	afx_msg void OnUpdateMrm(CCmdUI* pCmdUI);
	afx_msg void OnReb();
	afx_msg void OnUpdateReb(CCmdUI* pCmdUI);
	afx_msg void OnRes();
	afx_msg void OnUpdateRes(CCmdUI* pCmdUI);
	afx_msg void OnSvp();
	afx_msg void OnUpdateSvp(CCmdUI* pCmdUI);
	afx_msg void OnTst();
	afx_msg void OnUpdateTst(CCmdUI* pCmdUI);
	afx_msg void OnNak();
	afx_msg void OnUpdateNak(CCmdUI* pCmdUI);
	afx_msg void OnAbl();
	afx_msg void OnUpdateAbl(CCmdUI* pCmdUI);
	afx_msg void OnSystemChannels();
	afx_msg void OnUpdateSystemChannels(CCmdUI* pCmdUI);
	//}}AFX_MSG

	// Network //
	afx_msg LONG OnListeningSocket(WPARAM amount, LPARAM buffer);
	afx_msg LONG OnServerRX(WPARAM amount, LPARAM buffer);
	afx_msg LONG OnTerminalRX(WPARAM amount, LPARAM buffer);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mobymonView.cpp
inline CMobymonDoc* CMobymonView::GetDocument()
   { return (CMobymonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
