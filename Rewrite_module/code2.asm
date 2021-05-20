.686
PUBLIC _Triangle@12
.model flat
.code
_Triangle@12 proc

        mov eax, [esp+4]
        mov ebx, [esp+8]
        add eax, ebx
        jc go_next
        cmp eax, [esp+12]
        jbe finish_false
        
        go_next:
            mov eax, [esp+12]
            add eax, ebx
            jc go_next_again
            cmp eax, [esp+4]
            jbe finish_false
        go_next_again:
            mov eax, [esp+4]
            mov ebx, [esp+12]
            add eax, ebx
            jc finish_true
            cmp eax, [esp+8]
            jbe finish_false
        finish_true:
            mov eax, 1
            jmp end_point
        finish_false:
            mov eax, 0
        end_point:    
        ret 12
        _Triangle@12 endp
        end
    