   1               		.file	"halt.c"
   2               	__SP_H__ = 0x3e
   3               	__SP_L__ = 0x3d
   4               	__SREG__ = 0x3f
   5               	__tmp_reg__ = 0
   6               	__zero_reg__ = 1
   7               		.text
   8               	.Ltext0:
   9               		.cfi_sections	.debug_frame
  10               	.global	wait_1ms
  12               	wait_1ms:
  13               	.LFB7:
  14               		.file 1 "halt.c"
   1:halt.c        **** ...
  15               		.loc 1 6 0
  16               		.cfi_startproc
  17               	/* prologue: function */
  18               	/* frame size = 0 */
  19               	/* stack size = 0 */
  20               	.L__stack_usage = 0
  21               	.LVL0:
  22               		.loc 1 6 0
  23 0000 8EEA      		ldi r24,lo8(-82)
  24 0002 95E0      		ldi r25,lo8(5)
  25               	.LVL1:
  26               	.L3:
  27               	.LBB2:
  28               		.loc 1 8 0 discriminator 2
  29 0004 2091 0000 		lds r18,dummy
  30 0008 2F5F      		subi r18,lo8(-(1))
  31 000a 2093 0000 		sts dummy,r18
  32               	.LVL2:
  33 000e 0197      		sbiw r24,1
  34               	.LVL3:
  35               		.loc 1 7 0 discriminator 2
  36 0010 0097      		sbiw r24,0
  37 0012 01F4      		brne .L3
  38               	/* epilogue start */
  39               	.LBE2:
  40               		.loc 1 10 0
  41 0014 0895      		ret
  42               		.cfi_endproc
  43               	.LFE7:
  45               	.global	wait
  47               	wait:
  48               	.LFB8:
  49               		.loc 1 12 0
  50               		.cfi_startproc
  51               	.LVL4:
  52 0016 CF93      		push r28
  53               	.LCFI0:
  54               		.cfi_def_cfa_offset 3
  55               		.cfi_offset 28, -2
  56 0018 DF93      		push r29
  57               	.LCFI1:
  58               		.cfi_def_cfa_offset 4
  59               		.cfi_offset 29, -3
  60               	/* prologue: function */
  61               	/* frame size = 0 */
  62               	/* stack size = 2 */
  63               	.L__stack_usage = 2
  64 001a EC01      		movw r28,r24
  65               	.LVL5:
  66               	.L6:
  67               	.LBB3:
  68               		.loc 1 13 0 discriminator 1
  69 001c 2097      		sbiw r28,0
  70 001e 01F0      		breq .L8
  71               		.loc 1 14 0 discriminator 2
  72 0020 0E94 0000 		call wait_1ms
  73               	.LVL6:
  74               		.loc 1 13 0 discriminator 2
  75 0024 2197      		sbiw r28,1
  76               	.LVL7:
  77 0026 00C0      		rjmp .L6
  78               	.L8:
  79               	/* epilogue start */
  80               	.LBE3:
  81               		.loc 1 16 0
  82 0028 DF91      		pop r29
  83 002a CF91      		pop r28
  84               	.LVL8:
  85 002c 0895      		ret
  86               		.cfi_endproc
  87               	.LFE8:
  89               	.global	port_halt
  91               	port_halt:
  92               	.LFB9:
  93               		.loc 1 18 0
  94               		.cfi_startproc
  95               	/* prologue: function */
  96               	/* frame size = 0 */
  97               	/* stack size = 0 */
  98               	.L__stack_usage = 0
  99               		.loc 1 19 0
 100               	/* #APP */
 101               	 ;  19 "halt.c" 1
 102 002e F894      		cli
 103               	 ;  0 "" 2
 104               		.loc 1 21 0
 105               	/* #NOAPP */
 106 0030 C0E2      		ldi r28,lo8(32)
 107               	.L10:
 108               		.loc 1 21 0 is_stmt 0 discriminator 1
 109 0032 85B1      		in r24,0x5
 110 0034 8C27      		eor r24,r28
 111 0036 85B9      		out 0x5,r24
 112               		.loc 1 22 0 is_stmt 1 discriminator 1
 113 0038 82E3      		ldi r24,lo8(50)
 114 003a 90E0      		ldi r25,0
 115 003c 0E94 0000 		call wait
 116               	.LVL9:
 117 0040 00C0      		rjmp .L10
 118               		.cfi_endproc
 119               	.LFE9:
 121               		.comm	dummy,1,1
 122               	.Letext0:
 123               		.file 2 "/usr/lib/avr/include/stdint.h"
 124               		.file 3 "../chibios/os/hal/platforms/AVR/pal_lld.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 halt.c
     /tmp/ccjbdMKC.s:2      *ABS*:000000000000003e __SP_H__
     /tmp/ccjbdMKC.s:3      *ABS*:000000000000003d __SP_L__
     /tmp/ccjbdMKC.s:4      *ABS*:000000000000003f __SREG__
     /tmp/ccjbdMKC.s:5      *ABS*:0000000000000000 __tmp_reg__
     /tmp/ccjbdMKC.s:6      *ABS*:0000000000000001 __zero_reg__
     /tmp/ccjbdMKC.s:12     .text:0000000000000000 wait_1ms
                            *COM*:0000000000000001 dummy
     /tmp/ccjbdMKC.s:47     .text:0000000000000016 wait
     /tmp/ccjbdMKC.s:91     .text:000000000000002e port_halt

UNDEFINED SYMBOLS
__do_clear_bss
