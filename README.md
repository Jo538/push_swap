# push_swap

A 42 School project that sorts a stack of integers using a limited set of operations, optimizing for the fewest moves possible.

## The problem

You are given two stacks, `a` and `b`. Stack `a` starts loaded with `n` distinct integers (passed as program arguments). Stack `b` starts empty. The goal is to end with stack `a` sorted in ascending order, using only the operations below.

| Op  | Effect                                              |
| --- | --------------------------------------------------- |
| `sa` | Swap the top two elements of `a`                   |
| `sb` | Swap the top two elements of `b`                   |
| `ss` | `sa` and `sb` at the same time                     |
| `pa` | Push the top of `b` onto `a`                       |
| `pb` | Push the top of `a` onto `b`                       |
| `ra` | Rotate `a` upward (top goes to the bottom)         |
| `rb` | Rotate `b` upward                                  |
| `rr` | `ra` and `rb` at the same time                     |
| `rra`| Reverse rotate `a` (bottom goes to the top)        |
| `rrb`| Reverse rotate `b`                                 |
| `rrr`| `rra` and `rrb` at the same time                   |

The program prints the sequence of operations to stdout — one per line — and that sequence, when applied to the input, must yield a sorted stack.

## Build

```sh
make        # builds the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # rebuild from scratch
```

The Makefile compiles with `-Wall -Wextra -Werror` plus AddressSanitizer enabled (`-fsanitize=address`) for development.

## Usage

```sh
./push_swap 4 67 3 87 23
```

Arguments may also be passed as a single quoted string:

```sh
./push_swap "4 67 3 87 23"
```

Invalid input (non-numeric tokens, duplicates, values outside `int` range) causes the program to print `Error` to stderr and exit.

## Algorithm — "Turk sort"

The sort (named `turk_sort` in [main.c](main.c)) is a greedy cost-minimization strategy:

1. **Small cases** (≤ 4 elements) are handled directly by `handle_small_cases` / `sort_three`.
2. **Seed**: push the first two elements of `a` onto `b`.
3. **Push phase**: while `a` has more than 3 elements, for every element in `a`:
   - compute its target position in `b` (the closest smaller value, wrapping around),
   - compute the total cost (rotations on `a` + rotations on `b`, including the cheaper `rr`/`rrr` combos when both rotate in the same direction),
   - pick the cheapest element, move it to the top of both stacks using the fewest ops, then `pb`.
4. **Sort the remaining three** elements in `a`.
5. **Reinsert phase**: push everything back from `b` to `a`, each time targeting the cheapest position in `a`.
6. **Final rotation**: rotate `a` so the minimum is on top.

## Project layout

```
.
├── main.c            # entry point + turk_sort driver
├── push_swap.h       # types (t_list, t_stack, t_pair) and prototypes
├── Makefile
├── parser/           # argument parsing + libft-style helpers
│   ├── ft_split.c
│   ├── ft_strjoin.c
│   └── utils.c
├── operations/       # the 11 stack operations
│   ├── push.c
│   ├── rotate.c
│   ├── rrotate.c
│   └── swap.c
└── algo/             # turk_sort implementation
    ├── find_pair1.c
    ├── find_pair2.c
    ├── move_up1.c
    ├── move_up2.c
    └── small_sort.c
```

## Verifying output

Pipe the operations into the 42-provided `checker` binary (not part of this repo):

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

`checker` prints `OK` if the operations sort the stack, `KO` otherwise.
