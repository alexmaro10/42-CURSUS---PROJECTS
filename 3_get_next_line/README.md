# get_next_line

Función que lee un file descriptor y devuelve una línea cada vez que se llama, gestionando buffers y memoria de forma eficiente. *(Calificación: 103%)*

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
- Lectura línea a línea desde cualquier file descriptor (archivos, `stdin`...)
- Tamaño de buffer configurable en compilación con `BUFFER_SIZE`
- **Bonus:** gestión de varios file descriptors a la vez con una sola variable estática
- Gestión correcta de memoria: sin fugas y con liberación de restos

## 🛠️ Tecnologías
- C
- `read`, `malloc`, `free`
- Variables estáticas

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/3_get_next_line
# No requiere instalación; se compila junto a tu programa
```

## ⚙️ Configuración
El tamaño de lectura se define al compilar:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ...
```

## 💻 Uso

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int   fd = open("archivo.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl && ./gnl
```

## 📁 Estructura del proyecto

```
3_get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Prueba con distintos `BUFFER_SIZE` (1, 42, 9999, 10000000), archivos vacíos, sin salto de línea final y lectura desde `stdin`.

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
