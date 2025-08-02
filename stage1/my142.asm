; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no142

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
