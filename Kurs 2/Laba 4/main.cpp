#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    string filename;
    double x;
    
    cout << "Enter file path: ";
    cin >> filename;
    fstream fin(filename);
    if (fin.fail()) return -1;
    
    vector<double> _arr;

    while (fin >> x) _arr.push_back(x);
    cout << accumulate(_arr.begin(), _arr.end(), 1, multiplies<double>()) << endl;

    return 0;
}