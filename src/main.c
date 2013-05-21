#include "main.h"

enum USB_STATES usb_state = POWERED;

void main() {
  init_system();
  init_mcb();
  init_usb();

  while(1==1) {
    switch (usb_state) {
      case BOOTLOADER:
        SIGNATURE = 0xC3;   // Trigger bootloader after reset.
        __asm__("BGND");    // BGND illegal opcode reset. BDCSC_ENBDM must be 0.
        break;
      case ATTACHED:
      case DEFAULT:
      case ADDR_PENDING:
      case ADDRESSED:
      case CONFIGURED:
      case WAIT_SUSPEND:
      case SUSPEND:
        usb_loop();
        break;
      default:
        break;
    }
  }
}