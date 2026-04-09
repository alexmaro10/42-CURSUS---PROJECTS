# get_next_line

## Overview

get_next_line is a function that reads a line from a file descriptor, one line at a time, until the end of the file or an error occurs. It is part of the 42 curriculum and emphasizes efficient reading with buffering, handling multiple file descriptors, and proper memory management. The function returns 1 if a line is read, 0 on EOF, and -1 on error.

The project consists of the main function in `get_next_line.c`, utility functions in `get_next_line_utils.c`, and a header file `get_next_line.h`.

## Memory Management

Memory in get_next_line is managed carefully to avoid leaks and ensure efficiency:

- **Buffer Allocation**: A static buffer of size `BUFFER_SIZE` (defined in the header or as a macro) is used to read chunks from the file descriptor. This buffer is reused across calls.
- **Line Allocation**: The `line` parameter is dynamically allocated using `malloc` to store the extracted line, including the newline character if present. The caller is responsible for freeing this memory.
- **Static Storage**: A static variable holds the remaining unread data from the buffer, preventing data loss between function calls.
- **Cleanup**: On EOF or error, any remaining static data is freed. Utility functions like `ft_strjoin` and `ft_substr` handle string operations with proper allocation.
- **Edge Cases**: Handles NULL inputs, invalid file descriptors, and ensures no memory leaks by freeing temporary strings.

## Static Variables

Static variables in C retain their value between function calls and are initialized only once. In get_next_line:

- A static `char *` (often called `stash` or `remainder`) stores the leftover buffer content after extracting a line. This allows the function to resume reading from where it left off in subsequent calls.
- For multiple file descriptors, an array of static pointers or a more advanced structure (like a linked list) can be used to maintain separate states per fd.
- Benefits: Enables reading large files without loading everything into memory at once, and supports reading from multiple fds concurrently without interference.

## Functions

### Main Function

| Function | Description |
|----------|-------------|
| `get_next_line(int fd, char **line)` | Reads the next line from the file descriptor into `line`. Returns 1 on success, 0 on EOF, -1 on error. |

### Utility Functions

| Function | Description |
|----------|-------------|
| `ft_strjoin(char const *s1, char const *s2)` | Concatenates two strings into a new allocated string. |
| `ft_strchr(const char *s, int c)` | Finds the first occurrence of a character in a string. |
| `ft_strlen(const char *s)` | Returns the length of a string. |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Extracts a substring from a string. |
| `ft_strdup(const char *s1)` | Duplicates a string. |
