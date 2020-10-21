#include "Matrix.h"

#include <iostream>

// -------------------------------------------------------------------------------------
// Base Class - Matrix
// -------------------------------------------------------------------------------------
Matrix::Matrix(int a, int b) : len{a}, order{b} { A = new int[len]; };
Matrix::~Matrix() { delete[] A; }

// -------------------------------------------------------------------------------------
// Class - DiagonalMatrix
// -------------------------------------------------------------------------------------
DiagonalMatrix::DiagonalMatrix(int a) : Matrix(a, a) {}

void DiagonalMatrix::addElement() {
    for (int i = 0; i < len; i++) {
        std::cout << "Element at index [" << i + 1 << ", " << i + 1 << "] : ";
        std::cin >> A[i];
    }
}
int DiagonalMatrix::getElement(int i, int j) {
    if (i == j)
        return A[i];
    else
        return 0;
}
void DiagonalMatrix::display() {
    std::cout << "Matrix is: " << std::endl;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j)
                std::cout << A[i] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

// -------------------------------------------------------------------------------------
// Class - LowerTraingular
// -------------------------------------------------------------------------------------
LowerTriangluar::LowerTriangluar(int a) : Matrix{(a * (a + 1)) / 2, a} {}

void LowerTriangluar::addElement() {
    int x = 0;
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i >= j) {
                std::cout << "Element at index [" << i << ", " << j << "] : ";
                std::cin >> A[x];
                x++;
            }
        }
    }
}
int LowerTriangluar::getElement(int i, int j) {
    if (i < j)
        return 0;
    else
        return A[((i * (i - 1)) / 2) + (j - 1)];
}
void LowerTriangluar::display() {
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i < j)
                std::cout << "0 ";
            else
                std::cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
        }
        std::cout << std::endl;
    }
}

// ----------------------------------------------------------------------------------
// Class - UpperTriangular
// ----------------------------------------------------------------------------------
UpperTriangluar::UpperTriangluar(int a) : Matrix{(a * (a + 1)) / 2, a} {}

void UpperTriangluar::addElement() {
    int x = 0;
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i <= j) {
                std::cout << "Element at index [" << i << ", " << j << "] : ";
                std::cin >> A[x];
                x++;
            }
        }
    }
}
int UpperTriangluar::getElement(int i, int j) {
    if (i > j)
        return 0;
    else
        return A[((i * (i - 1)) / 2) + (j - 1)];
}
void UpperTriangluar::display() {
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i > j)
                std::cout << "0 ";
            else
                std::cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
        }
        std::cout << std::endl;
    }
}
// ----------------------------------------------------------------------------------
// Class - Symmetric
// ----------------------------------------------------------------------------------
Symmetric::Symmetric(int a) : Matrix{(a * (a + 1)) / 2, a} {}

void Symmetric::addElement() {
    int x = 0;
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i >= j) {
                std::cout << "Element at index [" << i << ", " << j << "] : ";
                std::cin >> A[x];
                x++;
            }
        }
    }
}
int Symmetric::getElement(int i, int j) {
    if (i < j) swap(i, j);
    // std::cout << "[" << i << ", " << j << "] :";
    return A[((i * (i - 1)) / 2) + (j - 1)];
}
void Symmetric::display() {
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i < j) {
                swap(i, j);
                std::cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
                swap(j, i);
            } else
                std::cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
        }
        std::cout << std::endl;
    }
}

// ----------------------------------------------------------------------------------
// Class - TriDiagonal
// ----------------------------------------------------------------------------------
TriDiagonal::TriDiagonal(int a) : Matrix{3 * a - 2, a} {}

void TriDiagonal::addElement() {
    int x = 0;
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (!(i - j >= 2 || i - j <= -2)) {
                std::cout << "Element at index [" << i << ", " << j << "] : ";
                std::cin >> A[x];
                x++;
            }
        }
    }
}

int TriDiagonal::getElement(int i, int j) {
    if (i - j >= 2 || i - j <= -2)
        return 0;
    else
        return A[2 * i + j - 3];
}
void TriDiagonal::display() {
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i - j >= 2 || i - j <= -2) {
                std::cout << "0 ";
            } else {
                std::cout << A[2 * i - j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

// ----------------------------------------------------------------------------------
// Class - Toeplitz
// ----------------------------------------------------------------------------------
Toeplitz::Toeplitz(int a) : Matrix{3 * a - 2, a} {}

void Toeplitz::addElement() {
    int x = 0;
    for (int i = 1; i < 2; i++) {
        for (int j = 1; j <= order; j++) {
            std::cout << "Element at index [" << i << ", " << j << "] : ";
            std::cin >> A[x];
            x++;
        }
        for (int j = 2; j <= order; j++) {
            std::cout << "Element at index [" << j << ", " << i << "] : ";
            std::cin >> A[x];
            x++;
        }
    }
}
int Toeplitz::getElement(int i, int j) {
    if (i - j < 0)
        return A[j - i];
    else
        return A[(order - 1) + (j - i)];
}

void Toeplitz::display() {
    for (int i = 1; i <= order; i++) {
        for (int j = 1; j <= order; j++) {
            if (i - j < 0) {
                std::cout << A[j - i] << " ";
            } else {
                std::cout << A[(order - 1) + (j - i)] << " ";
            }
        }
        std::cout << std::endl;
    }
}