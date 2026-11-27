// Daniel Gómez Guerrero
// A01572201

#ifndef Heap_h
#define Heap_h

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T, typename Compare = less<T>> // less<T> para max heap, greater<T> para min heap
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
        T getData(int index) const { return heap.at(index); }
        vector<T> heapSort(vector<T>& list, Compare c = Compare());

        size_t getComparisons() const { return comparisons; }
        void resetComparisons() { comparisons = 0; }
        void print() const;
        void printTree(int index, int space) const;
};

// swap function to swap two elements in the heap
template <typename T, typename Compare>
void Heap<T, Compare>::swap(int a, int b) {
    T temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
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

// siftDown
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

// siftUp
template <typename T, typename Compare>
void Heap<T, Compare>::siftUp(int aux) {
    // iteramos mientras aux sea mayor a 0
    while (aux > 0) {
        // obtenemos el índice del padre
        int father = (aux - 1) / 2;
        // incrementamos el contador de comparaciones
        comparisons++;
        // comparamos si aux es mayor que su padre
        if (comp(heap[father], heap[aux])) {
            // aux es mayor que su padre
            swap(aux, father);
            // cambiamos el valor de aux igual a father
            aux = father;
        } else {
            aux = 0;
        }
    }
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
void Heap<T, Compare>::push(const T& data) {
    // agrego el elemento al final de la lista
    heap.push_back(data);
    // llamo a siftUp para mantener la propiedad del heap
    siftUp(static_cast<int>(heap.size()) - 1);
}

template <typename T, typename Compare>
const T& Heap<T, Compare>::top() const {
    if (!heap.empty()) {
        // retornamos el primer elemento del heap
        return heap[0];
    }
    throw std::out_of_range("Heap is empty");
}

template <typename T, typename Compare>
int Heap<T, Compare>::height() const {
    if (heap.empty()) {
        return -1;
    }
    // inicializamos la altura en 0 y el índice en 0
    int h = 0;
    int index = 0;
    // iteramos mientras el índice del hijo izquierdo sea menor al tamaño del heap
    while (2 * index + 1 < static_cast<int>(heap.size())) {
        // incrementamos la altura
        h++;
        // actualizamos el índice al hijo izquierdo
        index = 2 * index + 1;
    }
    // retornamos la altura
    return h;
}

// heapSort (less<T> de menor a mayor, greater<T> de mayor a menor)
template <typename T, typename Compare>
vector<T> Heap<T, Compare>::heapSort(vector<T>& list, Compare c) {
    // creamos un heap con la lista y el comparador dado
    Heap<T, Compare> heap(list, c);
    // iteramos desde el final de la lista hasta el inicio
    for (int i = static_cast<int>(list.size()) - 1; i >= 0; i--) {
        // asignamos el valor del pop del heap a la posición actual de la lista
        list[i] = heap.pop();
    }
    return list;
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