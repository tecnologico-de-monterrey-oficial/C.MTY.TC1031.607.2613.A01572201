// Daniel Gómez Guerrero
// A01572201

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <typename T>
class LinkedList {
    private:
    //std::unique_ptr< Node<T> > head;
    Node<T>* head;
    int size;
    public:
    LinkedList() : head(nullptr), size(0) {}
    void push_front(T data);
    void push_back(T data);
    void print();
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    // crear un nodo nuevo
    //std::unique_ptr< Node<T> > node = std::make_unique< Node<T> >(data);
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    //node->next = std::move(head);
    node->next = head;
    // actualizo head
    //head = std::move(node);
    head = node;
};

template <typename T>
void LinkedList<T>::print() {
    // creamos un apuntador auxiliar que apunte a head
    //Node<T>* aux = head.get();
    Node<T>* aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        std::cout << aux->data;
        //aux = aux->next.get();
        aux = aux->next;
        if (aux != nullptr) {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
}

#endif /* LinkedList_h */