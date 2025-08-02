; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no103

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        mov     eax, I8                 
        mov     I7, eax                 
        mov     I9, eax                 
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
I0      dd      0                       ; zero

SECTION .bss                            
I6      resd    z                       ; I6
I7      resd    d                       ; I7
I8      resd    zero                    ; I8
I9      resd    z                       ; I9
I2      resd    integer                 ; a
I3      resd    integer                 ; a,b
I4      resd    integer                 ; a,b,c
B0      resd    boolean                 ; d
I5      resd    integer                 ; z
