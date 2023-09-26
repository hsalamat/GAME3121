; To write an assembly language project:
; 1. Create an empty c++ project
; 2. Right Click on Project--> Build Dependencies --> Build Customization --> select masm checkbox
; 3. Project Properties --> Linker --> System --> Select "Windows" subsystem
; 4. Make sure that you select "x86"
; 5. Add a new c++ item, but name it a main.asm
; 6.The listing file is useful for examining what the assembler has generated. To setup the listing file generation, 
;  right click the project name > Properties > Microsoft Macro Assembler > Listing File > Assembled Code Listing File : $(IntDir)$(ProjectName).lst
; 7. Click on "Project" menu --> Export Template --> select all the default so you have a template that next time you don't need to do these configs
; Look at the "Registers" window (select Debug > Windows > Registers, or press Alt+5)
.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

.data
myList DWORD 2, 3, 5, 8

.code
main PROC
  mov eax, 7
  add eax, 2
  INVOKE ExitProcess, eax
main ENDP
END main