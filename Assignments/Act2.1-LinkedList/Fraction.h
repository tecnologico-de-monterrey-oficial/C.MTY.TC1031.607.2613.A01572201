// Daniel Gómez Guerrero
// A01572201

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

#endif // FRACTION_H