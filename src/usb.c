#include "main.h"
#include "../util/usb_descriptors.h"
//Write the code that polls the status and reacts accordingly.

static void usb_int_resume() {

}

static void usb_int_reset() {
  
}

static void usb_int_SOF() {
  
}

static void usb_int_stall() {
  
}

static void usb_int_error() {
  
}

static void usb_int_sleep() {
  
}

static void usb_ep0_in() {

}

static void usb_ep0_out() {

}

static void usb_ep0_setup() {

}

static void usb_int_token() {
  byte endpoint = STAT_ENDP;
  byte in = STAT_IN;

  switch (endpoint) {
    case 0:
      if(in == 1) {
        usb_ep0_in();
      } else if(USB_EP0_OUT.Info.Read.PID == 0xD) {
        usb_ep0_setup();
      } else {
        usb_ep0_out();
      }
      break;
  }  
}

void usb_loop() {
  // Check if first call since STOP3
  USBCTL0_USBRESMEN = 0;

  // Check INTSTAT_RESUMEF
  //Enable Sleep, clear Resume flag, disable resume interrupt
  if(INTSTAT_RESUMEF != 0) usb_int_resume();

  // Check INTSTAT_USBRSTF 
  //Reset USB, BD registers initialize USB module, set USB state to DEFAULT
  if(INTSTAT_USBRSTF != 0) usb_int_reset();

  // Check INTSTAT_SOFTOKF 
  // Clear SOF interrupt flag
  if(INTSTAT_SOFTOKF != 0) usb_int_SOF();

  // Check INTSTAT_STALLF 
  // Process the stall from different endpoint, clear stall flag
  if(INTSTAT_STALLF != 0) usb_int_stall();

  // Check INTSTAT_ERRORF 
  // Check error source and process, clear error flag
  if(INTSTAT_ERRORF != 0) usb_int_error();

  // Check INTSTAT_SLEEPF 
  // Enable resume (USBRESMEN or RESUME bit), clear sleep flag,
  //  enter suspend mode
  if(INTSTAT_SLEEPF != 0) usb_int_sleep();

  // Check INTSTAT_TOKDNEF 
  // Process USB transaction Clear TOKDNEF flag
  if(INTSTAT_TOKDNEF != 0) usb_int_token();
}