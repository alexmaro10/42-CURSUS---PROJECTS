# push_swap

## Overview

Push_swap es un ejercicio enfocado en el aprendizaje de algoritmos y optimización.

Consiste ordenar una lista de números enteros utilizando dos pilas (stack A y stack B) y un conjunto muy limitado de operaciones predefinidas (como sa, pb, ra, etc.). El objetivo no es solo ordenar, sino hacerlo con el menor número de movimientos posible.

## Conceptos clave

se utilizan estructuras de datos tipo pila (stack), que siguen el principio LIFO (Last In, First Out). El programa trabaja con dos pilas, A y B, y todas las operaciones permitidas consisten en manipular estos elementos: intercambiar los dos primeros, mover elementos de una pila a otra o rotar la pila hacia arriba o hacia abajo. Implementar correctamente estas estructuras, ya sea mediante arrays o listas enlazadas, es fundamental para asegurar eficiencia y buen manejo de memoria.

Por otro lado, la algoritmia es el núcleo del proyecto. No basta con aplicar un algoritmo de ordenación tradicional, sino que hay que adaptarlo a las limitaciones impuestas por las operaciones disponibles. Por ejemplo, muchos estudiantes utilizan variantes de Radix Sort para listas grandes, mientras que para conjuntos pequeños se diseñan soluciones específicas más directas. La clave está en encontrar una estrategia que no solo funcione, sino que minimice el número de pasos necesarios.

Ligado a esto aparece la optimización, que es probablemente el aspecto más importante. Push_swap no evalúa únicamente si el resultado está ordenado, sino cuántas operaciones se han utilizado para conseguirlo. Esto obliga a pensar de forma estratégica, evitando movimientos innecesarios y combinando operaciones cuando es posible, con el objetivo de reducir al máximo la cantidad total de instrucciones.

Finalmente, el parsing o validación de entrada juega un papel esencial. Antes de comenzar cualquier proceso de ordenación, el programa debe verificar que los datos recibidos son correctos: comprobar que todos los valores son enteros válidos, que no hay duplicados y que no se producen errores de rango. Una gestión rigurosa de estos casos garantiza la robustez del programa y evita comportamientos inesperados.

En conjunto, Push_swap es un proyecto que combina estructuras de datos, diseño de algoritmos, optimización y validación, convirtiéndose en un excelente ejercicio para desarrollar pensamiento lógico y habilidades avanzadas en programación en C.

## Algoritmo Seleccionado

El algoritmo de chunks funciona de la siguiente manera:

En una primera fase, los elementos de la pila A se recorren y se envían progresivamente a la pila B. Para ello, se selecciona un bloque concreto y se comprueba si cada número pertenece a ese rango. Si es así, se empuja a la pila B mediante la operación correspondiente; si no, se rota la pila A para seguir buscando. Durante este proceso, es común aplicar pequeñas optimizaciones, como rotar la pila B después de insertar ciertos elementos, con el objetivo de mantener una organización parcial que facilite los pasos posteriores.

Una vez que todos los elementos han sido trasladados a la pila B, comienza la segunda fase del algoritmo. En este punto, se reconstruye la pila A en orden, devolviendo los elementos desde B. Para ello, se busca repetidamente el número más grande en la pila B, se realizan las rotaciones necesarias para colocarlo en la parte superior y se vuelve a insertar en la pila A. Al repetir este proceso, los elementos se van colocando en su posición correcta hasta que la pila queda completamente ordenada.

Este enfoque resulta eficaz porque reduce la complejidad del problema al dividirlo en subconjuntos manejables y permite un mayor control sobre los movimientos realizados. Además, al organizar parcialmente los elementos en la pila B, se disminuye el número de operaciones necesarias en la fase final.

## Resultados

Como se ve en las imagenes este algoritmo nos permite ordenar listas muy grandes de numero en pocos movimientos:

10 numeros: 24 - 36 movimientos.
100 numeros: 644 movimientos.
500 numeros: < 5900 movimientos