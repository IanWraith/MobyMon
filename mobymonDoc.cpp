// mobymonDoc.cpp : implementation of the CMobymonDoc class
//

#include "stdafx.h"
#include "mobymon.h"

#include "mobymonDoc.h"

#include <fstream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMobymonDoc

IMPLEMENT_DYNCREATE(CMobymonDoc, CDocument)

BEGIN_MESSAGE_MAP(CMobymonDoc, CDocument)
	//{{AFX_MSG_MAP(CMobymonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMobymonDoc construction/destruction

CMobymonDoc::CMobymonDoc()
{
	// TODO: add one-time construction code here

}

CMobymonDoc::~CMobymonDoc()
{
}

BOOL CMobymonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	// Scrolling line below // was 500 2000
	m_sizeDoc=CSize(1400,2000);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMobymonDoc serialization

void CMobymonDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	// Scrolling line below //
	ar<<m_sizeDoc;
	}
	else
	{
	// Scrolling line below //
    ar>>m_sizeDoc;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMobymonDoc diagnostics

#ifdef _DEBUG
void CMobymonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMobymonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMobymonDoc commands

BOOL CMobymonDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// Open file for reading //
	ifstream ifs(lpszPathName, ios::in);
	if (!ifs) return FALSE;

	// Read and interpret file //
	char line[512];
	int i=0;

	while (!ifs.eof())
	 {
	 ifs.getline(line,sizeof(line));
	 if (!ifs) break;
	 CString cs(line);
	 m_Contents.Add(cs);
	 i++;
	 }	

	return TRUE;
}
