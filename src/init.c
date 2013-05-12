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
  while((MCGSC & mask) != value);
}


static void init_fbe() {
  init_wait_MCGSC(0x00, 0x01);
}

static void init_pbe() {

}

static void init_pee() {

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