#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n, x;
    
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += i*pow(x, i);
    
    cout << "Result: " << res << endl;

    return 0;
}