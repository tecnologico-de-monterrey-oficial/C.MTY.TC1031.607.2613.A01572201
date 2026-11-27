// Daniel Gómez Guerrero
// A01572201

#include "BST.h"
#include "Log.h"
#include "Heap.h"
#include "json.hpp"

using json = nlohmann::json;

/*struct IpRecord {
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
};*/

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
    // archivo de entrada
    ifstream fileIn("log607-3.json");
    // aefinir archivos de salida
    string outputFile1 = "output608-1.out";
    string outputFile2 = "output608-2.out";
    // variable para almacenar cada renglon del archivo
    string line;
    // variables para guardar los datos de los logs
    string  month, day, year, time, ip, message;
    // objetos para almacenar los logs
    Heap<Log, greater<Log>> minHeapLogs;
    Heap<Log, less<Log>> maxHeapLogs;
    BST<string> logsBST;
    // vectores para almacenar los logs
    vector<Log> sortLogs1, sortLogs2;
    // ciclo para leer el archivo línea por línea
    while (getline(fileIn, line)) {
        // parseamos el renglón como JSON
        json logJson = json::parse(line);
        // extraemos los datos del log
        month = logJson["month"];
        day = logJson["day"];
        year = logJson["year"];
        time = logJson["time"];
        ip = logJson["ip"];
        message = logJson["message"];

        // creamos un objeto Log y le asignamos los datos
        Log log;
        log.month = month;
        log.day = day;
        log.year = year;
        log.time = time;
        log.ip = ip;
        log.log = message;
        // arreglamos la IP y el tiempo
        log.ip = log.arrangeIp(ip);
        log.time = log.arrangeTime(time);
        // creamos la clave única del log
        log.key = log.createKey(year, monthValues(month), day, time, ip);

        // agregamos el log a los heaps y al BST
        minHeapLogs.push(log);
        maxHeapLogs.push(log);
        logsBST.insert(log.key);
    }
    
    // inicializamos variables para menu
    int option = -1;
    bool sortMaxHeap = false;
    string ipSearch;
    int ipCount = 0;

    // inicializamos estructuras de datos para almacenar los logs y las IPs
    BST<string> holdBST;
    Heap<int, less<int>> holdHeap;
    map<string, int> ipMap;

    // ciclo para mostrar el menú y procesar las opciones
    while (option != 5) {
        cout << "\nQue accion desea realizar?" << endl;
        cout << "1. Ordenar de mayor a menor (MaxHeap)." << endl;
        cout << "2. Ordenar de menor a mayor (MinHeap)." << endl;
        cout << "3. Top 10 de IPs con más registros (MaxHeap)." << endl;
        cout << "4. Búsqueda por IP con BST." << endl;
        cout << "5. Salir." << endl;
        cin >> option;

        switch (option) {
            case 1: 
                sortLogs1.clear();
                // extraemos los logs del maxHeapLogs y los guardamos en sortLogs1
                while (!maxHeapLogs.empty()) {
                    sortLogs1.push_back(maxHeapLogs.pop());
                }
                // generamos el archivo de salida con los logs ordenados de mayor a menor
                generateFile(outputFile1, sortLogs1, 0, static_cast<int>(sortLogs1.size()) - 1);
                cout << "Archivo generado: " << outputFile1 << endl;
                sortMaxHeap = true;
                break;
            
            case 2:
                sortLogs2.clear();
                // extraemos los logs del minHeapLogs y los guardamos en sortLogs2
                while (!minHeapLogs.empty()) {
                    sortLogs2.push_back(minHeapLogs.pop());
                }
                // generamos el archivo de salida con los logs ordenados de menor a mayor
                generateFile(outputFile2, sortLogs2, 0, static_cast<int>(sortLogs2.size()) - 1);
                cout << "Archivo generado: " << outputFile2 << endl;
                break;
            
            case 3:
    }
    

}