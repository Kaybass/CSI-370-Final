;
; Alexander Bean Apmann
;
; int * SelectionSort(int * array, int arraylength)
;

section .text

global SelectionSort

SelectionSort:
        push ebp
        mov  ebp, esp

        mov  esi, [ebp+8]
        mov  ecx, [ebp+12]
        dec  ecx

L1:
        mov  edi, esi
        mov  eax, edi
        mov  ebx, [esi]
        push ecx

L2:
        add  edi, 4
        cmp  ebx, [edi]
        jg   less
        loop L2
        jmp  cont

less:
        mov  eax, edi
        mov  ebx, [edi+4]
        loop L2

cont:
        cmp  eax, esi
        je   noswitch
        mov  ebx, [eax]
        xchg ebx, [esi]
        xchg ebx, [eax]
        add  esi, 4
        pop  ecx
        loop L1
        jmp  end

noswitch:
        add  esi, 4
        pop  ecx
        loop L1

end:
        mov  eax, [ebp+8]

        mov  esp, ebp
        pop  ebp
        
        ret
