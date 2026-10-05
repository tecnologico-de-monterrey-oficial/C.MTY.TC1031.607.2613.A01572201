// Daniel Gómez Guerrero
// A01572201

#include "LinkedList.h"
#include <cstdlib>
#include <vector>
#include <ctime>

vector<int> genIntList(int size) {
    // creamos un vector
    vector<int> list;

    // iteramos desde 0 hasta size
    for (int i = 0; i < size; i++) {
        // generamos un valor aleatorio entre 0 y 100
        int randomValue = rand() % 100;
        // agregamos el valor aleatorio al vector
        list.push_back(randomValue);
    }

    // regresamos el vector
    return list;
}

vector<float> genFloatList(int size) {
    // creamos un vector
    vector<float> list;

    // iteramos desde 0 hasta size
    for (int i = 0; i < size; i++) {
        // generamos un valor aleatorio entre 0 y 100
        float randomValue = static_cast<float>(rand() % 100) / 10.0f;
        // agregamos el valor aleatorio al vector
        list.push_back(randomValue);
    }

    // regresamos el vector
    return list;
}

void genRandom(LinkedList<int>& list, int size) {
    // creamos un vector auxiliar de enteros con datos aleatorios
    vector<int> auxVector = genIntList(size);
    // agregamos los elementos del vector a la lista
    for (int i = 0; i < auxVector.size(); i++) {
        list.push_back(auxVector[i]);
    }
}

void genRandom(LinkedList<float>& list, int size) {
    // creamos un vector auxiliar de float con datos aleatorios
    vector<float> auxVector = genFloatList(size);
    // agregamos los elementos del vector a la lista
    for (int i = 0; i < auxVector.size(); i++) {
        list.push_back(auxVector[i]);
    }
}

template <typename T>
void createList(LinkedList<T> &list) {
    int size, option2;

    cout << "\nCuantos elementos tendra la lista?: ";
    cin >> size;

    while (size <= 0) {
        cout << "La cantidad debe ser mayor a 0. Intente de nuevo.\n";
        cin >> size;
    }

    cout << "\nSeleccione como construir la lista (escriba el numero de la opcion):\n";
    cout << "1. Con datos aleatorios\n";
    cout << "2. Con datos capturados (escritos por usuario)\n";
    cin >> option2;

    // validamos que la opcion este disponible
    while (option2 < 1 || option2 > 2) {
        cout << "Opcion desconocida, intente de nuevo: ";
        cin >> option2;
    }

    if (option2 == 1) {
        // generamos la lista con datos aleatorios
        genRandom(list, size);
    } else if (option2 == 2) {
        // generamos la lista con datos capturados por el usuario
        for (int i = 0; i < size; i++) {
            T valorUsuario;
            // pedimos al usuario que ingrese el valor del elemento
            cout << "Ingrese el valor del elemento " << (i + 1) << ": ";
            cin >> valorUsuario;
            // agregamos el valor a la lista
            list.push_back(valorUsuario);
        }
    }
}

template <typename T>
void startMenu() {
    // inicializamos variables
    int option = 1, index;
    T data, auxData;
    LinkedList<T> list;
    LinkedList<T> list2;

    // creamos la lista
    createList(list);
    cout << "\nLista actual:\n";
    list.print();

    while (option != 0) {
        cout << "\nSeleccione que accion desea hacer (escriba el numero de la opcion):\n";
        cout << "0. Salir\n";
        cout << "1. Agregar un elemento al principio de la lista\n";
        cout << "2. Agregar un elemento al final de la lista\n";
        cout << "3. Insertar un elemento despues del indice dado\n";
        cout << "4. Borrar un elemento dado de la lista\n";
        cout << "5. Borrar un elemento en una posicion de la lista\n";
        cout << "6. Obtener el elemento de una posicion dada de la lista\n";
        cout << "7. Actualizar un elemento dado de la lista\n";
        cout << "8. Actualizar un elemento que se encuentra en una posicion dada de la lista\n";
        cout << "9. Encontrar un elemento dado en la lista\n";
        cout << "10. Obtener el elemento de una posicion de la lista (sobrecargo operador [ ])\n";
        cout << "11. Actualizar el elemento de una posicion de la lista (sobrecargo operador [ ])\n";
        cout << "12. Igualar una lista con los datos de otra lista (sobrecargo operador =)\n";
        cout << "13. Crear/rehacer lista auxiliar\n";
        cin >> option;
        

        // validamos que la opcion este disponible
        while (option < 0 || option > 13) {
            cout << "Opcion desconocida, intente de nuevo: ";
            cin >> option;
        }


        switch(option) {
            case 0:
                break;
            
            case 1:
                cout << "\nInserte elemento a agregar: ";
                cin >> data;

                list.push_front(data);
                cout << "\nLista actual:\n";
                list.print();
                break;

            case 2:
                cout << "\nInserte elemento a agregar: ";
                cin >> data;

                list.push_back(data);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 3:
                cout << "\nInserte elemento a insertar: ";
                cin >> data;

                cout << "\nInserte indice a usar: ";
                cin >> index;

                list.insert(index, data);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 4:
                cout << "\nInserte elemento a borrar: ";
                cin >> data;

                list.deleteData(data);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 5:
                cout << "\nInserte indice de elemento a borrar: ";
                cin >> index;

                list.deleteAt(index);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 6:
                cout << "\nInserte indice de elemento que se quiere consultar: ";
                cin >> index;

                cout << "\nElemento en el indice " << index << ": " << list.getData(index) << "\n";
                break;
            
            case 7:
                cout << "\nInserte elemento a actualizar: ";
                cin >> data;

                cout << "\nInserte elemento que reemplazara al previo: ";
                cin >> auxData;

                list.updateData(data, auxData);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 8:
                cout << "\nInserte indice del elemento a actualizar: ";
                cin >> index;

                cout << "\nInserte elemento que reemplazara al previo: ";
                cin >> auxData;

                list.updateAt(index, auxData);
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 9:
                cout << "\nInserte elemento a encontrar: ";
                cin >> data;

                cout << "Elemento encontrado en el indice: " << list.findData(data) << endl;
                break;
            
            case 10:
                cout << "\nInserte indice de elemento que se quiere consultar: ";
                cin >> index;

                cout << list[index];
                break;
            
            case 11:
                cout << "\nInserte indice de elemento que se quiere actualizar: ";
                cin >> index;

                cout << "\nInserte elemento que reemplazara al previo: ";
                cin >> auxData;

                list[index] = auxData;
                cout << "\nLista actual:\n";
                list.print();
                break;
            
            case 12:
                cout << "Seleccione que accion desea hacer (escriba el numero de la opcion):\n";
                cout << "1. Igualar lista actual con lista auxiliar\n";
                cout << "2. Igualar lista auxiliar con lista actual\n";
                cin >> option;

                // validamos que la opcion este disponible
                while (option < 1 || option > 2) {
                    cout << "Opcion desconocida, intente de nuevo: ";
                    cin >> option;
                }

                switch(option) {
                    case 1:
                        list = list2;
                        cout << "\nLista actual:\n";
                        list.print();
                        break;
                    
                    case 2:
                        list2 = list;
                        cout << "\nLista auxiliar:\n";
                        list2.print();
                        break;

                    default:
                        cout << "Opcion desconocida" << endl;
                        break;
                }

                break;
            
            case 13:
                list2 = LinkedList<T>();
                createList(list2);
                cout << "\nLista auxiliar:\n";
                list2.print();
                break;

            default:
                cout << "Opcion desconocida" << endl;
                break;
        }
    }
}

int main() {
    srand(time(0));
    int option1;

    cout << "Seleccione el tipo de dato para sus listas (escriba el numero de la opcion):\n";
    cout << "1. Enteros (int)\n";
    cout << "2. Decimales (float)\n";
    cin >> option1;

    // validamos que la opcion este disponible
    while (option1 < 1 || option1 > 2) {
        cout << "Opcion desconocida, intente de nuevo: ";
        cin >> option1;
    }

    if (option1 == 1) {
        // trabajamos con listas de datos enteros
        startMenu<int>(); 
    } else if (option1 == 2) {
        // trabajamos con listas de datos float
        startMenu<float>(); 
    }

    return 0;
}