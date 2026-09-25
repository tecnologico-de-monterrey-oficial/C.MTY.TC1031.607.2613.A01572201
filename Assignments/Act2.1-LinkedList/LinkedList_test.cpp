// Daniel Gómez Guerrero
// A01572201

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<string> list;
    /*list.push_front("b");
    list.push_front("a");
    list.push_front("@");
    list.push_front("&");*/
    list.push_back("b");
    list.push_back("a");
    list.push_back("@");
    list.push_back("&");
    list.print();

    return 0;
}