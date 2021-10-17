#include <iostream>
#include <algorithm>
#include "SinCosFunc.hh"

using namespace std;

int main() {
    
    cout << "# Elements in array #" << endl;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;

    cout << "# Random #" << endl;
    int min, max;
    cout << "Enter min: ";
    cin >> min;
    cout << "Enter max: ";
    cin >> max;
    cout << endl;

    cout << "# Function #" << endl;
    double a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << endl;

    // Creating class
    SinCosFunc func(a, b, c);

    // Creating array
    cout << "# Generated array #" << endl;
    double* _arr = new double[n];
    for (int i = 0; i < n; i++) {
        _arr[i] = rand() % max + min;
        cout << _arr[i] << "\t";
    }
    cout << endl << endl;
    
    // Transform
    transform(_arr, _arr+n, _arr, func);

    // Configuring output
    cout.precision(2);
    cout << fixed;

    // Output
    cout << "# Results #" << endl;
    for (int i = 0; i < n; i++) {
        cout << _arr[i] << "\t";
    }
    cout << endl << endl;

    // String functions
    cout << "# Strings #" << endl;
    cout << "SinCosFunc: " << func.get_function_as_string() << endl;
    cout << "SinCosFunc(6.56) = " << func.get_function_as_string(6.56) << endl;
    cout << endl;
    
    system("PAUSE"); // Delete before printing
    return 0;
}