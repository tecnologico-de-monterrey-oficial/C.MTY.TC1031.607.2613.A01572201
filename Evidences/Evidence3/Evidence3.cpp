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

int main() {

}