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

- **Milestone:** 2 — build, parsing, and lifetime
- **Status:** `IMPLEMENTING`
- **Next small step:** return to the parked overflow-safe conversion (Slice 4
  remainder) to close numeric parsing — replace unguarded `ft_atoi` with
  `INT_MIN`/`INT_MAX`-exact conversion and test the boundary family; after that,
  milestone 2's parsing gate has only rank/operation-engine work downstream.
- **Paused design question:** operation metrics and emission remain undecided until
  the operation engine is the next implementation dependency.
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
  `ft_isdigit`; forwarding cleanup remains unfinished.
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
- Missing major deliverables: parser hardening (range, duplicates, flags),
  operations, strategies, benchmark mode, and README.
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
| 3 | Operation engine | `NOT STARTED` | All 11 operations pass focused 0/1/2/many-node tests, preserve invariants, emit only allowed stdout lines, and update metrics through one understood contract. |
| 4 | Disorder, selection, and benchmark foundation | `NOT STARTED` | Disorder is computed before moves; known cases and 0.2/0.5 boundaries pass; default/forced selectors work; benchmark data stays on stderr and operation data stays on stdout. |
| 5 | Simple O(n²) strategy | `NOT STARTED` | Learners compare candidates, select and justify one, prove its generated-operation upper bound, and pass forced-strategy correctness tests. |
| 6 | Medium O(n√n) strategy | `NOT STARTED` | Learners compare candidates, select and justify one, prove its operation upper bound, and pass forced-strategy correctness and scaling tests. |
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
| Build | `all`, repeated `all`, `clean`, `fclean`, `re`; required flags | Minimal shell passes fresh strict build; no-argument run exits 0 with empty stdout/stderr; repeated `make` reports nothing to do and preserves the binary timestamp; `clean` retains only the binary, `fclean` removes it, and `re` rebuilds. Umbrella-header dependencies are explicit; a temporary-copy probe showed a newer header rebuilds every object and then relinks. Learner explained both timestamp comparisons. The isolated root `libft/libft.a` target creates the archive; a repeated invocation reports it up to date and preserves its timestamp. Final binary linkage and cleanup integration remain pending. |
| Parsing | no args, one integer, signs, `INT_MIN/MAX`, overflow, non-number, empty token, duplicates, invalid/conflicting flags | Focused token-syntax suite passes 12 cases: unsigned and signed zero/ordinary digits are accepted; empty, sign-only, whitespace, suffix, and repeated-sign tokens are rejected. An isolated `parse_numbers` suite passes five scenarios under strict build and ASan/UBSan: left-to-right order with the first integer on top, correct `size`, mid-stream failure leaving an owned partial stack that `main`'s cleanup frees, immediate failure with an empty stack, and starting-index selection. Integrated `main` shows silent no-args, `Error\n` on stderr for a mid-stream invalid token, and silent valid input. Flag phase verified 2026-09-06: `parse_flags` (new `parse_flags.c`, in Makefile SRCS, prototype in `push_swap.h`) consumes exact `--bench`/selector tokens before the first non-flag token into `bench_enabled`/`strategy`, records the first-integer index via `int *start`, and rejects repeated `--bench`, conflicting selectors, and flags after the numeric boundary. Isolated ten-scenario harness plus a full 18-row stream matrix through the real binary: all valid flag+integer combinations (both bench/selector orders), plain integers, and flags-only runs are silent on both streams; `--bench --bench`, `--simple --adaptive`, `--bench 3 --bench`, `--benchmark`, non-integers, and duplicates print exactly `Error\n` on stderr with exit 0. Learner debugged the `&start` pointer bug (literal `1` passed instead of the address) and the bench/selector guard conflation via the matrix. A Norm-forced refactor (2026-09-06) extracted the five-branch flag dispatch into `static int flag_type`, slimmed `parse_flags` to 22 lines, and re-verified Norm-OK with an identical matrix. `norminette *.c *.h` and strict build remain clean. Range conversion (overflow, `INT_MIN`/`INT_MAX`) remains the sole open parsing row. Duplicate detection verified 2026-09-06 after Norm-forced refactor: `validated_node` walks `a` before allocating, returning NULL on a value match, and `parse_numbers` attaches only validated nodes. Strict build plus stream capture show mid-stream, front, end, adjacent-negative, and zero duplicates each print exactly `Error\n` to stderr with empty stdout and exit 0; single-node, all-unique, and negative-vs-positive controls stay silent. `norminette *.c *.h` is OK and repeated `make` does not relink. Subject confirmed invalid input requires exactly `Error\n` on stderr with no exit-code requirement, so exit 0 on error is acceptable. Range conversion (overflow, `INT_MIN`/`INT_MAX`), duplicates row now passing, and flags remain pending. |
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
| Header boundary | Separate narrow `node.h` beneath `push_swap.h` vs. one project-wide umbrella header | Chose one `push_swap.h` containing node, stack, strategy, context, and all project prototypes; removed `node.h` and made every source include the umbrella. This favors one centralized interface, with the understood consequence that changing it may rebuild every object. | `naamir` |
| Duplicate detection | Walk the already-attached nodes of `a` per token vs. copy values into a temporary sorted array | Walk `a` before each allocation: worst-case n(n−1)/2 value comparisons, zero extra allocation, no new allocation-failure mode, and the duplicate is rejected before its node exists, so cleanup paths stay unchanged. The array approach is deferred until rank assignment can justify its own allocation on its own merits. | `naamir` |
| Flag-phase boundary | Flag-looking tokens after numbers begin treated as invalid integers vs. special-cased anywhere | The flag phase consumes only exact `--bench`/`--simple`/`--medium`/`--complex`/`--adaptive` tokens; the first token that is not one of those exact strings ends the phase, so a later `--bench` after numbers begin is rejected as an invalid integer. `--bench` and one selector may appear in either order before the first integer; repeats and conflicts are invalid. This keeps one deterministic boundary and needs no lookahead. A run whose tokens are only
flags, with no integers following, prints nothing like a no-parameter run;
this is a learner-confirmed reading of the subject's unspecified corner. | `naamir` |
| Simple strategy | Pending | Pending | Pending |
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
Norm (22-line `parse_flags`) |
| Partner pending | None yet |

## Latest Session Handoff

- **Last confirmed achievement:** implemented the reasonable-input numeric
  builder and integrated it into `main`: `parse_numbers` builds `a` left-to-right
  with a parser-local tail and returns status without printing; `main` always
  initializes, parses only when arguments exist, prints `Error\n` to stderr as
  the single error source, and cleans up on every path. The isolated
  five-scenario parser suite and a three-path stream smoke pass strictly, with
  Norminette and no-relink evidence.
- **Open question:** who is the required second learner?
- **Resume with:** the overflow-safe conversion replacing unguarded `ft_atoi`
  in `validated_node` — the sole open parsing row for milestone 2; then rank
  assignment or the operation engine, per the build sequence. Flag phase and
  duplicate detection are both complete and Norm-clean.
