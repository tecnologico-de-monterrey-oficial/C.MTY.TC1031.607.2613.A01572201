// Daniel Gómez Guerrero
// A01572201

#ifndef SondeoLineal_h
#define SondeoLineal_h

#include <iostream>
using namespace std;

template <typename T>
class SondeoLineal {
    private:
        int m;
    public:
        vector<vector<int>> table;
        void insert(T data);
        void search(T data);
        void remove(T data);
        int hashFunction(int a);
};

template <typename T>
int SondeoLineal<T>::hashFunction(int a) {
    return (a % m);
}

template <typename T>
void SondeoLineal<T>::insert(T data) {
    // obtiene el indice de la llave
    int index = hashFunction(data);
    // pone la llave en el indice establecido
    table[index].push_back(data);
}

template <typename T>
void SondeoLineal<T>::search(T data) {
    // obtiene el indice de la llave
    int index = hashFunction(data);
    // busca la llave en el indice establecido
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == data) {
            return table[index][i];
        }
    }
    // si no se encuentra, lanza una excepción
    throw "Element not found";
}

template <typename T>
void SondeoLineal<T>::remove(T data) {
    // obtiene el indice de la llave
    int index = hashFunction(data);
    // busca la llave en el indice establecido
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == data) {
            // si se encuentra, la elimina
            table[index].erase(table[index].begin() + i);
            return;
        }
    }
    // si no se encuentra, lanza una excepción
    throw "Element not found";
}



#endif /* SondeoLineal_h */