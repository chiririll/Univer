#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x, y;
    cin >> x >> y;

    if (x > 0)
        if (pow(x, 2) + pow(y, 2) <= 4)
            cout << "Da" << endl;
        else
            cout << "No" << endl;
    else
        if (pow(x, 2) / 7 + pow(y, 2) / 3 <= 1)
            cout << "Da" << endl;
        else
            cout << "No" << endl;

    system("pause");
    return 0;
}