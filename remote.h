// remote.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// remote dialog

class remote : public CDialog , public moby
{
// Construction
public:
	remote(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(remote)
    enum { IDD = IDD_REMOTE };
	CString	m_server_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(remote)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(remote)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
