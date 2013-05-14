#ifdef __SDCC
// const unsigned char __at(0xFFB8) CHECKSUM_HOLD_HIGH = 0x00;
// const unsigned char __at(0xFFB9) CHECKSUM_HOLD_LOW = 0x00;
// const unsigned char __at(0xFFBA) CHECKSUM_BYPASS = 0xFF;
#else
#define __at(x)
#define __data
#define __xdata
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
  SUSPEND       = 6
};

extern enum USB_STATES usb_state;

typedef struct {
  union {
    byte Byte;
    struct {
      byte NONE1        :1;
      byte NONE2        :1;
      byte PID0_STALL   :1;
      byte PID1_DTS     :1;
      byte PID2         :1;
      byte PID3         :1;
      byte DATA01       :1;
      byte OWN          :1;
    } Bits;
  } Info;
  byte Length;
  byte Address;
} USB_BD;

#define USB_RAM_START = 0x1860;
volatile __xdata USB_BD __at(USB_RAM_START) USB_EP0_IN;
volatile __xdata USB_BD __at(USB_RAM_START+0x03) USB_EP0_OUT;


void init_system(void);
void init_mcb(void);
void init_usb(void);