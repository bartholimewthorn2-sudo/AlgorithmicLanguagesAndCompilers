; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no166

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        mov     eax, I8                 
        mov     I7, eax                 
        Exit    {0}                     

SECTION .data                           
I0      dd      3                       ; w
B0      dd      -1                      ; x

SECTION .bss                            
I6      resd    a                       ; I6
I7      resd    d                       ; I7
I8      resd    x                       ; I8
I1      resd    integer                 ; a
I2      resd    integer                 ; a,b
I3      resd    integer                 ; a,b,c
I4      resd    integer                 ; a,b,c,d
I5      resd    integer                 ; e
