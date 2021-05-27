.686
.model flat
.data

x1 dd ?
variable dd ?
eps dd ?
count dd 1
one dd 1
result dd ?

.code

_CalculateShinus@8 proc

finit
fld dword ptr[esp+4]
fst variable
fst result
fld dword ptr[esp+4]
fmul
fst x1
fld dword ptr[esp+8]
fst eps
fcompp
fstsw ax
sahf
ja _first

_cycle:
fld variable
fld x1
fmul
fild count 
fild one
fadd 
fist count
fdiv
fild count 
fild one
fadd 
fist count
fdiv
fst variable
fld result
fadd
fst result

fld variable
fld eps
fcompp
fstsw ax
sahf
jb _cycle

_first:
fld result
ret 8
_CalculateShinus@8 endp
end 