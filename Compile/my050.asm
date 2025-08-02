; LOUIS JENSEN       Thu Nov 21 21:41:48 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage0no050

_start:                                 
        Exit    {0}                     

SECTION .data                           
I0      dd      1                       ; a
I1      dd      1                       ; b
I2      dd      stage0no050             ; c
I3      dd      3                       ; d

SECTION .bss                            
I6      resd    1                       ; biggernum
B2      resd    1                       ; maybe
I4      resd    1                       ; smallnum
I5      resd    1                       ; smallnum,bignum
B0      resd    1                       ; yes
B1      resd    1                       ; yes,no
