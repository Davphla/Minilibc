  ```
  __  __ _       _ _ _ _          
 |  \/  (_)     (_) (_) |         
 | \  / |_ _ __  _| |_| |__   ___ 
 | |\/| | | '_ \| | | | '_ \ / __|
 | |  | | | | | | | | | |_) | (__ 
 |_|  |_|_|_| |_|_|_|_|_.__/ \___|
```
                                  
# Minilibc

Minilibc is a lightweight C library designed to reimplement key string and memory manipulation functions from the standard C library using **assembly language**. This project provides high-performance, low-level alternatives to commonly used functions, making it ideal for projects requiring optimized or minimal runtime environments.

---

## Features

The following functions are fully implemented in assembly:

- **String Manipulation**
  - `strlen` :white_check_mark: — Calculate the length of a string.
  - `strchr` :white_check_mark: — Locate the first occurrence of a character in a string.
  - `strcmp` :white_check_mark: — Compare two strings.
  - `strncmp` :white_check_mark: — Compare two strings up to a specified length.
  - `strcasecmp` :white_check_mark: — Compare two strings ignoring case.
  - `strstr` :white_check_mark: — Locate a substring within a string.
  - `strpbrk` :white_check_mark: — Find the first occurrence of any character from a set.
  - `strcspn` :white_check_mark: — Determine the length of a segment not containing specified characters.

- **Memory Manipulation**
  - `memset` :white_check_mark: — Set a block of memory to a specific value.
  - `memmove` :white_check_mark: — Safely copy memory areas that may overlap.

---

## Why Minilibc?

- **Lightweight**: Focused on essential functionality without the overhead of a full standard library.
- **Optimized**: Written in assembly for high performance and efficiency.
- **Portable**: Can be integrated into low-level systems or embedded environments where minimal dependencies are critical.
- **Educational**: Ideal for learning about low-level programming and assembly language techniques.

---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/minilibc.git
   cd minilibc
   ```

2. **Build the Library**:
   Ensure you have an appropriate assembler and compiler toolchain installed.
   ```bash
   make
   ```

3. **Include Minilibc in Your Project**:
   Link the `libasm.a` archive with your application during the build process:
   ```bash
   gcc -o your_program your_program.c -L. -lasm
   ```

---

## Usage

Include the relevant headers in your C code, then call the functions as you would with the standard library:
```c
#include "minilibc.h"

int main() {
    char str[] = "Hello, world!";
    size_t len = strlen(str);
    printf("Length: %zu\n", len);
    return 0;
}
```

---

## Roadmap

### Completed
- Core functions implemented:
  - `strlen`, `strchr`, `memset`, `strcmp`, `memmove`, `strncmp`, `strcasecmp`, `strstr`, `strpbrk`, `strcspn`.

### TODO
- **Add Unit Testing**: Implement testing using [Unity](https://www.throwtheswitch.org/unity) to ensure function correctness.
- **Release Library on GitHub**: Provide pre-built binaries and documentation.
- **Add SIMD Optimization**: Extend functionality with `libsimd` for enhanced performance.

