.pos 0x1000
offsettest: ld $0x4000, r0
            j *12(r0)      #jump to offsetpass

.pos 0x2000
offsetpass: ld $1, r6       #set r6 = 1
            ld $0x4000, r0
            ld $4, r1       # r1 = (&b - 4000) / 4
            j *(r0,r1,4)    #jump to indexpass
            
.pos 0x3000
indexpass:  ld $1, r7       #set r7 = 1
            halt

.pos 0x400a
a:          .long 0x2000
b:          .long 0x3000
# j *o(rt) dtpp pc ← m[r[t] + (o == pp*4)]
# j *(rb,ri,4) ebi- pc ← m[r[b] + r[i]*4]
