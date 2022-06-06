#include "Polynomial.h"

void Polynomial::NewTerm(const Coefficient c, const Exponent e)
{
    if (c == 0) return;
    if (terms.empty()) {
        terms.push_back(Term(c, e));
    } else {
        int idx;
        for (idx = 0; idx < terms.size() && e <= terms[idx].exp; idx++) {
            if (e == terms[idx].exp) {
                terms[idx].coef += c;
                return;
            }
        }
        terms.insert(terms.begin() + idx, Term(c, e));
    }
}

Polynomial Polynomial::Add(Polynomial poly)
{
    Polynomial res;
    for (auto term : this->terms) res.NewTerm(term.coef, term.exp);
    for (auto term : poly.terms) res.NewTerm(term.coef, term.exp);
    return res;
}

Polynomial Polynomial::Mult(Polynomial poly)
{
    Polynomial res;
    for (auto multiplier_term : this->terms)
        for (auto multiplicand_term : poly.terms)
            res.NewTerm(multiplier_term.coef * multiplicand_term.coef,
                        multiplier_term.exp + multiplicand_term.exp);
    return res;
}

float Polynomial::Eval(float f)
{
    float res = 0;
    for (auto term : this->terms) res += term.coef * pow(f, term.exp);
    return res;
}

int Polynomial::operator!() { return this->terms.empty() ? 1 : 0; }

Coefficient Polynomial::Coef(Exponent e)
{
    if (e > this->LeadExp()) return 0;
    for (int idx = 0; idx < this->terms.size(); idx++) {
        if (e == this->terms[idx].exp) return this->terms[idx].coef;
        if (e < this->terms[idx].exp) return 0;
    }
    return 0;
}

Exponent Polynomial::LeadExp()
{
    return this->terms.empty() ? 0 : this->terms[0].exp;
}

std::vector<Term> Polynomial::getTerms() { return terms; }

std::ostream &operator<<(std::ostream &out, Polynomial &poly)
{
    std::vector<Term> terms = poly.getTerms();
    for (int i = 0, cap = terms.size(); i < cap; i++) {
        const Coefficient c = terms[i].getCoef();
        const Exponent e = terms[i].getExp();
        if (c != 1.0 || (c == 1 && e == 0)) out << c;
        if (e != 0) {
            out << "x";
            if (e != 1) out << '^' << e;
        }
        if (i < cap - 1) out << " + ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &poly)
{
    std::string str_in;
    std::vector<std::string> str_terms;
    std::getline(in, str_in);

    // remove all whitespaces
    str_in.erase(remove(str_in.begin(), str_in.end(), ' '), str_in.end());

    // get terms in string form
    while (str_in.length()) {
        int len = str_in.find_first_of("+-", 1);
        if (len == std::string::npos) {
            str_terms.push_back(str_in);
            str_in.erase(str_in.begin(), str_in.end());
        } else {
            str_terms.push_back(str_in.substr(0, len));
            str_in.erase(str_in.begin(), str_in.begin() + len);
        }
    }

    // process each terms: eg, 3.6 x ^ 4
    // TO BE FIXED...
    for (auto str_term : str_terms) {
        int idx;
        Coefficient c;
        Exponent e;

        if (str_term.find('x') == std::string::npos) {
            // cannot find x: CONSTANT TERM, exponent == 0
            c = Coefficient(std::stod(str_term));
            e = Exponent(0);
        } else if (str_term.find('^') == std::string::npos) {
            // cannot find ^: exponent == 1
            if (str_term[0] == 'x') c = 1;
            else if (str_term[0] == '-' && str_term[1] == 'x') c = -1;
            else
                c = Coefficient(
                    std::stod(str_term.substr(0, str_term.length() - 1)));
            e = Exponent(1);
        } else {
            if (str_term[0] == 'x') c = 1;
            else if (str_term[0] == '-' && str_term[1] == 'x') c = -1;
            else
                c = Coefficient(
                    std::stod(str_term.substr(0, str_term.find('x'))));
            e = Exponent(std::stoi(
                str_term.substr(str_term.find('^') + 1, std::string::npos)));
        }
        poly.NewTerm(c, e);
    }

    return in;
}