#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;


    double res = 2;
    while (n > 1) {
        res = 2 + pow(res, 1.0 / n);
        n--;
    }
    
    cout << "Result: " << res << endl;

    return 0;
}