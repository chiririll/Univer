#include <iostream>
#include <fstream>

#include "Point.hpp"
#include "Array.hpp"

using namespace std;

int main () {
    // Opening file 
    ifstream fin("D:\\Projects\\Cpp\\Univer\\Kurs 2\\Laba 3\\.build\\input.txt");
    if (fin.fail()) {
        cout << "Error opening file :(" << endl;
        return 0;
    }

    int n;
    fin >> n;

    auto points = Array<Point>(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        fin >> x >> y;
        points[i].set(x, y);
    }

    double min_distance = points[0].get_distance_to(points[1]);
    int i_min = 0, j_min = 1;
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if (points[i].get_distance_to(points[j]) < min_distance) {
                min_distance = points[i].get_distance_to(points[j]);
                i_min = i;
                j_min = j;
            }
        }
    }
    
    cout << "Min distance: " << min_distance << endl;
    cout << "Point 1: (" << points[i_min].get_x() << ", " << points[i_min].get_y() << ")" << endl;
    cout << "Point 2: (" << points[j_min].get_x() << ", " << points[j_min].get_y() << ")" << endl;

    return 0;
}