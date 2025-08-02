;;;NASM - The Netwide Assembler https://www.nasm.us

;;Louis Jensen
;;CS 4301
;;Lab 12
 
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .data
msg1    dw      ' is valid',0
msg2    dw		' is invalid',0

SECTION .text
global  _start
 
_start: 
	mov edx, msg2
	call WriteString
	END