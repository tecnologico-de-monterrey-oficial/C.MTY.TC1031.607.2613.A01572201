// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> &list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <typename T>
void swapSort(vector<T> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            T a = list[i];
            T b = list[j];

            if (list[i] > list[j]) {
                list[i] = b;
                list[j] = a;
            }
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &list) {
    bool change = true;

    for (int i = list.size() - 1; i > 0 && change; i--) {
        change = false;

        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                change = true;
                swap(list[j], list[j + 1]);
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list) {
    // iteramos toda la lista, de principio a 1 antes del final
    for (int i = 0; i < list.size() - 1; i++) {
        // hacemos el índice de la posión i como el más chico
            int min = i;

        // iteramos desde el siguiente índice hasta el final
        for (int j = i + 1; j < list.size(); j++) {
            //comparamos el valor de j contra min
            if (list[j] < list[min]) {
                // si es menor, 
                // actualizamos el valor de min
                min = j;
            }
        }

        // intercambiamos el valor de min por el valor de i
        swap(list[i], list[min]);
    }
}

template <typename T>
void insertionSort(vector<T> &list) {
    // iteramos la lista desde la segunda posición hasta el final
    for (int i = 1; i < list.size(); i++) {

        // iteramos desde el índice i hasta 0
        for (int j = i; j > 0; j--) {

           //comparamos el valor de j contra j - 1
            if (list[j] < list[j - 1]) {
                // si es menor, 
                // los intercambiamos
                swap(list[j - 1], list[j]);
            }
        }
    }
}

template <typename T>
T part(vector<T> &sublist, int min, int max) {
    // pivot es igual al ultimo elemento de la sublista
    T pivot = sublist[max];
    // index es el limite de los elementos <= al pivot
    int index = min - 1;

    // iteramos desde el inicio de la sublista hasta antes del pivot
    for (int aux = min; aux < max; aux++) {
        // comparamos sublist[aux] con pivot
        if (sublist[aux] <= pivot) {
            // si es menor o igual,
            // index aumenta
            index++;
            // y el valor en aux se intercambia con el de index
            swap(sublist[aux], sublist[index]);
        }
    }

    // pivot se coloca en la posicion correcta
    swap(sublist[index + 1], sublist[max]);

    // retorna el indice de particion
    return index + 1;
}

template <typename T>
void quickSort(vector<T> &list, int min, int max) {
    if (min < max) {
        // se particiona el vector en sublistas
        int pivot = part(list, min, max);

        // se aplica recursivamente quickSort
        // en los elementos antes del pivot
        quickSort(list, min, pivot - 1);

        // se aplica recursivamente quickSort
        // en los elementos despues del pivot
        quickSort(list, pivot + 1, max);
    }
}

template <typename T>
void mergeSort(vector<T> &list) {
    
}

int main() {
    vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    cout << "Original: ";
    print(list);

    vector<int> list2 = list;
    //cout << "Original 2: ";
    //print(list2);

    vector<int> list3 = list;
    //cout << "Original 3: ";
    //print(list3);

    vector<int> list4 = list;
    //cout << "Original 4: ";
    //print(list4);

    vector<int> list5 = list;
    //cout << "Original 5: ";
    //print(list5);

    swapSort(list);
    cout << "Swap Sort: ";
    print(list);

    bubbleSort(list2);
    cout << "Bubble Sort: ";
    print(list2);

    selectionSort(list3);
    cout << "Selection Sort: ";
    print(list3);

    insertionSort(list4);
    cout << "Insertion Sort: ";
    print(list4);

    quickSort(list5, 0, list5.size() - 1);
    cout << "Quick Sort: ";
    print(list5);

    return 0;
}