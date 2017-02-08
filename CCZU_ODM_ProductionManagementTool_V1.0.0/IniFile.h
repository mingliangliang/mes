// IniFile.h: interface for the CIniFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INIFILE_H__88BC3B06_B3C9_4AF0_85E8_267482CB5768__INCLUDED_)
#define AFX_INIFILE_H__88BC3B06_B3C9_4AF0_85E8_267482CB5768__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIniFile  
{
public:
	CIniFile();
	virtual ~CIniFile();
public:
	CString m_csIniFileName;
public:
	int     ReadInt(char *SectionName,char *keyName,int Dv);
	CString ReadStr(char *SectionName,char *KeyName,const char *Dv);
	double  ReadD(char *SectionName,char *KeyName,double Dv);
	bool    ReadB(char *SectionName, char *KeyName, bool Bv);
	void    StoreB(char *SectionName, char *KeyName, bool Dv);
	void    StoreD(char *SectionName,char *KeyName,double dV);
	void    StoreStr(char *SectionName,char *KeyName,CString csV);
	void    StoreInt(char *SectionName,char *keyName,int nV);
	CIniFile(CString csFileName);

	//加密操作
	int     ReadInt_Ex(char *SectionName,char *keyName,int Dv,int iparameter);
	CString ReadStr_Ex(char *SectionName,char *KeyName,const char *Dv,int iparameter);
	double  ReadD_Ex(char *SectionName,char *KeyName,double Dv,int iparameter);
	bool    ReadB_Ex(char *SectionName, char *KeyName, bool Bv,int iparameter);

	void    StoreInt_Ex(char *SectionName,char *keyName,int nV,int iparameter);
	void    StoreStr_Ex(char *SectionName,char *KeyName,CString csV,int iparameter);
	void    StoreD_Ex(char *SectionName,char *KeyName,double dV,int iparameter);
	void    StoreB_Ex(char *SectionName, char *KeyName, bool Dv,int iparameter);
	
	CString Encrypt(CString S, WORD Key, int iPara); // 加密函数
	CString Decrypt(CString S, WORD Key, int iPara); // 解密函数
};

#endif // !defined(AFX_INIFILE_H__88BC3B06_B3C9_4AF0_85E8_267482CB5768__INCLUDED_)
