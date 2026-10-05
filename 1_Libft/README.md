# Libft

Recreación de las funciones estándar de C (`libc`) más utilidades adicionales y listas enlazadas, empaquetadas en la librería estática `libft.a`. Es la base que reutilizan el resto de proyectos del Common Core. *(Calificación: 125%)*

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
- Reimplementación de funciones de `<ctype.h>`, `<string.h>`, `<stdlib.h>` (`ft_isalpha`, `ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_calloc`, `ft_strdup`...)
- Funciones adicionales: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` y `ft_putchar_fd`/`ft_putstr_fd`/`ft_putendl_fd`/`ft_putnbr_fd`
- **Bonus:** manejo de listas enlazadas (`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`)
- Gestión de memoria sin fugas y compilación con `-Wall -Wextra -Werror`

## 🛠️ Tecnologías
- C (estándar C99, norma de 42)
- Make / `ar` para generar la librería estática
- Norminette

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/1_Libft
make        # genera libft.a
make bonus  # incluye las funciones de listas
```

## 💻 Uso

Incluye el header y enlaza la librería en tu proyecto:

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strjoin("Hola, ", "42!");
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o demo && ./demo
```

Otras reglas del `Makefile`: `make clean`, `make fclean`, `make re`.

## 📁 Estructura del proyecto

```
1_Libft/
├── Makefile
├── libft.h
├── ft_*.c          # funciones de la parte 1 y 2
├── ft_lst*_bonus.c # funciones de listas (bonus)
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

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
