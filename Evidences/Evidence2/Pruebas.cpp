// Daniel Gómez Guerrero
// A01572201

#include "DoublyLinkedList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main() {
    DoublyLinkedList<int> doublyList;
    LinkedList<int> singlyList;
    Queue<int> queue;
    Stack<int> stack;

    cout << "En caso de estructura vacia\n";

    cout << "-- Queue --\n";
    cout << "Pop en cola vacia:\n";
    try {
        queue.pop();
    } catch (const out_of_range& e) {
        cout << "La cola esta vacia" << endl;
    }

    cout << "Front en cola vacia:\n";
    try {
        queue.front();
    } catch (const out_of_range& e) {
        cout << "La cola esta vacia" << endl;
    }

    cout << "Push: 3\n";
    queue.push(3);
    cout << "Front: " << queue.front() << endl;
    queue.pop();

    cout << "\n-- Stack --\n";
    cout << "Pop en stack vacio:\n";
    try {
        stack.pop();
    } catch (const out_of_range& e) {
        cout << "El stack esta vacio" << endl;
    }

    cout << "Top en stack vacio:\n";
    try {
        stack.top();
    } catch (const out_of_range& e) {
        cout << "El stack esta vacio" << endl;
    }

    cout << "Push: 2\n";
    stack.push(2);
    cout << "Top: " << stack.top() << endl;
    stack.pop();

    cout << "\n-- LinkedList --\n";
    cout << "LinkedList vacia:\n";
    singlyList.deleteData(2);

    try {
        singlyList.deleteAt(0);
    } catch (const out_of_range& e) {
        cout << "Indice fuera de rango" << endl;
    }

    cout << "Push front: 1\n";
    singlyList.push_front(1);
    singlyList.deleteData(1);

    cout << "DoublyLinkedList vacia:\n";
    doublyList.deleteData(2);

    try {
        doublyList.deleteAt(0);
    } catch (const out_of_range& e) {
        cout << "Indice fuera de rango" << endl;
    }

    cout << "Add first:\n";
    doublyList.addFirst(4);
    doublyList.deleteData(4);

    cout << "\nEn caso de un solo elemento\n";

    cout << "-- Queue --\n";
    queue.push(3);
    cout << "Front: " << queue.front() << endl;
    queue.pop();

    cout << "Pop despues de vaciar la cola:\n";
    try {
        queue.pop();
    } catch (const out_of_range& e) {
        cout << "La cola esta vacia" << endl;
    }

    cout << "\n-- Stack --\n";
    stack.push(2);
    cout << "Top: " << stack.top() << endl;
    stack.pop();

    cout << "Pop despues de vaciar el stack:\n";
    try {
        stack.pop();
    } catch (const out_of_range& e) {
        cout << "El stack esta vacio" << endl;
    }

    cout << "\n-- LinkedList --\n";
    singlyList.push_front(1);
    cout << "Eliminar el unico elemento:\n";
    singlyList.deleteData(1);

    cout << "DoublyLinkedList\n";
    doublyList.addFirst(4);
    cout << "Eliminar el unico elemento:\n";
    doublyList.deleteData(4);

    cout << "\nOperaciones en los extremos\n";

    cout << "-- Queue --\n";
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Front: " << queue.front() << endl;
    queue.pop();
    cout << "Front despues de pop: " << queue.front() << endl;
    queue.pop();
    queue.pop();

    cout << "\n-- Stack --\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top: " << stack.top() << endl;
    stack.pop();
    cout << "Top despues de pop: " << stack.top() << endl;
    stack.pop();
    stack.pop();

    cout << "\n-- LinkedList --\n";
    singlyList.push_front(1);
    singlyList.push_back(2);
    singlyList.push_front(0);

    cout << "Eliminar primer elemento:\n";
    singlyList.deleteAt(0);

    cout << "Eliminar ultimo elemento:\n";
    singlyList.deleteAt(1);

    singlyList.deleteData(1);

    cout << "\n-- DoublyLinkedList --\n";
    doublyList.addFirst(4);
    doublyList.addLast(7);
    doublyList.addFirst(2);

    cout << "Eliminar primer elemento:\n";
    doublyList.deleteAt(0);

    cout << "Eliminar ultimo elemento:\n";
    doublyList.deleteAt(1);

    doublyList.deleteData(4);

    cout << "\nOperaciones con varios elementos\n";

    cout << "-- Queue --\n";
    queue.push(10);
    queue.push(20);
    queue.push(30);

    while (true) {
        try {
            cout << "Front: " << queue.front() << endl;
            queue.pop();
        } catch (const out_of_range& e) {
            cout << "Cola vaciada correctamente" << endl;
            break;
        }
    }

    cout << "\n-- Stack --\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (true) {
        try {
            cout << "Top: " << stack.top() << endl;
            stack.pop();
        } catch (const out_of_range& e) {
            cout << "Stack vaciado correctamente" << endl;
            break;
        }
    }

    cout << "\n-- LinkedList --\n";
    singlyList.push_back(10);
    singlyList.push_back(20);
    singlyList.push_back(30);
    
    singlyList.print();

    cout << "Borrar dato especifico (20): ";
    singlyList.deleteData(20);
    
    singlyList.print();

    singlyList.deleteAt(0);
    singlyList.deleteAt(0);

    cout << "\n-- DoublyLinkedList --\n";
    doublyList.addFirst(10);
    doublyList.addLast(20);
    doublyList.addLast(30);

    doublyList.print();

    cout << "Borrar dato especifico (20): ";
    doublyList.deleteData(20);

    doublyList.print();

    doublyList.deleteAt(0);
    doublyList.deleteAt(0);

    return 0;
}