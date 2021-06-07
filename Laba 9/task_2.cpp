#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // Opening file 
    ifstream fin("Laba 9/.input/input_2.txt");
    if (fin.fail()) {
        cout << "Error opening file :(" << endl;
        return 0;
    }

    // Entering array
    unsigned int n;
    fin >> n;
    
    double* arr = new double[n];
    for (int i = 0; i < n; i++) fin >> arr[i];

    // Changing size
    unsigned int n_new;
    cout << "Enter new size: ";
    cin >> n_new;
    
    double* tmp = arr;
    arr = new double[n_new];

    // Copyng array
    for (int i = 0; i < (n < n_new ? n : n_new); i++) 
        arr[i] = tmp[i];
    delete [] tmp;

    // Printing array
    for (int i = 0; i < n_new; i++) 
        cout << arr[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}