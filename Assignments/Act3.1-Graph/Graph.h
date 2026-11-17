// Daniel Gómez Guerrero
// A01572201

#ifndef Graph_h
#define Graph_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Edge.h"
using namespace std;

class Graph {
private:
    vector<string> vertices;
    vector<vector<Edge> > adjList;
    int findVertex(string vertex);
public:
    Graph() {};
    void addVertex(string vertex);
    void addEdge(Edge edge);
    void print();
    void BFS(string vertex);
};

int Graph::findVertex(string vertex) {
    // Busca el vértice y devuelve su posición dentro del vector.
    auto it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    }
    return -1;
}

void Graph::addVertex(string vertex) {
    if (findVertex(vertex) == -1) {
        vertices.push_back(vertex);
        adjList.push_back(vector<Edge>()); // <-
    } else {
        throw invalid_argument("el vértice ya existe");
    }
}

void Graph::addEdge(Edge edge) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);

    if (sourceIndex == -1 || targetIndex == -1) {
        throw invalid_argument("La fuente o el destino no existen");
    }

    adjList[sourceIndex].push_back(edge);
}

void Graph::BFS(string vertex) {
    vector<bool> status(vertices.size(), false);
    queue<int> q;
    int index = findVertex(vertex);
    if (index != -1) {
        q.push(index);
        status[index] = true;
        while (!q.empty()) {
            index = q.front();
            cout << vertices[index] << " ";
            q.pop();
            for (auto neighbor : adjList[index]) {
                int neighborIndex = findVertex(neighbor.target);
                // voy a asumir que existe
                if (!status[neighborIndex]) {
                    q.push(neighborIndex);
                    status[neighborIndex] = true;
                }
            }
        }
        cout << endl;
    }
}

void Graph::print() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j].target << "-" << adjList[i][j].weight;
            if (j < adjList[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

#endif /* Graph_h */