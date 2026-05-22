*This project has been created as part of the 42 curriculum by almaldon, bvarea-k, ancanale.*

# ft_irc

## Description

**ft_irc** is a custom implementation of an **IRC (Internet Relay Chat) server** written in C++98 as part of the 42 School curriculum.

The goal of this project is to understand and reproduce the core functionality of the IRC protocol by developing a fully functional server capable of handling multiple simultaneous clients, channels, authentication, and message exchange.

The server communicates using the IRC protocol and can be used with standard IRC clients such as HexChat, WeeChat, irssi, or any client compatible with RFC 1459 / RFC 2812. Through this project, we explored network programming concepts including socket management, multiplexing, client-server architecture, protocol parsing, and concurrent connection handling.

### Main Features

- TCP server using non-blocking sockets
- Multiple client connections
- Password-protected server access
- Nickname and username registration
- Channel creation and management
- Public and private messaging
- Channel operators
- Support for common IRC commands:
  - PASS
  - NICK
  - USER
  - JOIN
  - PRIVMSG
  - KICK
  - INVITE
  - TOPIC
  - MODE
  - QUIT
- Channel modes:
  - `i` — invite-only
  - `t` — topic restricted to operators
  - `k` — channel password
  - `o` — operator privileges
  - `l` — user limit

---

## Project Structure

```text
ft_irc/
├── bonus/
├── include/        # Header files
├── src/            # Source files
├── Makefile
└── README.md
```

---

## Instructions

### Requirements

- Linux or macOS
- C++ compiler supporting the C++98 standard
- Make

### Compilation

Clone the repository and compile the project:

```bash
git clone <repository_url>
cd ft_irc
make
```

This will generate the executable:

```bash
./ircserv
```

### Launching the Server

The server requires two arguments:

```bash
./ircserv <port> <password>
```

Example:

```bash
./ircserv 6667 mypassword
```

Where:

- `port` is the listening TCP port.
- `password` is the server password required by clients.

### Connecting with an IRC Client

Example using HexChat:

1. Open HexChat.
2. Create a new network.
3. Set:
   - Host: `localhost`
   - Port: `6667`
   - Password: `mypassword`
4. Connect.
5. Join a channel:

```text
/join #42
```

### Useful IRC Commands

Register:

```text
PASS mypassword
NICK nickname
USER username 0 * :Real Name
```

Join a channel:

```text
JOIN #channel
```

Send a message:

```text
PRIVMSG #channel :Hello everyone!
```

Send a private message:

```text
PRIVMSG nickname :Hello!
```

Become familiar with channel administration:

```text
KICK
INVITE
TOPIC
MODE
```

---

## Technical Choices

### Network Model

The server uses:

- TCP sockets for reliable communication.
- Non-blocking I/O.
- Multiplexing through `poll()` to handle multiple clients simultaneously without spawning a thread per connection.

### Architecture

The project is organized around several core components:

- **Server**: manages sockets and event polling.
- **Client**: stores user state and connection data.
- **Channel**: manages channel membership, permissions, and channel-specific modes.
- **Command Parser**: interprets IRC messages and dispatches commands.
- **Command Handlers**: implement protocol-specific behavior.

### Compliance

The implementation follows the project specifications and reproduces the behavior expected from a standard IRC server while remaining compatible with common IRC clients.

---

## Learning Outcomes

Through this project we gained practical experience in:

- Socket programming
- Network protocols
- Event-driven architectures
- IRC protocol design
- Parsing and command processing
- Object-Oriented Programming in C++98
- Resource management and error handling
- Collaborative software development using Git

---

## Resources

### IRC Documentation

- RFC 1459 — Internet Relay Chat Protocol
  - https://datatracker.ietf.org/doc/html/rfc1459

- RFC 2812 — Internet Relay Chat: Client Protocol
  - https://datatracker.ietf.org/doc/html/rfc2812

- RFC 2810 — IRC Architecture
  - https://datatracker.ietf.org/doc/html/rfc2810

### Socket Programming

- Beej's Guide to Network Programming
  - https://beej.us/guide/bgnet/

- Linux `poll()` documentation
  - https://man7.org/linux/man-pages/man2/poll.2.html

- Linux socket API documentation
  - https://man7.org/linux/man-pages/man7/socket.7.html

### IRC Clients

- HexChat
  - https://hexchat.github.io/

### C++ References

- C++98 Reference
  - https://en.cppreference.com/

- ISO C++ FAQ
  - https://isocpp.org/faq

### AI Usage

Artificial Intelligence tools (ChatGPT) were used exclusively as learning and documentation assistants during the development of the project.

AI assistance included:

- Clarification of IRC protocol concepts and RFC interpretation.
- Explanations of socket programming concepts.
- Assistance in understanding `poll()` behavior and event-driven architectures.
- Code review suggestions and debugging guidance.
- README drafting and documentation improvements.

All architectural decisions, implementation, testing, debugging, and final code were designed, developed, reviewed, and validated by the project authors.
