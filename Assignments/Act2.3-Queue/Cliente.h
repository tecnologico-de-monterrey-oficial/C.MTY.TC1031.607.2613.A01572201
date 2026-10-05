// Daniel Gómez Guerrero
// A01572201

#pragma once
#include <iostream>
using namespace std;

struct Cliente {
    string nombre;
    int boletos;
    friend ostream& operator<<(ostream& os, const Cliente& client) {
        os << client.nombre << " (" << client.boletos << " boleto(s))";
        return os;
    }
};