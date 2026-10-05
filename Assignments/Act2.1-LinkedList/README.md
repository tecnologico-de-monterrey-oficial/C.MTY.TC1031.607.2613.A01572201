# Actividad 2.1 - Listas encadenadas
Este código es un programa que implementa la funcionalidad de las listas encadenadas al permitir al usuario agregar, quitar o inclusive actualizar los elementos de una lista utilizando funciones que emplean los conceptos de listas encadenadas. También es posible para los usuarios duplicar listas mediante el uso de sobrecarga.

## Requisitos Previos
Se requiere un compilador de C++ compatible con las librerías utilizadas y que los archivos tengan nombres compatibles con el código.

## Instalación y Ejecución
1. Clona o descarga los archivos sin cambiar sus nombres o su estructura.
2. Abre tu terminal en el directorio del código fuente.
3. Compila el archivo.
4. Ejecuta el programa generado:

   ./ActivityRunner

## Acciones Disponibles
Después de que el usuario decida trabajar con elementos de tipo int o float y cree una lista de elementos aleatorios o capturados, se le presentarán las siguientes opciones en el código:

1. Agregar un elemento al principio de la lista.
2. Agregar un elemento al final de la lista.
3. Insertar un elemento después de un índice dado.
4. Borrar un elemento dado de la lista.
5. Borrar un elemento en una posición de la lista.
6. Obtener el elemento de una posición dada de la lista.
7. Actualizar un elemento dado de la lista.
8. Actualizar un elemento en una posición dada de la lista.
9. Encontrar un elemento dado en la lista.
10. Obtener el elemento de una posición de la lista (sobrecarga del operador [ ]).
11. Actualizar el elemento de una posición de la lista (sobrecarga del operador [ ]).
12. Igualar una lista con los datos de otra lista (sobrecarga del operador =).
13. Crear o rehacer una lista auxiliar.

Es importante mencionar que, para el buen funcionamiento del código, es necesario trabajar exclusivamente con elementos del tipo elegido; de otra manera, pueden surgir errores o acciones inesperadas. Por ejemplo, al intentar realizar la primera acción agregando un número float mientras se trabaja con elementos int, el código termina después de agregar el elemento, redondeado a int, a la lista.

También es importante mencionar que se debe elegir correctamente con qué tipo de elementos trabajar, ya que no se puede cambiar a menos que se vuelva a iniciar el código.

## Prompts Utilizados Durante la Elaboración
Para la elaboración de este código, se utilizaron una variedad de prompts para Gemini y ChatGPT. A Gemini le pregunté lo siguiente: "¿Podrías decirme por qué esta sección del código me está dando un error?". Utilicé este prompt para solucionar algunos errores de los que no estaba seguro por qué estaban ocurriendo, como que C++ no acepta un main con template; aunque mi hermano también me aclaró algunas dudas.

En cuanto a ChatGPT, le pedí lo siguiente: "¿Podrías arreglar los errores ortográficos de lo siguiente? No cambies nada del texto en sí". Esto lo utilicé principalmente para evitar algunos errores ortográficos en mis comentarios y en el mismo README, no realmente para el código.

No le pedí ningún prompt exacto a Copilot; simplemente me ayudaba automáticamente cuando lo tenía activo.

## Reflexión de Uso de IA
### ¿Qué parte del código te propuso la IA que aceptaste tal cual y por qué era correcta?
Gemini me ayudó a darme cuenta de que había un error en la parte de generar listas de mi código, específicamente por cómo lo tenía estructurado dentro de la función createList. Debido a que realmente lo único que cambiaba era mover partes del código que ya tenía hacia el main (específicamente, la parte de seleccionar qué tipo de elemento usar) o para formar las funciones de genRandom (es decir, la generación de mis listas aleatorias), no le vi ninguna razón para no aceptar la respuesta que me dio. Después de probar que el código funcionaba de la manera que Gemini me recomendó, no vi razón para pensar que estaba incorrecto.

### ¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?
De las partes relacionadas con la IA, realmente simplemente verifiqué que lo que me diera fuera funcional y que no hubiera cosas que me causaran fallos en el código; pero sí llegué a modificar secciones que creí incompletas, como agregar el uso de default a los switch después de que me ayudara a solucionar un error en su estructura. La mayor parte de lo que modifiqué de la IA fueron comentarios que simplemente no pensé que explicaran las cosas de la manera en que yo creía que debían ser explicadas.

En cuanto a cómo verifiqué que mis cambios eran mejores, simplemente le pedí a mi hermano que probara mi código para ver si era capaz de encontrar algún error que yo no hubiera notado una vez que lo terminé. Aunque sí modifiqué algunas partes del código visto en clase para que siguiera de forma más cercana las instrucciones de la tarea, pues en algunas de las funciones no se pedía el uso de out_of_range, por ejemplo.

### ¿Dónde se equivocó la IA (si ocurrió) y cómo lo detectaste?
Realmente, mi uso de IA en esta actividad fue relativamente poco. Aunque sí la utilicé para solucionar errores, la mayoría del código se realizó basándome en códigos que ya tenía previamente (como el de generar listas aleatorias en vectores, que saqué de la actividad 1.5) o en lo que hicimos en clase. La mayor parte del tiempo que usé Copilot, este solo lo utilicé para poner algunos comentarios de forma más rápida dentro del texto; pero, aun así, lo utilicé de forma mínima, por lo que solo se equivocó algunas veces en comentarios que no estaban completamente correctos, los cuales rectifiqué rápidamente.

No noté que Gemini me diera alguna pieza de código fallida las veces que le pregunté por las razones de los errores, inclusive después de probarlas. Sin embargo, debido a que le daba secciones pequeñas del código para solucionar errores específicos, tenía que comprobar que las respuestas dadas fueran aplicables al código completo.

En cuanto a ChatGPT, prácticamente no lo utilicé para el código, sino solo para textos.

### ¿Qué harías diferente si no tuvieras Copilot/ChatGPT?
Realmente, no utilicé tanto Copilot o ChatGPT; en todo caso, lo que realmente me afectaría sería el uso de Gemini para el código. Y, aun si no tuviera acceso a Gemini, lo único que habría cambiado es que tendría que buscar en Internet las posibles razones de varios errores de mi código. También es posible que solucionara cualquier error que surgiera en mi código a través de debugging constante, pidiendo más ayuda a mi hermano o mediante asesorías. No creo que me hubiera afectado demasiado el no tener acceso a la IA, simplemente me habría retrasado.



