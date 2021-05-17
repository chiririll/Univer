#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    // Localization
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    // Random
    srand(time(0));

    int n, r_min, r_max;
    
    cout << "Здравствуйте! Не могли бы вы ввести количество элементов массива? Если не возражаете, то вот поле ввода: ";
    cin >> n;
    cout << "Спасибо! Можно ли вас еще попросить задать диапазон для случайных чисел?" << endl;
    cout << "Минимальное число: ";
    cin >> r_min;
    cout << "Максимальное число: ";
    cin >> r_max;
    cout << "Огромное спасибо! Вы очень помогли!" << endl;

    // Average value in array
    double x_avg = 0;
    // Creating and filling array
    int* arr = new int[n];
    for (int* it = arr; it != arr+n; it++) {
        *it = r_min + rand() % (r_max - r_min);
        x_avg += *it;
    }
    x_avg /= n;

    // Saving array to file
    ofstream fout(".output/9_1.txt");
    for (int* it = arr; it != arr+n; it++) 
        fout << *it << " ";
    fout.close();

    // Task A
    double s2 = 0;
    for (int* it = arr; it != arr+n; it++) 
        s2 += pow(*it - x_avg, 2);
    s2 /= n-1;
    cout << "Исправленное среднеквадратическое отклонение массива = " << sqrt(s2) << endl;

    // Task B
    int sum = 0;
    for (int* it = arr; it != arr+n; it++) 
        if (*it > x_avg*2)
            sum += *it;
    cout << "Сумма элементов массива, вдвое больших среднего арифметического = " << sum << endl;

    system("pause");
    return 0;
}