*This project has been created as part of the 42 curriculum by naamir.*

# Libft

## Description
Libft is my first custom C library, where I try to re-implement standard libc
functions (Part 1), additional quality-of-life functions like `ft_split`,
`ft_itoa` and `ft_substr` (Part 2) and linked-list manipulation functions
(Part 3).

## Instructions
Compile the library by running `make` in the repository root. This produces
`libft.a`. To use it, include `libft.h` and link against `libft.a`. Clean up 
object files with `make clean`, remove all artifacts with `make fclean`, or 
rebuild from scratch with `make re`.

## Resources
- [Libft subject](en.subject.pdf)
- [GNU libc manual](https://www.gnu.org/software/libc/manual/)
- man pages: `man isalpha`, `man strlcpy`, `man calloc`

### AI Usage
AI was used to review edge cases and memory handling in Part 1-3 functions,
and to help structure the Makefile. Core logic was written manually and 
verified against man pages.
