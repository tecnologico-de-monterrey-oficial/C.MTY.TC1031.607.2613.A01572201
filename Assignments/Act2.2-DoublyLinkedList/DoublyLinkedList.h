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
        void insert(int index, T data);
        bool deleteData(T data);
        bool deleteAt(int index);
        T getData(int index);
        void updateData(T data, T newData);
        void updateAt(int index, T newData);
        int findData(T data);
        T& operator[](int index);
        DoublyLinkedList& operator=(const DoublyLinkedList<T> &other);
        void clear();
        void sort();
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
        if (head->next != nullptr) {
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
                if (index = size - 1) {
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

#endif /* DoublyLinkedList_h */