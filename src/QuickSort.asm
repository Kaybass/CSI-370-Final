;
; Alexander Bean Apmann
;
; int * QuickSort(int * array, int size)
;

section .text

global QuickSort

QuickSort:
        push ebp
        mov  ebp, esp

        mov  esi, [ebp+8]
        mov  eax, [ebp+12]
        dec  eax
        mov  ecx, 4
        mul  ecx
        mov  ecx, eax
        xor  eax, eax
        mov  ebx, ecx

        call QuickRecursive

        mov eax, [ebp+8]

        mov  esp, ebp
        pop  ebp

        ret

QuickRecursive:

        push ebp
        mov  ebp, esp

        cmp  eax, ebx
        jge  EndIf

        push eax
        push ebx
        add  ebx, 4
        mov  edi, [esi+eax]
L1:

L2:

        add  eax, 4
        cmp  eax, ebx
        jge  EL2

        cmp  [esi+eax], edi
        jge  EL2

        jmp  L2
EL2:

L3:

        sub  ebx, 4
        cmp  [esi+ebx], edi
        jle  EL3

        jmp  L3
EL3:

        cmp  eax, ebx
        jge  EndL1

        mov  edx, dword [esi+eax]
        xchg edx, dword [esi+ebx]
        xchg edx, dword [esi+eax]

        jmp  L1
EndL1:

        pop  edi
        pop  ecx
        cmp  ecx, ebx
        je   Recur

        mov  edx, dword [esi+ecx]
        xchg edx, dword [esi+ebx]
        xchg edx, dword [esi+ecx]
Recur:

        mov  eax, ecx
        push edi
        push ebx
        sub  ebx, 4

        call QuickRecursive

        pop  eax
        add  eax, 4
        pop  ebx

        call QuickRecursive
EndIf:

        mov  esp, ebp
        pop  ebp

        ret
