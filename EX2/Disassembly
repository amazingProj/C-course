#include<stdio.h>
/**
* @return 0 
*/
int main() {
003E1DD4  add         byte ptr [eax],al  
003E1DD6  add         byte ptr [eax-33333334h],bh  
003E1DDC  rep stos    dword ptr es:[edi]  
003E1DDE  mov         ecx,offset _605487F4_HelloWorld@c (03EC003h)  
003E1DE3  call        @__CheckForDebuggerJustMyCode@4 (03E1208h)  
	int i = 0;
003E1DE8  mov         dword ptr [i],0  
	while (i < 5)
003E1DEF  cmp         dword ptr [i],5  
003E1DF3  jge         main+64h (03E1E24h)  
	{
		i++;
003E1DF5  mov         eax,dword ptr [i]  
003E1DF8  add         eax,1  
003E1DFB  mov         dword ptr [i],eax  
		if ((i % 2) == 0)
003E1DFE  mov         eax,dword ptr [i]  
003E1E01  and         eax,80000001h  
003E1E06  jns         main+4Dh (03E1E0Dh)  
003E1E08  dec         eax  
003E1E09  or          eax,0FFFFFFFEh  
003E1E0C  inc         eax  
003E1E0D  test        eax,eax  
003E1E0F  jne         main+62h (03E1E22h)  
		{
			printf(" % d\n " , i);
003E1E11  mov         eax,dword ptr [i]  
003E1E14  push        eax  
003E1E15  push        offset string " % d\n " (03E7BCCh)  
003E1E1A  call        _printf (03E1375h)  
003E1E1F  add         esp,8  
		}
	}
003E1E22  jmp         main+2Fh (03E1DEFh)  
	return 0;
003E1E24  xor         eax,eax  
	
}
003E1E26  pop         edi  
003E1E27  pop         esi  
003E1E28  pop         ebx  
003E1E29  add         esp,0CCh  
003E1E2F  cmp         ebp,esp  
003E1E31  call        __RTC_CheckEsp (03E1212h)  
003E1E36  mov         esp,ebp  
003E1E38  pop         ebp  
003E1E39  ret  
