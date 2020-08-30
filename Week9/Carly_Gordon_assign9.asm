; Exercise 5: Caclulate the first seven Fibonacci numbers.

;.386
;.model flat,stdcall
;.stack 4096
;ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc


; change NUM to the value that you want to run the program with 
NUM = 12

.data
quadArray DWORD NUM DUP(0)

.code
main proc
	
	mov esi, OFFSET quadArray
	
	mov eax, 1	; The base cases (first four 1's) are assigned HERE
	mov [esi], eax
	add esi, TYPE quadArray
	mov [esi], eax
	add esi, TYPE quadArray
	mov [esi], eax
	add esi, TYPE quadArray
	mov [esi], eax
	add esi, TYPE quadArray
	
	mov edi, OFFSET quadArray

	mov ecx, NUM ; The counter value for the loop is set HERE
	sub ecx, 4
	L1:
		mov eax, edi

		mov ebx, [eax]
		mov [esi], ebx
		add eax, TYPE quadArray
		
		mov ebx, [eax]
		add [esi], ebx
		add eax, TYPE quadArray
		
		mov ebx, [eax]
		add [esi], ebx
		add eax, TYPE quadArray
		
		mov ebx, [eax]
		add [esi], ebx

		add esi, TYPE quadArray
		add edi, TYPE quadArray
	loop L1
	exit


	invoke	ExitProcess,0
main endp
end main