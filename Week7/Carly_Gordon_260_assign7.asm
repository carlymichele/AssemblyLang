.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
   array1 DWORD 999, 888, 777, 666, 555
   array2 DWORD 111, 222, 333, 444, 555
   array3 DWORD LENGTHOF array1 dup(?)
.code
main proc
    ; PHASE ONE - swapping and reversing element values
    ; 1. Array elements are stored in between eax and ebx. Using direct indexing, the elements can be swapped.
    mov eax, array1      ; 2. Note that the full 32-bit name must be used because the size of the variable in array1 is 32 bits.
    mov ebx, [array2+16] ; 3. Brackets are used to reference the location in memory of the element in the array.
    mov array1, ebx
    mov [array2+16], eax ; 4. Since the array stores type DWORD variables, I used the indexValue * 4 bytes to locate the proper element.

    mov eax, [array1+4]  ; 5. Note that the elements increment by four because the variable size of a DWORD is 4 bytes.
    mov ebx, [array2+12]
    mov [array1+4], ebx
    mov [array2+12], eax
    mov eax, [array1+8]
    mov ebx, [array2+8]
    mov [array1+8], ebx
    mov [array2+8], eax
    mov eax, [array1+12]
    mov ebx, [array2+4]
    mov [array1+12], ebx
    mov [array2+4], eax

    mov eax, [array1+16]
    mov ebx, array2
    mov [array1+16], ebx
    mov array2, eax

    ; PHASE TWO - subtracting element values
    mov eax, array1      ; 6. In order to subtract and store the sum in array3, the values from array1 are moved into eax.
    sub eax, array2      ; 7. Next, the cooresponding values of array2 are subtracted.
    mov array3, eax      ; 8. Finally, the sum is moved into the cooresponding index of array3.
    mov eax, [array1+4]
    sub eax, [array2+4]  ; 9. Brackets are used again to reference the element indeces by a factor of 4.
    mov [array3+4], eax  ; 10. Note that all the element values are all the same in phase two.
    mov eax, [array1+8]
    sub eax, [array2+8]
    mov [array3+8], eax
    mov eax, [array1+12]
    sub eax, [array2+12]
    mov [array3+12], eax
    mov eax, [array1+16]
    sub eax, [array2+16]
    mov [array3+16], eax


 invoke ExitProcess,0
main endp
end main
