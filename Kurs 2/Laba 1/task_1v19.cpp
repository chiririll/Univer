#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T f(int n, T (*func)(T), T x) {
    return n > 0 ? f(n-1, func, func(x)) : x;
};

int main() {
    cout << f<double>(2, sqrt, 256) << endl;
    return 0;
}
