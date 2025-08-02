; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no112

_start:                                 
        mov     eax, I8                 
        mov     I7, eax                 
        mov     eax, I10                
        mov     I9, eax                 
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
I0      dd      0                       ; zero

SECTION .bss                            
I10     resd    a                       ; I10
I7      resd    d                       ; I7
I8      resd    a                       ; I8
I9      resd    b                       ; I9
I2      resd    integer                 ; a
I3      resd    integer                 ; a,b
I4      resd    integer                 ; c
B0      resd    boolean                 ; d
B1      resd    boolean                 ; e
I5      resd    integer                 ; w
I6      resd    integer                 ; z
