#ifndef List_h
#define List_h

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class List {
    private:
        vector<T> list;
        int size;
    public:
        List();
        void insert(T data);
        void removeLast();
        T getData(int position);
        int getSize();
        T getMax();
        void print();
        void insertAt(int position, T data);
        void removeAt(int position);
};

template <typename T>
List<T>::List() {
    size = 0;
}

template <typename T>
void List<T>::insert(T data) {
    list.push_back(data);
    size++;
}

template <typename T>
void List<T>::removeLast() {
    if (size == 0) {
        cout << "NO HAY ELEMENTOS" << endl;
    } else {
        cout << list[size - 1] << endl;
        list.pop_back();
        size--;
    }
}

template <typename T>
T List<T>::getData(int position) {
    if (0 <= position && position < size) {
        return list[position];
    } else {
        cout << "POSICIÓN INVÁLIDA" << endl;
        return T();
    }
}

template <typename T>
int List<T>::getSize() {
    return size;
}

template <typename T>
T List<T>::getMax() {
    if (size == 0) {
        cout << "NO HAY ELEMENTOS" << endl;
        return T();
    } else {
        T maxValue = list[0];

        for (int i = 1; i < size; i++) {
            if (list[i] > maxValue) {
                maxValue = list[i];
            }
        }

        return maxValue;
    }
}

template <typename T>
void List<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << list[i] << endl;
    }
}

template <typename T>
void List<T>::insertAt(int position, T data) {
    if (0 <= position && position <= size) {
        list.insert(list.begin() + position, data);
        size++;
    } else {
        cout << "POSICIÓN INVÁLIDA" << endl;
    }
}

template <typename T>
void List<T>::removeAt(int position) {
    if (0 <= position && position < size) {
        cout << list[position] << endl;
        list.erase(list.begin() + position);
        size--;
    } else if (size == 0) {
        cout << "NO HAY ELEMENTOS" << endl;
    } else {
        cout << "POSICIÓN INVÁLIDA" << endl;
    }
}

#endif /* List_h */