.686
PUBLIC _Matrix_asm
.model flat
.code
_Matrix_asm proc
mov edi, [esp+4]
    mov esi, [esp+8]
    mov ecx, 0

    _begin:
    cmp ecx, [esp+12]
        je _end
        mov ebx, dword ptr[edi]
        mov eax, dword ptr[esi]
        imul ebx
        mov ebx, [esp+16]
        add [ebx], eax
        adc[ebx + 4], edx
        adc dword ptr [ebx + 8], 0
        inc ecx
        add edi, 4
        add esi, 4
        jmp _begin
        _end:
        ret 
_Matrix_asm endp
end