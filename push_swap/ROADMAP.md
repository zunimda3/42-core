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

- **Milestone:** 1 — interface and architecture decisions
- **Status:** `IMPLEMENTING`
- **Next small step:** identify the minimum caller-owned context fields and explain
  why each must persist beyond the parser call.
- **Outstanding team requirement:** the subject requires exactly two learners, but a
  partner has not yet been confirmed; this does not block architecture learning.

## Current Repository Baseline

Observed on 2026-09-01:

- The `push_swap/` directory is entirely untracked in its parent Git repository.
- Present source work: six linked-list helpers and `node.h` using a generic
  `void *content` node.
- Missing major deliverables: `main`, parser, operations, strategies, benchmark mode,
  Makefile, and README.
- `cc`, `make`, and `norminette` are available.
- Valgrind and a checker binary are not currently available; compiler sanitizers can
  provide interim memory diagnostics.
- Current sources pass syntax-only compilation with `-Wall -Wextra -Werror`.
- `ft_lstnew.c` currently has one Norm error: its return value needs parentheses.
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
| Build | `all`, repeated `all`, `clean`, `fclean`, `re`; required flags | Pending |
| Parsing | no args, one integer, signs, `INT_MIN/MAX`, overflow, non-number, empty token, duplicates, invalid/conflicting flags | Pending |
| Operations | each operation on empty, one-node, two-node, and ordinary stacks; combined-operation semantics | Pending |
| Disorder | sorted = 0, reverse = 1, known intermediate inputs, fewer than two elements, boundaries 0.2 and 0.5 | Pending |
| Streams | stdout contains only operations; errors and bench output use stderr; no bench text without `--bench` | Pending |
| Strategies | every selector on small, sorted, reverse, patterned, and random unique inputs | Pending |
| Metrics | total equals the sum of all 11 counters and matches stdout operation lines | Pending |
| Quality | `-Wall -Wextra -Werror`, Norm, sanitizer/Valgrind, no leaks or invalid access | Pending |
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
| `naamir` | Initial linked-list exploration; compared representations and selected a specialized singly linked node plus stack wrapper with explicit ownership invariants; drafted the specialized types in `node.h`; implemented `ft_lstadd_top` to update both `top` and `size`; initialized new nodes with unassigned rank `-1`; implemented stack cleanup that frees all nodes and resets both invariants; removed redundant traversal helpers to keep `t_stack.size` authoritative; selected the strict flags-before-integers input grammar and caller-owned parser lifetime contract |
| Partner pending | None yet |

## Latest Session Handoff

- **Last confirmed achievement:** correctly traced partial-parse cleanup and explained
  that freeing a node after transferring it into stack `a` would leave `main` to
  traverse and free the same allocation again.
- **Open question:** who is the required second learner?
- **Resume with:** teach the difference between transient parser locals and persistent
  program state, then have the learner propose the minimum context fields.
