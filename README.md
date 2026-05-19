*This project has been created as part of the 42 curriculum by ammirzae.*

# ft_printf – Because ft_putnbr() and ft_putstr() aren’t enough

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. 
The project focuses on learning **variadic functions** in C — functions that accept a variable number of arguments — using the `stdarg.h` macros (`va_start`, `va_arg`, `va_copy`, `va_end`). 
The goal is to produce a static library `libftprintf.a` that exposes a single function:

```c
int ft_printf(const char *, ...);
```

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d` | Signed decimal integer (base 10) |
| `%i` | Signed integer (base 10) |
| `%u` | Unsigned decimal integer (base 10) |
| `%x` | Unsigned hex integer (lowercase) |
| `%X` | Unsigned hex integer (uppercase) |
| `%%` | Literal percent sign |

The function returns the total number of characters printed, matching the behaviour of the original `printf()`.


## Instructions

### Compilation

```bash
# Build the library
make

# Clean object files
make clean

# Remove library and object files
make fclean

# Rebuild from scratch
make re
```

### Usage

Link `libftprintf.a` into your project:

```bash
cc -Wall -Wextra -Werror your_program.c -L/path/to/libftprintf.a -lftprintf
```

If `libftprintf.a` is in the same directory, then add the libary directly:
```bash
cc -Wall -Wextra -Werror your_program.c libftprintf.a
```

Include the header in your source files:

```c
#include "ft_printf.h"
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int n;

    n = ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Characters printed: %d\n", n);
    ft_printf("Pointer: %p | Hex: %x | Unsigned: %u\n", &n, 255, 4294967295U);
    return (0);
}
```

## Resources

- [42 Norm] Coding style standard for 42 projects
- [C `printf` man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C — `stdarg.h`](https://www.youtube.com/watch?v=7Sph8JlRo0g&t=439s&pp=ygUSVmFyaWFkaWMgZnVuY3Rpb25z)


### AI usage

During this project, AI (primarily DeepSeek and Claude) was used for the following tasks:
- Formatting this README according to the project requirements.
- Help with correcting mistakes and explaining concepts.
AI did not provide complete function implementations; it was used as a complementary learning tool.
