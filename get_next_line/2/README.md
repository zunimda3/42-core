*This project has been created as part of the 42 curriculum by naamir.*

# get_next_line

## Description

`get_next_line` implements a C function that returns the next line read from a
file descriptor. Repeated calls advance through the input one line at a time.
The returned string includes its terminating newline when one is present; the
last line may be returned without a newline when the file ends. The function
returns `NULL` when there is nothing left to read or when an error occurs.

The project introduces buffered input, dynamic memory management, file
descriptors, and function-local static storage. `BUFFER_SIZE` controls the
maximum number of bytes requested by each call to `read()`.

## Instructions

The required source files are:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

`get_next_line.c` contains the public function, while the reading, extraction,
and string helpers are implemented in `get_next_line_utils.c`.

Compile them with a chosen buffer size and your own test program containing a
`main` function:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

The header provides a default buffer size when `BUFFER_SIZE` is not defined, so
compilation without `-D BUFFER_SIZE=n` is also supported.

A typical call loop is:

```c
char *line;

line = get_next_line(fd);
while (line)
{
    /* Process the line here. */
    free(line);
    line = get_next_line(fd);
}
```

The caller owns every returned line and must free it. This mandatory
implementation maintains one reading state and is therefore intended for one
file descriptor at a time.

## Algorithm

The function keeps unread input in a function-local static string named
`saved`. Static storage is necessary because ordinary local variables disappear
when a function returns, while unread bytes must remain available for the next
call.

For each call, the algorithm works as follows:

1. Reject an invalid file descriptor or non-positive buffer size.
2. Allocate a temporary buffer of `BUFFER_SIZE + 1` bytes.
3. If `saved` does not contain a newline, read one chunk from the descriptor,
   terminate it with `\0`, append it to `saved`, and discard the previous
   allocation. Repeat only until a newline, end-of-file, or error is reached.
4. Copy the first complete line from `saved`, including `\n` when present.
5. Copy any bytes after that line into a new allocation, free the old `saved`
   string, and retain the remainder for the next call.
6. Return the extracted line. On an error or when no data remains, release the
   relevant allocations and return `NULL`.

This approach was selected because it stops issuing reads as soon as the saved
data contains a newline, while still preserving bytes that share a read chunk
with the following line. It works for lines smaller or larger than
`BUFFER_SIZE` and for a final line without a newline. With the simple repeated
string joins used here, processing a very long line can require quadratic
copying in the line length; the implementation favors clarity and compliance
with the project's limited set of permitted functions.

## Resources

- [Linux `read(2)` manual](https://man7.org/linux/man-pages/man2/read.2.html) —
  behavior, return values, and errors of `read()`.
- [POSIX `read()` specification](https://pubs.opengroup.org/onlinepubs/9799919799/functions/read.html)
  — portable requirements for reading from a file descriptor.
- [C storage-class specifiers](https://en.cppreference.com/w/c/language/storage_duration)
  — static storage duration and linkage in C.
- The `get_next_line` subject, version 14.3, supplied with the project.

AI was used as a review and learning aid to discuss how to isolate the reading
operation in a helper, identify an end-of-file loop condition, check appropriate
use of `ssize_t`, and suggest edge cases. 
