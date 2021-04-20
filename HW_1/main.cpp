#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

string TEST_PATH = "tests";
double COMB_STEP = 1.247;

/* Sorting */
void simple_sort (int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int j_min = 0;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[j_min])
                j_min = j;
        swap(arr[i], arr[j_min]);
    }
}

void bubble_sort (int *arr, int n) 
{
    bool f;
    do {
        f = false;
        for (int i = 0; i + 1 < n; i++)
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                f = true;
            }
    } while (f);
}

void comb_sort (int *arr, int n) 
{
    bool f;
    int jump = n;
    do {
        if (jump > 1)
            jump /= COMB_STEP;
        f = false;
        for (int i = 0; i + jump < n; i++)
            if (arr[i] > arr[i + jump]) {
                swap(arr[i], arr[i + jump]);
                f = true;
            }
    } while (jump > 1 || f);
}
/* ------- */

void test (void (*sort) (int* _arr, int n)) 
{
    unsigned int start;
    unsigned int end;

    for (int test = 1; test <= 9; test++) 
    {
        ifstream fin(TEST_PATH + "/" + to_string(test) + ".txt");
        if (fin.fail()) {
            cout << "\tError opening file :(" << endl;
            return;
        }
        
        int n;
        fin >> n;
        
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> arr[i];
        
        start = clock();
        sort(arr, n);
        end = clock();

        delete [] arr;
        cout << "\tTest #" << test << ": " << end - start << " ms" << endl;
    }
}

bool check_path() {
    ifstream fin(TEST_PATH + "/1.txt");
    return !fin.fail();
}

int main() {
    while (!check_path()) {
        cout << "Enter \'tests\' folder path: ";
        getline(cin, TEST_PATH);
        cout << endl;
    }

    cout << "Testing comb sort:" << endl;
    test(*comb_sort);
    cout << endl;

    cout << "Testing simple sort:" << endl;
    test(*simple_sort);
    cout << endl;

    cout << "Testing bubble sort:" << endl;
    test(*bubble_sort);
    cout << endl;

    system("PAUSE");
    return 0;
}