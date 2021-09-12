#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    switch (input) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        default:
            cout << "I don't know";
    }
    cout << endl;
    
    system("pause");
    return 0;
}