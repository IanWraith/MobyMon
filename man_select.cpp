// man_select.cpp : implementation file
//

#include "stdafx.h"
#include "mobymon.h"
#include "man_select.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// man_select dialog


man_select::man_select(CWnd* pParent /*=NULL*/)
	: CDialog(man_select::IDD, pParent)
{
	//{{AFX_DATA_INIT(man_select)
	m_single_man = _T("");
	//}}AFX_DATA_INIT
}


void man_select::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(man_select)
	DDX_Text(pDX, IDC_EDIT1, m_single_man);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(man_select, CDialog)
	//{{AFX_MSG_MAP(man_select)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// man_select message handlers

void man_select::OnOK() 
{
char a,manh[100];
int b;
	
CDialog::OnOK();

b=m_single_man.GetLength()-1;
for (a=0;a<=b;a++)
 manh[a]=m_single_man.GetAt(a);

manh[a]=0;
blacklist=0;

// Fault conditions //
if (b!=5)
 {
 AfxMessageBox("The MAN must contain 6 numbers !",MB_OK|MB_ICONEXCLAMATION,0);
 }
else
 {
 // Last digit //
 if (manh[5]==49) blacklist=1;
 if (manh[5]==50) blacklist=2;
 if (manh[5]==51) blacklist=3;
 if (manh[5]==52) blacklist=4;
 if (manh[5]==53) blacklist=5; 
 if (manh[5]==54) blacklist=6;
 if (manh[5]==55) blacklist=7;
 if (manh[5]==56) blacklist=8;
 if (manh[5]==57) blacklist=9;
 if (manh[5]==65 || manh[5]==97) blacklist=10; 
 if (manh[5]==66 || manh[5]==98) blacklist=11;
 if (manh[5]==67 || manh[5]==99) blacklist=12;
 if (manh[5]==68 || manh[5]==100) blacklist=13;
 if (manh[5]==69 || manh[5]==101) blacklist=14;
 if (manh[5]==70 || manh[5]==102) blacklist=15; 

 // 5th digit //
 if (manh[4]==49) blacklist=blacklist+16;
 if (manh[4]==50) blacklist=blacklist+(2*16);
 if (manh[4]==51) blacklist=blacklist+(3*16);
 if (manh[4]==52) blacklist=blacklist+(4*16);
 if (manh[4]==53) blacklist=blacklist+(5*16);
 if (manh[4]==54) blacklist=blacklist+(6*16);
 if (manh[4]==55) blacklist=blacklist+(7*16);
 if (manh[4]==56) blacklist=blacklist+(8*16);
 if (manh[4]==57) blacklist=blacklist+(9*16);
 if (manh[4]==65 || manh[4]==97) blacklist=blacklist+(10*16);
 if (manh[4]==66 || manh[4]==98) blacklist=blacklist+(11*16);
 if (manh[4]==67 || manh[4]==99) blacklist=blacklist+(12*16);
 if (manh[4]==68 || manh[4]==100) blacklist=blacklist+(13*16);
 if (manh[4]==69 || manh[4]==101) blacklist=blacklist+(14*16);
 if (manh[4]==70 || manh[4]==102) blacklist=blacklist+(15*16);
 
 // 4th digit //
 if (manh[3]==49) blacklist=blacklist+256;
 if (manh[3]==50) blacklist=blacklist+(2*256);
 if (manh[3]==51) blacklist=blacklist+(3*256);
 if (manh[3]==52) blacklist=blacklist+(4*256);
 if (manh[3]==53) blacklist=blacklist+(5*256);
 if (manh[3]==54) blacklist=blacklist+(6*256);
 if (manh[3]==55) blacklist=blacklist+(7*256);
 if (manh[3]==56) blacklist=blacklist+(8*256); 
 if (manh[3]==57) blacklist=blacklist+(9*256);
 if (manh[3]==65 || manh[3]==97) blacklist=blacklist+(10*256);
 if (manh[3]==66 || manh[3]==98) blacklist=blacklist+(11*256);
 if (manh[3]==67 || manh[3]==99) blacklist=blacklist+(12*256);
 if (manh[3]==68 || manh[3]==100) blacklist=blacklist+(13*256);
 if (manh[3]==69 || manh[3]==101) blacklist=blacklist+(14*256);
 if (manh[3]==70 || manh[3]==102) blacklist=blacklist+(15*256);

 // 3rd digit //
 if (manh[2]==49) blacklist=blacklist+4096;
 if (manh[2]==50) blacklist=blacklist+(2*4096);
 if (manh[2]==51) blacklist=blacklist+(3*4096);
 if (manh[2]==52) blacklist=blacklist+(4*4096);
 if (manh[2]==53) blacklist=blacklist+(5*4096);
 if (manh[2]==54) blacklist=blacklist+(6*4096);
 if (manh[2]==55) blacklist=blacklist+(7*4096);
 if (manh[2]==56) blacklist=blacklist+(8*4096);
 if (manh[2]==57) blacklist=blacklist+(9*4096);
 if (manh[2]==65 || manh[2]==97) blacklist=blacklist+(10*4096);
 if (manh[2]==66 || manh[2]==98) blacklist=blacklist+(11*4096);
 if (manh[2]==67 || manh[2]==99) blacklist=blacklist+(12*4096);
 if (manh[2]==68 || manh[2]==100) blacklist=blacklist+(13*4096);
 if (manh[2]==69 || manh[2]==101) blacklist=blacklist+(14*4096);
 if (manh[2]==70 || manh[2]==102) blacklist=blacklist+(15*4096);

 // 2nd digit //
 if (manh[1]==49) blacklist=blacklist+65536;
 if (manh[1]==50) blacklist=blacklist+(2*65536);
 if (manh[1]==51) blacklist=blacklist+(3*65536);
 if (manh[1]==52) blacklist=blacklist+(4*65536);
 if (manh[1]==53) blacklist=blacklist+(5*65536);
 if (manh[1]==54) blacklist=blacklist+(6*65536);
 if (manh[1]==55) blacklist=blacklist+(7*65536);
 if (manh[1]==56) blacklist=blacklist+(8*65536);
 if (manh[1]==57) blacklist=blacklist+(9*65536);
 if (manh[1]==65 || manh[1]==97) blacklist=blacklist+(10*65536);
 if (manh[1]==66 || manh[1]==98) blacklist=blacklist+(11*65536);
 if (manh[1]==67 || manh[1]==99) blacklist=blacklist+(12*65536);
 if (manh[1]==68 || manh[1]==100) blacklist=blacklist+(13*65536);
 if (manh[1]==69 || manh[1]==101) blacklist=blacklist+(14*65536);
 if (manh[1]==70 || manh[1]==102) blacklist=blacklist+(15*65536);

 // 1st digit //
 if (manh[0]==49) blacklist=blacklist+1048576;
 if (manh[0]==50) blacklist=blacklist+(2*1048576);
 if (manh[0]==51) blacklist=blacklist+(3*1048576);
 if (manh[0]==52) blacklist=blacklist+(4*1048576);
 if (manh[0]==53) blacklist=blacklist+(5*1048576);
 if (manh[0]==54) blacklist=blacklist+(6*1048576);
 if (manh[0]==55) blacklist=blacklist+(7*1048576);
 if (manh[0]==56) blacklist=blacklist+(8*1048576);
 if (manh[0]==57) blacklist=blacklist+(9*1048576);
 if (manh[0]==65 || manh[0]==97) blacklist=blacklist+(10*1048576);
 if (manh[0]==66 || manh[0]==98) blacklist=blacklist+(11*1048576);
 if (manh[0]==67 || manh[0]==99) blacklist=blacklist+(12*1048576);
 if (manh[0]==68 || manh[0]==100) blacklist=blacklist+(13*1048576);
 if (manh[0]==69 || manh[0]==101) blacklist=blacklist+(14*1048576);
 if (manh[0]==70 || manh[0]==102) blacklist=blacklist+(15*1048576);
 }

}

void man_select::OnCancel() 
{
blacklist=0;	
CDialog::OnCancel();
}
