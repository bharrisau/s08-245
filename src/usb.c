#include "main.h"
//Write the code that polls the status and reacts accordingly.

static byte usb_wake_loop() {
  byte delay_count;

  __asm__("STOP");    // Drop into STOP3

  delay_count = 50;   // Need to wait 2.5us for RESUME to be asserted
  do {
    delay_count--;
  } while (delay_count > 0);
  return INTSTAT_RESUMEF;
}

static void usb_suspend() {
  byte wakeup;

  USBCTL0_USBRESMEN = 1;
  usb_state = SUSPEND;

  //Disable other interupts (RTC)

  do {
    wakeup = usb_wake_loop();
  } while(wakeup == 0);

  usb_state = CONFIGURED;
  USBCTL0_USBRESMEN = 0;

  //Enable interrupts
}

static void usb_int_resume() {
  //Enable Sleep, clear Resume flag, disable resume interrupt
  INTSTAT = INTSTAT_RESUMEF_MASK;
}

static void usb_int_reset() {
  //Reset USB, BD registers initialize USB module, set USB state to DEFAULT
  ADDR = 0;
  usb_ep0_prep_setup();
  usb_state = DEFAULT;

  INTSTAT = INTSTAT_USBRSTF_MASK;
}

static void usb_int_SOF() {
  // Clear SOF interrupt flag
  INTSTAT = INTSTAT_SOFTOKF_MASK;
}

static void usb_int_stall() {
  // Process the stall from different endpoint, clear stall flag  
  INTSTAT = INTSTAT_STALLF_MASK;
}

static void usb_int_error() {
  // Still TODO
  // Check error source and process, clear error flag
  INTSTAT = INTSTAT_ERRORF_MASK;
}

static void usb_int_sleep() {
  INTSTAT = INTSTAT_SLEEPF_MASK;
  // Enable resume (USBRESMEN or RESUME bit), clear sleep flag,
  //  enter suspend mode

  //TODO Disable power
  usb_state = WAIT_SUSPEND;
}

static void usb_int_token() {
  // Process USB transaction Clear TOKDNEF flag
  byte endpoint = STAT_ENDP;

  switch (endpoint) {
    case 0:
      usb_ep0_token();
      break;
    //default:
      //STALL or something?
  }  
  INTSTAT = INTSTAT_TOKDNEF_MASK;
}

void usb_loop() {
  if (usb_state == WAIT_SUSPEND) {
    usb_suspend();
  }

  // Check INTSTAT_RESUMEF
  //if(INTSTAT_RESUMEF != 0) usb_int_resume();

  // Check INTSTAT_USBRSTF 
  if(INTSTAT_USBRSTF != 0) usb_int_reset();

  // Check INTSTAT_SOFTOKF 
  //if(INTSTAT_SOFTOKF != 0) usb_int_SOF();

  // Check INTSTAT_STALLF 
  //if(INTSTAT_STALLF != 0) usb_int_stall();

  // Check INTSTAT_ERRORF 
  //if(INTSTAT_ERRORF != 0) usb_int_error();

  // Check INTSTAT_SLEEPF 
  //if(INTSTAT_SLEEPF != 0) usb_int_sleep();

  // Check INTSTAT_TOKDNEF 
  if(INTSTAT_TOKDNEF != 0) usb_int_token();
}