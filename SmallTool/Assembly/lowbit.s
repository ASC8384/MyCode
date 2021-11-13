.code
; Count the number of 1's in the binary form of an integer using lowbit.
tmd:
        daddi   R4,R0,0
        ; daddi   R3,R0,233
        ; j L2
init:
        lui     R5,1
        ori     R6,R5,8
        daddi   R3,R0,8
        sd      R3,0(R5)
        ld      R3,0(R6)
L2:
        daddui  R2,R3,-1
        and     R3,R2,R3
        daddi   R4,R4,1
        nop
        ori     R1,R0,1
        sd      R3,(R6)
        sd      R1,(R5)
        nop
        bne     R3,R0,L2
end:
        ori     R1,R0,1
        sd      R4,(R6)
        sd      R1,(R5)
        halt
        nop