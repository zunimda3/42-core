# Current Milestone Implementation Map

## Milestone 5 — Simple O(n²) strategy

Gate: compare viable techniques, choose and justify one, derive an O(n²) generated-
operation upper bound, and eventually pass forced-simple correctness tests.

## Dependency order

- [ ] Compare minimum extraction and insertion-style placement using legal moves.
- [ ] Trace a small input and derive each candidate's operation bound and space use.
- [ ] Record the learner's selected method and rationale.
- [ ] Implement one public simple-strategy entry point with a sorted-input guard.
- [ ] Integrate forced `--simple` execution without pretending other strategies exist.
- [ ] Choose whether to run or defer focused simple-strategy tests.

## Proposed module grouping

- `simple_sort.c`: one public simple-strategy entry point plus cohesive static helpers
  that fit the Norm. Exact helpers remain unknown until the algorithm is chosen.
- `stack_analysis.c`: reuse ranks and `is_sorted`; add nothing unless the chosen
  algorithm exposes a genuinely reusable stack query.
- Strategy-wide dispatch remains deferred until concrete strategies exist; do not
  create placeholder implementations for medium or complex modes.

## Deferred evidence and decisions

- The simple algorithm and helper interfaces are not yet chosen.
- Forced-simple edge, patterned, and random correctness tests remain pending.
- Milestone 4 disorder, resolver-boundary, and sortedness tests remain deferred.
