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
        cout << "3. Ver al siguiente cliente sin atenderlo aun\n";
        cout << "4. Mostrar cuantas personas hay en la fila\n";
        cout << "5. Salir\n";
        cin >> option;

        // validamos que la opcion este disponible
        while (option < 1 || option > 5) {
            cout << "\nOpcion desconocida, intente de nuevo: ";
            cin >> option;
        }

        switch(option) {
            case 1: {
                cout << "\nInserte el nombre del cliente: ";
                // usamos cin.ignore() para limpiar el buffer de entrada y evitar problemas con getline
                cin.ignore();
                // usamos getline para permitir nombres con espacios
                getline(cin, cliente.nombre);

                cout << "\nInserte la cantidad de boletos que desea: ";
                // pedimos la cantidad de boletos que desea el cliente
                cin >> cliente.boletos;

                // agregamos el cliente a la fila
                fila.push(cliente);
                cout << "\nFila actual:\n";
                fila.print();

                // incrementamos el contador de personas en la fila
                numPersonas++;
                break;
            }

            case 2: {
                if (numPersonas == 0) {
                    cout << "\nNo hay clientes en la fila\n";
                    break;
                }

                Cliente current = fila.front();
                cout << "\nEl cliente " << current.nombre << " ha sido atendido y pidio " << current.boletos << " boleto(s)\n";
                // eliminamos el cliente de la fila
                fila.pop();
                // decrementamos el contador de personas en la fila
                numPersonas--;
                break;
            }

            case 3: {
                if (numPersonas == 0) {
                    cout << "\nNo hay clientes en la fila\n";
                    break;
                }

                Cliente current = fila.front();
                cout << "\nEl cliente " << current.nombre << " es el siguiente en la fila y desea " << current.boletos << " boleto(s)\n";
                break;
            }

            case 4: {
                cout << "\nHay " << numPersonas << " personas en la fila:\n";
                fila.print();
                break;
            }

            case 5:
                break;

            default:
                cout << "Opcion desconocida" << endl;
                break;
        }
    }

    return 0;
}