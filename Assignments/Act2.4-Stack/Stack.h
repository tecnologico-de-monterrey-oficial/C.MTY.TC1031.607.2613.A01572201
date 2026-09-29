// Daniel Gómez Guerrero
// A01572201

#ifndef Stack_h
#define Stack_h

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class Stack {
    private:
        Node<T>* head;
    public:
        Stack() : head(nullptr) {}
        void pop();
        void push(T data);
        void top();
        void print();
};

template <typename T>
void Stack<T>::pop() {
    // validamos que la lista no este vacia
    if (head != nullptr) {
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
void Stack<T>::push(T data) {
    // crear un nodo nuevo
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    node->next = head;
    // actualizo head
    head = node;
}

template <typename T>
void Stack<T>::top() {

}

template <typename T>
void Stack<T>::print() {
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


#endif /* Stack_h */