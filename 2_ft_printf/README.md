# ft_printf

Implementación propia de la función `printf` de la libc usando funciones variádicas, empaquetada en `libftprintf.a`. Útil para entender el formateo de salida y el manejo de `va_list`. *(Calificación: 100%)*

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
- Soporta las conversiones `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` y `%%`
- Devuelve el número de caracteres impresos, igual que el `printf` original
- Uso de `<stdarg.h>` (`va_start`, `va_arg`, `va_end`)
- Sin fugas de memoria y sin usar buffers globales

## 🛠️ Tecnologías
- C
- Funciones variádicas (`stdarg.h`)
- Make / `ar`
- Libft (si se enlaza en el proyecto)

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/2_ft_printf
make        # genera libftprintf.a
```

## 💻 Uso

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hola %s, tienes %d años y hex %#x\n", "42", 20, 255);
    ft_printf("Caracteres impresos: %d\n", n);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo && ./demo
```

## 📁 Estructura del proyecto

```
2_ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c     # parser del formato y bucle principal
├── ft_print_*.c    # funciones auxiliares por conversión
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Puedes comparar la salida con la de `printf` real para cada conversión.

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
