// Config.cpp: implementation of the CConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Config.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//加密所需参数
#define iParam1 35
#define iParam2 46
#define iParam3 210
#define iParam4 222
#define iParam5 350
#define iParam6 460

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConfig::CConfig()
{

}

CConfig::~CConfig()
{

}

void CConfig::InitConfigPath()
{
	char Temp[MAX_PATH];
	
	GetCurrentDirectory(MAX_PATH, Temp);
	this->m_iniFile.m_csIniFileName = Temp;
	this->m_iniFile.m_csIniFileName += "\\config.ini";
}


void CConfig::ReadConfig()
{
	//[Database Setting]
	this->m_csServer         = this->m_iniFile.ReadStr_Ex("Database Setting","Server","",iParam1);
	this->m_csDatabaseName   = this->m_iniFile.ReadStr_Ex("Database Setting","Database","",iParam2);
	this->m_csUserName       = this->m_iniFile.ReadStr_Ex("Database Setting","SQL_User","",iParam3);
	this->m_csPassword       = this->m_iniFile.ReadStr_Ex("Database Setting","SQL_Password","",iParam4);
	this->m_csCFGPath        = this->m_iniFile.ReadStr("Database Setting","Pack_CFG_PATH","");
	this->m_csLoginName      = this->m_iniFile.ReadStr_Ex("Database Setting","Login_Name","",iParam5);
	this->m_csLoginPSW       = this->m_iniFile.ReadStr_Ex("Database Setting","Login_Password","",iParam6);
	
	this->m_iHandleMode      = this->m_iniFile.ReadInt("Control","HandleMode",1);
	this->m_iIsScanMainImei  = this->m_iniFile.ReadInt("Control","IsScanMainImei",0);
}


void CConfig::SaveConfig()
{
	//[Database Setting]
	this->m_iniFile.StoreStr_Ex("Database Setting","Server",this->m_csServer,iParam1);
	this->m_iniFile.StoreStr_Ex("Database Setting","Database",this->m_csDatabaseName,iParam2);
	this->m_iniFile.StoreStr_Ex("Database Setting","SQL_User",this->m_csUserName,iParam3);
	this->m_iniFile.StoreStr_Ex("Database Setting","SQL_Password",this->m_csPassword,iParam4);
	this->m_iniFile.StoreStr("Database Setting","Pack_CFG_PATH",this->m_csCFGPath);
	this->m_iniFile.StoreStr_Ex("Database Setting","Login_Name",this->m_csLoginName,iParam5);
	this->m_iniFile.StoreStr_Ex("Database Setting","Login_Password",this->m_csLoginPSW,iParam6);
	
	this->m_iniFile.StoreInt("Control","HandleMode",this->m_iHandleMode);
	this->m_iniFile.StoreInt("Control","IsScanMainImei",this->m_iIsScanMainImei);
}
