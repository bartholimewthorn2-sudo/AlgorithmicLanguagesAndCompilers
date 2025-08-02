; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no141

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I1,eax                  ; store eax at I1
        Call    ReadInt                 ; read int; value placed in eax
        mov     I2,eax                  ; store eax at I2
        Call    ReadInt                 ; read int; value placed in eax
        mov     I3,eax                  ; store eax at I3
        mov     eax, I5                 
        mov     I4, eax                 
        mov     I6, eax                 
        Call    Clrf                    
        mov     I7, eax                 
        Call    Clrf                    
        mov     I8, eax                 
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I1      resd    aaaaaaaaaaaaaaa         ; I1
I2      resd    aaaaaaaaaaaaaaab        ; I2
I3      resd    aaaaaaaaaaaaaaac        ; I3
I4      resd    aaaaaaaaaaaaaaa         ; I4
I5      resd    aaaaaaaaaaaaaaac        ; I5
I6      resd    aaaaaaaaaaaaaaa         ; I6
I7      resd    aaaaaaaaaaaaaaab        ; I7
I8      resd    aaaaaaaaaaaaaaac        ; I8
I0      resd    integer                 ; aaaaaaaaaaaaaaa
