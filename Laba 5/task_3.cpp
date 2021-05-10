#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    switch (input) {
        case 4:
            cout << "Yes";
            break;
        default:
            cout << "No";
    }
    cout << endl;
    
    system("pause");
    return 0;
}