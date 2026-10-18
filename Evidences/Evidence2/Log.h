// Daniel Gómez Guerrero
// A01572201

#ifndef Log_h
#define Log_h

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <chrono> 
#include <algorithm>
using namespace std;

struct Log {
    // Atributos
    string year;
    string month;
    string day;
    string time;
    string ip;
    string log;
    string key;

    // Constructor
    Log() {
        year = "";
        month = "";
        day = "";
        time = "";
        ip = "";
        log = "";
        key = "";
    };

    // Métodos
    // Método para arreglar la IP agregando ceros a la izquierda
    string arrangeIp(string ip) {
        // creamos un stringstream con la ip
        stringstream ipStream(ip);

        // creamos un vector de strings para guardar los segmentos de la ip
        string segment;
        vector<string> segments;

        // iteramos mientras haya segmentos en la ip
        while (getline(ipStream, segment, '.')) {
            // agregamos el segmento al vector de segmentos
            segments.push_back(segment);
        }

        // iteramos hasta que cada segmento tenga 3 digitos
        for (int i = 0; i < segments.size(); i++) {
            // si el segmento tiene menos de 3 digitos, agregamos ceros a la izquierda
            while (segments[i].length() < 3) {
                // agregamos un cero a la izquierda del segmento
                segments[i] = "0" + segments[i];
            }
        }

        // retornamos la ip arreglada
        return segments[0] + segments[1] + segments[2] + segments[3];
    };

    // Método para arreglar el tiempo
    string arrangeTime(string time) {
        // creamos un stringstream con el tiempo
        stringstream timeStream(time);

        // creamos un vector de strings para guardar los segmentos del tiempo
        string segment;
        vector<string> segments;

        // iteramos mientras haya segmentos en el tiempo
        while (getline(timeStream, segment, ':')) {
            // agregamos el segmento al vector de segmentos
            segments.push_back(segment);
        }

        // iteramos hasta que cada segmento tenga 2 digitos
        for (int i = 0; i < segments.size(); i++) {
            // si el segmento tiene menos de 2 digitos, agregamos un cero a la izquierda
            while (segments[i].length() < 2) {
                // agregamos un cero a la izquierda del segmento
                segments[i] = "0" + segments[i];
            }
        }

        // retornamos el tiempo arreglado
        return segments[0] + segments[1] + segments[2];
    };

    // Método para crear la clave única del log
    string createKey(string year, string month, string day, string time, string ip) {
        return year + month + day + time + ip;
    };

    // Sobrecarga de operadores
    bool operator>(const Log &other) const {
        return key > other.key;
    };

    bool operator<(const Log &other) const {
        return key < other.key;
    };

    bool operator==(const Log &other) const {
        return key == other.key;
    };

    bool operator!=(const Log &other) const {
        return key != other.key;
    };

    bool operator>=(const Log &other) const {
        return key >= other.key;
    };

    bool operator<=(const Log &other) const {
        return key <= other.key;
    };
};

#endif /* Log_h */