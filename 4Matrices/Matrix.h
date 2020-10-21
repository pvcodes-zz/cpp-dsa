#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

class Matrix {
   protected:
    int *A;
    int len;
    int order;

   public:
    Matrix(int a, int b);
    virtual void addElement() = 0;
    virtual int getElement(int i, int j) = 0;
    virtual void display() = 0;
    ~Matrix();
};

class DiagonalMatrix : public Matrix {
   public:
    // Constructor
    DiagonalMatrix(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};

class LowerTriangluar : public Matrix {
   public:
    // Constructor
    LowerTriangluar(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};

class UpperTriangluar : public Matrix {
   public:
    // Constructor
    UpperTriangluar(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};

class Symmetric : public Matrix {
   public:
    // Constructor
    Symmetric(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};

class TriDiagonal : public Matrix {
   public:
    // Constructor
    TriDiagonal(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};

class Toeplitz : public Matrix {
   public:
    // Constructor
    Toeplitz(int a);
    void addElement() override;
    int getElement(int i, int j) override;
    void display() override;
};
#endif  // MATRIX_H