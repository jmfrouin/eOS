#ifndef __ARM_ASSEMBLY__
#define __ARM_ASSEMBLY__

#ifdef PLATFORM_ARCH_ARM

extern "C"
{
  /*!
   *@brief Fast Fixed-point * Fixed-point multiplication
   *@return Integer
   *@note precision loss: none
   *@note overload risk: none
   */
  int AFFMULI(int fpvalue1, int fpvalue2);
                      const XRect& rect, const int alpha565[]); // Stack
}

#endif

/*
ALIGN int __cdecl strlen_AgnerFog(const char* s)
{
	ALIGN int result = 0;
	__asm
	{
		mov     eax, [s]               ; get pointer s
		lea     edx, [eax+3]           ; pointer+3 used in the end
l1:
		mov     esi, [eax]             ; read 4 bytes of string
		add     eax, 4                 ; increment pointer
		lea     ecx, [esi - 01010101H] ; subtract 1 from each byte
		not     esi                    ; invert all bytes
		and     ecx, esi               ; and these two
		and     ecx, 80808080H         ; test all sign bits
		jz      l1                     ; no zero bytes, continue loop

		mov     esi, ecx
		shr     esi, 16
		test    ecx, 00008080H         ; test first two bytes
		cmovz   ecx, esi               ; shift if not in first 2 bytes
		lea     esi, [eax+2]           ; .. and increment pointer by 2
		cmovz   eax, esi
		add     cl,  cl                ; test first byte
		sbb     eax, edx               ; compute length
		mov [result], eax
	}
	return result;
}*/

#endif
