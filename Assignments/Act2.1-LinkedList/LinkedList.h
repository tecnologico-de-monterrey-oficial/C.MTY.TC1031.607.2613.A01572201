// Daniel Gómez Guerrero
// A01572201

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <iostream>
using namespace std;

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
        void deletaAt(int index);
        T getData(int index);
        void updateData(T data, T newData);
        void updateAt(int index, T newData);
        int findData(T data);
        T& operator[](int index);
        LinkedList& operator=(const LinkedList<T> &other);
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
            // return
            return;
        } else {
            // creamos un elemento auxPrev igual a head
            Node<T>* auxPrev = head;
            // creamos un elemento aux igual a head->next
            Node<T>* aux = head->next;
            // recorremos la lista
            while (aux != nullptr) {
                // validamos si el valor de aux es el que quiero borrar
                if (aux->data == data) {
                    // recorremos auxPrev->next a aux->next
                    auxPrev->next = aux->next;
                    // borro aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // return
                    return;
                }
                // recorrer los apuntadores
                auxPrev = aux;
                aux = aux->next;
            }
            // no lo encontre
            throw out_of_range("No se encontro el dato a borrar");
        } 
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
void LinkedList<T>::deletaAt(int index) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // validamos que la posicion exista
        if (index >= 0 && index < size) {
            // valido si el primer elemento es el que quiero borrar
            if (index == 0) {
                // quiero borrar el primer elemento
                // creamos un elemento aux igual a head
                Node<T>* aux = head;
                // recorremos head a head->next
                head = head->next;
                // borramos el primer elemento
                delete aux;
                // decrementamos sixe
                size--;
                // return
                return;
            } else {
                 // creamos un elemento auxPrev igual a head
                Node<T>* auxPrev = head;
                // recorremos hasta llegar al nodo anterior al que queremos borrar
                for (int i = 0; i < index - 1; i++) {
                    auxPrev = auxPrev->next;
                }
                // creamos un elemento aux igual a auxPrev->next
                Node<T>* aux = auxPrev->next;
                // recorremos auxPrev->next a aux->next
                auxPrev->next = aux->next;
                 // borramos aux
                delete aux;
                // decrementamos sixe
                size--;
                // return
                return;
            }
        } else {
            // error
            throw out_of_range("La posicion no existe en la lista");
        }
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
T LinkedList<T>::getData(int index) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // validamos que la posicion exista
        if (index >= 0 && index < size) {
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // recorremos hasta llegar al nodo que se desea consultar
            for (int i = 0; i < index; i++) {
                aux = aux->next;
            }
            return aux->data;
        } else {
            // error
            throw out_of_range("La posicion no existe en la lista"); 
        }
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
void LinkedList<T>::updateData(T data, T newData) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // la lista no esta vacia
        // valido si el primer elemento es el que quiero actualizar
        if (head->data == data) {
            // quiero actualizar el primer elemento
            head->data = newData;
        } else {
            // creamos un elemento aux igual a head->next
            Node<T>* aux = head->next;
            // recorremos la lista buscando el dato
            while (aux != nullptr) {
                // validamos si el valor de aux es el que quiero actualizar
                if (aux->data == data) {
                    // actualizamos el valor de aux
                    aux->data = newData;
                    // return
                    return;
                }
                // recorremos aux
                aux = aux->next;
            }
            // no lo encontre
            throw out_of_range("No se encontro el dato a actualizar");
        }
    } else {
        throw out_of_range("La lista esta vacia");
    }
};

template <typename T>
void LinkedList<T>::updateAt(int index, T newData) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // validamos que la posicion exista
        if (index >= 0 && index < size) {
            // valido si el primer elemento es el que quiero actualizar
            if (index == 0) {
                // quiero actualizar el primer elemento
                head->data = newData;
                // return
                return;
            } else {
                 // creamos un elemento aux igual a head->next
                Node<T>* aux = head->next;
                // recorremos hasta llegar al nodo al que queremos actualizar
                for (int i = 0; i < index - 1; i++) {
                    // recorremos aux
                    aux = aux->next;
                }
                // actualizamos aux
                aux->data = newData;
                // return
                return;
            }
        } else {
            // error
            throw out_of_range("La posicion no existe en la lista");
        }
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
int LinkedList<T>::findData(T data) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // creamos un elemento aux igual a head
        Node<T>* aux = head;
        // creamos un indice
        int index = 0;
        // recorremos hasta llegar al nodo con el dato deseado
        while (aux != nullptr) {
            // validamos si el valor de aux es el que quiero encontrar
            if (aux->data == data) {
                // return index
                return index;
            }
            // recorremos aux
            aux = aux->next;
            // incrementamos index
            index++;
        }
        // no lo encontre
        // throw out_of_range("No se encontro el dato en la lista");
        return -1;
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    // validamos que la lista no este vacia
    if (head != nullptr) {
        // validamos que la posicion exista
        if (index >= 0 && index < size) {
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // recorremos hasta llegar al nodo que se desea consultar
            for (int i = 0; i < index; i++) {
                // recorremos aux
                aux = aux->next;
            }
            return aux->data;
        } else {
            // error
            throw out_of_range("La posicion no existe en la lista"); 
        }
    } else {
        throw out_of_range("La lista esta vacia");
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &other) {
    // validamos si las listas son iguales
    if (this == &other) {
        // retornamos el objeto sin cambios
        return *this;
    }

    // validamos que la lista no este vacia
    if (head != nullptr) {
        // borramos la lista actual
        // recorremos la lista
        while (head != nullptr) {
            // creamos un elemento aux igual a head
            Node<T>* aux = head;
            // recorremos head a head->next
            head = head->next;
            // borramos aux
            delete aux;
        }
    }
    // copiamos la lista del otro objeto
    // creamos un elemento aux igual al head de la otra lista
    Node<T>* aux = other.head;
    // recorremos la lista del otro objeto
    while (aux != nullptr) {
        // agregamos el valor de aux a la lista actual
        this->push_back(aux->data);
        // recorremos aux
        aux = aux->next;
    }
    // Se copia el size de la otra lista
    size = other.size;
    // retornamos el objeto actual
    return *this;
}


#endif /* LinkedList_h */