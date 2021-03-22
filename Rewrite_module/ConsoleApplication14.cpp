#include <iostream>

using namespace std;

extern "C" int _stdcall Calculate(int, int,int, int );
extern "C" bool _stdcall Triangle(unsigned, unsigned, unsigned); 
extern "C" void _cdecl Matrix_asm(int*, int*, int, int*);

void Matrix(int n)
{
    int result[3]{ 0,0,0 };
    int* array1 = new int[n];
    int* array2 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter " << i + 1 << " element of array A - " << endl;
        cin >> array1[i];
        cout << "Enter " << i + 1 << " element of array B - " << endl;
        cin >> array2[i];
    }
    Matrix_asm(array1, array2, n, result);
    //cout << "Result is " << result[0] << endl;
}
int main()
{
    int a, b, c, y;
    cout << "Please, enter the variables!" << endl;;
    cin >> a >> b >> c >> y;
    cout << Calculate(a, b, c, y) << endl;
    Triangle(5, 3, 4);
    Triangle(3000000000, 3000000000, 2000000000);
    Triangle(1000000000, 2000000000, 3000000000);
    cout << "All is good, the first task is done! Let's go to the second!" << endl;
    int x = 3;
    Matrix(x);
    return 0;
}
