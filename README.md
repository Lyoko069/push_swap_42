*This project has been created as a part of the 42 curriculum by jjurado and mavidal-.*

<div align="center">

  <h1><code>push_swap</code></h1>
  <p><i>Because Swap_push isn’t as natural. Sorting integers across two stacks with the lowest possible number of operations.</i></p>

  <p>
    <a href="https://42.fr"><img src="https://img.shields.io/badge/School-42_M%C3%A1laga-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Málaga" /></a>
    <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language C" />
    <img src="https://img.shields.io/badge/Norminette-PASSED-brightgreen?style=for-the-badge" alt="Norminette Passed" />
  </p>

  <p>
    <a href="#-about-the-project">About</a> •
    <a href="#-architecture--data-flow">Architecture</a> •
    <a href="#-operations--memory-safety">Operations & Memory</a> •
    <a href="#-project-structure">Structure</a> •
    <a href="#-usage--compilation">Usage</a>
  </p>

  ---
</div>

## 📌 About the Project

The **`push_swap`** project at 42 challenges us to sort a list of unique integers in ascending order using two stacks (**Stack A** and **Stack B**) and a restricted set of stack manipulation instructions, aiming to minimize the total number of moves.

### Key Highlights
* ⚙️ **Bidirectional Doubly Linked Lists:** Each node (`t_stack`) stores its integer `value`, normalized `index`, and pointers to both `prev` and `next` nodes for $O(1)$ head/tail reconnections.
* 📊 **Disorder Metric & Strategy Flags:** Computes the initial inversion ratio (`ft_compute_disorder`) and supports execution flags (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`).
* 🛡️ **Strict Input & Overflow Validation:** Parses signed integers using `long` accumulators to catch `INT_MAX`/`INT_MIN` overflows, non-numeric characters, and duplicate values cleanly.
* 🧼 **Strict 42 Norm & Leak-Free:** Compiled with `-Wall -Wextra -Werror`, integrated with custom `ft_printf`, and verified with **0 memory leaks** in Valgrind.

---

## 🧱 Architecture & Data Flow

The program centralizes stack pointers, operation counters, and strategy settings inside a unified `t_data` state structure, flowing through a 4-stage execution pipeline:

```
                                      ┌─────────────────────────┐
                                      │      main & parser      │
                                      │  (Flags, Validation &   │
                                      │   Doubly Linked Build)  │
                                      └────────────┬────────────┘
                                                   │
                                                   ▼
                                      ┌─────────────────────────┐
                                      │  Disorder & Indexing    │
                                      │ (ft_compute_disorder &  │
                                      │    ft_assign_index)     │
                                      └────────────┬────────────┘
                                                   │
               ┌───────────────────────────────────┴───────────────────────────────────┐
               ▼                                                                       ▼
  ┌─────────────────────────┐                                             ┌─────────────────────────┐
  │     ft_sort_small       │                                             │     ft_sort_simple      │
  │ (≤ 5 Elements & 3-Sort) │                                             │ (Min-Extraction & Push) │
  └─────────────────────────┘                                             └─────────────────────────┘
```

---

## 🧹 Operations & Memory Safety

### Allowed Instruction Set
Every public operation updates its internal doubly linked list pointers (`static` helpers), increments its telemetry counter in `d->count[OP]`, and writes the instruction to `stdout`:

| Category | Instructions | Description |
| :--- | :--- | :--- |
| **Swap** | `sa`, `sb`, `ss` | Swaps the first two elements at the top of Stack A, Stack B, or both simultaneously. |
| **Push** | `pa`, `pb` | Pops the top element from one stack and pushes it onto the top of the other. |
| **Rotate** | `ra`, `rb`, `rr` | Shifts all elements up by 1; the first element becomes the last. |
| **Reverse Rotate** | `rra`, `rrb`, `rrr` | Shifts all elements down by 1; the last element becomes the first. |

### Memory & Leak Prevention

| Module / Function | Allocation Point | Free Condition | Description |
| :--- | :--- | :--- | :--- |
| `ft_new_node` | `malloc(sizeof(t_stack))` | `ft_free_stack` | Allocates each doubly linked node while building Stack A from CLI arguments. |
| `ft_error` | — | Invalid input / duplicate | Frees both `d->a` and `d->b`, prints `Error\n` to `stderr`, and exits with status `1`. |
| `main` | — | Program exit / already sorted | Calls `ft_free_stack` on both stacks before returning `0` to guarantee **0 leaks**. |

---

## 📁 Project Structure

| File | Description |
| :--- | :--- |
| `main.c` | Entry point: initializes `t_data`, parses arguments/flags, checks sorted state, and triggers sorting. |
| `push_swap.h` | Header containing `t_stack`, `t_data`, `t_op`, `t_strategy` definitions, and function prototypes. |
| `parser_arg.c` | Strict numeric validation and `long` conversion to prevent integer overflow. |
| `flags.c` | Parses optional strategy flags (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`). |
| `disorder.c` | Computes stack disorder ratio by counting inverted element pairs. |
| `index.c` | Assigns normalized sorted indices (`0` to `N - 1`) to every node in Stack A. |
| `stack_utils.c` | Doubly linked list constructors, duplicate checkers, sorted verification, and memory cleanup. |
| `stack_info.c` | Stack size calculation, minimum element position lookup, and shortest-path top rotation. |
| `sort.c` | Strategy router dispatching execution based on stack size and selected strategy flag. |
| `sort_small.c` | Optimal hard-coded sorting for 2 and 3 elements (`ft_sort_three`). |
| `sort_simple.c` | Selection-based sorting extracting minimum elements to Stack B before merging back. |
| `swap.c` / `push.c` | Internal pointer logic and public wrappers for `sa`, `sb`, `ss`, `pa`, and `pb`. |
| `rotate.c` / `rrotate.c` | Internal pointer logic and public wrappers for `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`. |
| `ft_printf/` | Custom `ft_printf` library compiled automatically via the `Makefile`. |

---

## 🛠️ Usage & Compilation

### 1. Build the Project
Compile `push_swap` and its `ft_printf` dependency using the `Makefile`:

```bash
make
```

### 2. Execution Examples
Run `push_swap` with a list of integers (and optional strategy flags):

```bash
# Default execution
./push_swap 42 -5 12 0 8

# Execution with explicit strategy flag
./push_swap --simple 3 2 1 5 4

# Count total instructions generated
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### 3. Testing Leaks & Edge Cases with Valgrind
Verify memory safety across valid inputs, sorted lists, and error cases (duplicates, overflows, non-numeric arguments):

```bash
# Standard unsorted list
valgrind --leak-check=full ./push_swap 9 -2 15 0 4

# Error handling (duplicate values)
valgrind --leak-check=full ./push_swap 1 2 2 3

# Overflow handling (> INT_MAX)
valgrind --leak-check=full ./push_swap 2147483648 0 -1
```

---

## 🤝 Resources & Useful Links

In this section, you will find the tools, documentation, and guides used to make the `push_swap` project.

### 🛠️ Tools
* **[Gemini AI](https://gemini.google.com/?hl=es-ES)** — Used to understand doubly linked list pointer manipulation, sorting strategies, and project documentation.
* **[Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)** — Visual debugging tool to inspect stack movements in real time.