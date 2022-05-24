#include <iostream>
#include <string>

#include "UI/UI.h"
#include "Loaders/FileLoader.h"


using namespace std;

int main() {
    // Getting filename
    string file_path;
    cout << "Enter config path: ";
    getline(cin, file_path);
    cout << endl;

    // Creating file loader
    FileLoader loader(file_path);

    UI interface(&loader);
    
    interface.StartLoop();
}