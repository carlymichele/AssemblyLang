# Programming Assignment 5

#### For this programming assignment you should ONLY use these instructions:
    1) mov (regular/standard move)
    2) add
    3) sub
    * Note that operands for instructions should be registers or memory locations.
    An exception is that you can use the immediate values 0, 1, -1, 0Fh, or 0FFh where it would make sense.
    The .data segment should NOT be modified.


### PHASE 1:
For phase 1 of the program, you need to SHIFT the contents of the four memory locations such that:
    * var1 will be storing ‘D’ (44h)
    * var2 will be storing ‘A’ (41h)
    * var3 will be storing ‘B’ (42h)
    * var4 will be storing ‘C’ (43h).
Phase 1 is approximately nine (9) instructions

### PHASE 2:
For phase 2, you need store the contents of var1, var2, var3, and var4 altogether in register eax such that:
    * var1 will be stored in the highest byte of eax
    * var2 will be stored in the second highest byte
    * var3 will be stored in the second lowest byte
    * var4 will be stored in the lowest byte.
    * NOTE: You cannot directly refer to the highest 16 bits of eax, but you can refer to the lowest 16 bits with register ax, and the second lowest byte (8 bits) with register ah, and the lowest byte with register al.
Phase 2 is approximately twenty-one (21) instructions

### PHASE 3:
For phase 3 you need to store the two’s complement of var1, var2, var3, and
var4 in register ebx. The two’s complement of:
    * var1 is in the highest byte of ebx,
    * var2 is the next byte
    * var3 is in the next byte
    * var4 is in the lowest byte.
Phase 3 is approximately twenty-one (21) instructions
