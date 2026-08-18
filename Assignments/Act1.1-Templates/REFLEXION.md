# Reflexión Personal

## ¿Qué ventaja concreta notaste al usar templates en tu clase List, comparado con haberla hecho solo para un tipo de dato (por ejemplo, solo enteros)? Da un ejemplo de tu propio código.

### El haber hecho la clase List con templates en lugar de con un tipo de dato específico trajo como ventaja el hecho de que la clase se pueda usar para que las operaciones de esta misma puedan trabajar con distintos tipos de datos sin tener que crear una clase individual para cada tipo específico. Por ejemplo, en mi código (el archivo .cpp) se puede observar esto al crear el objeto things para la clase List, que trabaja con strings, y el objeto list, que trabaja con int; ambos usan la clase List y tienen acceso a sus operaciones, pero things trabaja con strings y list con int. Usando la operación insert de la clase List, pude crear una lista de strings con things y una lista de int con list.

## ¿Qué parte de la actividad —ya sea el uso de templates o el reto de insertAt/removeAt— te costó más trabajo entender o depurar? ¿Qué hiciste para resolverlo?

### El uso de templates en sí no fue demasiado complicado; lo que fue más complicado definitivamente fue crear las operaciones insertAt y removeAt. Para llegar a crear estas operaciones, consideré que estaba usando un vector y, recordando lo que hicimos en clase, sabía que la librería <vector> tenía funciones como push_back y pop_back. Así que investigué qué otras funciones tenía <vector> y, con ello, logré hacer esas operaciones.

## Si tuvieras que explicarle a un compañero qué es un template en C++ usando tus propias palabras, sin tecnicismos, ¿qué le dirías?

### Si tuviera que explicarle a alguien qué es un template en C++, yo le diría que es una herramienta que permite que una operación o clase pueda ser utilizada para procesar diferentes tipos de datos sin la necesidad de tener que escribir nuevamente toda la operación o clase con otro tipo de dato en mente; en otras palabras, creando una versión generalizada de una clase u operación que puede adaptarse a distintos tipos de datos.

## Referencias

### Microsoft. (2025, July 11). Clase vector. Microsoft Learn. https://learn.microsoft.com/es-es/cpp/standard-library/vector-class?view=msvc-170#erase 