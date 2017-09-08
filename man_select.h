// man_select.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// man_select dialog

class man_select : public CDialog , public moby
{
// Construction
public:
	man_select(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(man_select)
	enum { IDD = IDD_MANSELECT };
	CString	m_single_man;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(man_select)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(man_select)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
