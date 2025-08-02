; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no149

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        mov     eax, I9                 
        add     eax, I9                 
        mov     eax, I12                
        mov     I11, eax                
        mov     I13, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I10     resd    d                       ; I10
I11     resd    T0                      ; I11
I12     resd    f                       ; I12
I13     resd    a                       ; I13
I6      resd    a,b,c,d,e,f             ; I6
I7      resd    a                       ; I7
I8      resd    b                       ; I8
I9      resd    c                       ; I9
I0      resd    integer                 ; a
I1      resd    integer                 ; a,b
I2      resd    integer                 ; a,b,c
I3      resd    integer                 ; a,b,c,d
I4      resd    integer                 ; a,b,c,d,e
I5      resd    integer                 ; f
