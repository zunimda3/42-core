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
- **Next small step:** design and implement validation/conversion of one integer
  token before allocation, covering syntax and signed-`int` bounds independently of
  full argv parsing.
- **Paused design question:** operation metrics and emission remain undecided until
  the operation engine is the next implementation dependency.
- **Outstanding team requirement:** the subject requires exactly two learners, but a
  partner has not yet been confirmed; this does not block architecture learning.

## Current Repository Baseline

Observed on 2026-09-05:

- Present source work uses `push_swap.h` as a single umbrella plus three specialized
  stack helpers; the learner removed obsolete `node.h` and `ft_lstiter.c`.
- The Makefile and temporary `main(void)` now complete the minimal build shell. A
  fresh strict build, silent no-argument run, no-relink check, required cleanup
  rules, `re`, and Norminette all produced successful evidence pending learner
  interpretation before entry in the Verification Matrix.
- `push_swap.h` intentionally defines the stack, strategy, context, and helper
  declarations as the project's single umbrella header; all sources include it.
- `context_init.c` initializes all confirmed fields, and `main` performs safe cleanup.
  Focused assertions and ASan/UBSan pass with leak detection disabled, pending learner
  interpretation. The Makefile now tracks `push_swap.h` for every object; a temporary
  copy confirmed a newer umbrella header rebuilds all objects and relinks.
- `push_swap.h` defines typed `value`, `rank`, and `next` node fields plus a stack
  wrapper with authoritative `top` and `size`.
- Missing major deliverables: parser, operations, strategies, benchmark mode,
  Makefile, and README.
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
| 2 | Build, parsing, and lifetime | `NOT STARTED` | Required Makefile rules work without relinking; valid inputs build `a`; all invalid-input families print only `Error\n` to stderr; every error path frees memory. |
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
| Build | `all`, repeated `all`, `clean`, `fclean`, `re`; required flags | Minimal shell passes fresh strict build; no-argument run exits 0 with empty stdout/stderr; repeated `make` reports nothing to do and preserves the binary timestamp; `clean` retains only the binary, `fclean` removes it, and `re` rebuilds. Umbrella-header dependencies are explicit; a temporary-copy probe showed a newer header rebuilds every object and then relinks. Learner explained both timestamp comparisons. |
| Parsing | no args, one integer, signs, `INT_MIN/MAX`, overflow, non-number, empty token, duplicates, invalid/conflicting flags | Pending |
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
| Stack helper interface | Keep generic traversal helpers vs. retain only helpers required by the stack abstraction | Removed `ft_lstlast` and `ft_lstsize`: no current operation requires the former, while the latter would duplicate the authoritative `t_stack.size`. The minimal interface currently contains node creation, add-to-top, and cleanup. | `naamir` |
| Input and flag grammar | Strict flags-before-integers grammar vs. accepting flags anywhere | Use `push_swap [--bench] [one strategy selector] integers...`: all flags precede the first integer; `--bench` may combine with one selector; repeated flags, conflicting selectors, or a flag after integer parsing begins are invalid; adaptive is the default selector; no arguments print nothing. This is deterministic and keeps parsing state simple. | `naamir` |
| Parser ownership contract | Parser cleans partial state vs. caller owns one initialized context for the whole run | `main` owns the context and always clears stack `a`; the parser transfers each allocated node immediately into `a`, returns status without printing, and may leave an owned partial stack on failure. `main` performs cleanup and is the single source of `Error\n` output. This keeps allocation ownership and error output centralized. | `naamir` |
| Input node construction order | Insert each argument at the top vs. append each argument at the bottom; parser-local tail vs. persistent stack tail | Chose left-to-right bottom insertion with a parser-local tail so the first integer remains the top of `a`, construction is O(n), and `t_stack` keeps only its existing `top` and `size` invariants. Parser work does not count as generated Push_swap operations. | `naamir` |
| Persistent run-state organization | One program context vs. separate stack, option, disorder, and metrics objects | Chose one caller-owned context to carry both stacks, the selected strategy, benchmark state, initial disorder, and operation counters across parsing, sorting, reporting, and cleanup. This centralizes lifetime and avoids globals. | `naamir` |
| Strategy representation | Retain the selector string vs. parse once into an enum | Store a `t_strategy` enum in the context, initialized to adaptive before parsing. Valid selectors replace that value, so sorting happens only after complete successful parsing and can dispatch without repeated string comparisons. | `naamir` |
| Header boundary | Separate narrow `node.h` beneath `push_swap.h` vs. one project-wide umbrella header | Chose one `push_swap.h` containing node, stack, strategy, context, and all project prototypes; removed `node.h` and made every source include the umbrella. This favors one centralized interface, with the understood consequence that changing it may rebuild every object. | `naamir` |
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
| `naamir` | Initial linked-list exploration; compared representations and selected a specialized singly linked node plus stack wrapper with explicit ownership invariants; drafted the specialized types in `node.h`; implemented `ft_lstadd_top` to update both `top` and `size`; initialized new nodes with unassigned rank `-1`; implemented stack cleanup that frees all nodes and resets both invariants; removed redundant traversal helpers to keep `t_stack.size` authoritative; selected the strict flags-before-integers input grammar, caller-owned parser lifetime contract, O(n) left-to-right bottom insertion using a parser-local non-owning tail, a single caller-owned program context, an adaptive-default strategy enum, and a separate `push_swap.h` program-level header over narrow `node.h`; explained that stack `a`, not the local alias, retains ownership after parsing; implemented and verified the minimal `main.c` and Makefile build shell |
| Partner pending | None yet |

## Latest Session Handoff

- **Last confirmed achievement:** verified context initialization and the corrected
  umbrella dependency, explaining the header-to-object and object-to-binary timestamp
  chain that triggers recompilation and relinking.
- **Open question:** who is the required second learner?
- **Resume with:** compare safe single-token conversion approaches, choose one, and
  test exact signed-`int` boundaries before integrating argv or allocations.
