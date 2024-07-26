# _printf

## Description

`_printf` is a custom implementation of the standard C library function `printf`. It provides a subset of the functionality offered by `printf`, allowing formatted output to be printed to the standard output.

## Features

The `_printf` function supports the following format specifiers:
- `%c` : Prints a character.
- `%s` : Prints a string.
- `%%` : Prints a literal percent sign.
- `%i` : Prints an integer in decimal format
- `%d` : Prints a decimal integer

## Function Signature

```c
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

## Compiling

The code has to be compiled with this
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

### Authorized functions and macros
```
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)
```

## Run Locally

Clone the project

```
	git clone https://github.com/MrSandouiche2/holbertonschool-printf.git
```
Go to the project directory

```
  cd holbertonschool-printf
```

Compile it with this line of command

```
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

## Authors
[@Trésor](https://github.com/EL274)
[@Mehdi](https://github.com/MrSandouiche2)



