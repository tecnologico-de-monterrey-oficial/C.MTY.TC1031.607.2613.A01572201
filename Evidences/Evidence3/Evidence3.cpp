// Daniel Gómez Guerrero
// A01572201

#include "BST.h"
#include "Log.h"
#include "Heap.h"
#include "json.hpp"

using json = nlohmann::json;

string monthValues(string month) {
    // creamos un mapa con los valores de los meses y su valor en número
    // para convertir el mes a número
    static const map<string, string> convert {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    // buscamos el mes en el mapa y retornamos su valor en número, si no se encuentra retornamos "00"
    auto it = convert.find(month);
    return (it != convert.end()) ? it->second : "00";
};

void generateFile(const string& fileName, const vector<Log>& list, int inicio, int fin) {
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
    // verificamos que el archivo se haya abierto correctamente
    if (!fileIn.is_open()) {
        cout << "Error al abrir log607-3.json" << endl;
        return 1;
    }

    // aefinir archivos de salida
    string outputFile1 = "output608-1.out";
    string outputFile2 = "output608-2.out";

    // objetos para almacenar los logs
    Heap<Log, greater<Log>> minHeapLogs;
    Heap<Log, less<Log>> maxHeapLogs;
    BST<string> logsBST;

    // vectores para almacenar los logs
    vector<Log> sortLogs1, sortLogs2;

    // variables para parcear el archivo JSON
    json dataJson;
    fileIn >> dataJson;

    // ciclo para leer el archivo línea por línea
    for (const auto& logJson : dataJson) {
        // extraemos los datos del log
        string month = logJson.at("month").get<string>();
        string day = logJson.at("day").get<string>();
        string year = logJson.at("year").get<string>();
        string time = logJson.at("time").get<string>();
        string ip = logJson.at("ip").get<string>();
        string message = logJson.at("message").get<string>();

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

        // creamos el rawLog con los datos originales
        log.rawLog = month + " " + day + " " + year + " " + time + " " + ip + " " + message;

        // creamos la clave única del log
        log.key = log.createKey(year, monthValues(month), day, log.time, log.ip);

        // agregamos el log a los heaps y al BST
        minHeapLogs.push(log);
        maxHeapLogs.push(log);
        logsBST.insert(log.key);
    }
    
    // inicializamos variables para menu
    int option = -1;
    bool sortMaxHeap = false;
    string ipSearch;

    // mapa para contar las ocurrencias de cada IP
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
            case 1: {
                sortLogs1.clear();
                // creamos una copia temporal del maxHeapLogs para no perder los datos
                Heap<Log, less<Log>> tempMax = maxHeapLogs;

                // extraemos los logs del maxHeapLogs y los guardamos en sortLogs1
                while (!tempMax.empty()) {
                    sortLogs1.push_back(tempMax.pop());
                }

                // generamos el archivo de salida con los logs ordenados de mayor a menor
               if (!sortLogs1.empty()) {
                    generateFile(outputFile1, sortLogs1, 0, static_cast<int>(sortLogs1.size()) - 1);
                }

                cout << "Archivo generado: " << outputFile1 << endl;
                sortMaxHeap = true;
                break;
            }
            
            case 2: {
                sortLogs2.clear();
                // creamos una copia temporal del minHeapLogs para no perder los datos
                Heap<Log, greater<Log>> tempMin = minHeapLogs;

                // extraemos los logs del minHeapLogs y los guardamos en sortLogs2
                while (!tempMin.empty()) {
                    sortLogs2.push_back(tempMin.pop());
                }

                // generamos el archivo de salida con los logs ordenados de menor a mayor
               if (!sortLogs2.empty()) {
                    generateFile(outputFile2, sortLogs2, 0, static_cast<int>(sortLogs2.size()) - 1);
                }
                
                cout << "Archivo generado: " << outputFile2 << endl;
                break;
            }
            
            case 3: {
                // verificamos que se haya generado el archivo ordenado de mayor a menor
                if (!sortMaxHeap) {
                    cout << "\nEl documento ordenado no se ha generado aun (realizar accion 1 primero).\n";
                    break;
                }

                // creamos un mapa para contar las ocurrencias de cada IP desde sortLogs1
                ipMap.clear();
                for (const auto& log : sortLogs1) {
                    ipMap[log.ip]++;
                }

                // se pasan los pares (IP, frecuencia) a un vector para ordenarlos de mayor a menor
                vector<pair<string, int>> rankedIps(ipMap.begin(), ipMap.end());
                // ordenamos el vector de pares por frecuencia y luego por IP
                sort(rankedIps.begin(), rankedIps.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                    // primero comparamos por frecuencia (segundo elemento del par)
                    if (a.second != b.second) {
                        // si las frecuencias son diferentes, ordenamos de mayor a menor
                        return a.second > b.second;
                    }
                    // si las frecuencias son iguales, ordenamos por IP (primer elemento del par) de menor a mayor
                    return a.first < b.first;
                });

                cout << "\nTop 10 de IPs con mas registros:\n";
                // mostramos las 10 IPs con más registros
                for (int i = 0; i < 10 && i < static_cast<int>(rankedIps.size()); i++) {
                    cout << "IP: " << rankedIps[i].first << " - Registros: " << rankedIps[i].second << endl;
                }
                break;
            }

            case 4: {
                cout << "Ingrese la IP a buscar en el BST: ";
                cin >> ipSearch;

                // arreglamos la IP ingresada por el usuario para que coincida con el formato de las claves en el BST
                string arrangedSearch = Log().arrangeIp(ipSearch);
                // buscamos la IP en el BST y obtenemos el resultado
                searchResult res = logsBST.search(arrangedSearch);
                if (res.found) {
                    cout << "\nLa IP " << ipSearch << " tiene " << res.count << " registros\n";
                } else {
                    cout << "\nLa IP " << ipSearch << " no fue encontrada en el BST.\n";
                }
                break;
            }

            case 5:
                // salimos del programa
                cout << "Saliendo del programa..." << endl;
                return 0;

            default: 
                cout << "Opcion no valida. Intente de nuevo." << endl;
                option = -1; // reiniciamos la opción para que el ciclo continue
                break;
        }
    
    }
}