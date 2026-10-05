// Daniel Gómez Guerrero
// A01572201

#pragma once
#include <iostream>
using namespace std;

struct PaginaWeb {
    string titulo;
    string url;
    friend ostream& operator<<(ostream& os, const PaginaWeb& web) {
        os << web.titulo << " (" << web.url << ")";
        return os;
    }
};