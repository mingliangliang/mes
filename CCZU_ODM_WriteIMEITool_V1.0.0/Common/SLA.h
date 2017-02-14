#ifndef _SLA_H_
#define _SLA_H_  

#include "SLA_Challenge.h"
#include "flashtool_handle.h"
/*
typedef struct
{

	 int m_bIsRunning;
	 int m_iConfirmState;   
	  AUTH_HANDLE_T  m_sAuthHandle;        
}CSLA;
CSLA SLA_Obj;		  
*/
  

extern AUTH_HANDLE_T Get_AuthHandle( void );

extern int Get_ConfirmState( void ); 
extern int REQ_AUTH_Unload( void ); 
extern int REQ_AUTH_Load(const char *auth_filepath );  
extern int REQ_AUTH_Destroy( void );  
extern int REQ_AUTH_Create( void ); 

#endif
