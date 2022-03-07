#include "Polynomial.h"

// #include <vector>
// #include <algorithm>
// #include "Term.h"

Polynomial::Polynomial()
{
    terms = std::vector<Term*>(0);
};

Polynomial::~Polynomial()
{
    for (int i = 0; i < terms.size(); i++) delete terms[i];
    terms.clear();
};

void Polynomial::NewTerm(const Coefficient c, const Exponent e)
{
    terms.push_back(new Term(c, e));
}

// Polynomial Polynomial::Add(Polynomial poly)
// {
//     terms = std::vector<Term*>(0);
// };

std::ostream &operator<<(std::ostream &out, Polynomial &poly) {
    std::vector<Term*> terms = poly.getTerms();
    for (int i = 0, cap = terms.size(); i < cap; i++) {
        const Coefficient c = terms[i]->getCoef();
        const Exponent e = terms[i]->getExp();
        if (c != 1.0) out << c;
        if (e != 0) out << "x^" << e;
        if (i < cap - 1) out << " + ";
    }
    return out;
}