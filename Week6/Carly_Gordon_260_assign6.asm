; Program template
;Original Code starts at "PHASE ONE" and ends with "PHASE THREE"
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
    msgforward WORD 6 DUP(?)
    msgbackward WORD 6 DUP(?)
    restore_esp DWORD ?

.code main proc
mov restore_esp, esp ; save the contents of register ESP so it can be restored before the program finishes
    ; DO NOT REMOVE THIS ; clear the registers
    mov eax, 0
    mov ebx, 0
    mov ecx, 0
    mov edx, 0
    mov esi, 0
    mov edi, 0
    mov esp, 0
    mov ebp , 0

; store the message "Welcome Home" in reverse order across the six 16-bit registers
    mov ax, "EM"
    mov bx, "OH"
    mov si, " E"
    mov di, "MO"
    mov sp, "CL"
    mov bp, "EW"

; PHASE ONE
    ;C1: Due to Little Endian Order, the values of the registers are reversed when stored into the array.
    ;C2: Brackets are used to move the contents of the registers into the array.
    mov [msgforward], bp ; C3: This adds each set of chars and increments by two indeces.
    mov [msgforward+2], sp
    mov [msgforward+4], di
    mov [msgforward+6], si
    mov [msgforward+8], bx
    mov [msgforward+10], ax

; PHASE TWO
    mov cx, bp ; C4: Since bp doesn't have 8 bit registers, cx and dx were used to access the top and bottom half of bp.
    mov dh, cl ; C5: Once the values of bp is moved into cx, the top and bottom halves of cx are stored in the bottom and top halves of dx.
    mov dl, ch
    mov bp, dx ; C6: 8 bit registers can't moved into 16 bit registers directly, so the values are stored as dh and dl, then moved into bp as dx.

    mov cx, sp ; C7: The same is done for sp, di, and si.
    mov dh, cl
    mov dl, ch
    mov sp, dx

    mov cx, di
    mov dh, cl
    mov dl, ch
    mov di, dx

    mov cx, si
    mov dh, cl
    mov dl, ch
    mov si, dx

    mov cl, bh ; C8: Since bx and ax have 8 bit registers, only one 8 bit register is needed for swapping.
    mov bh, bl ; C9: After the top half value is stored, the top half can be replaced by the bottom half.
    mov bl, cl ; C10: Then the original top value is stored in the bottom half.

    mov dl, ah
    mov ah, al
    mov al, dl
; PHASE THREE
    ; C11: Since the values for all the registers have been switched to forward, the new message will appear backward in memory after all the values have been moved.
    mov [msgbackward], ax ; C12: Like above, this block adds each set of chars and increments by two indeces
    mov [msgbackward+2], bx
    mov [msgbackward+4], si
    mov [msgbackward+6], di
    mov [msgbackward+8], sp
    mov [msgbackward+10], bp

mov esp, restore_esp ; restore register ESP to it's original value so the program can end correctly ; DO NOT REMOVE THIS
invoke ExitProcess,0 main endp
end main
