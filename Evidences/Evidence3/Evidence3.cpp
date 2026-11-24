// Daniel Gómez Guerrero
// A01572201

#include "BST.h"
#include "Log.h"
#include "Heap.h"

struct IpRecord {
    string rawIp;
    string numericIp;

    // constructores
    IpRecord() : rawIp(""), numericIp("") {}
    IpRecord(const string& ip, const string& arrangedIp) : rawIp(ip), numericIp(arrangedIp) {}

    // Sobrecarga de operadores
    bool operator==(const IpRecord& other) const {
        return numericIp == other.numericIp;
    }

    bool operator<(const IpRecord& other) const {
        return numericIp < other.numericIp;
    }

    friend ostream& operator<<(ostream& os, const IpRecord& record) {
        os << record.rawIp;
        return os;
    }
};

string monthValues(string month) {
    // creamos un mapa con los valores de los meses y su valor en número
    // para convertir el mes a número
    map<string, string> convert {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    return convert[month];
};

void generateFile(string fileName, vector<Log> list, int inicio, int fin) {
    // creamos un archivo con el nombre fileName
    ofstream file;

    // abrimos el archivo en modo escritura y truncado
    file.open(fileName, ofstream::out | fstream::trunc);

    // si el archivo se abrió correctamente, escribimos los logs en el archivo
    if (file.is_open()) {
        // iteramos desde inicio hasta fin
        for (int i = inicio; i <= fin; i++) {
            // escribimos el log en la posición i en el archivo
            file << list[i].rawLog << endl;
        }
    } else {
        // si el archivo no se abrió correctamente, imprimimos un mensaje de error
        cout << "Error al abrir el archivo" << endl;
    }

    // cerramos el archivo
    file.close();
}

int main() {
    // Archivo de entrada
    ifstream fileIn("log607-3.json");
}