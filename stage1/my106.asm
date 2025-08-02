; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no106

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I4,eax                  ; store eax at I4
        Call    ReadInt                 ; read int; value placed in eax
        mov     I5,eax                  ; store eax at I5
