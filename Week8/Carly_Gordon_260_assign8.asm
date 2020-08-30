; Program template

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


DAYS = 7     ; constant representing the number of days in a week
HOURS = 24   ; constant representing the number of hours in a day
MINUTES = 60  ; constant representing the number of minutes in an hour
SECONDS = 60  ; constant representing the number of seconds in a minute

.data

date_time DWORD ? ; byte 0000 stores the DAY, byte 0001 stores the HOUR, byte 0002 stores the MINUTE, and byte 0003 stores the SECOND
num_of_iters DWORD 0  ; counts the total number of iterations
day BYTE DAYS   ; used to restore cl to the current day value
hour BYTE HOURS  ; used to restore cl to the current hour value
minute BYTE MINUTES  ; used to restore cl to the current minute value
second BYTE SECONDS ; used to restore c1 to the current second value
	
.code
main proc
	
	movzx ecx, day
	; C1 - First loop setting the day
	L1:
		push ecx
		movzx ecx, hour
		; C2 - Second loop setting the hour
		; C - reset the hour since the unit is changed in the previous loop and date_time, 000000FFh
		L2: 
			push ecx
			movzx ecx, minute
			; 3 reset the minute since the unit is changed in the previous loop and date_time, 0000FFFFh
			; 4 hours loop
			; C3 - Third loop setting the minutes
			L3:
				push ecx
				movzx ecx, second
				; 5 reset the second since the unit is changed in the previous loop and date_time, 00FFFFFFh
				; C - Fourth loop setting the seconds
				L4:
					add date_time, 01000000h
					; 6 increment iteration
					inc num_of_iters
					loop L4
				pop ecx
				; 7 subtract and add bytes to move to the next unit
				sub date_time, 01000000h
				add date_time, 00010000h
			loop L3
			pop ecx
			; 8 subtract and add bytes to move to the next unit
			sub date_time, 00010000h
			add date_time, 00000100h
		loop L2
		pop ecx
		; 9 subtract and add bytes to move to the next unit
		sub date_time, 00000100h
		add date_time, 00000001h
		dec ecx
	jnz L1
	; 10 subtract the date byte to move to the next unit (doesn't add because there's no week) 
	sub date_time, 00000001h


	invoke ExitProcess,0
main endp
end main