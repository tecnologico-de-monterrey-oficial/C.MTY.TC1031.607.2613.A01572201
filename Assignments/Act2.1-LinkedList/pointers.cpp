// Daniel Gómez Guerrero
// A01572201

#include <iostream>
using namespace std;

#include "Fraction.h"

int main() {
    int x = 42;
    int* p = &x;

    cout << x << endl;
    cout << &x << endl;
    cout << p << endl;
    cout << *p << endl;

    cout << "Valores de q" << endl;
    int* q = new int(5);
    cout << q << endl;
    cout << *q << endl;

    delete q;
    cout << q << endl;
    cout << *q << endl;

    Fraction* f = new Fraction(2, 3);

    f->print();
    cout << f->getNumerator() << "/" << f->getDenominator() << endl;
    delete f;
    f = nullptr;

    auto g = make_unique<Fraction>(3, 4);
    g->print();
    cout << g->getNumerator() << "/" << g->getDenominator() << endl;

    return 0;
}