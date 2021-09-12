#include <iostream>
#include <windows.h> 

using namespace std;


// k > 0 - left shift
// k < 0 - right shift
double cycle_shift(double n, int k)
{
	long long int* pn = (long long int*)&n;
	if (k > 0)
		return *pn << k | *pn >> sizeof(n) * 8 - k;
	else if (k < 0)
		return *pn >> -k | *pn << sizeof(n) * 8 + k;

	return n;
}

void bit_show(double param)
{
    long long int* ppar = (long long int*)&param;
    for(int ii = 8*sizeof(param)-1; ii >= 0; ii--)
        cout << (*ppar&(1<<ii) ? 1 : 0) << " ";
    cout << endl;
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    double n = 1.256;
    SetConsoleTextAttribute(hConsole, 10);
	for (int i = 0; true; i++)
	    bit_show(cycle_shift(n, i));
    
	return 0;
}
