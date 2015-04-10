;
; Alexander Bean Apmann
;
; BubbleSort(int * array, int arraylen)
;

section .text

global BubbleSort

BubbleSort:
        push ebp
        mov  ebp, esp
       
        mov  ecx, [ebp+12]
        mov  edi, [ebp+8]
        dec  ecx

L1:
        push ecx
        mov  esi, edi

L2:
        mov  eax, [esi]
        cmp  eax, [esi+4]
        jl   L3
        xchg eax, [esi+4]
        mov  [esi], eax

L3:
        add  esi, 4
        loop L2
        pop  ecx
        loop L1

        mov  eax, edi

        mov  esp, ebp
        pop  ebp
        ret
