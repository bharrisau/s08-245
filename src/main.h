#include "../include/mc9s08js16l.h"

/*
4  PTB0 Device Suspend
5  PTB1 Device Ready
7  PTB3 Device Delay Init
8  PTA0 Device Reset
9  PAT1 TCK
10 PTA2 TDI (device->s08)
11 PTA3 TMS
12 PTA4 TDO (s08->device)
18 PTA5 Fet
19 PTA6 Rx (device->s08)
20 PTA7 Tx (s08->device)
*/

void init_system(void);