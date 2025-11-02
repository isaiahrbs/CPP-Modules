#include <iostream>
#include <string>
#include "Array.hpp"

template<typename T>
Array<T>::Array() : array(0), len(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {}

template<typename T>
Array<T>::Array(const Array& other) {
    len = other.len;
    if (len)
        array = new T[len];
    for (size_t i = 0; i < len; i++) {
        array[i] = other.array[i];
    }
}

template<typename T>
Array<T>::~Array() {
    delete[] array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        len = other.len;
        delete[] array;
        array = new T[len];
        for (size_t i = 0; i < len; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template<typename T>
size_t Array<T>::size() const {
    return len;
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= len)
        throw PassedArrayLimit();
    return array[i];
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= len)
        throw PassedArrayLimit();
    return array[i];
}

template<typename T>
const char* Array<T>::PassedArrayLimit::what() const throw() {
    return "Index is out of bound!";
}