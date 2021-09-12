#include <iostream>
using namespace std;

template <class T>
void bit_show(T param)
{
    for(int ii = 2*sizeof(T)-1; ii >= 0; ii--)
        cout << (param&(1<<ii) ? 1 : 0) << " ";
}

int main()
{
    cout << "x y z t | F" << endl << "-----------" << endl;
    for (short i = 0; i < 16; i++) {
        bit_show(i);
        
        bool x = i & 0b1000;
        bool y = i & 0b0100;
        bool z = i & 0b0010;
        bool t = i & 0b0001;
        
        cout << "| " << ((!(z && t) && (x || y) && !(y || z)) ? 1 : 0) << endl;
    }
    
    system("pause");
    return 0;
}