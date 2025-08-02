; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no128

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I0,eax                  ; store eax at I0
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I0      resd    5                       ; I0
