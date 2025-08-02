; LOUIS JENSEN       Sun Dec  8 23:54:42 2024
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text                           
global  _start                          ; program stage1no152

_start:                                 
        Call    ReadInt                 ; read int; value placed in eax
        mov     I23,eax                 ; store eax at I23
        mov     eax, I26                
        add     eax, I26                
        mov     T0, eax                 
        mov     eax, I29                
        add     eax, I29                
        mov     T1, eax                 
        mov     eax, I32                
        add     eax, I32                
        mov     T2, eax                 
        mov     eax, I35                
        add     eax, I35                
        mov     T3, eax                 
        mov     eax, I38                
        add     eax, I38                
        mov     T4, eax                 
        mov     eax, I41                
        add     eax, I41                
        mov     T5, eax                 
        mov     eax, I44                
        add     eax, I44                
        mov     T6, eax                 
        mov     eax, I47                
        add     eax, I47                
        mov     T7, eax                 
        mov     eax, I50                
        add     eax, I50                
        mov     T8, eax                 
        mov     eax, I53                
        add     eax, I53                
        mov     T9, eax                 
        mov     eax, I56                
        add     eax, I56                
        mov     T10, eax                
        mov     eax, I59                
        add     eax, I59                
        mov     T11, eax                
        mov     eax, I62                
        add     eax, I62                
        mov     T12, eax                
        mov     eax, I65                
        add     eax, I65                
        mov     T13, eax                
        mov     eax, I68                
        add     eax, I68                
        mov     T14, eax                
        mov     eax, I71                
        add     eax, I71                
        mov     T15, eax                
        mov     eax, I74                
        add     eax, I74                
        mov     T16, eax                
        mov     eax, I77                
        add     eax, I77                
        mov     T17, eax                
        mov     eax, I80                
        add     eax, I80                
        mov     T18, eax                
        mov     eax, I83                
        add     eax, I83                
        mov     T19, eax                
        mov     eax, I86                
        add     eax, I86                
        mov     T20, eax                
        mov     eax, I89                
        add     eax, I89                
        mov     T21, eax                
        mov     eax, I92                
        add     eax, I92                
        mov     T22, eax                
        mov     eax, I95                
        add     eax, I95                
        mov     T23, eax                
        mov     eax, I98                
        add     eax, I98                
        mov     T24, eax                
        mov     eax, I101               
        add     eax, I101               
        mov     T25, eax                
        mov     eax, I104               
        add     eax, I104               
        mov     T26, eax                
        mov     eax, I107               
        add     eax, I107               
        mov     T27, eax                
        mov     eax, I110               
        add     eax, I110               
        mov     T28, eax                
        mov     eax, I113               
        add     eax, I113               
        mov     T29, eax                
        mov     eax, I116               
        add     eax, I116               
        mov     T30, eax                
        mov     eax, I119               
        add     eax, I119               
        mov     T31, eax                
        mov     eax, I122               
        add     eax, I122               
        mov     T32, eax                
        mov     eax, I125               
        add     eax, I125               
        mov     T33, eax                
        mov     eax, I128               
        add     eax, I128               
        mov     T34, eax                
        mov     eax, I131               
        add     eax, I131               
        mov     T35, eax                
        mov     eax, I134               
        add     eax, I134               
        mov     T36, eax                
        mov     eax, I137               
        add     eax, I137               
        mov     T37, eax                
        mov     eax, I140               
        add     eax, I140               
        mov     T38, eax                
        mov     eax, I143               
        add     eax, I143               
        mov     T39, eax                
        mov     eax, I146               
        add     eax, I146               
        mov     T40, eax                
        mov     eax, I149               
        add     eax, I149               
        mov     T41, eax                
        mov     eax, I152               
        add     eax, I152               
        mov     T42, eax                
        mov     eax, I155               
        add     eax, I155               
        mov     T43, eax                
        mov     eax, I158               
        add     eax, I158               
        mov     T44, eax                
        mov     eax, I161               
        add     eax, I161               
        mov     T45, eax                
        mov     eax, I164               
        add     eax, I164               
        mov     T46, eax                
        mov     eax, I167               
        add     eax, I167               
        mov     T47, eax                
        mov     eax, I170               
        add     eax, I170               
        mov     T48, eax                
        mov     eax, I173               
        add     eax, I173               
        mov     T49, eax                
        mov     eax, I176               
        add     eax, I176               
        mov     T50, eax                
        mov     eax, I179               
        add     eax, I179               
        mov     T51, eax                
        mov     eax, I182               
        add     eax, I182               
        mov     T52, eax                
        mov     eax, I185               
        add     eax, I185               
        mov     T53, eax                
        mov     eax, I188               
        add     eax, I188               
        mov     T54, eax                
        mov     eax, I191               
        add     eax, I191               
        mov     T55, eax                
        mov     eax, I194               
        add     eax, I194               
        mov     T56, eax                
        mov     eax, I197               
        add     eax, I197               
        mov     T57, eax                
        mov     eax, I200               
        add     eax, I200               
        mov     T58, eax                
        mov     eax, I203               
        add     eax, I203               
        mov     T59, eax                
        mov     eax, I206               
        add     eax, I206               
        mov     T60, eax                
        mov     eax, I209               
        add     eax, I209               
        mov     T61, eax                
        mov     eax, I212               
        add     eax, I212               
        mov     T62, eax                
        mov     eax, I215               
        add     eax, I215               
        mov     T63, eax                
        mov     eax, I218               
        add     eax, I218               
        mov     T64, eax                
        mov     eax, I221               
        add     eax, I221               
        mov     T65, eax                
        mov     eax, I224               
        add     eax, I224               
        mov     T66, eax                
        mov     eax, I227               
        add     eax, I227               
        mov     T67, eax                
        mov     eax, I230               
        add     eax, I230               
        mov     T68, eax                
        mov     eax, I233               
        add     eax, I233               
        mov     T69, eax                
        mov     eax, I236               
        add     eax, I236               
        mov     T70, eax                
        mov     eax, I239               
        add     eax, I239               
        mov     T71, eax                
        mov     eax, I242               
        add     eax, I242               
        mov     T72, eax                
        mov     eax, I245               
        add     eax, I245               
        mov     T73, eax                
        mov     eax, I248               
        add     eax, I248               
        mov     T74, eax                
        mov     eax, I251               
        add     eax, I251               
        mov     T75, eax                
        mov     eax, I254               
        add     eax, I254               
        mov     T76, eax                
        mov     eax, I257               
        add     eax, I257               
        mov     T77, eax                
        mov     eax, I260               
        add     eax, I260               
        mov     T78, eax                
        mov     eax, I263               
        add     eax, I263               
        mov     T79, eax                
        mov     eax, I266               
        add     eax, I266               
        mov     T80, eax                
        mov     eax, I269               
        add     eax, I269               
        mov     T81, eax                
        mov     eax, I272               
        add     eax, I272               
        mov     T82, eax                
        mov     eax, I275               
        add     eax, I275               
        mov     T83, eax                
        mov     eax, I278               
        add     eax, I278               
        mov     T84, eax                
        mov     eax, I281               
        add     eax, I281               
        mov     T85, eax                
        mov     eax, I284               
        add     eax, I284               
        mov     T86, eax                
        mov     eax, I287               
        add     eax, I287               
        mov     T87, eax                
        mov     eax, I290               
        add     eax, I290               
        mov     T88, eax                
        mov     eax, I293               
        add     eax, I293               
        mov     T89, eax                
        mov     eax, I296               
        add     eax, I296               
        mov     T90, eax                
        mov     eax, I299               
        add     eax, I299               
        mov     T91, eax                
        mov     eax, I302               
        add     eax, I302               
        mov     T92, eax                
        mov     eax, I305               
        add     eax, I305               
        mov     T93, eax                
        mov     eax, I308               
        add     eax, I308               
        mov     T94, eax                
        mov     eax, I311               
        add     eax, I311               
        mov     T95, eax                
        mov     eax, I314               
        add     eax, I314               
        mov     T96, eax                
        mov     eax, I317               
        add     eax, I317               
        mov     T97, eax                
        mov     eax, I320               
        add     eax, I320               
        mov     T98, eax                
        mov     eax, I323               
        add     eax, I323               
        mov     eax, I326               
        mov     I325, eax               
        mov     I327, eax               
        Call    Clrf                    
        Exit    {0}                     

SECTION .data                           

SECTION .bss                            
I100    resd    T24                     ; I100
I101    resd    m                       ; I101
I102    resd    n                       ; I102
I103    resd    T25                     ; I103
I104    resd    o                       ; I104
I105    resd    p                       ; I105
I106    resd    T26                     ; I106
I107    resd    q                       ; I107
I108    resd    r                       ; I108
I109    resd    T27                     ; I109
I110    resd    s                       ; I110
I111    resd    t                       ; I111
I112    resd    T28                     ; I112
I113    resd    u                       ; I113
I114    resd    v                       ; I114
I115    resd    T29                     ; I115
I116    resd    c                       ; I116
I117    resd    d                       ; I117
I118    resd    T30                     ; I118
I119    resd    e                       ; I119
I120    resd    f                       ; I120
I121    resd    T31                     ; I121
I122    resd    g                       ; I122
I123    resd    h                       ; I123
I124    resd    T32                     ; I124
I125    resd    i                       ; I125
I126    resd    j                       ; I126
I127    resd    T33                     ; I127
I128    resd    k                       ; I128
I129    resd    l                       ; I129
I130    resd    T34                     ; I130
I131    resd    m                       ; I131
I132    resd    n                       ; I132
I133    resd    T35                     ; I133
I134    resd    o                       ; I134
I135    resd    p                       ; I135
I136    resd    T36                     ; I136
I137    resd    q                       ; I137
I138    resd    r                       ; I138
I139    resd    T37                     ; I139
I140    resd    s                       ; I140
I141    resd    t                       ; I141
I142    resd    T38                     ; I142
I143    resd    u                       ; I143
I144    resd    v                       ; I144
I145    resd    T39                     ; I145
I146    resd    c                       ; I146
I147    resd    d                       ; I147
I148    resd    T40                     ; I148
I149    resd    e                       ; I149
I150    resd    f                       ; I150
I151    resd    T41                     ; I151
I152    resd    g                       ; I152
I153    resd    h                       ; I153
I154    resd    T42                     ; I154
I155    resd    i                       ; I155
I156    resd    j                       ; I156
I157    resd    T43                     ; I157
I158    resd    k                       ; I158
I159    resd    l                       ; I159
I160    resd    T44                     ; I160
I161    resd    m                       ; I161
I162    resd    n                       ; I162
I163    resd    T45                     ; I163
I164    resd    o                       ; I164
I165    resd    p                       ; I165
I166    resd    T46                     ; I166
I167    resd    q                       ; I167
I168    resd    r                       ; I168
I169    resd    T47                     ; I169
I170    resd    s                       ; I170
I171    resd    t                       ; I171
I172    resd    T48                     ; I172
I173    resd    u                       ; I173
I174    resd    v                       ; I174
I175    resd    T49                     ; I175
I176    resd    c                       ; I176
I177    resd    d                       ; I177
I178    resd    T50                     ; I178
I179    resd    e                       ; I179
I180    resd    f                       ; I180
I181    resd    T51                     ; I181
I182    resd    g                       ; I182
I183    resd    h                       ; I183
I184    resd    T52                     ; I184
I185    resd    i                       ; I185
I186    resd    j                       ; I186
I187    resd    T53                     ; I187
I188    resd    k                       ; I188
I189    resd    l                       ; I189
I190    resd    T54                     ; I190
I191    resd    m                       ; I191
I192    resd    n                       ; I192
I193    resd    T55                     ; I193
I194    resd    o                       ; I194
I195    resd    p                       ; I195
I196    resd    T56                     ; I196
I197    resd    q                       ; I197
I198    resd    r                       ; I198
I199    resd    T57                     ; I199
I200    resd    s                       ; I200
I201    resd    t                       ; I201
I202    resd    T58                     ; I202
I203    resd    u                       ; I203
I204    resd    v                       ; I204
I205    resd    T59                     ; I205
I206    resd    c                       ; I206
I207    resd    d                       ; I207
I208    resd    T60                     ; I208
I209    resd    e                       ; I209
I210    resd    f                       ; I210
I211    resd    T61                     ; I211
I212    resd    g                       ; I212
I213    resd    h                       ; I213
I214    resd    T62                     ; I214
I215    resd    i                       ; I215
I216    resd    j                       ; I216
I217    resd    T63                     ; I217
I218    resd    k                       ; I218
I219    resd    l                       ; I219
I220    resd    T64                     ; I220
I221    resd    m                       ; I221
I222    resd    n                       ; I222
I223    resd    T65                     ; I223
I224    resd    o                       ; I224
I225    resd    p                       ; I225
I226    resd    T66                     ; I226
I227    resd    q                       ; I227
I228    resd    r                       ; I228
I229    resd    T67                     ; I229
I23     resd    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v; I23
I230    resd    s                       ; I230
I231    resd    t                       ; I231
I232    resd    T68                     ; I232
I233    resd    u                       ; I233
I234    resd    v                       ; I234
I235    resd    T69                     ; I235
I236    resd    c                       ; I236
I237    resd    d                       ; I237
I238    resd    T70                     ; I238
I239    resd    e                       ; I239
I24     resd    sum                     ; I24
I240    resd    f                       ; I240
I241    resd    T71                     ; I241
I242    resd    g                       ; I242
I243    resd    h                       ; I243
I244    resd    T72                     ; I244
I245    resd    i                       ; I245
I246    resd    j                       ; I246
I247    resd    T73                     ; I247
I248    resd    k                       ; I248
I249    resd    l                       ; I249
I25     resd    b                       ; I25
I250    resd    T74                     ; I250
I251    resd    m                       ; I251
I252    resd    n                       ; I252
I253    resd    T75                     ; I253
I254    resd    o                       ; I254
I255    resd    p                       ; I255
I256    resd    T76                     ; I256
I257    resd    q                       ; I257
I258    resd    r                       ; I258
I259    resd    T77                     ; I259
I26     resd    c                       ; I26
I260    resd    s                       ; I260
I261    resd    t                       ; I261
I262    resd    T78                     ; I262
I263    resd    u                       ; I263
I264    resd    v                       ; I264
I265    resd    T79                     ; I265
I266    resd    c                       ; I266
I267    resd    d                       ; I267
I268    resd    T80                     ; I268
I269    resd    e                       ; I269
I27     resd    d                       ; I27
I270    resd    f                       ; I270
I271    resd    T81                     ; I271
I272    resd    g                       ; I272
I273    resd    h                       ; I273
I274    resd    T82                     ; I274
I275    resd    i                       ; I275
I276    resd    j                       ; I276
I277    resd    T83                     ; I277
I278    resd    k                       ; I278
I279    resd    l                       ; I279
I28     resd    T0                      ; I28
I280    resd    T84                     ; I280
I281    resd    m                       ; I281
I282    resd    n                       ; I282
I283    resd    T85                     ; I283
I284    resd    o                       ; I284
I285    resd    p                       ; I285
I286    resd    T86                     ; I286
I287    resd    q                       ; I287
I288    resd    r                       ; I288
I289    resd    T87                     ; I289
I29     resd    e                       ; I29
I290    resd    s                       ; I290
I291    resd    t                       ; I291
I292    resd    T88                     ; I292
I293    resd    u                       ; I293
I294    resd    v                       ; I294
I295    resd    T89                     ; I295
I296    resd    c                       ; I296
I297    resd    d                       ; I297
I298    resd    T90                     ; I298
I299    resd    e                       ; I299
I30     resd    f                       ; I30
I300    resd    f                       ; I300
I301    resd    T91                     ; I301
I302    resd    g                       ; I302
I303    resd    h                       ; I303
I304    resd    T92                     ; I304
I305    resd    i                       ; I305
I306    resd    j                       ; I306
I307    resd    T93                     ; I307
I308    resd    k                       ; I308
I309    resd    l                       ; I309
I31     resd    T1                      ; I31
I310    resd    T94                     ; I310
I311    resd    m                       ; I311
I312    resd    n                       ; I312
I313    resd    T95                     ; I313
I314    resd    o                       ; I314
I315    resd    p                       ; I315
I316    resd    T96                     ; I316
I317    resd    q                       ; I317
I318    resd    r                       ; I318
I319    resd    T97                     ; I319
I32     resd    g                       ; I32
I320    resd    s                       ; I320
I321    resd    t                       ; I321
I322    resd    T98                     ; I322
I323    resd    u                       ; I323
I324    resd    v                       ; I324
I325    resd    T99                     ; I325
I326    resd    b                       ; I326
I327    resd    sum                     ; I327
I33     resd    h                       ; I33
I34     resd    T2                      ; I34
I35     resd    i                       ; I35
I36     resd    j                       ; I36
I37     resd    T3                      ; I37
I38     resd    k                       ; I38
I39     resd    l                       ; I39
I40     resd    T4                      ; I40
I41     resd    m                       ; I41
I42     resd    n                       ; I42
I43     resd    T5                      ; I43
I44     resd    o                       ; I44
I45     resd    p                       ; I45
I46     resd    T6                      ; I46
I47     resd    q                       ; I47
I48     resd    r                       ; I48
I49     resd    T7                      ; I49
I50     resd    s                       ; I50
I51     resd    t                       ; I51
I52     resd    T8                      ; I52
I53     resd    u                       ; I53
I54     resd    v                       ; I54
I55     resd    T9                      ; I55
I56     resd    c                       ; I56
I57     resd    d                       ; I57
I58     resd    T10                     ; I58
I59     resd    e                       ; I59
I60     resd    f                       ; I60
I61     resd    T11                     ; I61
I62     resd    g                       ; I62
I63     resd    h                       ; I63
I64     resd    T12                     ; I64
I65     resd    i                       ; I65
I66     resd    j                       ; I66
I67     resd    T13                     ; I67
I68     resd    k                       ; I68
I69     resd    l                       ; I69
I70     resd    T14                     ; I70
I71     resd    m                       ; I71
I72     resd    n                       ; I72
I73     resd    T15                     ; I73
I74     resd    o                       ; I74
I75     resd    p                       ; I75
I76     resd    T16                     ; I76
I77     resd    q                       ; I77
I78     resd    r                       ; I78
I79     resd    T17                     ; I79
I80     resd    s                       ; I80
I81     resd    t                       ; I81
I82     resd    T18                     ; I82
I83     resd    u                       ; I83
I84     resd    v                       ; I84
I85     resd    T19                     ; I85
I86     resd    c                       ; I86
I87     resd    d                       ; I87
I88     resd    T20                     ; I88
I89     resd    e                       ; I89
I90     resd    f                       ; I90
I91     resd    T21                     ; I91
I92     resd    g                       ; I92
I93     resd    h                       ; I93
I94     resd    T22                     ; I94
I95     resd    i                       ; I95
I96     resd    j                       ; I96
I97     resd    T23                     ; I97
I98     resd    k                       ; I98
I99     resd    l                       ; I99
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
T23     resd                            ; T23
T24     resd                            ; T24
T25     resd                            ; T25
T26     resd                            ; T26
T27     resd                            ; T27
T28     resd                            ; T28
T29     resd                            ; T29
T3      resd                            ; T3
T30     resd                            ; T30
T31     resd                            ; T31
T32     resd                            ; T32
T33     resd                            ; T33
T34     resd                            ; T34
T35     resd                            ; T35
T36     resd                            ; T36
T37     resd                            ; T37
T38     resd                            ; T38
T39     resd                            ; T39
T4      resd                            ; T4
T40     resd                            ; T40
T41     resd                            ; T41
T42     resd                            ; T42
T43     resd                            ; T43
T44     resd                            ; T44
T45     resd                            ; T45
T46     resd                            ; T46
T47     resd                            ; T47
T48     resd                            ; T48
T49     resd                            ; T49
T5      resd                            ; T5
T50     resd                            ; T50
T51     resd                            ; T51
T52     resd                            ; T52
T53     resd                            ; T53
T54     resd                            ; T54
T55     resd                            ; T55
T56     resd                            ; T56
T57     resd                            ; T57
T58     resd                            ; T58
T59     resd                            ; T59
T6      resd                            ; T6
T60     resd                            ; T60
T61     resd                            ; T61
T62     resd                            ; T62
T63     resd                            ; T63
T64     resd                            ; T64
T65     resd                            ; T65
T66     resd                            ; T66
T67     resd                            ; T67
T68     resd                            ; T68
T69     resd                            ; T69
T7      resd                            ; T7
T70     resd                            ; T70
T71     resd                            ; T71
T72     resd                            ; T72
T73     resd                            ; T73
T74     resd                            ; T74
T75     resd                            ; T75
T76     resd                            ; T76
T77     resd                            ; T77
T78     resd                            ; T78
T79     resd                            ; T79
T8      resd                            ; T8
T80     resd                            ; T80
T81     resd                            ; T81
T82     resd                            ; T82
T83     resd                            ; T83
T84     resd                            ; T84
T85     resd                            ; T85
T86     resd                            ; T86
T87     resd                            ; T87
T88     resd                            ; T88
T89     resd                            ; T89
T9      resd                            ; T9
T90     resd                            ; T90
T91     resd                            ; T91
T92     resd                            ; T92
T93     resd                            ; T93
T94     resd                            ; T94
T95     resd                            ; T95
T96     resd                            ; T96
T97     resd                            ; T97
T98     resd                            ; T98
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
I22     resd    integer                 ; v
