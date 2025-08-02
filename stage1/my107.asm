; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no107

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        Call    ReadInt                 ; read int; value placed in eax
        mov     I8,eax                  ; store eax at I8
        Call    ReadInt                 ; read int; value placed in eax
        mov     I9,eax                  ; store eax at I9
        mov     eax, I11                
        add     eax, I11                
        mov     I10, eax                
        mov     eax, I15                
        imul    eax, I15                
        mov     I14, eax                
        mov     eax, I19                
        mov     I18, eax                
        mov     I20, eax                
        Call    Clrf                    
        mov     I21, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
B0      dd      0                       ; right
I2      dd      45                      ; t0
B1      dd      -1                      ; wrong
I0      dd      0                       ; zero

SECTION .bss                            
I10     resd    a                       ; I10
I11     resd    b                       ; I11
I12     resd    c                       ; I12
I13     resd    T0                      ; I13
I14     resd    d                       ; I14
I15     resd    b                       ; I15
I16     resd    c                       ; I16
I17     resd    T1                      ; I17
I18     resd    d                       ; I18
I19     resd    b                       ; I19
I20     resd    a                       ; I20
I21     resd    d                       ; I21
I7      resd    a                       ; I7
I8      resd    b                       ; I8
I9      resd    c                       ; I9
I3      resd    integer                 ; a
I4      resd    integer                 ; a,b
I5      resd    integer                 ; a,b,c
I6      resd    integer                 ; d
