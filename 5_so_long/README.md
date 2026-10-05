# so_long

Pequeño juego 2D en vista cenital hecho con la MiniLibX: el jugador recoge todos los coleccionables del mapa y llega a la salida. *(Calificación: 125%)*

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
- Carga de mapas desde archivos `.ber` con validación (rectangular, rodeado de muros, camino válido)
- Elementos del mapa: `0` suelo, `1` muro, `C` coleccionable, `E` salida, `P` jugador
- Movimiento con `W`/`A`/`S`/`D` (o flechas) y cierre con `ESC` o la cruz de la ventana
- Contador de movimientos
- **Bonus:** elementos extra como enemigos y animaciones de sprites

## 🛠️ Tecnologías
- C
- MiniLibX (X11 / XQuartz)
- Flood fill para comprobar que el mapa es resoluble
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/5_so_long
make        # genera so_long
make bonus  # versión con los extras
```

## ⚙️ Configuración
Formato de mapa (`.ber`):

```
1111111111
1P0C0000C1
1000011001
1C00000E01
1111111111
```

## 💻 Uso

```bash
./so_long maps/mapa.ber
```

## 📁 Estructura del proyecto

```
5_so_long/
├── Makefile
├── includes/
├── src/
├── maps/           # mapas .ber de ejemplo
├── textures/       # sprites
├── minilibx-linux/
└── README.md
```

## 🧪 Tests

```bash
norminette -R CheckForbiddenSourceHeader
```

Además de la norma, el proyecto se ha probado manualmente y con testers de la comunidad (por ejemplo, Francinette).

Prueba con mapas inválidos (sin salida, sin camino, no rectangular, extensión incorrecta) para comprobar que el programa muestra `Error` y sale limpiamente.

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
