// Daniel Gómez Guerrero
// A01572201

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"

template <typename T>
class DoublyLinkedList {
    private:
        NodeD<T>* head;
        NodeD<T>* tail;
        int size = 0;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
        void addFirst(T data);
        void addLast(T data);
};

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    // validamos si la lista esta vacia
    if (head == nullptr) {
        // si esta vacia la lista
        // apunto head a un nuevo nodo con data
        head = new NodeD<T>(data);
        // apunto tail a head
        tail = head;
        // incremento size
        size++;
    } else {
        // la lista no esta vacia
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el next de aux a head
        aux->next = head;
        // apuntamos el prev de head a aux
        head->prev = aux;
        // apuntamos head a aux
        head = aux;
        // incrementamos size
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // validamos si la lista esta vacia
    if (head == nullptr) {
        // si esta vacia la lista
        // apunto head a un nuevo nodo con data
        head = new NodeD<T>(data);
        // apunto tail a head
        tail = head;
        // incremento size
        size++;
    } else {
        // la lista no esta vacia
        // creamos un nuevo nodo
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el prev de aux a tail
        aux->prev = tail;
        // apuntamos el next de tail a aux
        tail->next = aux;
        // apuntamos tail a aux
        tail = aux;
        // incrementamos size
        size++;
    }
}


#endif /* DoublyLinkedList_h */