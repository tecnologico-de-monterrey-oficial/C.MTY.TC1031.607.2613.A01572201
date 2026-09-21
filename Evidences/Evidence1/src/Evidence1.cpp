// Daniel Gómez Guerrero
// A01572201

#include "..\include\Log.h"


template <typename T>
void swapSort(vector<T> &list) {
    // iteramos toda la lista, de principio a 1 antes del final
    for (int i = 0; i < list.size() - 1; i++) {
        // iteramos desde el siguiente índice hasta el final
        for (int j = i + 1; j < list.size(); j++) {
            // creamos variables auxiliares para guardar los valores de i y j
            T a = list[i];
            T b = list[j];

            // comparamos el valor de i contra j
            if (list[i] > list[j]) {
                // si es mayor, los intercambiamos
                list[i] = b;
                list[j] = a;
            }
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &list) {
    // creamos una variable booleana para controlar si hubo cambios en la iteración
    bool change = true;

    // iteramos desde el final de la lista hasta el principio, mientras haya cambios
    for (int i = list.size() - 1; i > 0 && change; i--) {
        // reiniciamos la variable de cambios a false
        change = false;

        // iteramos desde el principio de la lista hasta el índice i
        for (int j = 0; j < i; j++) {
            // comparamos el valor de j contra j + 1
            if (list[j] > list[j + 1]) {
                // si es mayor, los intercambiamos y marcamos que hubo un cambio
                change = true;
                swap(list[j], list[j + 1]);
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list) {
    // iteramos toda la lista, de principio a 1 antes del final
    for (int i = 0; i < list.size() - 1; i++) {
        // hacemos el índice de la posicion i como el más chico
            int min = i;

        // iteramos desde el siguiente índice hasta el final
        for (int j = i + 1; j < list.size(); j++) {
            //comparamos el valor de j contra min
            if (list[j] < list[min]) {
                // si es menor, 
                // actualizamos el valor de min
                min = j;
            }
        }

        // intercambiamos el valor de min por el valor de i
        // si min es diferente a i
        if (min != i) {
            swap(list[i], list[min]);
        }
    }
}

template <typename T>
void insertionSort(vector<T> &list) {
    // iteramos la lista desde la segunda posición hasta el final
    for (int i = 1; i < list.size(); i++) {

        // iteramos desde el índice i hasta 1 mayor a 0
        for (int j = i; j > 0; j--) {
           //comparamos el valor de j contra j - 1
            if (list[j] < list[j - 1]) {
                // si es menor, 
                // los intercambiamos
                swap(list[j - 1], list[j]);
            }
        }
    }
}

template <typename T>
int getPivot(vector<T> &sublist, int min, int max) {
    // pivot es el mismo valor que max

    // creamos una variable auxiliar con valor min - 1
    int aux = min - 1;

    // iteramos desde el inicio de la sublista hasta antes del pivot
    for (int index = min; index < max; index++) {
        // comparamos el valor en index con el que esta en el pivot
        if (sublist[index] <= sublist[max]) {
            // aux aumenta
            aux++;
            // se intercambia el valor en aux con el que esta en index
            swap(sublist[aux], sublist[index]);
        }
    }

    // aux incrementa
    aux++;

    // se intercambia el valor en aux con el que esta en el pivot
    swap(sublist[aux], sublist[max]);

    // se regresa aux
    return aux;
}

template <typename T>
void quickSort(vector<T> &list, int min, int max) {
    // la condicion de control es min < max
    if (min < max) {
        // se particiona el vector en sublistas
        int pivot = getPivot(list, min, max);

        // ordenamos la lista antes del pivote
        quickSort(list, min, pivot - 1);

        // ordenamos la lista despues del pivote
        quickSort(list, pivot + 1, max);
    }
}

template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {
    // creamos una lista para los valores del lado izquierdo
    vector<T> leftList;
    // iteramos la lista de left hasta mid
    for (int i = left; i <= mid; i++) {
        leftList.push_back(list[i]);
    }

    // creamos una lista para los valores del lado derecho
    vector<T> rightList;
    // iteramos la lista de mid + 1 hasta right
    for (int j = mid + 1; j <= right; j++) {
        rightList.push_back(list[j]);
    }

    // combinamos las dos listas
    // creamos una variable index que contenga el indice a actualizar
    int index = left;
    // inicializamos el indice del lado izquierdo
    int i = 0;
    // inicializamos el indice del lado derecho
    int j = 0;

    // iteramos mientras no se acaben las listas
    while (i < leftList.size() && j < rightList.size()) {
        // comparamos el valor de i de la lista izquierda con el valor de j de la lista derecha
        if (leftList[i] < rightList[j]) {
            // actualizamos list en index con el valor de leftList en i
            list[index] = leftList[i];
            // incrementamos i
            i++;
        } else {
            // actualizamos list en index con el valor de rightList en j
            list[index] = rightList[j];
            // incrementamos j
            j++;
        }

        // incrementamos index
        index++;
    }

    // vaciamos la lista del lado izquierdo
    while (i < leftList.size()) {
        // actualizamos list en index con el valor de leftList en i
        list[index] = leftList[i];
        // incrementamos i
        i++;
        // incrementamos index
        index++;
    }

    // vaciamos la lista del lado derecho
    while (j < rightList.size()) {
        // actualizamos list en index con el valor de rightList en j
        list[index] = rightList[j];
        // incrementamos j
        j++;
        // incrementamos index
        index++;
    }
}

template <typename T>
void mergeSort(vector<T> &list, int left, int right) {
    // la condicion de control es left < right
    if (left < right) {
        // calculamos mid
        int mid = (left + right) / 2;

        // ordenamos de left a mid
        mergeSort(list, left, mid);

        // ordenamos de mid + 1 a right
        mergeSort(list, mid + 1, right);

        // combinamos las dos partes de la lista
        merge(list, left, mid, right);
    }
}

template <typename T>
void shellSort(vector<T> &list) {
     // obtenemos el tamaño de la lista y la mitad del tamaño
    int size = list.size();
    int half = size / 2;

    // iteramos mientras half sea mayor a 0
    while (half > 0) {
        // iteramos desde half hasta el final de la lista
        for (int i = half; i < size; i++) {
            // creamos una variable temporal con el valor de la posición i
            T temp = list[i];
            // creamos una variable auxiliar con el valor de i
            int aux = i;

            // iteramos mientras aux sea mayor o igual a half y 
            // el valor en la posición aux - half sea mayor que temp
            while (aux >= half && list[aux - half] > temp) {
                // actualizamos el valor en la posición aux con 
                // el valor en la posición aux - half
                list[aux] = list[aux - half];
                // decrementamos aux en half
                aux -= half;
            }

            // actualizamos el valor en la posición aux con temp
            list[aux] = temp;
        }

        // decrementamos half a la mitad
        half /= 2;
    }
}

string monthValues(string month) {
    // creamos un mapa con los valores de los meses y su valor en número
    // para convertir el mes a número
    map<string, string> convert {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    return convert[month];
};

template <typename T>
int binarySearch(vector<T> &list, T aux, bool inicio) {
    // creamos dos variables para el inicio y el final de la lista
    int left = 0;
    int right = list.size() - 1;
    int mid = left + (right - left) / 2;

    string targetKey = aux.key.substr(0, 14);

    // iteramos mientras left sea menor o igual a right
    while (left <= right) {
        // calculamos el mid y obtenemos el valor en la posición mid
        mid = left + (right - left) / 2;
        string currentKey = list[mid].key.substr(0, 14);
        
        // comparamos el valor de currentKey con targetKey
        if (currentKey == targetKey) {
            // si es igual, retornamos mid
            return mid;
        } else if (currentKey < targetKey) {
            // si es menor, actualizamos left a mid + 1
            left = mid + 1;
        } else {
            // si es mayor, actualizamos right a mid - 1
            right = mid - 1;
        }
    }

    // si inicio es true, retornamos max(0, left)
    if (inicio) {
        return max(0, left);
    } else {
        int hold = list.size();
    // si inicio es false, retornamos min(hold-1, right)
        return min(hold-1, right);
    }
}

/*void printLogs(vector<Log> &list, int start, int end) {
    // iteramos desde start hasta end
    for (int i = start; i <= end; i++) {
       // imprimimos el log en la posición i
       cout << list[i].log << endl;
    }

  cout << endl;  
}*/

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
        cout << "1. Usar Swap Sort" << endl;
        cout << "2. Usar Bubble Sort" << endl;
        cout << "3. Usar Selection Sort" << endl;
        cout << "4. Usar Insertion Sort" << endl;
        cout << "5. Usar Quick Sort" << endl;
        cout << "6. Usar Merge Sort" << endl;
        cout << "7. Usar Shell Sort" << endl;
        cout << "8. Busqueda por rango (output608.txt)" << endl;
        cout << "9. Cambiar de Archivo" << endl;
        cin >> option;

        switch (option) {
            case 0:
                // terminamos la ejecución
                cout << "Saliendo del programa..." << endl;
                return 0;
            case 1:
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                swapSort(logs);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Swap Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n^2)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
                
            case 2:
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                bubbleSort(logs);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Bubble Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n^2)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;

            case 3:
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                selectionSort(logs);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Selection Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n^2)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            case 4:
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                insertionSort(logs);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Insertion Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n^2)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            case 5:
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                quickSort(logs, 0, logs.size() - 1);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Quick Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n log n)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            case 6: 
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                mergeSort(logs, 0, logs.size() - 1);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Merge Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n log n)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            case 7: 
                // restauramos el vector a su estado inicial y solicitamos predicciones
                logs = logsUnsorted;

                cout << "\nCual es tu prediccion de rendimiento/tiempo para este algoritmo? (En ms)" << endl;
                cin >> predictionMs;

                cout << "Porque?" << endl;
                cin.ignore(); getline(cin, prediction);

                // tomamos el tiempo antes y despues del método de ordenamiento
                startTime = chrono::high_resolution_clock::now();
                shellSort(logs);
                endTime = chrono::high_resolution_clock::now();

                // calculamos la diferencia y actualizamos la bandera de ordenamiento
                duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
                sorted = true;

                // si la lista quedó vacía detenemos este case
                if(logs.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                /*
                for(auto s : logs){
                    cout << s.log << endl;
                }
                */

                // preparamos e imprimimos la información detallada de la corrida
                predictionDif = abs((int)duration - predictionMs);
                cout << "\n--- RESULTADOS ---" << endl;
                cout << "Algoritmo: Shell Sort" << endl;
                cout << "Archivo usado: " << fileUsed << endl;
                cout << "Tamano del vector: " << logs.size() << " elementos" << endl;
                cout << "Tiempo: " << duration << " milisegundos" << endl;
                cout << "Complejidad teorica: O(n log n) a O(n^1.5)" << endl;
                cout << "Tu prediccion: " << predictionMs << endl;
                cout << "Razon: " << prediction << endl;

                // verificamos si la predicción fue exacta
                if(predictionDif == 0) cout << "Tu prediccion fue correcta." << endl;
                else cout << "Tu prediccion difiere por " << predictionDif << " ms." << endl;
                cout << "------------------\n" << endl;

                // escribimos el resultado y notificamos al usuario
                generateFile(outputFile, logs, 0, logs.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;
            case 8:
                // reiniciamos el control de variables para buscar duplicados
                duplicados.clear();
                repeat = false;

                // la busqueda binaria solo funciona con vectores previamente ordenados
                if (!sorted) {
                    cout << "\nEl vector necesita estar sorteado para implementar busqueda binaria.\n\n";
                    break;
                }

                // vaciamos el vector de rangos en caso de que contenga búsquedas pasadas
                if (!logsRange.empty()) {
                    logsRange.clear();
                }

                // capturamos la fecha de inicio del usuario
                cout << "Inserte la fecha de inicio (DD MM YYYY):" << endl;
                cin >> startLog.day >> startLog.month >> startLog.year;

                // capturamos la hora de inicio del usuario
                cout << "Inserte la hora de inicio (hr:min:sec):" << endl;
                cin >> startLog.time;

                // creamos la clave del objeto de inicio a partir de las entradas
                startLog.key = startLog.createKey(startLog.year, startLog.month, startLog.day, startLog.arrangeTime(startLog.time), "0");

                // capturamos la fecha final del usuario
                cout << "Inserte la fecha final (DD MM YYYY):" << endl;
                cin >> endLog.day >> endLog.month >> endLog.year;

                // capturamos la hora final del usuario
                cout << "Inserte la hora final (hr:min:sec):" << endl;
                cin >> endLog.time;

                // creamos la clave del objeto de cierre a partir de las entradas
                endLog.key = endLog.createKey(endLog.year, endLog.month, endLog.day, endLog.arrangeTime(endLog.time), "0");

                // realizamos búsqueda binaria del index inicial y del index final
                startIndex = binarySearch(logs, startLog, true);
                endIndex = binarySearch(logs, endLog, false);

                // imprimimos datos para validación de la búsqueda
                /*cout << "StartKey: " << startLog.key << " EndKey: " << endLog.key << endl;
                cout << "Start: " << startIndex << " End: " << endIndex << endl;
                cout << "StartTime: " << startLog.time << "EndTime: " << endLog.time << endl;*/

                // ajustamos startIndex retrocediendo en caso de encontrar timestamps idénticos colindantes
                if(startIndex > 0){
                    while (startIndex > 0 && logs[startIndex].key.substr(0, 14) == logs[startIndex - 1].key.substr(0, 14)) {
                        repeat = true;
                        startIndex -= 1;
                        duplicados.push_back(logs[startIndex]);
                    }
                }
                
                // ajustamos endIndex avanzando en caso de encontrar timestamps idénticos colindantes
                if(endIndex < logs.size() - 1){
                    while (endIndex < logs.size() - 1 && logs[endIndex].key.substr(0, 14) == logs[endIndex + 1].key.substr(0, 14)) {
                        repeat = true;
                        endIndex += 1;
                        duplicados.push_back(logs[endIndex]);
                    }
                }

                // ingresamos el valor inicial y el resto del rango al nuevo vector
                logsRange.push_back(logs[startIndex]);
                for (int i = startIndex + 1; i <= endIndex && i < logs.size(); i++) {
                    logsRange.push_back(logs[i]);

                    // detectamos si hay elementos idénticos en el resto de los elementos para guardarlos
                    if (logsRange[i - startIndex].key.substr(0, 14) == logsRange[i - startIndex - 1].key.substr(0, 14)) {
                        repeat = true;
                        duplicados.push_back(logsRange[i - startIndex]);
                    }
                }

                // notificamos al usuario la existencia de elementos idénticos si se encontraron
                if (repeat) {
                    cout << "Alerta de timestamp(s) duplicado(s). Se incluyen en el output todos los siguientes timestamps duplicados dentro del rango establecido en orden:\n\n";
                    
                    for(auto k : duplicados){
                        cout << k.log << endl;
                    }
                }

                // verificamos si la búsqueda entregó algún resultado
                if(logsRange.empty()){
                    cout << "\nNo fue posible guardar el vector.\nEl vector esta vacio.\n\n";
                    continue;
                }

                // imprimimos el resultado de los logs obtenidos
                for(auto s : logsRange){
                    cout << s.log << endl;
                }

                // generamos el documento range607.txt
                generateFile(rangeFile, logsRange, 0, logsRange.size()-1);
                cout << "\nSe ha guardado la informacion\n\n";
                break;

            case 9:
                // regresamos los parámetros al estado por default y desordenado
                logs = logsUnsorted;
                sorted = false;

                // cerramos y limpiamos el flujo de lectura previo
                inputFile.close();
                inputFile.clear();

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

                // limpiamos los vectores antes de rellenar con datos nuevos
                logs.clear();

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

                // guardamos la nueva configuración desordenada por default
                logsUnsorted = logs;
                break;

            default:
                cout << "\nElige una opcion valida\n\n";
                option = -1;
                break;
        }
    }
}
