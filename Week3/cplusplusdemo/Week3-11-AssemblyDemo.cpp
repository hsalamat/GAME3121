/** @file Week3-11-AssemblyDemo.cpp
 *  @brief Assembly Demo
 *
 * 
 *  @attention make sure that you change the platform to "32 bit"
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <stdio.h>
#include <intrin.h>

#define EAX 0
#define EBX 1
#define ECX 2
#define EDX 3

int main(void)
{
    int exx[4], a;

    // http://msdn.microsoft.com/en-us/library/4ks26t93%28v=vs.100%29.aspx
    puts("Using VC inline assembler:");

    for (a = 0; a < 5; a++)
    {
        __asm
        {
            xor ecx, ecx            // needed for a=4
            mov eax, a
            cpuid
            mov exx[EAX], eax
        }
        printf("The code %i gives %08X\n", a, exx[EAX]);
    }

    // http://msdn.microsoft.com/en-us/library/vstudio/hskdteyh%28v=vs.100%29.aspx
    puts("Using VC intrinsics:");

    for (a = 0; a < 5; a++)
    {
        __cpuid(exx, a);
        printf("The code %i gives %08X\n", a, exx[EAX]);
    }

    return 0;
}