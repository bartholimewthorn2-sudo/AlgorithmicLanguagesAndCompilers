; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no138

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I4,eax                  ; store eax at I4
        mov     eax, I6                 
        cdq                             
        idiv    dword I6                
        mov     eax, I8                 
        imul    eax, I8                 
        mov     I5, eax                 
        mov     eax, I12                
        mov     I11, eax                
        mov     eax, I14                
        mov     I13, eax                
        mov     I15, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I10     resd    T1                      ; I10
I11     resd    d                       ; I11
I12     resd    b                       ; I12
I13     resd    e                       ; I13
I14     resd    d                       ; I14
I15     resd    a,b,c,d,e               ; I15
I4      resd    a,b                     ; I4
I5      resd    c                       ; I5
I6      resd    a                       ; I6
I7      resd    b                       ; I7
I8      resd    T0                      ; I8
I9      resd    b                       ; I9
I0      resd    integer                 ; a
I1      resd    integer                 ; a,b
I2      resd    integer                 ; a,b,c
I3      resd    integer                 ; d
B0      resd    boolean                 ; e
