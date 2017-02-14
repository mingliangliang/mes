#if !defined  _USB_COM_FINDER_H_
#define		  _USB_COM_FINDER_H_

#include <objbase.h>
//#include <initguid.h>


#ifdef __cplusplus
extern "C" {
#endif

    extern BOOL __stdcall GetPresentDevicePath(GUID guid,
            const char * pPID,
            const char * pVID,
            unsigned long index,
            char *pPortName,
            unsigned long portNameLength,
            unsigned long * portNameRealLength,
            char *pSymbolicName,
            unsigned long symbolicLength,
            unsigned long * symbolicRealLength);

    extern unsigned long __stdcall GetDeviceNumber(GUID guid, const char * p_pid, const char * p_vid);

#ifdef __cplusplus
};
#endif



#endif		  //_USB_COM_FINDER_H_
