#include "main.h"

enum USB_STATES usb_state = POWERED;

void main() {
  if(usb_state != DEFAULT) {
    PTAD = (byte) (PTAD_PTAD2_MASK | PTAD_PTAD3_MASK);
  }
}