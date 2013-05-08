/* Based on CPU DB MC9S08JS16_24, version 3.00.019 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s08js16l.h
**     Processor : MC9S08JS16LCFK
**     FileFormat: V2.32
**     DataSheet : MC9S08JS16RM Rev. 4 4/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 13:52
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**
**     Redistribution and use in source and binary forms, with or without
** 	   modification, are permitted provided that the following conditions
**     are met:
**     - Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     - Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     - Neither the name of Freescale Semiconductor, Inc. nor the names of
**       its contributors may be used to endorse or promote products derived
**       from this software without specific prior written permission.
**
**    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
**    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
**    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
**    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
**    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
**    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
**    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
**    OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
**    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
**    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
**    WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
**    POSSIBILITY OF SUCH DAMAGE.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 22.08.2008, V3.00.0:
**              - Removed register SOPT3. Added Checksum Bypass at 0xFFBA.
**              -   REASON: Changes in Reference Manual(from Rev. 0 Draft D 12/2007 to Rev. 0 Draft F 4/2008).
**      - 13.11.2008, V3.00.1:
**              - Removed vectors VReserved30(0xFFC2),VReserved31(0xFFC0).
**              -   REASON: Changes in Reference Manual (#6793 in Issue Manager).
**      - 16.04.2009, V3.00.2:
**              - Address of NVFTRIM, NVMCGTRM changed to 0xFFAE,0xFFAF
**              -   REASON: Changes in Reference Manual (from Rev 1, 8/2008 to Rev 3, 3/2009).
**      - 6.08.2009, V3.00.3:
**              - Bits SIGNATURE0-SIGNATURE7 merged to SIGNATURE[0:7] group.
**              -   REASON: Access to individual bits is useless (#7539 in Issue Manager).
**
**     File-Format-Revisions:
**      - 02.01.2008, V2.21 :
**               - Changes have not affected this file (because they are related to another family)
**      - 13.02.2008, V2.22 :
**               - Changes have not affected this file (because they are related to another family)
**      - 20.02.2008, V2.23 :
**               - Changes have not affected this file (because they are related to another family)
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user�s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08JS16L_H
#define _MC9S08JS16L_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55U, SRS = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vrtc               29U
#define VectorNumber_VReserved28        28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_Vmtim              26U
#define VectorNumber_Vkeyboard          25U
#define VectorNumber_VReserved24        24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_VReserved22        22U
#define VectorNumber_Vscitx             21U
#define VectorNumber_Vscirx             20U
#define VectorNumber_Vscierr            19U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved17        17U
#define VectorNumber_VReserved16        16U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved14        14U
#define VectorNumber_VReserved13        13U
#define VectorNumber_VReserved12        12U
#define VectorNumber_Vtpmovf            11U
#define VectorNumber_Vtpmch1            10U
#define VectorNumber_Vtpmch0            9U
#define VectorNumber_VReserved8         8U
#define VectorNumber_Vusb               7U
#define VectorNumber_VReserved6         6U
#define VectorNumber_Vspi               5U
#define VectorNumber_Vlol               4U
#define VectorNumber_Vlvd               3U
#define VectorNumber_Virq               2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vrtc                            0xFFC4U
#define VReserved28                     0xFFC6U
#define VReserved27                     0xFFC8U
#define Vmtim                           0xFFCAU
#define Vkeyboard                       0xFFCCU
#define VReserved24                     0xFFCEU
#define VReserved23                     0xFFD0U
#define VReserved22                     0xFFD2U
#define Vscitx                          0xFFD4U
#define Vscirx                          0xFFD6U
#define Vscierr                         0xFFD8U
#define VReserved18                     0xFFDAU
#define VReserved17                     0xFFDCU
#define VReserved16                     0xFFDEU
#define VReserved15                     0xFFE0U
#define VReserved14                     0xFFE2U
#define VReserved13                     0xFFE4U
#define VReserved12                     0xFFE6U
#define Vtpmovf                         0xFFE8U
#define Vtpmch1                         0xFFEAU
#define Vtpmch0                         0xFFECU
#define VReserved8                      0xFFEEU
#define Vusb                            0xFFF0U
#define VReserved6                      0xFFF2U
#define Vspi                            0xFFF4U
#define Vlol                            0xFFF6U
#define Vlvd                            0xFFF8U
#define Virq                            0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD                       _PTBD.MergedBits.grpPTBD

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD_MASK                  63U
#define PTBD_PTBD_BITNUM                0U


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte             :1; 
    byte             :1; 
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBDD :2;
    byte         :1;
    byte         :1;
    byte grpPTBDD_4 :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD                     _PTBDD.MergedBits.grpPTBDD
#define PTBDD_PTBDD_4                   _PTBDD.MergedBits.grpPTBDD_4

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD_MASK                3U
#define PTBDD_PTBDD_BITNUM              0U
#define PTBDD_PTBDD_4_MASK              48U
#define PTBDD_PTBDD_4_BITNUM            4U


/*** MTIMSC - MTIM Clock Configuration Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIMSCSTR;
extern volatile MTIMSCSTR _MTIMSC;
#define MTIMSC                          _MTIMSC.Byte
#define MTIMSC_TSTP                     _MTIMSC.Bits.TSTP
#define MTIMSC_TRST                     _MTIMSC.Bits.TRST
#define MTIMSC_TOIE                     _MTIMSC.Bits.TOIE
#define MTIMSC_TOF                      _MTIMSC.Bits.TOF

#define MTIMSC_TSTP_MASK                16U
#define MTIMSC_TRST_MASK                32U
#define MTIMSC_TOIE_MASK                64U
#define MTIMSC_TOF_MASK                 128U


/*** MTIMCLK - MTIM Clock Configuration Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock source Prescaler Bit 0 */
    byte PS1         :1;                                       /* Clock source Prescaler Bit 1 */
    byte PS2         :1;                                       /* Clock source Prescaler Bit 2 */
    byte PS3         :1;                                       /* Clock source Prescaler Bit 3 */
    byte CLKS0       :1;                                       /* Clock source Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock source Select Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIMCLKSTR;
extern volatile MTIMCLKSTR _MTIMCLK;
#define MTIMCLK                         _MTIMCLK.Byte
#define MTIMCLK_PS0                     _MTIMCLK.Bits.PS0
#define MTIMCLK_PS1                     _MTIMCLK.Bits.PS1
#define MTIMCLK_PS2                     _MTIMCLK.Bits.PS2
#define MTIMCLK_PS3                     _MTIMCLK.Bits.PS3
#define MTIMCLK_CLKS0                   _MTIMCLK.Bits.CLKS0
#define MTIMCLK_CLKS1                   _MTIMCLK.Bits.CLKS1
#define MTIMCLK_PS                      _MTIMCLK.MergedBits.grpPS
#define MTIMCLK_CLKS                    _MTIMCLK.MergedBits.grpCLKS

#define MTIMCLK_PS0_MASK                1U
#define MTIMCLK_PS1_MASK                2U
#define MTIMCLK_PS2_MASK                4U
#define MTIMCLK_PS3_MASK                8U
#define MTIMCLK_CLKS0_MASK              16U
#define MTIMCLK_CLKS1_MASK              32U
#define MTIMCLK_PS_MASK                 15U
#define MTIMCLK_PS_BITNUM               0U
#define MTIMCLK_CLKS_MASK               48U
#define MTIMCLK_CLKS_BITNUM             4U


/*** MTIMCNT - MTIM Counter Register; 0x0000000A ***/
typedef union {
  byte Byte;
} MTIMCNTSTR;
extern volatile MTIMCNTSTR _MTIMCNT;
#define MTIMCNT                         _MTIMCNT.Byte


/*** MTIMMOD - MTIM Modulo Register; 0x0000000B ***/
typedef union {
  byte Byte;
} MTIMMODSTR;
extern volatile MTIMMODSTR _MTIMMOD;
#define MTIMMOD                         _MTIMMOD.Byte


/*** CRCH - CRC High Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* High byte of CRC register ,bit 8 */
    byte BIT9        :1;                                       /* High byte of CRC register ,bit 9 */
    byte BIT10       :1;                                       /* High byte of CRC register ,bit 10 */
    byte BIT11       :1;                                       /* High byte of CRC register ,bit 11 */
    byte BIT12       :1;                                       /* High byte of CRC register ,bit 12 */
    byte BIT13       :1;                                       /* High byte of CRC register ,bit 13 */
    byte BIT14       :1;                                       /* High byte of CRC register ,bit 14 */
    byte BIT15       :1;                                       /* High byte of CRC register ,bit 15 */
  } Bits;
} CRCHSTR;
extern volatile CRCHSTR _CRCH;
#define CRCH                            _CRCH.Byte
#define CRCH_BIT8                       _CRCH.Bits.BIT8
#define CRCH_BIT9                       _CRCH.Bits.BIT9
#define CRCH_BIT10                      _CRCH.Bits.BIT10
#define CRCH_BIT11                      _CRCH.Bits.BIT11
#define CRCH_BIT12                      _CRCH.Bits.BIT12
#define CRCH_BIT13                      _CRCH.Bits.BIT13
#define CRCH_BIT14                      _CRCH.Bits.BIT14
#define CRCH_BIT15                      _CRCH.Bits.BIT15

#define CRCH_BIT8_MASK                  1U
#define CRCH_BIT9_MASK                  2U
#define CRCH_BIT10_MASK                 4U
#define CRCH_BIT11_MASK                 8U
#define CRCH_BIT12_MASK                 16U
#define CRCH_BIT13_MASK                 32U
#define CRCH_BIT14_MASK                 64U
#define CRCH_BIT15_MASK                 128U


/*** CRCL - CRC Low Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCLSTR;
extern volatile CRCLSTR _CRCL;
#define CRCL                            _CRCL.Byte
#define CRCL_BIT0                       _CRCL.Bits.BIT0
#define CRCL_BIT1                       _CRCL.Bits.BIT1
#define CRCL_BIT2                       _CRCL.Bits.BIT2
#define CRCL_BIT3                       _CRCL.Bits.BIT3
#define CRCL_BIT4                       _CRCL.Bits.BIT4
#define CRCL_BIT5                       _CRCL.Bits.BIT5
#define CRCL_BIT6                       _CRCL.Bits.BIT6
#define CRCL_BIT7                       _CRCL.Bits.BIT7

#define CRCL_BIT0_MASK                  1U
#define CRCL_BIT1_MASK                  2U
#define CRCL_BIT2_MASK                  4U
#define CRCL_BIT3_MASK                  8U
#define CRCL_BIT4_MASK                  16U
#define CRCL_BIT5_MASK                  32U
#define CRCL_BIT6_MASK                  64U
#define CRCL_BIT7_MASK                  128U


/*** TPMSC - TPM Status and Control Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPMSCSTR;
extern volatile TPMSCSTR _TPMSC;
#define TPMSC                           _TPMSC.Byte
#define TPMSC_PS0                       _TPMSC.Bits.PS0
#define TPMSC_PS1                       _TPMSC.Bits.PS1
#define TPMSC_PS2                       _TPMSC.Bits.PS2
#define TPMSC_CLKSA                     _TPMSC.Bits.CLKSA
#define TPMSC_CLKSB                     _TPMSC.Bits.CLKSB
#define TPMSC_CPWMS                     _TPMSC.Bits.CPWMS
#define TPMSC_TOIE                      _TPMSC.Bits.TOIE
#define TPMSC_TOF                       _TPMSC.Bits.TOF
#define TPMSC_PS                        _TPMSC.MergedBits.grpPS
#define TPMSC_CLKSx                     _TPMSC.MergedBits.grpCLKSx

#define TPMSC_PS0_MASK                  1U
#define TPMSC_PS1_MASK                  2U
#define TPMSC_PS2_MASK                  4U
#define TPMSC_CLKSA_MASK                8U
#define TPMSC_CLKSB_MASK                16U
#define TPMSC_CPWMS_MASK                32U
#define TPMSC_TOIE_MASK                 64U
#define TPMSC_TOF_MASK                  128U
#define TPMSC_PS_MASK                   7U
#define TPMSC_PS_BITNUM                 0U
#define TPMSC_CLKSx_MASK                24U
#define TPMSC_CLKSx_BITNUM              3U


/*** TPMCNT - TPM Timer Counter Register; 0x00000011 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPMCNTH - TPM Timer Counter Register High; 0x00000011 ***/
    union {
      byte Byte;
    } TPMCNTHSTR;
    #define TPMCNTH                     _TPMCNT.Overlap_STR.TPMCNTHSTR.Byte
    

    /*** TPMCNTL - TPM Timer Counter Register Low; 0x00000012 ***/
    union {
      byte Byte;
    } TPMCNTLSTR;
    #define TPMCNTL                     _TPMCNT.Overlap_STR.TPMCNTLSTR.Byte
    
  } Overlap_STR;

} TPMCNTSTR;
extern volatile TPMCNTSTR _TPMCNT;
#define TPMCNT                          _TPMCNT.Word


/*** TPMMOD - TPM Timer Counter Modulo Register; 0x00000013 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPMMODH - TPM Timer Counter Modulo Register High; 0x00000013 ***/
    union {
      byte Byte;
    } TPMMODHSTR;
    #define TPMMODH                     _TPMMOD.Overlap_STR.TPMMODHSTR.Byte
    

    /*** TPMMODL - TPM Timer Counter Modulo Register Low; 0x00000014 ***/
    union {
      byte Byte;
    } TPMMODLSTR;
    #define TPMMODL                     _TPMMOD.Overlap_STR.TPMMODLSTR.Byte
    
  } Overlap_STR;

} TPMMODSTR;
extern volatile TPMMODSTR _TPMMOD;
#define TPMMOD                          _TPMMOD.Word


/*** TPMC0SC - TPM Timer Channel 0 Status and Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPMC0SCSTR;
extern volatile TPMC0SCSTR _TPMC0SC;
#define TPMC0SC                         _TPMC0SC.Byte
#define TPMC0SC_ELS0A                   _TPMC0SC.Bits.ELS0A
#define TPMC0SC_ELS0B                   _TPMC0SC.Bits.ELS0B
#define TPMC0SC_MS0A                    _TPMC0SC.Bits.MS0A
#define TPMC0SC_MS0B                    _TPMC0SC.Bits.MS0B
#define TPMC0SC_CH0IE                   _TPMC0SC.Bits.CH0IE
#define TPMC0SC_CH0F                    _TPMC0SC.Bits.CH0F
#define TPMC0SC_ELS0x                   _TPMC0SC.MergedBits.grpELS0x
#define TPMC0SC_MS0x                    _TPMC0SC.MergedBits.grpMS0x

#define TPMC0SC_ELS0A_MASK              4U
#define TPMC0SC_ELS0B_MASK              8U
#define TPMC0SC_MS0A_MASK               16U
#define TPMC0SC_MS0B_MASK               32U
#define TPMC0SC_CH0IE_MASK              64U
#define TPMC0SC_CH0F_MASK               128U
#define TPMC0SC_ELS0x_MASK              12U
#define TPMC0SC_ELS0x_BITNUM            2U
#define TPMC0SC_MS0x_MASK               48U
#define TPMC0SC_MS0x_BITNUM             4U


/*** TPMC0V - TPM Timer Channel 0 Value Register; 0x00000016 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPMC0VH - TPM Timer Channel 0 Value Register High; 0x00000016 ***/
    union {
      byte Byte;
    } TPMC0VHSTR;
    #define TPMC0VH                     _TPMC0V.Overlap_STR.TPMC0VHSTR.Byte
    

    /*** TPMC0VL - TPM Timer Channel 0 Value Register Low; 0x00000017 ***/
    union {
      byte Byte;
    } TPMC0VLSTR;
    #define TPMC0VL                     _TPMC0V.Overlap_STR.TPMC0VLSTR.Byte
    
  } Overlap_STR;

} TPMC0VSTR;
extern volatile TPMC0VSTR _TPMC0V;
#define TPMC0V                          _TPMC0V.Word


/*** TPMC1SC - TPM Timer Channel 1 Status and Control Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPMC1SCSTR;
extern volatile TPMC1SCSTR _TPMC1SC;
#define TPMC1SC                         _TPMC1SC.Byte
#define TPMC1SC_ELS1A                   _TPMC1SC.Bits.ELS1A
#define TPMC1SC_ELS1B                   _TPMC1SC.Bits.ELS1B
#define TPMC1SC_MS1A                    _TPMC1SC.Bits.MS1A
#define TPMC1SC_MS1B                    _TPMC1SC.Bits.MS1B
#define TPMC1SC_CH1IE                   _TPMC1SC.Bits.CH1IE
#define TPMC1SC_CH1F                    _TPMC1SC.Bits.CH1F
#define TPMC1SC_ELS1x                   _TPMC1SC.MergedBits.grpELS1x
#define TPMC1SC_MS1x                    _TPMC1SC.MergedBits.grpMS1x

#define TPMC1SC_ELS1A_MASK              4U
#define TPMC1SC_ELS1B_MASK              8U
#define TPMC1SC_MS1A_MASK               16U
#define TPMC1SC_MS1B_MASK               32U
#define TPMC1SC_CH1IE_MASK              64U
#define TPMC1SC_CH1F_MASK               128U
#define TPMC1SC_ELS1x_MASK              12U
#define TPMC1SC_ELS1x_BITNUM            2U
#define TPMC1SC_MS1x_MASK               48U
#define TPMC1SC_MS1x_BITNUM             4U


/*** TPMC1V - TPM Timer Channel 1 Value Register; 0x00000019 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPMC1VH - TPM Timer Channel 1 Value Register High; 0x00000019 ***/
    union {
      byte Byte;
    } TPMC1VHSTR;
    #define TPMC1VH                     _TPMC1V.Overlap_STR.TPMC1VHSTR.Byte
    

    /*** TPMC1VL - TPM Timer Channel 1 Value Register Low; 0x0000001A ***/
    union {
      byte Byte;
    } TPMC1VLSTR;
    #define TPMC1VL                     _TPMC1V.Overlap_STR.TPMC1VLSTR.Byte
    
  } Overlap_STR;

} TPMC1VSTR;
extern volatile TPMC1VSTR _TPMC1V;
#define TPMC1V                          _TPMC1V.Word


/*** IRQSC - Interrupt request status and control register; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1U
#define IRQSC_IRQIE_MASK                2U
#define IRQSC_IRQACK_MASK               4U
#define IRQSC_IRQF_MASK                 8U
#define IRQSC_IRQPE_MASK                16U
#define IRQSC_IRQEDG_MASK               32U
#define IRQSC_IRQPDD_MASK               64U


/*** KBISC - KBI Status and Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte KBMOD       :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBISCSTR;
extern volatile KBISCSTR _KBISC;
#define KBISC                           _KBISC.Byte
#define KBISC_KBMOD                     _KBISC.Bits.KBMOD
#define KBISC_KBIE                      _KBISC.Bits.KBIE
#define KBISC_KBACK                     _KBISC.Bits.KBACK
#define KBISC_KBF                       _KBISC.Bits.KBF

#define KBISC_KBMOD_MASK                1U
#define KBISC_KBIE_MASK                 2U
#define KBISC_KBACK_MASK                4U
#define KBISC_KBF_MASK                  8U


/*** KBIPE - KBI Pin Enable Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBIPESTR;
extern volatile KBIPESTR _KBIPE;
#define KBIPE                           _KBIPE.Byte
#define KBIPE_KBIPE0                    _KBIPE.Bits.KBIPE0
#define KBIPE_KBIPE1                    _KBIPE.Bits.KBIPE1
#define KBIPE_KBIPE2                    _KBIPE.Bits.KBIPE2
#define KBIPE_KBIPE3                    _KBIPE.Bits.KBIPE3
#define KBIPE_KBIPE4                    _KBIPE.Bits.KBIPE4
#define KBIPE_KBIPE5                    _KBIPE.Bits.KBIPE5
#define KBIPE_KBIPE6                    _KBIPE.Bits.KBIPE6
#define KBIPE_KBIPE7                    _KBIPE.Bits.KBIPE7

#define KBIPE_KBIPE0_MASK               1U
#define KBIPE_KBIPE1_MASK               2U
#define KBIPE_KBIPE2_MASK               4U
#define KBIPE_KBIPE3_MASK               8U
#define KBIPE_KBIPE4_MASK               16U
#define KBIPE_KBIPE5_MASK               32U
#define KBIPE_KBIPE6_MASK               64U
#define KBIPE_KBIPE7_MASK               128U


/*** KBIES - KBI Edge Select Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBIESSTR;
extern volatile KBIESSTR _KBIES;
#define KBIES                           _KBIES.Byte
#define KBIES_KBEDG0                    _KBIES.Bits.KBEDG0
#define KBIES_KBEDG1                    _KBIES.Bits.KBEDG1
#define KBIES_KBEDG2                    _KBIES.Bits.KBEDG2
#define KBIES_KBEDG3                    _KBIES.Bits.KBEDG3
#define KBIES_KBEDG4                    _KBIES.Bits.KBEDG4
#define KBIES_KBEDG5                    _KBIES.Bits.KBEDG5
#define KBIES_KBEDG6                    _KBIES.Bits.KBEDG6
#define KBIES_KBEDG7                    _KBIES.Bits.KBEDG7

#define KBIES_KBEDG0_MASK               1U
#define KBIES_KBEDG1_MASK               2U
#define KBIES_KBEDG2_MASK               4U
#define KBIES_KBEDG3_MASK               8U
#define KBIES_KBEDG4_MASK               16U
#define KBIES_KBEDG5_MASK               32U
#define KBIES_KBEDG6_MASK               64U
#define KBIES_KBEDG7_MASK               128U


/*** SCIBD - SCI Baud Rate Register; 0x00000020 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x00000020 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    #define SCIBDH_RXEDGIE              _SCIBD.Overlap_STR.SCIBDHSTR.Bits.RXEDGIE
    #define SCIBDH_LBKDIE               _SCIBD.Overlap_STR.SCIBDHSTR.Bits.LBKDIE
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1U
    #define SCIBDH_SBR9_MASK            2U
    #define SCIBDH_SBR10_MASK           4U
    #define SCIBDH_SBR11_MASK           8U
    #define SCIBDH_SBR12_MASK           16U
    #define SCIBDH_RXEDGIE_MASK         64U
    #define SCIBDH_LBKDIE_MASK          128U
    #define SCIBDH_SBR_8_MASK           31U
    #define SCIBDH_SBR_8_BITNUM         0U
    

    /*** SCIBDL - SCI Baud Rate Register Low; 0x00000021 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    #define SCIBDL_SBR0_MASK            1U
    #define SCIBDL_SBR1_MASK            2U
    #define SCIBDL_SBR2_MASK            4U
    #define SCIBDL_SBR3_MASK            8U
    #define SCIBDL_SBR4_MASK            16U
    #define SCIBDL_SBR5_MASK            32U
    #define SCIBDL_SBR6_MASK            64U
    #define SCIBDL_SBR7_MASK            128U
    
  } Overlap_STR;

} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD;
#define SCIBD                           _SCIBD.Word


/*** SCIC1 - SCI Control Register 1; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1;
#define SCIC1                           _SCIC1.Byte
#define SCIC1_PT                        _SCIC1.Bits.PT
#define SCIC1_PE                        _SCIC1.Bits.PE
#define SCIC1_ILT                       _SCIC1.Bits.ILT
#define SCIC1_WAKE                      _SCIC1.Bits.WAKE
#define SCIC1_M                         _SCIC1.Bits.M
#define SCIC1_RSRC                      _SCIC1.Bits.RSRC
#define SCIC1_SCISWAI                   _SCIC1.Bits.SCISWAI
#define SCIC1_LOOPS                     _SCIC1.Bits.LOOPS

#define SCIC1_PT_MASK                   1U
#define SCIC1_PE_MASK                   2U
#define SCIC1_ILT_MASK                  4U
#define SCIC1_WAKE_MASK                 8U
#define SCIC1_M_MASK                    16U
#define SCIC1_RSRC_MASK                 32U
#define SCIC1_SCISWAI_MASK              64U
#define SCIC1_LOOPS_MASK                128U


/*** SCIC2 - SCI Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2;
#define SCIC2                           _SCIC2.Byte
#define SCIC2_SBK                       _SCIC2.Bits.SBK
#define SCIC2_RWU                       _SCIC2.Bits.RWU
#define SCIC2_RE                        _SCIC2.Bits.RE
#define SCIC2_TE                        _SCIC2.Bits.TE
#define SCIC2_ILIE                      _SCIC2.Bits.ILIE
#define SCIC2_RIE                       _SCIC2.Bits.RIE
#define SCIC2_TCIE                      _SCIC2.Bits.TCIE
#define SCIC2_TIE                       _SCIC2.Bits.TIE

#define SCIC2_SBK_MASK                  1U
#define SCIC2_RWU_MASK                  2U
#define SCIC2_RE_MASK                   4U
#define SCIC2_TE_MASK                   8U
#define SCIC2_ILIE_MASK                 16U
#define SCIC2_RIE_MASK                  32U
#define SCIC2_TCIE_MASK                 64U
#define SCIC2_TIE_MASK                  128U


/*** SCIS1 - SCI Status Register 1; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1;
#define SCIS1                           _SCIS1.Byte
#define SCIS1_PF                        _SCIS1.Bits.PF
#define SCIS1_FE                        _SCIS1.Bits.FE
#define SCIS1_NF                        _SCIS1.Bits.NF
#define SCIS1_OR                        _SCIS1.Bits.OR
#define SCIS1_IDLE                      _SCIS1.Bits.IDLE
#define SCIS1_RDRF                      _SCIS1.Bits.RDRF
#define SCIS1_TC                        _SCIS1.Bits.TC
#define SCIS1_TDRE                      _SCIS1.Bits.TDRE

#define SCIS1_PF_MASK                   1U
#define SCIS1_FE_MASK                   2U
#define SCIS1_NF_MASK                   4U
#define SCIS1_OR_MASK                   8U
#define SCIS1_IDLE_MASK                 16U
#define SCIS1_RDRF_MASK                 32U
#define SCIS1_TC_MASK                   64U
#define SCIS1_TDRE_MASK                 128U


/*** SCIS2 - SCI Status Register 2; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2;
#define SCIS2                           _SCIS2.Byte
#define SCIS2_RAF                       _SCIS2.Bits.RAF
#define SCIS2_LBKDE                     _SCIS2.Bits.LBKDE
#define SCIS2_BRK13                     _SCIS2.Bits.BRK13
#define SCIS2_RWUID                     _SCIS2.Bits.RWUID
#define SCIS2_RXINV                     _SCIS2.Bits.RXINV
#define SCIS2_RXEDGIF                   _SCIS2.Bits.RXEDGIF
#define SCIS2_LBKDIF                    _SCIS2.Bits.LBKDIF

#define SCIS2_RAF_MASK                  1U
#define SCIS2_LBKDE_MASK                2U
#define SCIS2_BRK13_MASK                4U
#define SCIS2_RWUID_MASK                8U
#define SCIS2_RXINV_MASK                16U
#define SCIS2_RXEDGIF_MASK              64U
#define SCIS2_LBKDIF_MASK               128U


/*** SCIC3 - SCI Control Register 3; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCIC3STR;
extern volatile SCIC3STR _SCIC3;
#define SCIC3                           _SCIC3.Byte
#define SCIC3_PEIE                      _SCIC3.Bits.PEIE
#define SCIC3_FEIE                      _SCIC3.Bits.FEIE
#define SCIC3_NEIE                      _SCIC3.Bits.NEIE
#define SCIC3_ORIE                      _SCIC3.Bits.ORIE
#define SCIC3_TXINV                     _SCIC3.Bits.TXINV
#define SCIC3_TXDIR                     _SCIC3.Bits.TXDIR
#define SCIC3_T8                        _SCIC3.Bits.T8
#define SCIC3_R8                        _SCIC3.Bits.R8

#define SCIC3_PEIE_MASK                 1U
#define SCIC3_FEIE_MASK                 2U
#define SCIC3_NEIE_MASK                 4U
#define SCIC3_ORIE_MASK                 8U
#define SCIC3_TXINV_MASK                16U
#define SCIC3_TXDIR_MASK                32U
#define SCIC3_T8_MASK                   64U
#define SCIC3_R8_MASK                   128U


/*** SCID - SCI Data Register; 0x00000027 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID;
#define SCID                            _SCID.Byte
#define SCID_R0_T0                      _SCID.Bits.R0_T0
#define SCID_R1_T1                      _SCID.Bits.R1_T1
#define SCID_R2_T2                      _SCID.Bits.R2_T2
#define SCID_R3_T3                      _SCID.Bits.R3_T3
#define SCID_R4_T4                      _SCID.Bits.R4_T4
#define SCID_R5_T5                      _SCID.Bits.R5_T5
#define SCID_R6_T6                      _SCID.Bits.R6_T6
#define SCID_R7_T7                      _SCID.Bits.R7_T7

#define SCID_R0_T0_MASK                 1U
#define SCID_R1_T1_MASK                 2U
#define SCID_R2_T2_MASK                 4U
#define SCID_R3_T3_MASK                 8U
#define SCID_R4_T4_MASK                 16U
#define SCID_R5_T5_MASK                 32U
#define SCID_R6_T6_MASK                 64U
#define SCID_R7_T7_MASK                 128U


/*** SPIC1 - SPI Control Register 1; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPIC1STR;
extern volatile SPIC1STR _SPIC1;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1U
#define SPIC1_SSOE_MASK                 2U
#define SPIC1_CPHA_MASK                 4U
#define SPIC1_CPOL_MASK                 8U
#define SPIC1_MSTR_MASK                 16U
#define SPIC1_SPTIE_MASK                32U
#define SPIC1_SPE_MASK                  64U
#define SPIC1_SPIE_MASK                 128U


/*** SPIC2 - SPI Control Register 2; 0x00000031 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8- or 16-bit Mode Select */
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPIC2STR;
extern volatile SPIC2STR _SPIC2;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN
#define SPIC2_SPIMODE                   _SPIC2.Bits.SPIMODE
#define SPIC2_SPMIE                     _SPIC2.Bits.SPMIE

#define SPIC2_SPC0_MASK                 1U
#define SPIC2_SPISWAI_MASK              2U
#define SPIC2_BIDIROE_MASK              8U
#define SPIC2_MODFEN_MASK               16U
#define SPIC2_SPIMODE_MASK              64U
#define SPIC2_SPMIE_MASK                128U


/*** SPIBR - SPI Baud Rate Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPIS - SPI Status Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPISSTR;
extern volatile SPISSTR _SPIS;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPMF                       _SPIS.Bits.SPMF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16U
#define SPIS_SPTEF_MASK                 32U
#define SPIS_SPMF_MASK                  64U
#define SPIS_SPRF_MASK                  128U


/*** SPID16 - SPI Data Register; 0x00000034 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPIDH - SPI Data Register High; 0x00000034 ***/
    union {
      byte Byte;
    } SPIDHSTR;
    #define SPIDH                       _SPID16.Overlap_STR.SPIDHSTR.Byte
    

    /*** SPIDL - SPI Data Register Low; 0x00000035 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SPIDL - SPI Data Register Low; Several registers at the same address ***/
        #define SPIDL                   _SPID16.Overlap_STR.SPIDLSTR.Byte
        
        /*** SPID - SPI Data Register Low; Several registers at the same address ***/
        union {
          struct {
            byte Bit0        :1;                                       /* SPI Data Bit 0 */
            byte Bit1        :1;                                       /* SPI Data Bit 1 */
            byte Bit2        :1;                                       /* SPI Data Bit 2 */
            byte Bit3        :1;                                       /* SPI Data Bit 3 */
            byte Bit4        :1;                                       /* SPI Data Bit 4 */
            byte Bit5        :1;                                       /* SPI Data Bit 5 */
            byte Bit6        :1;                                       /* SPI Data Bit 6 */
            byte Bit7        :1;                                       /* SPI Data Bit 7 */
          } Bits;
        } SPIDSTR;
        #define SPID                    _SPID16.Overlap_STR.SPIDLSTR.Byte
        #define SPID_Bit0               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit0
        #define SPID_Bit1               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit1
        #define SPID_Bit2               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit2
        #define SPID_Bit3               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit3
        #define SPID_Bit4               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit4
        #define SPID_Bit5               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit5
        #define SPID_Bit6               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit6
        #define SPID_Bit7               _SPID16.Overlap_STR.SPIDLSTR.SameAddr_STR.SPIDSTR.Bits.Bit7
        
        #define SPID_Bit0_MASK          1U
        #define SPID_Bit1_MASK          2U
        #define SPID_Bit2_MASK          4U
        #define SPID_Bit3_MASK          8U
        #define SPID_Bit4_MASK          16U
        #define SPID_Bit5_MASK          32U
        #define SPID_Bit6_MASK          64U
        #define SPID_Bit7_MASK          128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SPIDLSTR;
    
  } Overlap_STR;

} SPID16STR;
extern volatile SPID16STR _SPID16;
#define SPID16                          _SPID16.Word


/*** SPIM - SPI Match Register; 0x00000036 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPIMH - SPI Match Register High; 0x00000036 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* SPI Match Value Bit 8 */
        byte Bit9        :1;                                       /* SPI Match Value Bit 9 */
        byte Bit10       :1;                                       /* SPI Match Value Bit 10 */
        byte Bit11       :1;                                       /* SPI Match Value Bit 11 */
        byte Bit12       :1;                                       /* SPI Match Value Bit 12 */
        byte Bit13       :1;                                       /* SPI Match Value Bit 13 */
        byte Bit14       :1;                                       /* SPI Match Value Bit 14 */
        byte Bit15       :1;                                       /* SPI Match Value Bit 15 */
      } Bits;
    } SPIMHSTR;
    #define SPIMH                       _SPIM.Overlap_STR.SPIMHSTR.Byte
    #define SPIMH_Bit8                  _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit8
    #define SPIMH_Bit9                  _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit9
    #define SPIMH_Bit10                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit10
    #define SPIMH_Bit11                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit11
    #define SPIMH_Bit12                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit12
    #define SPIMH_Bit13                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit13
    #define SPIMH_Bit14                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit14
    #define SPIMH_Bit15                 _SPIM.Overlap_STR.SPIMHSTR.Bits.Bit15
    
    #define SPIMH_Bit8_MASK             1U
    #define SPIMH_Bit9_MASK             2U
    #define SPIMH_Bit10_MASK            4U
    #define SPIMH_Bit11_MASK            8U
    #define SPIMH_Bit12_MASK            16U
    #define SPIMH_Bit13_MASK            32U
    #define SPIMH_Bit14_MASK            64U
    #define SPIMH_Bit15_MASK            128U
    

    /*** SPIML - SPI Match Register Low; 0x00000037 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
        byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
        byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
        byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
        byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
        byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
        byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
        byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
      } Bits;
    } SPIMLSTR;
    #define SPIML                       _SPIM.Overlap_STR.SPIMLSTR.Byte
    #define SPIML_Bit0                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit0
    #define SPIML_Bit1                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit1
    #define SPIML_Bit2                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit2
    #define SPIML_Bit3                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit3
    #define SPIML_Bit4                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit4
    #define SPIML_Bit5                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit5
    #define SPIML_Bit6                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit6
    #define SPIML_Bit7                  _SPIM.Overlap_STR.SPIMLSTR.Bits.Bit7
    
    #define SPIML_Bit0_MASK             1U
    #define SPIML_Bit1_MASK             2U
    #define SPIML_Bit2_MASK             4U
    #define SPIML_Bit3_MASK             8U
    #define SPIML_Bit4_MASK             16U
    #define SPIML_Bit5_MASK             32U
    #define SPIML_Bit6_MASK             64U
    #define SPIML_Bit7_MASK             128U
    
  } Overlap_STR;

} SPIMSTR;
extern volatile SPIMSTR _SPIM;
#define SPIM                            _SPIM.Word


/*** MCGC1 - MCG Control Register 1; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} MCGC1STR;
extern volatile MCGC1STR _MCGC1;
#define MCGC1                           _MCGC1.Byte
#define MCGC1_IREFSTEN                  _MCGC1.Bits.IREFSTEN
#define MCGC1_IRCLKEN                   _MCGC1.Bits.IRCLKEN
#define MCGC1_IREFS                     _MCGC1.Bits.IREFS
#define MCGC1_RDIV0                     _MCGC1.Bits.RDIV0
#define MCGC1_RDIV1                     _MCGC1.Bits.RDIV1
#define MCGC1_RDIV2                     _MCGC1.Bits.RDIV2
#define MCGC1_CLKS0                     _MCGC1.Bits.CLKS0
#define MCGC1_CLKS1                     _MCGC1.Bits.CLKS1
#define MCGC1_RDIV                      _MCGC1.MergedBits.grpRDIV
#define MCGC1_CLKS                      _MCGC1.MergedBits.grpCLKS

#define MCGC1_IREFSTEN_MASK             1U
#define MCGC1_IRCLKEN_MASK              2U
#define MCGC1_IREFS_MASK                4U
#define MCGC1_RDIV0_MASK                8U
#define MCGC1_RDIV1_MASK                16U
#define MCGC1_RDIV2_MASK                32U
#define MCGC1_CLKS0_MASK                64U
#define MCGC1_CLKS1_MASK                128U
#define MCGC1_RDIV_MASK                 56U
#define MCGC1_RDIV_BITNUM               3U
#define MCGC1_CLKS_MASK                 192U
#define MCGC1_CLKS_BITNUM               6U


/*** MCGC2 - MCG Control Register 2; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} MCGC2STR;
extern volatile MCGC2STR _MCGC2;
#define MCGC2                           _MCGC2.Byte
#define MCGC2_EREFSTEN                  _MCGC2.Bits.EREFSTEN
#define MCGC2_ERCLKEN                   _MCGC2.Bits.ERCLKEN
#define MCGC2_EREFS                     _MCGC2.Bits.EREFS
#define MCGC2_LP                        _MCGC2.Bits.LP
#define MCGC2_HGO                       _MCGC2.Bits.HGO
#define MCGC2_RANGE                     _MCGC2.Bits.RANGE
#define MCGC2_BDIV0                     _MCGC2.Bits.BDIV0
#define MCGC2_BDIV1                     _MCGC2.Bits.BDIV1
#define MCGC2_BDIV                      _MCGC2.MergedBits.grpBDIV

#define MCGC2_EREFSTEN_MASK             1U
#define MCGC2_ERCLKEN_MASK              2U
#define MCGC2_EREFS_MASK                4U
#define MCGC2_LP_MASK                   8U
#define MCGC2_HGO_MASK                  16U
#define MCGC2_RANGE_MASK                32U
#define MCGC2_BDIV0_MASK                64U
#define MCGC2_BDIV1_MASK                128U
#define MCGC2_BDIV_MASK                 192U
#define MCGC2_BDIV_BITNUM               6U


/*** MCGTRM - MCG Trim Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} MCGTRMSTR;
extern volatile MCGTRMSTR _MCGTRM;
#define MCGTRM                          _MCGTRM.Byte
#define MCGTRM_TRIM0                    _MCGTRM.Bits.TRIM0
#define MCGTRM_TRIM1                    _MCGTRM.Bits.TRIM1
#define MCGTRM_TRIM2                    _MCGTRM.Bits.TRIM2
#define MCGTRM_TRIM3                    _MCGTRM.Bits.TRIM3
#define MCGTRM_TRIM4                    _MCGTRM.Bits.TRIM4
#define MCGTRM_TRIM5                    _MCGTRM.Bits.TRIM5
#define MCGTRM_TRIM6                    _MCGTRM.Bits.TRIM6
#define MCGTRM_TRIM7                    _MCGTRM.Bits.TRIM7

#define MCGTRM_TRIM0_MASK               1U
#define MCGTRM_TRIM1_MASK               2U
#define MCGTRM_TRIM2_MASK               4U
#define MCGTRM_TRIM3_MASK               8U
#define MCGTRM_TRIM4_MASK               16U
#define MCGTRM_TRIM5_MASK               32U
#define MCGTRM_TRIM6_MASK               64U
#define MCGTRM_TRIM7_MASK               128U


/*** MCGSC - MCG Status and Control Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM_bit   :1;                                       /* MCG Fine Trim */ /*Warning: bit name is duplicated with register name*/
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte PLLST       :1;                                       /* PLL Select Status */
    byte LOCK        :1;                                       /* Lock Status */
    byte LOLS        :1;                                       /* Loss of Lock Status */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGSCSTR;
extern volatile MCGSCSTR _MCGSC;
#define MCGSC                           _MCGSC.Byte
#define MCGSC_FTRIM                     _MCGSC.Bits.FTRIM_bit
#define MCGSC_OSCINIT                   _MCGSC.Bits.OSCINIT
#define MCGSC_CLKST0                    _MCGSC.Bits.CLKST0
#define MCGSC_CLKST1                    _MCGSC.Bits.CLKST1
#define MCGSC_IREFST                    _MCGSC.Bits.IREFST
#define MCGSC_PLLST                     _MCGSC.Bits.PLLST
#define MCGSC_LOCK                      _MCGSC.Bits.LOCK
#define MCGSC_LOLS                      _MCGSC.Bits.LOLS
#define MCGSC_CLKST                     _MCGSC.MergedBits.grpCLKST

#define MCGSC_FTRIM_MASK                1U
#define MCGSC_OSCINIT_MASK              2U
#define MCGSC_CLKST0_MASK               4U
#define MCGSC_CLKST1_MASK               8U
#define MCGSC_IREFST_MASK               16U
#define MCGSC_PLLST_MASK                32U
#define MCGSC_LOCK_MASK                 64U
#define MCGSC_LOLS_MASK                 128U
#define MCGSC_CLKST_MASK                12U
#define MCGSC_CLKST_BITNUM              2U


/*** MCGC3 - MCG Control Register 3; 0x00000044 ***/
typedef union {
  byte Byte;
  struct {
    byte VDIV0       :1;                                       /* VCO Divider, bit 0 */
    byte VDIV1       :1;                                       /* VCO Divider, bit 1 */
    byte VDIV2       :1;                                       /* VCO Divider, bit 2 */
    byte VDIV3       :1;                                       /* VCO Divider, bit 3 */
    byte             :1; 
    byte CME         :1;                                       /* Clock Monitor Enable */
    byte PLLS        :1;                                       /* PLL Select */
    byte LOLIE       :1;                                       /* Loss of Lock Interrupt Enable */
  } Bits;
  struct {
    byte grpVDIV :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC3STR;
extern volatile MCGC3STR _MCGC3;
#define MCGC3                           _MCGC3.Byte
#define MCGC3_VDIV0                     _MCGC3.Bits.VDIV0
#define MCGC3_VDIV1                     _MCGC3.Bits.VDIV1
#define MCGC3_VDIV2                     _MCGC3.Bits.VDIV2
#define MCGC3_VDIV3                     _MCGC3.Bits.VDIV3
#define MCGC3_CME                       _MCGC3.Bits.CME
#define MCGC3_PLLS                      _MCGC3.Bits.PLLS
#define MCGC3_LOLIE                     _MCGC3.Bits.LOLIE
#define MCGC3_VDIV                      _MCGC3.MergedBits.grpVDIV

#define MCGC3_VDIV0_MASK                1U
#define MCGC3_VDIV1_MASK                2U
#define MCGC3_VDIV2_MASK                4U
#define MCGC3_VDIV3_MASK                8U
#define MCGC3_CME_MASK                  32U
#define MCGC3_PLLS_MASK                 64U
#define MCGC3_LOLIE_MASK                128U
#define MCGC3_VDIV_MASK                 15U
#define MCGC3_VDIV_BITNUM               0U


/*** RTCSC - RTC Status and Control Register; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte RTCPS3      :1;                                       /* Real-Time Clock Prescaler Select, bit 3 */
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
extern volatile RTCSCSTR _RTCSC;
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1U
#define RTCSC_RTCPS1_MASK               2U
#define RTCSC_RTCPS2_MASK               4U
#define RTCSC_RTCPS3_MASK               8U
#define RTCSC_RTIE_MASK                 16U
#define RTCSC_RTCLKS0_MASK              32U
#define RTCSC_RTCLKS1_MASK              64U
#define RTCSC_RTIF_MASK                 128U
#define RTCSC_RTCPS_MASK                15U
#define RTCSC_RTCPS_BITNUM              0U
#define RTCSC_RTCLKS_MASK               96U
#define RTCSC_RTCLKS_BITNUM             5U


/*** RTCCNT - RTC Counter Register; 0x00000049 ***/
typedef union {
  byte Byte;
} RTCCNTSTR;
extern volatile RTCCNTSTR _RTCCNT;
#define RTCCNT                          _RTCCNT.Byte


/*** RTCMOD - RTC Modulo Register; 0x0000004A ***/
typedef union {
  byte Byte;
} RTCMODSTR;
extern volatile RTCMODSTR _RTCMOD;
#define RTCMOD                          _RTCMOD.Byte


/*** USBCTL0 - USB Control Register 0; 0x00000050 ***/
typedef union {
  byte Byte;
  struct {
    byte USBPHYEN    :1;                                       /* USB PHY Tranceiver Enable */
    byte             :1; 
    byte USBVREN     :1;                                       /* USB Voltage Regulator Enable */
    byte             :1; 
    byte LPRESF      :1;                                       /* Low-Power Resume Flag */
    byte USBRESMEN   :1;                                       /* USB Low-Power Resume Event Enable */
    byte USBPU       :1;                                       /* Pull Up Source */
    byte USBRESET    :1;                                       /* USB Reset */
  } Bits;
} USBCTL0STR;
extern volatile USBCTL0STR _USBCTL0;
#define USBCTL0                         _USBCTL0.Byte
#define USBCTL0_USBPHYEN                _USBCTL0.Bits.USBPHYEN
#define USBCTL0_USBVREN                 _USBCTL0.Bits.USBVREN
#define USBCTL0_LPRESF                  _USBCTL0.Bits.LPRESF
#define USBCTL0_USBRESMEN               _USBCTL0.Bits.USBRESMEN
#define USBCTL0_USBPU                   _USBCTL0.Bits.USBPU
#define USBCTL0_USBRESET                _USBCTL0.Bits.USBRESET

#define USBCTL0_USBPHYEN_MASK           1U
#define USBCTL0_USBVREN_MASK            4U
#define USBCTL0_LPRESF_MASK             16U
#define USBCTL0_USBRESMEN_MASK          32U
#define USBCTL0_USBPU_MASK              64U
#define USBCTL0_USBRESET_MASK           128U


/*** PERID - Peripheral ID Register; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Peripheral Configuration Number Bit 0 */
    byte ID1         :1;                                       /* Peripheral Configuration Number Bit 1 */
    byte ID2         :1;                                       /* Peripheral Configuration Number Bit 2 */
    byte ID3         :1;                                       /* Peripheral Configuration Number Bit 3 */
    byte ID4         :1;                                       /* Peripheral Configuration Number Bit 4 */
    byte ID5         :1;                                       /* Peripheral Configuration Number Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpID   :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERIDSTR;
extern volatile PERIDSTR _PERID;
#define PERID                           _PERID.Byte
#define PERID_ID0                       _PERID.Bits.ID0
#define PERID_ID1                       _PERID.Bits.ID1
#define PERID_ID2                       _PERID.Bits.ID2
#define PERID_ID3                       _PERID.Bits.ID3
#define PERID_ID4                       _PERID.Bits.ID4
#define PERID_ID5                       _PERID.Bits.ID5
#define PERID_ID                        _PERID.MergedBits.grpID

#define PERID_ID0_MASK                  1U
#define PERID_ID1_MASK                  2U
#define PERID_ID2_MASK                  4U
#define PERID_ID3_MASK                  8U
#define PERID_ID4_MASK                  16U
#define PERID_ID5_MASK                  32U
#define PERID_ID_MASK                   63U
#define PERID_ID_BITNUM                 0U


/*** IDCOMP - Peripheral ID Complement Register; 0x00000059 ***/
typedef union {
  byte Byte;
  struct {
    byte NID0        :1;                                       /* Complement ID Number Bit 0 */
    byte NID1        :1;                                       /* Complement ID Number Bit 1 */
    byte NID2        :1;                                       /* Complement ID Number Bit 2 */
    byte NID3        :1;                                       /* Complement ID Number Bit 3 */
    byte NID4        :1;                                       /* Complement ID Number Bit 4 */
    byte NID5        :1;                                       /* Complement ID Number Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpNID  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} IDCOMPSTR;
extern volatile IDCOMPSTR _IDCOMP;
#define IDCOMP                          _IDCOMP.Byte
#define IDCOMP_NID0                     _IDCOMP.Bits.NID0
#define IDCOMP_NID1                     _IDCOMP.Bits.NID1
#define IDCOMP_NID2                     _IDCOMP.Bits.NID2
#define IDCOMP_NID3                     _IDCOMP.Bits.NID3
#define IDCOMP_NID4                     _IDCOMP.Bits.NID4
#define IDCOMP_NID5                     _IDCOMP.Bits.NID5
#define IDCOMP_NID                      _IDCOMP.MergedBits.grpNID

#define IDCOMP_NID0_MASK                1U
#define IDCOMP_NID1_MASK                2U
#define IDCOMP_NID2_MASK                4U
#define IDCOMP_NID3_MASK                8U
#define IDCOMP_NID4_MASK                16U
#define IDCOMP_NID5_MASK                32U
#define IDCOMP_NID_MASK                 63U
#define IDCOMP_NID_BITNUM               0U


/*** REV - Peripheral Revision Register; 0x0000005A ***/
typedef union {
  byte Byte;
  struct {
    byte REV0        :1;                                       /* Revision Bit 0 */
    byte REV1        :1;                                       /* Revision Bit 1 */
    byte REV2        :1;                                       /* Revision Bit 2 */
    byte REV3        :1;                                       /* Revision Bit 3 */
    byte REV4        :1;                                       /* Revision Bit 4 */
    byte REV5        :1;                                       /* Revision Bit 5 */
    byte REV6        :1;                                       /* Revision Bit 6 */
    byte REV7        :1;                                       /* Revision Bit 7 */
  } Bits;
} REVSTR;
extern volatile REVSTR _REV;
#define REV                             _REV.Byte
#define REV_REV0                        _REV.Bits.REV0
#define REV_REV1                        _REV.Bits.REV1
#define REV_REV2                        _REV.Bits.REV2
#define REV_REV3                        _REV.Bits.REV3
#define REV_REV4                        _REV.Bits.REV4
#define REV_REV5                        _REV.Bits.REV5
#define REV_REV6                        _REV.Bits.REV6
#define REV_REV7                        _REV.Bits.REV7

#define REV_REV0_MASK                   1U
#define REV_REV1_MASK                   2U
#define REV_REV2_MASK                   4U
#define REV_REV3_MASK                   8U
#define REV_REV4_MASK                   16U
#define REV_REV5_MASK                   32U
#define REV_REV6_MASK                   64U
#define REV_REV7_MASK                   128U


/*** INTSTAT - Interrupt Status Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte USBRSTF     :1;                                       /* USB Reset Flag */
    byte ERRORF      :1;                                       /* Error Flag */
    byte SOFTOKF     :1;                                       /* SOF Token Flag */
    byte TOKDNEF     :1;                                       /* Token Complete Flag */
    byte SLEEPF      :1;                                       /* Sleep Flag */
    byte RESUMEF     :1;                                       /* Resume Flag */
    byte             :1; 
    byte STALLF      :1;                                       /* Stall Flag */
  } Bits;
} INTSTATSTR;
extern volatile INTSTATSTR _INTSTAT;
#define INTSTAT                         _INTSTAT.Byte
#define INTSTAT_USBRSTF                 _INTSTAT.Bits.USBRSTF
#define INTSTAT_ERRORF                  _INTSTAT.Bits.ERRORF
#define INTSTAT_SOFTOKF                 _INTSTAT.Bits.SOFTOKF
#define INTSTAT_TOKDNEF                 _INTSTAT.Bits.TOKDNEF
#define INTSTAT_SLEEPF                  _INTSTAT.Bits.SLEEPF
#define INTSTAT_RESUMEF                 _INTSTAT.Bits.RESUMEF
#define INTSTAT_STALLF                  _INTSTAT.Bits.STALLF

#define INTSTAT_USBRSTF_MASK            1U
#define INTSTAT_ERRORF_MASK             2U
#define INTSTAT_SOFTOKF_MASK            4U
#define INTSTAT_TOKDNEF_MASK            8U
#define INTSTAT_SLEEPF_MASK             16U
#define INTSTAT_RESUMEF_MASK            32U
#define INTSTAT_STALLF_MASK             128U


/*** INTENB - Interrupt Enable Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte USBRST      :1;                                       /* USBRST Interrupt Enable */
    byte ERROR       :1;                                       /* ERROR Interrupt Enable */
    byte SOFTOK      :1;                                       /* SOFTOK Interrupt Enable */
    byte TOKDNE      :1;                                       /* TOKDNE Interrupt Enable */
    byte SLEEP       :1;                                       /* SLEEP Interrupt Enable */
    byte RESUME      :1;                                       /* RESUME Interrupt Enable */
    byte             :1; 
    byte STALL       :1;                                       /* STALL Interrupt Enable */
  } Bits;
} INTENBSTR;
extern volatile INTENBSTR _INTENB;
#define INTENB                          _INTENB.Byte
#define INTENB_USBRST                   _INTENB.Bits.USBRST
#define INTENB_ERROR                    _INTENB.Bits.ERROR
#define INTENB_SOFTOK                   _INTENB.Bits.SOFTOK
#define INTENB_TOKDNE                   _INTENB.Bits.TOKDNE
#define INTENB_SLEEP                    _INTENB.Bits.SLEEP
#define INTENB_RESUME                   _INTENB.Bits.RESUME
#define INTENB_STALL                    _INTENB.Bits.STALL

#define INTENB_USBRST_MASK              1U
#define INTENB_ERROR_MASK               2U
#define INTENB_SOFTOK_MASK              4U
#define INTENB_TOKDNE_MASK              8U
#define INTENB_SLEEP_MASK               16U
#define INTENB_RESUME_MASK              32U
#define INTENB_STALL_MASK               128U


/*** ERRSTAT - Error Interrupt Status Register; 0x00000062 ***/
typedef union {
  byte Byte;
  struct {
    byte PIDERRF     :1;                                       /* PID Error Flag */
    byte CRC5F       :1;                                       /* CRC5 Error Flag */
    byte CRC16F      :1;                                       /* CRC16 Error Flag */
    byte DFN8F       :1;                                       /* Data Field Error Flag */
    byte BTOERRF     :1;                                       /* Bus Turnaround Error Timeout Flag */
    byte BUFERRF     :1;                                       /* Buffer Error Flag */
    byte             :1; 
    byte BTSERRF     :1;                                       /* Bit Stuff Error Flag */
  } Bits;
} ERRSTATSTR;
extern volatile ERRSTATSTR _ERRSTAT;
#define ERRSTAT                         _ERRSTAT.Byte
#define ERRSTAT_PIDERRF                 _ERRSTAT.Bits.PIDERRF
#define ERRSTAT_CRC5F                   _ERRSTAT.Bits.CRC5F
#define ERRSTAT_CRC16F                  _ERRSTAT.Bits.CRC16F
#define ERRSTAT_DFN8F                   _ERRSTAT.Bits.DFN8F
#define ERRSTAT_BTOERRF                 _ERRSTAT.Bits.BTOERRF
#define ERRSTAT_BUFERRF                 _ERRSTAT.Bits.BUFERRF
#define ERRSTAT_BTSERRF                 _ERRSTAT.Bits.BTSERRF

#define ERRSTAT_PIDERRF_MASK            1U
#define ERRSTAT_CRC5F_MASK              2U
#define ERRSTAT_CRC16F_MASK             4U
#define ERRSTAT_DFN8F_MASK              8U
#define ERRSTAT_BTOERRF_MASK            16U
#define ERRSTAT_BUFERRF_MASK            32U
#define ERRSTAT_BTSERRF_MASK            128U


/*** ERRENB - Error Interrupt Enable Register; 0x00000063 ***/
typedef union {
  byte Byte;
  struct {
    byte PIDERR      :1;                                       /* PIDERR Interrupt Enable */
    byte CRC5        :1;                                       /* CRC5 Interrupt Enable */
    byte CRC16       :1;                                       /* CRC16 Interrupt Enable */
    byte DFN8        :1;                                       /* DFN8 Interrupt Enable */
    byte BTOERR      :1;                                       /* BTOERR Interrupt Enable */
    byte BUFERR      :1;                                       /* BUFERR Interrupt Enable */
    byte             :1; 
    byte BTSERR      :1;                                       /* BTSERR Interrupt Enable */
  } Bits;
} ERRENBSTR;
extern volatile ERRENBSTR _ERRENB;
#define ERRENB                          _ERRENB.Byte
#define ERRENB_PIDERR                   _ERRENB.Bits.PIDERR
#define ERRENB_CRC5                     _ERRENB.Bits.CRC5
#define ERRENB_CRC16                    _ERRENB.Bits.CRC16
#define ERRENB_DFN8                     _ERRENB.Bits.DFN8
#define ERRENB_BTOERR                   _ERRENB.Bits.BTOERR
#define ERRENB_BUFERR                   _ERRENB.Bits.BUFERR
#define ERRENB_BTSERR                   _ERRENB.Bits.BTSERR

#define ERRENB_PIDERR_MASK              1U
#define ERRENB_CRC5_MASK                2U
#define ERRENB_CRC16_MASK               4U
#define ERRENB_DFN8_MASK                8U
#define ERRENB_BTOERR_MASK              16U
#define ERRENB_BUFERR_MASK              32U
#define ERRENB_BTSERR_MASK              128U


/*** STAT - Status Register; 0x00000064 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ODD         :1;                                       /* Odd/Even Transaction */
    byte IN          :1;                                       /* In/Out Transaction */
    byte ENDP0       :1;                                       /* Endpoint Number Bit 0 */
    byte ENDP1       :1;                                       /* Endpoint Number Bit 1 */
    byte ENDP2       :1;                                       /* Endpoint Number Bit 2 */
    byte ENDP3       :1;                                       /* Endpoint Number Bit 3 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpENDP :4;
  } MergedBits;
} STATSTR;
extern volatile STATSTR _STAT;
#define STAT                            _STAT.Byte
#define STAT_ODD                        _STAT.Bits.ODD
#define STAT_IN                         _STAT.Bits.IN
#define STAT_ENDP0                      _STAT.Bits.ENDP0
#define STAT_ENDP1                      _STAT.Bits.ENDP1
#define STAT_ENDP2                      _STAT.Bits.ENDP2
#define STAT_ENDP3                      _STAT.Bits.ENDP3
#define STAT_ENDP                       _STAT.MergedBits.grpENDP

#define STAT_ODD_MASK                   4U
#define STAT_IN_MASK                    8U
#define STAT_ENDP0_MASK                 16U
#define STAT_ENDP1_MASK                 32U
#define STAT_ENDP2_MASK                 64U
#define STAT_ENDP3_MASK                 128U
#define STAT_ENDP_MASK                  240U
#define STAT_ENDP_BITNUM                4U


/*** CTL - Control Register; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte USBEN       :1;                                       /* USB Enable */
    byte ODDRST      :1;                                       /* Odd Reset */
    byte CRESUME     :1;                                       /* Resume Signaling */
    byte             :1; 
    byte             :1; 
    byte TSUSPEND    :1;                                       /* Transaction Suspend */
    byte             :1; 
    byte             :1; 
  } Bits;
} CTLSTR;
extern volatile CTLSTR _CTL;
#define CTL                             _CTL.Byte
#define CTL_USBEN                       _CTL.Bits.USBEN
#define CTL_ODDRST                      _CTL.Bits.ODDRST
#define CTL_CRESUME                     _CTL.Bits.CRESUME
#define CTL_TSUSPEND                    _CTL.Bits.TSUSPEND

#define CTL_USBEN_MASK                  1U
#define CTL_ODDRST_MASK                 2U
#define CTL_CRESUME_MASK                4U
#define CTL_TSUSPEND_MASK               32U


/*** ADDR - Address Register; 0x00000066 ***/
typedef union {
  byte Byte;
  struct {
    byte ADDR0       :1;                                       /* USB Address Bit 0 */
    byte ADDR1       :1;                                       /* USB Address Bit 1 */
    byte ADDR2       :1;                                       /* USB Address Bit 2 */
    byte ADDR3       :1;                                       /* USB Address Bit 3 */
    byte ADDR4       :1;                                       /* USB Address Bit 4 */
    byte ADDR5       :1;                                       /* USB Address Bit 5 */
    byte ADDR6       :1;                                       /* USB Address Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpADDR :7;
    byte         :1;
  } MergedBits;
} ADDRSTR;
extern volatile ADDRSTR _ADDR;
#define ADDR                            _ADDR.Byte
#define ADDR_ADDR0                      _ADDR.Bits.ADDR0
#define ADDR_ADDR1                      _ADDR.Bits.ADDR1
#define ADDR_ADDR2                      _ADDR.Bits.ADDR2
#define ADDR_ADDR3                      _ADDR.Bits.ADDR3
#define ADDR_ADDR4                      _ADDR.Bits.ADDR4
#define ADDR_ADDR5                      _ADDR.Bits.ADDR5
#define ADDR_ADDR6                      _ADDR.Bits.ADDR6
#define ADDR_ADDR                       _ADDR.MergedBits.grpADDR

#define ADDR_ADDR0_MASK                 1U
#define ADDR_ADDR1_MASK                 2U
#define ADDR_ADDR2_MASK                 4U
#define ADDR_ADDR3_MASK                 8U
#define ADDR_ADDR4_MASK                 16U
#define ADDR_ADDR5_MASK                 32U
#define ADDR_ADDR6_MASK                 64U
#define ADDR_ADDR_MASK                  127U
#define ADDR_ADDR_BITNUM                0U


/*** FRMNUML - Frame Number Register Low; 0x00000067 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM0        :1;                                       /* Frame Number Bit 0 */
    byte FRM1        :1;                                       /* Frame Number Bit 1 */
    byte FRM2        :1;                                       /* Frame Number Bit 2 */
    byte FRM3        :1;                                       /* Frame Number Bit 3 */
    byte FRM4        :1;                                       /* Frame Number Bit 4 */
    byte FRM5        :1;                                       /* Frame Number Bit 5 */
    byte FRM6        :1;                                       /* Frame Number Bit 6 */
    byte FRM7        :1;                                       /* Frame Number Bit 7 */
  } Bits;
} FRMNUMLSTR;
extern volatile FRMNUMLSTR _FRMNUML;
#define FRMNUML                         _FRMNUML.Byte
#define FRMNUML_FRM0                    _FRMNUML.Bits.FRM0
#define FRMNUML_FRM1                    _FRMNUML.Bits.FRM1
#define FRMNUML_FRM2                    _FRMNUML.Bits.FRM2
#define FRMNUML_FRM3                    _FRMNUML.Bits.FRM3
#define FRMNUML_FRM4                    _FRMNUML.Bits.FRM4
#define FRMNUML_FRM5                    _FRMNUML.Bits.FRM5
#define FRMNUML_FRM6                    _FRMNUML.Bits.FRM6
#define FRMNUML_FRM7                    _FRMNUML.Bits.FRM7

#define FRMNUML_FRM0_MASK               1U
#define FRMNUML_FRM1_MASK               2U
#define FRMNUML_FRM2_MASK               4U
#define FRMNUML_FRM3_MASK               8U
#define FRMNUML_FRM4_MASK               16U
#define FRMNUML_FRM5_MASK               32U
#define FRMNUML_FRM6_MASK               64U
#define FRMNUML_FRM7_MASK               128U


/*** FRMNUMH - Frame Number Register High; 0x00000068 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM8        :1;                                       /* Frame Number Bit 8 */
    byte FRM9        :1;                                       /* Frame Number Bit 9 */
    byte FRM10       :1;                                       /* Frame Number Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFRM_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FRMNUMHSTR;
extern volatile FRMNUMHSTR _FRMNUMH;
#define FRMNUMH                         _FRMNUMH.Byte
#define FRMNUMH_FRM8                    _FRMNUMH.Bits.FRM8
#define FRMNUMH_FRM9                    _FRMNUMH.Bits.FRM9
#define FRMNUMH_FRM10                   _FRMNUMH.Bits.FRM10
#define FRMNUMH_FRM_8                   _FRMNUMH.MergedBits.grpFRM_8
#define FRMNUMH_FRM                     FRMNUMH_FRM_8

#define FRMNUMH_FRM8_MASK               1U
#define FRMNUMH_FRM9_MASK               2U
#define FRMNUMH_FRM10_MASK              4U
#define FRMNUMH_FRM_8_MASK              7U
#define FRMNUMH_FRM_8_BITNUM            0U


/*** EPCTL0 - Endpoint Control Register 0; 0x0000006D ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL0STR;
extern volatile EPCTL0STR _EPCTL0;
#define EPCTL0                          _EPCTL0.Byte
#define EPCTL0_EPHSHK                   _EPCTL0.Bits.EPHSHK
#define EPCTL0_EPSTALL                  _EPCTL0.Bits.EPSTALL
#define EPCTL0_EPTXEN                   _EPCTL0.Bits.EPTXEN
#define EPCTL0_EPRXEN                   _EPCTL0.Bits.EPRXEN
#define EPCTL0_EPCTLDIS                 _EPCTL0.Bits.EPCTLDIS
/* EPCTL_ARR: Access 7 EPCTLx registers in an array */
#define EPCTL_ARR                       ((volatile byte * __far) &EPCTL0)

#define EPCTL0_EPHSHK_MASK              1U
#define EPCTL0_EPSTALL_MASK             2U
#define EPCTL0_EPTXEN_MASK              4U
#define EPCTL0_EPRXEN_MASK              8U
#define EPCTL0_EPCTLDIS_MASK            16U


/*** EPCTL1 - Endpoint Control Register 1; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL1STR;
extern volatile EPCTL1STR _EPCTL1;
#define EPCTL1                          _EPCTL1.Byte
#define EPCTL1_EPHSHK                   _EPCTL1.Bits.EPHSHK
#define EPCTL1_EPSTALL                  _EPCTL1.Bits.EPSTALL
#define EPCTL1_EPTXEN                   _EPCTL1.Bits.EPTXEN
#define EPCTL1_EPRXEN                   _EPCTL1.Bits.EPRXEN
#define EPCTL1_EPCTLDIS                 _EPCTL1.Bits.EPCTLDIS

#define EPCTL1_EPHSHK_MASK              1U
#define EPCTL1_EPSTALL_MASK             2U
#define EPCTL1_EPTXEN_MASK              4U
#define EPCTL1_EPRXEN_MASK              8U
#define EPCTL1_EPCTLDIS_MASK            16U


/*** EPCTL2 - Endpoint Control Register 2; 0x0000006F ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL2STR;
extern volatile EPCTL2STR _EPCTL2;
#define EPCTL2                          _EPCTL2.Byte
#define EPCTL2_EPHSHK                   _EPCTL2.Bits.EPHSHK
#define EPCTL2_EPSTALL                  _EPCTL2.Bits.EPSTALL
#define EPCTL2_EPTXEN                   _EPCTL2.Bits.EPTXEN
#define EPCTL2_EPRXEN                   _EPCTL2.Bits.EPRXEN
#define EPCTL2_EPCTLDIS                 _EPCTL2.Bits.EPCTLDIS

#define EPCTL2_EPHSHK_MASK              1U
#define EPCTL2_EPSTALL_MASK             2U
#define EPCTL2_EPTXEN_MASK              4U
#define EPCTL2_EPRXEN_MASK              8U
#define EPCTL2_EPCTLDIS_MASK            16U


/*** EPCTL3 - Endpoint Control Register 3; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL3STR;
extern volatile EPCTL3STR _EPCTL3;
#define EPCTL3                          _EPCTL3.Byte
#define EPCTL3_EPHSHK                   _EPCTL3.Bits.EPHSHK
#define EPCTL3_EPSTALL                  _EPCTL3.Bits.EPSTALL
#define EPCTL3_EPTXEN                   _EPCTL3.Bits.EPTXEN
#define EPCTL3_EPRXEN                   _EPCTL3.Bits.EPRXEN
#define EPCTL3_EPCTLDIS                 _EPCTL3.Bits.EPCTLDIS

#define EPCTL3_EPHSHK_MASK              1U
#define EPCTL3_EPSTALL_MASK             2U
#define EPCTL3_EPTXEN_MASK              4U
#define EPCTL3_EPRXEN_MASK              8U
#define EPCTL3_EPCTLDIS_MASK            16U


/*** EPCTL4 - Endpoint Control Register 4; 0x00000071 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL4STR;
extern volatile EPCTL4STR _EPCTL4;
#define EPCTL4                          _EPCTL4.Byte
#define EPCTL4_EPHSHK                   _EPCTL4.Bits.EPHSHK
#define EPCTL4_EPSTALL                  _EPCTL4.Bits.EPSTALL
#define EPCTL4_EPTXEN                   _EPCTL4.Bits.EPTXEN
#define EPCTL4_EPRXEN                   _EPCTL4.Bits.EPRXEN
#define EPCTL4_EPCTLDIS                 _EPCTL4.Bits.EPCTLDIS

#define EPCTL4_EPHSHK_MASK              1U
#define EPCTL4_EPSTALL_MASK             2U
#define EPCTL4_EPTXEN_MASK              4U
#define EPCTL4_EPRXEN_MASK              8U
#define EPCTL4_EPCTLDIS_MASK            16U


/*** EPCTL5 - Endpoint Control Register 5; 0x00000072 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL5STR;
extern volatile EPCTL5STR _EPCTL5;
#define EPCTL5                          _EPCTL5.Byte
#define EPCTL5_EPHSHK                   _EPCTL5.Bits.EPHSHK
#define EPCTL5_EPSTALL                  _EPCTL5.Bits.EPSTALL
#define EPCTL5_EPTXEN                   _EPCTL5.Bits.EPTXEN
#define EPCTL5_EPRXEN                   _EPCTL5.Bits.EPRXEN
#define EPCTL5_EPCTLDIS                 _EPCTL5.Bits.EPCTLDIS

#define EPCTL5_EPHSHK_MASK              1U
#define EPCTL5_EPSTALL_MASK             2U
#define EPCTL5_EPTXEN_MASK              4U
#define EPCTL5_EPRXEN_MASK              8U
#define EPCTL5_EPCTLDIS_MASK            16U


/*** EPCTL6 - Endpoint Control Register 6; 0x00000073 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHSHK      :1;                                       /* Endpoint Handshake */
    byte EPSTALL     :1;                                       /* Endpoint Stall */
    byte EPTXEN      :1;                                       /* Endpoint Tx Enable */
    byte EPRXEN      :1;                                       /* Endpoint Rx Enable */
    byte EPCTLDIS    :1;                                       /* Endpoint Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EPCTL6STR;
extern volatile EPCTL6STR _EPCTL6;
#define EPCTL6                          _EPCTL6.Byte
#define EPCTL6_EPHSHK                   _EPCTL6.Bits.EPHSHK
#define EPCTL6_EPSTALL                  _EPCTL6.Bits.EPSTALL
#define EPCTL6_EPTXEN                   _EPCTL6.Bits.EPTXEN
#define EPCTL6_EPRXEN                   _EPCTL6.Bits.EPRXEN
#define EPCTL6_EPCTLDIS                 _EPCTL6.Bits.EPCTLDIS

#define EPCTL6_EPHSHK_MASK              1U
#define EPCTL6_EPSTALL_MASK             2U
#define EPCTL6_EPTXEN_MASK              4U
#define EPCTL6_EPRXEN_MASK              8U
#define EPCTL6_EPCTLDIS_MASK            16U


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte LOC         :1;                                       /* Loss-of-Clock Reset */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_LOC                         _SRS.Bits.LOC
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_LOC_MASK                    4U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte RSTPE       :1;                                       /* RESET Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte BLMSS       :1;                                       /* BLMS Pin State */
    byte             :1; 
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_RSTPE                     _SOPT1.Bits.RSTPE
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_BLMSS                     _SOPT1.Bits.BLMSS
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_RSTPE_MASK                1U
#define SOPT1_BKGDPE_MASK               2U
#define SOPT1_BLMSS_MASK                4U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT0_MASK                64U
#define SOPT1_COPT1_MASK                128U
#define SOPT1_COPT_MASK                 192U
#define SOPT1_COPT_BITNUM               6U


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte SPIFE       :1;                                       /* SPI Ports Input Filter Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte COPW        :1;                                       /* COP Window */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_SPIFE                     _SOPT2.Bits.SPIFE
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_SPIFE_MASK                4U
#define SOPT2_COPW_MASK                 64U
#define SOPT2_COPCLKS_MASK              128U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID;
#define SDID                            _SDID.Word


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning status */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVWIE                    _SPMSC1.Bits.LVWIE
#define SPMSC1_LVWACK                   _SPMSC1.Bits.LVWACK
#define SPMSC1_LVWF                     _SPMSC1.Bits.LVWF

#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVWIE_MASK               32U
#define SPMSC1_LVWACK_MASK              64U
#define SPMSC1_LVWF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte             :1; 
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LVWV_MASK                16U
#define SPMSC2_LVDV_MASK                32U


/*** FTRIM - Reserved for storage of FTRIM; 0x0000180C ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM_bit   :1;                                       /* Factory FTRIM value */ /*Warning: bit name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTRIMSTR;
extern volatile FTRIMSTR _FTRIM;
#define FTRIM                           _FTRIM.Byte
#define FTRIM_FTRIM                     _FTRIM.Bits.FTRIM_bit

#define FTRIM_FTRIM_MASK                1U


/*** MCGTRIM - Reserved for storage of MCGTRIM; 0x0000180D ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* Factory trim value, bit 0 */
    byte TRIM1       :1;                                       /* Factory trim value, bit 1 */
    byte TRIM2       :1;                                       /* Factory trim value, bit 2 */
    byte TRIM3       :1;                                       /* Factory trim value, bit 3 */
    byte TRIM4       :1;                                       /* Factory trim value, bit 4 */
    byte TRIM5       :1;                                       /* Factory trim value, bit 5 */
    byte TRIM6       :1;                                       /* Factory trim value, bit 6 */
    byte TRIM7       :1;                                       /* Factory trim value, bit 7 */
  } Bits;
} MCGTRIMSTR;
extern volatile MCGTRIMSTR _MCGTRIM;
#define MCGTRIM                         _MCGTRIM.Byte
#define MCGTRIM_TRIM0                   _MCGTRIM.Bits.TRIM0
#define MCGTRIM_TRIM1                   _MCGTRIM.Bits.TRIM1
#define MCGTRIM_TRIM2                   _MCGTRIM.Bits.TRIM2
#define MCGTRIM_TRIM3                   _MCGTRIM.Bits.TRIM3
#define MCGTRIM_TRIM4                   _MCGTRIM.Bits.TRIM4
#define MCGTRIM_TRIM5                   _MCGTRIM.Bits.TRIM5
#define MCGTRIM_TRIM6                   _MCGTRIM.Bits.TRIM6
#define MCGTRIM_TRIM7                   _MCGTRIM.Bits.TRIM7

#define MCGTRIM_TRIM0_MASK              1U
#define MCGTRIM_TRIM1_MASK              2U
#define MCGTRIM_TRIM2_MASK              4U
#define MCGTRIM_TRIM3_MASK              8U
#define MCGTRIM_TRIM4_MASK              16U
#define MCGTRIM_TRIM5_MASK              32U
#define MCGTRIM_TRIM6_MASK              64U
#define MCGTRIM_TRIM7_MASK              128U


/*** FPROTD - Flash Protection Defeat Register; 0x0000180E ***/
typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       /* FPROT_FPDIS can be set to 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FPROTDSTR;
extern volatile FPROTDSTR _FPROTD;
#define FPROTD                          _FPROTD.Byte
#define FPROTD_Bit0                     _FPROTD.Bits.Bit0

#define FPROTD_Bit0_MASK                1U


/*** SIGNATURE - SIGNATURE Register; 0x0000180F ***/
typedef union {
  byte Byte;
} SIGNATURESTR;
extern volatile SIGNATURESTR _SIGNATURE;
#define SIGNATURE                       _SIGNATURE.Byte


/*** DBGCA - Debug Comparator A Register; 0x00001810 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1U
    #define DBGCAH_Bit9_MASK            2U
    #define DBGCAH_Bit10_MASK           4U
    #define DBGCAH_Bit11_MASK           8U
    #define DBGCAH_Bit12_MASK           16U
    #define DBGCAH_Bit13_MASK           32U
    #define DBGCAH_Bit14_MASK           64U
    #define DBGCAH_Bit15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1U
    #define DBGCAL_Bit1_MASK            2U
    #define DBGCAL_Bit2_MASK            4U
    #define DBGCAL_Bit3_MASK            8U
    #define DBGCAL_Bit4_MASK            16U
    #define DBGCAL_Bit5_MASK            32U
    #define DBGCAL_Bit6_MASK            64U
    #define DBGCAL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001812 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1U
    #define DBGCBH_Bit9_MASK            2U
    #define DBGCBH_Bit10_MASK           4U
    #define DBGCBH_Bit11_MASK           8U
    #define DBGCBH_Bit12_MASK           16U
    #define DBGCBH_Bit13_MASK           32U
    #define DBGCBH_Bit14_MASK           64U
    #define DBGCBH_Bit15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1U
    #define DBGCBL_Bit1_MASK            2U
    #define DBGCBL_Bit2_MASK            4U
    #define DBGCBL_Bit3_MASK            8U
    #define DBGCBL_Bit4_MASK            16U
    #define DBGCBL_Bit5_MASK            32U
    #define DBGCBL_Bit6_MASK            64U
    #define DBGCBL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB;
#define DBGCB                           _DBGCB.Word


/*** DBGF - Debug FIFO Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1U
    #define DBGFH_Bit9_MASK             2U
    #define DBGFH_Bit10_MASK            4U
    #define DBGFH_Bit11_MASK            8U
    #define DBGFH_Bit12_MASK            16U
    #define DBGFH_Bit13_MASK            32U
    #define DBGFH_Bit14_MASK            64U
    #define DBGFH_Bit15_MASK            128U
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1U
    #define DBGFL_Bit1_MASK             2U
    #define DBGFL_Bit2_MASK             4U
    #define DBGFL_Bit3_MASK             8U
    #define DBGFL_Bit4_MASK             16U
    #define DBGFL_Bit5_MASK             32U
    #define DBGFL_Bit6_MASK             64U
    #define DBGFL_Bit7_MASK             128U
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF;
#define DBGF                            _DBGF.Word


/*** DBGC - Debug Control Register; 0x00001816 ***/
typedef union {
  byte Byte;
  struct {
    byte RWBEN       :1;                                       /* Enable R/W for Comparator B */
    byte RWB         :1;                                       /* R/W Comparison Value for Comparator B */
    byte RWAEN       :1;                                       /* Enable R/W for Comparator A */
    byte RWA         :1;                                       /* R/W Comparison Value for Comparator A */
    byte BRKEN       :1;                                       /* Break Enable */
    byte TAG         :1;                                       /* Tag/Force Select */
    byte ARM         :1;                                       /* Arm Control */
    byte DBGEN       :1;                                       /* Debug Module Enable */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC;
#define DBGC                            _DBGC.Byte
#define DBGC_RWBEN                      _DBGC.Bits.RWBEN
#define DBGC_RWB                        _DBGC.Bits.RWB
#define DBGC_RWAEN                      _DBGC.Bits.RWAEN
#define DBGC_RWA                        _DBGC.Bits.RWA
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_RWBEN_MASK                 1U
#define DBGC_RWB_MASK                   2U
#define DBGC_RWAEN_MASK                 4U
#define DBGC_RWA_MASK                   8U
#define DBGC_BRKEN_MASK                 16U
#define DBGC_TAG_MASK                   32U
#define DBGC_ARM_MASK                   64U
#define DBGC_DBGEN_MASK                 128U


/*** DBGT - Debug Trigger Register; 0x00001817 ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Select Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Select Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Select Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Select Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Select */
    byte TRGSEL      :1;                                       /* Trigger Type */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1U
#define DBGT_TRG1_MASK                  2U
#define DBGT_TRG2_MASK                  4U
#define DBGT_TRG3_MASK                  8U
#define DBGT_BEGIN_MASK                 64U
#define DBGT_TRGSEL_MASK                128U
#define DBGT_TRG_MASK                   15U
#define DBGT_TRG_BITNUM                 0U


/*** DBGS - Debug Status Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bit 3 */
    byte             :1; 
    byte ARMF        :1;                                       /* Arm Flag */
    byte BF          :1;                                       /* Trigger Match B Flag */
    byte AF          :1;                                       /* Trigger Match A Flag */
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS;
#define DBGS                            _DBGS.Byte
#define DBGS_CNT0                       _DBGS.Bits.CNT0
#define DBGS_CNT1                       _DBGS.Bits.CNT1
#define DBGS_CNT2                       _DBGS.Bits.CNT2
#define DBGS_CNT3                       _DBGS.Bits.CNT3
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF
#define DBGS_CNT                        _DBGS.MergedBits.grpCNT

#define DBGS_CNT0_MASK                  1U
#define DBGS_CNT1_MASK                  2U
#define DBGS_CNT2_MASK                  4U
#define DBGS_CNT3_MASK                  8U
#define DBGS_ARMF_MASK                  32U
#define DBGS_BF_MASK                    64U
#define DBGS_AF_MASK                    128U
#define DBGS_CNT_MASK                   15U
#define DBGS_CNT_BITNUM                 0U


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1U
#define FCDIV_DIV1_MASK                 2U
#define FCDIV_DIV2_MASK                 4U
#define FCDIV_DIV3_MASK                 8U
#define FCDIV_DIV4_MASK                 16U
#define FCDIV_DIV5_MASK                 32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_DIVLD_MASK                128U
#define FCDIV_DIV_MASK                  63U
#define FCDIV_DIV_BITNUM                0U


/*** FOPT - FLASH Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC00                      _FOPT.Bits.SEC00
#define FOPT_SEC01                      _FOPT.Bits.SEC01
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC0                       _FOPT.MergedBits.grpSEC0

#define FOPT_SEC00_MASK                 1U
#define FOPT_SEC01_MASK                 2U
#define FOPT_FNORED_MASK                64U
#define FOPT_KEYEN_MASK                 128U
#define FOPT_SEC0_MASK                  3U
#define FOPT_SEC0_BITNUM                0U


/*** FCNFG - FLASH Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Writing of Access Key */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - FLASH Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS7                      _FPROT.Bits.FPS7
#define FPROT_FPS_1                     _FPROT.MergedBits.grpFPS_1
#define FPROT_FPS                       FPROT_FPS_1

#define FPROT_FPDIS_MASK                1U
#define FPROT_FPS1_MASK                 2U
#define FPROT_FPS2_MASK                 4U
#define FPROT_FPS3_MASK                 8U
#define FPROT_FPS4_MASK                 16U
#define FPROT_FPS5_MASK                 32U
#define FPROT_FPS6_MASK                 64U
#define FPROT_FPS7_MASK                 128U
#define FPROT_FPS_1_MASK                254U
#define FPROT_FPS_1_BITNUM              1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - FLASH Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* FLASH Command Bit 0 */
    byte FCMD1       :1;                                       /* FLASH Command Bit 1 */
    byte FCMD2       :1;                                       /* FLASH Command Bit 2 */
    byte FCMD3       :1;                                       /* FLASH Command Bit 3 */
    byte FCMD4       :1;                                       /* FLASH Command Bit 4 */
    byte FCMD5       :1;                                       /* FLASH Command Bit 5 */
    byte FCMD6       :1;                                       /* FLASH Command Bit 6 */
    byte FCMD7       :1;                                       /* FLASH Command Bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD7_MASK                 128U


/*** PTAPE - Port A Pull Enable Register; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTBPE - Port B Pull Enable Register; 0x00001844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte             :1; 
    byte             :1; 
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTBPE :2;
    byte         :1;
    byte         :1;
    byte grpPTBPE_4 :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE                     _PTBPE.MergedBits.grpPTBPE
#define PTBPE_PTBPE_4                   _PTBPE.MergedBits.grpPTBPE_4

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE_MASK                3U
#define PTBPE_PTBPE_BITNUM              0U
#define PTBPE_PTBPE_4_MASK              48U
#define PTBPE_PTBPE_4_BITNUM            4U


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001845 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPTBSE_1 :5;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE_1                   _PTBSE.MergedBits.grpPTBSE_1

#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE_1_MASK              62U
#define PTBSE_PTBSE_1_BITNUM            1U


/*** PTBDS - Port B Drive Strength Selection Register; 0x00001846 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte grpPTBDS_1 :5;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS_1                   _PTBDS.MergedBits.grpPTBDS_1

#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS_1_MASK              62U
#define PTBDS_PTBDS_1_BITNUM            1U


/*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x0000FFAE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM_bit   :1;                                       /* MCG Fine Trim */ /*Warning: bit name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR * __far)0x0000FFAE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM_bit

#define NVFTRIM_FTRIM_MASK              1U


/*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x0000FFAF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} NVMCGTRMSTR;
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT = <NVMCGTRM_INITVAL>; */
#define _NVMCGTRM (*(const NVMCGTRMSTR * __far)0x0000FFAF)
#define NVMCGTRM                        _NVMCGTRM.Byte
#define NVMCGTRM_TRIM0                  _NVMCGTRM.Bits.TRIM0
#define NVMCGTRM_TRIM1                  _NVMCGTRM.Bits.TRIM1
#define NVMCGTRM_TRIM2                  _NVMCGTRM.Bits.TRIM2
#define NVMCGTRM_TRIM3                  _NVMCGTRM.Bits.TRIM3
#define NVMCGTRM_TRIM4                  _NVMCGTRM.Bits.TRIM4
#define NVMCGTRM_TRIM5                  _NVMCGTRM.Bits.TRIM5
#define NVMCGTRM_TRIM6                  _NVMCGTRM.Bits.TRIM6
#define NVMCGTRM_TRIM7                  _NVMCGTRM.Bits.TRIM7

#define NVMCGTRM_TRIM0_MASK             1U
#define NVMCGTRM_TRIM1_MASK             2U
#define NVMCGTRM_TRIM2_MASK             4U
#define NVMCGTRM_TRIM3_MASK             8U
#define NVMCGTRM_TRIM4_MASK             16U
#define NVMCGTRM_TRIM5_MASK             32U
#define NVMCGTRM_TRIM6_MASK             64U
#define NVMCGTRM_TRIM7_MASK             128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** CHECKSUMBYPASS - Checksum bypass; 0x0000FFBA ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Checksum bypass, bit 0 */
    byte BIT1        :1;                                       /* Checksum bypass, bit 1 */
    byte BIT2        :1;                                       /* Checksum bypass, bit 2 */
    byte BIT3        :1;                                       /* Checksum bypass, bit 3 */
    byte BIT4        :1;                                       /* Checksum bypass, bit 4 */
    byte BIT5        :1;                                       /* Checksum bypass, bit 5 */
    byte BIT6        :1;                                       /* Checksum bypass, bit 6 */
    byte BIT7        :1;                                       /* Checksum bypass, bit 7 */
  } Bits;
} CHECKSUMBYPASSSTR;
/* Tip for register initialization in the user code:  const byte CHECKSUMBYPASS_INIT = <CHECKSUMBYPASS_INITVAL>; */
#define _CHECKSUMBYPASS (*(const CHECKSUMBYPASSSTR * __far)0x0000FFBA)
#define CHECKSUMBYPASS                  _CHECKSUMBYPASS.Byte
#define CHECKSUMBYPASS_BIT0             _CHECKSUMBYPASS.Bits.BIT0
#define CHECKSUMBYPASS_BIT1             _CHECKSUMBYPASS.Bits.BIT1
#define CHECKSUMBYPASS_BIT2             _CHECKSUMBYPASS.Bits.BIT2
#define CHECKSUMBYPASS_BIT3             _CHECKSUMBYPASS.Bits.BIT3
#define CHECKSUMBYPASS_BIT4             _CHECKSUMBYPASS.Bits.BIT4
#define CHECKSUMBYPASS_BIT5             _CHECKSUMBYPASS.Bits.BIT5
#define CHECKSUMBYPASS_BIT6             _CHECKSUMBYPASS.Bits.BIT6
#define CHECKSUMBYPASS_BIT7             _CHECKSUMBYPASS.Bits.BIT7

#define CHECKSUMBYPASS_BIT0_MASK        1U
#define CHECKSUMBYPASS_BIT1_MASK        2U
#define CHECKSUMBYPASS_BIT2_MASK        4U
#define CHECKSUMBYPASS_BIT3_MASK        8U
#define CHECKSUMBYPASS_BIT4_MASK        16U
#define CHECKSUMBYPASS_BIT5_MASK        32U
#define CHECKSUMBYPASS_BIT6_MASK        64U
#define CHECKSUMBYPASS_BIT7_MASK        128U


/*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS7                     _NVPROT.Bits.FPS7
#define NVPROT_FPS_1                    _NVPROT.MergedBits.grpFPS_1
#define NVPROT_FPS                      NVPROT_FPS_1

#define NVPROT_FPDIS_MASK               1U
#define NVPROT_FPS1_MASK                2U
#define NVPROT_FPS2_MASK                4U
#define NVPROT_FPS3_MASK                8U
#define NVPROT_FPS4_MASK                16U
#define NVPROT_FPS5_MASK                32U
#define NVPROT_FPS6_MASK                64U
#define NVPROT_FPS7_MASK                128U
#define NVPROT_FPS_1_MASK               254U
#define NVPROT_FPS_1_BITNUM             1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC00                     _NVOPT.Bits.SEC00
#define NVOPT_SEC01                     _NVOPT.Bits.SEC01
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC0                      _NVOPT.MergedBits.grpSEC0

#define NVOPT_SEC00_MASK                1U
#define NVOPT_SEC01_MASK                2U
#define NVOPT_FNORED_MASK               64U
#define NVOPT_KEYEN_MASK                128U
#define NVOPT_SEC0_MASK                 3U
#define NVOPT_SEC0_BITNUM               0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 11.8.2009 7:48:10 */

#define SIGNATURE_SIGNATURE0             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE1             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE2             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE3             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE4             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE5             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE6             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE7             This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE0_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE1_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE2_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE3_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE4_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE5_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE6_MASK        This_symb_has_been_depreciated
#define SIGNATURE_SIGNATURE7_MASK        This_symb_has_been_depreciated
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
