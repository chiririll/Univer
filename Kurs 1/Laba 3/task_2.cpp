#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    
    a = --a / 2 - a++ * 2;

    cout << a << endl;
    
    system("pause");
    return 0;
}