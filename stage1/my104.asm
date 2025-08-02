; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no104

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I4,eax                  ; store eax at I4
        mov     eax, I7                 
        mov     I6, eax                 
        mov     eax, I9                 
        mov     I8, eax                 
        mov     eax, I11                
        mov     I10, eax                
        mov     I12, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I0      dd      5                       ; five

SECTION .bss                            
I10     resd    c                       ; I10
I11     resd    a                       ; I11
I12     resd    a,b,c                   ; I12
I4      resd    a                       ; I4
I5      resd    a                       ; I5
I6      resd    a                       ; I6
I7      resd    five                    ; I7
I8      resd    b                       ; I8
I9      resd    a                       ; I9
I1      resd    integer                 ; a
I2      resd    integer                 ; a,b
I3      resd    integer                 ; c
