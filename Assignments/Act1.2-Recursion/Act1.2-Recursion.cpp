// Daniel Gómez Guerrero
// A01572201

#include <iostream>
using namespace std;

int sumIterative (int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

int sumRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumRecursive(n - 1);
}

int sumFormula(int n) {
    return n * (n + 1) / 2;
}

int fibonacciIterative(int n) {
    int a = 1;
    int b = 1;
    int c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int fibonacciRecursive(int n) {
    if (n <= 2) {
        return 1;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int bacteriasIterative(int n) {
    double born = 3.78;
    double died = 2.34;
    int sum = 1;

    for (int i = 1; i <= n; i++) {
        int bacBorn = sum * born;
        int bacDied = sum * died;
        sum += bacBorn - bacDied;
    }

    return sum;
}

int bacteriasRecursive(int n) {
    if (n == 0) {
        return 1;
    }

    int bacteria = bacteriasRecursive(n - 1);
    int born = bacteria * 3.78;
    int died =  bacteria * 2.34;

    return bacteria + born - died;
}

int investmentIterative(int n) {

}

int investmentRecursive(int n) {

}

int powIterative(int n) {

}

int powRecursive(int n) {

}

int main() {

    // Suma Iterativa
    cout << "La suma iterativa de 5 es: " << sumIterative(5) << endl;

    // Suma Recursiva
    cout << "La suma recursiva de 5 es: " << sumRecursive(5) << endl;

    // Suma con Formula
    cout << "La suma con formula de 5 es: " << sumFormula(5) << endl;

    // Fibonacci Iterativo
    cout << "El fibonacci iterativo de 8 es: " << fibonacciIterative(8) << endl;

    // Fibonacci Recursivo
    cout << "El fibonacci recursivo de 8 es: " << fibonacciRecursive(8) << endl;

    // Bacterias Iterativas
    cout << "La cantidad de bacterias iterativas en 5 dias es: " << bacteriasIterative(5) << endl;

    // Bacterias Recursivas
    cout << "La cantidad de bacterias recursivas en 5 dias es: " << bacteriasRecursive(5) << endl;
}