#include <iostream>
using namespace std;

int main()
{
    int q;
    int* pq = &q;
    int** ppq = &pq;
    int*** pppq = &ppq;
    
    cout << "| Variable |\t" << "q" << "\t|\t" << "pq" << "\t|\t" << "ppq" << "\t|\t" << "pppq" << "\t|" << endl;
    cout << string(73, '-') << endl;
    cout << "| Addres   | "  << &q  << "\t| "  << &pq  << "\t| "  << &ppq  << "\t| "  << &pppq  << "\t|" << endl;
    cout << "| Value    | "  <<  q  << "\t| "  <<  pq  << "\t| "  <<  ppq  << "\t| "  <<  pppq  << "\t|" << endl;
    
    cout << endl << "Answer: " << ppq + 1 << endl;
    
    system("pause");
    return 0;
}