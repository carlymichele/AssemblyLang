.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	var1 BYTE 'A'
	var2 BYTE 'B'
	var3 BYTE 'C'
	var4 BYTE 'D'

.code
main proc
	; C = "Comment 1"

	; PHASE ONE
	mov eax, 0 ; Clears the register

	;C1 Step One: Store and reassign var1
	mov ah, var4 ; assigns upper byte of ax to var4
	mov al, var1 ; assigns lowest byte of ax to var1
	mov var1, ah ; reassigns var1 to var4 value

	;C2 Step Two: Store and reassign var2
	mov ah, var2 ; reassigns byte value from var4 to var2
	mov var2, al ; reassigns var2 to var1 value

	;C3 Step Three: Store and reassign var3
	mov al, var3
	mov var3, ah ; reassigns var3 to var2 value

	;C4 Step Four: Store and reassign var4
	mov var4, al ; reassigns var 4 to var3 value from lowest byte in ax


	; PHASE TWO
	;C5 Step One: Assign var1 and var2 to the lower register of eax
	mov ah, var1 ; assigns upper byte of ax to var1
	mov al, var2 ; assigns lowest byte of ax to var2

	;C6 Step Two: Shift values into the upper register of eax.
	; The next 16 lines add eax to itself 16 times in order to shift the values.
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax
	add eax, eax

	;C7 Step Three: After shifting everything left, assign var3 and var4 to the lower register of eax
	mov ah, var3 ; assigns upper byte of ax to var3
	mov al, var4 ; assigns lowest byte of ax to var4


	;C8 PHASE THREE
	mov ebx, 0 ; Clears the register

	;C9 Step One: Get and store the two's complement of var1 and var2 into ebx
	mov ah, 0ffh
	sub ah, var1
	add ah, 1
	mov bh, ah

	mov al, 0ffh
	sub al, var2
	add al, 1
	mov bl, al

	;C10 Step Two: Shift values into the upper register of ebx.
	; The next 16 lines add ebx to itself 16 times in order to shift the values.
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx
	mov ebx, ebx

	;C11 Step Three: After shifting everything left, assign var3 and var4 to the lower register of ebx
	mov ah, 0ffh
	sub ah, var3
	add ah, 1
	mov bh, ah

	mov al, 0ffh
	sub al, var4
	add al, 1
	mov bl, al

	invoke ExitProcess,0
main endp
end main
