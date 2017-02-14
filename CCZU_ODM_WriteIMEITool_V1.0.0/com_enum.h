/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  com_enum.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  Enumerate serial ports.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef _COM_ENUM_H_
#define _COM_ENUM_H_

#define	COM_ENUM_OK						0
#define	COM_ENUM_INVALID_ARGUMENT		1
#define	COM_ENUM_NO_COM_PORT_FOUND		2
#define	COM_ENUM_COM_ARRAY_TOO_SMALL	3
#define	COM_ENUM_ERROR					4

typedef enum {
	COM_ENUM_BY_CREATEFILE = 0,
	COM_ENUM_BY_REGISTRY,
        COM_ENUM_BY_LIBUDEV
} COM_ENUM_METHOD;

// Hardware ID structure
typedef struct {
	unsigned int id_count;      // valid id count
	const char **usb_id;        // hw id string array ex:usb_id[0] = "VID_0E8D&PID_0003", usb_id[1] = "VID_0E8D&PID_00A2&Rev_0200"
} COM_USB_Valid_ID;

// BCD device ID structure
typedef struct {
	unsigned int id_count;      // valid id count
	const char **bcd_id;        // bcd id string array  ex:bcd_id[0] = "0100", bcd_id[1] = "0200"
} COM_USB_BCD_DEVICE;
// BCD device means release version, which placed in the Rev_XXXX in comport hardware identify
// Example: VID_0E8D&PID_0003&Rev_0100    bcd device = "0100"

#if defined(__GNUC__) && !defined(__stdcall)
#   define __stdcall
#endif


#ifdef	__cplusplus
extern "C" {
#endif

extern int __stdcall ComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
extern int __stdcall ComPortEnumerateWithPrefix(unsigned short *p_com_port_array, unsigned short *p_com_port_count, const char *registryValuePrefix);
extern int __stdcall ComPortEnumerateEx(COM_ENUM_METHOD  method, unsigned short *p_com_port_array, unsigned short *p_com_port_count);
extern int __stdcall UsbComPortEnumerate(unsigned short *p_com_port_array, unsigned short *p_com_port_count);
extern int __stdcall ComPortEnumerateWithFilterHardwareID(unsigned short *p_com_port_array, unsigned short *p_com_port_count, COM_USB_Valid_ID *hwID);
extern int __stdcall ComPortEnumerateWithFilterBCDDevice(unsigned short *p_com_port_array, unsigned short *p_com_port_count, COM_USB_BCD_DEVICE *bcdDevice);

#ifdef __APPLE__
#define DL_PORT_VID 0x0e8d
#define DL_PORT_PID 0x0003

#define kIOProductIDKey         "idProduct"
#define kIOVendorIDKey          "idVendor"
#define kIOBCDDeviceKey         "bcdDevice"
#define kIOInterfaceNumberKey   "bInterfaceNumber"

//Set bcdDevice = 0 --> Get com port without the condition of bcdDevice value
extern bool GetDynamicComPort(char *deviceFilePath, unsigned int maxPathSize, int vid = DL_PORT_VID, int pid = DL_PORT_PID, int bcdDevice = 0);
#endif

#ifdef	__cplusplus
}
#endif

#endif
