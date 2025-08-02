; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no126

_start:                                 
        mov     I0, eax                 
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I0      resd    a                       ; I0
