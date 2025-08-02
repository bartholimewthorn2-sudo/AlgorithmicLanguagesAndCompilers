; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no101

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I5,eax                  ; store eax at I5
        Call    ReadInt                 ; read int; value placed in eax
        mov     I6,eax                  ; store eax at I6
        mov     I7, eax                 
        Call    Clrf                    
        mov     I8, eax                 
        Call    Clrf                    
        mov     eax, I10                
        mov     I9, eax                 
        mov     eax, I12                
        mov     I11, eax                
        mov     I13, eax                
        Call    Clrf                    
        mov     I14, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
I0      dd      0                       ; zero

SECTION .bss                            
I10     resd    34                      ; I10
I11     resd    b                       ; I11
I12     resd    a                       ; I12
I13     resd    five                    ; I13
I14     resd    a,b,c,five,zero         ; I14
I5      resd    a                       ; I5
I6      resd    b,c                     ; I6
I7      resd    a                       ; I7
I8      resd    b                       ; I8
I9      resd    a                       ; I9
I2      resd    integer                 ; a
I3      resd    integer                 ; b
I4      resd    integer                 ; c
