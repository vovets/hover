   1               		.file	"cobs.c"
   2               	__SP_H__ = 0x3e
   3               	__SP_L__ = 0x3d
   4               	__SREG__ = 0x3f
   5               	__tmp_reg__ = 0
   6               	__zero_reg__ = 1
   7               		.text
   8               	.Ltext0:
   9               		.cfi_sections	.debug_frame
  10               	.global	cobs_encode
  12               	cobs_encode:
  13               	.LFB0:
  14               		.file 1 "cobs.c"
   1:cobs.c        **** ...
  15               		.loc 1 6 0
  16               		.cfi_startproc
  17               	.LVL0:
  18 0000 CF93      		push r28
  19               	.LCFI0:
  20               		.cfi_def_cfa_offset 3
  21               		.cfi_offset 28, -2
  22 0002 DF93      		push r29
  23               	.LCFI1:
  24               		.cfi_def_cfa_offset 4
  25               		.cfi_offset 29, -3
  26               	/* prologue: function */
  27               	/* frame size = 0 */
  28               	/* stack size = 2 */
  29               	.L__stack_usage = 2
  30               	.LVL1:
  31               		.loc 1 19 0
  32 0004 A42F      		mov r26,r20
  33 0006 B52F      		mov r27,r21
  34 0008 1196      		adiw r26,1
  35               	.LVL2:
  36               		.loc 1 20 0
  37 000a 680F      		add r22,r24
  38 000c 791F      		adc r23,r25
  39               	.LVL3:
  40 000e C82F      		mov r28,r24
  41 0010 D92F      		mov r29,r25
  42               		.loc 1 8 0
  43 0012 E42F      		mov r30,r20
  44 0014 F52F      		mov r31,r21
  45               		.loc 1 7 0
  46 0016 81E0      		ldi r24,lo8(1)
  47               	.LVL4:
  48               	.L2:
  49 0018 2A2F      		mov r18,r26
  50 001a 3B2F      		mov r19,r27
  51 001c 2F5F      		subi r18,-1
  52 001e 3F4F      		sbci r19,-1
  53               		.loc 1 21 0 discriminator 1
  54 0020 C617      		cp r28,r22
  55 0022 D707      		cpc r29,r23
  56 0024 00F4      		brsh .L8
  57               		.loc 1 22 0
  58 0026 9991      		ld r25,Y+
  59               	.LVL5:
  60 0028 9111      		cpse r25,__zero_reg__
  61 002a 00C0      		rjmp .L3
  62               		.loc 1 23 0
  63 002c 8083      		st Z,r24
  64               	.LVL6:
  65 002e EA2F      		mov r30,r26
  66 0030 FB2F      		mov r31,r27
  67 0032 00C0      		rjmp .L6
  68               	.LVL7:
  69               	.L3:
  70               		.loc 1 26 0
  71 0034 9C93      		st X,r25
  72               	.LVL8:
  73               		.loc 1 29 0
  74 0036 8F5F      		subi r24,lo8(-(1))
  75               	.LVL9:
  76               		.loc 1 30 0
  77 0038 8F3F      		cpi r24,lo8(-1)
  78 003a 01F4      		brne .L4
  79               		.loc 1 31 0
  80 003c 8083      		st Z,r24
  81               	.LVL10:
  82 003e E22F      		mov r30,r18
  83 0040 F32F      		mov r31,r19
  84 0042 2A2F      		mov r18,r26
  85 0044 3B2F      		mov r19,r27
  86               	.LVL11:
  87 0046 2E5F      		subi r18,-2
  88 0048 3F4F      		sbci r19,-1
  89               	.LVL12:
  90               	.L6:
  91 004a 81E0      		ldi r24,lo8(1)
  92               	.LVL13:
  93               	.L4:
  94               		.loc 1 31 0 is_stmt 0 discriminator 1
  95 004c A22F      		mov r26,r18
  96 004e B32F      		mov r27,r19
  97 0050 00C0      		rjmp .L2
  98               	.LVL14:
  99               	.L8:
 100               		.loc 1 35 0 is_stmt 1
 101 0052 8083      		st Z,r24
 102               	.LVL15:
 103               		.loc 1 36 0
 104 0054 822F      		mov r24,r18
 105 0056 932F      		mov r25,r19
 106 0058 841B      		sub r24,r20
 107 005a 950B      		sbc r25,r21
 108               		.loc 1 37 0
 109 005c 0197      		sbiw r24,1
 110               	/* epilogue start */
 111 005e DF91      		pop r29
 112 0060 CF91      		pop r28
 113               	.LVL16:
 114 0062 0895      		ret
 115               		.cfi_endproc
 116               	.LFE0:
 118               	.Letext0:
 119               		.file 2 "/usr/lib/avr/include/stdint.h"
 120               		.file 3 "/usr/lib/gcc/avr/4.8.2/include/stddef.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 cobs.c
     /tmp/ccwK81fc.s:2      *ABS*:000000000000003e __SP_H__
     /tmp/ccwK81fc.s:3      *ABS*:000000000000003d __SP_L__
     /tmp/ccwK81fc.s:4      *ABS*:000000000000003f __SREG__
     /tmp/ccwK81fc.s:5      *ABS*:0000000000000000 __tmp_reg__
     /tmp/ccwK81fc.s:6      *ABS*:0000000000000001 __zero_reg__
     /tmp/ccwK81fc.s:12     .text:0000000000000000 cobs_encode

NO UNDEFINED SYMBOLS
