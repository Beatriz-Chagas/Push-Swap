*This project has been created as part of the 42 curriculum by bchagas-.*

# Push_swap

## Description

**Push_swap** is a sorting algorithm project developed as part of the 42 School curriculum.  
The goal is to sort a stack of integers using a limited set of operations and **produce the smallest possible number of instructions**.

The project focuses on:
- Algorithmic thinking
- Data structures (stacks)
- Optimization
- Memory management
- Parsing and error handling

The program receives a list of integers as arguments, representing stack **A**, and outputs a sequence of instructions that will sort the stack in ascending order using only the allowed operations.
The sorting strategy is based on a cost-based heuristic commonly used in the 42 community, often referred to as the “Turk algorithm”.
It combines insertion logic, rotation cost calculation, and greedy selection to minimize the total number of operations.

An additional program, **checker**, is provided to validate whether a sequence of instructions correctly sorts the stack.

---

## Instructions

### Compilation

To compile the main program:

```bash
make
```
This will generate the executable:

```bash
./push_swap
```
To compile the checker program:

```bash
make bonus
```
This will generate:

```bash
./checker
```
### Usage
**push_swap**
```bash
./push_swap <list_of_integers>
```
Example:

```bash
./push_swap 3 2 1
```
Output:

sa
rra
Each instruction is printed on a new line and represents an operation applied to the stacks.

If no arguments are provided, the program prints nothing.

In case of invalid input (non-integer values, duplicates, overflow), the program prints:

Error
to standard error.

**checker**
The checker program verifies whether a sequence of instructions correctly sorts stack A.

```bash
./checker <list_of_integers>
```
The checker reads instructions from standard input, one per line.

**Using the keyboard (interactive mode)**
```bash
./checker 3 2 1
```
Then type the instructions manually, pressing Enter after each instruction:

sa
rra
To finish input, press:

- Ctrl + D (Linux / macOS)

The checker will then output:

- `OK` if stack A is sorted and stack B is empty

- `KO` otherwise

**Using pipes**
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```
**Error handling**
If an invalid instruction is detected, the checker prints:

Error
to standard error.

Examples of errors:

- Invalid instruction (`foo`)

- Duplicate numbers

- Integer overflow

- Non-numeric arguments

**Allowed Operations**
- `sa`, `sb`, `ss`

- `pa`, `pb`

- `ra`, `rb`, `rr`

- `rra`, `rrb`, `rrr`

Each operation must be followed by a newline.

## Resources
**Algorithm & Computer Science**
- Stack-based sorting algorithms

- Selection sort, insertion logic

- Cost-based rotation strategies

**Documentation**
- GNU C Library Documentation

- Valgrind User Manual

- Linux man pages (`read`, `write`, `malloc`,`free`)

**AI Usage Disclosure**
AI tools were used ethically and critically during this project for:

- Explaining algorithmic concepts

- Reviewing logic and edge cases

- Generating test ideas

- Improving documentation clarity

**All AI-generated suggestions were:**

- Fully reviewed

- Tested

- Understood

- Adapted manually

No code was blindly copied.
Final implementations and design decisions were made by the author.

### Notes
This project was developed following:

42 Norminette rules

No global variables

No memory leaks (validated with Valgrind)

Strict error handling

flowchart TD
    A[Start] --> B[Parse arguments]
    B --> C{Error}
    C -- Yes --> D[Print Error and exit]
    C -- No --> E{Stack size <= 3}

    E -- Yes --> F[Sort directly]
    F --> Z[End]

    E -- No --> G{Stack size <= 5}
    G -- Yes --> H[Push minimum elements to B]
    H --> I[Sort remaining three in A]
    I --> J[Reinsert from B to A]
    J --> Z

    G -- No --> K[Compute median]
    K --> L[Push elements smaller than median to B]
    L --> M[Sort remaining three in A]

    M --> N{Is B empty}
    N -- No --> O[Find insertion position in A]
    O --> P[Calculate rotation cost]
    P --> Q[Select cheapest element]
    Q --> R[Apply rotations]
    R --> S[Push from B to A]
    S --> N

    N -- Yes --> T[Rotate A until minimum is on top]
    T --> Z

The project emphasizes understanding, optimization, and robustness over brute force solutions.