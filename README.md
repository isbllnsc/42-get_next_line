*This project has been created as part of the 42 curriculum by isabde-s.*

# get_next_line

## Description

This projects consists in coding a C function that reads a given file descriptor one line at a time, simulating the behavior of standard library functions like getline(). The function must allow you to read a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand.
Key learning objectives include: file descriptors and I/O, memory management, static variables and compilation flag.

---

## Instructions

### Files

The project is composed of the following files:

* `get_next_line.c` — main logic of the function
* `get_next_line_utils.c` — helper functions
* `get_next_line.h` — header file
* `README.md`

---

### Compilation

Compile the project by defining `BUFFER_SIZE` at compile time:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42
```

You may change the value of `BUFFER_SIZE` to test different behaviors:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=1000
```

---

## Resources

### Documentation and references

* `man 2 read`
* `man 2 open`
* `man 3 malloc`
* `man 3 free`
* 42 official subject PDF for *get_next_line*
* cppreference.com (C standard library reference)

### Use of Artificial Intelligence

AI tools (ChatGPT) were used as a **learning and debugging assistant**, specifically to:

* clarify concepts such as file descriptors, buffers, and static variables,
* reason about memory management and edge cases,
* review logic for helper functions (`ft_strjoin`, `extract_line`, `clean_stash`),
* identify and correct compilation errors and undefined behaviors.

All code was **written, adapted, and understood by the author**, with AI serving as a conceptual guide rather than an automated code generator.