// Daniel Gómez Guerrero
// A01572201

#include "Queue.h"
#include "Cliente.h"
#include <string>

int main() {
    Queue<Cliente> fila;
    Cliente cliente;
    int option = 0;
    int numPersonas = 0;

    while (option != 5) {
        cout << "\nSeleccione que accion desea simular o tomar (escriba el numero de la opcion):\n";
        cout << "1. Llegada de un nuevo cliente\n";
        cout << "2. Atender al siguiente cliente\n";
        cout << "3. Ver al siguiente cliente sin atenderlo aún\n";
        cout << "4. Mostrar cuántas personas hay en la fila\n";
        cout << "5. Salir\n";
        cin >> option;

        // validamos que la opcion este disponible
        while (option < 1 || option > 5) {
            cout << "Opcion desconocida, intente de nuevo: ";
            cin >> option;
        }

        switch(option) {
            case 1: {
                cout << "Inserte el nombre del cliente:";
                getline(cin, cliente.nombre);

                cout << "\nInserte la cantidad de boletos que desea:";
                cin >> cliente.boletos;

                fila.push(cliente);
                cout << "Fila actual:\n";
                fila.print();

                numPersonas++;
                break;
            }

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            default:
                cout << "Opcion desconocida" << endl;
                break;
        }
    }


    return 0;
}