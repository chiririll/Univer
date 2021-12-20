#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    double x, mult = 1;
    
    fstream fin("input.txt");
    if (fin.fail()) return -1;
    
    vector<double> _arr;

    while (fin >> x) _arr.push_back(x);
    cout << accumulate(_arr.begin(), _arr.end(), 1, multiplies<double>()) << endl;

    return 0;
}