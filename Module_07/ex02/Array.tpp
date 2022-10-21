#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <class T>
const char  *Array<T>::IndexOutOfRange::what() const throw () {
    return (RED "Index is out of range...\n" RESET);
}

template <class T>
Array<T>::Array() {
    cout << GREEN "Array default constructor called\n" RESET;
    this->_size = 0;
}

template <class T>
Array<T>::Array(unsigned int n) {
    cout << GREEN "Array constructor called\n" RESET;
    this->_arr = new T[n];
    this->_size = n;
}

template <class T>
Array<T>::Array(const Array &array_var) {
    cout << BLUE "Array copy constructor called\n" RESET;
    *this = array_var;
}

template <class T>
Array<T>::~Array() {
    cout << RED "Array destructor called\n" RESET;
    delete[] this->_arr;
}

template <class T>
Array<T>  &Array<T>::operator = (const Array &array_var) {
    cout << CYAN "Array copy assignment operator called\n" RESET;
    if (this->_size > 0) {
        delete[] this->_arr;
    }
    this->_arr = new T[array_var.size()];
    this->_size = array_var.size();
    for (int i = 0; i < this->_size; i++) {
        this->_arr[i] = array_var[i];
    }
    return (*this);
}

template <class T>
T   &Array<T>::operator [] (int index) const {
    if (index >= this->_size) {
        throw IndexOutOfRange();
    }
    return (this->_arr[index]);
}

template <class T>
int Array<T>::size(void) const {
    return (this->_size);
}

template <class T>
ostream &operator << (ostream &out, const Array<T> &array_var) {
    for (int i = 0; i < array_var.size(); i++) {
        out << YELLOW "[" << array_var[i] << "]" RESET;
    }
    out << endl;
    return (out);
}

#endif