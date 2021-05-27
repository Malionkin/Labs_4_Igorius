.686
.model flat

.data
angle dd 180
res dd 1
.code
_CalculateArcsin@4 proc

finit
fld dword ptr[esp+4]
fld dword ptr[esp+4]
fmul
fld1
fsubr
fsqrt
fld dword ptr[esp+4]
fxch
fpatan
fild angle
fmul
fldpi
fdiv
fistp angle
mov eax, angle

ret 4
_CalculateArcsin@4 endp
end
