# Push_swap — Subject Reference

> Clean Markdown transcription of `en.subject.pdf`, **Push_swap**, version 1.1.
>
> Canonical source: `en.subject.pdf`  
> SHA-256: `ab88b4223a19188c929474fd2621b1d9e61d860376e9be59dd62ddc1670927ee`
>
> This file exists so agents and learners can consult the subject without repeatedly
> extracting the PDF. If this transcription and the PDF disagree, the PDF wins.

## Contents

1. Foreword
2. Common Instructions
3. AI Instructions
4. Introduction
5. Objectives
6. Mandatory Part
7. README Requirements
8. Bonus Part
9. Submission and Peer Evaluation

## I. Foreword

The project introduces Big-O notation through a concrete constraint: sort with two
stacks while keeping the number of generated operations low. An algorithm that is
efficient for ordinary in-memory sorting may not have the same complexity when its
cost is measured in Push_swap operations. The goal is to sort smartly rather than
emit long, repetitive sequences of moves.

## II. Common Instructions

- The project must be written in C and comply with the 42 Norm.
- Norm errors in mandatory or bonus files result in a grade of zero.
- Functions must not quit unexpectedly through segmentation faults, bus errors,
  double frees, or similar failures, except for undefined behavior.
- Heap allocations must be freed when necessary. Memory leaks are not tolerated.
- The required Makefile must compile with `cc -Wall -Wextra -Werror` and must not
  perform unnecessary relinking.
- The Makefile must provide at least `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- If a bonus is submitted, the Makefile must provide a `bonus` rule. Unless the
  subject says otherwise, bonus files use `_bonus.c` and `_bonus.h` suffixes.
- If libft is used, copy its sources and Makefile into a `libft/` directory. The
  project Makefile must build libft through its own Makefile before building the
  project.
- Test programs are encouraged but are not graded or required for submission.
- Only work in the assigned Git repository is graded. Deepthought stops evaluation
  when an error is encountered.

## III. AI Instructions

### Context and main message

AI may help with many tasks, but generated explanations, documentation, ideas, and
code must be reviewed critically. AI should reduce repetitive work and help develop
prompting, technical, and collaboration skills—not replace understanding or peers.

Only use AI-generated content that you fully understand and can take responsibility
for.

### Learner rules

- Explore AI tools and use them ethically while considering errors and bias.
- Think about the problem before prompting and use accurate vocabulary.
- Systematically check, question, review, and test generated work.
- Seek peer review rather than relying only on personal or AI validation.

### Intended outcomes

- Develop general and domain-specific prompting skills.
- Improve productivity through effective AI use.
- Strengthen computational thinking, problem-solving, adaptability, and
  collaboration.
- Be ready to explain the work without AI during exams and evaluations.

Good practice is to use AI for testing ideas or parser design, attempt and verify the
work, and review it with a peer. Copying an entire generated function without being
able to explain its behavior is explicitly bad practice.

## IV. Introduction

The project supplies integer values, two stacks, and a limited operation language.
Write a program named `push_swap` that prints a program made from those operations
which sorts the received integers. The requested sequence should be as small as
possible.

## V. Objectives

The objective is to discover algorithmic complexity in a concrete way. Sorting a
random list and an almost-sorted list are different problems, and the chosen strategy
can greatly change the generated operation count.

## VI. Mandatory Part

### VI.1 Group project requirements

- The project must be completed by **exactly two learners**.
- Both learners must contribute meaningfully and understand every implemented
  algorithm.
- `README.md` must clearly identify both learners' contributions.
- Both learners must be present at the defense and able to explain any part of the
  code.
- Both learners' logins must appear in the repository submission.

### VI.2 Stack model and operations

There are two stacks, `a` and `b`. Initially, `a` contains unique positive and/or
negative integers, and `b` is empty. The goal is ascending order in `a`, with the
smallest number at the top. The first program argument is the top of `a`.

| Operation | Required behavior |
| --- | --- |
| `sa` | Swap the first two elements of `a`; do nothing with fewer than two. |
| `sb` | Swap the first two elements of `b`; do nothing with fewer than two. |
| `ss` | Perform `sa` and `sb` at the same time. |
| `pa` | Move the top of `b` to the top of `a`; do nothing if `b` is empty. |
| `pb` | Move the top of `a` to the top of `b`; do nothing if `a` is empty. |
| `ra` | Rotate `a` upward: the first element becomes the last. |
| `rb` | Rotate `b` upward: the first element becomes the last. |
| `rr` | Perform `ra` and `rb` at the same time. |
| `rra` | Reverse-rotate `a`: the last element becomes the first. |
| `rrb` | Reverse-rotate `b`: the last element becomes the first. |
| `rrr` | Perform `rra` and `rrb` at the same time. |

### VI.3 Algorithm requirements

Four distinct strategies must be implemented in the `push_swap` binary and must be
selectable at runtime according to the input configuration.

#### VI.3.1 Complexity model

Each strategy analyzes the input and generates operations from the Push_swap
language. A claimed complexity class describes the **number of generated Push_swap
operations**, not the ordinary loop or array complexity of the C implementation.

#### VI.3.2 Mandatory disorder metric

`disorder` is between 0 and 1. It is the fraction of pairs that are inversions:

```text
function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a) - 1:
        for j from i + 1 to size(a) - 1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs
```

Already-sorted input has disorder 0; worst-order input has disorder 1. Disorder must
be measured **before any move**.

#### VI.3.3 Required strategies

1. **Simple — O(n²):** at least one baseline strategy. Examples include insertion,
   selection, bubble, or simple min/max extraction adaptations.
2. **Medium — O(n√n):** examples include √n chunks, block partitioning, √n buckets,
   or range-based strategies.
3. **Complex — O(n log n):** examples include radix, two-stack merge, quick-sort
   partitioning, heap-sort adaptation, or binary-indexed-tree approaches.
4. **Custom adaptive strategy:** selects internal methods from the initial disorder:
   - Low: `disorder < 0.2` must use an O(n²) method.
   - Medium: `0.2 <= disorder < 0.5` must use an O(n√n) method.
   - High: `disorder >= 0.5` must use an O(n log n) method.

The repository documentation must justify the adaptive thresholds and internal
techniques and give short time and space upper-bound arguments in the Push_swap
operation model.

### VI.4 Worked operation example

For the input `2 1 3 6 5 8`, the subject demonstrates this 12-operation sequence:

```text
sa
pb
pb
pb
ra
rb
rra
rrb
sa
pa
pa
pa
```

It illustrates that `ra` + `rb` is equivalent to `rr`, and `rra` + `rrb` is
equivalent to `rrr`. The example asks whether the list can be sorted in fewer moves.

### VI.5 The `push_swap` program

| Field | Requirement |
| --- | --- |
| Program | `push_swap` |
| Files | `Makefile`, `*.h`, `*.c` |
| Makefile rules | `NAME`, `all`, `clean`, `fclean`, `re` |
| Arguments | Stack `a`, plus optional strategy/benchmark selectors |
| Allowed functions | `read`, `write`, `malloc`, `free`, `exit`, and a learner-written `ft_printf` equivalent |
| Libft | Authorized |
| Description | Sort stacks |

Program rules:

- Global variables are forbidden.
- The first integer argument is the top of stack `a`.
- Strategy selectors are:
  - `--simple` forces O(n²).
  - `--medium` forces O(n√n).
  - `--complex` forces O(n log n).
  - `--adaptive` uses the disorder-based adaptive algorithm.
- Adaptive is the default when no strategy selector is supplied.
- Every valid strategy selector must work for every valid input size and disorder.
- Print one operation per line on standard output, with no other stdout content.
- With no parameters, print nothing and return control to the prompt.
- On invalid input, print exactly `Error\n` to standard error. Invalid inputs include
  non-integers, values outside the `int` range, and duplicates.
- The binary must embed all four strategies.
- The selected strategy's name and complexity must be available in benchmark mode.

#### Benchmark mode

When `--bench` is present, print benchmark information to **standard error after
sorting**, while keeping the operation stream alone on stdout. Report:

- Initial disorder as a percentage with two decimal places.
- Strategy name and theoretical complexity.
- Total generated operation count.
- Individual counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`,
  `rrb`, and `rrr`.

Benchmark text must appear only when `--bench` is supplied.

#### VI.5.1 Usage examples

Basic operation stream:

```sh
./push_swap 2 1 3 6 5 8
```

The subject's example prints:

```text
ra
pb
rra
pb
pb
ra
pb
ra
pb
pb
pa
pa
pa
pa
pa
pa
```

Select strategies and verify output:

```sh
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | wc -l       # subject example: 13
./push_swap --simple 5 4 3 2 1
./push_swap --complex $ARG | ./checker_linux $ARG
```

The subject's `--simple 5 4 3 2 1` example is:

```text
rra
pb
rra
pb
rra
pb
ra
pb
pb
pa
pa
pa
pa
pa
```

Large input example:

```sh
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
# subject example: 6784
```

Hide operations, check them, and retain benchmark output:

```sh
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt \
    | ./checker_linux $(cat args.txt)
cat bench.txt
```

The screenshot illustrates benchmark output in this form:

```text
[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

Combined adaptive and benchmark example:

```sh
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2> bench.txt \
    | ./checker_linux $ARG
cat bench.txt
```

The subject screenshot shows:

```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

Error examples:

```sh
./push_swap --adaptive 0 one 2 3    # Error on stderr
./push_swap --simple 3 2 3          # Error on stderr
```

### VI.6 Performance benchmark

Random-input operation targets:

| Input size | Pass | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 | fewer than 2000 | fewer than 1500 | fewer than 700 |
| 500 | fewer than 12000 | fewer than 8000 | fewer than 5500 |

The supplied checker is used during evaluation.

## VII. README Requirements

A root `README.md` is mandatory. Its first line must be italicized and read:

```text
This project has been created as part of the 42 curriculum by <login1>[, <login2>[, ...]].
```

It must contain:

- A **Description** section with the goal and brief overview.
- An **Instructions** section for compilation, installation, and/or execution.
- A **Resources** section listing classic references and describing exactly how AI
  was used and for which tasks or project parts.
- A detailed explanation and justification of every selected algorithm.
- Both learners' contributions, as required by the group-project rules.

English is recommended; the campus's main language is also allowed.

## VIII. Bonus Part

The bonus is evaluated only when the mandatory part is perfect, including all
mandatory benchmarks.

### VIII.1 The `checker` program

| Field | Requirement |
| --- | --- |
| Program | `checker` |
| Files | `*.h`, `*.c` |
| Makefile rule | `bonus` |
| Arguments | Stack `a` |
| Allowed functions | `read`, `write`, `malloc`, `free`, `exit`, and a learner-written `ft_printf` equivalent |
| Libft | Authorized |

- With no arguments, stop and print nothing.
- Read newline-terminated operations from standard input and execute them.
- Print `OK\n` on stdout only if `a` is sorted and `b` is empty after all input.
- Otherwise print `KO\n` on stdout.
- Print `Error\n` on stderr for invalid integers, overflow, duplicates, invalid or
  incorrectly formatted instructions, and other parsing errors.
- Exact behavior need not reproduce the supplied binary; error handling is mandatory,
  while the learner may choose the parsing design.

Subject examples:

```text
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

$> ./checker 3 2 1 0
sa
rra
pb
KO

$> ./checker 3 2 one 0
Error

$> ./checker "" 1
Error
```

## IX. Submission and Peer Evaluation

- Submit through the assigned Git repository; only repository contents are graded.
- Verify all filenames before submission.
- Both learners must be listed as contributors and have their contributions documented.
- Both must attend the defense and explain any part of the implementation.
- The evaluator may request a small behavior change, rewrite, or easy feature during
  the defense. Each learner must understand the project well enough to perform it
  within the stated time.
