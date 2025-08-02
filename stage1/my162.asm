; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no162

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        mov     I8, eax                 
        Call    Clrf                    
        mov     eax, I11                
        mov     I10, eax                
