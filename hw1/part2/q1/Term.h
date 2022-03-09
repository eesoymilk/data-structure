#ifndef TERM_H
#define TERM_H

#include "Polynomial.h"
#include "global.h"

class Term
{
private:
    Coefficient coef = 0;
    Exponent exp = 0;
public:
    Term() {}
    Term(Coefficient c, Exponent e): coef{c}, exp{e} {}
    Coefficient getCoef() { return coef; }
    Exponent getExp() { return exp; }
friend class Polynomial;
};

#endif