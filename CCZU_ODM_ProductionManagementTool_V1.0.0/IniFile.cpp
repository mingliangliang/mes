// IniFile.cpp: implementation of the CIniFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IniFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define C1 92845
#define C2 72719
#define wkey 8314

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIniFile::CIniFile()
{

}

CIniFile::~CIniFile()
{

}


int CIniFile::ReadInt(char *SectionName, char *KeyName, int Dv)
{
	int i;
	i = GetPrivateProfileInt(SectionName,KeyName,Dv,this->m_csIniFileName);
	return i;
}

CString CIniFile::ReadStr(char *SectionName, char *KeyName, const char *Dv)
{
	CString Tmp;
	char Temp[256];
	GetPrivateProfileString(SectionName,KeyName,Dv,Temp,255,this->m_csIniFileName);
	Tmp = Temp;
	return Tmp;
}

double CIniFile::ReadD(char *SectionName, char *KeyName, double Dv)
{
	char Temp[33],Tmp[25];
	double dt;
	sprintf(Temp,"%4.2f",Dv);
    GetPrivateProfileString(SectionName,KeyName,Temp,Tmp,32,this->m_csIniFileName);
    dt = atof(Tmp);
	return dt;
}

void CIniFile::StoreInt(char *SectionName, char *keyName, int nV)
{
	char Temp[32];
	sprintf(Temp,"%d",nV);
	WritePrivateProfileString(SectionName,keyName,Temp,this->m_csIniFileName);
	
}

void CIniFile::StoreStr(char *SectionName, char *KeyName, CString csV)
{
	WritePrivateProfileString(SectionName,KeyName,csV,this->m_csIniFileName);
}

void CIniFile::StoreD(char *SectionName, char *KeyName, double dV)
{
	
	char Temp[32];
	sprintf(Temp,"%4.2f",dV);
	WritePrivateProfileString(SectionName,KeyName,Temp,this->m_csIniFileName);
	
}

bool CIniFile::ReadB(char *SectionName, char *KeyName, bool Bv)
{
	int i;
	if (Bv)
		i = GetPrivateProfileInt(SectionName,KeyName,1,this->m_csIniFileName);
	else
		i = GetPrivateProfileInt(SectionName,KeyName,0,this->m_csIniFileName);
	if (i>0)
		return true;
	else
		return false;
}

void CIniFile::StoreB(char *SectionName, char *KeyName, bool Dv)
{  
	if (Dv)
		WritePrivateProfileString(SectionName,KeyName,"1",this->m_csIniFileName);
	else
		WritePrivateProfileString(SectionName,KeyName,"0",this->m_csIniFileName);
}

int CIniFile::ReadInt_Ex(char *SectionName, char *KeyName, int Dv, int iparameter)
{
	int i=0;
	CString Tmp;
	char Temp[1000];
	CString encryptioncsV;

	GetPrivateProfileString(SectionName,KeyName,"",Temp,1000,this->m_csIniFileName);
	Tmp = Temp;
	encryptioncsV = Decrypt(Tmp,wkey,iparameter);
	i = atoi((LPTSTR)(LPCTSTR)encryptioncsV);
	return i;
}

CString CIniFile::ReadStr_Ex(char *SectionName, char *KeyName, const char *Dv, int iparameter)
{
	CString Tmp;
	char Temp[1000];
	CString encryptioncsV;

	GetPrivateProfileString(SectionName,KeyName,Dv,Temp,1000,this->m_csIniFileName);
	Tmp = Temp;
	encryptioncsV = Decrypt(Tmp,wkey,iparameter);
	return encryptioncsV;
}

double CIniFile::ReadD_Ex(char *SectionName, char *KeyName, double Dv, int iparameter)
{
	CString encryptioncsV;
	char Temp[33],Tmp[25];
	double dt;

	sprintf(Temp,"%4.2f",Dv);
    GetPrivateProfileString(SectionName,KeyName,Temp,Tmp,32,this->m_csIniFileName);
	encryptioncsV = Decrypt(Tmp,wkey,iparameter);
    dt = atof(encryptioncsV);
	return dt;
}

bool CIniFile::ReadB_Ex(char *SectionName, char *KeyName, bool Bv, int iparameter)
{
	int i = 0;
	CString Tmp;
	char Temp[1000];
	CString encryptioncsV;

	GetPrivateProfileString(SectionName,KeyName,"",Temp,1000,this->m_csIniFileName);
	Tmp = Temp;
	encryptioncsV = Decrypt(Tmp,wkey,iparameter);
	i = atoi((LPTSTR)(LPCTSTR)encryptioncsV);

	if (i)
		return true;
	else
		return false;
}

void CIniFile::StoreInt_Ex(char *SectionName, char *keyName, int nV, int iparameter)
{
	char Temp[32];
	CString encryptioncsV;

	sprintf(Temp,"%d",nV);
	encryptioncsV = Encrypt(Temp,wkey,iparameter);
	WritePrivateProfileString(SectionName,keyName,encryptioncsV,this->m_csIniFileName);
}

void CIniFile::StoreStr_Ex(char *SectionName, char *KeyName, CString csV, int iparameter)
{
	CString encryptioncsV;

	encryptioncsV = Encrypt(csV,wkey,iparameter);
	WritePrivateProfileString(SectionName,KeyName,encryptioncsV,this->m_csIniFileName);
}

void CIniFile::StoreD_Ex(char *SectionName, char *KeyName, double dV, int iparameter)
{
	CString encryptioncsV;
	char Temp[32];

	sprintf(Temp,"%4.2f",dV);
	encryptioncsV = Encrypt(Temp,wkey,iparameter);
	WritePrivateProfileString(SectionName,KeyName,encryptioncsV,this->m_csIniFileName);
}

void CIniFile::StoreB_Ex(char *SectionName, char *KeyName, bool Dv, int iparameter)
{
	char Temp[32];
	CString encryptioncsV;
	
	if (Dv)
		sprintf(Temp,"%d",1);
	else
		sprintf(Temp,"%d",0);

	encryptioncsV = Encrypt(Temp,wkey,iparameter);
	WritePrivateProfileString(SectionName,KeyName,encryptioncsV,this->m_csIniFileName);
}


CString CIniFile::Encrypt(CString S, WORD Key, int iPara) //加密函数
{
	CString Result,str;
	int i,j;
	
	Result=S; // 初始化结果字符串
	for(i=0; i<S.GetLength(); i++) // 依次对字符串中各字符进行操作
	{
		Result.SetAt(i, S.GetAt(i)^(Key>>8)); // 将密钥移位后与字符异或
		Key = ((BYTE)Result.GetAt(i)+Key)*C1+C2; // 产生下一个密钥
	}
	S=Result; // 保存结果
	Result.Empty(); // 清除结果
	for(i=0; i<S.GetLength(); i++) // 对加密结果进行转换
	{
		j=(BYTE)S.GetAt(i); // 提取字符
		// 将字符转换为两个字母保存
		str="12"; // 设置str长度为2
		str.SetAt(0, iPara+j/26);//这里将65改大点的数例如256，密文就会变乱码，效果更好，相应的，解密处要改为相同的数
		str.SetAt(1, iPara+j%26);
		Result += str;
	}
	return Result;
}

CString CIniFile::Decrypt(CString S, WORD Key, int iPara) // 解密函数
{
	CString Result,str;
	int i,j;
	
	Result.Empty(); // 清除结果
	for(i=0; i < S.GetLength()/2; i++) // 将字符串两个字母一组进行处理
	{
		j = ((BYTE)S.GetAt(2*i)-iPara)*26;//相应的，解密处要改为相同的数
		j += (BYTE)S.GetAt(2*i+1)-iPara;
		str="1"; // 设置str长度为1
		str.SetAt(0, j);
		Result+=str; // 追加字符，还原字符串
	}
	S=Result; // 保存中间结果
	for(i=0; i<S.GetLength(); i++) // 依次对字符串中各字符进行操作
	{
		Result.SetAt(i, (BYTE)S.GetAt(i)^(Key>>8)); // 将密钥移位后与字符异或
		Key = ((BYTE)S.GetAt(i)+Key)*C1+C2; // 产生下一个密钥
	}
	return Result;
}
