*This project has been created as part of the 42 curriculum by naamir.*

# ft_printf

## Description

`ft_printf` is a C static library that recreates the mandatory behaviour of the
standard `printf` function. The project introduces variadic functions, format
string parsing, number-base conversion, recursion, and static-library creation.

The library produces `libftprintf.a` and provides this public function:

```c
int	ft_printf(const char *fmt, ...);
```

The mandatory conversions supported are:

| Conversion | Output |
| --- | --- |
| `%c` | A single character |
| `%s` | A null-terminated string |
| `%p` | A pointer in hexadecimal notation |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal integer using lowercase digits |
| `%X` | An unsigned hexadecimal integer using uppercase digits |
| `%%` | A percent sign |

The implementation performs no output buffering. Characters are written
directly to standard output with `write`.

## Algorithm and data structures

`ft_printf` reads the format string from left to right while maintaining a
counter for the number of characters written. An ordinary character is written
immediately. When a `%` is encountered, the next character is treated as a
conversion specifier and dispatched to either the numeric or non-numeric
conversion function.

Arguments are accessed through a `va_list`. Each conversion retrieves the type
required by its specifier with `va_arg`. The same `va_list` is passed by pointer
to the helper functions so consuming an argument updates the shared traversal
state.

Numeric output uses recursive base conversion. The number is repeatedly divided
by the base length until its most significant digit is reached. As the recursive
calls return, each remainder selects a character from the appropriate digit
string, such as `0123456789abcdef`. Signed decimal values are handled separately
so a negative sign can be written before converting the magnitude.

No heap-allocated data structure is needed. The implementation uses:

- A `va_list` to traverse the variable arguments.
- Pointers to traverse strings and share the output counter.
- Constant digit strings to represent decimal and hexadecimal alphabets.
- The call stack for recursive number conversion.

This design was chosen because the mandatory conversions can be processed in a
single pass without storing the formatted result. It keeps memory use small and
matches the subject requirement not to reproduce the original `printf` buffer
management.

## Instructions

Build the static library from the project root:

```sh
make
```

The Makefile provides the required rules:

```sh
make all      # Build libftprintf.a
make clean    # Remove object files
make fclean   # Remove object files and libftprintf.a
make re       # Perform a complete rebuild
```

To use the library in another C program, include the header:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Value: %d\n", 42);
	return (0);
}
```

Then link that program with the archive:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```

## Project structure

- `ft_printf.c`: format-string traversal and conversion dispatch.
- `conversion_num.c`: numeric and pointer conversions.
- `conversion_other.c`: character, string, and percent conversions.
- `putnbr_base.c`: recursive unsigned base conversion.
- `putnbr_signed.c`: recursive signed decimal conversion.
- `ft_strlen.c`: local string-length helper.
- `ft_printf.h`: shared declarations and required system headers.
- `Makefile`: compilation and static-library rules.

## Resources

- [`printf(3)` manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)` manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [`write(2)` manual page](https://man7.org/linux/man-pages/man2/write.2.html)

AI was used as a learning assistant to explain header files, separate compilation,
object files, static libraries, and Makefile rules one step at a time. The source 
code was developed and edited by myself, tested and compared against the official
printf(3).
