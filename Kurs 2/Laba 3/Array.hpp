#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array 
{
private:
    T* _pointer;
    int _size;
public:
    Array(int size): _size(_size) {_pointer = new T[_size];};
    ~Array() {delete [] _pointer;};

    int size() const {return _size;};
    T& operator[] (int _index) {return _pointer[_index];};

    // External
    Array(const Array& _arr);
    Array operator=(const Array& _arr);
};

template <class T>
Array<T>::Array(const Array& _arr): Array(_arr._size) {
    for (int i = 0; i < _size; i++) 
        _pointer[i] = _arr._pointer[i];
}

template <class T>
Array<T> Array<T>::operator=(const Array& _arr) {
    if (this != &_arr) {
        delete [] _pointer;
        _size = _arr._size;
        _pointer = new T[_size];
        for (int i = 0; i < _size; i++)
            _pointer[i] = _arr._pointer[i];
    }
    return *this;
}

#endif