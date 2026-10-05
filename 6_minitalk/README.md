# minitalk

Pequeño programa de comunicación cliente-servidor en el que los procesos intercambian texto utilizando únicamente las señales UNIX `SIGUSR1` y `SIGUSR2`. *(Calificación: 100%)*

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
- El servidor muestra su PID al arrancar y puede recibir mensajes de varios clientes de forma consecutiva
- El cliente envía una cadena bit a bit usando solo `SIGUSR1` y `SIGUSR2`
- Reconstrucción de caracteres en el servidor a partir de los bits recibidos
- Manejo de señales con `sigaction`

## 🛠️ Tecnologías
- C
- Señales UNIX (`signal`, `sigaction`, `kill`)
- Operaciones a nivel de bits
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/6_minitalk
make        # genera server y client
```

## 💻 Uso

En una terminal, lanza el servidor:

```bash
./server
# PID: 12345
```

En otra terminal, envía un mensaje:

```bash
./client 12345 "Hola desde minitalk"
```

## 📁 Estructura del proyecto

```
6_minitalk/
├── Makefile
├── minitalk.h
├── server.c
├── client.c
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Prueba con mensajes largos, caracteres Unicode y varios clientes enviando mensajes seguidos.

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
