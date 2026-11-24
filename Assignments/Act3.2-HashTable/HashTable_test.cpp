// Daniel Gómez Guerrero
// A01572201

#include "Encadenamiento.h"
#include "SondeoLineal.h"

int main() {
    vector<int> list = {15, 25, 35, 45, 55, 65, 75, 85, 95, 105};
    Encadenamiento<int> encadenamiento;
    //encadenamiento.m = 10;
    for (int x : list) {
        encadenamiento.insert(x);
    }
}