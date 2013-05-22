#ifdef __SDCC
// const unsigned char __at(0xFFB8) CHECKSUM_HOLD_HIGH = 0x00;
// const unsigned char __at(0xFFB9) CHECKSUM_HOLD_LOW = 0x00;
// const unsigned char __at(0xFFBA) CHECKSUM_BYPASS = 0xFF;
#else
#define __at(x)
#define __data
#define __xdata
#define __asm__(x)
#endif

#include "../include/mc9s08js16l.h"

/*
4  PTB0 Device Suspend
5  PTB1 Device Ready
7  PTB3 Device Delay Init
8  PTA0 Device Reset
9  PAT1 TCK
10 PTA2 TDI (device->s08)
11 PTA3 TMS
12 PTA4 TDO (s08->device)
18 PTA5 Fet
19 PTA6 Rx (device->s08)
20 PTA7 Tx (s08->device)
*/

enum USB_STATES {
  POWERED       = 0,
  ATTACHED      = 1,
  DEFAULT       = 2,
  ADDR_PENDING  = 3,
  ADDRESSED     = 4,
  CONFIGURED    = 5,
  WAIT_SUSPEND  = 6,
  SUSPEND       = 7,
  USB_POWER     = 8,
  BOOTLOADER    = 9
};

/*@i@*/ extern enum USB_STATES usb_state;

typedef struct {
  union {
    byte Byte;
    struct {
      byte              :1;
      byte              :1;
      byte STALL        :1;
      byte DTS          :1;
      byte              :1;
      byte              :1;
      byte DATA         :1;
      byte OWN          :1;
    } Write;
    struct {
      byte              :2;
      byte PID          :4;
      byte              :1;
      byte OWN          :1;
    } Read;
  } Info;
  byte Length;
  byte Address;
} USB_BD;

#define USB_RAM_START 0x1860
volatile __xdata USB_BD __at(USB_RAM_START) USB_EP0_IN;
volatile __xdata USB_BD __at(USB_RAM_START+0x03) USB_EP0_OUT;
volatile __xdata USB_BD __at(USB_RAM_START+0x06) USB_IF1_IN;
volatile __xdata USB_BD __at(USB_RAM_START+0x09) USB_IF1_OUT;

#define USB_EP0_IN_BUFF   32
#define USB_EP0_OUT_BUFF  48
#define USB_EP0_LENGTH    8
#define USB_BD_DTS        8
#define USB_BD_DATA1      64
#define USB_BD_OWN        128
#define USB_IF1_BUFF1     64
#define USB_IF1_BUFF2     128
#define USB_IF1_BUFF3     192
#define USB_IF1_BUFF_L    64


void init_system(void);
void init_mcb(void);
void init_usb(void);
void usb_loop(void);
void usb_ep0_token(void);
void usb_ep0_prep_setup(void);
void usb_ep1_token(void);
void usb_ep2_token(void);
void usb_ep2_loop(void);