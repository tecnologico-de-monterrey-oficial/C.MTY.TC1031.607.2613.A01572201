// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

template <typename T>
void print(vector<T> &list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

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

vector<int> genIntList(int size) {
    // creamos un vector
    vector<int> list;

    // iteramos desde 0 hasta size
    for (int i = 0; i < size; i++) {
        // generamos un valor aleatorio entre 0 y 100000
        int randomValue = rand() % 100000;
        // agregamos el valor aleatorio al vector
        list.push_back(randomValue);
    }

    // regresamos el vector
    return list;
}

vector<double> genDoubleList(int size) {
    // creamos un vector
    vector<double> list;

    // iteramos desde 0 hasta size
    for (int i = 0; i < size; i++) {
        // generamos un valor aleatorio entre 0 y 100000
        double randomValue = static_cast<double>(rand() % 100000) / 1000.0;
        // agregamos el valor aleatorio al vector
        list.push_back(randomValue);
    }

    // regresamos el vector
    return list;
}

vector<float> genFloatList(int size) {
    // creamos un vector
    vector<float> list;

    // iteramos desde 0 hasta size
    for (int i = 0; i < size; i++) {
        // generamos un valor aleatorio entre 0 y 100000
        float randomValue = static_cast<float>(rand() % 100000) / 100.0f;
        // agregamos el valor aleatorio al vector
        list.push_back(randomValue);
    }

    // regresamos el vector
    return list;
}

template <typename T>
vector<T> sortMenu(vector<T> &list, int option) {
    // creamos variables para contar comparaciones e intercambios
    long long comparisons = 0;
    long long swaps = 0;

    // iniciamos el reloj para medir el tiempo de ejecución
    auto start = chrono::high_resolution_clock::now();

    // seleccionamos el algoritmo de ordenamiento dependiendo en la opción del usuario
    switch (option) {
        case 1:
            swapSort(list, comparisons, swaps);
            break;
        case 2:
            bubbleSort(list, comparisons, swaps);
            break;
        case 3:
            selectionSort(list, comparisons, swaps);
            break;
        case 4:
            insertionSort(list, comparisons, swaps);
            break;
        case 5:
            quickSort(list, 0, list.size() - 1);
            break;
        case 6:
            mergeSort(list, 0, list.size() - 1);
            break;
        case 7:
            shellSort(list);
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }

    // detenemos el reloj y calculamos el tiempo de ejecución
    auto end = chrono::high_resolution_clock::now();
    // tiempo en nanosegundos
    long long tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Tiempo de ejecucion de vector " << list.size() << ": " << tiempo << " nanosegundos" << endl;

    // mostramos el número de comparaciones e intercambios si el algoritmo es uno de los primeros cuatro
    if (option >= 1 && option <= 4) {
        cout << "El numero de comparaciones es: " << comparisons << endl;
        cout << "El numero de intercambios es: " << swaps << endl;
    }

    return list;
}



int main() {
    srand(time(0));

    // Tests en Clase
    /*vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    cout << "Original: ";
    print(list);

    vector<int> list2 = list;
    vector<int> list3 = list;
    vector<int> list4 = list;
    vector<int> list5 = list;
    vector<int> list6 = list;
    vector<int> list7 = list;
   
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

    mergeSort(list6, 0, list6.size() - 1);
    cout << "Merge Sort: ";
    print(list6);

    shellSort(list7);
    cout << "Shell Sort: ";
    print(list7);*/

    cout << "Seleccione el algoritmo de ordenamiento:" << endl;
    cout << "1. Swap Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Insertion Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Merge Sort" << endl;
    cout << "7. Shell Sort" << endl;
    cout << "Opcion: ";
    int sortOption;
    cin >> sortOption;

    cout << "Seleccione el tipo de datos:" << endl;
    cout << "1. Int" << endl;
    cout << "2. Double" << endl;
    cout << "3. Float" << endl;
    cout << "Opcion: ";
    int dataType;
    cin >> dataType;

    switch (dataType) {
        case 1: {
            vector<int> intList1000 = genIntList(1000);
            sortMenu(intList1000, sortOption);
            // print(intList1000);

            vector<int> intList10000 = genIntList(10000);
            sortMenu(intList10000, sortOption);
            // print(intList10000);

            vector<int> intList100000 = genIntList(100000);
            sortMenu(intList100000, sortOption);
            // print(intList100000);

            break;
        }
        case 2: {
            vector<double> doubleList1000 = genDoubleList(1000);
            sortMenu(doubleList1000, sortOption);
            // print(doubleList1000);

            vector<double> doubleList10000 = genDoubleList(10000);
            sortMenu(doubleList10000, sortOption);
            // print(doubleList10000);

            vector<double> doubleList100000 = genDoubleList(100000);
            sortMenu(doubleList100000, sortOption);
            // print(doubleList100000);

            break;
        }
        case 3: {
            vector<float> floatList1000 = genFloatList(1000);
            sortMenu(floatList1000, sortOption);
            // print(floatList1000);

            vector<float> floatList10000 = genFloatList(10000);
            sortMenu(floatList10000, sortOption);
            // print(floatList10000);

            vector<float> floatList100000 = genFloatList(100000);
            sortMenu(floatList100000, sortOption);
            // print(floatList100000);

            break;
        }
        default:
            cout << "Opcion invalida." << endl;
            break;
    }

    return 0;
}