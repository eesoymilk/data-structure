#pragma once

#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

class Matrix;   // Forward Declarations
class MatrixNode
{
    friend class Matrix;
    friend std::istream &operator>>(std::istream &, Matrix &);
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

public:
    MatrixNode(bool b, std::tuple<int, int, int> t);    // constructor

private:
    MatrixNode *down, *right;
    bool is_head;
    union { // union without name
        MatrixNode *next;
        std::tuple<int, int, int> triple;
    };
};

class Matrix
{
    friend std::istream &operator>>(std::istream &, Matrix &);
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

public:
    Matrix();
    Matrix(const Matrix &a);
    ~Matrix();  // desrtuctor
    const Matrix Transpose() const;
    Matrix operator+(const Matrix &b) const;
    Matrix operator*(const Matrix &b) const;

private:
    MatrixNode *head = nullptr;
};
