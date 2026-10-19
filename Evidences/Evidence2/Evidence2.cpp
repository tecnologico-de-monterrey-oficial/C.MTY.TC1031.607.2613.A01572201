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

void generateFile(string fileName, DoublyLinkedList<Log> &list, int start, int end) {
    // creamos un archivo con el nombre fileName
    ofstream file;

    // abrimos el archivo en modo escritura y truncado
    file.open(fileName, ofstream::out | fstream::trunc);

    // si el archivo se abrió correctamente, escribimos los logs en el archivo
    if (file.is_open()) {
        // iteramos desde start hasta end
        for (int i = start; i <= end; i++) {
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
    // variables
    int left, right, option;
    long long totalComparisons = 0;
    int maxRecursionDepth = 0;
    bool sorted = false;
    auto startTime = chrono::high_resolution_clock::now();
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    string line;
    string fileUsed;
    string lastUsedDate = "";
    map<string, int> eventNums, dayNums, ipNums;
    int maxEvent, maxDay, maxIp;
    maxEvent = maxDay = maxIp = 0;
    string maxEventStr, maxDayStr, maxIpStr, ogIp; 
    maxEventStr = maxDayStr = maxIpStr = "";

    // variables para guardar los datos de los logs
    Log tempLog, startLog, endLog;

    // creamos los vectores de logs
    DoublyLinkedList<Log> logs, logsUnsorted, logsRange;

    // inicializamos la lectura del archivo
    ifstream inputFile;

    // nombre de los archivos de salida
    string outputFile = "output608.txt";

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
        inputFile.open("./data/log607-1.txt");
        fileUsed = "log607-1.txt";
    } else if (option == 2) {
        // abrimos el archivo log607-2.txt
        inputFile.open("./data/log607-2.txt");
        fileUsed = "log607-2.txt";
    } 

    // validamos que el archivo se haya abierto correctamente
        if (!inputFile.is_open()) {
            cout << "Error al abrir el archivo" << endl;
            return 1;
        }

    // Fila de logs
    Queue<string> logsQueue;

    // leemos el archivo línea por línea y guardamos los logs en la fila
    while (getline(inputFile, line)) {
        if (!line.empty()) {
            logsQueue.push(line);
        }
    }
    inputFile.close();

    // procesamos la fila de logs y los guardamos en la lista de logs
    int logCount = 0;
    int skippedCount = 0;
    int lineNumber = 0;

    while (!logsQueue.isEmpty()) {
        lineNumber++;
        string currentLine = logsQueue.front();
        logsQueue.pop();

        // creamos un log temporal y le asignamos la línea actual
        tempLog.rawLog = currentLine; 

        // validamos que la línea no esté vacía
        if (currentLine.empty()) {
            cout << "Linea " << lineNumber << " omitida debido a que esta vacia." << endl;
            skippedCount++;
            continue;
        }

        // procesamos la línea del log
        stringstream ss(currentLine);
        ss >> tempLog.month >> tempLog.day >> tempLog.year >> tempLog.time >> tempLog.ip;
        getline(ss, tempLog.log);

        // Comprobacion de los campos del log
        // Validacion de year
        try {
            int yearInt = stoi(tempLog.year);
            if (yearInt < 2000 || yearInt > 2099) {
                throw invalid_argument("Año fuera de rango");
            }
        } catch (const invalid_argument& e) {
            cout << "Linea " << lineNumber << " omitida debido a año invalido: " << tempLog.year << endl;
            skippedCount++;
            continue;
        }

        // Validacion de month
        if(monthValues(tempLog.month) == "") {
            cout << "Linea " << lineNumber << " omitida debido a mes invalido: " << tempLog.month << endl;
            skippedCount++;
            continue;
        }

        // Validacion de day
        try {
            int dayInt = stoi(tempLog.day);
            if (dayInt < 1 || dayInt > 31) {
                throw invalid_argument("Dia fuera de rango");
            }
        } catch (const invalid_argument& e) {
            cout << "Linea " << lineNumber << " omitida debido a dia invalido: " << tempLog.day << endl;
            skippedCount++;
            continue;
        }

        // Validacion de time
        try {
            stringstream timeStream(tempLog.time);
            string segment;
            vector<string> segments;
            while (getline(timeStream, segment, ':')) {
                segments.push_back(segment);
            }
            if (segments.size() != 3) {
                throw invalid_argument("Formato de tiempo invalido");
            }
            int hour = stoi(segments[0]);
            int minute = stoi(segments[1]);
            int second = stoi(segments[2]);
            if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
                throw invalid_argument("Tiempo fuera de rango");
            }
        } catch (const invalid_argument& e) {
            cout << "Linea " << lineNumber << " omitida debido a tiempo invalido: " << tempLog.time << endl;
            skippedCount++;
            continue;
        }

        // Validacion de ip
        stringstream ipStream(tempLog.ip);
        string ipSegment;
        vector<string> ipSegments;
        while (getline(ipStream, ipSegment, '.')) {
            ipSegments.push_back(ipSegment);
        }
        if (ipSegments.size() != 4) {
            cout << "Linea " << lineNumber << " omitida debido a IP invalida: " << tempLog.ip << endl;
            skippedCount++;
            continue;
        }
        bool validIp = true;
        for (const string& segment : ipSegments) {
            try {
                int segmentInt = stoi(segment);
                if (segmentInt < 0 || segmentInt > 255) {
                    validIp = false;
                    break;
                }
            } catch (const invalid_argument& e) {
                validIp = false;
                break;
            }
        }
        if (!validIp) {
            cout << "Linea " << lineNumber << " omitida debido a IP invalida: " << tempLog.ip << endl;
            skippedCount++;
            continue;
        }


        // arreglamos la IP y el tiempo
        ogIp = tempLog.ip;
        tempLog.ip = tempLog.arrangeIp(tempLog.ip);
        tempLog.time = tempLog.arrangeTime(tempLog.time);

        // creamos la clave única del log
        tempLog.key = tempLog.createKey(tempLog.year, monthValues(tempLog.month), tempLog.day, tempLog.time, tempLog.ip);

        // Conteo de eventos, días y direcciones IP
        eventNums[tempLog.log]++;
        if (eventNums[tempLog.log] > maxEvent) {
            maxEvent = eventNums[tempLog.log];
            maxEventStr = tempLog.log;
        } else if (eventNums[tempLog.log] == maxEvent) {
            maxEventStr += ", " + tempLog.log;
        }

        dayNums[tempLog.day + tempLog.month + tempLog.year]++;
        if (dayNums[tempLog.day + tempLog.month + tempLog.year] > maxDay) {
            maxDay = dayNums[tempLog.day + tempLog.month + tempLog.year];
            maxDayStr = tempLog.day + "-" + tempLog.month + "-" + tempLog.year;
        } else if (dayNums[tempLog.day + tempLog.month + tempLog.year] == maxDay) {
            maxDayStr += ", " + tempLog.day + "-" + tempLog.month + "-" + tempLog.year;
        }

        ipNums[tempLog.ip]++;
        if (ipNums[tempLog.ip] > maxIp) {
            maxIp = ipNums[tempLog.ip];
            maxIpStr = ogIp;
        } else if (ipNums[tempLog.ip] == maxIp) {
            maxIpStr += ", " + ogIp;
        }

        // agregamos el log a la lista de logs
        logs.addLast(tempLog);
        logCount++;
    }

    cout << "\n--- LECTURA DE DATOS (" << fileUsed << ") ---" << endl;
    cout << "Registros cargados: " << logCount << endl;
    cout << "Registros omitidos: " << skippedCount << endl;

    // creamos una copia de respaldo desordenada
    logsUnsorted = logs;

    // variables para predicción del usuario
    string predictionComplexity;
    string predictionDif;
    
    // inicializamos opción para arrancar el ciclo del menú principal
    option = -1;
    // validamos que la opción este disponible y sea distinta a salida (0)
    while (option != 0) {

        cout << "\nQue accion desea realizar?" << endl;
        cout << "1. Ordenar logs" << endl;
        cout << "2. Buscar logs por dia" << endl;
        cout << "3. Mostrar logs por dia en orden descendente" << endl;
        cout << "4. Mostrar estadisticas del archivo" << endl;
        cout << "5. Salir" << endl;
        cin >> option;

        switch (option) {
            case 1:
                if (sorted) {
                    cout << "\nLa lista ya esta ordenada.\n\n";
                    break;
                }
                
                cout << "\nCual es tu prediccion del crecimiento en el numero de comparaciones? (por ejemplo, aproximadamente nlogn o n^2)" << endl;
                cin >> predictionComplexity;

                /*cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);*/

                // variables para ver total de comparaciones y profundidad máxima de recursión
                totalComparisons = 0;
                maxRecursionDepth = 0;

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                logs.sort(logs, 0, logs.size - 1, 1, maxRecursionDepth, totalComparisons);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.size == 0){
                    cout << "\nNo fue posible guardar la lista.\nLa lista esta vacia.\n\n";
                    break;
                }

                predictionDif = "nlogn";

                // imprimimos la información detallada de la corrida
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Merge Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano de la lista: " << logs.size << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Numero de comparaciones: " << totalComparisons << " comparaciones" << endl;
                cout << "Profundidad maxima de recursion alcanzada: " << maxRecursionDepth << endl;
                cout << "Complejidad teorica: " << predictionDif << endl;
                cout << "Tu prediccion: " << predictionComplexity << endl;
                //cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == predictionComplexity) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion no fue correcta." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size - 1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            
            case 2: {
                // validamos que la lista este ordenada antes de buscar
                if (!sorted) {
                    cout << "\nLa lista no esta ordenada, por favor ordene la lista primero.\n\n";
                    break;
                }

                // Limpiamos el búfer antes de leer la línea con espacios
                cin.ignore();

                // pedimos al usuario que ingrese la fecha a buscar
                string dateStr;
                cout << "\nIngrese la fecha a buscar (por ejemplo: Sep 14 2024): ";
                getline(cin, dateStr);

                // creamos un stringstream para separar la fecha en mes, día y año
                stringstream dateStream(dateStr);
                string searchMonth, searchDay, searchYear;
                dateStream >> searchMonth >> searchDay >> searchYear;

                // validamos que los campos de la fecha no estén vacíos
                if (searchMonth.empty() || searchDay.empty() || searchYear.empty()) {
                    cout << "Formato de fecha incompleto. Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de año
                try {
                    int yearInt = stoi(searchYear);
                    if (yearInt < 2000 || yearInt > 2099) {
                        throw invalid_argument("Año fuera de rango");
                    }
                } catch (const invalid_argument& e) {
                    cout << "Año invalido: " << searchYear << ". Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de mes
                if (monthValues(searchMonth) == "") {
                    cout << "Mes invalido: " << searchMonth << ". Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de día
                try {
                    int dayInt = stoi(searchDay);
                    if (dayInt < 1 || dayInt > 31) {
                        throw invalid_argument("Dia fuera de rango");
                    }
                } catch (const invalid_argument& e) {
                    cout << "Dia invalido: " << searchDay << ". Intente de nuevo.\n\n";
                    break;
                }

                // Guardamos la última fecha utilizada para búsquedas
                lastUsedDate = dateStr;

                // creamos la clave de búsqueda
                string formatDay = searchDay;
                if (formatDay.length() < 2) formatDay = "0" + formatDay;
                string formatMonthNum = monthValues(searchMonth);
                string searchDateKey = searchYear + formatMonthNum + formatDay;

                // buscamos la fecha en la lista de logs
                int foundCount = 0;
                cout << "\n--- RESULTADOS DE BUSQUEDA PARA: " << dateStr << " ---" << endl;

                for (int i = 0; i < logs.size; i++) {
                    // obtenemos la clave de fecha del log actual (los primeros 8 caracteres de la clave)
                    string logDateKey = logs[i].key.substr(0, 8);

                    // Si la fecha del log es menor a la buscada, seguimos buscando
                    if (logDateKey < searchDateKey) {
                        continue;
                    }

                    // Si la fecha del log coincide exactamente con la buscada
                    if (logDateKey == searchDateKey) {
                        // mostramos el log encontrado y aumentamos el contador de encontrados
                        cout << logs[i].log << endl;
                        foundCount++;
                    } else if (logDateKey > searchDateKey) {
                        // Como la lista está ordenada, en cuanto la clave supere la fecha buscada, nos detenemos
                        break;
                    }
                }
                cout << "-----------------------------------------------" << endl;
                if (foundCount == 0) {
                    cout << "No se encontraron registros para la fecha especificada.\n" << endl;
                } else {
                    cout << "Total de registros encontrados: " << foundCount << "\n" << endl;
                }
                break;
            }

            case 3: {
                // validamos que la lista este ordenada antes de buscar
                if (!sorted) {
                    cout << "\nLa lista no esta ordenada, por favor ordene la lista primero.\n\n";
                    break;
                }

                string dateStr = "";

                // Si ya se hizo una búsqueda previa, la reutilizamos
                if (!lastUsedDate.empty()) {
                    cout << "\nUsando la ultima fecha consultada (" << lastUsedDate << ")..." << endl;
                    dateStr = lastUsedDate;
                } else {
                    cin.ignore();
                    cout << "\nAun no se ha realizado ninguna busqueda previa." << endl;
                    cout << "Ingrese la fecha a buscar en orden descendente (por ejemplo: Sep 14 2024): ";
                    getline(cin, dateStr);
                }

                // creamos un stringstream para separar la fecha en mes, día y año
                stringstream dateStream(dateStr);
                string searchMonth, searchDay, searchYear;
                dateStream >> searchMonth >> searchDay >> searchYear;

                // validamos que los campos de la fecha no estén vacíos
                if (searchMonth.empty() || searchDay.empty() || searchYear.empty()) {
                    cout << "Formato de fecha incompleto. Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de año
                try {
                    int yearInt = stoi(searchYear);
                    if (yearInt < 2000 || yearInt > 2099) {
                        throw invalid_argument("Año fuera de rango");
                    }
                } catch (const invalid_argument& e) {
                    cout << "Año invalido: " << searchYear << ". Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de mes
                if (monthValues(searchMonth) == "") {
                    cout << "Mes invalido: " << searchMonth << ". Intente de nuevo.\n\n";
                    break;
                }

                // Validacion de día
                try {
                    int dayInt = stoi(searchDay);
                    if (dayInt < 1 || dayInt > 31) {
                        throw invalid_argument("Dia fuera de rango");
                    }
                } catch (const invalid_argument& e) {
                    cout << "Dia invalido: " << searchDay << ". Intente de nuevo.\n\n";
                    break;
                }

                // Guardamos la última fecha utilizada para búsquedas
                lastUsedDate = dateStr;

                // creamos la clave de búsqueda
                string formatDay = searchDay;
                if (formatDay.length() < 2) formatDay = "0" + formatDay;
                string formatMonthNum = monthValues(searchMonth);
                string searchDateKey = searchYear + formatMonthNum + formatDay;

                // buscamos la fecha en la lista de logs y los guardamos en una pila para mostrarlos en orden descendente
                Stack<string> logStack;
                int foundCount = 0;

                for (int i = 0; i < logs.size; i++) {
                    // obtenemos la clave de fecha del log actual (los primeros 8 caracteres de la clave)
                    string logDateKey = logs[i].key.substr(0, 8);

                    // Si la fecha del log es menor a la buscada, seguimos buscando
                    if (logDateKey < searchDateKey) continue;

                    // Si la fecha del log coincide exactamente con la buscada, lo agregamos a la pila
                    if (logDateKey == searchDateKey) {
                        // agregamos el log a la pila para mostrarlo en orden descendente
                        logStack.push(logs[i].log);
                        foundCount++;
                    } else if (logDateKey > searchDateKey) {
                        // Como la lista está ordenada, en cuanto la clave supere la fecha buscada, nos detenemos
                        break;
                    }
                }

                cout << "\n--- RESULTADOS EN ORDEN DESCENDENTE PARA: " << dateStr << " ---" << endl;
                if (foundCount == 0) {
                    cout << "No se encontraron registros para la fecha especificada.\n" << endl;
                } else {
                    while (!logStack.isEmpty()) {
                        cout << logStack.top() << endl;
                        logStack.pop();
                    }
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Total de registros encontrados: " << foundCount << "\n" << endl;
                }
                break;
            }

            case 4:
                // verificamos que haya registros para mostrar estadísticas
                if (logs.size == 0) {
                    cout << "\nNo hay registros para mostrar estadisticas.\n\n";
                    break;
                }

                // mostramos las estadísticas del archivo
                cout << "\n--- ESTADISTICAS DEL ARCHIVO (" << fileUsed << ") ---" << endl;
                cout << "Total de registros cargados: " << logCount << endl;
                cout << "Evento mas frecuente: " << maxEventStr << " con " << maxEvent << " ocurrencias" << endl;
                cout << "Dia mas frecuente: " << maxDayStr << " con " << maxDay << " ocurrencias" << endl;
                cout << "IP mas frecuente: " << maxIpStr << " con " << maxIp << " ocurrencias" << endl;
                break;

            case 5:
                // salimos del programa
                cout << "Saliendo del programa..." << endl;
                return 0;
        }
    }
}