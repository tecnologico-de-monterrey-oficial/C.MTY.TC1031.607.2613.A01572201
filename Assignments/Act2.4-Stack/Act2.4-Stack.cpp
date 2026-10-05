// Daniel Gómez Guerrero
// A01572201

#include "Stack.h"
#include "PaginaWeb.h"
#include <string>

int main() {
    PaginaWeb paginas;
    Stack<PaginaWeb> pila;
    int option = 0;
    int numPaginas = 0;

    while (option != 5) {
        cout << "\nSeleccione que accion desea hacer (escriba el numero de la opcion):\n";
        cout << "1. Visitar una nueva pagina\n";
        cout << "2. Retroceder a la pagina anterior\n";
        cout << "3. Ver la pagina actual\n";
        cout << "4. Mostrar cuantas paginas hay en el historial\n";
        cout << "5. Salir\n";
        cin >> option;

        // validamos que la opcion este disponible
        while (option < 1 || option > 5) {
            cout << "\nOpcion desconocida, intente de nuevo: ";
            cin >> option;
        }

        switch(option) {
            case 1: {
                cout << "\nInserte el titulo de la pagina: ";
                // usamos cin.ignore() para limpiar el buffer de entrada y evitar problemas con getline
                cin.ignore();
                // usamos getline para permitir titulos con espacios
                getline(cin, paginas.titulo);

                cout << "\nInserte la URL de la pagina: ";
                // pedimos la URL de la pagina
                cin >> paginas.url;

                // agregamos la pagina a la pila
                pila.push(paginas);
                cout << "\nHistorial actual:\n";
                pila.print();

                // incrementamos el contador de paginas en la pila
                numPaginas++;
                break;
            }

            case 2: {
                if (numPaginas == 0) {
                    cout << "\nNo hay paginas en el historial\n";
                    break;
                }

                PaginaWeb current = pila.top();
                cout << "\nLa pagina " << current.titulo << " de la URL " << current.url << " ha sido cerrada\n";
                // eliminamos la pagina de la pila
                pila.pop();
                // decrementamos el contador de paginas en la pila
                numPaginas--;
                break;
            }

            case 3: {
                if (numPaginas == 0) {
                    cout << "\nNo hay paginas en el historial\n";
                    break;
                }

                PaginaWeb current = pila.top();
                cout << "\nLa pagina actual es " << current.titulo << " de la URL " << current.url << endl;
                break;
            }

            case 4: {
                cout << "\nHay " << numPaginas << " paginas en el historial:\n";
                pila.print();
                break;
            }

            case 5:
                break;

            default:
                cout << "\nOpcion desconocida\n" << endl;
                break;
        }
    }


    return 0;
}