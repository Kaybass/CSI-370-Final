;
;
; InsertionSort(int * array, int array)
;
;

section .text

global InsertionSort

InsertionSort:
        push ebp
        mov  ebp, esp

        mov  eax, [ebp+12]
        mov  ecx, 4
        mul  ecx
        mov  ecx, eax
        mov  eax, 4
        xor  ebx, ebx
        mov  esi, [ebp+8]
L1:
        cmp  eax, ecx

        jge  end

        push ecx
        mov  ecx, [esi+eax]
        mov  ebx, eax
        sub  ebx, 4
L2:
        cmp  ebx, 0

        jl   L3

        cmp  [esi+ebx], ecx

        jle  L3

        mov  edx, [esi+ebx]
        mov  dword [esi+ebx+4], edx
        sub  ebx, 4

        jmp  L2
L3:
        mov [esi+ebx+4], ecx
        add eax, 4
        pop ecx

        jmp L1
end:
        mov esp, ebp
        pop ebp
        ret
