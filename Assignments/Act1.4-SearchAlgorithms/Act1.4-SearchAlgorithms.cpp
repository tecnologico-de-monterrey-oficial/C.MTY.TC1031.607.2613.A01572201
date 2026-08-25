#include <iostream>
#include <vector>
using namespace std;

int sequentialSearch(vector<int> &list, int data) {
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
    vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};

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
    }

    return 0;
}