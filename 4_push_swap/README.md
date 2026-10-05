# push_swap

Programa que ordena una pila de enteros usando una segunda pila y un conjunto limitado de operaciones, buscando el menor número de movimientos posible. *(Calificación: 100%)*

## 🚀 Demo / Screenshot
> _Añade aquí una captura de pantalla o GIF del proyecto en ejecución._

## 📋 Tabla de contenidos
- [Características](#-características)
- [Tecnologías](#️-tecnologías)
- [Instalación](#-instalación)
- [Uso](#-uso)
- [Estructura del proyecto](#-estructura-del-proyecto)
- [Tests](#-tests)
- [Contribuir](#-contribuir)
- [Licencia](#-licencia)

## ✨ Características
- Ordena pilas con las operaciones `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Algoritmos distintos según el tamaño de la entrada (casos pequeños y pilas grandes)
- Validación de argumentos: duplicados, no numéricos y desbordamiento de `int`
- Optimización del número de movimientos

## 🛠️ Tecnologías
- C
- Estructuras de datos (listas enlazadas / pilas)
- Complejidad algorítmica
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/4_push_swap
make        # genera el ejecutable push_swap
```

## 💻 Uso

```bash
./push_swap 2 1 3 6 5 8
```

Imprime en `stdout` la lista de operaciones. Para contarlas:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Si hay error (duplicados, valores no válidos) escribe `Error` en `stderr`.

## 📁 Estructura del proyecto

```
4_push_swap/
├── Makefile
├── push_swap.h
├── main.c
├── operations/     # sa, pb, ra, rra...
├── algorithms/     # ordenación por tamaño
├── utils/          # parseo y validación
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Prueba con 3, 5, 100 y 500 números aleatorios y verifica el número de movimientos con la escala de evaluación (por ejemplo, 100 números en menos de ~700 movimientos).

## 🤝 Contribuir
Este es un proyecto académico del Common Core de 42, por lo que no se esperan contribuciones directas, pero las sugerencias y revisiones son bienvenidas. Si quieres proponer algo:
1. Haz fork del repositorio
2. Crea tu rama (`git checkout -b feature/nueva-funcionalidad`)
3. Commit tus cambios
4. Push a la rama
5. Abre un Pull Request

> ⚠️ Si eres estudiante de 42, úsalo solo como referencia: copiar código va contra las normas de la escuela.

## 📄 Licencia
Proyecto académico realizado en 42 Málaga con fines educativos.

## 👤 Autor
Alejandro Maldonado Robles - [@alexmaro10](https://github.com/alexmaro10)
