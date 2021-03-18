
#include <iostream>
using namespace std;

bool Triangle(unsigned a, unsigned b, unsigned c)
{
    unsigned result;
    __asm
    {
        mov eax, a
        mov ebx, b
        add eax, ebx
        jc go_next
        cmp eax, c
        jbe finish_false
        
        go_next:
            mov eax, c
            add eax, ebx
            jc go_next_again
            cmp eax, a
            jbe finish_false
        go_next_again:
            mov eax, a
            mov ebx, c
            add eax, ebx
            jc finish_true
            cmp eax, b
            jbe finish_false
        finish_true :
            mov result, 1
            jmp end_point
        finish_false:
            mov result, 0
            
        
        
                
        end_point:    
    }
    cout << result << endl;
    return result;
}



   
    int main() 
    {
        Triangle(5, 3, 4);
        Triangle(3000000000, 3000000000, 2000000000);
        Triangle(1000000000, 2000000000, 3000000000);
        cout << "All is good, the first task is done! Let's go to the second!" << endl;



        int result[3]{0,0,0};
        int n ;
        cout << "Enter the size of array!" << endl;
        cin >> n;
        int* array1 = new int[n];
        int* array2 = new int[n];
        for (int i = 0; i < n; ++i) 
        {
            cout << "Enter " << i+1 << " element of array A - " << endl;
            cin >> array1[i];
            cout << "Enter " << i+1 << " element of array B - " << endl;
            cin >> array2[i];
        }

        __asm 
        {
            mov edi, array1
            mov esi, array2
            mov ecx, 0

            _begin:
                cmp ecx, n
                    je _end
                mov ebx, dword ptr[edi]
                mov eax, dword ptr[esi]
                imul ebx
                add [result], eax
                adc [result + 4], edx
                adc [result + 8], 0
                inc ecx
                add edi, 4
                add esi, 4
                    jmp _begin
                _end :
        }
        cout << "Result is " << result[0] << endl;

        return 0;
    }

