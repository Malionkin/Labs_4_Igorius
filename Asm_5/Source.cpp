#include <iostream>
using namespace std;
extern "C" int _stdcall CalculateArcsin(float x);
extern "C" float _stdcall CalculateShinus(float x, float eps);

int main()
{
    float x;
    cout << "Please, enter x for calculating arcsin(x)!" << endl;
    cin >> x;
    cout << CalculateArcsin(x) << endl;
    cout << "OK! Go to the second task!" << endl;
    float x1, eps;
    cout << "Enter x: " << endl;
    cin >> x1;
    cout << "Enter eps: " << endl;
    cin >> eps;
    cout << CalculateShinus(x1, eps) << endl;
    return 0;
}
