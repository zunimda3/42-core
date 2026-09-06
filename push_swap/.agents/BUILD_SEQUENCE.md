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
- Prefix specialized stack helpers with `ps_` so their `t_node`/`t_stack` API can
  coexist with libft's generic `ft_lst*` symbols.
- Flags precede integers. One selector may combine with `--bench`; repeats,
  conflicts, unknown flags, and flags after integers are invalid.
- Adaptive is the default strategy.
- `main` owns one initialized context, error output, and final cleanup.
- Parser returns status without printing; partial nodes remain owned by stack `a`.
- Build `a` left-to-right using a parser-local non-owning tail so argv order remains
  stack order in O(n) ordinary C work.
- Strategy is stored as an adaptive-default enum.
- Flag phase: only exact `--bench`/`--simple`/`--medium`/`--complex`/`--adaptive`
  tokens are flags; the first non-exact token ends the phase, so later
  flag-looking strings are invalid integers. Bench and one selector are
  order-independent within the phase; repeats and conflicts are invalid. Flags
  with no following integers print nothing, like no parameters.
- Duplicates are rejected by walking the already-attached nodes of stack `a`
  before allocation: O(n²) worst-case comparisons, no extra allocation; array
  reuse is revisited only if rank assignment justifies one.
- Overflow-safe conversion is parked by learner choice; it remains a required
  parsing gate before milestone 2 can verify.
- Metrics layout, operation emission policy, rank method, and algorithms are open.

## Active cursor

### Slice 1: stabilize the existing stack foundation

The learner removed obsolete `ft_lstiter.c` on 2026-09-05. The retained helpers pass
strict syntax compilation and Norminette. Focused assertions pass normally and under
AddressSanitizer/UndefinedBehaviorSanitizer with leak detection disabled;
LeakSanitizer itself is unavailable under the environment's active tracing.

The learner interpreted the evidence correctly: reset invariants do not alone prove
that nodes were freed, and LeakSanitizer remains a missing dynamic check. Proceed to
Slice 2 while retaining that limitation for later memory verification.

### Active cursor: Slice 2 — minimal build shell

Have the learner add only a no-output `main` and the required Makefile surface. Gate
this slice on strict compilation, correct required rules, no-argument silence, and a
second `make` performing no relink. Do not introduce context or parsing yet.

First attempt evidence: `make` cannot find target `push_swap` because `$NAME` is not
the Make variable reference `$(NAME)`; `main.c` is absent from `SRCS`; the target
recipe uses the archiver instead of the compiler/linker; and strict compilation flags
both unused `main` parameters. Have the learner correct these before retesting.

The learner corrected the Makefile target, source list, and linker recipe. The only
remaining build failure is the unused `argc`/`argv` pair in the temporary `main`.

The learner changed the temporary entry point to `main(void)`. Fresh build evidence
passes strict compilation, no-argument stream capture, no-relink behavior, `clean`,
`fclean`, `re`, and Norminette. The learner interpreted the unchanged binary timestamp
as evidence that the second successful `make` did not rewrite the target.

### Active cursor: Slice 3 — context initialization/lifetime

Introduce only the confirmed context fields needed before parsing: two empty stacks,
adaptive-default strategy, benchmark disabled, and initial disorder zero. Defer the
metrics layout. Resolve the header boundary now that the context depends on stack
types, then test initialization and cleanup safety before and after partial ownership.

Confirmed revised header boundary: use one project-wide `push_swap.h` containing
node, stack, strategy, context, and all project prototypes. All sources include it;
`node.h` is intentionally removed. The learner accepts the broader rebuild dependency
in exchange for a centralized interface.

Implementation evidence: initialization, cleanup, strict build, Norm, focused field
assertions, and ASan/UBSan pass with leak detection disabled. The Makefile still
depends on deleted `node.h`; make therefore selected its built-in compile rule, and
`main.o` currently lists only `main.c` as a prerequisite. Replace that dependency
with `push_swap.h` and retest before closing the slice.

The dependency is corrected. Fresh/repeated builds pass, the dependency database
lists `push_swap.h` for relevant objects, and a temporary-copy timestamp probe rebuilds
all objects and relinks after the umbrella changes. The learner explained both
timestamp comparisons. Slice 3 is complete; proceed to Slice 4.

### Active cursor: Slice 4 — integer conversion

Validate and convert one token before allocation. Compare wide accumulation with
explicit guarding against arbitrarily long input versus per-digit checking against
the signed-int limit. Gate on signs, zero, `INT_MIN/MAX`, immediate overflow,
arbitrarily long digit strings, empty/sign-only input, whitespace, and suffixes.

The learner copied libft into the project and renamed the specialized helper
declarations, definitions, filenames, and `main` calls with a `ps_` prefix. The root
Makefile creates `libft/libft.a` through its sub-Makefile, preserves its timestamp on
a repeated isolated invocation, and links it after the project objects in a strict
successful build. Cleanup forwarding remains unfinished. The focused 12-case
`is_valid_int` syntax suite now passes ordinary signed digits, empty, sign-only,
whitespace, suffix, and repeated-sign cases; strict build and Norm also pass. Add
overflow-safe conversion and exact signed-int boundary tests next.

The learner explicitly chose a build-first detour on 2026-09-05: construct stack `a`
for ordinary unique in-range numeric argv before hardening overflow and other edge
cases. Restore the current header/definition mismatch for `is_valid_int`, then move
temporarily to Slice 5 with no flags and controlled in-range inputs. Return to Slice
4 range safety and Slice 6 error/flag barriers before parsing can be verified.

After considering refactoring risk, the learner confirmed this order: make the
numeric builder return status and preserve caller-owned cleanup now; harden range and
duplicates before leaving numeric parsing; defer flag recognition until afterward.
Give the numeric builder a starting argv index so flags can later select where
numbers begin without rewriting stack construction. Implement and test this builder
in isolation before changing `main`.

The learner began `parse_numbers` in `parser.c` and correctly passes `t_context *ctx`,
which already provides stack `a` as `ctx->a`. The unfinished slice must use a local
tail rather than `ps_lstadd_top`, preserve the caller-supplied `start`, loop with
`start < argc`, advance the index, update `a.size` once per attached node, and return
success after the loop.

`push_swap.h` now exists with all four namespaced enum choices and the agreed
non-metrics context fields; standalone strict inclusion and Norminette pass. Context
initialization is implemented. Make the shared header dependency explicit in the
build graph before proceeding.

### Active cursor: Slice 5 — numeric stack construction (implemented)

`parse_numbers` builds `a` left-to-right with a parser-local non-owning tail: the
first node sets `a.top`, later nodes link through `tail->next`, `tail` and
`start` advance every pass, and `a.size` grows once per attached node. It returns
0 on an invalid token or allocation failure and 1 on success, without printing.
An isolated five-scenario suite passes strictly and under ASan/UBSan: order
preservation with the first integer on top, mid-stream failure leaving an owned
size-2 partial stack that `main`'s `ps_lstclear` frees, single element, immediate
failure with an empty `a`, and starting-index selection. `main(int, char **)`
always initializes, parses only when `argc > 1`, prints `Error\n` to stderr as
the single error source, cleans up on every path, and stays silent for no
arguments. Strict build, no-relink, and Norminette pass.

Duplicate detection implemented and verified (2026-09-06): `validated_node`
walks `a`'s attached nodes before each allocation and returns NULL on a value
match, so the duplicate is rejected before its node exists and cleanup paths
stay unchanged. `parse_numbers` attaches only validated nodes. The duplicate
family passes through the real binary (mid-stream, front, end, adjacent,
zero) with `Error\n` on stderr and silent controls. A Norm-forced refactor
split `validated_node` out of `parse_numbers`.

### Active cursor: Slice 6 — flags and complete-input barrier (implemented)

`parse_flags.c` (prototype in `push_swap.h`, object in the root Makefile)
consumes exact `--bench`/selector tokens before the first non-flag token,
records the first-integer index into `int *start`, and rejects repeated
`--bench`, conflicting selectors, and flag-looking tokens after the numeric
boundary via `flag_type` dispatch into a bench/selector `set_flag`. `main`
calls `parse_flags` then `parse_numbers` only when `start < argc`, so
flags-only runs stay silent. A Norm-forced refactor extracted `flag_type`;
`parse_flags` is 22 lines and Norm-OK. Full stream matrix passes: valid
flag+integer combinations in both orders are silent, invalid and conflicting
runs print exactly `Error\n` on stderr with exit 0. Learner debugged the
`&start` pointer pass and the bench/selector guard conflation via the matrix.

Next dependency: the overflow-safe conversion (Slice 4 remainder) replacing
unguarded `ft_atoi` in `validated_node` — the sole open numeric-parsing row —
then rank assignment (Slice 7) or the operation engine, per learner choice.

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

- Header and Makefile layout.
- Duplicate-detection and rank-assignment methods.
- Metrics representation and no-op emission/counting policy.
- Simple, medium, and complex methods.
- Adaptive benchmark naming.
- Second learner and contribution split.
