; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no146

_start:                                 
        mov     eax, I5                 
        mov     I4, eax                 
        mov     eax, I7                 
        cdq                             
        idiv    dword I7                
        xchg    eax, edx                
        mov     I6, eax                 
        mov     eax, I11                
        neg     eax                     
        mov     I10, eax                
        mov     I13, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I0      dd      5                       ; five

SECTION .bss                            
I10     resd    c                       ; I10
I11     resd    b                       ; I11
I12     resd    T1                      ; I12
I13     resd    a,b,c                   ; I13
I4      resd    a                       ; I4
I5      resd    34                      ; I5
I6      resd    b                       ; I6
I7      resd    5                       ; I7
I8      resd    a                       ; I8
I9      resd    T0                      ; I9
I1      resd    integer                 ; a
I2      resd    integer                 ; a,b
I3      resd    integer                 ; c
