#include "main.h"


//Set up endpoint
//Add interface definition
//Ep1 is IN    EPCTL1 = 0b00101
//EP2 is OUT   EPCTL2 = 0b01001
//64 byte buffers each
//Setup USB_IF1_OUT for the first receive command

/*
  GPIO0                       TCK
  GPIO1                       TDI
  GPIO2                       TDO (input)
  GPIO3                       TMS

  < 0x80 follows:
    bit 0:                    Write on -ve (1) clock
    bit 1:                    bit mode (1) or byte mode (0)
    bit 2:                    Read on -ve (1) clock
    bit 3:                    LSB (1) first
    bit 4:                    Write TDI
    bit 5:                    Read TDO
    bit 6:                    Write TMS

  bit, length                 Write length+1 bits from the next byte
  byte, lenL, lenH            Write the next length+1 bytes
  TMS mode                    Set TDI to bit 7 for the duration
  TMS must be TDI=0 and bit mode

  0x80, value, dir:           Write (dir=1) or read from first 8 gpio (sets default clock state)
  0x81                        Read from first 8 gpio
  0x82, value, dir            Write (dir=1) or read from last 8 gpio
  0x83                        Read from last 8 gpio
  0x84                        Loopback TDO <- TDI
  0x85                        Undo Loopback
  0x86                        Set clock frequency (don't support)
  0x87                        Send immediate
  0x88                        Wait till GPIOL1 = 1 (don't support)
  0x89                        Wait till GPIOL1 = 0 (don't support)
  0x8E, len                   Clock 1+len (len<8) times
  0x8F, lenL, lenH            Clock 8*(len+1) times
  0x94                        Clock till GPIOL1 = 1 (don't support)
  0x95                        Clock till GPIOL1 = 0 (don't support)
  0x96                        Adaptive clocking (don't support)
  0x97                        Disable Adaptive (don't support)
  0x9c, lenL, lenH            Combine 0x8F and 0x94 (don't suport)
  0x9d, lenL, lenH            Combine 0x8F and 0x95 (don't support)

  PTAD_PTAD1 TCK
  PTAD_PTAD2 (device->s08)
  PTAD_PTAD3 TMS
  PTAD_PTAD4 (s08->device)
*/

static const byte *IF1_BUFF1 = (byte *)(USB_RAM_START+USB_IF1_BUFF1);
static const byte *IF1_BUFF2 = (byte *)(USB_RAM_START+USB_IF1_BUFF2);
static const byte *IF1_BUFF3 = (byte *)(USB_RAM_START+USB_IF1_BUFF3);

enum BUFF_STATE {
  UNUSED    = 0,
  RX        = 1,
  WORK      = 2,
  DONE      = 3,
  TX        = 4
};

typedef union {
  struct {
    byte writeN   :1;
    byte bitMode  :1;
    byte readN    :1;
    byte LSB      :1;
    byte write    :1;
    byte read     :1;
    byte tms      :1;
    byte cmd      :1;
  } Bits;
  byte Byte;
} sCommand;

static enum BUFF_STATE buff1_state = UNUSED;
static enum BUFF_STATE buff2_state = UNUSED;
static enum BUFF_STATE buff3_state = UNUSED;

static byte buff1_length = 0;
static byte buff2_length = 0;
static byte buff3_length = 0;

static void usb_ep2_work(byte number) {
  byte *pRead;
  byte *pWrite;
  byte *pEnd;
  sCommand *command;
  byte length;

  switch (number) {
    case 1:
      pRead = pWrite = IF1_BUFF1;
      pEnd = IF1_BUFF1 + buff1_length;
      break;
    case 2:
      pRead = pWrite = IF1_BUFF2;
      pEnd = IF1_BUFF2 + buff2_length;
      break;
    case 3:
      pRead = pWrite = IF1_BUFF3;
      pEnd = IF1_BUFF3 + buff3_length;
      break;
    default:
      return;
  }
  //Start at 1 and process through for length
  while (pRead < pEnd) {
    command = (sCommand *)pRead++;

    if (command->Bits.cmd == 0) {
      if (command->Bits.bitMode > 0) {
        //Bit mode
        if (command->Bits.tms > 0) {
          //TMS mode
        } else {
          //Normal mode
          length = *pRead++ + 1;

        }
      } else {
        //Byte mode
      }
    }
  }

  switch (number) {
    case 1:
      buff1_length = pRead - IF1_BUFF1;
      buff1_state = DONE;
      break;
    case 2:
      buff2_length = pRead - IF1_BUFF2;
      buff2_state = DONE;
      break;
    case 3:
      buff3_length = pRead - IF1_BUFF3;
      buff3_state = DONE;
      break;
  }
}

static void usb_ep1_set(byte number) {
  switch (number) {
    case 1:
      USB_IF1_IN.Address = USB_IF1_BUFF1>>2;
      USB_IF1_IN.Length = buff1_length;
      break;
    case 2:
      USB_IF1_IN.Address = USB_IF1_BUFF2>>2;
      USB_IF1_IN.Length = buff2_length;
      break;
    case 3:
      USB_IF1_IN.Address = USB_IF1_BUFF3>>2;
      USB_IF1_IN.Length = buff3_length;
      break;
  }
  if (USB_IF1_IN.Info.Write.DATA > 0) {
    USB_IF1_IN.Info.Byte = USB_BD_OWN;
  } else {
    USB_IF1_IN.Info.Byte = USB_BD_OWN | USB_BD_DATA1;
  }
}

static void usb_ep2_set(byte number) {
  switch (number) {
    case 1:
      USB_IF1_OUT.Address = USB_IF1_BUFF1>>2;
      break;
    case 2:
      USB_IF1_OUT.Address = USB_IF1_BUFF2>>2;
      break;
    case 3:
      USB_IF1_OUT.Address = USB_IF1_BUFF3>>2;
      break;
  }
  if (USB_IF1_OUT.Info.Write.DATA > 0) {
    USB_IF1_OUT.Info.Byte = USB_BD_OWN | USB_BD_DTS;
  } else {
    USB_IF1_OUT.Info.Byte = USB_BD_OWN | USB_BD_DATA1 | USB_BD_DTS;
  }
}

void usb_ep2_loop() {
  //Ensure a RX is allocated
  if (buff1_state != RX && buff2_state != RX && buff3_state != RX) {
    if (buff1_state == UNUSED) {
      usb_ep2_set(1);
    } else if (buff2_state == UNUSED) {
      usb_ep2_set(2);
    } else if (buff3_state == UNUSED) {
      usb_ep2_set(3);
    }
  }

  //If there is a DONE and no TX, make into TX
  if (buff1_state != TX && buff2_state != TX && buff3_state != TX) {
    if (buff1_state == DONE) {
      usb_ep1_set(1);
    } else if (buff2_state == DONE) {
      usb_ep1_set(2);
    } else if (buff3_state == DONE) {
      usb_ep1_set(3);
    }
  }

  //If there is a WORK, make into a DONE
  if (buff1_state == WORK) {
    usb_ep2_work(1);
  } else if (buff2_state == WORK) {
    usb_ep2_work(2);
  } else if (buff3_state == WORK) {
    usb_ep2_work(3);
  }
}

void usb_ep1_token() {
  //Set a TX to UNUSED
}

void usb_ep2_token() {
  //Set a RX to WORK 
}
