; Look at the "Registers" window
.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

.data
	;define your variables here
.code

main PROC
	;write your asssembly code here
	mov eax, 3  ;;load value 3 into registry EAX
	mov ebx, 8  ;; load value 8 into registry EBX
	imul eax, 7 ;; multiply the content of EAX by 7, store the resultin EAX
	add eax, ebx  ;; add EAX to EBX and result stored in EAX

	INVOKE ExitProcess, 0
main ENDP
END main