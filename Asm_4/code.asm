.686
.model flat
.code
_Polyndrom proc
mov edi, dword ptr[esp+4]
mov al, 0
mov ecx, -1
_continue:
add ecx, 1
scasb
jne _continue;


mov edi, dword ptr[esp+4]
mov esi, dword ptr[esp+4]
add esi, ecx
add esi, -1

_check:
cmp ecx, 0
jng _true;
add ecx, -2
mov eax, 0
std
lodsb
cld
scasb
je _check;

mov eax, 0
jmp _end;

_true:
mov eax, 1

_end:

ret 
_Polyndrom endp

_Braces proc
	push ebp
	mov ebp, esp
	push esi
	push edi

	mov edi, [ebp + 8]
	mov ecx, [ebp + 12]
	inc ecx
	
	mov al, '('
	repne scasb
	mov esi, edi
	mov edx, ecx
	dec edx
	
	mov al, ')'
	repne scasb
	sub edx, ecx

	push esi
	push edi
	pop esi
	pop edi

	dec edi
	rep movsb

	mov eax, [ebp + 12]
	sub eax, edx

	pop edi
	pop esi
	pop ebp
	ret 
_Braces  endp
end