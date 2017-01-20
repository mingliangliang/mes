// PrintSetting.cpp : implementation file
//

#include "stdafx.h"
#include "ColorBox.h"
#include "PrintSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintSetting dialog


CPrintSetting::CPrintSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintSetting)
	m_csOffset = _T("");
	m_csColor = _T("");
	//}}AFX_DATA_INIT
}


void CPrintSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintSetting)
	DDX_Text(pDX, IDC_EDIT_OFFSET, m_csOffset);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_csColor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintSetting, CDialog)
	//{{AFX_MSG_MAP(CPrintSetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintSetting message handlers

BOOL CPrintSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CStdioFile fp;
	CString temp,cstemp;
	CString CommandBuff1,CommandBuff2;
	int ibias1,ibias2;
	temp.Empty();
	CommandBuff1.Empty();
	CommandBuff2.Empty();
	
	if (!fp.Open(csLocalPath,CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The type of color print resources file Can not be founded!");
		return FALSE;
	}
	else
	{
		while(fp.ReadString(temp))
		{
			if(temp.Find("^LH")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("^LH");
				ioffset11 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset12 = ibias2;
						m_csOffset = CommandBuff2.Left(ibias2);
						break;
					}
					ibias2++;
				}
			}

			if(temp.Find("~SD")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("~SD");
				ioffset21 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset22 = ibias2;
						m_csColor = CommandBuff2.Left(ibias2);
						break;
					}
					ibias2++;
				}
			}

			continue;
		}

		UpdateData(FALSE);

		fp.Close();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CPrintSetting::OnOK() 
{
	CStdioFile fp,fp1;
	CString temp,cstemp;
	CString CommandBuff1,CommandBuff2,CommandBuff3;
	int ibias1,ibias2;
	temp.Empty();
	CommandBuff1.Empty();
	CommandBuff2.Empty();
	CommandBuff3.Empty();

	UpdateData();
	
	if (!fp.Open(csLocalPath,CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The type of color print resources file Can not be founded!");
		return;
	}
	else
	{
		while(fp.ReadString(temp))
		{
			if(temp.Find("^LH")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("^LH");
				ioffset11 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset12 = ibias2;
						break;
					}
					ibias2++;
				}
				temp.Delete(ioffset11,ioffset12);
				temp.Insert(ioffset11,m_csOffset);
			}

			if(temp.Find("~SD")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("~SD");
				ioffset21 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset22 = ibias2;
						break;
					}
					ibias2++;
				}
				temp.Delete(ioffset21,ioffset22);
				temp.Insert(ioffset21,m_csColor);
			}

			CommandBuff3+=temp+"\r\n";

			continue;
		}

		UpdateData(FALSE);

		fp.Close();

		DeleteFile(csLocalPath);

		fp1.Open(csLocalPath,CFile::modeWrite | CFile::typeBinary| CFile::modeCreate);
		fp1.WriteString(CommandBuff3);
		fp1.Close();   
	}

	CDialog::OnOK();
}
