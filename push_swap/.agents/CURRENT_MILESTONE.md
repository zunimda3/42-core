# Current Milestone Implementation Map

## Milestone 5 — Simple O(n²) strategy

Gate: compare viable techniques, choose and justify one, derive an O(n²) generated-
operation upper bound, and eventually pass forced-simple correctness tests.

## Dependency order

- [x] Finish organization cleanup and pass fresh fclean/rebuild plus full Norm.
- [x] Define the future dispatcher contract: `1` means success, `0` means failure;
  the standalone draft remains unintegrated until real strategy targets exist.
- [ ] Compare minimum extraction and insertion-style placement using legal moves.
- [ ] Trace a small input and derive each candidate's operation bound and space use.
- [ ] Record the learner's selected method and rationale.
- [ ] Implement one public simple-strategy entry point with a sorted-input guard.
- [ ] Connect the dispatcher only when real strategy targets make it a useful,
  linkable slice; never use empty strategy stubs.
- [ ] Choose whether to run or defer focused simple-strategy tests.

## Proposed module grouping

- `simple_sort.c`: one public simple-strategy entry point plus cohesive static helpers
  that fit the Norm. Exact helpers remain unknown until the algorithm is chosen.
- `strategy_dispatch.c`: central sortedness guard, effective-strategy resolution,
  and eventual calls to real strategy entry points. It is compiled but not called by
  `main` until its first real strategy target exists.
- `stack_analysis.c`: reuse ranks and `is_sorted`; add nothing unless the chosen
  algorithm exposes a genuinely reusable stack query.
- Strategy-wide dispatch remains deferred until concrete strategies exist; do not
  create placeholder implementations for medium or complex modes.

## Deferred evidence and decisions

- The simple algorithm and helper interfaces are not yet chosen.
- `resolve_strategy` and `run_strategy` are now grouped in `strategy_dispatch.c`.
- Stack helpers are grouped in `stack_utils.c` with the corrected banner; legacy
  files and stale objects are removed.
- Both layer-specific structure is clean; generated tracked binaries remain a later
  Git-hygiene decision.
- The dispatcher uses `int` status so future strategy/allocation failures propagate
  to `main`; its current unsorted `0` branches are non-integrated placeholders.
- Forced-simple edge, patterned, and random correctness tests remain pending.
- Milestone 4 disorder, resolver-boundary, and sortedness tests remain deferred.
