*This project has been created as part of the 42 curriculum by bchagas-.*

# push_swap

## Description

The **push_swap** project consists of sorting a stack of integers using a limited set of operations and the smallest possible number of moves possible.  
The program must output a sequence of instructions that sorts stack **A** in ascending order, using an auxiliary stack **B**, while respecting strict operational constraints.

This project focuses on:
- Algorithmic problem-solving
- Optimization and efficiency
- Data structure manipulation
- Robust input validation
- Memory-safe C programming

---

## Instructions

### Compilation

To compile the program:

```bash
make
```
This will generate the executable:

```bash
./push_swap
```
Usage
```bash
./push_swap <list_of_integers>
```
Example:

```bash
./push_swap 3 2 1
```
The program prints a list of instructions to standard output that, when executed, sort stack A.

If no arguments are provided, the program exits silently.

Features
Full input validation:

Non-numeric arguments

Integer overflow / underflow

Duplicate values

Optimized handling for small stack sizes

Scalable algorithm for larger inputs

Deterministic output based on input

Clean memory management with no leaks

Technical Choices
Data Structure: Doubly linked lists for efficient rotations and stack operations

Sorting Strategy:

Specialized logic for very small stacks

Partitioning strategy for larger stacks

Error Handling:

Immediate termination on invalid input

Proper memory cleanup before exit

Performance:

Optimized to reduce unnecessary operations


### Resources
Classic References
42 Project Subject: push_swap

Sorting algorithms:

Selection sort

Insertion logic

Median-based partitioning

Data structures:

Linked lists

Linux manual pages:

man malloc

man free

man write

man exit

Valgrind documentation

Use of AI Tools
AI tools were used as a support resource, not as a substitute for understanding or responsibility.

AI was used to:

Help design and expand test cases

Assist in reasoning about algorithmic behavior

Review code organization and readability

Suggest possible refactoring strategies

All AI-generated content was:

Carefully reviewed and tested

Fully understood before being applied

Example Test
```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG
The output sequence correctly sorts stack A.
```
