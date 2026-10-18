// Daniel Gómez Guerrero
// A01572201

#include "DoublyLinkedList.h"
#include "LinkedList.h"
#include "Log.h"
#include "Queue.h"
#include "Stack.h"

string monthValues(string month) {
    // creamos un mapa con los valores de los meses y su valor en número
    // para convertir el mes a número
    map<string, string> convert {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    return convert[month];
};

void generateFile(string fileName, vector<Log> &list, int start, int end) {
    // creamos un archivo con el nombre fileName
    ofstream file;

    // abrimos el archivo en modo escritura y truncado
    file.open(fileName, ofstream::out | fstream::trunc);

    // si el archivo se abrió correctamente, escribimos los logs en el archivo
    if (file.is_open()) {
        // iteramos desde start hasta end
        for (int i = start; i <= end; i++) {
            // escribimos el log en la posición i en el archivo
            file << list[i].log << endl;
        }
    } else {
        // si el archivo no se abrió correctamente, imprimimos un mensaje de error
        cout << "Error al abrir el archivo" << endl;
    }

    // cerramos el archivo
    file.close();
}

int main() {
    // variables
    int left, right, option;
    bool sorted = false;
    auto startTime = chrono::high_resolution_clock::now();
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    string line;
    string fileUsed;

    // variables para guardar los datos de los logs
    Log tempLog, startLog, endLog;

    // creamos los vectores de logs
    vector<Log> logs, logsUnsorted, logsRange;

    // inicializamos la lectura del archivo
    ifstream inputFile;

    // nombre de los archivos de salida
    string outputFile = "output608.txt", rangeFile = "range607.txt";

    // pedimos al usuario que ingrese el nombre del archivo a usar
    cout << "Cual es el nombre del archivo que desea usar? (inserte el numero)" << endl;
    cout << "1. log607-1.txt" << endl;
    cout << "2. log607-2.txt" << endl;
    cin >> option;

    // validamos que la opción sea 1 o 2
    while (option != 1 && option != 2) {
        cout << "Opcion invalida, intente de nuevo" << endl;
        cin >> option;
    }

    if (option == 1) {
        // abrimos el archivo log607-1.txt
        inputFile.open("../data/log607-1.txt");
        fileUsed = "log607-1.txt";
    } else if (option == 2) {
        // abrimos el archivo log607-2.txt
        inputFile.open("../data/log607-2.txt");
        fileUsed = "log607-2.txt";
    } 

    // validamos que el archivo se haya abierto correctamente
        if (!inputFile.is_open()) {
            cout << "Error al abrir el archivo" << endl;
            return 1;
        }

    while (getline(inputFile, line)) {
        // creamos un stringstream con la línea leída
        stringstream stream(line);

        // guardamos los datos de la línea en un log temporal
        tempLog.log = line;
        stream >> tempLog.month >> tempLog.day >> tempLog.year >> tempLog.time >> tempLog.ip;

        // creamos la clave única del log
        tempLog.key = tempLog.createKey(tempLog.year, monthValues(tempLog.month), tempLog.day, tempLog.arrangeTime(tempLog.time), tempLog.arrangeIp(tempLog.ip));

        // agregamos el log temporal al vector de logs
        logs.push_back(tempLog);
    }

    // creamos una copia de respaldo desordenada
    logsUnsorted = logs;

    // variables exclusivas para búsqueda binaria y predicción del usuario
    int startIndex;
    int endIndex;
    bool repeat = false;
    string prediction;
    vector<Log> duplicados;
    int predictionMs;
    int predictionDif;
    
    // inicializamos opción para arrancar el ciclo del menú principal
    option = -1;
    // validamos que la opción este disponible y sea distinta a salida (0)
    while (option != 0) {

        cout << "Que accion desea realizar?" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Ordenar logs" << endl;
        cout << "2. Buscar logs por día" << endl;
        cout << "3. Mostrar logs por día en orden descendente" << endl;
        cout << "4. Mostrar estadísticas del archivo" << endl;
        cin >> option;
    }
}