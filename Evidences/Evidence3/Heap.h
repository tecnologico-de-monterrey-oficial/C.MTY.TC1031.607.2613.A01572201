// Daniel Gómez Guerrero
// A01572201

#ifndef Heap_h
#define Heap_h

#include <vector>
#include <iostream>
using namespace std;

template <typename T, typename Compare = std::less<T>>
class Heap {
    private:
        vector<T> heap;
        Compare comp;
        size_t comparisons;

        void swap(int a, int b);
        void siftDown(int aux);
        void siftUp(int aux);
        
    public:
        Heap(Compare c = Compare()) : comp(c), comparisons(0) {};
        Heap(const vector<T>& list, Compare c = Compare());

        void push(const T& data);
        T pop();
        const T& top() const;
        bool empty() const { return heap.empty(); }
        size_t size() const { return heap.size(); }
        int height() const;

        void print() const;
        void printTree(int index, int space) const;
};

// shiftDown
template <typename T, typename Compare>
void Heap<T, Compare>::siftDown(int aux) {
    // obtenemos el tamaño del heap
    int n = static_cast<int>(heap.size());
    // obtenemos el ultimo parent
    int lastParent = n / 2 - 1;
    // iteramos mientras los hijos de aux sean padres
    while (aux <= lastParent) {
        // calculamos el índice de primer hijo
        int first = aux * 2 + 1;
        // validar si aux tiene 2 hijos o 1 hijo
        // definimos una varibale para determinar cual hijo es mayor
        int elder;
        if (first == n - 1) {
            // tiene un hijo
            elder = first;
        } else {
            // tiene dos hijos
            // calculamos el 2do hijo
            int second = aux * 2 + 2;
            // incrementamos el contador de comparaciones
            comparisons++;
            // validamos cual es que tiene mayor prioridad
            elder = comp(heap[first], heap[second]) ? second : first;
        }
        // incrementamos el contador de comparaciones
        comparisons++;
        // comparamos si el más grande de los hijos es mayor a aux
        if (comp(heap[aux], heap[elder])) {
            // el mayor de los hijos es de mayor priodidad que el padre
            swap(aux, elder);
            // cambiamos el valor de aux igual a elder
            aux = elder;
        } else {
            aux = lastParent + 1;
        }
    }
}

// constructor en base a una lista
template <typename T, typename Compare>
Heap<T, Compare>::Heap(const vector<T>& list, Compare c) : heap(list), comp(c), comparisons(0) {
    // determinar cual es el último de los padres
    int lastParent = static_cast<int>(heap.size()) / 2 - 1;
    // iteramos desde el último de los padres hasta el primero
    int parent = lastParent;
    while (parent >= 0) {
        siftDown(parent);
        // decrementamos el valor del indice del padre actual
        parent--;
    }
}

// swap function to swap two elements in the heap
template <typename T, typename Compare>
void Heap<T, Compare>::swap(int a, int b) {
    T temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

template <typename T, typename Compare>
T Heap<T, Compare>::pop() {
    if (!heap.empty()) {
        T data = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
        return data;
    }
    throw std::out_of_range("Heap is empty");
}

template <typename T, typename Compare>
void Heap<T, Compare>::push(T data) {
    // agrego el elemento al final de la lista
    heap.push_back(data);
    // determino el indice del elemento agregado
    int index = heap.size() - 1;
    // determino el indice del padre
    int father = (index - 1) / 2;
    // itero mientras el índice del padre sea mayor o igual a 0
    while (father >= 0) {
        // comparo si el valor del indice es mayor al valor del padre
        if (heap[index] > heap[father]) {
            // si es mayor
            // intercambio los valores
            swap(index, father);
            // hago que el indice sea igual al padre
            index = father;
            // calculo el nuevo padre
            father = (index - 1) / 2;
        } else {
            // no es mayor
            // me salgo de la función
            return;
        }
    }
}

// print function to print the elements of the heap
template <typename T, typename Compare>
void Heap<T, Compare>::print() const {
    for (size_t i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// print del tree
template <typename T, typename Compare>
void Heap<T, Compare>::printTree(int index, int space) const {
    if (index >= static_cast<int>(heap.size())) {
        return;
    }
    space += 5;
    printTree(2 * index + 2, space);
    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << heap[index] << "\n";
    printTree(2 * index + 1, space);
}

#endif // Heap_h