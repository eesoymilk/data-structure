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
        if (c != 1.0 && e != 0) out << c;
        if (e != 0) {
            out << "x";
            if (e != 1) out << '^' << e;
        }
        if (i < cap - 1) out << " + ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &poly) {
    std::string str_in;
    std::vector<std::string> str_terms;

    std::getline(in, str_in);
    // std::cout << "Raw input: " << str_in << '\n'; 

    // remove all whitespaces
    str_in.erase(remove(str_in.begin(), str_in.end(), ' '), str_in.end());
    // std::cout << "No whitespaces: " << str_in << '\n'; 

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
        // std::cout << "string extracted: " << *(str_terms.rbegin()) << '\n';
        // std::cout << "string left: " << str_in << '\n';
    }

    // std::cout << "Terms in string forms:\n";
    // process each terms: eg, 3.6 x ^ 4
    for (auto str_term: str_terms) {
        // std::cout << str_term << '\n';
        Coefficient c;
        Exponent e;
        if (str_term.find('x') == std::string::npos) {
            c = Coefficient(std::stod(str_term));
            e = Exponent(0);
        } else if (str_term.find('^') == std::string::npos) {
            c = Coefficient(std::stod(str_term.substr(0, str_term.length() - 1)));
            e = Exponent(1);
        } else {
            c = Coefficient(std::stod(str_term.substr(0, str_term.find('x'))));
            e = Exponent(std::stoi(str_term.substr(str_term.find('^') + 1, std::string::npos)));
        }
        poly.terms.push_back(new Term(c, e));
    }

    return in;
}