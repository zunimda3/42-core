# Push_swap Build Sequence

## Use

Silent implementation-navigation reference. Keep it aligned with `SUBJECT.md`,
confirmed decisions in `ROADMAP.md`, and fresh code/test evidence. It does not prove
completion and must not decide unresolved choices for the learners.

## Confirmed decisions

- Specialized singly linked `t_node` stores `value`, `rank`, and `next`.
- `t_stack.top` is the stack top; `t_stack.size` is authoritative.
- Nodes belong to exactly one stack and are freed once. Pushes transfer ownership.
- Retain only helpers required by the specialized stack abstraction.
- Flags precede integers. One selector may combine with `--bench`; repeats,
  conflicts, unknown flags, and flags after integers are invalid.
- Adaptive is the default strategy.
- `main` owns one initialized context, error output, and final cleanup.
- Parser returns status without printing; partial nodes remain owned by stack `a`.
- Build `a` left-to-right using a parser-local non-owning tail so argv order remains
  stack order in O(n) ordinary C work.
- Strategy is stored as an adaptive-default enum.
- Metrics layout, operation emission policy, rank method, and algorithms are open.

## Active cursor

### Slice 1: stabilize the existing stack foundation

Fresh strict-compilation evidence from 2026-09-04:

```text
ft_lstiter.c:21:22: error: t_node has no member named content
```

`ft_lstiter.c` is a leftover generic-list helper that conflicts with the specialized
node and is absent from the current header interface. Reconcile it only with explicit
learner authorization. Then compile and test `ft_lstnew`, `ft_lstadd_top`, and
`ft_lstclear` on empty, one-node, and multi-node stacks, including sanitizer checks.

Do not introduce context, parsing, metrics, or strategies before this foundation is
compiled, tested, and interpreted.

## Ordered slices

### 1. Stack foundation

Verify allocation, top insertion, authoritative size, link order, and cleanup back to
`top == NULL`, `size == 0`. Remove or adapt obsolete generic helpers only after the
learner decides they have a real role.

### 2. Minimal build shell

Add the smallest project header boundary, `main`, and Makefile. First gate: strict
build, required rules, no arguments produce nothing, and repeated `make` does not
relink. Decide umbrella versus narrow headers and object-directory layout only when
the build needs the choice.

### 3. Context initialization/lifetime

Introduce the confirmed caller-owned context incrementally. Initialize both stacks
empty, strategy adaptive, benchmark disabled, and all report state zero before any
fallible work. Keep cleanup safe before parsing, after partial parsing, and on success.
Defer the unresolved metrics representation until operations require it.

### 4. Integer conversion

Validate one token before allocation: optional sign, at least one digit, no trailing
characters, and range within signed `int`. Compare `long` accumulation with per-digit
overflow checks. Test zero, signs, `INT_MIN/MAX`, overflow, empty/sign-only strings,
spaces, and non-digit suffixes.

### 5. Numeric stack construction

Use the selected parser-local tail. The first node sets `a.top` and `tail`; later
nodes link through `tail->next`; advance the alias and increment size once per owned
node. Never free the alias separately.

Duplicate alternatives: traverse built nodes (simple O(n²), no extra allocation),
use a temporary array, or combine detection with ranking. Learners choose when this
dependency is reached. Test order preservation, size, duplicates, allocation failure,
and whole-partial-stack cleanup by `main`.

### 6. Flags and complete-input barrier

Implement the confirmed grammar and enum mapping. No sorting or stdout operation may
begin until every argument is valid. On failure, `main` writes exactly `Error\n` to
stderr and clears all owned nodes. Capture stdout and stderr separately.

### 7. Rank assignment

Compare: count-smaller O(n²) with no array; copy/sort/map O(n log n) with O(n) space;
or linked merge machinery with more pointer complexity. Ranking emits no Push_swap
operations. Gate: ranks are unique/contiguous and values/order remain unchanged.

### 8. Primitive mutations

Implement internal swap, push, rotate, and reverse-rotate without output first.
Combined commands apply primitives without recursively emitting two commands. Test
empty, one, two, and many nodes; exact links/sizes; pushes allocate/free nothing.

### 9. Operation emission and metrics

Compare named counters with an operation-enum-indexed array. Decide whether useless
commands are suppressed or printed/counted, including partial combined commands. Use
one dispatcher so each emitted command mutates state, writes exactly one mnemonic,
increments exactly one individual counter, and increments total. Maintain
`total == sum(individual) == stdout line count`.

### 10. Initial disorder and dispatch

Compute inversion fraction before the first move with wide pair counters; define
sizes below two as disorder zero. Save the initial value. Forced selectors work on
every valid input; adaptive boundaries are exactly `< 0.2`, `[0.2, 0.5)`, and
`>= 0.5`.

### 11. Small-input layer

Add sortedness and focused 0–5 element handling after operations pass. Exhaustively
test manageable permutations and require no output for already-sorted inputs.

### 12. Simple O(n^2)

Compare minimum extraction, insertion-style placement, and bubble-like adaptation.
Trace legal operations, derive a generated-operation bound, compare space and coding
risk, then let learners choose. A minimum-extraction baseline is easy to explain but
is not preselected.

### 13. Medium O(n sqrt(n))

Compare sqrt-width rank chunks, buckets, and block partition/recovery. Derive the
generated-operation bound rather than C loop complexity. Choose only after a trace.

### 14. Complex O(n log n)

Compare binary radix on ranks, bottom-up two-stack merge, and bounded partitioning.
Radix is generally easiest to prove; merge may reduce counts but increases pointer
and control-flow risk. Choose only after trace, operation bound, and threshold review.

### 15. Adaptive

Dispatch among the three implemented/understood complexity-class methods using saved
initial disorder. Resolve benchmark naming for adaptive plus its selected internal
method when reached.

### 16. Benchmark

After sorting, write only to stderr: initial disorder with two decimals, strategy and
class, total, and all 11 counts. Verify absence without `--bench`, clean stdout, and
counter equality. Use only allowed output facilities.

### 17. Integration and performance

Run forced/adaptive edge, patterned, reverse, sorted, and random cases; strict build,
Norm, sanitizer/Valgrind, stream separation, Makefile relink checks, and repeated
100/500 samples reporting worst, average, and failures. Optimize only measured causes.

### 18. README and defense

Document algorithms, generated-operation bounds, auxiliary space, resources, AI use,
and accurate work by exactly two learners. Keep bonus locked until every mandatory
gate passes and both learners can explain and modify the implementation.

## Deferred decisions

- Disposition of obsolete `ft_lstiter.c` (immediate).
- Header and Makefile layout.
- Duplicate-detection and rank-assignment methods.
- Metrics representation and no-op emission/counting policy.
- Simple, medium, and complex methods.
- Adaptive benchmark naming.
- Second learner and contribution split.
