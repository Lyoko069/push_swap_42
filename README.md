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
    <a href="#-description">Description</a> •
    <a href="#%EF%B8%8F-instructions">Instructions</a> •
    <a href="#-algorithms">Algorithms</a> •
    <a href="#-architecture--data-flow">Architecture</a> •
    <a href="#-project-structure">Structure</a> •
    <a href="#-contributions">Contributions</a> •
    <a href="#-resources">Resources</a>
  </p>

  ---
</div>

## 📌 Description

The **`push_swap`** project at 42 challenges us to sort a list of unique integers in ascending order using two stacks (**Stack A** and **Stack B**) and a restricted set of stack instructions, while minimizing the total number of moves.

This version of the subject also asks for **four sorting strategies** of different complexity classes, a **disorder metric** that decides between them at runtime, and an optional **benchmark mode**.

### Key Highlights
* ⚙️ **Doubly linked lists:** each node (`t_stack`) stores its `value`, its normalized `index` (`0` … `n-1`) and `prev`/`next` pointers for $O(1)$ head/tail reconnections.
* 🧠 **Four strategies:** Simple $O(n^2)$, Medium $O(n\sqrt{n})$, Complex $O(n \log n)$ and an **Adaptive** selector driven by the disorder of the input.
* 📊 **Disorder metric & benchmark:** the share of inverted pairs is computed before any move, and `--bench` reports disorder, strategy, total and per-instruction counts on `stderr`.
* 🛡️ **Strict input validation:** non-numeric arguments, `INT_MAX`/`INT_MIN` overflow, duplicates (including `0` / `-0`) and conflicting flags all print `Error` to `stderr`.
* 🧼 **42 Norm & leak-free:** compiled with `-Wall -Wextra -Werror`, only `read`, `write`, `malloc`, `free` and `exit` are used, and every exit path frees both stacks.

### Allowed Instruction Set

Every public operation updates the list pointers, increments its counter in `d->count[OP]` and writes the instruction to `stdout`:

| Category | Instructions | Description |
| :--- | :--- | :--- |
| **Swap** | `sa`, `sb`, `ss` | Swaps the first two elements at the top of A, B, or both. |
| **Push** | `pa`, `pb` | Takes the top element of one stack and puts it on top of the other. |
| **Rotate** | `ra`, `rb`, `rr` | Shifts all elements up by 1; the first element becomes the last. |
| **Reverse Rotate** | `rra`, `rrb`, `rrr` | Shifts all elements down by 1; the last element becomes the first. |

---

## 🛠️ Instructions

### 1. Build

```bash
make        # builds ft_printf and push_swap
make clean  # removes object files
make fclean # removes object files, libftprintf.a and push_swap
make re     # full rebuild
```

### 2. Run

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <int> <int> ...
```

* The first number is the **top** of stack A. Flags may appear anywhere among the numbers.
* Without a strategy flag the program uses `--adaptive`. Giving two strategy flags is an error.
* Without arguments the program prints nothing. An already sorted list prints no instruction.

```bash
./push_swap 42 -5 12 0 8                 # adaptive (default)
./push_swap --simple 5 4 3 2 1           # force the O(n²) strategy
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

> **zsh users:** zsh does not split `$ARG` into words. Use `./push_swap ${=ARG}` or run the examples in `bash`.

### 3. Benchmark mode

`--bench` writes its report to **`stderr`**, so the instruction stream on `stdout` can still be piped into the checker:

```bash
$ ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
$ ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
OK
$ cat bench.txt
[bench] disorder:  48.52%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  4943
[bench] sa:  0  sb:  0  ss:  0  pa:  500  pb:  500
[bench] ra:  1566  rb:  1219  rr:  0  rra:  0  rrb:  1158  rrr:  0
```

In adaptive mode the reported complexity is the one of the method chosen internally.

### 4. Testing

```bash
# correctness with the official checker
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

# number of operations
./push_swap $ARG | wc -l

# memory (Valgrind, or AddressSanitizer where Valgrind is not available)
valgrind --leak-check=full ./push_swap 9 -2 15 0 4
cc -g -fsanitize=address -I. -Ift_printf *.c ft_printf/*.c -o ps_asan && ./ps_asan 1 2 2
```

---

## 🧠 Algorithms

All strategies work on the normalized `index` of each node (`0` for the smallest value, `n-1` for the largest), computed once before sorting. This turns "is this value in range?" into a simple integer comparison and gives radix sort a dense range of small numbers.

Inputs of **≤ 5 elements** are always solved by `sort_small.c` (at most 2 moves for 3 numbers and 10 for 5 numbers, below the 3 / 12 limits), whatever strategy is selected.

### Disorder metric (`disorder.c`)

$$\text{disorder} = \frac{\#\{(i, j) : i < j,\ a_i > a_j\}}{n(n-1)/2}$$

It is `0` for a sorted stack and `1` for a reversed one, and it is computed **before any move**, as required.

### 1. Simple — $O(n^2)$ · `--simple` · `sort_simple.c`

**Minimum extraction (selection sort):** while A has more than 3 elements, bring its minimum to the top through the shortest path (`ra` or `rra`) and `pb` it. Sort the last 3 by hand and `pa` everything back.

* **Time:** each of the `n` extractions may rotate up to `n/2` positions, so $O(n^2)$ operations.
* **Space:** $O(1)$ extra; nodes are only relinked.
* **Why:** the most direct strategy to explain and verify; it serves as the baseline of the project.

### 2. Medium — $O(n\sqrt{n})$ · `--medium` · `sort_chunk.c`

**Chunk sort with a sliding window** of size `chunk ≈ 1.5·√n` (15 for 100 numbers, 33 for 500):

1. **A → B.** `i` counts the elements already in B. For the top of A:
   * `index ≤ i` → `pb` + `rb` (small values sink to the bottom of B);
   * `index ≤ i + chunk` → `pb` (stays near the top of B);
   * otherwise → `ra`.
   There are `i + chunk + 1` indices `≤ i + chunk` and only `i` of them are in B, so a candidate always exists and the loop always ends.
2. **B → A.** The maximum of B is always `size(B) - 1`. Bring it to the top through the shortest path (`rb`/`rrb`) and `pa`. A is rebuilt from the largest value down.

* **Time:** for each of the `n` pushes, A is scanned about `√n` positions on average, so $O(n\sqrt{n})$.
* **Space:** $O(1)$ extra.
* **Why:** B ends up "spindle-shaped" (large values near both ends), so phase 2 only needs short rotations. With the `1.5·√n` window it is the strategy with the lowest operation counts on random inputs.

### 3. Complex — $O(n \log n)$ · `--complex` · `sort_radix.c`

**Binary LSD radix sort** on the indices. For each bit `k`, from the least significant one to bit $\lceil \log_2 n \rceil - 1$:

1. Look at the top of A exactly `n` times: if bit `k` of its index is `0` → `pb`, else → `ra`.
2. `pa` until B is empty.

After each pass, elements with a `0` bit sit above those with a `1` bit, and the order of the previous pass is kept inside each group (the pass is **stable**). After the last bit, the stack is fully sorted.

* **Time:** $\lceil \log_2 n \rceil$ passes of at most `2n` operations, so $O(n \log n)$.
* **Space:** $O(1)$ extra.
* **Why:** it guarantees the $O(n \log n)$ bound. Its operation count does not depend on the order of the input (always **1084** for 100 numbers and **6784** for 500), and every step is easy to justify.

### 4. Low disorder — $O(n)$ for nearly sorted inputs · `sort_low.c`, `sort_low_utils.c`

Used only by the adaptive strategy. If most numbers are already in relative order, only the few that are out of place are moved.

1. **Keep:** compute the *Longest Increasing Subsequence* (LIS) of the indices. Those elements stay in A.
2. **Split:** one pass over A. Kept elements → `ra`. Any other element → `pb`, after rotating B so that it stays sorted in decreasing order. The pass stops after the last element that must move.
3. **Merge:** with A ascending and B descending, merge them in a single sweep: `rra` while the bottom of A is greater than the top of B, otherwise `pa`. Finally bring the minimum to the top.

* **Time:** `n` (split) + at most `k²/2` (keeping B sorted) + `n + k` (merge) operations, where `k` is the number of elements outside the LIS, so $O(n + k^2)$. With a low disorder `k` is small and the cost is **linear** in practice (≈ 1000–1500 operations for 500 nearly sorted numbers). It is $O(n)$ whenever $k \le \sqrt{n}$.
* **Space:** $O(n)$ extra, one buffer of `3n` integers for the LIS, freed before sorting continues.
* **Note:** the LIS is computed with an $O(n^2)$ comparison loop. That is CPU time, not stack operations, and takes under a millisecond for 500 numbers.

### 5. Adaptive — default · `--adaptive` · `sort.c`

`ft_choose` picks the method in one single place, so the sorting code and `--bench` always agree:

| Disorder | Method | Class |
| :--- | :--- | :--- |
| `< 0.2` | Low disorder (LIS + merge) | $O(n)$ |
| `0.2 ≤ d < 0.5` | Medium (chunks) | $O(n\sqrt{n})$ |
| `≥ 0.5` | Complex (radix) | $O(n \log n)$ |

**Threshold justification.** The values `0.2` and `0.5` are fixed by the subject, and our measurements are consistent with them:

* Below `0.2` few elements are out of place (`k` is small), so leaving the LIS untouched is far cheaper than moving every element. For 500 nearly sorted numbers it takes ~1000–1500 operations, against ~5000 for chunks and 6784 for radix.
* Between `0.2` and `0.5` the number of misplaced elements grows quickly and the $k^2$ term of the low method stops paying off. Chunk sort keeps a low and stable cost (≈ 3700–4400 operations for 500 numbers).
* From `0.5` (a random permutation has a disorder of ≈ 0.5) the input carries no useful order, and radix sort offers the guaranteed $O(n \log n)$ bound with a fixed, input-independent cost.

### Measured results (100 runs each, verified with `checker_linux`)

| Strategy | 100 numbers (min / avg / max) | 500 numbers (min / avg / max) |
| :--- | :--- | :--- |
| Adaptive (default) | 535 / 812 / 1084 | 4897 / 5973 / 6784 |
| Medium | 533 / 577 / 621 | 4916 / 5073 / 5269 |
| Complex | 1084 / 1084 / 1084 | 6784 / 6784 / 6784 |
| Simple | 1261 / 1447 / 1660 | 29581 / 32169 / 34165 |

The default mode stays below the pass limits of the subject (**2000** for 100 numbers and **12000** for 500 numbers). The Simple strategy is $O(n^2)$ by design and is not meant to reach them on 500 numbers.

---

## 🧱 Architecture & Data Flow

The program keeps both stacks, the operation counters and the strategy settings in a single `t_data` structure (no global variables):

```
                         ┌─────────────────────────────┐
                         │         main & parser       │
                         │ (flags, validation, build A)│
                         └──────────────┬──────────────┘
                                        ▼
                         ┌─────────────────────────────┐
                         │     disorder & indexing     │
                         │ (ft_compute_disorder,       │
                         │  ft_assign_index)           │
                         └──────────────┬──────────────┘
                                        ▼
                         ┌─────────────────────────────┐
                         │  ft_choose → ft_sort        │
                         │  (≤ 5 elements: sort_small) │
                         └──────────────┬──────────────┘
          ┌──────────────────┬──────────┴───────┬──────────────────┐
          ▼                  ▼                  ▼                  ▼
  ┌───────────────┐  ┌───────────────┐  ┌───────────────┐  ┌───────────────┐
  │    Simple     │  │ Low disorder  │  │    Medium     │  │    Complex    │
  │    O(n²)      │  │ O(n) (LIS)    │  │  O(n√n)       │  │  O(n log n)   │
  └───────────────┘  └───────────────┘  └───────────────┘  └───────────────┘
                                        │
                                        ▼
                         ┌─────────────────────────────┐
                         │ --bench report (stderr)     │
                         │ free both stacks            │
                         └─────────────────────────────┘
```

### Memory & Leak Prevention

| Module / Function | Allocation | Freed by | Description |
| :--- | :--- | :--- | :--- |
| `ft_new_node` | `malloc(sizeof(t_stack))` | `ft_free_stack` | One node per number while building stack A. |
| `ft_sort_low` | `malloc(3n * sizeof(int))` | `free` in the same function | LIS buffer. If it fails, the medium strategy is used instead. |
| `ft_error` | — | — | Frees A and B, prints `Error\n` to `stderr` and exits with status `1`. |
| `main` | — | — | Frees A and B before returning `0`. |

---

## 📁 Project Structure

| File | Description |
| :--- | :--- |
| `main.c` | Entry point: initializes `t_data`, parses arguments/flags, sorts, prints the benchmark and frees memory. |
| `push_swap.h` | `t_stack`, `t_data`, `t_op`, `t_strategy` definitions and prototypes. |
| `parser_arg.c` | Strict numeric validation and `long` conversion to detect integer overflow. |
| `flags.c` | Strategy flags (`--simple`, `--medium`, `--complex`, `--adaptive`) and `--bench`. |
| `disorder.c` | Disorder ratio (inverted pairs / total pairs). |
| `index.c` | Normalized indices (`0` to `n - 1`). |
| `stack_utils.c` | Node creation, append, duplicate check, sorted check and memory cleanup. |
| `stack_info.c` | Stack size, minimum position and shortest-path rotation to the top of A or B. |
| `sort.c` | Method selection (`ft_choose`) and dispatch (`ft_sort`). |
| `sort_small.c` | Hard-coded sorting for 2–5 elements. |
| `sort_simple.c` | Simple strategy: minimum extraction, $O(n^2)$. |
| `sort_chunk.c` | Medium strategy: sliding-window chunk sort, $O(n\sqrt{n})$. |
| `sort_radix.c` | Complex strategy: binary LSD radix sort, $O(n \log n)$. |
| `sort_low.c` / `sort_low_utils.c` | Low-disorder method: LIS, split into a sorted B, single-sweep merge. |
| `bench.c` / `bench_utils.c` | `--bench` report written to `stderr`. |
| `swap.c` / `push.c` | `sa`, `sb`, `ss`, `pa`, `pb`. |
| `rotate.c` / `rrotate.c` | `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`. |
| `ft_printf/` | Custom `ft_printf` library, compiled automatically by the `Makefile`. |

---

## 👥 Contributions

| Member | Contribution |
| :--- | :--- |
| **jjurado** | Repository and `ft_printf` setup; argument parser (string to integer conversion); the 11 stack instructions (`swap.c`, `push.c`, `rotate.c`, `rrotate.c`); first sorter for 3 and 5 elements; original README and its layout. |
| **mavidal-** | `Makefile`; `t_data` context, stack construction, index normalization and operation counters; flag parsing; disorder metric; reorganization of the small sorter into `sort_small.c`; Simple strategy. |
| **jjurado & mavidal-** | Medium, Complex, Low-disorder and Adaptive strategies; `--bench` mode; testing (checker, Norm, memory). |

---

## 🤝 Resources

### 📚 References
* **Donald E. Knuth**, *The Art of Computer Programming, Vol. 3: Sorting and Searching* — sorting algorithms, radix sort and inversions (the basis of the disorder metric).
* **Cormen, Leiserson, Rivest, Stein**, *Introduction to Algorithms* (CLRS) — asymptotic notation (Big-O), radix sort, merge procedure and the longest increasing subsequence via dynamic programming.
* [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — complexity classes of common algorithms.
* [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — LSD radix sort and why it is stable.
* [Longest increasing subsequence — Wikipedia](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) — the $O(n^2)$ and $O(n \log n)$ algorithms.

### 🛠️ Tools
* **[Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)** — visual debugging tool to inspect stack movements in real time.
* **`checker_linux`** — official checker from the subject, used to validate every strategy.
* **Valgrind / AddressSanitizer** and **norminette** — memory and Norm verification.

### 🤖 Use of AI
* **Gemini (Google)** — used to understand pointer handling in doubly linked lists, sorting strategies, and for the first version of this README.
* **Claude (Anthropic), through Claude Code** — used as a guided assistant, with step-by-step explanations of every change, for:
  * implementing the Medium (chunks), Complex (radix), Low-disorder (LIS + merge) and Adaptive strategies, and the `--bench` mode;
  * checking memory with AddressSanitizer;
  * writing a test script (error cases, all permutations of 2–5 numbers, 100 random runs per strategy with `checker_linux`) and measuring the operation counts above;
  * updating this README (algorithm explanations and justification).

  Each AI-assisted change was explained, reviewed and tested by the team before being committed.
