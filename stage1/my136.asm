; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no136

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I2,eax                  ; store eax at I2
        mov     I3, eax                 
        Call    Clrf                    
        mov     eax, I5                 
        mov     I4, eax                 
        mov     eax, I9                 
        mov     I8, eax                 
        mov     I10, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I10     resd    a,b                     ; I10
I2      resd    a,b                     ; I2
I3      resd    a,b                     ; I3
I4      resd    a                       ; I4
I5      resd    b                       ; I5
I6      resd    b                       ; I6
I7      resd    b                       ; I7
I8      resd    a                       ; I8
I9      resd    b                       ; I9
I0      resd    integer                 ; a
I1      resd    integer                 ; b
