// Daniel Gómez Guerrero
// A01572201

#include "Log.h"
#include <vector>
#include <iostream>

template <typename T>
int getPivot(vector<T> &sublist, int min, int max) {
    // pivot es el mismo valor que max

    // creamos una variable auxiliar con valor min - 1
    int aux = min - 1;

    // iteramos desde el inicio de la sublista hasta antes del pivot
    for (int index = min; index < max; index++) {
        // comparamos el valor en index con el que esta en el pivot
        if (sublist[index] <= sublist[max]) { // esta parte es esencial para la evidencia
            // aux aumenta
            aux++;
            // se intercambia el valor en aux con el que esta en index
            swap(sublist[aux], sublist[index]);
        }
    }

    // aux incrementa
    aux++;

    // se intercambia el valor en aux con el que esta en el pivot
    swap(sublist[aux], sublist[max]);

    // se regresa aux
    return aux;
}

template <typename T>
void quickSort(vector<T> &list, int min, int max) {
    // la condicion de control es min < max
    if (min < max) {
        // se particiona el vector en sublistas
        int pivot = getPivot(list, min, max);

        // ordenamos la lista antes del pivote
        quickSort(list, min, pivot - 1);

        // ordenamos la lista despues del pivote
        quickSort(list, pivot + 1, max);
    }
}

int main() {

}
