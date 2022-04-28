#pragma once

#include "CircularList.h"
#include "Global.h"

class Term
{
    friend class Polynomial;
    friend std::istream &operator>>(std::istream &in, Polynomial &p);
    friend std::ostream &operator<<(std::ostream &out, Polynomial &p);

public:
    Term(double c = 1, int e = 0) : coef(c), exp(e) {}

private:
    double coef;
    int exp;
};

class Polynomial
{
private:
    CircularList<Term> poly;

public:
    Polynomial();
    Polynomial(const Polynomial &a);
    ~Polynomial();
    void NewTerm(double c, int e);
    Polynomial &operator=(const Polynomial &a);
    const Polynomial operator+(const Polynomial &b) const;
    const Polynomial operator-(const Polynomial &b) const;
    const Polynomial operator*(const Polynomial &b) const;

    double Evaluate(double x) const;

    friend std::istream &operator>>(std::istream &in, Polynomial &p);
    friend std::ostream &operator<<(std::ostream &out, Polynomial &p);
};
