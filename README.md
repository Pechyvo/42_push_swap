# Push Swap

Push Swap is a 42 algorithm project that sorts a stack of integers using a
second auxiliary stack and a restricted set of operations. The program prints
the operation sequence to standard output; its goal is to produce a correct
sort using as few operations as practical.

## Usage

Build the executable:

```sh
make
```

Run it with integers supplied as separate arguments:

```sh
./push_swap 4 67 3 87 23
```

To verify the result with the official checker, when available:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

A valid sequence produces `OK`. The program produces no output when the input
is already sorted or when no values are provided.

## Input rules

Each argument must be:

- A valid decimal integer within the `int` range
- Unique within the input
- Written without unsupported characters or malformed signs

Invalid input writes `Error` followed by a newline to standard error and exits
with a non-zero status.

This implementation expects numbers as separate command-line arguments. A
single quoted argument containing several space-separated numbers is not
supported.

## Available operations

| Operation | Effect |
| --- | --- |
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Move the first element of stack B to stack A |
| `pb` | Move the first element of stack A to stack B |
| `ra` | Rotate stack A upward |
| `rb` | Rotate stack B upward |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse-rotate stack A |
| `rrb` | Reverse-rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Algorithm

The implementation assigns each value a sorted index and selects a strategy
based on input size:

- Inputs of two to five values use dedicated small-sort routines.
- Larger inputs are recursively partitioned from stack A into stack B until a
  small sorted base remains.
- Each value in stack B is assigned a target position in stack A.
- Rotation costs are calculated for both stacks, allowing compatible rotations
  to be combined with `rr` or `rrr`.
- The cheapest candidate is moved back to stack A until sorting is complete.

## Project structure

```text
.
├── incl/
│   └── push_swap.h        # stack type and function declarations
├── srcs/                  # parsing, operations, costs, and sorting logic
├── libft/                 # bundled support library
├── Makefile
└── en.subject_push_swap.pdf
```

## Makefile targets

```sh
make          # build push_swap and the bundled Libft
make clean    # remove object files
make fclean   # remove object files and executables/libraries
make re       # rebuild everything
```

The project is compiled with `-Wall -Wextra -Werror`.

## Testing

Generate shuffled input and count the emitted operations:

```sh
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l
```

If the official checker is available, validate the same sequence with:

```sh
./push_swap $ARG | ./checker_linux $ARG
```

## Project subject

The complete assignment is available in
[en.subject_push_swap.pdf](./en.subject_push_swap.pdf).
