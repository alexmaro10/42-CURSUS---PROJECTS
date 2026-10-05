# minishell

Intérprete de comandos propio inspirado en `bash`, con parseo, ejecución de procesos, redirecciones, pipes y built-ins. *(Calificación: 100%)*

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
- Prompt interactivo con historial (`readline`)
- Ejecución de comandos mediante la variable `PATH` o ruta absoluta/relativa
- Redirecciones `<`, `>`, `>>` y heredoc `<<`
- Pipes `|` entre comandos
- Expansión de variables de entorno y `$?`, y comillas simples y dobles
- Built-ins: `echo -n`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Gestión de señales `Ctrl-C`, `Ctrl-D` y `Ctrl-\`

## 🛠️ Tecnologías
- C
- GNU Readline
- Llamadas al sistema: `fork`, `execve`, `pipe`, `dup2`, `waitpid`, `signal`
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/7_minishell
# Requiere la librería readline (Debian/Ubuntu)
sudo apt install libreadline-dev
make        # genera minishell
```

## 💻 Uso

```bash
./minishell
minishell$ echo "Hola 42" | tr a-z A-Z > salida.txt
minishell$ cat < salida.txt
HOLA 42
minishell$ export NOMBRE=Alex && echo $NOMBRE
Alex
minishell$ exit
```

## 📁 Estructura del proyecto

```
7_minishell/
├── Makefile
├── includes/
├── src/
│   ├── lexer/      # tokenización
│   ├── parser/     # construcción de comandos
│   ├── executor/   # procesos, pipes, redirecciones
│   ├── builtins/
│   └── signals/
├── libft/
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Compara el comportamiento con `bash` en casos límite: comillas anidadas, redirecciones múltiples, pipes largos, variables inexistentes y comandos no encontrados. Comprueba fugas de memoria con `valgrind` (ignorando las propias de `readline`).

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
