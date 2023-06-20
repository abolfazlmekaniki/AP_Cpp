#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <math.h>
#include<compare>
// #include<ostream>
class Matrix{

    public:
    Matrix();
    ~Matrix();
    Matrix(int size);
    Matrix(int row, int column);
    Matrix(const Matrix& m);
    Matrix(std::initializer_list<std::initializer_list<double>> a);
    const Matrix& append(const Matrix& m,int axis=0);
    const Matrix& operator*(const Matrix& m);
    const Matrix& operator+(const Matrix& m);
    const Matrix& operator-(const Matrix& m);
    const Matrix& operator|(const Matrix& m);
    Matrix&  operator+=(const Matrix& m);
    std::partial_ordering operator<=>(const Matrix& m);
    int* operator[](size_t);
    bool operator==(const Matrix& m) const;
    const Matrix& operator++();
    const Matrix operator++(int);
    const Matrix& operator--();
    const Matrix operator--(int);
    const Matrix& operator=(const Matrix& m);
    friend std::ostream& operator<<(std::ostream & out ,const Matrix& m);
    void display() const;
    int getRowSize();
    int getColSize();
    int getRowCapacity();
    int getColCapacity();
    int** getMatrix();

    private:
    int** matrix;
    size_t row ;
    size_t col;
    size_t row_cap;
    size_t col_cap;
};

#endif // !MATRIX_H