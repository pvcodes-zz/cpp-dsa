#include "Array.h"

#include <iostream>

// Constructor
Array::Array() : size{10}, length{0} {
    p = new int[size];
    Add();
}
Array::Array(int sz) : size{sz}, length{0} {
    std::cout << size << std::endl;
    p = new int[size];
    Add();
}
// Destructor
Array::~Array() { delete[] p; }

// Private Method
void Array::Add() {
    length = 0;
    std::cout << "Note: If you want to leave before filling all element enter '8899'" << std::endl;
    for (int i = 0; i < size; i++) {
        int tmp;
        std::cout << "Enter the element for index " << i << ": ";
        std::cin >> tmp;
        if (tmp == 8899) break;
        p[i] = tmp;
        length++;
    }
}

void Array::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Public Method
void Array::Display() {
    std::cout << "Elements are: ";
    for (int i = 0; i < length; i++) std::cout << p[i] << " ";
    puts("");
}

int Array::Sum() {
    int total{0};
    for (int i = 0; i < length; i++) total += p[i];
    return total;
}

int Array::Max() {
    int m = p[0];
    for (int i = 1; i < length; i++)
        if (m < p[i]) m = p[i];
    return m;
}

int Array::Min() {
    int m = p[0];
    for (int i = 1; i < length; i++)
        if (m > p[i]) m = p[i];
    return m;
}

int Array::Avg() { return Sum() / length; }

bool Array::isSorted() {
    for (int i = 0; i < length - 1; i++)
        if (p[i] > p[i + 1]) return 0;
    return 1;
}

void Array::Insert(int index, int value) {
    if (index >= 0 && index <= size) {
        for (int i = length - 1; i >= index; i--) {
            p[i + 1] = p[i];
        }
        p[index] = value;
        if (index > length) length += index - (length - 1);
        length++;
    }
}
int Array::getLength() { return this->length; }
int Array::getSize() { return this->size; }
int *Array::getPtrAddr() { return p; }

int Array::BinarySearch(int value) {
    int l{0}, h{length - 1}, m{(l + h) / 2};
    while (l <= h) {
        if (p[m] == value)
            return m;
        else if (p[m] < value)
            l = m + 1;
        else if (p[m > value])
            h = m - 1;
        m = (l + h) / 2;
    }
    return -1;
}

void Array::Reverse() {
    for (int i = 0, j = length - 1; i < ((length - 1) / 2); i++, j--) swap(p[i], p[j]);
}
void Array::Append(int value) {
    p[length] = value;
    length++;
}

void Array::LeftShift() {
    // int tmp = p[0];
    for (int i = 0; i < length; i++) {
        p[i] = p[i + 1];
    }
    // p[length - 1] = 0;
}
void Array::LeftRotate() {
    int tmp = p[0];
    this->LeftShift();
    p[length - 1] = tmp;
}

void Array::RightShift() {
    for (int i = length; i >= 0; i--) {
        /* code */
        p[i] = p[i - 1];
    }
    length++;
}

void Array::RightRotate() {
    int tmp = p[length - 1];
    for (int i = length; i >= 0; i--) {
        p[i] = p[i - 1];
    }
    p[0] = tmp;
}