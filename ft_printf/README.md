*This project has been created as a part of the 42 curriculum by jjurado.*

<div align="center">

  <h1><code>ft_printf</code></h1>
  <p><i>Because <code>write(1, "hello", 5)</code> is simply not enough.</i></p>

  <p>
    <a href="https://42.fr"><img src="https://img.shields.io/badge/School-42_M%C3%A1laga-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Málaga" /></a>
    <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language C" />
    <img src="https://img.shields.io/badge/Norminette-PASSED-brightgreen?style=for-the-badge" alt="Norminette Passed" />
  </p>

  <p>
    <a href="#-about-the-project">About</a> •
    <a href="#-architecture--data-flow">Architecture</a> •
    <a href="#-conversions-handled">Conversions</a> •
    <a href="#-project-structure">Structure</a> •
    <a href="#-usage--compilation">Usage</a>
  </p>

  ---
</div>

## 📌 About the Project

The **`ft_printf`** project at 42 requires recoding the standard C library's `printf` function. The primary objective is to handle variadic arguments using `<stdarg.h>`, format various data types, and return the exact total count of printed characters.

### Key Highlights
* ⚙️ **Direct Return Architecture:** Every output function returns the exact number of written characters, cascading directly into the total count.
* 🛡️ **Type Safety & Bounds:** Proper management of signed/unsigned boundary conditions (`INT_MIN`, `UINT_MAX`, 64-bit pointers).
* 🧼 **Strict 42 Norm Compliance:** Zero memory leaks, zero norm warnings, clean function splitting.

---

## 🧱 Architecture & Data Flow

The project uses a dispatcher structure that delegates printing and counting to specialized helpers without global or local counter pollution.

```
                                      ┌─────────────────────────┐
                                      │       ft_printf         │
                                      │  (Format Loop Router)   │
                                      └────────────┬────────────┘
                                                   │
                                                   ▼
                                      ┌─────────────────────────┐
                                      │        ft_parser        │
                                      │  (Variadic Dispatcher)  │
                                      └────────────┬────────────┘
                                                   │
               ┌───────────────────────────────────┴───────────────────────────────────┐
               ▼                                   ▼                                   ▼
  ┌─────────────────────────┐         ┌─────────────────────────┐         ┌─────────────────────────┐
  │      ft_parser_str      │         │      ft_parser_nbr      │         │        ft_putchar       │
  │          (%s)           │         │   (%d, %i, %u, %x...)   │         │         (%c, %%)        │
  └─────────────────────────┘         └────────────┬────────────┘         └─────────────────────────┘
                                                   │
                                                   ▼
                                      ┌─────────────────────────┐
                                      │     ft_putnbr_base      │
                                      │  (Recursive Function)   │
                                      └─────────────────────────┘
```

---

## 🎨 Conversions Handled

| Specifier | Argument Type | Description | Example Output |
| :---: | :---: | :--- | :--- |
| <comment-tag>`%c`</comment-tag> | `int` | Single character | `'A'` |
| <comment-tag>`%s`</comment-tag> | `char *` | String of characters (handles `NULL` as `(null)`) | `"42 Málaga"` |
| <comment-tag>`%p`</comment-tag> | `void *` | Memory address in hexadecimal (handles `0` as `(nil)`) | `0x7ffee4b32abc` |
| <comment-tag>`%d`</comment-tag> | `int` | Base 10 signed integer | `-2147483648` |
| <comment-tag>`%i`</comment-tag> | `int` | Base 10 signed integer | `42` |
| <comment-tag>`%u`</comment-tag> | `unsigned int` | Base 10 unsigned integer | `4294967295` |
| <comment-tag>`%x`</comment-tag> | `unsigned int` | Base 16 lowercase hexadecimal | `2fa3` |
| <comment-tag>`%X`</comment-tag> | `unsigned int` | Base 16 uppercase hexadecimal | `2FA3` |
| <comment-tag>`%%`</comment-tag> | None | Literal percent sign | `%` |

---

## 🛠️ Usage & Compilation

### 1. Build the library
Run `make` to compile the library into `libftprintf.a`:

```bash
make
```

### 2. Available Rules
* `make` — Compiles `libftprintf.a`.
* `make clean` — Removes object (`.o`) files.
* `make fclean` — Removes object files and `libftprintf.a`.
* `make re` — Rebuilds the entire library.

### 3. Integration Example

Create a `main.c`:

```c
#include "libftprintf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s! Number: %d, Hex: %x, Pointer: %p\n", "42", 42, 255, &len);
	ft_printf("Printed %d characters.\n", len);
	return (0);
}
```

Compile with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```