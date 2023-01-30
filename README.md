# ft_get_next_line
42 Madrid project

Grade: 125/100

`get_next_line` is a function that reads a line ending with a newline character '\n' from a file descriptor and returns it as a null-terminated string. The implementation of the function reads a line ending with a newline character '\n' from a file descriptor and returns it as a null-terminated string. The implementation of the function also includes the gnl_bzero and gnl_calloc functions.

I see it as a introduction to text parsing for future system and network communication applications.

### Usage
Include the header file get_next_line_bonus.h in your program, and call the function get_next_line with the file descriptor of the file you want to read from.

```
#include "get_next_line_bonus.h"

char *line;
int fd;

fd = open("file.txt", O_RDONLY);
line = get_next_line(fd);
printf("%s", line);
close(fd);
```

The function get_next_line returns a null-terminated string with the next line of the file. If there is an error opening the file, the function returns NULL.

### Limitations
The function has a limit of `FOPEN_MAX` file descriptors and a buffer size of `BUFFER_SIZE`. If you want to change these limits, you need to modify the definitions in the header file `get_next_line_bonus.h`.

### Additional Functions
The implementation of the `get_next_line` function also includes the `gnl_bzero` and `gnl_calloc` functions.

The gnl_bzero function sets the first 'len' bytes of the block of memory pointed by 'str' to zero.

The `gnl_calloc` function allocates a block of memory for an array of 'count' elements, each of 'size' bytes and returns a pointer to the first byte of the allocated memory.
