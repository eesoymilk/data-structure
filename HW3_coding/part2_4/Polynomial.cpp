#include "Polynomial.h"

// class Term
// private:
//     double coef;
//     int exp;

// class Polynomial
// private:
//     CircularList<Term> poly;

Polynomial::Polynomial() {}

Polynomial::Polynomial(const Polynomial &a) {}

Polynomial::~Polynomial() {}

void Polynomial::NewTerm(double c, int e) {
  Node<Term> *now, *prev;
  if (poly.head->link == poly.head) {
  }
}

const Polynomial &Polynomial::operator=(const Polynomial &a) {}

const Polynomial Polynomial::operator+(const Polynomial &b) const {}

const Polynomial Polynomial::operator-(const Polynomial &b) const {}

const Polynomial Polynomial::operator*(const Polynomial &b) const {}

double Polynomial::Evaluate(double x) const {}

std::istream &operator>>(std::istream &in, Polynomial &p) {
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
    double c;
    int e;

    if (str_term.find('x') == std::string::npos) {
      // cannot find x: CONSTANT TERM, exponent == 0
      c = double(std::stod(str_term));
      e = int(0);
    } else if (str_term.find('^') == std::string::npos) {
      // cannot find ^: exponent == 1
      if (str_term[0] == 'x')
        c = 1;
      else if (str_term[0] == '-' && str_term[1] == 'x')
        c = -1;
      else
        c = double(std::stod(str_term.substr(0, str_term.length() - 1)));
      e = int(1);
    } else {
      if (str_term[0] == 'x')
        c = 1;
      else if (str_term[0] == '-' && str_term[1] == 'x')
        c = -1;
      else
        c = double(std::stod(str_term.substr(0, str_term.find('x'))));
      e = int(std::stoi(
          str_term.substr(str_term.find('^') + 1, std::string::npos)));
    }
    p.NewTerm(c, e);
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, Polynomial &p) {}
