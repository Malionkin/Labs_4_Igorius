#include <iostream>

using namespace std;

int Calculate(int a, int b, int c, int y)
{
    int result;
    __asm
    {
        mov eax, a
        imul eax, 3
        mov ecx, eax
        mov eax, b
        mov ebx, y
        imul eax, ebx
        mov ebx, c
        add eax, ebx
        neg eax
        cdq
        idiv ecx
        cmp edx, 0
        jne go_round
        jmp end_if

        go_round :
            imul edx, 2
            cmp edx, ecx
            jg plus_one
            jmp if_not

        plus_one :
            inc eax
            jmp end_if
        if_not :

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

        end_if :
            mov result, eax
    }
    return result;
}

int main() 
{
    int a, b, c, y;
    cout << "Please, enter the variables!"<< endl;;
    cin >> a >> b >> c >> y;
    cout << Calculate(a, b, c, y) << endl;
    return 0;
}







