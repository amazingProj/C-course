#include<stdio.h>
/**
* @return 0 
*/
int main() {
00753BF0  push        ebp  
00753BF1  mov         ebp,esp  
00753BF3  sub         esp,0CCh  
00753BF9  push        ebx  
00753BFA  push        esi  
00753BFB  push        edi  
00753BFC  lea         edi,[ebp-0CCh]  
00753C02  mov         ecx,33h  
00753C07  mov         eax,0CCCCCCCCh  
00753C0C  rep stos    dword ptr es:[edi]  
00753C0E  mov         ecx,offset _605487F4_HelloWorld@c (075C003h)  
00753C13  call        @__CheckForDebuggerJustMyCode@4 (0751208h)  
	int i = 0;
00753C18  mov         dword ptr [i],0  
	for(;i<5;++i)
00753C1F  jmp         main+3Ah (0753C2Ah)  
00753C21  mov         eax,dword ptr [i]  
00753C24  add         eax,1  
00753C27  mov         dword ptr [i],eax  
00753C2A  cmp         dword ptr [i],5  
00753C2E  jge         main+66h (0753C56h)  
	{
		if ((i % 2) == 0)
00753C30  mov         eax,dword ptr [i]  
00753C33  and         eax,80000001h  
00753C38  jns         main+4Fh (0753C3Fh)  
00753C3A  dec         eax  
00753C3B  or          eax,0FFFFFFFEh  
00753C3E  inc         eax  
00753C3F  test        eax,eax  
00753C41  jne         main+64h (0753C54h)  
		{
			printf(" % d\n " , i);
00753C43  mov         eax,dword ptr [i]  
00753C46  push        eax  
00753C47  push        offset string " % d\n " (0757BCCh)  
00753C4C  call        _printf (0751375h)  
00753C51  add         esp,8  
		}
	}
00753C54  jmp         main+31h (0753C21h)  
	return 0;
00753C56  xor         eax,eax  
	
}
00753C58  pop         edi  
00753C59  pop         esi  
00753C5A  pop         ebx  
00753C5B  add         esp,0CCh  
00753C61  cmp         ebp,esp  
00753C63  call        __RTC_CheckEsp (0751212h)  
00753C68  mov         esp,ebp  
00753C6A  pop         ebp  
00753C6B  ret  
