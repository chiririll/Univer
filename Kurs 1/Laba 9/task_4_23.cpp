#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string path;
    cout << "Enter file path: ";
    getline(cin, path);

    // Opening file
    ifstream fin(path);
    if (fin.fail()) {
        cout << "Error opening file :(" << endl;
        return 0;
    }
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Creating and filling matrix
    int*** matr = new int**[n];
    for (int i = 0; i < n; i++) {
        matr[i] = new int*[n];
        for (int j = 0; j < n; j++) {
            matr[i][j] = new int[n];
            for (int k = 0; k < n; k++)
                fin >> matr[i][j][k];
        }
    }

    // Printing matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                cout << matr[i][j][k] << " ";
            cout  << endl;
        }
        cout << endl;
    }
    cout << endl;

    // Finding sum
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += matr[i][i][i];
    
    cout << "Sum is: " << sum << endl;

    system("pause");
    return 0;
}
