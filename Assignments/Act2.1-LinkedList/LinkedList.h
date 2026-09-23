// Daniel Gómez Guerrero
// A01572201

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <typename T>
class LinkedList {
    private:
    std::unique_ptr< Node<T> > head;
    int size;
    public:
    LinkedList() : head(nullptr), size(0) {}
    void prepend(T data);
    void print();
}

template <typename T>
void LinkedList<T>::push_front(T data) {
    // crear un nodo nuevo
    std::unique_ptr< Node<T> > node = make_unique< Node<T> >(data);
    // actualizo el next del nodo nuevo para que apunte a head
    node->next = std::move(head);
    // actualizo head
    head = std::move(node);
};

template <typename T>
void LinkedList<T>::print() {
    // creamos un apuntador auxiliar que apunte a head
    Node<T> aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        std::cout << aux->data;
        aux = aux->next.get();
        if (aux != nullptr) {
            cout << "-";
        }
    }
    std::cout << std::endl;
}

#endif /* LinkedList_h */