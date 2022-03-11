#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "global.h"
#include "Term.h"

class Polynomial
{
private:
    std::vector<Term*> terms;
public:
    // construct the polynomial p(x) = 0
    Polynomial();

    // destructor for the polynomial
    ~Polynomial();

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
    std::vector<Term*> getTerms();

    // output functions
    friend std::ostream &operator<<(std::ostream &out, Polynomial &poly);

    // input functions
    friend std::istream &operator>>(std::istream &out, Polynomial &poly);
};

#endif