; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no139

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I7,eax                  ; store eax at I7
        mov     eax, I9                 
        imul    eax, I9                 
        mov     T0, eax                 
        mov     eax, I11                
        cdq                             
        idiv    dword I11               
        mov     T1, eax                 
        mov     eax, I13                
        sub     eax, I13                
        mov     T2, eax                 
        mov     eax, I15                
        add     eax, I15                
        mov     I8, eax                 
        mov     I18, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I10     resd    c                       ; I10
I11     resd    T0                      ; I11
I12     resd    d                       ; I12
I13     resd    T1                      ; I13
I14     resd    e                       ; I14
I15     resd    T2                      ; I15
I16     resd    f                       ; I16
I17     resd    T3                      ; I17
I18     resd    a,b,c,d,e,f,g           ; I18
I7      resd    a,b,c,d,e,f             ; I7
I8      resd    g                       ; I8
I9      resd    b                       ; I9
T0      resd                            ; T0
T1      resd                            ; T1
T2      resd                            ; T2
I0      resd    integer                 ; a
I1      resd    integer                 ; a,b
I2      resd    integer                 ; a,b,c
I3      resd    integer                 ; a,b,c,d
I4      resd    integer                 ; a,b,c,d,e
I5      resd    integer                 ; a,b,c,d,e,f
I6      resd    integer                 ; g
