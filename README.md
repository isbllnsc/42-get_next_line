*This project has been created as part of the 42 curriculum by isabde-s.*

# get_next_line

## Description

This projects consists in coding a C function that reads a given file descriptor one line at a time, simulating the behavior of standard library functions like getline(). The function must allow you to read a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand.
Key learning objectives include: file descriptors and I/O, memory management, static variables and compilation flag.

---

## Instructions

### Function Prototype

```c
char *get_next_line(int fd);
````

### Files Provided

* `get_next_line.c`
* `get_next_line_utils.c`
* `get_next_line.h`

### Compilation

Compilation is done directly using `cc`:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

To test the function, you can add your own `main.c`:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

Or you can use the main function I made and left commented on the `get_next_line.c`.

### Usage Example

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---
!!!!!!!!!!!!!!!!! REVISAR !!!!!!!!!!!!!!!!!!
## Algorithm Explanation and Justification

The algorithm uses a **static buffer (stash)** to store unread data between function calls.
This allows the function to remember leftover content after returning a line.

### Steps:

1. Read from the file descriptor into a temporary buffer.
2. Append the buffer to the static stash.
3. Check if a newline character (`\n`) exists in the stash.
4. If found:

   * Extract the line up to and including `\n`.
   * Keep the remaining content in the stash for the next call.
5. If EOF is reached:

   * Return the remaining content (if any).
   * Free the stash.

### Why this approach?

* Ensures **no data loss** between calls.
* Handles files of any size.
* Efficient memory usage by freeing unused buffers.
* Fully compliant with the project constraints.

---

## Resources

* Linux `read()` manual
* 42 Network subject PDF
* Articles about static variables in C

### AI Usage

AI was used to:

* Review the explanation clarity
* Improve documentation structure
* Ensure compliance with README requirements

---