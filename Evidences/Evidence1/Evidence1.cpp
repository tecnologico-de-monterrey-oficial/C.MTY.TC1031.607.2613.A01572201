// Daniel Gómez Guerrero
// A01572201

#include "Log.h"

template <typename T>
void swapSort(vector<T> &list, long long &comparisons, long long &swaps) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            T a = list[i];
            T b = list[j];

            if (list[i] > list[j]) {
                list[i] = b;
                list[j] = a;
                swaps++;
            }

            comparisons++;
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &list, long long &comparisons, long long &swaps) {
    bool change = true;

    for (int i = list.size() - 1; i > 0 && change; i--) {
        change = false;

        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                change = true;
                swap(list[j], list[j + 1]);
                swaps++;
            }

            comparisons++;
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list, long long &comparisons, long long &swaps) {
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

            comparisons++;
        }

        // intercambiamos el valor de min por el valor de i
        // si min es diferente a i
        if (min != i) {
            swap(list[i], list[min]);
            swaps++;
        }
    }
}

template <typename T>
void insertionSort(vector<T> &list, long long &comparisons, long long &swaps) {
    // iteramos la lista desde la segunda posición hasta el final
    for (int i = 1; i < list.size(); i++) {

        // iteramos desde el índice i hasta 0
        for (int j = i; j > 0; j--) {
           //comparamos el valor de j contra j - 1
            if (list[j] < list[j - 1]) {
                // si es menor, 
                // los intercambiamos
                swap(list[j - 1], list[j]);
                swaps++;
            }

            comparisons++;
        }
    }
}

template <typename T>
int getPivot(vector<T> &sublist, int min, int max) {
    // pivot es el mismo valor que max

    // creamos una variable auxiliar con valor min - 1
    int aux = min - 1;

    // iteramos desde el inicio de la sublista hasta antes del pivot
    for (int index = min; index < max; index++) {
        // comparamos el valor en index con el que esta en el pivot
        if (sublist[index] <= sublist[max]) {
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

template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {
    // creamos una lista para los valores del lado izquierdo
    vector<T> leftList;
    // iteramos la lista de left hasta mid
    for (int i = left; i <= mid; i++) {
        leftList.push_back(list[i]);
    }

    // creamos una lista para los valores del lado derecho
    vector<T> rightList;
    // iteramos la lista de mid + 1 hasta right
    for (int j = mid + 1; j <= right; j++) {
        rightList.push_back(list[j]);
    }

    // combinamos las dos listas
    // creamos una variable index que contenga el indice a actualizar
    int index = left;
    // inicializamos el indice del lado izquierdo
    int i = 0;
    // inicializamos el indice del lado derecho
    int j = 0;

    // iteramos mientras no se acaben las listas
    while (i < leftList.size() && j < rightList.size()) {
        // comparamos el valor de i de la lista izquierda con el valor de j de la lista derecha
        if (leftList[i] < rightList[j]) {
            // actualizamos list en index con el valor de leftList en i
            list[index] = leftList[i];
            // incrementamos i
            i++;
        } else {
            // actualizamos list en index con el valor de rightList en j
            list[index] = rightList[j];
            // incrementamos j
            j++;
        }

        // incrementamos index
        index++;
    }

    // vaciamos la lista del lado izquierdo
    while (i < leftList.size()) {
        // actualizamos list en index con el valor de leftList en i
        list[index] = leftList[i];
        // incrementamos i
        i++;
        // incrementamos index
        index++;
    }

    // vaciamos la lista del lado derecho
    while (j < rightList.size()) {
        // actualizamos list en index con el valor de rightList en j
        list[index] = rightList[j];
        // incrementamos j
        j++;
        // incrementamos index
        index++;
    }
}

template <typename T>
void mergeSort(vector<T> &list, int left, int right) {
    // la condicion de control es left < right
    if (left < right) {
        // calculamos mid
        int mid = (left + right) / 2;

        // ordenamos de left a mid
        mergeSort(list, left, mid);

        // ordenamos de mid + 1 a right
        mergeSort(list, mid + 1, right);

        // combinamos las dos partes de la lista
        merge(list, left, mid, right);
    }
}

template <typename T>
void shellSort(vector<T> &list) {
     // obtenemos el tamaño de la lista y la mitad del tamaño
    int size = list.size();
    int half = size / 2;

    // iteramos mientras half sea mayor a 0
    while (half > 0) {
        // iteramos desde half hasta el final de la lista
        for (int i = half; i < size; i++) {
            // creamos una variable temporal con el valor de la posición i
            T temp = list[i];
            // creamos una variable auxiliar con el valor de i
            int aux = i;

            // iteramos mientras aux sea mayor o igual a half y 
            // el valor en la posición aux - half sea mayor que temp
            while (aux >= half && list[aux - half] > temp) {
                // actualizamos el valor en la posición aux con 
                // el valor en la posición aux - half
                list[aux] = list[aux - half];
                // decrementamos aux en half
                aux -= half;
            }

            // actualizamos el valor en la posición aux con temp
            list[aux] = temp;
        }

        // decrementamos half a la mitad
        half /= 2;
    }
}


int main() {

}
