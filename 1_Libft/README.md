# Libft

## Overview

Libft is a custom C library project from the 42 curriculum, designed to reimplement essential functions from the standard C library (libc). It serves as a foundational library for future projects, providing a set of utility functions for string manipulation, memory operations, character checks, and more. The library includes mandatory functions, additional utilities, and bonus linked list functions. All functions are prefixed with `ft_` to avoid conflicts with standard library functions.

The library is compiled into a static archive (`libft.a`) using the provided Makefile, which supports compilation, cleaning, and recompilation.

## Functions

### Mandatory Functions

#### Character Checks

| Function | Description |
|----------|-------------|
| `ft_isalpha(int c)` | Checks if the character is an alphabetic letter (a-z, A-Z). |
| `ft_isdigit(int c)` | Checks if the character is a digit (0-9). |
| `ft_isalnum(int c)` | Checks if the character is alphanumeric (letter or digit). |
| `ft_isascii(int c)` | Checks if the character is a valid ASCII character (0-127). |
| `ft_isprint(int c)` | Checks if the character is printable (including space, 32-126). |

#### String Operations

| Function | Description |
|----------|-------------|
| `ft_strlen(const char *s)` | Returns the length of the string. |
| `ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Copies a string to a destination buffer with size limit, ensuring null-termination. |
| `ft_strlcat(char *dst, const char *src, size_t dstsize)` | Concatenates a string to the end of another with size limit. |
| `ft_strchr(const char *s, int c)` | Locates the first occurrence of a character in a string. |
| `ft_strrchr(const char *s, int c)` | Locates the last occurrence of a character in a string. |
| `ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares two strings up to n characters. |
| `ft_strnstr(const char *haystack, const char *needle, size_t len)` | Locates a substring within a string, limited by length. |
| `ft_strdup(const char *s1)` | Duplicates a string, allocating memory for the copy. |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Extracts a substring from a string starting at an index with a given length. |
| `ft_strjoin(char const *s1, char const *s2)` | Concatenates two strings into a new string. |
| `ft_strtrim(char const *s1, char const *set)` | Trims characters from the beginning and end of a string based on a set. |
| `ft_split(char const *s, char c)` | Splits a string into an array of substrings based on a delimiter. |
| `ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies a function to each character of a string, creating a new string. |
| `ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies a function to each character of a string in place. |

#### Memory Operations

| Function | Description |
|----------|-------------|
| `ft_memset(void *b, int c, size_t len)` | Fills a block of memory with a specified value. |
| `ft_bzero(void *s, size_t n)` | Sets a block of memory to zero. |
| `ft_memcpy(void *dst, const void *src, size_t n)` | Copies a block of memory from source to destination. |
| `ft_memmove(void *dst, const void *src, size_t len)` | Moves a block of memory, handling overlapping regions. |
| `ft_memchr(const void *s, int c, size_t n)` | Searches for a character in a block of memory. |
| `ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares two blocks of memory. |

#### Conversion

| Function | Description |
|----------|-------------|
| `ft_atoi(const char *str)` | Converts a string to an integer. |
| `ft_itoa(int n)` | Converts an integer to a string. |
| `ft_tolower(int c)` | Converts a character to lowercase. |
| `ft_toupper(int c)` | Converts a character to uppercase. |

#### Output

| Function | Description |
|----------|-------------|
| `ft_putchar_fd(char c, int fd)` | Writes a character to a file descriptor. |
| `ft_putstr_fd(char *s, int fd)` | Writes a string to a file descriptor. |
| `ft_putendl_fd(char *s, int fd)` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd(int n, int fd)` | Writes an integer to a file descriptor. |

#### Memory Allocation

| Function | Description |
|----------|-------------|
| `ft_calloc(size_t count, size_t size)` | Allocates and initializes memory for an array. |

### Bonus Functions (Linked Lists)

| Function | Description |
|----------|-------------|
| `ft_lstnew(void *content)` | Creates a new linked list node with given content. |
| `ft_lstadd_front(t_list **lst, t_list *new)` | Adds a new node to the front of the list. |
| `ft_lstsize(t_list *lst)` | Returns the number of nodes in the list. |
| `ft_lstlast(t_list *lst)` | Returns the last node of the list. |
| `ft_lstadd_back(t_list **lst, t_list *new)` | Adds a new node to the back of the list. |
| `ft_lstdelone(t_list *lst, void (*del)(void*))` | Deletes a single node and frees its content. |
| `ft_lstclear(t_list **lst, void (*del)(void*))` | Deletes and frees all nodes in the list. |
| `ft_lstiter(t_list *lst, void (*f)(void *))` | Applies a function to the content of each node. |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying a function to each node's content. |
