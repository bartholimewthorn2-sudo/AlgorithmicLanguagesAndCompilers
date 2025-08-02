; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no105

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        Call    ReadInt                 ; read int; value placed in eax
        mov     I8,eax                  ; store eax at I8
        Call    ReadInt                 ; read int; value placed in eax
        mov     I9,eax                  ; store eax at I9
        Call    ReadInt                 ; read int; value placed in eax
        mov     I10,eax                 ; store eax at I10
        mov     eax, I12                
        mov     I11, eax                
        mov     eax, I14                
        mov     I13, eax                
