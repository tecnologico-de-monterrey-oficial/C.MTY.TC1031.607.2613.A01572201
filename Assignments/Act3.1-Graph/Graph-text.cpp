// Daniel Gómez Guerrero
// A01572201

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Edge.h"


int main() {
    Graph graph;

    graph.addVertex("Ana");
    graph.addVertex("Beto");
    graph.addVertex("Caro");
    graph.addVertex("Dani");
    graph.addVertex("Eli");
    graph.addVertex("Fer");
    graph.addVertex("Gabo");
    graph.addVertex("Hugo");
    graph.addVertex("Iris");

    auto addEdge = [&graph](string source, string target, int weight) {
        Edge edge;
        edge.source = source;
        edge.target = target;
        edge.weight = weight;
        graph.addEdge(edge);
    };

    addEdge("Ana", "Beto", 1);
    addEdge("Ana", "Dani", 1);
    addEdge("Beto", "Caro", 1);
    addEdge("Beto", "Dani", 1);
    addEdge("Caro", "Eli", 1);
    addEdge("Caro", "Fer", 1);
    addEdge("Dani", "Eli", 1);
    addEdge("Dani", "Gabo", 1);
    addEdge("Eli", "Hugo", 1);
    addEdge("Fer", "Iris", 1);
    addEdge("Gabo", "Hugo", 1);
    addEdge("Hugo", "Iris", 1);

    graph.print();
    graph.BFS("Ana");


    return 0;
}