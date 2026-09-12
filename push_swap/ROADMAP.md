# Push_swap Learning Roadmap

This is a shared learning and progress document, not a substitute for the subject.
Requirements come from [`SUBJECT.md`](SUBJECT.md). The AI companion may propose an
update, but it must not edit this file until the learner approves the exact change.

## Status Legend

- `NOT STARTED` — no verified work yet
- `LEARNING` — concepts or design are being explored
- `IMPLEMENTING` — approved implementation is in progress
- `VERIFYING` — implementation exists but its gate is incomplete
- `DONE` — the learner has explained it and the required evidence passes
- `BLOCKED` — progress depends on a named missing decision or resource
- `LOCKED` — intentionally unavailable until its prerequisite is complete

## Current Focus

- **Milestone:** 6 — medium O(n√n) strategy
- **Status:** `LEARNING`
- **Next small step:** compare rank chunks with block/bucket placement, then trace a
  small legal-operation example before selecting the medium method.
- **Deferred verification:** Milestone 5 now includes the learner-deferred focused
  simple-strategy harness. Milestone 4 retains the postponed disorder, resolver, and
  sortedness checks; also add the learner-owned rank suite and 0/1/2/many-node raw-
  operation tests. Milestone 2 remains `VERIFYING` for memory tooling.
- **Confirmed output rule:** suppress wholly ineffective commands; a combined command
  emits/counts once when at least one component changes.
- **Outstanding team requirement:** the subject requires exactly two learners, but a
  partner has not yet been confirmed; this does not block architecture learning.

## Current Repository Baseline

Observed on 2026-09-05:

- Present source work uses `push_swap.h` as a single umbrella plus three specialized
  stack helpers; the learner removed obsolete `node.h` and `ft_lstiter.c`.
- The Makefile and `main(int argc, char **argv)` now complete the build shell
  with the parser integrated: `context_init` always runs, `parse_numbers` runs
  only when arguments exist, `main` alone prints `Error\n` to stderr, and
  cleanup runs on every path. Fresh strict build, silent no-argument run,
  no-relink check, cleanup rules, `re`, and Norminette all pass.
- The copied libft has an isolated root Makefile target: it creates
  `libft/libft.a`, and a repeated invocation leaves the archive timestamp unchanged.
  A strict root build now links the archive after the project objects and resolves
  `ft_isdigit`; root cleanup now delegates `clean`/`fclean` to libft.
- `is_valid_int` strictly builds, passes its focused 12-case syntax suite, and
  correctly accepts ordinary signed digit strings while rejecting empty, sign-only,
  whitespace, suffix, and repeated-sign inputs. The learner chose to defer exact
  range hardening until the reasonable-input construction path works; it remains a
  required parsing gate before verification.
- `parse_numbers` builds stack `a` left-to-right with a parser-local tail: the
  first node sets `a.top`, later nodes link through `tail->next`, `tail` and
  `start` advance every pass, and `size` grows once per attached node. It
  returns status without printing. An isolated five-scenario suite passes
  strictly and under ASan/UBSan: order preservation, mid-stream failure leaving
  an owned size-2 partial stack that `ps_lstclear` frees, single element,
  immediate failure, and starting-index selection.
- Confirmed implementation order: establish the parser return/ownership contract
  during reasonable-input construction; add exact range and duplicate checks before
  leaving numeric parsing; add flags afterward through the starting-index boundary.
- `push_swap.h` intentionally defines the stack, strategy, context, and helper
  declarations as the project's single umbrella header; all sources include it.
- `context_init.c` initializes all confirmed fields, and `main` performs safe cleanup.
  Focused assertions and ASan/UBSan pass with leak detection disabled, pending learner
  interpretation. The Makefile now tracks `push_swap.h` for every object; a temporary
  copy confirmed a newer umbrella header rebuilds all objects and relinks.
- `push_swap.h` defines typed `value`, `rank`, and `next` node fields plus a stack
  wrapper with authoritative `top` and `size`.
- `assign_ranks.c` now contains the learner-written count-smaller traversal; its
  umbrella declaration and Makefile source entry are present. Strict compilation
  and Norm pass. The AI-generated temporary invariant harness is diagnostic only
  and is not recorded as learner-interpreted verification evidence.
- Missing major deliverables: operations, strategies, benchmark mode, and README.
- `cc`, `make`, and `norminette` are available.
- Valgrind and a checker binary are not currently available; compiler sanitizers can
  provide interim memory diagnostics.
- The three retained helpers pass strict syntax-only compilation and Norminette.
- Focused empty, one-node, and two-node assertion tests pass normally and under
  AddressSanitizer/UndefinedBehaviorSanitizer with leak detection disabled; this
  environment cannot run LeakSanitizer under its active tracing mechanism.
- Existing files are learner work and must not be rewritten or discarded without
  explicit approval.

## Milestones

| # | Milestone | Status | Completion gate |
| ---: | --- | --- | --- |
| 0 | Subject and team orientation | `LEARNING` | Learner explains the deliverables, four strategies, disorder regimes, streams, performance gates, and group obligations; partner status is recorded. |
| 1 | Interface and architecture decisions | `IMPLEMENTING` | Top-of-stack invariant, node/data representation, ownership, input/flag grammar, operation-emission contract, and module boundaries are documented and explained. |
| 2 | Build, parsing, and lifetime | `IMPLEMENTING` | Required Makefile rules work without relinking; valid inputs build `a`; all invalid-input families print only `Error\n` to stderr; every error path frees memory. |
| 3 | Operation engine | `VERIFYING` | All 11 operations pass focused 0/1/2/many-node tests, preserve invariants, emit only allowed stdout lines, and update metrics through one understood contract. |
| 4 | Disorder, selection, and benchmark foundation | `IMPLEMENTING` | Disorder is computed before moves; known cases and 0.2/0.5 boundaries pass; default/forced selectors work; benchmark data stays on stderr and operation data stays on stdout. |
| 5 | Simple O(n²) strategy | `VERIFYING` | Learners compare candidates, select and justify one, prove its generated-operation upper bound, and pass forced-strategy correctness tests. |
| 6 | Medium O(n√n) strategy | `LEARNING` | Learners compare candidates, select and justify one, prove its operation upper bound, and pass forced-strategy correctness and scaling tests. |
| 7 | Complex O(n log n) strategy | `NOT STARTED` | Learners compare candidates, select and justify one, prove its operation upper bound, and pass forced-strategy correctness and scaling tests. |
| 8 | Adaptive strategy | `NOT STARTED` | Low, medium, and high disorder regimes select understood techniques at the exact required boundaries; documentation gives time/space arguments. |
| 9 | Integration and optimization | `NOT STARTED` | Every forced mode and adaptive mode sorts edge, patterned, and randomized inputs; Norm, memory, stream, relink, benchmark-count, and 100/500 performance checks pass. |
| 10 | README and defense readiness | `NOT STARTED` | Required first line and sections exist; algorithms, resources, AI use, and both contributions are accurate; both learners can explain or modify any area. |
| 11 | Bonus checker | `LOCKED` | Unlock only after every mandatory correctness, Norm, memory, Makefile, and benchmark gate passes. |

Milestone order is a guide rather than a prison. A session may explore another topic,
but the current focus and next step must remain explicit.

## Verification Matrix

Evidence should be recorded here only after the learner has seen and understood it.

| Area | Minimum scenarios | Evidence |
| --- | --- | --- |
| Build | `all`, repeated `all`, `clean`, `fclean`, `re`; required flags | Minimal shell passes fresh strict build; no-argument run exits 0 with empty stdout/stderr; repeated `make` reports nothing to do and preserves the binary timestamp; `clean` retains only the binary, `fclean` removes it, and `re` rebuilds. Umbrella-header dependencies are explicit; a temporary-copy probe showed a newer header rebuilds every object and then relinks. Learner explained both timestamp comparisons. The root target creates and links `libft/libft.a` after project objects. Cleanup delegation verified 2026-09-06 from a full 7-root/43-libft-object state: `clean` removes both object sets while retaining `push_swap` and `libft.a`; `fclean` removes both final targets too; `re` restores all artifacts; repeated `make` preserves binary/archive timestamps. Full Norm and parsing smoke checks remain clean after `re`. |
| Parsing | no args, one integer, signs, `INT_MIN/MAX`, overflow, non-number, empty token, duplicates, invalid/conflicting flags | Focused token-syntax suite passes 12 cases: unsigned and signed zero/ordinary digits are accepted; empty, sign-only, whitespace, suffix, and repeated-sign tokens are rejected. An isolated `parse_numbers` suite passes five scenarios under strict build and ASan/UBSan: left-to-right order with the first integer on top, correct `size`, mid-stream failure leaving an owned partial stack that `main`'s cleanup frees, immediate failure with an empty stack, and starting-index selection. Integrated `main` shows silent no-args, `Error\n` on stderr for a mid-stream invalid token, and silent valid input. Flag phase verified 2026-09-06: `parse_flags` (new `parse_flags.c`, in Makefile SRCS, prototype in `push_swap.h`) consumes exact `--bench`/selector tokens before the first non-flag token into `bench_enabled`/`strategy`, records the first-integer index via `int *start`, and rejects repeated `--bench`, conflicting selectors, and flags after the numeric boundary. Isolated ten-scenario harness plus a full 18-row stream matrix through the real binary: all valid flag+integer combinations (both bench/selector orders), plain integers, and flags-only runs are silent on both streams; `--bench --bench`, `--simple --adaptive`, `--bench 3 --bench`, `--benchmark`, non-integers, and duplicates print exactly `Error\n` on stderr with exit 0. Learner debugged the `&start` pointer bug (literal `1` passed instead of the address) and the bench/selector guard conflation via the matrix. A Norm-forced refactor (2026-09-06) extracted the five-branch flag dispatch into `static int flag_type`, slimmed `parse_flags` to 22 lines, and re-verified Norm-OK with an identical matrix. `norminette *.c *.h` and strict build remain clean. Range conversion verified 2026-09-06 with guarded positive-magnitude `long long` accumulation: a strict ASan/UBSan assertion harness stores exact `INT_MAX`, `INT_MIN`, and zero, while stream captures accept both exact boundaries and reject immediate and arbitrarily long overflow with exactly `Error\n` on stderr. The learner explained sign/limit selection and that the final digit is rejected before its addition would cross the limit. Duplicate detection verified 2026-09-06 after Norm-forced refactor: `validated_node` walks `a` before allocating, returning NULL on a value match, and `parse_numbers` attaches only validated nodes. Strict build plus stream capture show mid-stream, front, end, adjacent-negative, and zero duplicates each print exactly `Error\n` to stderr with empty stdout and exit 0; single-node, all-unique, and negative-vs-positive controls stay silent. `norminette *.c *.h` is OK and repeated `make` does not relink. Subject confirmed invalid input requires exactly `Error\n` on stderr with no exit-code requirement, so exit 0 on error is acceptable. Syntax, range, and duplicates pass their focused cases. Fresh flag evidence first exposed an asymmetric adaptive-default defect. The learner traced it, implemented local selector-seen state, used two failing matrices to separate benchmark and selector state correctly, and explained that repeated benchmark is independently rejected through `bench_enabled`. The final strict build, full Norm, 28-case symmetric stream matrix, isolated ASan/UBSan contract harness, and no-relink check pass. |
| Operations | each operation on empty, one-node, two-node, and ordinary stacks; combined-operation semantics | Pending |
| Disorder | sorted = 0, reverse = 1, known intermediate inputs, fewer than two elements, boundaries 0.2 and 0.5 | Pending |
| Streams | stdout contains only operations; errors and bench output use stderr; no bench text without `--bench` | Pending |
| Strategies | every selector on small, sorted, reverse, patterned, and random unique inputs | Pending |
| Metrics | total equals the sum of all 11 counters and matches stdout operation lines | Pending |
| Quality | `-Wall -Wextra -Werror`, Norm, sanitizer/Valgrind, no leaks or invalid access | Stack foundation and context initializer: strict compilation and Norm pass; focused initialization, empty/one/two-node, partial-ownership, and cleanup assertions pass normally and with ASan/UBSan. Learner explained uninitialized-pointer cleanup risk and that resetting `top`/`size` alone cannot prove nodes were freed. LeakSanitizer remains unavailable, so leak evidence is incomplete. |
| Performance | repeated random samples of 100 and 500 against pass/good/excellent thresholds | Pending |
| Defense | each learner explains invariants, algorithms, complexity, ownership, errors, and a small modification | Pending |

## Decision Log

Do not record a design as final merely because an AI suggested it.

| Decision | Alternatives considered | Rationale and operation bound | Confirmed by |
| --- | --- | --- | --- |
| Stack representation | Generic `void *content` nodes vs. project-specific nodes; raw head pointers vs. a stack wrapper | Singly linked `t_node` stores immutable raw value, rank, and `next`; `t_stack` stores `top` and `size`, with the head as top. This gives typed access, one allocation per node, explicit size checks, and simple ownership: every node belongs to exactly one stack and is freed once; pushes transfer nodes without allocating or freeing. Internal list traversal does not itself generate Push_swap operations. | `naamir` |
| Stack helper interface | Keep generic traversal helpers vs. retain only helpers required by the stack abstraction | Removed `ft_lstlast` and `ft_lstsize`: no current operation requires the former, while the latter would duplicate the authoritative `t_stack.size`. The specialized node creation, add-to-top, and cleanup helpers use a `ps_` prefix so their `t_node`/`t_stack` interfaces can coexist with libft's different `ft_lst*` API. | `naamir` |
| Input and flag grammar | Strict flags-before-integers grammar vs. accepting flags anywhere | Use `push_swap [--bench] [one strategy selector] integers...`: all flags precede the first integer; `--bench` may combine with one selector; repeated flags, conflicting selectors, or a flag after integer parsing begins are invalid; adaptive is the default selector; no arguments print nothing. This is deterministic and keeps parsing state simple. | `naamir` |
| Parser ownership contract | Parser cleans partial state vs. caller owns one initialized context for the whole run | `main` owns the context and always clears stack `a`; the parser transfers each allocated node immediately into `a`, returns status without printing, and may leave an owned partial stack on failure. `main` performs cleanup and is the single source of `Error\n` output. This keeps allocation ownership and error output centralized. | `naamir` |
| Input node construction order | Insert each argument at the top vs. append each argument at the bottom; parser-local tail vs. persistent stack tail | Chose left-to-right bottom insertion with a parser-local tail so the first integer remains the top of `a`, construction is O(n), and `t_stack` keeps only its existing `top` and `size` invariants. Parser work does not count as generated Push_swap operations. | `naamir` |
| Persistent run-state organization | One program context vs. separate stack, option, disorder, and metrics objects | Chose one caller-owned context to carry both stacks, the selected strategy, benchmark state, initial disorder, and operation counters across parsing, sorting, reporting, and cleanup. This centralizes lifetime and avoids globals. | `naamir` |
| Strategy representation | Retain the selector string vs. parse once into an enum | Store a `t_strategy` enum in the context, initialized to adaptive before parsing. Valid selectors replace that value, so sorting happens only after complete successful parsing and can dispatch without repeated string comparisons. | `naamir` |
| Adaptive strategy resolution | Overwrite the requested enum vs. store a second context field vs. return an effective method from a pure resolver | Keep `context.strategy` as the requested mode and use a pure resolver to return the effective simple/medium/complex method. Forced selectors return unchanged; adaptive maps the saved initial disorder at the exact subject boundaries. This preserves truthful benchmark reporting without adding persistent state and generates zero Push_swap operations. | `naamir` |
| Header boundary | Separate narrow `node.h` beneath `push_swap.h` vs. one project-wide umbrella header | Chose one `push_swap.h` containing node, stack, strategy, context, and all project prototypes; removed `node.h` and made every source include the umbrella. This favors one centralized interface, with the understood consequence that changing it may rebuild every object. | `naamir` |
| Exact integer conversion | Negative `int` accumulation vs. a guarded positive magnitude in `long long` | Chose the wider positive accumulator for readability. A per-digit pre-check against `INT_MAX` or the magnitude of `INT_MIN` rejects overflow before multiplication, including arbitrarily long tokens; syntax validation remains a separate pass. Conversion is O(k) character work and emits no Push_swap operations. The retained implementation was written by AI at the learner's explicit request; the learner then explained its sign, limit, and rejection behavior. | `naamir` |
| Duplicate detection | Walk the already-attached nodes of `a` per token vs. copy values into a temporary sorted array | Walk `a` before each allocation: worst-case n(n−1)/2 value comparisons, zero extra allocation, no new allocation-failure mode, and the duplicate is rejected before its node exists, so cleanup paths stay unchanged. The array approach is deferred until rank assignment can justify its own allocation on its own merits. | `naamir` |
| Flag-phase boundary | Flag-looking tokens after numbers begin treated as invalid integers vs. special-cased anywhere | The flag phase consumes only exact `--bench`/`--simple`/`--medium`/`--complex`/`--adaptive` tokens; the first token that is not one of those exact strings ends the phase, so a later `--bench` after numbers begin is rejected as an invalid integer. `--bench` and one selector may appear in either order before the first integer; repeats and conflicts are invalid. This keeps one deterministic boundary and needs no lookahead. A run whose tokens are only
flags, with no integers following, prints nothing like a no-parameter run;
this is a learner-confirmed reading of the subject's unspecified corner. | `naamir` |
| Rank assignment | Count-smaller traversal vs. copy-sort-map array; narrow `t_stack *` vs. whole `t_context *` interface | Chose count-smaller: each node's rank is the number of smaller values. It is O(n²) C comparisons, O(1) auxiliary space, requires no allocation or failure cleanup, preserves values/link order, and generates exactly zero Push_swap operations. Chose `void assign_ranks(t_stack *stack)` because ranking needs only one stack's nodes, not options or the other stack. The learner prioritized simplicity because ranking work does not count toward emitted-operation thresholds, while acknowledging ordinary runtime still exists. | `naamir` |
| Raw push parameter order | Destination-first vs. source-first | Chose `push(source, destination)` so the first argument relinquishes ownership and the second receives the same node. The primitive allocates and frees nothing. | `naamir` |
| Raw rotate tail helper | Generic add-back changes size vs. rotation-only tail link preserves size | `ps_lstadd_back` only links the already-owned moved node at the tail and deliberately does not change size. Rotate changes order within one stack, not membership; the learner explained that its node count therefore remains unchanged. | `naamir` |
| Operation metrics representation | Eleven named context fields vs. an enum-indexed counter array | Chose a `t_operation` enum with all 11 commands plus `OP_COUNT`, `size_t counts[OP_COUNT]`, and `size_t total`. One operation identifier can drive mutation, output, and its matching counter; iteration can initialize, sum, and report all counters consistently. The learner explained that enum members are compile-time integer indexes rather than values stored in the array. | `naamir` |
| No-op emission and counting | Always emit requested commands vs. suppress commands that change no state | The canonical PDF says primitive operations do nothing when their precondition is absent, the strategy output is the operation sequence that sorts, and the program must display the smallest list possible. A wholly ineffective command can always be removed, so it must not be emitted or counted. A combined command emits/counts once if at least one component changes; its two primitives are never counted separately. | `en.subject.pdf` |
| Operation wrapper organization | Shared emitter vs. emission/counting inside each command handler | Chose separate handlers for all 11 commands with mutation, stdout emission, and the matching individual/total increments colocated in each handler; `execute_operation` performs enum dispatch. This fits the Norm file/function limits and is direct, with the accepted maintenance risk that every handler must independently preserve mnemonic length and counter consistency. | `naamir` |
| Strategy dispatcher sequencing | Implement strategies first vs. compile empty strategy stubs vs. define dispatcher architecture first | Define the dispatcher contract and complete call flow before building the simple strategy, so later work has a clear integration target. `run_strategy` returns `1` on success and `0` on a strategy/allocation failure; `main` owns `Error\n`. Do not compile empty strategy bodies: they would make valid unsorted input follow the error path or silently remain unsorted. Add the dispatcher source only when real callees make it a useful compilable slice. | `naamir` |
| Simple strategy | Minimum extraction vs. insertion-style ordered placement | Repeatedly move the smallest remaining rank to the top of `a` and `pb` it until `a.size == 1`, then `pa` all extracted nodes. The last node is the maximum rank; `b` is descending from top to bottom, so restoration makes `a` ascending. With shortest-direction rotation, the generated-operation bound is `sum(floor(m / 2), m = 2..n) + 2(n - 1)`, hence O(n²), with O(1) auxiliary space. | `naamir` |
| Medium strategy | Pending | Pending | Pending |
| Complex strategy | Pending | Pending | Pending |
| Adaptive internal methods | Pending | Pending | Pending |

## Contribution Record

The partner is not yet confirmed. Once confirmed, record meaningful design,
implementation, testing, review, and documentation contributions here as they occur.
The final `README.md` must contain an accurate human-readable summary for both learners.

| Learner | Confirmed contributions |
| --- | --- |
| `naamir` | Initial linked-list exploration; compared representations and selected a specialized singly linked node plus stack wrapper with explicit ownership invariants; drafted the specialized types in `node.h`; implemented add-to-top to update both `top` and `size`; initialized new nodes with unassigned rank `-1`; implemented stack cleanup that frees all nodes and resets both invariants; removed redundant traversal helpers to keep `t_stack.size` authoritative; renamed the specialized helpers with a `ps_` prefix so they do not collide with libft's generic list API; selected the strict flags-before-integers input grammar, caller-owned parser lifetime contract, O(n) left-to-right bottom insertion using a parser-local non-owning tail, a single caller-owned program context, an adaptive-default strategy enum, and a separate `push_swap.h` program-level header over narrow `node.h`; explained that stack `a`, not the local alias, retains ownership after parsing; implemented and verified the minimal `main.c` and Makefile build shell; added the copied-libft archive target and linked it after the project objects in the strict root build; implemented `parse_numbers` building stack `a` left-to-right through a parser-local tail with first-node `a.top` attachment, per-node size updates, and an advanced start index; integrated `main` as the single `Error\n` source with caller-owned cleanup on every path; on 2026-09-06
chose walk-based duplicate detection over a temporary sorted array so rejection
happens before allocation with no extra allocation or failure mode; on
2026-09-06 confirmed the flag-phase boundary (exact-match tokens, first
non-flag ends the phase, order-independent bench/selector, flags-only silent);
implemented `parse_flags.c` with an exact-match `is_flag` helper, a
bench/selector `set_flag`, and a `flag_type` dispatcher; debugged via the
stream matrix the `&start` pointer pass, the bench/selector guard conflation,
and the `1 < argc` loop-condition crash; wired `main` to parse flags then
numbers with the flags-only silent guard; refactored `flag_type` out for
Norm (22-line `parse_flags`); selected guarded positive-magnitude `long long`
conversion over negative `int` accumulation for readability and explicitly
requested the AI-authored `parser.c` rewrite; explanation and evidence
interpretation followed by tracing the sign, positive magnitude limit, and
final-digit overflow rejection; on 2026-09-06, traced `--adaptive --simple`:
the context starts adaptive, remains adaptive after the explicit selector, and
therefore incorrectly permits simple because the code mistakes the enum value
for "no selector seen"; implemented a first local `selector_seen` attempt that
now rejects selector conflicts but also treats `--bench` as a selector, exposed
by the focused review matrix; restricted the second-attempt conflict check to
nonzero types, then made assignment selector-only so the full symmetric matrix and
isolated flag contract now pass; explained that repeated benchmark is rejected by
`set_flag` setting status to zero when `bench_enabled` is already true; distinguished
`clean` (remove root/libft objects, retain final targets) from `fclean` (also remove
`push_swap` and `libft.a`); implemented root cleanup delegation to libft, with the
full artifact-state, `re`, no-relink, Norm, and parser smoke checks passing; traced
zero-based ranks correctly and selected count-smaller rank assignment for its
no-allocation simplicity and zero generated-operation cost; selected a narrow
`t_stack *` interface because ranking needs only one stack's nodes; implemented
the nested count-smaller traversal and added its umbrella declaration and Makefile
source entry; implemented the first no-output/no-metrics `swap(t_stack *)` pointer
primitive with a fewer-than-two no-op guard and unchanged size; chose and implemented
the corrected source-first raw push transfer using a saved moved-node pointer and
both top updates, with no allocation or freeing; implemented guarded raw rotate using
a tail-link helper without changing stack size; corrected reverse-rotate by retaining
and detaching the penultimate/last pair before installing the last as top; chose
enum-indexed operation counters and explained how enum constants index numeric
counter elements; implemented all 11 command handlers and enum dispatch with
emission/counting colocated in each handler; corrected all mnemonic byte lengths so
each generated command ends in exactly one newline with no NUL byte; chose a pure
adaptive resolver that preserves the requested strategy enum while returning the
effective complexity-class method for dispatch and later benchmark reporting;
consolidated rank/disorder/sortedness work into `stack_analysis.c` and implemented
the const-correct adjacent-order `is_sorted` query with its public interface; chose
to define the strategy-dispatch architecture before individual strategies while
rejecting compiled empty stubs that could masquerade as successful sorting; traced
the dispatcher's `0` return through `main`'s `!ok` branch and confirmed the shared
success/failure contract; reorganized numeric parsing into `parse_numbers.c`, merged
specialized node/list helpers into `stack_utils.c`, grouped resolution/dispatch in
`strategy_dispatch.c`, and synchronized the public declarations and Makefile sources;
traced minimum extraction on `[3, 1, 4, 2]`, identified the redundant final
`pb`/`pa` round trip, and selected minimum extraction as the simple strategy because
the sole node left in `a` is the maximum rank while `b` restores in sorted order;
wrote the first `simple.c` implementation draft with rank-position search,
direction selection, and extraction through the existing operation wrappers;
completed the minimum-extraction entry point, including shortest-direction movement,
restoration with `pa`, and the dispatcher's successful simple branch; connected
`run_strategy` to the successful parse/rank path in `main`; extracted
`prepare_and_sort` so the integrated entry path remains within the Norm line limit |
| Partner pending | None yet |

## Latest Session Handoff

- **All command handlers implemented:** the learner split `sa/pa/ra/rra`,
  `sb/pb/rb/rrb`, combined `ss/rr/rrr`, raw primitives, and enum dispatch across
  Norm-sized files, with emission/counting baked into each handler rather than a
  shared emitter. Strict build and full operation-file Norm pass. An AI-authored
  all-operation diagnostic confirms pointer effects, no-op suppression, and counter
  selection, but exposes `write(..., 3)` for `rra\n`, `rrb\n`, and `rrr\n`: their
  missing newlines collapse 11 emitted commands into only 8 stdout lines.
- **First mnemonic-length correction:** `rrr\n` is corrected to 4, but `rra\n` and
  `rrb\n` remain at 3; `ss\n` and `rr\n` were incorrectly changed to 4, causing
  `write` to emit each string's terminating NUL. Strict build and Norm still pass,
  while the byte-level diagnostic shows 36 bytes, 9 lines, two NUL bytes, and joined
  reverse-operation mnemonics instead of the required 11 clean lines.
- **Mnemonic-length correction complete:** strict build and full operation-file Norm
  pass. The AI-authored all-operation diagnostic passes pointer/counter assertions
  under ASan/UBSan and emits exactly 36 bytes as 11 newline-terminated mnemonics with
  zero NUL bytes. Milestone 3 moves to `VERIFYING`; learner-owned edge/stream tests
  remain required before `DONE`.
- **Metrics decision:** the learner chose an operation enum plus
  `counts[OP_COUNT]` and `total`, and explained that the enum constants are numeric
  indexes while the array elements store counts.
- **Canonical no-op rule:** direct review of the unchanged expected-hash PDF confirms
  that primitives do nothing without their preconditions, generated output is the
  sorting sequence, and the binary must display the smallest list possible. Therefore
  wholly ineffective commands are suppressed; combined commands emit/count once when
  either component changes.
- **Metrics-state first attempt:** the enum and context fields are correctly placed,
  and strict build plus Norm pass. The loop `while (i++ < OP_COUNT)` increments before
  the body, skipping `counts[0]` and writing `counts[OP_COUNT]`; UBSan reports the
  out-of-bounds index 11. Move the increment after the indexed assignment.
- **Metrics-state correction:** the learner moved the increment after assignment.
  Strict build and Norm pass; an AI-authored ASan/UBSan initialization harness sees
  all 11 counters, total, and both empty-stack states initialized to zero with no
  diagnostic. Learner-owned verification remains part of the operation gate.
- **Operation-engine implementation:** the learner created `operations.c` with an
  internal `swap(t_stack *)` primitive. Its pointer rewiring and size guard are
  correct; it is now declared in `push_swap.h` and included in the Makefile. Fresh
  strict build, Norm, and no-relink checks pass. An AI-authored ASan/UBSan diagnostic
  covers empty, single, and three-node behavior, but is not learner-owned verification.
- **Raw-push first attempt:** the learner chose `push(source, destination)`, but the
  current body overwrites `source->top->next` before advancing either stack top and
  never assigns `destination->top`. This disconnects the remainder of the source and
  leaves both top pointers wrong even though standalone compilation and Norm pass.
- **Raw-push correction:** the learner added the saved `moved` pointer, advances the
  source top before relinking, assigns the destination top, and updates both sizes.
  Strict build and Norm pass. An AI-authored ASan/UBSan diagnostic covers empty-source
  no-op and a many-to-nonempty transfer but is not learner-owned verification.
- **Rotate implementation:** the learner added a guarded raw rotate that detaches the
  top node and appends it through a new `ps_lstadd_back` helper. Strict build and Norm
  pass, its duplicate declaration is removed, and `rotate` now has an umbrella
  prototype. A repeated build performs no relink. The learner explained that the
  helper must not change size because rotate only reorders one stack's existing nodes.
- **Reverse-rotate first attempt:** standalone strict syntax compilation and Norm
  pass, but traversal retains only the last node. Linking that last node to the old
  top without clearing the penultimate node's link creates a cycle instead of moving
  the tail. Retain the penultimate pointer and detach the tail before relinking; the
  umbrella prototype is also still missing.
- **Reverse-rotate correction:** the learner now tracks the last and penultimate
  nodes, clears the penultimate link, and moves the last node to top, eliminating the
  original cycle. The stale unused variable is removed and the umbrella prototype is
  present. Strict build and Norm pass; an AI-authored ASan/UBSan diagnostic covers
  empty, single, and three-node behavior but is not learner-owned gate evidence.
- **Current implementation:** the learner implemented `assign_ranks(t_stack *)`
  with a reset count and full scan for every node, and added the header declaration
  and Makefile source entry. The corrected `main` integration now guards the call
  with successful `parse_numbers` status, preserving the complete-input barrier.
  Strict compilation and Norm pass; valid input remains silent and invalid mid-stream
  input still produces only `Error\n` on stderr. An AI-authored
  temporary harness also passed, but it is not learner-owned or learner-interpreted
  evidence and must not be used to close the focused gate.
- **Last implementation evidence:** at the learner's explicit request, AI replaced
  the negative-accumulation draft in `parser.c` with guarded positive-magnitude
  `long long` conversion. Strict build, Norm, an ASan/UBSan assertion harness for
  exact `INT_MIN`/`INT_MAX`, and the focused syntax/range/duplicate stream
  regression pass. The learner interpreted the limit selection and explained
  that invalid final-digit addition is rejected before crossing that limit.
- **Latest interpreted finding:** the selector-conflict check is asymmetric because
  `STRATEGY_ADAPTIVE` represents both the default and an explicit `--adaptive`;
  the learner traced why adaptive-first repeats/conflicts are incorrectly accepted.
- **Latest implementation evidence:** the learner added local `selector_seen` state;
  strict build and Norm pass, and selector repeats/conflicts now reject externally,
  but the focused matrix shows valid bench-plus-selector orders fail because every
  recognized flag currently consumes/checks selector state. Learner interpretation
  of this new evidence is pending.
- **Second-attempt evidence:** strict build and Norm still pass. Selector-first bench
  combinations now pass, but bench-first simple/adaptive still fail: the check is
  selector-only, while `selector_seen = 1` remains unconditional after benchmark.
- **Third-attempt evidence:** the learner made assignment selector-only. Strict build,
  full Norm, all 28 stream cases, an isolated ASan/UBSan flag-contract harness, and
  no-relink check pass. The learner explained the independent `bench_enabled`
  rejection path, closing the focused flag gate.
- **Latest learning evidence:** the learner distinguished intermediate object cleanup
  from final-target cleanup across both the root project and libft.
- **Latest build evidence:** root `clean`/`fclean` now delegate to libft. From a full
  build, artifact-state checks confirm the intended clean/fclean distinction; `re`,
  strict compilation, full Norm, parser smoke checks, and no-relink all pass.
- **Latest design choice:** count-smaller rank assignment, O(n²) C work and O(1)
  auxiliary space, with values/order unchanged and zero generated operations;
  `assign_ranks` takes only the `t_stack *` it actually needs.
- **Open question:** who is the required second learner?
- **Deferred verification:** learner-owned rank tests for empty, single, sorted,
  reverse, and mixed stacks, including unchanged structural invariants.
- **Disorder implementation begins:** the learner added an untracked
  `compute_disorder.c`. Its nested traversal covers every later-node pair, returns
  zero below two nodes, and passes standalone strict compilation and Norm. The learner
  then changed the counters to `size_t`, made both cursors const, added the prototype,
  and added the Makefile entry. The filename typo was corrected; the full strict build
  now succeeds, the function and header pass Norm, and an immediate repeated `make`
  performs no work.
- **Resume with:** save the computed disorder on the successful complete-input path,
  while retaining the postponed focused checks as missing verification evidence.
- **Test-cadence choice:** the learner explicitly deferred the focused disorder
  harness and requested that future focused harness phases begin by asking whether
  to test now or delay. This evidence remains required before Milestone 4 can be
  `DONE`; proceed meanwhile with saving the initial disorder on successful input.
- **Initial-disorder integration:** `main` now stores `compute_disorder(&context.a)`
  only after complete successful parsing and before rank assignment or any future
  operation. Strict build and Norm pass, and an immediate repeated `make` performs
  no work. Focused disorder behavior remains deliberately unverified for now.
- **Resume with:** choose whether adaptive resolution should return an effective
  strategy without mutation or store a separate effective-strategy field; do not
  overwrite the requested strategy and lose future benchmark identity.
- **Adaptive-resolution decision:** use a pure resolver rather than overwriting the
  requested enum or adding a persistent effective-strategy field. Forced selectors
  pass through unchanged; adaptive returns a method from the exact disorder regimes.
- **Resume with:** implement only that resolver, its declaration, and build entry;
  do not call a sorting strategy that does not exist yet.
- **Resolver implementation:** `resolve_strategy.c` correctly passes forced modes
  through and maps adaptive `< 0.2`, `< 0.5`, and the remaining range to simple,
  medium, and complex. The learner corrected their boundary interpretation against
  the canonical PDF. The source is in the Makefile; strict build, source/header Norm,
  and no-relink pass, but the promised public declaration is still missing from
  `push_swap.h` because the build does not yet call the function externally.
- **Resume with:** add that declaration before any integration or focused test choice.
- **Resolver interface complete:** the declaration is now in `push_swap.h`; a full
  strict rebuild, resolver/header Norm, and immediate no-relink check pass. The
  learner chose to defer focused forced-mode and exact-0.2/0.5 checks, so resolver
  correctness remains unverified gate evidence despite the implementation review.
- **Resume with:** build the smallest read-only sortedness helper before any strategy
  implementation; ask again when its focused test phase becomes timely.
- **Stack-analysis consolidation:** the learner replaced separate `assign_ranks.c`
  and `compute_disorder.c` modules with `stack_analysis.c`, retaining both functions
  and adding `is_sorted`. The sortedness logic accepts fewer than two nodes, rejects
  the first descending adjacent pair, and otherwise accepts the stack. The full
  strict build, file/header Norm, and no-relink check pass. Its public declaration is
  now present, and the cursor is `const t_node *`, enforcing the intended read-only
  contract. A fresh strict rebuild, file/header Norm, and no-relink check pass.
- **Resume with:** ask whether to run focused empty/single/sorted/reverse checks now
  or explicitly defer them; do not close the verification gate without evidence.
- **Sortedness verification deferred:** the learner chose not to run the focused
  harness now. Empty, single, sorted, reverse, and unchanged-structure evidence stays
  open for Milestone 4. Focus shifts to comparing simple-strategy candidates without
  treating Milestone 4 as complete.
- **Resume with:** compare and trace minimum extraction versus insertion-style
  placement in legal Push_swap operations before selecting the O(n²) baseline.
- **Dispatcher-first clarification:** the learner wants the central selection and
  execution path designed before implementing the individual strategies. The agreed
  order is contract/control-flow first, then real strategy implementations, then the
  compilable dispatcher connection; empty sorting stubs are excluded because they
  would create false-success behavior.
- **Resume with:** settle the dispatcher's responsibilities and error-return boundary,
  then return directly to selecting and building the simple strategy.
- **Dispatcher draft:** the learner created untracked `strategy_dispatch.c` with the
  agreed sorted-input guard and pure effective-strategy resolution. It passes strict
  standalone compilation and Norm and is correctly absent from the project build for
  now. All three unsorted branches return `0`; under the proposed status contract this
  means every unsorted valid input fails, so the draft cannot be integrated until
  real strategy calls replace those placeholders.
- **Resume with:** have the learner explain the `1`/`0` meaning, then preserve this as
  a non-integrated draft and return to choosing the simple strategy.
- **Dispatcher status understood:** the learner traced a `0` return into `main`'s
  `!ok` branch and correctly concluded that it would print `Error\n`. This confirms
  `1` as success and `0` as failure; the draft remains outside the build until real
  strategy calls replace its unsorted placeholders.
- **Resume with:** compare, trace, and choose the O(n²) simple strategy.
- **Organization review:** numeric parsing was renamed and its private syntax helper
  made static; specialized node/list helpers were consolidated and the constructor
  renamed `ps_lstnew`; rank, disorder, sortedness, and strategy resolution now share
  `stack_analysis.c`. A fresh strict build, full source/header Norm, no-relink check,
  and basic valid/invalid stream smoke checks pass after the moves.
- **Organization issues to resolve:** `resolve_strategy` is strategy-selection logic,
  not stack analysis, so its current placement conflicts with the planned cohesive
  `strategy_dispatch.c`. Also, `operation_linked_lists.c` contains support utilities,
  not emitted Push_swap operations, so its name is misleading. The tracked generated
  files `push_swap`, `parser`, and `libft/libft.a` also require an intentional Git
  hygiene decision rather than being treated as ordinary ignored artifacts.
- **Resume with:** decide the two module names/placements without changing behavior,
  then return to the simple-strategy comparison.
- **Organization recheck:** helper implementations now live cohesively in
  `stack_utils.c`; `stack_analysis.c` contains only rank/disorder/sortedness; and
  `resolve_strategy` now sits beside the unintegrated `run_strategy` draft in
  `strategy_dispatch.c`. Fresh `fclean`/rebuild, active-source strict compilation,
  standalone dispatcher compilation, no-relink, and parsing/stream smokes pass.
- **Remaining organization defects:** the old tracked `ps_lstadd_top.c` and
  `resolve_strategy.c` were emptied rather than removed, so full Norm fails both with
  `EMPTY_LINE_EOF`; `stack_utils.c` still names `operation_linked_lists.c` in its 42
  banner. A stale ignored `operation_linked_lists.o` also survived `fclean` only
  because it predates the renamed Makefile source list. `push_swap.h` publicly
  declares `resolve_strategy`, but the Makefile excludes its new defining module, so
  neither resolver nor dispatcher exists in the linked binary. Generated binaries
  remain tracked and continue to create Git noise.
- **Resume with:** remove the two empty legacy sources, fix the banner, discard the
  stale ignored object as housekeeping, and re-run full Norm before strategy work.
- **Organization cleanup confirmed:** both empty legacy sources and the stale object
  are gone; `stack_utils.c` has the correct banner; `strategy_dispatch.c` is in the
  Makefile; and both resolver/dispatcher declarations are public. Fresh `fclean`
  leaves zero root/libft objects and removes both targets; a strict rebuild, full
  source/header Norm, symbol check, no-relink check, and existing stream smokes pass.
- **Remaining repository-hygiene note:** generated binaries are still tracked, so
  builds modify Git-visible artifacts; this is separate from the now-correct source
  organization.
- **Resume with:** return to the minimum-extraction versus insertion-style comparison
  and choose the simple O(n²) method.
- **Simple-strategy decision:** the learner selected minimum extraction over
  insertion-style placement. On `[3, 1, 4, 2]`, the learner produced a correct
  sorting trace, then explained why extraction stops at `a.size == 1`: after all
  smaller ranks have moved to `b`, the remaining node is the maximum and need not
  take a redundant `pb`/`pa` round trip. `b` is descending top-to-bottom, so repeated
  `pa` reconstructs ascending `a`.
- **Resume with:** design and implement the minimum-position/rotation slice in
  `simple_sort.c`, then connect the real simple target to the dispatcher.
- **First simple-strategy draft:** `simple.c` now searches for each wanted rank and
  calls the existing operation wrappers. Norm passes, but strict compilation rejects
  the order of `static`, signed/unsigned rank comparisons, and an unused local. Review
  also found that the reverse branch keeps a stale tail pointer and can loop forever,
  odd-sized midpoint selection may choose the longer direction, restoration with
  `pa` is missing, and the dispatcher currently reports `0` after `run_simple`.
- **Resume with:** have the learner correct those focused issues before integration or
  strategy testing; `main` still does not call `run_strategy`.
- **Second simple-strategy draft:** the learner corrected `static` placement, the
  odd-size direction choice, and restoration from `b` with `pa`. The revised reverse
  branch now refreshes its tail and is logically able to reach the wanted rank, but
  it is more complicated than checking `a.top` after each `rra`. Strict compilation
  still rejects three signed/unsigned rank comparisons and the unused `tail` local in
  `run_simple`; Norm remains clean. The dispatcher still returns failure after the
  simple strategy.
- **Resume with:** make those remaining small corrections, then rerun strict
  compilation before any focused strategy harness.
- **Third simple-strategy draft:** rank types, top-based reverse rotation, and the
  dispatcher's success return are corrected, and full Norm passes. The strict build
  now fails only because unused `tail` declarations remain in both `push_to_b` and
  `run_simple`; no focused strategy test has started.
- **Simple strategy builds:** both unused declarations are removed. A strict full
  build succeeds, full source/header Norm passes, and an immediate repeated `make`
  performs no work while preserving the binary timestamp. Code review shows the
  extraction/restoration flow is complete; correctness on actual stacks remains
  unverified because the focused harness has not yet been chosen or run.
- **Resume with:** ask whether to run the focused strategy harness now or defer it;
  do not treat compilation and Norm as sorting evidence.
- **Test-cadence choice:** the learner deferred the focused simple-strategy harness.
  Sorting correctness remains open; proceed only with dispatcher integration and do
  not mark Milestone 5 verified from compilation alone.
- **Resume with:** assign `ok = run_strategy(&context)` after successful ranking in
  `main`, preserving the existing single error-output and cleanup path.
- **Main integration:** `main` now assigns the dispatcher result to `ok` after saving
  disorder and assigning ranks. The strict build succeeds, but Norm reports
  `TOO_MANY_LINES` because `main` is now over 25 lines. Behavior has not been focused-
  tested because the learner deferred that harness.
- **Resume with:** extract the successful numeric-input preparation/sort path into a
  static helper without changing ownership, output, or flags-only behavior.
- **Main refactor complete:** learner-authored `prepare_and_sort` now owns numeric
  parsing, disorder capture, rank assignment, and strategy execution while `main`
  retains initialization, error output, and cleanup. Strict full build and full Norm
  pass; an immediate repeated `make` performs no work and preserves the binary
  timestamp. The deferred simple-strategy harness remains required, so Milestone 5
  moves to `VERIFYING`, not `DONE`.
- **Resume with:** begin Milestone 6 by comparing understandable O(n√n) candidates;
  do not propose a medium source file until the learner selects and traces a method.
