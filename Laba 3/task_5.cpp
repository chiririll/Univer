#include <iostream>
#include <cmath>

using namespace std;

template <class T>
void bit_show(T param)
{
    for(int ii = 8*sizeof(T)-1; ii >= 0; ii--)
        cout << (param&(1<<ii) ? 1 : 0) << " ";
}

int main()
{
    int a;
    cout << "Enter a: ";
    cin >> a;

    int shifted = (a >> 1) & (int)(pow(2, 32-1) - 1);
    cout << "Shifted: " << shifted << endl;

    cout << endl << "Default: ";
    bit_show(a);
    cout << endl << "Shifted: ";
    bit_show(shifted);
    cout << endl;
    
    system("pause");
    return 0;
}