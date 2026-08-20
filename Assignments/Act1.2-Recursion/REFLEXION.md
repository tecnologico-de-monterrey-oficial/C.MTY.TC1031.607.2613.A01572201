# Reflexión Personal

## ¿En qué casos notaste que la versión recursiva fue más lenta o usó más memoria que la iterativa? ¿A qué se debió?

### Durante las pruebas que hice entre las versiones recursivas e iterativas, me pude dar cuenta de que la versión recursiva iba significativamente más lenta en los casos en los que la cantidad de recursiones era muy grande. Por ejemplo, intenté hacer que fibonacciRecursive llegara al 100; sin embargo, se tardó tanto que preferí simplemente detener el código. La razón por la que esto pasa se debe principalmente a la gran cantidad de llamadas que realiza el método recursivo antes de terminar, ya que cada llamada recursiva utiliza memoria para almacenarse.

## Para la suma 1..n, sumFormula resuelve en un solo paso lo que a sumIterative y sumRecursive les toma n pasos. ¿Qué te dice esto sobre buscar una fórmula antes de escribir código?

### El que sumFormula resuelva en una sola instancia lo que sumIterative y sumRecursive hacen en una multitud de pasos me dice que buscar fórmulas e implementarlas en el código puede hacer que este mismo sea mucho más eficiente y optimizado, lo cual es vital para ejecutar programas más complicados y evitar la utilización excesiva de recursos.

## Si bacteriasRecursive tuviera que calcular n = 100,000 días, ¿qué problema esperarías encontrar y cómo lo resolverías?

### Si bacteriasRecursive tuviera que calcular hasta los 100,000 días, esperaría que el código tomara un tiempo gigantesco para terminar y dar el resultado esperado. Por tanto, yo resolvería este problema intentando buscar alguna fórmula que agilice el proceso. En caso de que no haya ninguna fórmula que pueda optimizar más a bacteriasRecursive, entonces mejor cambiaría a bacteriasIterative, la cual no debería sufrir el problema del tiempo de manera tan grave al ser iterativa en lugar de recursiva.