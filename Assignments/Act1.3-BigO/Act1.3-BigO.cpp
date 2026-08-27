#include <iostream>
#include <vector>
using namespace std;

// El orden de esta función es O(n)
int sumaImparIterativa(vector<int> &lista) {
    int sum = 0;

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i] % 2 != 0) {
            sum += lista[i];
        }
    }

    return sum;
}

// El orden de esta función es O(n)
int sumaImparRecursiva(vector<int> &lista, int n) {
    // n = indice
    if (n == lista.size()) {
        return 0;
    }

    if (lista[n] % 2 != 0) {
        return lista[n] + sumaImparRecursiva(lista, n + 1);
    }

    return sumaImparRecursiva(lista, n + 1);
}

int main() {
    vector<int> lista = {1, 2, 3, 4, 5, 6};

    cout << "La suma iterativa de impares es: " << sumaImparIterativa(lista) << endl;

    cout << "La suma recursiva de impares es: " << sumaImparRecursiva(lista, 0) << endl;

    return 0;
}

