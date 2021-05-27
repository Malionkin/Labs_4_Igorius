#include <iostream>
using namespace std;


extern "C" bool _cdecl Polyndrom(char* s);
extern "C" int _cdecl Braces(char* s, int length);

int main()
{
    cout << "Enter the line: " << endl;;
    

    char c[1000];
    cin >> c;

    if (Polyndrom(c)) {
        cout << "It's a polyndrom" << endl;;
    }
    else {
        cout << "It's not a polyndrom"<<endl;
    }
    
    
    cout << "Enter the line: " << endl;;

    char d[1000];
    cin >> d;

    cout << Braces(d, strlen(d)) << endl;
    cout << d;

    return 0;
}