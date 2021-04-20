#include <iostream>
using namespace std;

int main()
{
    int q;
    int* pq = &q;
    int** ppq = &pq;
    int*** pppq = &ppq;
    
    cout << ppq + sizeof(ppq) + 1 << endl;
    
    system("pause");
    return 0;
}