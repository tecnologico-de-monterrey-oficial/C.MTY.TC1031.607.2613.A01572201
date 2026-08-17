#include "List.h"

/**
int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

string sum(string a, string b) {
    return a + b;
}
**/

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {

    // Ejemplos vistos en clase
    string a = "hola ";
    string b = "crayola";
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;
    
    int c = 5;
    int d = 10;
    cout << "Sum of " << c << " and " << d << " is: " << sum(c, d) << endl;

    double e = 5.5;
    double f = 10.5;
    cout << "Sum of " << e << " and " << f << " is: " << sum(e, f) << endl;

    List<string> things;
    things.insert("Laptop");
    things.insert("bottle");
    things.print();

    // Operaciones de la Tarea

    List<int> list; // llama al constructor default

    // Inserta elementos a la lista
    cout << "Llenando lista..." << endl;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(17.6);
    list.insert(20.12);
    list.print(); // Imprime la lista de datos

    // Quita el ultimo elemento de la lista
    cout << "Removiendo ultimo elemento de lista..." << endl;
    list.removeLast();
    list.print();

    // Retorna el valor de una posicion especifica de la lista
    cout << "Consiguiendo informacion de lista..." << endl;
    cout << list.getData(3) << endl;
    cout << list.getData(0) << endl;

    // Retorna el tamaño de la lista
    cout << "Obteniendo tamaño de lista..." << endl;
    cout << list.getSize() << endl;

    // Retorna el valor maximo de la lista
    cout << "Consiguiendo valor maximo de lista..." << endl;
    cout << list.getMax() << endl;

    // Inserta un valor en una posicion de la lista y mueve una posicion a la derecha los elementos que le siguen
    cout << "Insertando valor a lista..." << endl;
    list.insertAt(2, 6.92);
    list.print();

    // Remueve un valor en una posicion de la lista y mueve una posicion a la izquierda los elementos que le siguen
    cout << "Removiendo valor de lista..." << endl;
    list.removeAt(3);
    list.print();

    return 0;
}

