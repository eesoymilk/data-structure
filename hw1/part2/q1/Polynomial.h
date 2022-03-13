#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define Coefficient float
#define Exponent int

class Term
{
friend class Polynomial;
private:
    Coefficient coef = 0;
    Exponent exp = 0;
public:
    Term() {}
    Term(Coefficient c, Exponent e): coef{c}, exp{e} {}
    Coefficient getCoef() { return coef; }
    Exponent getExp() { return exp; }
};

class Polynomial
{
private:
    std::vector<Term> terms = std::vector<Term>(0);
public:
    // construct the polynomial p(x) = 0
    Polynomial() {}

    // add new term
    void NewTerm(const Coefficient c, const Exponent e);

    // return the sum of *this and poly
    Polynomial Add(Polynomial poly);

    // return the product of *this and poly
    Polynomial Mult(Polynomial poly);

    // Evaluate the polynomial *this at f and return the results
    float Eval(float f);

    // if *this is the zero polynomial, return 1; else return 0;
    int operator!();

    // return the coefficient of e in *this
    Coefficient Coef(Exponent e);

    // return the largest exponent in *this
    Exponent LeadExp();

    // return all terms
    std::vector<Term> getTerms();

    // output functions
    friend std::ostream &operator<<(std::ostream &out, Polynomial &poly);

    // input functions
    friend std::istream &operator>>(std::istream &out, Polynomial &poly);
};

#endif