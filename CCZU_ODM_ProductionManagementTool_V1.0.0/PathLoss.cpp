// PathLoss.cpp : implementation file
//

#include "stdafx.h"
#include "productionmanagementtool.h"
#include "PathLoss.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPathLoss dialog


CPathLoss::CPathLoss(CWnd* pParent /*=NULL*/)
	: CDialog(CPathLoss::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPathLoss)
	m_fG900Loss1 = 0.0f;
	m_fG900Loss2 = 0.0f;
	m_fG900Loss3 = 0.0f;
	m_fG900Loss4 = 0.0f;
	m_fG900Loss5 = 0.0f;
	m_fG900Loss6 = 0.0f;
	m_fG900Loss7 = 0.0f;
	m_fG900Loss8 = 0.0f;
	m_fG900Loss9 = 0.0f;
	m_fG900Loss10 = 0.0f;
	m_fG900Loss11 = 0.0f;
	m_fG900Loss12 = 0.0f;
	m_fG900Loss13 = 0.0f;
	m_fG900Loss14 = 0.0f;
	m_fG900Loss15 = 0.0f;
	m_fG900Loss16 = 0.0f;
	m_fG900Loss17 = 0.0f;
	m_fG900Loss18 = 0.0f;
	m_fG900Loss19 = 0.0f;
	m_fG900Loss20 = 0.0f;
	m_fG1800Loss1 = 0.0f;
	m_fG1800Loss2 = 0.0f;
	m_fG1800Loss3 = 0.0f;
	m_fG1800Loss4 = 0.0f;
	m_fG1800Loss5 = 0.0f;
	m_fG1800Loss6 = 0.0f;
	m_fG1800Loss7 = 0.0f;
	m_fG1800Loss8 = 0.0f;
	m_fG1800Loss9 = 0.0f;
	m_fG1800Loss10 = 0.0f;
	m_fG1800Loss11 = 0.0f;
	m_fG1800Loss12 = 0.0f;
	m_fG1800Loss13 = 0.0f;
	m_fG1800Loss14 = 0.0f;
	m_fG1800Loss15 = 0.0f;
	m_fG1800Loss16 = 0.0f;
	m_fG1800Loss17 = 0.0f;
	m_fG1800Loss18 = 0.0f;
	m_fG1800Loss19 = 0.0f;
	m_fG1800Loss20 = 0.0f;
	m_fW850Loss1 = 0.0f;
	m_fW850Loss2 = 0.0f;
	m_fW850Loss3 = 0.0f;
	m_fW850Loss4 = 0.0f;
	m_fW850Loss5 = 0.0f;
	m_fW850Loss6 = 0.0f;
	m_fW850Loss7 = 0.0f;
	m_fW850Loss8 = 0.0f;
	m_fW850Loss9 = 0.0f;
	m_fW850Loss10 = 0.0f;
	m_fW850Loss11 = 0.0f;
	m_fW850Loss12 = 0.0f;
	m_fW850Loss13 = 0.0f;
	m_fW850Loss14 = 0.0f;
	m_fW850Loss15 = 0.0f;
	m_fW850Loss16 = 0.0f;
	m_fW850Loss17 = 0.0f;
	m_fW850Loss18 = 0.0f;
	m_fW850Loss19 = 0.0f;
	m_fW850Loss20 = 0.0f;
	m_fW900Loss1 = 0.0f;
	m_fW900Loss2 = 0.0f;
	m_fW900Loss3 = 0.0f;
	m_fW900Loss4 = 0.0f;
	m_fW900Loss5 = 0.0f;
	m_fW900Loss6 = 0.0f;
	m_fW900Loss7 = 0.0f;
	m_fW900Loss8 = 0.0f;
	m_fW900Loss9 = 0.0f;
	m_fW900Loss10 = 0.0f;
	m_fW900Loss11 = 0.0f;
	m_fW900Loss12 = 0.0f;
	m_fW900Loss13 = 0.0f;
	m_fW900Loss14 = 0.0f;
	m_fW900Loss15 = 0.0f;
	m_fW900Loss16 = 0.0f;
	m_fW900Loss17 = 0.0f;
	m_fW900Loss18 = 0.0f;
	m_fW900Loss19 = 0.0f;
	m_fW900Loss20 = 0.0f;
	m_fW1900Loss1 = 0.0f;
	m_fW1900Loss2 = 0.0f;
	m_fW1900Loss3 = 0.0f;
	m_fW1900Loss4 = 0.0f;
	m_fW1900Loss5 = 0.0f;
	m_fW1900Loss6 = 0.0f;
	m_fW1900Loss7 = 0.0f;
	m_fW1900Loss8 = 0.0f;
	m_fW1900Loss9 = 0.0f;
	m_fW1900Loss10 = 0.0f;
	m_fW1900Loss11 = 0.0f;
	m_fW1900Loss12 = 0.0f;
	m_fW1900Loss13 = 0.0f;
	m_fW1900Loss14 = 0.0f;
	m_fW1900Loss15 = 0.0f;
	m_fW1900Loss16 = 0.0f;
	m_fW1900Loss17 = 0.0f;
	m_fW1900Loss18 = 0.0f;
	m_fW1900Loss19 = 0.0f;
	m_fW1900Loss20 = 0.0f;
	m_fW2100Loss1 = 0.0f;
	m_fW2100Loss2 = 0.0f;
	m_fW2100Loss3 = 0.0f;
	m_fW2100Loss4 = 0.0f;
	m_fW2100Loss5 = 0.0f;
	m_fW2100Loss6 = 0.0f;
	m_fW2100Loss7 = 0.0f;
	m_fW2100Loss8 = 0.0f;
	m_fW2100Loss9 = 0.0f;
	m_fW2100Loss10 = 0.0f;
	m_fW2100Loss11 = 0.0f;
	m_fW2100Loss12 = 0.0f;
	m_fW2100Loss13 = 0.0f;
	m_fW2100Loss14 = 0.0f;
	m_fW2100Loss15 = 0.0f;
	m_fW2100Loss16 = 0.0f;
	m_fW2100Loss17 = 0.0f;
	m_fW2100Loss18 = 0.0f;
	m_fW2100Loss19 = 0.0f;
	m_fW2100Loss20 = 0.0f;
	//}}AFX_DATA_INIT
}


void CPathLoss::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPathLoss)
	DDX_Text(pDX, IDC_EDIT_G900_LOSS1, m_fG900Loss1);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS2, m_fG900Loss2);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS3, m_fG900Loss3);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS4, m_fG900Loss4);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS5, m_fG900Loss5);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS6, m_fG900Loss6);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS7, m_fG900Loss7);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS8, m_fG900Loss8);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS9, m_fG900Loss9);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS10, m_fG900Loss10);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS11, m_fG900Loss11);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS12, m_fG900Loss12);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS13, m_fG900Loss13);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS14, m_fG900Loss14);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS15, m_fG900Loss15);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS16, m_fG900Loss16);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS17, m_fG900Loss17);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS18, m_fG900Loss18);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS19, m_fG900Loss19);
	DDX_Text(pDX, IDC_EDIT_G900_LOSS20, m_fG900Loss20);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS1, m_fG1800Loss1);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS2, m_fG1800Loss2);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS3, m_fG1800Loss3);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS4, m_fG1800Loss4);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS5, m_fG1800Loss5);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS6, m_fG1800Loss6);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS7, m_fG1800Loss7);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS8, m_fG1800Loss8);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS9, m_fG1800Loss9);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS10, m_fG1800Loss10);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS11, m_fG1800Loss11);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS12, m_fG1800Loss12);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS13, m_fG1800Loss13);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS14, m_fG1800Loss14);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS15, m_fG1800Loss15);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS16, m_fG1800Loss16);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS17, m_fG1800Loss17);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS18, m_fG1800Loss18);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS19, m_fG1800Loss19);
	DDX_Text(pDX, IDC_EDIT_G1800_LOSS20, m_fG1800Loss20);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS1, m_fW850Loss1);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS2, m_fW850Loss2);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS3, m_fW850Loss3);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS4, m_fW850Loss4);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS5, m_fW850Loss5);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS6, m_fW850Loss6);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS7, m_fW850Loss7);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS8, m_fW850Loss8);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS9, m_fW850Loss9);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS10, m_fW850Loss10);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS11, m_fW850Loss11);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS12, m_fW850Loss12);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS13, m_fW850Loss13);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS14, m_fW850Loss14);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS15, m_fW850Loss15);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS16, m_fW850Loss16);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS17, m_fW850Loss17);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS18, m_fW850Loss18);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS19, m_fW850Loss19);
	DDX_Text(pDX, IDC_EDIT_W850_LOSS20, m_fW850Loss20);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS1, m_fW900Loss1);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS2, m_fW900Loss2);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS3, m_fW900Loss3);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS4, m_fW900Loss4);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS5, m_fW900Loss5);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS6, m_fW900Loss6);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS7, m_fW900Loss7);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS8, m_fW900Loss8);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS9, m_fW900Loss9);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS10, m_fW900Loss10);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS11, m_fW900Loss11);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS12, m_fW900Loss12);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS13, m_fW900Loss13);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS14, m_fW900Loss14);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS15, m_fW900Loss15);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS16, m_fW900Loss16);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS17, m_fW900Loss17);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS18, m_fW900Loss18);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS19, m_fW900Loss19);
	DDX_Text(pDX, IDC_EDIT_W900_LOSS20, m_fW900Loss20);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS1, m_fW1900Loss1);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS2, m_fW1900Loss2);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS3, m_fW1900Loss3);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS4, m_fW1900Loss4);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS5, m_fW1900Loss5);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS6, m_fW1900Loss6);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS7, m_fW1900Loss7);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS8, m_fW1900Loss8);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS9, m_fW1900Loss9);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS10, m_fW1900Loss10);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS11, m_fW1900Loss11);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS12, m_fW1900Loss12);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS13, m_fW1900Loss13);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS14, m_fW1900Loss14);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS15, m_fW1900Loss15);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS16, m_fW1900Loss16);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS17, m_fW1900Loss17);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS18, m_fW1900Loss18);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS19, m_fW1900Loss19);
	DDX_Text(pDX, IDC_EDIT_W1900_LOSS20, m_fW1900Loss20);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS1, m_fW2100Loss1);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS2, m_fW2100Loss2);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS3, m_fW2100Loss3);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS4, m_fW2100Loss4);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS5, m_fW2100Loss5);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS6, m_fW2100Loss6);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS7, m_fW2100Loss7);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS8, m_fW2100Loss8);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS9, m_fW2100Loss9);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS10, m_fW2100Loss10);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS11, m_fW2100Loss11);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS12, m_fW2100Loss12);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS13, m_fW2100Loss13);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS14, m_fW2100Loss14);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS15, m_fW2100Loss15);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS16, m_fW2100Loss16);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS17, m_fW2100Loss17);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS18, m_fW2100Loss18);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS19, m_fW2100Loss19);
	DDX_Text(pDX, IDC_EDIT_W2100_LOSS20, m_fW2100Loss20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPathLoss, CDialog)
	//{{AFX_MSG_MAP(CPathLoss)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPathLoss message handlers

BOOL CPathLoss::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//获取项目列表
	if(!this->GetPathLoss())
	{
		MessageBox("获取所有站位线损值失败!");
		return FALSE;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPathLoss::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	_variant_t var;
	CString    sql,sqltemp[20];
	bool       m_bFlag;  //PathLossList表中是否有记录，0——表示没有，1——表示已有
	float      m_fPathLoss[6][20];

	m_bFlag = FALSE;

	//清空数组
	for (int m=0;m<6;m++)
	{
		for (int n=0;n<20;n++)
		{
			m_fPathLoss[m][n] = 0.0;
		}
	}

	m_fPathLoss[0][0] = m_fG900Loss1;
	m_fPathLoss[0][1] = m_fG900Loss2;
	m_fPathLoss[0][2] = m_fG900Loss3;
	m_fPathLoss[0][3] = m_fG900Loss4;
	m_fPathLoss[0][4] = m_fG900Loss5;
	m_fPathLoss[0][5] = m_fG900Loss6;
	m_fPathLoss[0][6] = m_fG900Loss7;
	m_fPathLoss[0][7] = m_fG900Loss8;
	m_fPathLoss[0][8] = m_fG900Loss9;
	m_fPathLoss[0][9] = m_fG900Loss10;
	m_fPathLoss[0][10] = m_fG900Loss11;
	m_fPathLoss[0][11] = m_fG900Loss12;
	m_fPathLoss[0][12] = m_fG900Loss13;
	m_fPathLoss[0][13] = m_fG900Loss14;
	m_fPathLoss[0][14] = m_fG900Loss15;
	m_fPathLoss[0][15] = m_fG900Loss16;
	m_fPathLoss[0][16] = m_fG900Loss17;
	m_fPathLoss[0][17] = m_fG900Loss18;
	m_fPathLoss[0][18] = m_fG900Loss19;
	m_fPathLoss[0][19] = m_fG900Loss20;
	m_fPathLoss[1][0] = m_fG1800Loss1;
	m_fPathLoss[1][1] = m_fG1800Loss2;
	m_fPathLoss[1][2] = m_fG1800Loss3;
	m_fPathLoss[1][3] = m_fG1800Loss4;
	m_fPathLoss[1][4] = m_fG1800Loss5;
	m_fPathLoss[1][5] = m_fG1800Loss6;
	m_fPathLoss[1][6] = m_fG1800Loss7;
	m_fPathLoss[1][7] = m_fG1800Loss8;
	m_fPathLoss[1][8] = m_fG1800Loss9;
	m_fPathLoss[1][9] = m_fG1800Loss10;
	m_fPathLoss[1][10] = m_fG1800Loss11;
	m_fPathLoss[1][11] = m_fG1800Loss12;
	m_fPathLoss[1][12] = m_fG1800Loss13;
	m_fPathLoss[1][13] = m_fG1800Loss14;
	m_fPathLoss[1][14] = m_fG1800Loss15;
	m_fPathLoss[1][15] = m_fG1800Loss16;
	m_fPathLoss[1][16] = m_fG1800Loss17;
	m_fPathLoss[1][17] = m_fG1800Loss18;
	m_fPathLoss[1][18] = m_fG1800Loss19;
	m_fPathLoss[1][19] = m_fG1800Loss20;
	m_fPathLoss[2][0] = m_fW850Loss1;
	m_fPathLoss[2][1] = m_fW850Loss2;
	m_fPathLoss[2][2] = m_fW850Loss3;
	m_fPathLoss[2][3] = m_fW850Loss4;
	m_fPathLoss[2][4] = m_fW850Loss5;
	m_fPathLoss[2][5] = m_fW850Loss6;
	m_fPathLoss[2][6] = m_fW850Loss7;
	m_fPathLoss[2][7] = m_fW850Loss8;
	m_fPathLoss[2][8] = m_fW850Loss9;
	m_fPathLoss[2][9] = m_fW850Loss10;
	m_fPathLoss[2][10] = m_fW850Loss11;
	m_fPathLoss[2][11] = m_fW850Loss12;
	m_fPathLoss[2][12] = m_fW850Loss13;
	m_fPathLoss[2][13] = m_fW850Loss14;
	m_fPathLoss[2][14] = m_fW850Loss15;
	m_fPathLoss[2][15] = m_fW850Loss16;
	m_fPathLoss[2][16] = m_fW850Loss17;
	m_fPathLoss[2][17] = m_fW850Loss18;
	m_fPathLoss[2][18] = m_fW850Loss19;
	m_fPathLoss[2][19] = m_fW850Loss20;
	m_fPathLoss[3][0] = m_fW900Loss1;
	m_fPathLoss[3][1] = m_fW900Loss2;
	m_fPathLoss[3][2] = m_fW900Loss3;
	m_fPathLoss[3][3] = m_fW900Loss4;
	m_fPathLoss[3][4] = m_fW900Loss5;
	m_fPathLoss[3][5] = m_fW900Loss6;
	m_fPathLoss[3][6] = m_fW900Loss7;
	m_fPathLoss[3][7] = m_fW900Loss8;
	m_fPathLoss[3][8] = m_fW900Loss9;
	m_fPathLoss[3][9] = m_fW900Loss10;
	m_fPathLoss[3][10] = m_fW900Loss11;
	m_fPathLoss[3][11] = m_fW900Loss12;
	m_fPathLoss[3][12] = m_fW900Loss13;
	m_fPathLoss[3][13] = m_fW900Loss14;
	m_fPathLoss[3][14] = m_fW900Loss15;
	m_fPathLoss[3][15] = m_fW900Loss16;
	m_fPathLoss[3][16] = m_fW900Loss17;
	m_fPathLoss[3][17] = m_fW900Loss18;
	m_fPathLoss[3][18] = m_fW900Loss19;
	m_fPathLoss[3][19] = m_fW900Loss20;
	m_fPathLoss[4][0] = m_fW1900Loss1;
	m_fPathLoss[4][1] = m_fW1900Loss2;
	m_fPathLoss[4][2] = m_fW1900Loss3;
	m_fPathLoss[4][3] = m_fW1900Loss4;
	m_fPathLoss[4][4] = m_fW1900Loss5;
	m_fPathLoss[4][5] = m_fW1900Loss6;
	m_fPathLoss[4][6] = m_fW1900Loss7;
	m_fPathLoss[4][7] = m_fW1900Loss8;
	m_fPathLoss[4][8] = m_fW1900Loss9;
	m_fPathLoss[4][9] = m_fW1900Loss10;
	m_fPathLoss[4][10] = m_fW1900Loss11;
	m_fPathLoss[4][11] = m_fW1900Loss12;
	m_fPathLoss[4][12] = m_fW1900Loss13;
	m_fPathLoss[4][13] = m_fW1900Loss14;
	m_fPathLoss[4][14] = m_fW1900Loss15;
	m_fPathLoss[4][15] = m_fW1900Loss16;
	m_fPathLoss[4][16] = m_fW1900Loss17;
	m_fPathLoss[4][17] = m_fW1900Loss18;
	m_fPathLoss[4][18] = m_fW1900Loss19;
	m_fPathLoss[4][19] = m_fW1900Loss20;
	m_fPathLoss[5][0] = m_fW2100Loss1;
	m_fPathLoss[5][1] = m_fW2100Loss2;
	m_fPathLoss[5][2] = m_fW2100Loss3;
	m_fPathLoss[5][3] = m_fW2100Loss4;
	m_fPathLoss[5][4] = m_fW2100Loss5;
	m_fPathLoss[5][5] = m_fW2100Loss6;
	m_fPathLoss[5][6] = m_fW2100Loss7;
	m_fPathLoss[5][7] = m_fW2100Loss8;
	m_fPathLoss[5][8] = m_fW2100Loss9;
	m_fPathLoss[5][9] = m_fW2100Loss10;
	m_fPathLoss[5][10] = m_fW2100Loss11;
	m_fPathLoss[5][11] = m_fW2100Loss12;
	m_fPathLoss[5][12] = m_fW2100Loss13;
	m_fPathLoss[5][13] = m_fW2100Loss14;
	m_fPathLoss[5][14] = m_fW2100Loss15;
	m_fPathLoss[5][15] = m_fW2100Loss16;
	m_fPathLoss[5][16] = m_fW2100Loss17;
	m_fPathLoss[5][17] = m_fW2100Loss18;
	m_fPathLoss[5][18] = m_fW2100Loss19;
	m_fPathLoss[5][19] = m_fW2100Loss20;

	try
	{
		sql.Format("select * from PathLossList");
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			m_bFlag = TRUE;
		}
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		MessageBox("查询数据库失败!","Error",MB_OK);
		return;
	}

	if (!m_bFlag)
	{
		for (int i=0;i<20;i++)
		{
			sqltemp[i].Format("INSERT INTO PathLossList (WorkStation,GSM900_PathLoss,GSM1800_PathLoss, \
			WCDMA850_PathLoss,WCDMA900_PathLoss,WCDMA1900_PathLoss,WCDMA2100_PathLoss) VALUES \
			(%d,%f,%f,%f,%f,%f,%f)",i+1,m_fPathLoss[0][i],m_fPathLoss[1][i],m_fPathLoss[2][i],m_fPathLoss[3][i], \
			m_fPathLoss[4][i],m_fPathLoss[5][i]);
		}
	}
	else
	{
		for (int j=0;j<20;j++)
		{
			sqltemp[j].Format("UPDATE PathLossList SET GSM900_PathLoss = %f,GSM1800_PathLoss = %f, \
				WCDMA850_PathLoss = %f,WCDMA900_PathLoss = %f,WCDMA1900_PathLoss = %f,WCDMA2100_PathLoss = %f \
				WHERE WorkStation = %d",\
				m_fPathLoss[0][j],m_fPathLoss[1][j],m_fPathLoss[2][j],m_fPathLoss[3][j], \
				m_fPathLoss[4][j],m_fPathLoss[5][j],j+1);
		}
	}

	for (int k=0;k<20;k++)
	{
		try
		{
			if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
				((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sqltemp[k],NULL,adCmdText);
			if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
				((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			MessageBox("设置线损失败!","Error",MB_OK);
			return;
		}
	}

	MessageBox("设置线损成功!","OK",MB_OK);

	CDialog::OnOK();
}

bool CPathLoss::GetPathLoss()
{
	_variant_t var;
	CString sql;
	float   m_fPathLoss[6][20];

	//清空数组
	for (int m=0;m<6;m++)
	{
		for (int n=0;n<20;n++)
		{
			m_fPathLoss[m][n] = 0.0;
		}
	}

	//获取20个工位的不同频段的线损值
	for (int i=0;i<20;i++)
	{
		try
		{
			sql.Format("select * from PathLossList where WorkStation=%d",i+1);
			
			if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
				((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);		
			if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
			{			
				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("GSM900_PathLoss");
				m_fPathLoss[0][i]=var.dblVal;

				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("GSM1800_PathLoss");
				m_fPathLoss[1][i]=var.dblVal;

				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WCDMA850_PathLoss");
				m_fPathLoss[2][i]=var.dblVal;

				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WCDMA900_PathLoss");
				m_fPathLoss[3][i]=var.dblVal;

				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WCDMA1900_PathLoss");
				m_fPathLoss[4][i]=var.dblVal;

				var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WCDMA2100_PathLoss");
				m_fPathLoss[5][i]=var.dblVal;
			}
			
			if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
				((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	m_fG900Loss1 = m_fPathLoss[0][0];
	m_fG900Loss2 = m_fPathLoss[0][1];
	m_fG900Loss3 = m_fPathLoss[0][2];
	m_fG900Loss4 = m_fPathLoss[0][3];
	m_fG900Loss5 = m_fPathLoss[0][4];
	m_fG900Loss6 = m_fPathLoss[0][5];
	m_fG900Loss7 = m_fPathLoss[0][6];
	m_fG900Loss8 = m_fPathLoss[0][7];
	m_fG900Loss9 = m_fPathLoss[0][8];
	m_fG900Loss10 = m_fPathLoss[0][9];
	m_fG900Loss11 = m_fPathLoss[0][10];
	m_fG900Loss12 = m_fPathLoss[0][11];
	m_fG900Loss13 = m_fPathLoss[0][12];
	m_fG900Loss14 = m_fPathLoss[0][13];
	m_fG900Loss15 = m_fPathLoss[0][14];
	m_fG900Loss16 = m_fPathLoss[0][15];
	m_fG900Loss17 = m_fPathLoss[0][16];
	m_fG900Loss18 = m_fPathLoss[0][17];
	m_fG900Loss19 = m_fPathLoss[0][18];
	m_fG900Loss20 = m_fPathLoss[0][19];
	m_fG1800Loss1 = m_fPathLoss[1][0];
	m_fG1800Loss2 = m_fPathLoss[1][1];
	m_fG1800Loss3 = m_fPathLoss[1][2];
	m_fG1800Loss4 = m_fPathLoss[1][3];
	m_fG1800Loss5 = m_fPathLoss[1][4];
	m_fG1800Loss6 = m_fPathLoss[1][5];
	m_fG1800Loss7 = m_fPathLoss[1][6];
	m_fG1800Loss8 = m_fPathLoss[1][7];
	m_fG1800Loss9 = m_fPathLoss[1][8];
	m_fG1800Loss10 = m_fPathLoss[1][9];
	m_fG1800Loss11 = m_fPathLoss[1][10];
	m_fG1800Loss12 = m_fPathLoss[1][11];
	m_fG1800Loss13 = m_fPathLoss[1][12];
	m_fG1800Loss14 = m_fPathLoss[1][13];
	m_fG1800Loss15 = m_fPathLoss[1][14];
	m_fG1800Loss16 = m_fPathLoss[1][15];
	m_fG1800Loss17 = m_fPathLoss[1][16];
	m_fG1800Loss18 = m_fPathLoss[1][17];
	m_fG1800Loss19 = m_fPathLoss[1][18];
	m_fG1800Loss20 = m_fPathLoss[1][19];
	m_fW850Loss1 = m_fPathLoss[2][0];
	m_fW850Loss2 = m_fPathLoss[2][1];
	m_fW850Loss3 = m_fPathLoss[2][2];
	m_fW850Loss4 = m_fPathLoss[2][3];
	m_fW850Loss5 = m_fPathLoss[2][4];
	m_fW850Loss6 = m_fPathLoss[2][5];
	m_fW850Loss7 = m_fPathLoss[2][6];
	m_fW850Loss8 = m_fPathLoss[2][7];
	m_fW850Loss9 = m_fPathLoss[2][8];
	m_fW850Loss10 = m_fPathLoss[2][9];
	m_fW850Loss11 = m_fPathLoss[2][10];
	m_fW850Loss12 = m_fPathLoss[2][11];
	m_fW850Loss13 = m_fPathLoss[2][12];
	m_fW850Loss14 = m_fPathLoss[2][13];
	m_fW850Loss15 = m_fPathLoss[2][14];
	m_fW850Loss16 = m_fPathLoss[2][15];
	m_fW850Loss17 = m_fPathLoss[2][16];
	m_fW850Loss18 = m_fPathLoss[2][17];
	m_fW850Loss19 = m_fPathLoss[2][18];
	m_fW850Loss20 = m_fPathLoss[2][19];
	m_fW900Loss1 = m_fPathLoss[3][0];
	m_fW900Loss2 = m_fPathLoss[3][1];
	m_fW900Loss3 = m_fPathLoss[3][2];
	m_fW900Loss4 = m_fPathLoss[3][3];
	m_fW900Loss5 = m_fPathLoss[3][4];
	m_fW900Loss6 = m_fPathLoss[3][5];
	m_fW900Loss7 = m_fPathLoss[3][6];
	m_fW900Loss8 = m_fPathLoss[3][7];
	m_fW900Loss9 = m_fPathLoss[3][8];
	m_fW900Loss10 = m_fPathLoss[3][9];
	m_fW900Loss11 = m_fPathLoss[3][10];
	m_fW900Loss12 = m_fPathLoss[3][11];
	m_fW900Loss13 = m_fPathLoss[3][12];
	m_fW900Loss14 = m_fPathLoss[3][13];
	m_fW900Loss15 = m_fPathLoss[3][14];
	m_fW900Loss16 = m_fPathLoss[3][15];
	m_fW900Loss17 = m_fPathLoss[3][16];
	m_fW900Loss18 = m_fPathLoss[3][17];
	m_fW900Loss19 = m_fPathLoss[3][18];
	m_fW900Loss20 = m_fPathLoss[3][19];
	m_fW1900Loss1 = m_fPathLoss[4][0];
	m_fW1900Loss2 = m_fPathLoss[4][1];
	m_fW1900Loss3 = m_fPathLoss[4][2];
	m_fW1900Loss4 = m_fPathLoss[4][3];
	m_fW1900Loss5 = m_fPathLoss[4][4];
	m_fW1900Loss6 = m_fPathLoss[4][5];
	m_fW1900Loss7 = m_fPathLoss[4][6];
	m_fW1900Loss8 = m_fPathLoss[4][7];
	m_fW1900Loss9 = m_fPathLoss[4][8];
	m_fW1900Loss10 = m_fPathLoss[4][9];
	m_fW1900Loss11 = m_fPathLoss[4][10];
	m_fW1900Loss12 = m_fPathLoss[4][11];
	m_fW1900Loss13 = m_fPathLoss[4][12];
	m_fW1900Loss14 = m_fPathLoss[4][13];
	m_fW1900Loss15 = m_fPathLoss[4][14];
	m_fW1900Loss16 = m_fPathLoss[4][15];
	m_fW1900Loss17 = m_fPathLoss[4][16];
	m_fW1900Loss18 = m_fPathLoss[4][17];
	m_fW1900Loss19 = m_fPathLoss[4][18];
	m_fW1900Loss20 = m_fPathLoss[4][19];
	m_fW2100Loss1 = m_fPathLoss[5][0];
	m_fW2100Loss2 = m_fPathLoss[5][1];
	m_fW2100Loss3 = m_fPathLoss[5][2];
	m_fW2100Loss4 = m_fPathLoss[5][3];
	m_fW2100Loss5 = m_fPathLoss[5][4];
	m_fW2100Loss6 = m_fPathLoss[5][5];
	m_fW2100Loss7 = m_fPathLoss[5][6];
	m_fW2100Loss8 = m_fPathLoss[5][7];
	m_fW2100Loss9 = m_fPathLoss[5][8];
	m_fW2100Loss10 = m_fPathLoss[5][9];
	m_fW2100Loss11 = m_fPathLoss[5][10];
	m_fW2100Loss12 = m_fPathLoss[5][11];
	m_fW2100Loss13 = m_fPathLoss[5][12];
	m_fW2100Loss14 = m_fPathLoss[5][13];
	m_fW2100Loss15 = m_fPathLoss[5][14];
	m_fW2100Loss16 = m_fPathLoss[5][15];
	m_fW2100Loss17 = m_fPathLoss[5][16];
	m_fW2100Loss18 = m_fPathLoss[5][17];
	m_fW2100Loss19 = m_fPathLoss[5][18];
	m_fW2100Loss20 = m_fPathLoss[5][19];

	UpdateData(FALSE);
	return TRUE;
}
