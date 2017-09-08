// comselect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// comselect dialog

class comselect : public CDialog , public moby
{
// Construction
public:
	comselect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(comselect)
	enum { IDD = IDD_COMSELECT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(comselect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(comselect)
	afx_msg void OnCom1();
	afx_msg void OnCom2();
	afx_msg void OnCom3();
	afx_msg void OnCom4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
