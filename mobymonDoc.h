// mobymonDoc.h : interface of the CMobymonDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CMobymonDoc : public CDocument
{
protected: // create from serialization only
	CMobymonDoc();
	DECLARE_DYNCREATE(CMobymonDoc)

// Scroll line below //
CSize m_sizeDoc;

// Attributes
public:

// Scroll line below //
CSize GetDocSize() {return m_sizeDoc;}

// Operations
public:
// Printer Lines below //
int NumLines() {return m_Contents.GetSize();}
const CString& Line(int n) {return m_Contents[n];}

protected:
CStringArray m_Contents;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMobymonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMobymonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMobymonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
