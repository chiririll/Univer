#include <iostream>
#include <fstream>
#include "windows.h"

using namespace std;

int main() {
    ifstream file;
    file.open("D:\\Projects\\Cpp\\Univer\\Kurs 2\\Laba 2\\SinCosFunc.cpp");
    if (file.fail()) return -1;
    
    char sym;
    while ((file.get(sym), file.eof()) == false) {
        cout << sym;
        Sleep(500);
    }

    return 0;
}