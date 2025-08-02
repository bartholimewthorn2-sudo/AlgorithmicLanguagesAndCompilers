; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no110

_start:                                 
        mov     eax, I8                 
        mov     I7, eax                 
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
I0      dd      0                       ; zero

SECTION .bss                            
I7      resd    a                       ; I7
I8      resd    m                       ; I8
I2      resd    integer                 ; a
I3      resd    integer                 ; a,b
I4      resd    integer                 ; c
I5      resd    integer                 ; w
I6      resd    integer                 ; z
