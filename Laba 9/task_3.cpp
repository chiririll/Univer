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
    
    int m, n;
    cout << "Enter m, n: ";
    cin >> m >> n;

    // Creating and filling matrix
    int** matr = new int*[m];
    for (int i = 0; i < m; i++) {
        matr[i] = new int[n];
        for (int j = 0; j < n; j++)
            fin >> matr[i][j];
    }

    // Printing matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // Finding sum
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int linesum = 0;
        for (int j = 0; j < n; j++) {
            if (matr[i][j] < 0) {
                linesum = 0;
                break;
            }
            linesum += matr[i][j];
        }
        sum += linesum;
    }
    cout << "Sum is: " << sum << endl;
    
    return 0;
}
