; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no160

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        mov     I8, eax                 
        Call    Clrf                    
        mov     eax, I11                
        mov     I10, eax                
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
I10     resd    a                       ; I10
I11     resd    c                       ; I11
I6      resd    i                       ; I6
I7      resd    j                       ; I7
I8      resd    i,j                     ; I8
I9      resd    k                       ; I9
I4      resd    integer                 ; i
I5      resd    integer                 ; j
B4      resd    boolean                 ; k
