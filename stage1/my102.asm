; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no102

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        Call    ReadInt                 ; read int; value placed in eax
        mov     I8,eax                  ; store eax at I8
        mov     eax, I10                
        cdq                             
        idiv    dword I10               
        xchg    eax, edx                
        mov     I9, eax                 
        mov     I13, eax                
        Call    Clrf                    
        mov     eax, I15                
        neg     eax                     
        mov     I14, eax                
        mov     I17, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           
I1      dd      5                       ; five
I0      dd      0                       ; zero

SECTION .bss                            
I10     resd    5                       ; I10
I11     resd    a                       ; I11
I12     resd    T0                      ; I12
I13     resd    z                       ; I13
I14     resd    c                       ; I14
I15     resd    z                       ; I15
I16     resd    T1                      ; I16
I17     resd    c                       ; I17
I7      resd    a                       ; I7
I8      resd    b                       ; I8
I9      resd    z                       ; I9
I2      resd    integer                 ; a
I3      resd    integer                 ; a,b
I4      resd    integer                 ; c
I5      resd    integer                 ; w
I6      resd    integer                 ; z
