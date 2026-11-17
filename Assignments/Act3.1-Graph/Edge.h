// Daniel Gómez Guerrero
// A01572201

#pragma once
#include <string>

using namespace std;

struct Edge {
    string source;
    string target;
    int weight;
    Edge() : source(""), target(""), weight(0) {};
};