// Daniel Gómez Guerrero
// A01572201

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        Queue() : head(nullptr), tail(nullptr) {}
        void pop();
        void push(T data);
        void front();
        void print();
};

template <typename T>
void Queue<T>::pop() {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // validamos si solo hay un elemento
        if (head == tail) {
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // borramos aux
            delete aux;
            // inicializamos head y tail
            head = nullptr;
            tail = nullptr;
        }
        // creamos un elemento aux igual a head
        Node<T>* aux = head;
        // recorremos head a head->next
        head = head->next;
        // borramos el primer elemento
        delete aux;
    } else {
        throw out_of_range("La lista esta vacia")
    }
}

template <typename T>
void Queue<T>::push(T data) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // actualizamos el next de tail con un nodo nuevo
        tail->next = new Node<T>(data);
        // actualizamos tail con tail->next
        tail = tail->next;
    } else {
        // apunto head a un nuevo nodo
        head = new Node<T>(data);
        // apunto tail a head;
        tail = head;
    }
}

template <typename T>
void Queue<T>::front() {
    // validamos si la lista esta vacia
    if (head != nullptr) {
        // regresa el primer valor
        return ;
    }
}

template <typename T>
void Queue<T>::print() {
    // creamos un apuntador auxiliar que apunte a head
    Node<T>* aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) {
            cout << "-";
        }
    }
    cout << endl;
}

#endif /* Queue_h */