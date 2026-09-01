// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> &list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <typename T>
void swapSort(vector<T> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            T a = list[i];
            T b = list[j];

            if (list[i] > list[j]) {
                list[i] = b;
                list[j] = a;
            }
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &list) {
    bool change = true;

    for (int i = list.size() - 1; i > 0 && change; i--) {
        change = false;

        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                change = true;
                swap(list[j], list[j + 1]);
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list) {
    int min = 0, max;

    for (int i = 0; i < list.size(); i++) {

    }
}

template <typename T>
void insertionSort(vector<T> &list) {
    for (int i = 1; i < list.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (list[j] < list[j - 1]) {
                swap(list[j - 1], list[j]);
            }
        }
    }
}

template <typename T>
void quickSort(vector<T> &list) {
    
}

template <typename T>
void mergeSort(vector<T> &list) {
    
}

int main() {
    vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    cout << "Original: ";
    print(list);

    vector<int> list2 = list;
    //cout << "Original 2: ";
    //print(list2);

    vector<int> list3 = list;
    //cout << "Original 3: ";
    //print(list3);

    vector<int> list4 = list;
    //cout << "Original 4: ";
    //print(list4);

    swapSort(list);
    cout << "Swap Sort: ";
    print(list);

    bubbleSort(list2);
    cout << "Bubble Sort: ";
    print(list2);

    /*selectionSort(list3);
    cout << "Selection Sort: ";
    print(list3);*/

    insertionSort(list4);
    cout << "Insertion Sort: ";
    print(list4);

    return 0;
}