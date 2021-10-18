#include <iostream>
#include <algorithm>
#include "SinCosFunc.hh"

using namespace std;

int main() {
    
    cout << "# Array configuration #" << endl;
    int n, min, max;
    cout << "Number of elements: ";
    cin >> n;
    cout << "Rand min: ";
    cin >> min;
    cout << "Rand max: ";
    cin >> max;
    cout << endl;

    cout << "# Function constants #" << endl;
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
    printf("Checking constants a = %f, b = %f, c = %f\n\n", func.get_a(), func.get_b(), func.get_c());

    // Configuring output
    cout.precision(2);
    cout << fixed;

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

    // Output
    cout << "# Results #" << endl;
    for (int i = 0; i < n; cout << _arr[i++] << "\t");
        cout << endl << endl;

    // Reverse function
    cout << "# Reverse function #" << endl;
    cout << "func(x) = -1.35, x = "<< func.get_argument_of_value(-1.35) << endl;
    cout << "Check: " << func.get_function_as_string(func.get_argument_of_value(-1.35)) << endl;
    cout << "func(x) = 0.58, x = "<< func.get_argument_of_value(0.58) << endl;
    cout << "Check: " << func.get_function_as_string(func.get_argument_of_value(0.58)) << endl;
    cout << endl;

    // String functions
    cout << "# Strings #" << endl;
    cout << "SinCosFunc: " << func.get_function_as_string() << endl;
    cout << "SinCosFunc(6.56) = " << func.get_function_as_string(6.56) << endl;
    cout << "SinCosFunc(-8.24) = " << func.get_function_as_string(-8.24) << endl;
    cout << endl;
    
    system("PAUSE"); // Delete before printing
    return 0;
}