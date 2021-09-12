#include <iostream>

using namespace std;

template <typename T>
void append(T* arr, int pos, T el) {
    arr[pos] = el;
};

template <typename T, typename ... TYPES>
void append(T* arr, int pos, T el, TYPES ... args) {
    arr[pos] = el;
    append<T>(arr, pos+1, args...);
};

template <typename T, typename ... TYPES>
T* create_arr(int count, T el, TYPES ... args) {
    auto arr = new T[count];
    arr[0] = el;
    append<T>(arr, 1, args...);
    return arr;
};

int main() {
    auto arr = create_arr(5, 1, 2, 3, 4, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';
    cout << endl;
    
    system("pause");
    return 0;
}