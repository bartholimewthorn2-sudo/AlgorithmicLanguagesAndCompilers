; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no137

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I4,eax                  ; store eax at I4
        mov     I5, eax                 
        Call    Clrf                    
        mov     eax, I6                 
        neg     eax                     
