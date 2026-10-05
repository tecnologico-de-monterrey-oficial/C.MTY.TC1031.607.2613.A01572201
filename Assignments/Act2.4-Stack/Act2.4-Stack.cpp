// Daniel Gómez Guerrero
// A01572201

#include "Stack.h"
#include "PaginaWeb.h"

int main() {
    Stack<PaginaWeb> pila;
    int option = 0;
    int numPaginas = 0;

    while (option != 5) {
        cout << "\nSeleccione que accion desea hacer (escriba el numero de la opcion):\n";
        cout << "1. Visitar una nueva página\n";
        cout << "2. Retroceder a la página anterior\n";
        cout << "3. Ver la página actual\n";
        cout << "4. Mostrar cuántas páginas hay en el historial\n";
        cout << "5. Salir\n";
        cin >> option;

        // validamos que la opcion este disponible
        while (option < 1 || option > 5) {
            cout << "Opcion desconocida, intente de nuevo: ";
            cin >> option;
        }

        switch(option) {
            case 1:
                numPaginas++;
                break;

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