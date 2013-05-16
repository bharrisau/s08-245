#include "main.h"
#include "../util/usb_descriptors.h"

#define DIR_RX      (0)
#define DIR_TX      (1<<7)

#define TYPE_STD    (0)
#define TYPE_CLS    (1<<5)
#define TYPE_VEN    (2<<5)

#define RCPT_DEV    (0)
#define RCPT_INT    (1)
#define RCPT_END    (2)

static const byte *EP0_IN_BUFF = (byte *)(USB_RAM_START+USB_EP0_IN_BUFF);
static const byte *EP0_OUT_BUFF = (byte *)(USB_RAM_START+USB_EP0_OUT_BUFF);

// No remote wakeup, bus powered
static const byte usb_device_status[] = {0, 0};

typedef struct {
  byte Recipient  : 5;
  byte Type       : 2;
  byte Direction  : 1;
  byte Request;
  union {
    word Word;
    struct {
      byte Low;
      byte High;
    } Byte;
  } wValue;
  word wIndex;
  word wLength;
} EP0_REQ_TYPE;

static volatile __xdata EP0_REQ_TYPE 
  __at(USB_RAM_START+USB_EP0_OUT_BUFF) ep0_setup_packet;

static enum {
  WAIT_SETUP,
  DATA_TX,
  DATA_RX
} ep0_state = WAIT_SETUP;

static byte *ep0_data_index;
static byte *ep0_data_end;
static byte pending_address;

void usb_ep0_prep_setup() {
  //Prepare EP0 for setup packet
  USB_EP0_OUT.Length = 8;
  USB_EP0_OUT.Info.Byte = 0x88;
}

static void usb_ep0_stall() {
  //Prepare for next setup packet
  usb_ep0_prep_setup();
  //Assert stall
  EPCTL0_EPSTALL = 1;
}

static void usb_ep0_fill_in() {
  byte *p = EP0_IN_BUFF;
  byte i;
  for (i = 0; i < USB_EP0_LENGTH &&
    ep0_data_index < ep0_data_end; p++, i++, ep0_data_index++) {
    *p = *ep0_data_index;
  }
  USB_EP0_IN.Length = i;
  USB_EP0_IN.Info.Byte = 0xC0;

  //Prepare OUT for ack packet
  USB_EP0_OUT.Length = 0;
  USB_EP0_OUT.Info.Byte = 0xC0;
}

static void usb_ep0_in() {
  if (usb_state == ADDR_PENDING) {
    usb_state = ADDRESSED;
    ADDR = pending_address;
  }
  if (ep0_state == DATA_TX) {
    usb_ep0_fill_in();
  } else {
    //Prepare for next setup message
    ep0_state = WAIT_SETUP;
  }
}

static void usb_ep0_out() {
  if (ep0_state == DATA_RX) {
    //All data is <=8 bytes - no more bytes to transfer

  } else {
    //Prepare for next setup message
    ep0_state = WAIT_SETUP;
  }
}

static void usb_ep0_data_write(byte *start, byte length) {
  ep0_state = DATA_TX;
  ep0_data_index = start;
  ep0_data_end = start+length;

  usb_ep0_fill_in();
}

static void usb_ep0_data_read(byte length) {
  //Only supports length = 0;
  ep0_state = DATA_RX;
  USB_EP0_OUT.Length = length;
  USB_EP0_OUT.Info.Byte = 0xC0;

  //Prepare IN for ack packet
  USB_EP0_IN.Length = 0;
  USB_EP0_IN.Info.Byte = 0xC0;
}

static void usb_ep0_standard_device_rx() {
  switch (ep0_setup_packet.Request) {
    case 1:                 //CLEAR_FEATURE
      //Ignore this one
      break;
    case 3:                 //SET_FEATURE
      //Ignore this one
      break;
    case 4:                 //SET_ADDRESS
      usb_state = ADDR_PENDING;
      pending_address = ep0_setup_packet.wValue.Byte.Low;
      break;
    case 7:                 //SET_DESCRIPTOR
      return usb_ep0_stall();      //Not supported
    case 9:                 //SET_CONFIGURATION
      //Lets assume it is picking our ONLY configuration
      usb_state = CONFIGURED;
      break;
    default:
      return usb_ep0_stall();
  }
  usb_ep0_data_read(0);     //Simplify things because we never read > 0
}

static void usb_ep0_standard_device_tx() {
  byte strIndex;

  switch (ep0_setup_packet.Request) {
    case 0:                 //GET_STATUS
      usb_ep0_data_write(usb_device_status, 2);
      break;
    case 6:                 //GET_DESCRIPTOR
      switch (ep0_setup_packet.wValue.Byte.High) {
        case 1:             //Device descriptor
          usb_ep0_data_write(device_descriptor, *device_descriptor);
          break;
        case 2:             //Configuration descriptor
          usb_ep0_data_write(configuration, *configuration);
          break;
        case 3:             //String descriptor
          strIndex = ep0_setup_packet.wValue.Byte.Low;
          if (strIndex > sizeof(strings)/sizeof(strings[0])) {
            return usb_ep0_stall();
          } else {
            byte *str = strings[strIndex];
            usb_ep0_data_write(str, *str);
          }
          break;
        default:
          return usb_ep0_stall();
      }
      break;
    case 8:                 //GET_CONFIGURATION
      if (usb_state == CONFIGURED) {
        strIndex = 1;
      } else {
        strIndex = 0;
      }
      usb_ep0_data_write(&strIndex, 1);
      break;
    default:
      return usb_ep0_stall();
  }
}

static void usb_ep0_standard_interface_rx() {
  // switch (ep0_setup_packet.Request) {
  //   case 1:                 //CLEAR_FEATURE 
  //     break;
  //   case 3:                 //SET_FEATURE 
  //     break;
  //   case 11:                //SET_INTERFACE
  //     break;
  //   default:
  //     return usb_ep0_stall(); //STALL
  // }
  return usb_ep0_stall();
}

static void usb_ep0_standard_interface_tx() {
  // switch (ep0_setup_packet.Request) {
  //   case 0:                 //GET_STATUS
  //     break;
  //   case 10:                //GET_INTERFACE 
  //     break;
  //   default:
  //     return usb_ep0_stall(); //STALL  
  // }
  return usb_ep0_stall();
}

static void usb_ep0_standard_endpoint_rx() {
  // switch (ep0_setup_packet.Request) {
  //   case 1:                 //CLEAR_FEATURE 
  //     break;
  //   case 3:                 //SET_FEATURE 
  //     break;
  //   default:
  //     return usb_ep0_stall(); //STALL
  // }
  return usb_ep0_stall();
}

static void usb_ep0_standard_endpoint_tx() {
  // switch (ep0_setup_packet.Request) {
  //   case 0:                 //GET_STATUS
  //     break;
  //   case 12:                //SYNCH_FRAME 
  //     break;
  //   default:
  //     return usb_ep0_stall(); //STALL  
  // }
  return usb_ep0_stall();
}

static void usb_ep0_vendor_device_rx() {
  switch (ep0_setup_packet.Request) {
    case 0x68:              //Reset to bootloader

    break;
    default:
      usb_ep0_stall();
  }
}

static void usb_ep0_vendor_device_tx() {
  return usb_ep0_stall();
}

static void usb_ep0_setup() {
  ep0_state = WAIT_SETUP;
  switch(*EP0_OUT_BUFF) {
    case TYPE_STD | RCPT_DEV | DIR_RX:
      usb_ep0_standard_device_rx();
      break;
    case TYPE_STD | RCPT_DEV | DIR_TX:
      usb_ep0_standard_device_tx();
      break;
    case TYPE_STD | RCPT_INT | DIR_RX:
      usb_ep0_standard_interface_rx();
      break;
    case TYPE_STD | RCPT_INT | DIR_TX:
      usb_ep0_standard_interface_tx();
      break;
    case TYPE_STD | RCPT_END | DIR_RX:
      usb_ep0_standard_endpoint_rx();
      break;
    case TYPE_STD | RCPT_END | DIR_TX:
      usb_ep0_standard_endpoint_tx();
      break;
    case TYPE_VEN | RCPT_DEV | DIR_RX:
      usb_ep0_vendor_device_rx();
      break;
    case TYPE_VEN | RCPT_DEV | DIR_TX:
      usb_ep0_vendor_device_tx();
      break;
    default:
      usb_ep0_stall();
  }
  CTL_TSUSPEND = 0;
}

void usb_ep0_token() {
  if(STAT_IN == 1) {
    usb_ep0_in();
  } else if(USB_EP0_OUT.Info.Read.PID == 0xD) {
    usb_ep0_setup();
  } else {
    usb_ep0_out();
  }
}