*This project has been created as part of the 42 curriculum by haghomar.*

# Libft

## Description

**Libft** is an individual project from the 42 curriculum. The goal of this project is to create a personal C library by reimplementing several standard C library functions, as well as developing additional utility functions.

Instead of relying entirely on standard library functions, this project requires us to understand how these functions work internally and implement our own versions.

The library is called `libft.a` and contains reusable functions for manipulating characters, strings, memory, numbers, and linked lists.

This project helps develop a deeper understanding of:
- C programming and memory management.
- Pointers and pointer arithmetic.
- Dynamic memory allocation using `malloc` and `free`.
- String and memory manipulation.
- Data structures, especially singly linked lists.
- Compilation and static libraries using Makefiles.

## Instructions

### Requirements

To compile this library, you need:

- A C compiler (`cc` or `gcc`).
- GNU Make.
- A Unix-based operating system (Linux or macOS).

### Compilation

Clone the repository:

```bash
git clone git@vogsphere-v2-bg.1337.ma:vogsphere/intra-uuid-7729103e-7c3e-4fc2-9b84-28bdd83fb396-7738480-haghomar
```

Navigate to the project directory:

```bash
cd Libft
```

Compile the library:

```bash
make
```

This generates the static library:

```text
libft.a
```

### Makefile commands

| Command | Description |
|---|---|
| `make` | Compiles the source files and creates `libft.a`. |
| `make clean` | Removes the object files (`.o`). |
| `make fclean` | Removes object files and `libft.a`. |
| `make re` | Recompiles the entire library. |

### Using the library

To use Libft in another C project, include the header file:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lft -o program
```

Then execute it:

```bash
./program
```

## Library Description

The library is divided into several categories of functions.

### 1. Character Checking and Conversion

These functions reproduce the behavior of standard C character functions.

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is an alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII character set. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

### 2. String Length and Memory Manipulation

These functions allow working directly with memory blocks and measuring string lengths.

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_memset` | Fills a memory block with a specific byte. |
| `ft_bzero` | Sets a memory block to zero. |
| `ft_memcpy` | Copies a specified number of bytes from one memory area to another. |
| `ft_memmove` | Copies memory safely, including overlapping memory areas. |
| `ft_memchr` | Searches for a specific byte in a memory block. |
| `ft_memcmp` | Compares two memory blocks byte by byte. |

### 3. String Manipulation

These functions reproduce standard string operations.

| Function | Description |
|---|---|
| `ft_strlcpy` | Copies a string into a destination buffer with size limitation. |
| `ft_strlcat` | Concatenates strings while respecting the destination buffer size. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strnstr` | Searches for a substring within a string, limited by a specified length. |
| `ft_strdup` | Duplicates a string using dynamic memory allocation. |

### 4. Memory Allocation and Number Conversion

These functions handle memory allocation and conversions between strings and integers.

| Function | Description |
|---|---|
| `ft_calloc` | Allocates memory for an array and initializes it to zero. |
| `ft_atoi` | Converts a string into an integer. |
| `ft_itoa` | Converts an integer into a newly allocated string. |

### 5. Additional String Functions

These functions provide useful operations for creating and manipulating strings.

| Function | Description |
|---|---|
| `ft_substr` | Creates a substring from a given string, starting at a specified position. |
| `ft_strjoin` | Concatenates two strings into a newly allocated string. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter. |
| `ft_strmapi` | Applies a function to each character of a string and creates a new string. |
| `ft_striteri` | Applies a function to each character of a string using its index. |

### 6. File Descriptor Output Functions

These functions write characters, strings, and numbers to a specified file descriptor.

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a specified file descriptor. |
| `ft_putstr_fd` | Writes a string to a specified file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a specified file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a specified file descriptor. |

### 7. Linked List Functions

This part of the library implements operations for managing singly linked lists.

The project uses the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node contains:
- `content`: A pointer to the data stored in the node.
- `next`: A pointer to the next node in the list.

The following functions provide linked-list operations:

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node with the given content. |
| `ft_lstadd_front` | Adds a new node at the beginning of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a new node at the end of a list. |
| `ft_lstdelone` | Deletes one node and frees its content using a given deletion function. |
| `ft_lstclear` | Deletes and frees an entire list. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

## Technical Choices

- **Language:** C.
- **Compiler:** `cc`.
- **Compilation flags:** `-Wall -Wextra -Werror`.
- **Library format:** Static library (`.a`).
- **Build system:** Makefile.
- **Header file:** `libft.h`.

The project follows the coding standards and restrictions imposed by the 42 curriculum.

## Resources

The following resources were used to understand the concepts and implement the library:

- [42 Libft Subject](https://cdn.intra.42.fr/pdf/pdf/230875/en.subject.pdf) – Official project requirements.
- [C Reference](https://en.cppreference.com/w/c.html) – C language documentation and reference.
- [Linux Manual Pages](https://man7.org/linux/man-pages/) – Documentation for standard C and system functions.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) – Understanding Makefiles and compilation rules.
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/) – Reference for standard library behavior.

### AI Usage

AI tools (ChatGPT) were used as a learning and development assistant during this project.

They were used for:
- Understanding how standard C library functions work.
- Explaining pointers, memory allocation, pointer arithmetic, and linked lists.
- Understanding compiler errors, segmentation faults, and memory errors.
- Debugging and investigating issues identified using Valgrind.
- Understanding Makefile rules and compilation commands.
- Suggesting test cases and explaining edge cases.
- Reviewing implementation logic and improving understanding of the project requirements.

AI-generated explanations and suggestions were used as learning support. The implementation, testing, and final decisions were handled by the student.

## Author

**haghomar**

42 Network – 1337
