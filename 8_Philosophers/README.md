# Philosophers

Resolución del clásico problema de los filósofos comensales con hilos y mutexes, evitando deadlocks y condiciones de carrera. *(Calificación: 100%)*

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
- Un hilo por filósofo; cada tenedor protegido por un mutex
- Parámetros configurables: número de filósofos, tiempos de muerte, comer y dormir, y número opcional de comidas
- Detección de muerte de un filósofo con precisión de milisegundos
- Salida del log sin mezclarse entre hilos
- Sin data races (verificable con `helgrind`/`ThreadSanitizer`)

## 🛠️ Tecnologías
- C
- POSIX threads (`pthread_create`, `pthread_mutex_*`)
- `gettimeofday` / `usleep`
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/8_Philosophers
make        # genera philo
```

## 💻 Uso

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Ejemplos:

```bash
./philo 5 800 200 200       # nadie debería morir
./philo 4 310 200 100       # un filósofo muere
./philo 5 800 200 200 7     # termina al comer 7 veces cada uno
```

Formato de salida: `timestamp_ms id acción`.

## 📁 Estructura del proyecto

```
8_Philosophers/
├── Makefile
├── philo.h
├── main.c
├── init.c          # inicialización de hilos y mutexes
├── routine.c       # ciclo comer / dormir / pensar
├── monitor.c       # control de muerte
├── utils.c
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

```bash
valgrind --tool=helgrind ./philo 5 800 200 200
```

Prueba con 1 filósofo, con 200 filósofos y con tiempos justos de supervivencia.

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
