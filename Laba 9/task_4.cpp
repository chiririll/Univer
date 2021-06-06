#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int m, n;
    cout << "Enter m, n: ";
    cin >> m >> n;
    
    double a, b;
    cout << "Enter a, b: ";
    cin >> a >> b;

    // Creating and filling matrix
    double** matr = new double*[m];
    for (int i = 0; i < m; i++) {
        matr[i] = new double[n];
        for (int j = 0; j < n; j++)
            matr[i][j] = double(rand())/(double)RAND_MAX*(b-a)+a;
    }

    // Printing matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
