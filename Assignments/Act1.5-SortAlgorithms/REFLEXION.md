# Reflexión sobre el uso de Copilot

## ¿Qué algoritmos lograste implementar con mayor facilidad gracias al apoyo de Copilot?

### En verdad, no utilicé realmente Copilot a la hora de construir los algoritmos de ordenamiento, ya que preferí investigar y consultar páginas web para entender su funcionamiento (especialmente GeeksforGeeks). Admitiré, sin embargo, que Copilot me ayudó bastante a la hora de encontrar errores o soluciones cuando no sabía cómo escribir algo o tenía algún error en mi código de los algoritmos.

## ¿En qué casos Copilot te dio soluciones correctas de inmediato y en cuáles tuviste que corregir o ajustar la propuesta?

### Aunque no haya utilizado Copilot tanto en la construcción de los algoritmos en sí, este sí me ayudó al crear algunas funciones que utilicé en mi código, como las que me permitían imprimir los vectores o las que creaban vectores random de un tipo de dato específico. Sin embargo, me aseguré de probar lo dado por Copilot para ver si lo proporcionado estaba correcto o si se necesitaban ajustes.

## ¿Consideras que Copilot te ayudó a ahorrar tiempo o más bien te obligó a pensar más sobre cómo funciona el algoritmo?

### Considero que Copilot sí me ayudó a ahorrar una cantidad de tiempo considerable, ya que, cuando encontraba un error en mi código, casi de inmediato me sugería una posible solución al error en cuestión. Eso no quiere decir que simplemente aceptara todas sus sugerencias, ya que prefería ver exactamente qué efecto tenía su sugerencia en el código y qué estaba cambiando de este antes de implementarlo, ya que podría estar cambiando algo que no quería.

## Escribe un ejemplo concreto donde Copilot no resolvió el problema directamente y tuviste que razonar la solución.

### Un ejemplo es la necesidad de medir el tiempo de los algoritmos de ordenamiento en nanosegundos. Ya había utilizado anteriormente una forma de medir el tiempo en la actividad 1.4 utilizando clock_t *x* = clock(); sin embargo, esto lo utilicé para medir el tiempo en segundos. Aunque Copilot me sugirió una manera de transformar el valor dado por clock a nanosegundos, decidí indagar si clock daba el valor exacto en nanosegundos o si simplemente me estaba transformando segundos a nanosegundos. Cuando me di cuenta de que estaba haciendo lo segundo, decidí buscar otra forma de medir el tiempo en nanosegundos, encontrándome con chrono. Una vez que encontré chrono, lo implementé; aunque admitiré que Copilot me ayudó a asegurarme de que estuviera bien implementado.

## ¿Qué hubieras hecho diferente si no hubieras tenido acceso a Copilot para esta actividad?

### Creo que la mayor diferencia sería el tiempo, pues los algoritmos de ordenamiento fueron casi en su totalidad hechos en clase o buscando información sobre su funcionamiento en línea. Sin embargo, habría tomado más tiempo encontrar y arreglar cualquier error que hubiera aparecido. Ahora, lo que sí habría tomado mucho más tiempo es lo demás del código, aunque dudo que el main y las funciones de imprimir o crear vectores hubieran tardado mucho más tiempo; la función sortMenu habría tomado más tiempo para asegurarme de que estaba implementando chrono correctamente y de que todo se estaba llevando a cabo de forma correcta.