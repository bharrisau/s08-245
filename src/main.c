#include "../include/mc9s08js16l.h"

void main() {
  PTAD = (byte) (PTAD_PTAD2_MASK | PTAD_PTAD3_MASK);
}