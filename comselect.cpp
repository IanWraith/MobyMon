// comselect.cpp : implementation file
//

#include "stdafx.h"
#include "mobymon.h"
#include "comselect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// comselect dialog


comselect::comselect(CWnd* pParent /*=NULL*/)
	: CDialog(comselect::IDD, pParent)
{
	//{{AFX_DATA_INIT(comselect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void comselect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(comselect)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(comselect, CDialog)
	//{{AFX_MSG_MAP(comselect)
	ON_BN_CLICKED(IDC_COM1, OnCom1)
	ON_BN_CLICKED(IDC_COM2, OnCom2)
	ON_BN_CLICKED(IDC_COM3, OnCom3)
	ON_BN_CLICKED(IDC_COM4, OnCom4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// comselect message handlers

void comselect::OnCom1() 
{
com_port=1;	
}

void comselect::OnCom2() 
{
com_port=2;	
}

void comselect::OnCom3() 
{
com_port=3;	
}

void comselect::OnCom4() 
{
com_port=4;	
}
