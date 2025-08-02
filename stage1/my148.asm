; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no148

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I4,eax                  ; store eax at I4
        mov     eax, I6                 
        mov     I5, eax                 
        mov     eax, I8                 
        mov     I7, eax                 
        mov     eax, I10                
        mov     I9, eax                 
        mov     I11, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I0      dd      0                       ; zero

SECTION .bss                            
I10     resd    b                       ; I10
I11     resd    a,b,c,d,e,f             ; I11
I4      resd    a,b,c                   ; I4
I5      resd    d                       ; I5
I6      resd    zero                    ; I6
I7      resd    e                       ; I7
I8      resd    c                       ; I8
I9      resd    f                       ; I9
I1      resd    integer                 ; a
I2      resd    integer                 ; a,b
I3      resd    integer                 ; c
B0      resd    boolean                 ; d
B1      resd    boolean                 ; d,e
B2      resd    boolean                 ; f
