// Daniel Gómez Guerrero
// A01572201

#if !defined(BST_h)
#define BST_h

#include "NodeT.h"
#include <iostream>
#include <queue>
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
        int calculateHeight(NodeT<T>* node);
    public:
        BST() : root(nullptr) {}
        void insert(T data);
        bool find(T data);
        void visit(string method);
        void remove(T data);
        void print();
        int height();
        void ancestors(T data);
        int whatLevelAml(T data);
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
                // (data < aux->data) ? aux = aux->left : aux = aux->right;
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
       // creamos una fila de nodos
       queue<NodeT<T>*> nodeQueue;
       // agregamos a la fila el nodo dado
       nodeQueue.push(node);
       // iteramos mientras la fila no este vacia
       while (!nodeQueue.empty()) {
            // imprimimos el primer elemento de la fila
            node = nodeQueue.front();
            cout << node->data << " ";
            // eliminamos el elemento de la fila
            nodeQueue.pop();
            // agregamos a los hijos del elemento eliminado si existen
            if (node->left != nullptr) nodeQueue.push(node->left);
            if (node->right != nullptr) nodeQueue.push(node->right);
        }
        cout << endl;
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
            // creamos un apuntador aux igual a root
            NodeT<T>* aux = root;
            // validamos que el apuntador right de aux->left sea nulos
            if (aux->left->right == nullptr) {
                // aux->left es el más grande del lado izquierdo
                // creamos un apuntador que apunte a aux->left
                NodeT<T>* auxRemove = aux->left;
                // actualizamos el valor de aux por el valor de aux->left
                aux->data = auxRemove->data;
                // asignamos a aux->left, auxRemove->left
                aux->left = auxRemove->left;
                // removemos auxRemove
                delete auxRemove;
                // nos salimos de la funcion
                return;
            } else {
                // el más grande del lado izquierdo no es aux->left
                // creamos un apuntador que va a ser el padre del que voy a remover igual a aux->left
                NodeT<T>* fatherRemove = aux->left;
                // creamos un apuntador hacia el hijo derecho de fatherRemove
                NodeT<T>* auxRemove = fatherRemove->right;
                // iteramos hasta encontrar el más grande
                while (auxRemove->right != nullptr) {
                    // recorremos los apuntadores hacia la derecha
                    fatherRemove = auxRemove;
                    auxRemove = auxRemove->right;
                }
                // ya encontramos al más grande del lado izquierdo
                // igualamos aux->data igual a auxRemove->data
                aux->data = auxRemove->data;
                // actualizamos con nulos el lado derecho de fatherRemove
                fatherRemove->right = nullptr;
                // removemos auxRemove
                delete auxRemove;
                // nos salimos de la funcion
                return;
            }
        } else {
            // no quiero borrar raiz
            // busco el nodo a borrar
            // creamos un apuntador father igual a root
            NodeT<T>* father = root;
            // creamos un apuntador aux igual al hijo correspondiente
            NodeT<T>* aux = (data < root->data) ? root->left : root->right;
            // itero en el arbol hasta encontrar el nodo a buscar o que no lo encuentre
            while (aux != nullptr) {
                // valido si aux->data es igual a data
                if (aux->data == data) {
                    // son iguales
                    // lo removemos
                    // validamos si no tiene hijos
                    if (aux->left == nullptr && aux->right == nullptr) {
                        // aux no tiene hijos
                        // asignamos nulos al hijo correspondiente de father
                        (data < father->data) ? father->left = nullptr : father->right = nullptr;
                        // removemos aux
                        delete aux;
                        // nos salimos de la funcion
                        return;
                    }
                    // validamos si tiene un hijo
                    if (aux->left == nullptr || aux->right == nullptr) {
                        // aux solo tiene un hijo
                        if (data < father->data) {
                            // el hijo esta a la izquierda del padre
                            father->left = (aux->left != nullptr) ? aux->left : aux->right;
                        } else {
                            // el hijo esta a la derecha del padre
                            father->right = (aux->left != nullptr) ? aux->left : aux->right;
                        }
                        // removemos aux
                        delete aux;
                        // nos salimos de la funcion
                        return;
                    }
                    // aux tiene dos hijos
                    // validamos que el apuntador right de aux->left sea nulos
                    if (aux->left->right == nullptr) {
                        // aux->left es el más grande del lado izquierdo
                        // creamos un apuntador que apunte a aux->left
                        NodeT<T>* auxRemove = aux->left;
                        // actualizamos el valor de aux por el valor de aux->left
                        aux->data = auxRemove->data;
                        // asignamos a aux->left, auxRemove->left
                        aux->left = auxRemove->left;
                        // removemos auxRemove
                        delete auxRemove;
                        // nos salimos de la funcion
                        return;
                    } else {
                        // el más grande del lado izquierdo no es aux->left
                        // creamos un apuntador que va a ser el padre del que voy a remover igual a aux->left
                        NodeT<T>* fatherRemove = aux->left;
                        // creamos un apuntador hacia el hijo derecho de fatherRemove
                        NodeT<T>* auxRemove = fatherRemove->right;
                        // iteramos hasta encontrar el más grande
                        while (auxRemove->right != nullptr) {
                            // recorremos los apuntadores hacia la derecha
                            fatherRemove = auxRemove;
                            auxRemove = auxRemove->right;
                        }
                        // ya encontramos al más grande del lado izquierdo
                        // igualamos aux->data igual a auxRemove->data
                        aux->data = auxRemove->data;
                        // actualizamos con nulos el lado derecho de fatherRemove
                        fatherRemove->right = nullptr;
                        // removemos auxRemove
                        delete auxRemove;
                        // nos salimos de la funcion
                        return;
                    }
                } else {
                    // recorremos aux y father
                    father = aux;
                    aux = (data < aux->data) ? aux->left : aux->right;
                }
            }
            // no se encontro el dato a buscar, arrojamos una excepcion
            throw out_of_range("El nodo a borrar no existe");
        }
    }
}

template <typename T>
int BST<T>::calculateHeight(NodeT<T>* node) {
    // si el nodo es nulo, la altura es 0 
    if (node == nullptr) {
        return 0;
    }
    
    // utilizamos recursion para calcular la altura de los subarboles izquierdo y derecho
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    
    // retornamos la mayor altura de los dos subárboles más 1
    return max(leftHeight, rightHeight) + 1;
}

template <typename T>
int BST<T>::height() {
    return calculateHeight(root);
}

template <typename T>
void BST<T>::ancestors(T data) {
    // si el arbol esta vacio, no hay ancestros
    if (root == nullptr) {
        return;
    }

    // si el dato esta en la raiz, no tiene ancestros
    if (root->data == data) {
        return;
    }

    // creamos un nodo igual a root
    NodeT<T>* node = root;

    // iteramos mientras que node no sea nulo
    while (node != nullptr) {
        // validamos si el dato actual es el objetivo
        if (node->data == data) {
            // si es el dato dado, terminamos el programa
            return;
        } else {
            // imprimimos el nodo actual como ancestro
            cout << node->data << " ";
            // recorremos node
            node = (data < node->data) ? node->left : node->right;
        }
    }   
}

template <typename T>
int BST<T>::whatLevelAml(T data) {
    // validamos si el arbol esta vacio
    if (root != nullptr) {
        // creamos un contador para los niveles
        int counter = 1;
        // creamos un nodo igual a root
        NodeT<T>* node = root;
        // iteramos mientras que node no sea nulo
        while (node != nullptr) {
            // validamos si el dato actual es el dato dado
            if (node->data == data) {
                // retornamos el nivel
                return counter;
            } else {
                // recorremos node
                node = (data < node->data) ? node->left : node->right;
                // incrementamos counter
                counter++;
            }
        }
        return -1;
    } else {
        return -1;
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