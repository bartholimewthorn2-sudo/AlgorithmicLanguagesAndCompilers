; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no122

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I27,eax                 ; store eax at I27
        mov     eax, I30                
        add     eax, I30                
        mov     T0, eax                 
        mov     eax, I33                
        add     eax, I33                
        mov     T1, eax                 
        mov     eax, I36                
        add     eax, I36                
        mov     T2, eax                 
        mov     eax, I39                
        add     eax, I39                
        mov     T3, eax                 
        mov     eax, I42                
        add     eax, I42                
        mov     T4, eax                 
        mov     eax, I45                
        add     eax, I45                
        mov     T5, eax                 
        mov     eax, I48                
        add     eax, I48                
        mov     T6, eax                 
        mov     eax, I51                
        add     eax, I51                
        mov     T7, eax                 
        mov     eax, I54                
        add     eax, I54                
        mov     T8, eax                 
        mov     eax, I57                
        add     eax, I57                
        mov     T9, eax                 
        mov     eax, I60                
        add     eax, I60                
        mov     eax, I63                
        mov     I62, eax                
        mov     I64, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I27     resd    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; I27
I28     resd    sum                     ; I28
I29     resd    b                       ; I29
I30     resd    c                       ; I30
I31     resd    d                       ; I31
I32     resd    T0                      ; I32
I33     resd    e                       ; I33
I34     resd    f                       ; I34
I35     resd    T1                      ; I35
I36     resd    g                       ; I36
I37     resd    h                       ; I37
I38     resd    T2                      ; I38
I39     resd    i                       ; I39
I40     resd    j                       ; I40
I41     resd    T3                      ; I41
I42     resd    k                       ; I42
I43     resd    l                       ; I43
I44     resd    T4                      ; I44
I45     resd    m                       ; I45
I46     resd    n                       ; I46
I47     resd    T5                      ; I47
I48     resd    o                       ; I48
I49     resd    p                       ; I49
I50     resd    T6                      ; I50
I51     resd    q                       ; I51
I52     resd    r                       ; I52
I53     resd    T7                      ; I53
I54     resd    s                       ; I54
I55     resd    t                       ; I55
I56     resd    T8                      ; I56
I57     resd    u                       ; I57
I58     resd    v                       ; I58
I59     resd    T9                      ; I59
I60     resd    w                       ; I60
I61     resd    x                       ; I61
I62     resd    T10                     ; I62
I63     resd    z                       ; I63
I64     resd    sum                     ; I64
T0      resd                            ; T0
T1      resd                            ; T1
T2      resd                            ; T2
T3      resd                            ; T3
T4      resd                            ; T4
T5      resd                            ; T5
T6      resd                            ; T6
T7      resd                            ; T7
T8      resd                            ; T8
T9      resd                            ; T9
I0      resd    integer                 ; sum
I1      resd    integer                 ; sum,a
I2      resd    integer                 ; sum,a,b
I3      resd    integer                 ; sum,a,b,c
I4      resd    integer                 ; sum,a,b,c,d
I5      resd    integer                 ; sum,a,b,c,d,e
I6      resd    integer                 ; sum,a,b,c,d,e,f
I7      resd    integer                 ; sum,a,b,c,d,e,f
I8      resd    integer                 ; sum,a,b,c,d,e,f
I9      resd    integer                 ; sum,a,b,c,d,e,f
I10     resd    integer                 ; sum,a,b,c,d,e,f
I11     resd    integer                 ; sum,a,b,c,d,e,f
I12     resd    integer                 ; sum,a,b,c,d,e,f
I13     resd    integer                 ; sum,a,b,c,d,e,f
I14     resd    integer                 ; sum,a,b,c,d,e,f
I15     resd    integer                 ; sum,a,b,c,d,e,f
I16     resd    integer                 ; sum,a,b,c,d,e,f
I17     resd    integer                 ; sum,a,b,c,d,e,f
I18     resd    integer                 ; sum,a,b,c,d,e,f
I19     resd    integer                 ; sum,a,b,c,d,e,f
I20     resd    integer                 ; sum,a,b,c,d,e,f
I21     resd    integer                 ; sum,a,b,c,d,e,f
I22     resd    integer                 ; sum,a,b,c,d,e,f
I23     resd    integer                 ; sum,a,b,c,d,e,f
I24     resd    integer                 ; sum,a,b,c,d,e,f
I25     resd    integer                 ; sum,a,b,c,d,e,f
I26     resd    integer                 ; z
