; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no124

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I15,eax                 ; store eax at I15
        mov     eax, I16                
        neg     eax                     
        mov     eax, I17                
        neg     eax                     
        mov     eax, I18                
        neg     eax                     
        mov     eax, I19                
        neg     eax                     
        mov     eax, I20                
        neg     eax                     
        mov     eax, I21                
        neg     eax                     
        mov     eax, I22                
        neg     eax                     
        mov     eax, I23                
        neg     eax                     
