// Daniel Gómez Guerrero
// A01572201

#if !defined(BST_h)
#define BST_h

#include "NodeT.h"
#include <iostream>
using namespace std;

template <typename T>
class BST {
    private:
        NodeT<T>* root;
        void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);
    public:
        BST() : root(nullptr) {}
        void insert(T data);
        bool find(T data);
        void print();
};

template <typename T>
void BST<T>::insert(T data) {
    // Validamos si el arbol esta vacio
    if (root == nullptr) {
        // el arbol esta vacio
        // apuntamos root al nuevo nodo
        root = new NodeT<T>(data);
    } else {
        // el arbol no esta vacio
        // creamos un apuntador aux igual a root
        NodeT<T>* aux = root;
        // creamos un apuntador father igual a root
        NodeT<T>* father = root;
        // itero en el arbol hasta encontrar donde voy a insertar el nodo
        while (aux != nullptr) {
            // valido si aux->data es igual a data
            if (aux->data == data) {
                // son iguales
                return;
            } else {
                // hacemos father igual a aux
                father = aux;
                // recorremos aux
                //if (data < aux->data ? aux = aux->left : aux = aux->right);
                if (data < aux->data) {
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }
        }
        // inserto el nodo en el lado correspondiente
        if (data < father->data) {
            // el nodo va al lado izquierdo de father
            father->left = new NodeT<T>(data);
        } else {
            // el nodo va al lado derecho de father
            father->right = new NodeT<T>(data);
        }
    }
}

template <typename T>
bool BST<T>::find(T data) {
    // validamos que el arbol no este vacio
    if (root == nullptr) {
        // el arbol esta vacio
        // retornamos false
        return false;
    } else {
        // el arbol no esta vacio
        // creamos un apuntador aux igual a root
        NodeT<T>* aux = root;
        // itero en el arbol hasta encontrar el nodo a buscar o que no lo encuentre
        while (aux != nullptr) {
            // valido si aux->data es igual a data
            if (aux->data == data) {
                // son iguales, regreso true
                return true;
            } else {
                // recorremos aux
                //if (data < aux->data ? aux = aux->left : aux = aux->right);
                if (data < aux->data) {
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }
        }
        // no se encontro el dato a buscar, regreso false
        return false;
    }
}

template <typename T>
void BST<T>::print() {
    if (root == nullptr) { cout << "(arbol vacio)" << endl; return; }
    printTree(root, "", false, true);
}

template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {
    if (node == nullptr) return;
    printTree(node->right, prefix + (isRoot ? "" : (isRight ? "      " : "|     ")), true, false);
    cout << prefix << (isRoot ? "" : (isRight ? ".---- " : "`---- ")) << node->data << endl;
    printTree(node->left,  prefix + (isRoot ? "" : (isRight ? "|     " : "      ")), false, false);
}

#endif /* BST_h */