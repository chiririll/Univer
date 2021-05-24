#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int E, x, n;
    
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter E: ";
    cin >> E;

    double res = 0;
    int mult = 1, deg = 2;
    do {
        res += mult * pow(x, deg);
        mult += deg;
        deg++;
        n--;
    } while (n > 0);
    
    cout << fixed;
    cout.precision(E);
    cout << "Result: " << res << endl;

    return 0;
}