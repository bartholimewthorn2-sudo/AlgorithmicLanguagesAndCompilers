; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no153

_start:                                 
        mov     I4, eax                 
        Call    Clrf                    
        Call    ReadInt                 ; read int; value placed in eax
        mov     I5,eax                  ; store eax at I5
        mov     I6, eax                 
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
B0      dd      -1                      ; a
B1      dd      0                       ; b
B2      dd      -1                      ; c
B3      dd      0                       ; d
I0      dd      5                       ; e
I1      dd      +5                      ; f
I2      dd      -5                      ; g
I3      dd      -5                      ; h

SECTION .bss                            
I4      resd    a,b,c,d                 ; I4
I5      resd    i                       ; I5
I6      resd    i                       ; I6
B4      resd    boolean                 ; i
B5      resd    boolean                 ; j
