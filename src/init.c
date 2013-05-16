#include "main.h"

static void init_writeOnce() {
  SOPT1 = 0x10;
  SOPT2 = 0x0;
  SPMSC1 = 0x14;
  SPMSC2 = 0x0;
}

static void init_pta() {
  PTAD = 0x20;
  PTADD = 0xBB;
  PTAPE = 0x44;
  PTASE = 0xBB;
  PTADS = 0x00;
}

static void init_ptb() {
  PTBD = 0x00;
  PTBDD = 0x09;
  PTBPE = 0x06;
  PTBSE = 0x09;
  PTBDS = 0x00;
}

static void init_wait_MCGSC(byte mask, byte value) {
  /*@i@*/ while((MCGSC & mask) != value);
}

static void init_wait_USBCTL0(byte mask, byte value) {
  /*@i@*/ while((USBCTL0 & mask) != value);
}


static void init_fbe() {
  MCGC2 = 0x36;
  init_wait_MCGSC(0x2, 0x2);

  MCGC1 = 0xB8;
  init_wait_MCGSC(0x1C, 0x8);
}

static void init_pbe() {
  MCGC2 = 0x3E;
  MCGC1 = 0x98;
  MCGC3 = 0x46;
  init_wait_MCGSC(0x20, 0x20);

  MCGC2 = 0x36;
  init_wait_MCGSC(0x40, 0x40);
}

static void init_pee() {
  MCGC1 = 0x18;
  init_wait_MCGSC(0xC, 0xC);
}

static void init_reset_usb() {
  USBCTL0_USBRESET = 1;
  init_wait_USBCTL0(0x80, 0);
}

static void init_ep0() {
  USB_EP0_IN.Address = USB_EP0_IN_BUFF>>2;
  USB_EP0_IN.Length = 0;
  USB_EP0_IN.Info.Byte = 0;

  USB_EP0_OUT.Address = USB_EP0_OUT_BUFF>>2;
  // USB_EP0_OUT.Length = USB_EP0_LENGTH;
  // USB_EP0_OUT.Info.Byte = 0x88;
  usb_ep0_prep_setup();

  EPCTL0 = 0x0D;
}

static void init_usbctl0() {
  USBCTL0_USBPU = 1;
  USBCTL0_USBPHYEN = 1;
}

static void init_enable_usb() {
  CTL_USBEN = 1;

  usb_state = ATTACHED;
}

void init_system() {
  init_writeOnce();

  init_pta();
  init_ptb();
}

void init_mcb() {
  init_fbe();
  init_pbe();
  init_pee();
}

void init_usb() {
  init_reset_usb();

  init_ep0();

  init_usbctl0();

  init_enable_usb();
}