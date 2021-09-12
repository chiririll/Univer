#include <iostream>
using namespace std;

int main()
{
    bool x, y;
    float a, b;

    // Вводим значения переменных
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    // Вычисляем значение переменных
    cout << endl;
    if (!x || (x && !y) ^ (a != b))
        cout << "Da" << endl;
    else
        cout << "No" << endl;
    
    system("pause");
    return 0;
}
