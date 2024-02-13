;
; File generated by cc65 v 2.18 - Ubuntu 2.19-1
;
	.fopt		compiler,"cc65 v 2.18 - Ubuntu 2.19-1"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.import		_printf
	.import		_clrscr
	.import		_cgetc
	.import		_textcolor
	.import		_bgcolor
	.import		_bordercolor
	.export		_textc
	.export		_backgroundc
	.export		_borderc
	.export		_main

.segment	"DATA"

_textc:
	.byte	$00
_backgroundc:
	.byte	$00
_borderc:
	.byte	$00

.segment	"RODATA"

L0019:
	.byte	$C3,$D4,$D2,$CC,$20,$2B,$20,$D3,$C8,$C9,$C6,$D4,$20,$2D,$20,$C5
	.byte	$CE,$C1,$C2,$CC,$C5,$2F,$C4,$C9,$D3,$C1,$C2,$CC,$C5,$20,$D5,$D0
	.byte	$D0,$C5,$D2,$2F,$CC,$CF,$D7,$C5,$D2,$20,$C3,$C1,$D3,$C5,$2E,$0D
	.byte	$00
L0016:
	.byte	$D3,$C3,$D2,$CC,$20,$CC,$CF,$C3,$CB,$20,$2D,$20,$C6,$CF,$D2,$20
	.byte	$C4,$C9,$C7,$C9,$D4,$20,$C9,$CE,$20,$CB,$C5,$D9,$C2,$CF,$C1,$D2
	.byte	$C4,$2E,$0D,$00
L0013:
	.byte	$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$20,$D7,$C5,$CC,$C3,$CF
	.byte	$CD,$C5,$20,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$3A,$0D,$0D,$00
L002C:
	.byte	$D0,$52,$4F,$47,$52,$41,$4D,$20,$46,$49,$4E,$49,$53,$48,$45,$44
	.byte	$2E,$00
L0029:
	.byte	$81,$00

; ---------------------------------------------------------------
; int __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

;
; clrscr();
;
	jsr     _clrscr
;
; *(char*)0XD021 = 3; // Background color (only bits #0-#3).
;
	ldx     #$00
	lda     #$03
	sta     $D021
;
; *(char*)0xD020 = 5; // Border color (only bits #0-#3).
;
	ldx     #$00
	lda     #$05
	sta     $D020
;
; textc = textcolor(COLOR_BLACK);
;
	lda     #$00
	jsr     _textcolor
	sta     _textc
;
; printf(":::::::::: WELCOME ::::::::::\n\n");
;
	lda     #<(L0013)
	ldx     #>(L0013)
	jsr     pushax
	ldy     #$02
	jsr     _printf
;
; printf("SCRL LOCK - FOR DIGIT IN KEYBOARD.\n");
;
	lda     #<(L0016)
	ldx     #>(L0016)
	jsr     pushax
	ldy     #$02
	jsr     _printf
;
; printf("CTRL + SHIFT - ENABLE/DISABLE UPPER/LOWER CASE.\n");
;
	lda     #<(L0019)
	ldx     #>(L0019)
	jsr     pushax
	ldy     #$02
	jsr     _printf
;
; cgetc();
;
	jsr     _cgetc
;
; clrscr();
;
	jsr     _clrscr
;
; textcolor(textc);
;
	lda     _textc
	jsr     _textcolor
;
; bordercolor(borderc);
;
	lda     _borderc
	jsr     _bordercolor
;
; bgcolor(backgroundc);
;
	lda     _backgroundc
	jsr     _bgcolor
;
; POKE(0xD018, 0x14); // Mesma coisa que fazer *(char*)0xD018 = 0x14;
;
	ldx     #$00
	lda     #$14
	sta     $D018
;
; printf("\x81"); 
;
	lda     #<(L0029)
	ldx     #>(L0029)
	jsr     pushax
	ldy     #$02
	jsr     _printf
;
; printf("Program finished.");
;
	lda     #<(L002C)
	ldx     #>(L002C)
	jsr     pushax
	ldy     #$02
	jsr     _printf
;
; return 0;
;
	ldx     #$00
	lda     #$00
	jmp     L0009
;
; }
;
L0009:	rts

.endproc

