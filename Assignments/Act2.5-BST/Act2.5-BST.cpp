// Daniel Gómez Guerrero
// A01572201

#include "BST.h"

int main() {
    BST<int> bst;
    int valor;

    // inicializamos opción para arrancar el ciclo del menú principal
    int option = -1;

    // validamos que la opción este disponible y sea distinta a salida
    while (option != 7) {
        cout << "\nQue accion desea realizar?" << endl;
        cout << "1. Insertar valores en el arbol" << endl;
        cout << "2. Mostrar el recorrido inorder, preorder, postorder y level by level" << endl;
        cout << "3. Buscar un valor" << endl;
        cout << "4. Mostrar la altura del arbol" << endl;
        cout << "5. Mostrar los ancestros de un nodo" << endl;
        cout << "6. Consultar el nivel de un nodo" << endl;
        cout << "7. Salir del programa" << endl;
        cin >> option;
    
        switch (option) {
            case 1:
                cout << "\nInserte valor a insertar: ";
                cin >> valor;
                bst.insert(valor);
                cout << endl;
                bst.print();
                break;
            
            case 2:
                cout << "\nRecorrido inorder: ";
                bst.visit("inOrder");

                cout << "\nRecorrido preorder: ";
                bst.visit("preOrder");

                cout << "\nRecorrido postorder: ";
                bst.visit("postOrder");

                cout << "\nRecorrido level by level: ";
                bst.visit("levelPerLevel");
                break;
            
            case 3:
                cout << "\nInserte valor a buscar: ";
                cin >> valor;

                if (bst.find(valor)) {
                    cout << "\nEl valor esta presente en el arbol\n";
                } else {
                    cout << "\nEl valor no esta presente en el arbol\n";
                }
                break;
            
            case 4:
                cout << "\nAltura del arbol: " << bst.height() << endl;
                break;

            case 5:
                cout << "\nInserte valor a listar ancestros: ";
                cin >> valor;
                bst.ancestors(valor);
                cout << endl;
                break;
            
            case 6:
                cout << "\nInserte valor a consultar nivel: ";
                cin >> valor;
                if (bst.whatLevelAml(valor) != -1) {
                    cout << "\nEl nivel del nodo es: " << bst.whatLevelAml(valor) << endl;
                } else {
                    cout << "\nNo se encontro el nodo\n";
                }
                break;
            
            case 7:
                cout << "\nSaliendo del programa..." << endl;
                return 0;
        }
    }
}