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

void init_system() {
  init_writeOnce();

  init_pta();
  init_ptb();
}