# ft_printf

## Overview

ft_printf is a custom implementation of the `printf` function from the C standard library (stdio.h), part of the 42 curriculum. It provides formatted output to the standard output (stdout) or a specified file descriptor, supporting a subset of format specifiers such as characters, strings, integers, unsigned integers, hexadecimal numbers, and pointers. The project emphasizes handling variadic arguments and modular helper functions for different data types.

The library is compiled into a static archive or can be used directly, with a Makefile for building and cleaning.

## Variadic Arguments

ft_printf uses variadic functions to accept a variable number of arguments, similar to the standard `printf`. In C, variadic functions are declared with `...` in the parameter list. To access these arguments, the `<stdarg.h>` header provides macros:

- `va_list`: A type to hold the list of arguments.
- `va_start(va_list ap, last_named_param)`: Initializes the argument list, starting after the last named parameter.
- `va_arg(va_list ap, type)`: Retrieves the next argument of the specified type and advances the list.
- `va_end(va_list ap)`: Cleans up the argument list.

In ft_printf, `va_start` is called after processing the format string, `va_arg` is used to extract arguments based on format specifiers, and `va_end` is called at the end to free resources.

## Functions

### Main Function

| Function | Description |
|----------|-------------|
| `ft_printf(const char *format, ...)` | Formats and prints output according to the format string, supporting specifiers like %c, %s, %d, %i, %u, %x, %X, %p, and %%. Returns the number of characters printed. |

### Helper Functions

The helper functions are modular utilities that handle the writing of specific data types to stdout, each taking an `int *count` parameter to track the number of characters printed. They ensure efficient and type-safe output without redundancy in the main function.

| Function | Description |
|----------|-------------|
| `ft_putnbr_base(long long nbr, char *base)` | Prints a number in a given base (e.g., decimal, hexadecimal) by recursively dividing and mapping to base characters. |
| `ft_write_char(char c, int *count)` | Writes a single character using `write(1, &c, 1)` and increments the count. |
| `ft_write_hex(unsigned long long n, int uppercase, int *count)` | Writes a hexadecimal number, prefixing with "0x" for pointers, and handles uppercase/lowercase based on the flag. |
| `ft_write_number(int n, int *count)` | Writes a signed integer, handling negative numbers by printing '-' and recursing on the absolute value. |
| `ft_write_ptr(void *ptr, int *count)` | Writes a pointer address in hexadecimal format, casting to `unsigned long long` and using `ft_write_hex`. |
| `ft_write_str(char *s, int *count)` | Writes a string character by character, handling NULL by printing "(null)". |
| `ft_write_unsigned_nbr(unsigned int n, int *count)` | Writes an unsigned integer by recursively dividing and printing digits. |
