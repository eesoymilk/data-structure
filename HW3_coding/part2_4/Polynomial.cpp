#include "Polynomial.h"

#include <iostream>

Polynomial::Polynomial() {}

Polynomial::Polynomial(const Polynomial& a) {}

Polynomial::~Polynomial() {}

const Polynomial& Polynomial::operator=(const Polynomial& a) {}

const Polynomial Polynomial::operator+(const Polynomial& b) const {}

const Polynomial Polynomial::operator-(const Polynomial& b) const {}

const Polynomial Polynomial::operator*(const Polynomial& b) const {}

double Polynomial::Evaluate(double x) const {}

std::istream& operator>>(std::istream& in, Polynomial& p) {}

std::ostream& operator<<(std::ostream& out, Polynomial& p) {}
