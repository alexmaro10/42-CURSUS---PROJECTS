# ft_irc

Servidor IRC escrito en C++98 que permite a varios clientes IRC reales conectarse, unirse a canales y chatear con autenticación por contraseña. *(Calificación: 125%)*

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
- Servidor TCP no bloqueante que gestiona múltiples clientes con un único `poll()` (o equivalente)
- Autenticación con contraseña y registro de usuarios (`PASS`, `NICK`, `USER`)
- Canales y mensajes privados (`JOIN`, `PART`, `PRIVMSG`, `QUIT`)
- Comandos de operador: `KICK`, `INVITE`, `TOPIC` y `MODE` (`i`, `t`, `k`, `o`, `l`)
- Compatible con clientes IRC de referencia
- **Bonus:** funcionalidades extra (por ejemplo, un bot y/o transferencia de archivos)

## 🛠️ Tecnologías
- C++98
- Sockets POSIX (`socket`, `bind`, `listen`, `accept`, `recv`, `send`)
- `poll()` / I/O no bloqueante
- Make

## 📦 Instalación

```bash
git clone https://github.com/alexmaro10/42-CURSUS---PROJECTS.git
cd 42-CURSUS---PROJECTS/10_ft_irc
make        # genera ircserv
make bonus  # si aplica
```

## 💻 Uso

Arranca el servidor indicando puerto y contraseña:

```bash
./ircserv <puerto> <contraseña>
./ircserv 6667 mipass
```

Conéctate con un cliente IRC (por ejemplo, HexChat/irssi) o con `nc`:

```bash
nc -C 127.0.0.1 6667
PASS mipass
NICK alex
USER alex 0 * :Alejandro
JOIN #42
PRIVMSG #42 :Hola a todos
```

## 📁 Estructura del proyecto

```
10_ft_irc/
├── Makefile
├── includes/
├── src/
│   ├── Server.cpp
│   ├── Client.cpp
│   ├── Channel.cpp
│   └── commands/   # un archivo por comando
├── bonus/
└── README.md
```

## 🧪 Tests

```bash
make && ./ircserv 6667 mipass
```

Pruebas recomendadas: conexión de varios clientes, mensajes fragmentados con `nc` (`Ctrl+D` para enviar en partes), desconexiones abruptas y comandos de operador con distintos modos de canal.

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
