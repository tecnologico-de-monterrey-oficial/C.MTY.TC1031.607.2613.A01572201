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
    void insert(int index, T data);
    void deleteData(T data);
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    // crear un nodo nuevo
    // std::unique_ptr< Node<T> > node = std::make_unique< Node<T> >(data);
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    // node->next = std::move(head);
    node->next = head;
    // actualizo head
    // head = std::move(node);
    head = node;
};

template <typename T>
void LinkedList<T>::print() {
    // creamos un apuntador auxiliar que apunte a head
    // Node<T>* aux = head.get();
    Node<T>* aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        std::cout << aux->data;
        // aux = aux->next.get();
        aux = aux->next;
        if (aux != nullptr) {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    // validamos si la lista esta vacia
    if (head != nullptr) {
        // la lista no esta vacía
        // creamos un apuntador auxiliar que apunte a head
        Node<T>* aux = head;
        // recorremos la lista mientras aux->next sea diferente de nullptr
        while (aux->next != nullptr) {
            // recorremos aux a aux->next
            aux = aux->next;
        }
        // agregamos el nodo despues de aux
        aux->next = new Node<T>(data);
    } else {
        // la lista esta vacia
        head = new Node<T>(data);
    }
    // incrementamos size
    size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
    // validamos que la posicion exista
    if (index >= 0 && index < size) {
        // creamos un indice auxiliar
        int auxIndex = 0;
        // creamos un nodo auxiliar
        Node<T>* aux = head;
        // recorremos la lista hasta encontrar la posicion donde vamos a hacer el insert
        while (auxIndex < index) {
            // recorremos aux
            aux = aux->next;
            // incrementamos el indice auxiliar
            auxIndex++;
        }
        // insertamos el nuevo nodo
        aux->next = new Node<T>(data, aux->next);
        // incrementamos size
        size++;
    } else {
        // error
        throw out_of_range("La posicion no existe en la lista")
    }
}

    // si la lista esta vacia
    // si la lista no tiene elemento x
    // si quiero eliminar primer elemento
    // si quiero eliminar cualquier otro elem
template <typename T>
void LinkedList<T>::deleteData(T data) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // la lista no esta vacia
        // valido si el primer elemento es el que quiero borrar
        if (head->data == data) {
            // quiero borrar el primer elemento
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // recorremos head a head->next
            head = head->next;
            // borramos el primer elemento
            delete aux;
            // decrementamos sixe
            size--;
        } else {
            // creamos un elemento auxPrev igual a head
            Node<T>* auxPrev = head;
            // creamos un elemento aux igual a head->next
            Node<T>* aux = head->next;
            // recorremos la lista
            while (aux != nullptr) {
                // validamos si el valor de aux es el que quiero borrar
                if (aux->data == data) {
                    //
                    auxPrev->next = aux->next;
                    // borro aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // return
                }
                // recorrer los apuntadores
                auxPrev = aux;
                aux = aux->next;
            }
            // no lo encontre
            throw out_of_range("No se encontro el dato a borrar")
        } else {
            throw out_of_range("La lista esta vacia")
        }
    }
}


#endif /* LinkedList_h */