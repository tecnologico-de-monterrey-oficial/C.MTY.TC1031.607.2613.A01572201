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
        void preOrder(NodeT<T>* node);
        void inOrder(NodeT<T>* node);
        void postOrder(NodeT<T>* node);
        void levelPerLevel(NodeT<T>* node);
    public:
        BST() : root(nullptr) {}
        void insert(T data);
        bool find(T data);
        void visit(string method);
        void remove(T data);
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
void BST<T>::preOrder(NodeT<T>* node) {
    if (node != nullptr) {
        // imprimimos data
        cout << node->data << " ";
        // hacemos preOrder con left
        preOrder(node->left);
        // hacemos preOrder con right
        preOrder(node->right);
    }
}

template <typename T>
void BST<T>::inOrder(NodeT<T>* node) {
    if (node != nullptr) {
        // hacemos inOrder con left
        inOrder(node->left);
        // imprimimos data
        cout << node->data << " ";
        // hacemos inOrder con right
        inOrder(node->right);
    }
}

template <typename T>
void BST<T>::postOrder(NodeT<T>* node) {
    if (node != nullptr) {
        // hacemos postOrder con left
        postOrder(node->left);
        // hacemos postOrder con right
        postOrder(node->right);
        // imprimimos data
        cout << node->data << " ";
    }
}

template <typename T>
void BST<T>::levelPerLevel(NodeT<T>* node) {
    if (node != nullptr) {
       
    }
}

template <typename T>
void BST<T>::visit(string method) {
    if (method == "preOrder") {
        preOrder(root);
    }

    if (method == "inOrder") {
        inOrder(root);
    }

    if (method == "postOrder") {
        postOrder(root);
    }

    if (method == "levelPerLevel") {
        levelPerLevel(root);
    }

    cout << endl;
}

template <typename T>
void BST<T>::remove(T data) {
    // validamos si el arbol esta vacio
    if (root != nullptr) {
        // validamos si el nodo a borrar es root
        if (root->data == data) {
            // validamos si no tiene hijos
            if (root->left == nullptr && root->right == nullptr) {
                // root no tiene hijos
                // creamos un nodo aux igual a root
                NodeT<T>* aux = root;
                // asignamos nulos a root
                root = nullptr;
                // removemos aux
                delete aux;
                // nos salimos de la funcion
                return;
            }
            // validamos si tiene un hijo
            if (root->left == nullptr || root->right == nullptr) {
                // root solo tiene un hijo
                // creamos un apuntador auxiliar igual a root
                NodeT<T>* aux = root;
                // movemos root al hijo
                root = (root->left == nullptr) ? root = root->right : root = root->left;
                // removemos aux
                delete aux;
                // nos salimos de la funcion
                return;
            }
            // root tiene dos hijos
            
        }
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