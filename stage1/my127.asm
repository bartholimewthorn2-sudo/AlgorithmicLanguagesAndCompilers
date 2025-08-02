; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no127

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I1,eax                  ; store eax at I1
        Exit    {0}                     

SECTION .data                           
I0      dd      5                       ; a

SECTION .bss                            
I1      resd    a                       ; I1
