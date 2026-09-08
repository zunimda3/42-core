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
- Exact conversion uses a guarded positive magnitude in `long long`, with separate
  syntax validation. Per-digit checking selects `INT_MAX` or the magnitude of
  `INT_MIN` before multiplication; the learner traced the sign, limit, and
  final-digit rejection.
- Rank assignment uses count-smaller traversal: O(n²) C comparisons, O(1) auxiliary
  space, no allocation/failure path, and exactly zero generated operations.
- Operation metrics use a `t_operation` enum, `counts[OP_COUNT]`, and `total` so one
  operation identifier can drive mutation, output, and counting.
- Wholly ineffective commands are suppressed because the canonical subject requires
  the smallest generated list; combined commands emit/count once if either side
  changes. Algorithms remain open.

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

On 2026-09-06 the learner selected guarded positive-magnitude `long long`
accumulation over negative `int` accumulation for readability and explicitly
requested the AI-authored rewrite. Strict build and Norm pass; an ASan/UBSan
assertion harness confirms exact `INT_MIN`, `INT_MAX`, and zero values, while stream
tests reject immediate and arbitrarily long overflow with exact stderr and retain
duplicate/syntax behavior. The learner interpreted the evidence by explaining that
the final digit is rejected before its addition would cross the selected limit.

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

### Slice 6 — flags and complete-input barrier (focused gate complete)

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

Fresh walkthrough evidence on 2026-09-06 exposes an asymmetric selector bug:
`--adaptive --adaptive` and `--adaptive --simple` are accepted, while the reverse
conflict is rejected. `set_flag` uses `STRATEGY_ADAPTIVE` both as the default value
and as evidence that no selector has appeared, so explicit adaptive cannot be
distinguished from the default. The learner traced that state sequence correctly.
Restore an explicit selector-seen invariant before closing parsing; then finish
root/libft cleanup integration before rank assignment.

First learner implementation adds local `selector_seen` but sets and checks it for
every recognized flag. Strict build and Norm pass; all selector conflicts now reject
externally, but valid `--bench --simple`, `--simple --bench`, and
`--adaptive --bench` fail because benchmark type 0 incorrectly consumes selector
state. Restrict selector-seen logic to types 1..4, retain `set_flag`'s independent
repeated-bench handling, and rerun the symmetric matrix. Learner interpretation of
this first-attempt evidence is pending.

Second learner attempt changes the conflict check to `type && selector_seen`, so
selector-first benchmark combinations pass. The following assignment remains
unconditional, however, so benchmark-first selector combinations still fail (2 of
15 matrix cases). Make `selector_seen = 1` conditional on `type > 0`, then rerun.

Third learner attempt makes both the conflict check and state assignment
selector-only. Strict build and full Norm pass; a 28-case stream matrix covers every
selector alone, both bench orders, repeats, symmetric conflicts, late/unknown flags,
and range/duplicate regressions with zero failures. An isolated ASan/UBSan harness
also confirms successful context/start state and direct failure returns; no-relink
passes. The learner explained that `set_flag` rejects repeated benchmark by setting
status to zero when `bench_enabled` is already true. Close Slice 6 and return to
Makefile cleanup integration.

Cleanup probe after a full libft rebuild: built state has 7 root and 43 libft
objects, the binary, and the archive. Root `clean` removes only the 7 root objects;
root `fclean` then removes only the binary, leaving all 43 libft objects and
`libft.a`. The normal built state was restored. Have the learner distinguish clean
from fclean and then forward the corresponding sub-Make targets. The learner now
explains that clean removes root/libft objects while retaining the binary/archive,
and fclean additionally removes both final targets. Proceed with the minimal root
Makefile delegation and artifact-state test.

Cleanup delegation is implemented and verified: starting with 7 root and 43 libft
objects, root `clean` removes both object sets while retaining the binary/archive;
root `fclean` removes all objects plus both final targets; `re` restores the full
build. Repeated `make` preserves binary/archive timestamps, and full Norm plus parser
smokes pass after rebuilding. Proceed to Slice 7 rank assignment; keep milestone 2
in verification until unavailable LeakSanitizer/Valgrind evidence can be replaced or
obtained.

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

Learner chose count-smaller after correctly tracing mixed zero-based ranks. Build a
narrow no-allocation function: for each outer node, scan all nodes and assign the
number of smaller values. Test empty, single, sorted, reverse, and mixed cases while
asserting values, links, order, and authoritative size are unchanged.

The learner selected `void assign_ranks(t_stack *stack)` rather than a context
parameter because the function needs only one stack's nodes. The learner has now
implemented the nested count-smaller traversal and added its umbrella declaration
and Makefile source entry; strict compilation and Norm pass. An AI-authored temporary
harness is diagnostic only, not learner-interpreted gate evidence. Integrate the call
after successful parsing, then obtain a learner-owned focused invariant test before
moving to primitive mutations. The first integration attempt places the call directly
after `parse_numbers`, so it still runs when parsing returns failure with a partially
owned stack. The learner added the success guard; strict build and Norm pass, valid
input remains silent, and invalid mid-stream input still emits only `Error\n` on
stderr. Obtain the learner-owned focused invariant test next.

The learner has explicitly deferred that learner-owned rank suite to keep development
moving. Preserve it as a required verification item and proceed to Slice 8; do not
treat the AI-authored diagnostic harness as closing the rank gate.

### 8. Primitive mutations

Implement internal swap, push, rotate, and reverse-rotate without output first.
Combined commands apply primitives without recursively emitting two commands. Test
empty, one, two, and many nodes; exact links/sizes; pushes allocate/free nothing.

The learner created `operations.c` with `swap(t_stack *)`: the fewer-than-two guard
and three-link rewiring are correct, and standalone strict syntax compilation plus
Norm pass. Its umbrella declaration and Makefile source entry are now present; fresh
strict build, Norm, and no-relink checks pass. An AI-authored ASan/UBSan diagnostic
covers empty, single, and three-node behavior but is not learner-owned gate evidence.
Proceed to the raw push transfer while retaining focused operation tests as a gate.

The learner chose the source-first interface `push(source, destination)`. The first
body rewrites `source->top->next` and adjusts sizes but never advances `source->top`
or assigns `destination->top`, disconnecting the remaining source chain. Correct it
with a saved moved-node pointer and both top assignments before proceeding.

The learner corrected raw push with the saved moved-node pointer, both top updates,
and balanced size changes. Strict build and Norm pass; an AI-authored ASan/UBSan
diagnostic covers empty-source no-op and many-to-nonempty transfer but is not
learner-owned evidence. Proceed to raw rotate.

The learner added raw `rotate(t_stack *)` plus `ps_lstadd_back`. Its guarded detach
and append logic preserves size, and the real strict build plus Norm pass. The header
duplicate is removed and `rotate` is now declared; repeated make performs no relink.
The learner explained that the tail helper must not change size because rotate only
reorders existing membership. Proceed to raw reverse-rotate.

The first reverse-rotate attempt walks only to the final node, then links it to the
old top. Because the penultimate node still points to that final node, the result is
a cycle. Track both nodes, clear the penultimate link before installing the last as
the new top, and add the missing umbrella prototype. The learner corrected the link
logic, but a stale unused `i` now fails `-Werror`, and the prototype is still absent;
remove/add those respectively, then rebuild. Both are now corrected; strict build and
Norm pass, and an AI-authored ASan/UBSan diagnostic covers empty, single, and
three-node behavior without replacing the deferred learner-owned primitive suite.
Proceed to the operation emission/metrics contract.

Current development cursor: begin with the narrow internal swap primitive. It changes
only the first two links and `top`, leaves `size` unchanged, and is a no-op below two
nodes. Keep output and metrics out of this slice.

### 9. Operation emission and metrics

Compare named counters with an operation-enum-indexed array. Decide whether useless
commands are suppressed or printed/counted, including partial combined commands. Use
one dispatcher so each emitted command mutates state, writes exactly one mnemonic,
increments exactly one individual counter, and increments total. Maintain
`total == sum(individual) == stdout line count`.

The learner chose the enum-indexed array and explained that enum members are integer
indexes into numeric counters, not values that must first be stored in the array.
Add the enum and context fields, then initialize all counters and total to zero before
building the dispatcher. Direct PDF review resolved the no-op policy: suppress a
command when it changes no state; for a combined command, emit/count one combined
mnemonic if at least one side changes. Build only the first `sa` path next.

The learner instead completed all 11 handlers and enum dispatch at once, splitting
them across Norm-sized files and intentionally colocating emission/counting in every
handler rather than using a shared emitter. Strict build and Norm pass. An AI-authored
all-operation diagnostic confirms mutations, suppression, and selected counters, but
finds three stream-length defects: `rra\n`, `rrb\n`, and `rrr\n` are written with
length 3, collapsing 11 commands into 8 lines. Change those lengths to 4 before the
focused operation gate.

The first correction fixed `rrr\n`, but left `rra\n`/`rrb\n` at 3 and changed
`ss\n`/`rr\n` to 4. Since `write` emits exactly the requested byte count, those two
short mnemonics now include terminating NUL bytes. Required lengths are 3 for every
two-letter mnemonic plus newline and 4 for every three-letter mnemonic plus newline.

The learner corrected all five affected call lengths. Strict build and full operation
Norm pass; the AI-authored all-operation diagnostic passes under ASan/UBSan and emits
11 clean newline-terminated mnemonics, 36 bytes total, with no NUL bytes. Keep the
learner-owned operation suite deferred as the Milestone 3 gate and proceed to initial
disorder without marking the engine done.

The learner added the enum and context fields. The first initializer uses
`while (i++ < OP_COUNT)`, so the body begins at index 1 and ends by writing index
`OP_COUNT`; UBSan reports index 11 out of bounds. Use the current index in the body,
then increment it afterward, and rerun the focused initialization gate. The learner
made that correction; strict build and Norm pass, and an AI-authored ASan/UBSan
harness sees every counter plus total initialized to zero. Resolve the no-op policy,
then build only the first `sa` dispatcher path.

### 10. Initial disorder and dispatch

Compute inversion fraction before the first move with wide pair counters; define
sizes below two as disorder zero. Save the initial value. Forced selectors work on
every valid input; adaptive boundaries are exactly `< 0.2`, `[0.2, 0.5)`, and
`>= 0.5`.

The learner's `compute_disorder.c` now has the correct all-later-pairs traversal,
zero-below-two guard, wide integer counters, const node cursors, final floating-point
division, header declaration, and corrected Makefile entry. The full strict build and
Norm pass, and an immediate repeated `make` does no work. Run focused read-only checks
next, including unchanged node/link/top/size assertions. Do not integrate into `main`
yet.

The learner explicitly deferred that focused harness. Keep it as missing gate
evidence and integrate the result into `context.initial_disorder` only on the
successful complete-input path, before any future emitted operation. When a new
focused harness becomes timely, ask whether to run it now or defer it.

`main` now saves the initial disorder after complete successful parsing and before
rank assignment or any future operation; strict build, Norm, and no-relink checks
pass. Resolve adaptive dispatch next without overwriting `context.strategy`, because
benchmark mode must retain the originally requested strategy identity. Compare a
pure resolver return value with a separate effective-strategy context field.

Confirmed: use a pure resolver. It accepts the requested strategy and initial
disorder, returns forced selectors unchanged, and maps adaptive to simple below 0.2,
medium from 0.2 through below 0.5, and complex from 0.5 upward. It must not mutate
context or emit operations. Build only this helper/interface slice; strategy calls
remain unavailable.

The learner implemented the resolver with the exact boundaries and added its
Makefile entry. Strict build, Norm, and no-relink pass, but `push_swap.h` has no
resolver declaration yet. Add the prototype before integrating or offering the
focused boundary-test choice.

The declaration is now present; full strict rebuild, Norm, and no-relink pass. The
learner deferred the focused forced-mode and exact-boundary checks. Preserve that
missing evidence and move to the read-only sortedness helper; ask whether to test or
defer when its focused test phase is reached.

The learner consolidated ranking, disorder, and the new sortedness query into
`stack_analysis.c`; strict build, Norm, and no-relink pass. The adjacent-order logic
and umbrella declaration are present, but its node cursor remains mutable. Make that
cursor const before offering the focused sortedness-test choice.

The cursor is now const. Fresh strict rebuild, file/header Norm, and no-relink pass;
the sortedness implementation slice is complete. Ask whether to run focused
empty/single/sorted/reverse and unchanged-structure checks now or defer them.

The learner deferred those sortedness checks. Keep Milestone 4 verification open and
move to the simple-strategy comparison; do not treat implementation review as gate
evidence.

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
