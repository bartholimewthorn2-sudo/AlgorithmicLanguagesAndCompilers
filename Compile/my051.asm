; LOUIS JENSEN       Thu Nov 21 21:41:48 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage0no051

_start:                                 
        Exit    {0}                     

SECTION .data                           
I2      dd      1                       ; big
I3      dd      +2336                   ; biggeryet
I9      dd      false                   ; fal_se
I4      dd      +2336                   ; large
B2      dd      0                       ; maybe
I6      dd      -1234                   ; minus
B1      dd      0                       ; no
I8      dd      false                   ; off
I7      dd      true                    ; on
B3      dd      -1                      ; possible
I0      dd      0                       ; small
I1      dd      -1234                   ; smalleryet
I10     dd      true                    ; tru_e
B0      dd      -1                      ; yes
I5      dd      0                       ; zero

SECTION .bss                            
I12     resd    1                       ; many
B4      resd    1                       ; right
I11     resd    1                       ; some
B5      resd    1                       ; wrong
