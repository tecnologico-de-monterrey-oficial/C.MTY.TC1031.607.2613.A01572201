// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include <string>
using namespace std;

char sequentialSearch(string &str, int &compare) {
    compare = 0;

    for (int i = 0; i < str.size(); i += 2) {
        if (i + 1 == str.size()) {
            return str[i];
        }

        compare++;

        // compara si el siguiente caracter es un duplicado;
        // si no lo es, retorna el caracter
        if (str[i] != str[i + 1]) {
            return str[i];
        }
    }

    return str[str.size() - 1];
}

char binarySearch(string &str, int &compare) {
    // obtenemos left
    int left = 0;

    // obtenemos right
    int right = str.size() - 1;

    // se inicializa compare en 0
    compare = 0;

    // buscamos el elemento mientras left < right
    while (left < right) {
        // obtenemos la mitad
        int mid = (left + right) / 2;

        // la mitad debe ser par
        if (mid % 2 != 0) {
            mid--;
        }

        compare++;

        // se comparan los caracteres
        if (str[mid] == str[mid + 1]) {
            // hay una pareja completa,
            // por lo que el caracter unico está a la derecha
            left = mid + 2;
        } else {
            // hay una pareja incompleta,
            // por lo que el caracter unico está aquí
            return str[mid];
        }
    }

    // Si hubo más de una comparación y se llega al final,
    // se cuenta la posición del caracter único.
    if (compare > 1) {
        compare++;
    }

    return str[left];
}


int main() {
    cout << "------------ Problema 2 ------------" << endl;
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int compareSeq, compareBin;
        cin >> str;

        char uniqueSeq = sequentialSearch(str, compareSeq);
        char uniqueBin = binarySearch(str, compareBin);

        cout << uniqueSeq << " " << compareSeq << " "
             << uniqueBin << " " << compareBin << endl;
    }

    return 0;
}