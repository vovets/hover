   1               		.file	"test1.c"
   2               	__SP_H__ = 0x3e
   3               	__SP_L__ = 0x3d
   4               	__SREG__ = 0x3f
   5               	__tmp_reg__ = 0
   6               	__zero_reg__ = 1
   7               		.text
   8               	.Ltext0:
   9               		.cfi_sections	.debug_frame
  10               	.global	sendPacketRaw
  12               	sendPacketRaw:
  13               	.LFB7:
  14               		.file 1 "test1.c"
   1:test1.c       **** ...
  15               		.loc 1 21 0
  16               		.cfi_startproc
  17               	.LVL0:
  18 0000 EF92      		push r14
  19               	.LCFI0:
  20               		.cfi_def_cfa_offset 3
  21               		.cfi_offset 14, -2
  22 0002 FF92      		push r15
  23               	.LCFI1:
  24               		.cfi_def_cfa_offset 4
  25               		.cfi_offset 15, -3
  26 0004 0F93      		push r16
  27               	.LCFI2:
  28               		.cfi_def_cfa_offset 5
  29               		.cfi_offset 16, -4
  30 0006 1F93      		push r17
  31               	.LCFI3:
  32               		.cfi_def_cfa_offset 6
  33               		.cfi_offset 17, -5
  34 0008 CF93      		push r28
  35               	.LCFI4:
  36               		.cfi_def_cfa_offset 7
  37               		.cfi_offset 28, -6
  38 000a DF93      		push r29
  39               	.LCFI5:
  40               		.cfi_def_cfa_offset 8
  41               		.cfi_offset 29, -7
  42               	/* prologue: function */
  43               	/* frame size = 0 */
  44               	/* stack size = 6 */
  45               	.L__stack_usage = 6
  46 000c EB01      		movw r28,r22
  47 000e 7A01      		movw r14,r20
  48               		.loc 1 22 0
  49 0010 E60E      		add r14,r22
  50 0012 F71E      		adc r15,r23
  51               	.LVL1:
  52               		.loc 1 23 0
  53 0014 2091 0000 		lds r18,sent_packets
  54 0018 3091 0000 		lds r19,sent_packets+1
  55 001c 8C01      		movw r16,r24
  56 001e 095E      		subi r16,-23
  57 0020 1F4F      		sbci r17,-1
  58 0022 232B      		or r18,r19
  59 0024 01F4      		brne .L3
  60               		.loc 1 25 0
  61 0026 4FEF      		ldi r20,lo8(-1)
  62 0028 5FEF      		ldi r21,lo8(-1)
  63               	.LVL2:
  64 002a 60E0      		ldi r22,0
  65               	.LVL3:
  66               	.L5:
  67               		.loc 1 29 0 discriminator 2
  68 002c C801      		movw r24,r16
  69 002e 0E94 0000 		call chOQPutTimeout
  70               	.LVL4:
  71               	.L3:
  72               		.loc 1 29 0 is_stmt 0 discriminator 1
  73 0032 4FEF      		ldi r20,lo8(-1)
  74 0034 5FEF      		ldi r21,lo8(-1)
  75               		.loc 1 27 0 is_stmt 1 discriminator 1
  76 0036 CE15      		cp r28,r14
  77 0038 DF05      		cpc r29,r15
  78 003a 00F4      		brsh .L7
  79               		.loc 1 29 0 discriminator 2
  80 003c 6991      		ld r22,Y+
  81               	.LVL5:
  82 003e 00C0      		rjmp .L5
  83               	.LVL6:
  84               	.L7:
  85               		.loc 1 31 0
  86 0040 60E0      		ldi r22,0
  87 0042 C801      		movw r24,r16
  88 0044 0E94 0000 		call chOQPutTimeout
  89               	.LVL7:
  90               		.loc 1 32 0
  91 0048 8091 0000 		lds r24,sent_packets
  92 004c 9091 0000 		lds r25,sent_packets+1
  93 0050 0196      		adiw r24,1
  94 0052 9093 0000 		sts sent_packets+1,r25
  95 0056 8093 0000 		sts sent_packets,r24
  96               	/* epilogue start */
  97               		.loc 1 33 0
  98 005a DF91      		pop r29
  99 005c CF91      		pop r28
 100               	.LVL8:
 101 005e 1F91      		pop r17
 102 0060 0F91      		pop r16
 103               	.LVL9:
 104 0062 FF90      		pop r15
 105 0064 EF90      		pop r14
 106               	.LVL10:
 107 0066 0895      		ret
 108               		.cfi_endproc
 109               	.LFE7:
 111               		.section	.rodata.str1.1,"aMS",@progbits,1
 112               	.LC0:
 113 0000 7365 6E64 		.string	"sendPacket(), #1"
 113      5061 636B 
 113      6574 2829 
 113      2C20 2331 
 113      00
 114               		.text
 115               	.global	sendPacket
 117               	sendPacket:
 118               	.LFB8:
 119               		.loc 1 38 0
 120               		.cfi_startproc
 121               	.LVL11:
 122 0068 EF92      		push r14
 123               	.LCFI6:
 124               		.cfi_def_cfa_offset 3
 125               		.cfi_offset 14, -2
 126 006a FF92      		push r15
 127               	.LCFI7:
 128               		.cfi_def_cfa_offset 4
 129               		.cfi_offset 15, -3
 130 006c 0F93      		push r16
 131               	.LCFI8:
 132               		.cfi_def_cfa_offset 5
 133               		.cfi_offset 16, -4
 134 006e 1F93      		push r17
 135               	.LCFI9:
 136               		.cfi_def_cfa_offset 6
 137               		.cfi_offset 17, -5
 138 0070 CF93      		push r28
 139               	.LCFI10:
 140               		.cfi_def_cfa_offset 7
 141               		.cfi_offset 28, -6
 142 0072 DF93      		push r29
 143               	.LCFI11:
 144               		.cfi_def_cfa_offset 8
 145               		.cfi_offset 29, -7
 146               	/* prologue: function */
 147               	/* frame size = 0 */
 148               	/* stack size = 6 */
 149               	.L__stack_usage = 6
 150 0074 7C01      		movw r14,r24
 151 0076 CB01      		movw r24,r22
 152               	.LVL12:
 153 0078 EA01      		movw r28,r20
 154               		.loc 1 39 0
 155 007a 40E0      		ldi r20,lo8(encode_buffer)
 156 007c 50E0      		ldi r21,hi8(encode_buffer)
 157               	.LVL13:
 158 007e BE01      		movw r22,r28
 159               	.LVL14:
 160 0080 0E94 0000 		call cobs_encode
 161               	.LVL15:
 162 0084 8C01      		movw r16,r24
 163               	.LVL16:
 164               		.loc 1 40 0
 165 0086 2196      		adiw r28,1
 166               	.LVL17:
 167 0088 8C17      		cp r24,r28
 168 008a 9D07      		cpc r25,r29
 169 008c 01F0      		breq .L9
 170               		.loc 1 40 0 is_stmt 0 discriminator 1
 171 008e 80E0      		ldi r24,lo8(.LC0)
 172 0090 90E0      		ldi r25,hi8(.LC0)
 173 0092 0E94 0000 		call chDbgPanic
 174               	.LVL18:
 175               	.L9:
 176               		.loc 1 41 0 is_stmt 1
 177 0096 A801      		movw r20,r16
 178 0098 60E0      		ldi r22,lo8(encode_buffer)
 179 009a 70E0      		ldi r23,hi8(encode_buffer)
 180 009c C701      		movw r24,r14
 181               	/* epilogue start */
 182               		.loc 1 42 0
 183 009e DF91      		pop r29
 184 00a0 CF91      		pop r28
 185               	.LVL19:
 186 00a2 1F91      		pop r17
 187 00a4 0F91      		pop r16
 188               	.LVL20:
 189 00a6 FF90      		pop r15
 190 00a8 EF90      		pop r14
 191               	.LVL21:
 192               		.loc 1 41 0
 193 00aa 0C94 0000 		jmp sendPacketRaw
 194               	.LVL22:
 195               		.cfi_endproc
 196               	.LFE8:
 198               	.global	sendTestPackets
 200               	sendTestPackets:
 201               	.LFB9:
 202               		.loc 1 47 0
 203               		.cfi_startproc
 204 00ae FF92      		push r15
 205               	.LCFI12:
 206               		.cfi_def_cfa_offset 3
 207               		.cfi_offset 15, -2
 208 00b0 0F93      		push r16
 209               	.LCFI13:
 210               		.cfi_def_cfa_offset 4
 211               		.cfi_offset 16, -3
 212 00b2 1F93      		push r17
 213               	.LCFI14:
 214               		.cfi_def_cfa_offset 5
 215               		.cfi_offset 17, -4
 216 00b4 CF93      		push r28
 217               	.LCFI15:
 218               		.cfi_def_cfa_offset 6
 219               		.cfi_offset 28, -5
 220 00b6 DF93      		push r29
 221               	.LCFI16:
 222               		.cfi_def_cfa_offset 7
 223               		.cfi_offset 29, -6
 224               	/* prologue: function */
 225               	/* frame size = 0 */
 226               	/* stack size = 5 */
 227               	.L__stack_usage = 5
 228               	.LVL23:
 229               		.loc 1 47 0
 230 00b8 C1E0      		ldi r28,lo8(1)
 231 00ba D0E0      		ldi r29,0
 232 00bc 00E0      		ldi r16,lo8(message_buffer)
 233 00be 10E0      		ldi r17,hi8(message_buffer)
 234               	.LBB2:
 235               	.LBB3:
 236               	.LBB4:
 237               		.loc 1 52 0
 238 00c0 83E0      		ldi r24,lo8(3)
 239 00c2 F82E      		mov r15,r24
 240               	.LVL24:
 241               	.L11:
 242 00c4 2C2F      		mov r18,r28
 243               	.LVL25:
 244               	.LBE4:
 245               	.LBE3:
 246               	.LBE2:
 247               		.loc 1 47 0 discriminator 1
 248 00c6 E0E0      		ldi r30,lo8(message_buffer)
 249 00c8 F0E0      		ldi r31,hi8(message_buffer)
 250               	.LVL26:
 251               	.L14:
 252 00ca 8E2F      		mov r24,r30
 253 00cc 801B      		sub r24,r16
 254               	.LBB7:
 255               	.LBB6:
 256               	.LBB5:
 257               		.loc 1 52 0 discriminator 2
 258 00ce 6F2D      		mov r22,r15
 259 00d0 0E94 0000 		call __udivmodqi4
 260               		.loc 1 53 0 discriminator 2
 261 00d4 9193      		st Z+,r25
 262               	.LVL27:
 263 00d6 8E2F      		mov r24,r30
 264 00d8 801B      		sub r24,r16
 265               	.LBE5:
 266               		.loc 1 50 0 discriminator 2
 267 00da 8217      		cp r24,r18
 268 00dc 00F0      		brlo .L14
 269               	.LBE6:
 270               		.loc 1 55 0
 271 00de AE01      		movw r20,r28
 272 00e0 60E0      		ldi r22,lo8(message_buffer)
 273 00e2 70E0      		ldi r23,hi8(message_buffer)
 274 00e4 80E0      		ldi r24,lo8(SD1)
 275 00e6 90E0      		ldi r25,hi8(SD1)
 276 00e8 0E94 0000 		call sendPacket
 277               	.LVL28:
 278 00ec 2196      		adiw r28,1
 279               	.LVL29:
 280               		.loc 1 48 0
 281 00ee C031      		cpi r28,16
 282 00f0 D105      		cpc r29,__zero_reg__
 283 00f2 01F4      		brne .L11
 284               	/* epilogue start */
 285               	.LBE7:
 286               		.loc 1 57 0
 287 00f4 DF91      		pop r29
 288 00f6 CF91      		pop r28
 289               	.LVL30:
 290 00f8 1F91      		pop r17
 291 00fa 0F91      		pop r16
 292 00fc FF90      		pop r15
 293 00fe 0895      		ret
 294               		.cfi_endproc
 295               	.LFE9:
 297               		.section	.rodata.str1.1
 298               	.LC1:
 299 0011 4865 6C6C 		.string	"Hello!"
 299      6F21 00
 300               		.text
 301               	.global	sendHello
 303               	sendHello:
 304               	.LFB10:
 305               		.loc 1 62 0
 306               		.cfi_startproc
 307               	/* prologue: function */
 308               	/* frame size = 0 */
 309               	/* stack size = 0 */
 310               	.L__stack_usage = 0
 311               		.loc 1 63 0
 312 0100 60E0      		ldi r22,lo8(.LC1)
 313 0102 70E0      		ldi r23,hi8(.LC1)
 314 0104 80E0      		ldi r24,lo8(message_buffer)
 315 0106 90E0      		ldi r25,hi8(message_buffer)
 316 0108 0E94 0000 		call strcpy
 317               	.LVL31:
 318               		.loc 1 64 0
 319 010c E0E0      		ldi r30,lo8(message_buffer)
 320 010e F0E0      		ldi r31,hi8(message_buffer)
 321 0110 DF01      		movw r26,r30
 322               		0:
 323 0112 0D90      		ld __tmp_reg__,X+
 324 0114 0020      		tst __tmp_reg__
 325 0116 01F4      		brne 0b
 326 0118 AD01      		movw r20,r26
 327 011a 4150      		subi r20,1
 328 011c 5109      		sbc r21,__zero_reg__
 329 011e 4050      		subi r20,lo8(message_buffer)
 330 0120 5040      		sbci r21,hi8(message_buffer)
 331 0122 BF01      		movw r22,r30
 332 0124 80E0      		ldi r24,lo8(SD1)
 333 0126 90E0      		ldi r25,hi8(SD1)
 334 0128 0C94 0000 		jmp sendPacket
 335               	.LVL32:
 336               		.cfi_endproc
 337               	.LFE10:
 339               		.section	.text.startup,"ax",@progbits
 340               	.global	main
 342               	main:
 343               	.LFB11:
 344               		.loc 1 73 0
 345               		.cfi_startproc
 346               	/* prologue: function */
 347               	/* frame size = 0 */
 348               	/* stack size = 0 */
 349               	.L__stack_usage = 0
 350               		.loc 1 74 0
 351 0000 0E94 0000 		call halInit
 352               	.LVL33:
 353               		.loc 1 75 0
 354 0004 0E94 0000 		call chSysInit
 355               	.LVL34:
 356               		.loc 1 76 0
 357               	/* #APP */
 358               	 ;  76 "test1.c" 1
 359 0008 2D98      		cbi 5,5
 360               		
 361               	 ;  0 "" 2
 362               		.loc 1 77 0
 363               	/* #NOAPP */
 364 000a 60E0      		ldi r22,lo8(serialConfig)
 365 000c 70E0      		ldi r23,hi8(serialConfig)
 366 000e 80E0      		ldi r24,lo8(SD1)
 367 0010 90E0      		ldi r25,hi8(SD1)
 368 0012 0E94 0000 		call sdStart
 369               	.LVL35:
 370               	.L17:
 371               		.loc 1 80 0 discriminator 1
 372               	/* #APP */
 373               	 ;  80 "test1.c" 1
 374 0016 2D9A      		sbi 5,5
 375               		
 376               	 ;  0 "" 2
 377               		.loc 1 81 0 discriminator 1
 378               	/* #NOAPP */
 379 0018 0E94 0000 		call sendTestPackets
 380               	.LVL36:
 381               		.loc 1 82 0 discriminator 1
 382 001c 0E94 0000 		call sendHello
 383               	.LVL37:
 384               		.loc 1 83 0 discriminator 1
 385               	/* #APP */
 386               	 ;  83 "test1.c" 1
 387 0020 2D98      		cbi 5,5
 388               		
 389               	 ;  0 "" 2
 390               		.loc 1 84 0 discriminator 1
 391               	/* #NOAPP */
 392 0022 88EC      		ldi r24,lo8(-56)
 393 0024 90E0      		ldi r25,0
 394 0026 0E94 0000 		call chThdSleep
 395               	.LVL38:
 396 002a 00C0      		rjmp .L17
 397               		.cfi_endproc
 398               	.LFE11:
 400               		.data
 403               	serialConfig:
 404 0000 0800      		.word	8
 405 0002 03        		.byte	3
 406               		.comm	encode_buffer,16,1
 407               		.comm	message_buffer,15,1
 408               		.local	sent_packets
 409               		.comm	sent_packets,2,1
 410               		.text
 411               	.Letext0:
 412               		.file 2 "/usr/lib/gcc/avr/4.8.2/include/stddef.h"
 413               		.file 3 "/usr/lib/avr/include/stdint.h"
 414               		.file 4 "../chibios/os/ports/GCC/AVR/chtypes.h"
 415               		.file 5 "../chibios/os/kernel/include/chlists.h"
 416               		.file 6 "../chibios/os/kernel/include/chthreads.h"
 417               		.file 7 "../chibios/os/ports/GCC/AVR/chcore.h"
 418               		.file 8 "../chibios/os/kernel/include/chevents.h"
 419               		.file 9 "../chibios/os/kernel/include/chqueues.h"
 420               		.file 10 "../chibios/os/hal/platforms/AVR/pal_lld.h"
 421               		.file 11 "../chibios/os/hal/include/serial.h"
 422               		.file 12 "../chibios/os/hal/platforms/AVR/serial_lld.h"
 423               		.file 13 "cobs.h"
 424               		.file 14 "/usr/lib/avr/include/string.h"
 425               		.file 15 "../chibios/os/hal/include/hal.h"
 426               		.file 16 "../chibios/os/kernel/include/chsys.h"
 427               		.file 17 "../chibios/os/kernel/include/chdebug.h"
DEFINED SYMBOLS
                            *ABS*:0000000000000000 test1.c
     /tmp/ccutt7dr.s:2      *ABS*:000000000000003e __SP_H__
     /tmp/ccutt7dr.s:3      *ABS*:000000000000003d __SP_L__
     /tmp/ccutt7dr.s:4      *ABS*:000000000000003f __SREG__
     /tmp/ccutt7dr.s:5      *ABS*:0000000000000000 __tmp_reg__
     /tmp/ccutt7dr.s:6      *ABS*:0000000000000001 __zero_reg__
     /tmp/ccutt7dr.s:12     .text:0000000000000000 sendPacketRaw
                             .bss:0000000000000000 sent_packets
     /tmp/ccutt7dr.s:117    .text:0000000000000068 sendPacket
                            *COM*:0000000000000010 encode_buffer
     /tmp/ccutt7dr.s:200    .text:00000000000000ae sendTestPackets
                            *COM*:000000000000000f message_buffer
     /tmp/ccutt7dr.s:303    .text:0000000000000100 sendHello
     /tmp/ccutt7dr.s:342    .text.startup:0000000000000000 main
     /tmp/ccutt7dr.s:403    .data:0000000000000000 serialConfig

UNDEFINED SYMBOLS
chOQPutTimeout
cobs_encode
chDbgPanic
__udivmodqi4
SD1
strcpy
halInit
chSysInit
sdStart
chThdSleep
__do_copy_data
__do_clear_bss
