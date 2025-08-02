;;;NASM - The Netwide Assembler https://www.nasm.us
;;Louis Jensen
;;CS 4301
;;Lab 11
 
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .data
msg1    dw      'Fib(',0
msg2    dw		') = ',0
Fib0	dq		0
Fib1	dq		1
CurFib	dq		0

SECTION .text
global  _start
 
_start: 
call    ReadDec         ;read # from standard input
mov 	edi, eax
mov 	edx, msg1
call 	WriteString
mov 	eax, 0
call 	WriteDec
mov 	edx, msg2
call 	WriteString
mov		eax, 0
call 	WriteDec
call 	Crlf

mov		eax, edi
jz		.done
	
mov edx, msg1
call WriteString
mov eax, 1
call WriteDec
mov edx, msg2
call WriteString
mov eax, 1
call WriteDec
call Crlf

cmp edi, 2
jl	.done

mov ecx, 2
.Loop:
        mov     ebx,[Fib0]
		mov		eax,[Fib1]
        add     ebx,eax
        mov     [CurFib],ebx
		mov 	ebx,[Fib1]
		mov		[Fib0],ebx
		mov		ebx,[CurFib]
		mov		[Fib1],ebx
		
		mov		edx, msg1
		call 	WriteString
		mov 	eax, ecx
		call	WriteDec
		mov		edx, msg2
		call 	WriteString
		mov		eax, [CurFib]
		Call 	WriteDec
		call	Crlf
		
		inc 	ecx
		cmp		ecx, edi
		jle     .Loop
.done:
		Exit    {0}