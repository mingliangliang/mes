// PrintSetting.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
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
	m_csColor = _T("");
	m_csColorSub = _T("");
	m_csOffset = _T("");
	m_csOffsetSub = _T("");
	//}}AFX_DATA_INIT
}


void CPrintSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintSetting)
	DDX_Text(pDX, IDC_EDIT_COLOR, m_csColor);
	DDX_Text(pDX, IDC_EDIT_COLOR_SUB, m_csColorSub);
	DDX_Text(pDX, IDC_EDIT_OFFSET, m_csOffset);
	DDX_Text(pDX, IDC_EDIT_OFFSET_SUB, m_csOffsetSub);
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
	CStdioFile fp,fp1;
	CString temp,cstemp;
	CString CommandBuff1,CommandBuff2;
	int ibias1,ibias2;
	
	if (!fp.Open(csLocalPath+"\\CartonResource.txt",CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The pallet print resources file not found!");
		return FALSE;
	}
	else
	{
		temp.Empty();
		CommandBuff1.Empty();
		CommandBuff2.Empty();

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
		fp.Close();
	}

	if (!fp1.Open(csLocalPath+"\\CartonResource_Sub.txt",CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The pallet print resources file not found!");
		return FALSE;
	}
	else
	{
		temp.Empty();
		CommandBuff1.Empty();
		CommandBuff2.Empty();

		while(fp1.ReadString(temp))
		{
			if(temp.Find("^LH")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("^LH");
				ioffset31 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset32 = ibias2;
						m_csOffsetSub = CommandBuff2.Left(ibias2);
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
				ioffset41 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset42 = ibias2;
						m_csColorSub = CommandBuff2.Left(ibias2);
						break;
					}
					ibias2++;
				}
			}

			continue;
		}
		fp1.Close();
	}

	UpdateData(FALSE);

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
	
	if (!fp.Open(csLocalPath+"\\CartonResource.txt",CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The pallet print resources file not found!");
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

		DeleteFile(csLocalPath+"\\CartonResource.txt");

		fp1.Open(csLocalPath+"\\CartonResource.txt",CFile::modeWrite | CFile::typeBinary| CFile::modeCreate);
		fp1.WriteString(CommandBuff3);
		fp1.Close();   
	}

	temp.Empty();
	CommandBuff1.Empty();
	CommandBuff2.Empty();
	CommandBuff3.Empty();

	if (!fp.Open(csLocalPath+"\\CartonResource_Sub.txt",CFile::modeRead | CFile::typeBinary))
	{
		MessageBox("The pallet print resources file not found!");
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
				ioffset31 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset32 = ibias2;
						break;
					}
					ibias2++;
				}
				temp.Delete(ioffset31,ioffset32);
				temp.Insert(ioffset31,m_csOffsetSub);
			}

			if(temp.Find("~SD")!=-1)
			{
				ibias2 = 0;
				CommandBuff1 = temp;
				ibias1 = CommandBuff1.Find("~SD");
				ioffset41 = ibias1 + 3;
				CommandBuff2 = CommandBuff1.Right(CommandBuff1.GetLength() - ibias1 - 3);
				while (1)
				{
					cstemp = CommandBuff2.Mid(ibias2,1);
					if (cstemp == "^" || cstemp == "~")
					{
						ioffset42 = ibias2;
						break;
					}
					ibias2++;
				}
				temp.Delete(ioffset41,ioffset42);
				temp.Insert(ioffset41,m_csColorSub);
			}

			CommandBuff3+=temp+"\r\n";

			continue;
		}

		UpdateData(FALSE);

		fp.Close();

		DeleteFile(csLocalPath+"\\CartonResource_Sub.txt");

		fp1.Open(csLocalPath+"\\CartonResource_Sub.txt",CFile::modeWrite | CFile::typeBinary| CFile::modeCreate);
		fp1.WriteString(CommandBuff3);
		fp1.Close();   
	}

	CDialog::OnOK();
}
