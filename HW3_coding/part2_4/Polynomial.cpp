#include "Polynomial.h"

// class Node
//     T data;
//     Node<T> *link = nullptr;

// class CircularList
//     Node<T> *head = new Node<T>(), *last = head;

// class Term
//     double coef;
//     int exp;

// class Polynomial
//     CircularList<Term> poly;

Polynomial::Polynomial() {}

Polynomial::Polynomial(const Polynomial &a) : poly(a.poly) {}

Polynomial::~Polynomial() {}

void Polynomial::NewTerm(double c, int e)
{
    Node<Term> *now = poly.head->link, *prev = nullptr;
    Node<Term> *new_node = CircularList<Term>::GetNode();
    new_node->data = Term(c, e);
    if (now == poly.head) {
        new_node->link = poly.head;
        poly.last = poly.head->link = new_node;
        return;
    }

    if (now->data.exp <= e) {
        new_node->link = poly.head->link;
        poly.head->link = new_node;
        return;
    }

    while (now != poly.head && now->data.exp > e) {
        prev = now;
        now = now->link;
    }
    if (now != poly.head && now->data.exp == e) {
        now->data.coef += c;
        return;
    }
    new_node->link = now;
    prev->link = new_node;
}

Polynomial &Polynomial::operator=(const Polynomial &a)
{
    poly = a.poly;
    return *this;
}

const Polynomial Polynomial::operator+(const Polynomial &b) const
{
    Polynomial res;
    Node<Term> *lhs_now = poly.head->link, *rhs_now = b.poly.head->link;
    while (true) {
        bool done = true;
        if (lhs_now != poly.head) {
            res.NewTerm(lhs_now->data.coef, lhs_now->data.exp);
            lhs_now = lhs_now->link;
            done = false;
        }
        if (rhs_now != b.poly.head) {
            res.NewTerm(rhs_now->data.coef, rhs_now->data.exp);
            rhs_now = rhs_now->link;
            done = false;
        }
        if (done) break;
    }
    return res;
}

const Polynomial Polynomial::operator-(const Polynomial &b) const
{
    Polynomial res;
    Node<Term> *lhs_now = poly.head->link, *rhs_now = b.poly.head->link;
    while (true) {
        bool done = true;
        if (lhs_now != poly.head) {
            res.NewTerm(lhs_now->data.coef, lhs_now->data.exp);
            lhs_now = lhs_now->link;
            done = false;
        }
        if (rhs_now != b.poly.head) {
            res.NewTerm(-rhs_now->data.coef, rhs_now->data.exp);
            rhs_now = rhs_now->link;
            done = false;
        }
        if (done) break;
    }
    return res;
}

const Polynomial Polynomial::operator*(const Polynomial &b) const
{
    Polynomial res;
    Node<Term> *lhs_now = poly.head->link;
    for (; lhs_now != poly.head; lhs_now->link) {
        Node<Term> *rhs_now = b.poly.head->link;
        for (; rhs_now != b.poly.head; rhs_now = rhs_now->link)
            res.NewTerm(lhs_now->data.coef * rhs_now->data.coef,
                        lhs_now->data.exp + rhs_now->data.exp);
    }
    return res;
}

double Polynomial::Evaluate(double x) const
{
    double res = 0;
    Node<Term> *now = poly.head->link;
    for (; now != poly.head; now = now->link) {
        auto [c, e] = std::make_pair(now->data.coef, now->data.exp);
        res += c * pow(x, e);
    }
    return res;
}

std::istream &operator>>(std::istream &in, Polynomial &p)
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
        // std::cout << str_term << ' ';
        int idx;
        double c;
        int e;

        if (str_term.find('x') == std::string::npos) {
            // cannot find x: CONSTANT TERM, exponent == 0
            c = std::stod(str_term);
            e = 0;
        } else if (str_term.find('^') == std::string::npos) {
            // cannot find ^: exponent == 1
            e = 1;
            if (str_term[0] == '-' && str_term[1] == 'x') c = -1;
            else c = std::stod(str_term.substr(0, str_term.length() - 1));
        } else {
            if (str_term[0] == 'x') c = 1;
            else if (str_term[0] == '-' && str_term[1] == 'x') c = -1;
            else c = double(std::stod(str_term.substr(0, str_term.find('x'))));
            e = std::stoi(
                str_term.substr(str_term.find('^') + 1, std::string::npos));
        }
        p.NewTerm(c, e);
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, Polynomial &p)
{
    // auto [c, e] = std::make_pair(now->data.coef, now->data.exp);
    for (Node<Term> *now = p.poly.head->link; now != p.poly.head;
         now = now->link)
        out << '(' << now->data.coef << ", " << now->data.exp << ')'
            << " \n"[now->link == p.poly.head ? 1 : 0];
    return out;
}
