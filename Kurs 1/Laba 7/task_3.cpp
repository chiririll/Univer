#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int E, x;
    
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter E: ";
    cin >> E;

    double res = 0;
    int mult = 1, deg = 2;
    do {
        res += mult * pow(x, deg);
        mult += deg;
        deg++;
        E--;
    } while (E > 0);
    
    cout << "Result: " << res << endl;

    return 0;
}