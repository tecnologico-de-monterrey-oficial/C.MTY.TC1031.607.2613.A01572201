# Evidencia 1 - Visualizador y Ordenador de Logs en C++
El programa está diseñado para leer archivos de texto con grandes cantidades de logs (registros), analizarlos y permitir al usuario utilizar múltiples algoritmos de ordenamiento para observar y comparar sus tiempos de ejecución y complejidad (Big O). También tiene la habilidad de permitir al usuario realizar búsquedas más específicas mediante la utilización de un rango de fechas, que funciona utilizando búsqueda binaria.

## Estructura de Archivos
El programa está organizado de tal manera que depende de una estructura de carpetas específica para funcionar, específicamente de una carpeta data (donde se almacenan los archivos de prueba), una carpeta include (donde se almacenan los archivos .h) y una carpeta src (donde se almacena el main). Se puede representar la estructura de la siguiente forma:

/proyecto
 ├── /data
 │    ├── log607-1.txt
 │    └── log607-2.txt
 ├── /include
 │    └── Log.h
 └── /src
      └── Evidence1_3.cpp

## Requisitos Previos
Se requiere un compilador de C++ compatible con las librerías utilizadas (como chrono) y que los archivos tengan nombres compatibles con el código.

## Instalación y Ejecución
1. Clona o descarga los archivos sin cambiar sus nombres o su estructura
2. Abre tu terminal en el directorio del código fuente (/src).
3. Compila el archivo:

   g++ -o EvidenceRunner Evidence1.cpp

4. Ejecuta el programa generado:

   ./EvidenceRunner

## Algoritmos Usados
El código permite utilizar 7 diferentes tipos de algoritmos de ordenamiento:
1. Swap Sort
2. Bubble Sort
3. Selection Sort
4. Insertion Sort
5. Quick Sort
6. Merge Sort
7. Shell Sort
Se le pedirá al usuario que realice una predicción del rendimiento en tiempo del algoritmo que utilice, para que pueda comparar los resultados reales de los algoritmos con sus predicciones después de su ejecución.

## Uso de Búsqueda Binaria
Una vez que uno de los archivos de prueba haya sido ordenado por algún algoritmo de ordenamiento, se puede utilizar la opción de Búsqueda por Rango en el menú presentado al usuario. Para utilizar la búsqueda binaria, se pedirá una fecha/hora de inicio y una fecha/hora de fin, con lo cual la búsqueda binaria localizará rápidamente los índices correspondientes y se creará un documento ordenado con los logs dentro del rango solicitado. También, se le informará y presentará al usuario si en el documento hay timestamps idénticos dentro del rango solicitado.

## Video explicativo breve 

