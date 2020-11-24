#include<stdio.h>
/**
* @return 0 
*/
int main() {
00851700  push        ebp  
00851701  mov         ebp,esp  
00851703  sub         esp,0D8h  
00851709  push        ebx  
0085170A  push        esi  
0085170B  push        edi  
0085170C  lea         edi,[ebp-0D8h]  
00851712  mov         ecx,36h  
00851717  mov         eax,0CCCCCCCCh  
0085171C  rep stos    dword ptr es:[edi]  
0085171E  mov         ecx,offset _605487F4_HelloWorld@c (085C003h)  
00851723  call        @__CheckForDebuggerJustMyCode@4 (0851208h)  
	int i = 0;
00851728  mov         dword ptr [i],0  
	++i;
0085172F  mov         eax,dword ptr [i]  
00851732  add         eax,1  
00851735  mov         dword ptr [i],eax  
	i++;
00851738  mov         eax,dword ptr [i]  
0085173B  add         eax,1  
0085173E  mov         dword ptr [i],eax  
	int j = 0;
00851741  mov         dword ptr [j],0  
	j = i++;
00851748  mov         eax,dword ptr [i]  
0085174B  mov         dword ptr [j],eax  
0085174E  mov         ecx,dword ptr [i]  
00851751  add         ecx,1  
00851754  mov         dword ptr [i],ecx  
	j = ++i;
00851757  mov         eax,dword ptr [i]  
0085175A  add         eax,1  
0085175D  mov         dword ptr [i],eax  
00851760  mov         ecx,dword ptr [i]  
00851763  mov         dword ptr [j],ecx  
	return 0;
00851766  xor         eax,eax  
}
00851768  pop         edi  
00851769  pop         esi  
0085176A  pop         ebx  
0085176B  add         esp,0D8h  
00851771  cmp         ebp,esp  
00851773  call        __RTC_CheckEsp (0851212h)  
00851778  mov         esp,ebp  
0085177A  pop         ebp  
0085177B  ret  
