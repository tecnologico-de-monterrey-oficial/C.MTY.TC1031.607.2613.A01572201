// Daniel Gómez Guerrero
// A01572201

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"
#include <iostream>
#include <stdexcept>
using namespace std;

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
        void insert(int index, T data);
        bool deleteData(T data);
        bool deleteAt(int index);
        T getData(int index);
        void updateData(T data, T newData);
        void updateAt(int index, T newData);
        int findData(T data);
        T& operator[](int index);
        const T& operator[](int index) const;
        DoublyLinkedList& operator=(const DoublyLinkedList<T> &other);
        void clear();
        void sort(DoublyLinkedList<T> &list);
        void duplicate();
        void removeDuplicates();
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

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    // validamos que el indice sea valido
    if (index >= 0 && index <= size - 1) {
        // validamos que el indice sea desde 0 hasta el penultimo
        if (index != size - 1) {
            // el index es desde 0 hasta el penultimo (en medio)
            // creamos un indice auxiliar igual a 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // iteramos hasta encontrar el indice dado
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos el indice auxiliar
                auxIndex++;
            }
            // creamos un nodo nuevo
            NodeD<T>* auxNew = NodeD<T>(data);
            // el prev del nuevo lo apuntamos a aux
            auxNew->prev = aux;
            // el next del nuevo lo apuntamos a aux->next
            auxNew->next = aux->next;
            // el prev del siguiente de aux lo apuntamos al nuevo
            aux->next->prev = auxNew;
            // apuntamos aux->next al nuevo
            aux->next = auxNew;
            // incrementamos size
            size++;
        } else {
            // el index es igual a size - 1
            // hacemos como si fuera addLast
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
    } else {
        throw out_of_range("Indice invalido");
    }
}

template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
    // findData
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;
    // inicializamos un indice auxiliar en 0
    int auxIndex = 0;
    // recorremos la lista mientras auxIndex < size
    while (auxIndex < size) {
        // validamos si lo encontramos
        if (aux->data == data) {
            // si lo encontramos, hay que borrarlo
            // validamos si es el unico
            if (head == tail) {
                // apuntamos a nulos head y tail
                head = nullptr;
                tail = nullptr;
                // liberamos aux
                delete aux;
                // decrementamos size
                size--;
                // retornamos verdadero
                return true;
            } else {
                // validamos si vamos a borrar head
                if (aux == head) {
                    // si es el primer elemento
                    // apuntamos head al siguiente elemento
                    head = head->next;
                    // actualizamos el apuntador prev de head
                    head->prev = nullptr;
                    // liberamos aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // retornamos verdadero
                    return true;
                } else {
                    // validamos si es el ultimo elemento
                    if (aux == tail) {
                        // si es el ultimo elemento
                        // apuntamos tail al elemento previo
                        tail = tail->prev;
                        // actualizamos el apuntador next de tail
                        tail->next = nullptr;
                        // liberamos aux
                        delete aux;
                        // decrementamos size
                        size--;
                        // retornamos verdadero
                        return true;
                    }  else {
                        // borramos el de en medio
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // liberamos aux
                        delete aux;
                        // decrementamos size
                        size--;
                        // regreso true
                        return true;
                    }
                }
            }
        }
        // recorremos aux e incrementamos auxIndex
        auxIndex++;
        aux = aux->next;
    }
    // data no se encuentra en la lista
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // validamos si el indice es valido
    if (index >= 0 && index < size) {
        // indice valido
        // validamos si solo hay un elemento
        if (head == tail) {
            // solo hay un elemento
            // creamos un nodo auxiliar que apunte a head
            NodeD<T>* aux = head;
            // apuntamos a nulos head y tail
            head = nullptr;
            tail = nullptr;
            // liberamos aux
            delete aux;
            // decrementamos size
            size--;
            // retornamos verdadero
            return true;
        } else {
            // hay más de un elemento
            // validamos si queremos borrar el primero
            if (index == 0) {
                // queremos borrar el primero
                // creamos un nodo auxiliar que apunte a head
                NodeD<T>* aux = head;
                // apuntamos head al siguiente elemento
                head = head->next;
                // actualizamos el apuntador prev de head
                head->prev = nullptr;
                // liberamos aux
                delete aux;
                // decrementamos size
                size--;
                // retornamos verdadero
                return true;
            } else {
                // validamos si queremos borrar el ultimo elemento
                if (index == size - 1) {
                    // borramos el ultimo
                    // creamos un nodo auxiliar que apunte a tail
                    NodeD<T>* aux = tail;
                    // apuntamos tail al elemento previo
                    tail = tail->prev;
                    // actualizamos el apuntador next de tail
                    tail->next = nullptr;
                    // liberamos aux
                    delete aux;
                    // decrementamos size
                    size--;
                    // retornamos verdadero
                    return true;
                } else {
                    // borramos el de en medio
                    // revisamos por donde empezamos a recorrer la lista
                    if (index <= (size - 1)/2) {
                        // recorremos por la izquierda
                        // creamos un indice auxiliar = 1
                        int auxIndex = 1;
                        // creamos un apuntador auxiliar igual a head->next
                        NodeD<T>* aux = head->next;
                        // recorremos la lista mientras auxIndex < index
                        while (auxIndex < index) {
                            // recorremos aux
                            aux = aux->next;
                            // incrementamos auxIndex
                            auxIndex++;
                        }
                        // ya llegue al nodo deseado
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // liberamos aux
                        delete aux;
                        // decrementamos size
                        size--;
                        // regreso true
                        return true;
                    } else {
                        // recorremos por la derecha
                        // creamos un indice auxiliar = size - 2
                        int auxIndex = size - 2;
                        // creamos un apuntador auxiliar igual a tail->prev
                        NodeD<T>* aux = tail->prev;
                        // recorremos la lista mientras index < auxIndex
                        while (index < auxIndex) {
                            // recorremos aux
                            aux = aux->prev;
                            // decrementamos auxIndex
                            auxIndex--;
                        }
                        // ya llegue al nodo deseado
                        // actualizamos el next de aux->prev que apunte a aux->next
                        aux->prev->next = aux->next;
                        // actualizamos el prev de aux->next que apunte a aux->prev
                        aux->next->prev = aux->prev;
                        // liberamos aux
                        delete aux;
                        // decrementamos size
                        size--;
                        // regreso true
                        return true;
                    }
                }
            }
        }
    } else {
        // indice invalido
        return false;
    }
}

template <typename T>
T DoublyLinkedList<T>::getData(int index) {
    // validamos que la posicion exista
    if (index >= 0 && index < size) {
        // revisamos por donde empezamos a recorrer la lista
        if (index <= (size - 1)/2) {
            // recorremos por la izquierda
            // creamos un indice auxiliar = 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // recorremos la lista mientras auxIndex < index
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos auxIndex
                auxIndex++;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        } else {
            // recorremos por la derecha
            // creamos un indice auxiliar = size - 1
            int auxIndex = size - 1;
            // creamos un apuntador auxiliar igual a tail
            NodeD<T>* aux = tail;
            // recorremos la lista mientras index < auxIndex
            while (index < auxIndex) {
                // recorremos aux
                aux = aux->prev;
                // decrementamos auxIndex
                auxIndex--;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        }
    } else {
        throw out_of_range("La posicion no existe en la lista"); 
    }
}

template <typename T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // findData
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;
    // inicializamos un indice auxiliar en 0
    int auxIndex = 0;
    // recorremos la lista mientras auxIndex < size
    while (auxIndex < size) {
        // validamos si lo encontramos
        if (aux->data == data) {
            // si lo encontramos
            // actualizamos el valor de aux
            aux->data = newData;
            // return
            return;
        }
        // recorremos aux e incrementamos auxIndex
        auxIndex++;
        aux = aux->next;
    }
    // data no se encuentra en la lista
    throw out_of_range("No se encontro el dato a actualizar");
}


template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    // getData
    // validamos que la posicion exista
    if (index >= 0 && index < size) {
        // revisamos por donde empezamos a recorrer la lista
        if (index <= (size - 1)/2) {
            // recorremos por la izquierda
            // creamos un indice auxiliar = 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // recorremos la lista mientras auxIndex < index
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos auxIndex
                auxIndex++;
            }
            // ya llegue al nodo deseado
            // actualizamos aux
            aux->data = newData;
            // return
            return;
        } else {
            // recorremos por la derecha
            // creamos un indice auxiliar = size - 1
            int auxIndex = size - 1;
            // creamos un apuntador auxiliar igual a tail
            NodeD<T>* aux = tail;
            // recorremos la lista mientras index < auxIndex
            while (index < auxIndex) {
                // recorremos aux
                aux = aux->prev;
                // decrementamos auxIndex
                auxIndex--;
            }
            // ya llegue al nodo deseado
            // actualizamos aux
            aux->data = newData;
            // return
            return;
        }
    } else {
        throw out_of_range("La posicion no existe en la lista"); 
    }
}

template <typename T>
int DoublyLinkedList<T>::findData(T data) {
    // creamos un apuntador auxiliar
    NodeD<T>* aux = head;
    // inicializamos un indice auxiliar en 0
    int auxIndex = 0;
    // recorremos la lista mientras auxIndex < size
    while (auxIndex < size) {
        // validamos si lo encontramos
        if (aux->data == data) {
            // si lo encontramos
            return auxIndex;
        }
        // recorremos aux e incrementamos auxIndex
        auxIndex++;
        aux = aux->next;
    }
    // data no se encuentra en la lista
    return -1;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    // getData
    // validamos que la posicion exista
    if (index >= 0 && index < size) {
        // revisamos por donde empezamos a recorrer la lista
        if (index <= (size - 1)/2) {
            // recorremos por la izquierda
            // creamos un indice auxiliar = 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // recorremos la lista mientras auxIndex < index
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos auxIndex
                auxIndex++;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        } else {
            // recorremos por la derecha
            // creamos un indice auxiliar = size - 1
            int auxIndex = size - 1;
            // creamos un apuntador auxiliar igual a tail
            NodeD<T>* aux = tail;
            // recorremos la lista mientras index < auxIndex
            while (index < auxIndex) {
                // recorremos aux
                aux = aux->prev;
                // decrementamos auxIndex
                auxIndex--;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        }
    } else {
        throw out_of_range("La posicion no existe en la lista"); 
    }
}

// para leer de listas const
template <typename T>
const T& DoublyLinkedList<T>::operator[](int index) const {
    // getData
    // validamos que la posicion exista
    if (index >= 0 && index < size) {
        // revisamos por donde empezamos a recorrer la lista
        if (index <= (size - 1)/2) {
            // recorremos por la izquierda
            // creamos un indice auxiliar = 0
            int auxIndex = 0;
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // recorremos la lista mientras auxIndex < index
            while (auxIndex < index) {
                // recorremos aux
                aux = aux->next;
                // incrementamos auxIndex
                auxIndex++;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        } else {
            // recorremos por la derecha
            // creamos un indice auxiliar = size - 1
            int auxIndex = size - 1;
            // creamos un apuntador auxiliar igual a tail
            NodeD<T>* aux = tail;
            // recorremos la lista mientras index < auxIndex
            while (index < auxIndex) {
                // recorremos aux
                aux = aux->prev;
                // decrementamos auxIndex
                auxIndex--;
            }
            // ya llegue al nodo deseado
            // regresamos el valor de aux
            return aux->data;
        }
    } else {
        throw out_of_range("La posicion no existe en la lista"); 
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other) {
    // validamos si las listas son iguales
    if (this == &other) {
        // retornamos el objeto sin cambios
        return *this;
    }

    // borramos la lista actual
    // recorremos la lista
    while (head != nullptr) {
        // creamos un elemento aux igual a head
        NodeD<T>* aux = head;
        // recorremos head a head->next
        head = head->next;
        // borramos aux
        delete aux;
    }

    // resetamos tail y size
    tail = nullptr; 
    size = 0;

    // copiamos la lista del otro objeto
    // creamos un elemento aux igual al head de la otra lista
    NodeD<T>* aux = other.head;
    // recorremos la lista del otro objeto
    while (aux != nullptr) {
        // agregamos el valor de aux a la lista actual
        this->addLast(aux->data);
        // recorremos aux
        aux = aux->next;
    }
    // retornamos el objeto actual
    return *this;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    // recorremos la lista
    while (head != nullptr) {
        // creamos un elemento aux igual a head
        NodeD<T>* aux = head;
        // recorremos head a head->next
        head = head->next;
        // borramos aux
        delete aux;
    }

    // resetamos tail y size
    tail = nullptr; 
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::sort(DoublyLinkedList<T> &list) {
    // shellSort
    // obtenemos el tamaño de la lista y la mitad del tamaño
    int size = list.size;
    int half = size / 2;

    // iteramos mientras half sea mayor a 0
    while (half > 0) {
        // iteramos desde half hasta el final de la lista
        for (int i = half; i < size; i++) {
            // creamos una variable temporal con el valor de la posición i
            T temp = list[i];
            // creamos una variable auxiliar con el valor de i
            int aux = i;

            // iteramos mientras aux sea mayor o igual a half y 
            // el valor en la posición aux - half sea mayor que temp
            while (aux >= half && list[aux - half] > temp) {
                // actualizamos el valor en la posición aux con 
                // el valor en la posición aux - half
                list[aux] = list[aux - half];
                // decrementamos aux en half
                aux -= half;
            }

            // actualizamos el valor en la posición aux con temp
            list[aux] = temp;
        }

        // decrementamos half a la mitad
        half /= 2;
    }
}

template <typename T>
void DoublyLinkedList<T>::duplicate() {
    // validamos si la lista esta vacia
    if (head != nullptr) {
        // creamos un apuntador auxiliar igual a head
        NodeD<T>* aux = head;
        // recorremos la lista mientras aux sea diferente de nullptr
        while (aux != nullptr) {
            // creamos un nodo duplicado
            NodeD<T>* dupliNode = new NodeD<T>(aux->data);
            // apuntamos dupliNode->next a aux->next
            dupliNode->next = aux->next;
            // apuntamos dupliNode->prev a aux
            dupliNode->prev = aux;
            // validamos si hay un siguiente nodo
            if (aux->next != nullptr) {
                // apuntamos el prev de aux->next al nodo duplicado
                aux->next->prev = dupliNode;
            } else {
                // apuntamos tail al nodo duplicado
                tail = dupliNode;
            }
            // apuntamos el next del nodo original al duplicado
            aux->next = dupliNode;
            // incrementamos size
            size++;
            // apuntamos aux al next del duplicado
            aux = dupliNode->next;
        }
    } else {
        //throw out_of_range("La lista esta vacia");
        return;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    // validamos si la lista esta vacia
    if (head != nullptr) {
        // validamos si hay un siguiente nodo
        if (head->next != nullptr) {
            // creamos un apuntador auxiliar igual a head
            NodeD<T>* aux = head;
            // recorremos la lista mientras aux sea diferente de nullptr y aux->next sea diferente de nullptr
            while (aux != nullptr && aux->next != nullptr) {
                // validamos si el valor de aux es igual al valor del siguiente nodo
                if (aux->data == aux->next->data) {
                    // creamos un apuntador auxiliar del nodo a borrar
                    NodeD<T>* auxRemove = aux->next;
                    // apuntamos el next del nodo original al next del duplicado
                    aux->next = auxRemove->next;
                    // validamos si hay un nodo siguiente del duplicado
                    if (auxRemove->next != nullptr) {
                        // apuntamos el prev del siguiente nodo al nodo original
                        auxRemove->next->prev = aux;
                    } else {
                        // apuntamos tail al nodo original
                        tail = aux;
                    }
                    // eliminamos el nodo duplicado
                    delete auxRemove;
                    // decrementamos size
                    size--;
                } else {
                    // apuntamos aux al siguiente nodo
                    aux = aux->next;
                }
            }
        } else {
            //throw out_of_range("Solo hay un elemento en la lista");
            return;
        }
    } else {
        //throw out_of_range("La lista esta vacia");
        return;
    }
}

#endif /* DoublyLinkedList_h */