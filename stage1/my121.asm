; LOUIS JENSEN       Sun Dec  8 23:54:41 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no121

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I27,eax                 ; store eax at I27
        mov     eax, I29                
        add     eax, I29                
        mov     T0, eax                 
        mov     eax, I31                
        add     eax, I31                
        mov     T1, eax                 
        mov     eax, I33                
        add     eax, I33                
        mov     T2, eax                 
        mov     eax, I35                
        add     eax, I35                
        mov     T3, eax                 
        mov     eax, I37                
        add     eax, I37                
        mov     T4, eax                 
        mov     eax, I39                
        add     eax, I39                
        mov     T5, eax                 
        mov     eax, I41                
        add     eax, I41                
        mov     T6, eax                 
        mov     eax, I43                
        add     eax, I43                
        mov     T7, eax                 
        mov     eax, I45                
        add     eax, I45                
        mov     T8, eax                 
        mov     eax, I47                
        add     eax, I47                
        mov     T9, eax                 
        mov     eax, I49                
        add     eax, I49                
        mov     T10, eax                
        mov     eax, I51                
        add     eax, I51                
        mov     T11, eax                
        mov     eax, I53                
        add     eax, I53                
        mov     T12, eax                
        mov     eax, I55                
        add     eax, I55                
        mov     T13, eax                
        mov     eax, I57                
        add     eax, I57                
        mov     T14, eax                
        mov     eax, I59                
        add     eax, I59                
        mov     T15, eax                
        mov     eax, I61                
        add     eax, I61                
        mov     T16, eax                
        mov     eax, I63                
        add     eax, I63                
        mov     T17, eax                
        mov     eax, I65                
        add     eax, I65                
        mov     T18, eax                
        mov     eax, I67                
        add     eax, I67                
        mov     T19, eax                
        mov     eax, I69                
        add     eax, I69                
        mov     T20, eax                
        mov     eax, I71                
        add     eax, I71                
        mov     T21, eax                
        mov     eax, I73                
        add     eax, I73                
        mov     T22, eax                
        mov     eax, I75                
        add     eax, I75                
        mov     I28, eax                
        mov     I78, eax                
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I27     resd    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; I27
I28     resd    sum                     ; I28
I29     resd    b                       ; I29
I30     resd    c                       ; I30
I31     resd    T0                      ; I31
I32     resd    d                       ; I32
I33     resd    T1                      ; I33
I34     resd    e                       ; I34
I35     resd    T2                      ; I35
I36     resd    f                       ; I36
I37     resd    T3                      ; I37
I38     resd    g                       ; I38
I39     resd    T4                      ; I39
I40     resd    h                       ; I40
I41     resd    T5                      ; I41
I42     resd    i                       ; I42
I43     resd    T6                      ; I43
I44     resd    j                       ; I44
I45     resd    T7                      ; I45
I46     resd    k                       ; I46
I47     resd    T8                      ; I47
I48     resd    l                       ; I48
I49     resd    T9                      ; I49
I50     resd    m                       ; I50
I51     resd    T10                     ; I51
I52     resd    n                       ; I52
I53     resd    T11                     ; I53
I54     resd    o                       ; I54
I55     resd    T12                     ; I55
I56     resd    p                       ; I56
I57     resd    T13                     ; I57
I58     resd    q                       ; I58
I59     resd    T14                     ; I59
I60     resd    r                       ; I60
I61     resd    T15                     ; I61
I62     resd    s                       ; I62
I63     resd    T16                     ; I63
I64     resd    t                       ; I64
I65     resd    T17                     ; I65
I66     resd    u                       ; I66
I67     resd    T18                     ; I67
I68     resd    v                       ; I68
I69     resd    T19                     ; I69
I70     resd    w                       ; I70
I71     resd    T20                     ; I71
I72     resd    x                       ; I72
I73     resd    T21                     ; I73
I74     resd    y                       ; I74
I75     resd    T22                     ; I75
I76     resd    z                       ; I76
I77     resd    T23                     ; I77
I78     resd    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum; I78
T0      resd                            ; T0
T1      resd                            ; T1
T10     resd                            ; T10
T11     resd                            ; T11
T12     resd                            ; T12
T13     resd                            ; T13
T14     resd                            ; T14
T15     resd                            ; T15
T16     resd                            ; T16
T17     resd                            ; T17
T18     resd                            ; T18
T19     resd                            ; T19
T2      resd                            ; T2
T20     resd                            ; T20
T21     resd                            ; T21
T22     resd                            ; T22
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
