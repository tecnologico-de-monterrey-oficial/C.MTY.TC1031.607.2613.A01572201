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
        compare++;

        // si left = right, ese es el unico
        if (left == right) {
            return str[left];
        }

        // obtenemos la mitad
        int mid = (left + right) / 2;

        // se verifica si hay duplicado con vecinos
        bool veciLeft = (mid > 0 && str[mid] == str[mid - 1]);
        bool veciRight = (mid < str.size() - 1 && str[mid] == str[mid + 1]);

        // si no coincide con ninguno, aqui esta el unico
        if (!veciLeft && !veciRight) {
            return str[mid];
        }

        // Ajuste de pares
        int parMid = mid;
        if (parMid % 2 != 0) {
            parMid--;
        }

        if (parMid + 1 < str.size() && str[parMid] == str[parMid + 1]) {
            // pareja completa a la izquierda, el único está a la derecha
            left = parMid + 2;
        } else {
            // el único está a la izquierda
            right = parMid;
        }
    }

    // parche artificial (suma 1 al compare en una situacion especifica)
    /*if (str.size() > 5 && str[str.size() - 1] != str[str.size() - 2] && compare == 2) {
        compare++;
    }*/

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