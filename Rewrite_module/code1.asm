.686
PUBLIC _Calculate@16
.model flat
.code
_Calculate@16 proc
        mov eax, [esp+4]
        imul eax, 3
        mov ecx, eax
        mov eax, [esp+8]
        mov ebx, [esp+16]
        imul eax, ebx
        mov ebx, [esp+12]
        add eax, ebx
        neg eax
        cdq
        idiv ecx
        cmp edx, 0
        jne go_round
        jmp end_if

        go_round:
            imul edx, 2
            cmp edx, ecx
            jg plus_one
            jmp if_not

        plus_one:
            inc eax
            jmp end_if
        if_not:

        cmp edx, ecx
            jl end_if
            mov ecx, eax
            mov ebx, 2
            cdq
            idiv ebx
            cmp edx, 0
            je end_if
            mov eax, ecx
            inc eax

        end_if:
            
            ret 16
            _Calculate@16 endp
            end

   