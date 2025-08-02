; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no134

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I3,eax                  ; store eax at I3
        mov     eax, I5                 
        add     eax, I5                 
        mov     I4, eax                 
        mov     I8, eax                 
        Call    Clrf                    
