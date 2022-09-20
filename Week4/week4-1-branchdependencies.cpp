//Branch dependency Demo
//Debug --> Window --> Disassembly
//Ctrl + Alt + D to see disassembly
///
///	return (b != 0) ? a / b : defaultValue;
//00007FF7C64C1787  cmp         dword ptr[b], 0
// dependency here is between cmp (compare) instruction and je (jump equal)
// the CPU cannot issue conditional jump until it knows the result of the comparison
//00007FF7C64C178E  je          SafeIntegerDivide + 45h(07FF7C64C17A5h)   
//00007FF7C64C1790  mov         eax, dword ptr[a]
// The CDQ instruction can be used to produce a quadword dividend from a doubleword before doubleword division.
//00007FF7C64C1796  cdq			;The CDQ instruction copies the sign (bit 31) of the value in the EAX register into every bit position in the EDX register
//00007FF7C64C1797  idiv        eax, dword ptr[b]  ;quotient lands in eax
//00007FF7C64C179D  mov         dword ptr[rbp + 0C0h], eax
//00007FF7C64C17A3  jmp         SafeIntegerDivide + 51h(07FF7C64C17B1h)
//00007FF7C64C17A5  mov         eax, dword ptr[defaultValue]
//00007FF7C64C17AB  mov         dword ptr[rbp + 0C0h], eax
//00007FF7C64C17B1  mov         eax, dword ptr[rbp + 0C0h]
//}
//00007FF7C64C17B7  lea         rsp, [rbp + 0D8h] ; lea is an abbreviation of "load effective address". It loads the address of the location reference by the source operand to the destination operand.
//00007FF7C64C17BE  pop         rdi
//00007FF7C64C17BF  pop         rbp
//00007FF7C64C17C0  ret          ; eax is the return value
/// 
///

#include <iostream>
using namespace std;

int SafeIntegerDivide(int a, int b, int defaultValue) {
	return (b != 0) ? a / b : defaultValue;
}

int main()
{
	cout << SafeIntegerDivide(4, 2, 0);
	system("pause");
}


