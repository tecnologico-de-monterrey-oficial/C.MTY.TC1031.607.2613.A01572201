// Daniel Gómez Guerrero
// A01572201

#include "BST.h"

int main() {
    BST<int> bst;

    bst.insert(40);
    bst.insert(20);
    bst.insert(60);
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(30);
    bst.insert(35);
    bst.insert(38);
    bst.insert(50);
    bst.insert(70);
    bst.print();
    /*if (bst.find(40)) {
        cout << "si se encuentra el nodo" << endl;
    } else {
        cout << "no se encuentra el nodo" << endl;
    }*/
    bst.visit("preOrder");
    bst.visit("inOrder");
    bst.visit("postOrder");
    /*bst.remove(40);
    bst.print();
    bst.remove(38);
    bst.print();*/
    bst.remove(20);
    bst.print();

    return 0;
}