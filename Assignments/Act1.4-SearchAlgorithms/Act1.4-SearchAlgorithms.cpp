// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename T>
int sequentialSearch(vector<T> &list, T data) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }

    // no se encontro
    throw out_of_range("No se encontro el valor");
}

template <typename T>
int binarySearch(vector<T> &list, T data) {
    // obtenemos left
    int left = 0;

    // obtenemos right
    int right = list.size() - 1;

    // buscamos el elemento mientras left <= right
    while (left <= right) {
        // obtenemos la mitad
        int mid = (left + right) / 2;

        // comparamos el valor buscando con el valor de la mitad
        if (data == list[mid]) {
            // regresamos el valor de mid que es el indice del valor encontrado
            return mid;
        } else {
            // preguntamos si el valor buscado es menor que el valor mid
            if (data < list[mid]) {
                // si es menor
                right = mid - 1;
            } else {
                // si es mayor
                left = mid + 1;
            }
            // data < list[mid] ? right = mid - 1 : left = mid + 1;
        }
    }

    // no se encontro
    throw out_of_range("No se encontro el valor");
}

int main() {
    //Test de Clase
    /*vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};

     try {
    int index = sequentialSearch(list, 13);
    cout << "El valor esta en: " << index << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }

    try {
    int index = binarySearch(list, 14);
    cout << "El valor esta en: " << index << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }*/

    // Problema 1
    cout << "------------ Problema 1 ------------" << endl;
    srand(time(0));

    vector<int> list1;

    for (int i = 0; i < 10000; i++) {
        int randomNumber = rand() % 1000000 + 1; //+1 para evitar 0
        list1.push_back(randomNumber);
    }

    sort(list1.begin(), list1.end());

    int select = 1;
    while (select != 0) {
        cout << "Introduzca un valor entero entre 1 y 1,000,000 (inserte 0 para terminar): ";
        cin >> select;

        if (select == 0) {
            break;
        }

        // busqueda secuencial
         clock_t startSecuencial = clock();
        try {
            int index = sequentialSearch(list1, select);
            cout << "El valor esta en: " << index << endl;
        } catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
        clock_t endSecuencial = clock();

        double tiempoSecuencial = (double)(endSecuencial - startSecuencial) / CLOCKS_PER_SEC;
        cout << "La busqueda secuencial tardo: " << tiempoSecuencial << " segundos" << endl;

        // busqueda binaria
        clock_t startBinario = clock();
        try {
            int index = binarySearch(list1, select);
            cout << "El valor esta en: " << index << endl;
        } catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
        clock_t endBinario = clock();

        double tiempoBinario = (double)(endBinario - startBinario) / CLOCKS_PER_SEC;
        cout << "La busqueda binaria tardo: " << tiempoBinario << " segundos" << endl;
    }

    return 0;
}