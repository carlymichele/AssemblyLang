# Programming Assignment 6

#### For this programming assignment you should ONLY use the mov (regular/standard move) instruction.
    The .data segment should NOT be modified.

### PHASE 1:
    Move the message that is being stored across the six registers in forward order to the msgforward word array. This means after phase 1 is completed, the msgforward array should be storing “Welcome Home”.
Phase 1 is approximately six (6) instructions

### PHASE 2:
    Reverse the ordering of each of the two letters in each of the six registers. For example, initially register ax is storing “EM”, where the “E” (45h) is in ah and the “M” (4D) is in al. Your goal is to reverse the order, so that the “M” (4D) is in ah and the “E” (45h) is in al. The same needs to be done for the other five registers as well.
    NOTE: Registers cx and dx are unused and are available to help with the swapping.
Phase 2 is approximately twenty-two (22) instructions

### PHASE 3:
    Move the message that is being stored across the six registers in backward order to the msgbackward word array. This means after phase 1 is completed, the msgbackward array should be storing “EMOH EMOCLEW” (WELCOME HOME backwards)
Phase 3 is approximately six (6) instructions
