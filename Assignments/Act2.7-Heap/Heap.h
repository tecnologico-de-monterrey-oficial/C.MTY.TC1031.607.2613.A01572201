// Daniel Gómez Guerrero
// A01572201

#ifndef Heap_h
#define Heap_h

template <typename T>
class Heap {
    private:
        vector<T> heap;
    public:
        Heap();
        void push(T data);
        void print();
};

template <typename T>
void Heap<T>::push(T data) {
    // agrego el elemento al final de la lista
    heap.push_back(data);
    // determino el indice del elemento agregado
    int index = heap.size() - 1;
    // itero mientras que el indice del elemento agregado sea mayor que 0
    while (index > 0) {
        // determino el indice del padre
        int parentIndex = (index - 1) / 2;
        // comparo el elemento agregado con su padre
        if (heap[index] > heap[parentIndex]) {
            // intercambio el elemento agregado con su padre
            swap(heap[index], heap[parentIndex]);
            // actualizo el indice del elemento agregado
            index = parentIndex;
        } else {
            // si el elemento agregado es menor o igual que su padre, salgo del ciclo
            break;
        }
    }
}

#endif // Heap_h