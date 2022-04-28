#pragma once

#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

class Matrix;
class MatrixNode
{
    friend class Matrix;
    friend std::istream &operator>>(std::istream &, Matrix &);
    friend std::ostream &operator<<(std::ostream &, Matrix &);

public:
    MatrixNode(bool b, std::tuple<int, int, int> t);

private:
    MatrixNode *down, *right;
    bool is_head;
    union {
        MatrixNode *next;
        std::tuple<int, int, int> triple;
    };
};

MatrixNode::MatrixNode(bool b,
                       std::tuple<int, int, int> t = std::make_tuple(0, 0, 0))
{
    is_head = b;
    if (b) right = down = this;
    else triple = t;
}

class Matrix
{
    friend std::istream &operator>>(std::istream &, Matrix &);
    friend std::ostream &operator<<(std::ostream &, Matrix &);

public:
    Matrix();
    Matrix(const Matrix &a);
    ~Matrix();
    void Transpose();
    const Matrix &operator+(const Matrix &b) const;
    const Matrix &operator*(const Matrix &b) const;

private:
    MatrixNode *head;
};
