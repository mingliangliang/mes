// Config.h: interface for the CConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONFIG_H__169027B2_4A54_4F44_8E69_415F8AA9B663__INCLUDED_)
#define AFX_CONFIG_H__169027B2_4A54_4F44_8E69_415F8AA9B663__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IniFile.h"
class CConfig  
{
public:
	CConfig();
	virtual ~CConfig();
public:
	CIniFile m_iniFile;

	//[Database Setting]
	CString	m_csServer;
	CString m_csDatabaseName;
	CString	m_csUserName;
	CString	m_csPassword;
	CString m_csCFGPath;
	CString	m_csLoginName;
	CString m_csLoginPSW;
	int     m_iHandleMode;
	int     m_iIsScanMainImei;
	
public:
	void InitConfigPath();
	void ReadConfig();
	void SaveConfig();
};

#endif // !defined(AFX_CONFIG_H__169027B2_4A54_4F44_8E69_415F8AA9B663__INCLUDED_)
