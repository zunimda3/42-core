# Current Milestone Implementation Map

## Milestone 6 — Medium O(n√n) strategy

Gate: compare viable methods, choose and justify one, derive an O(n√n) generated-
operation bound, and eventually pass forced-medium correctness and scaling tests.

## Dependency order

- [x] Compare rank chunks with block/bucket placement using legal operations.
- [x] Trace a small example and explain the stack order being maintained
  (7-value trace; `b` ends chunk-ordered: descending between chunks, arbitrary
  within).
- [x] Choose the restoration mechanism: highest remaining rank to the top of `b`,
  then `pa`, proceeding downward.
- [x] Implement the private restoration helper (Norm-clean; not yet called or
  integrated).
- [ ] Derive the full generated-operation bound.
- [x] Record the learner's chosen method and rationale.
- [x] Decide the public entry point and cohesive grouping: `void run_medium` plus
  four private helpers in `medium.c` (five functions total).
- [x] Implement the standalone medium module; strict compilation and Norm pass.
- [x] Declare, build, and connect the real medium dispatcher target; strict build
  and targeted Norm checks pass.
- [x] Focused medium tests explicitly deferred by the learner.

## Expected interfaces and grouping

- One public `void run_medium(t_context *ctx)`; it has no allocation/failure path.
- Nearest-member lookup requires that the requested rank/range exists; missing-rank
  propagation is intentionally outside the valid internal contract.
- Reuse fixed ranks and existing operation wrappers.
- Do not add a medium source file until the method and its helper needs are chosen.
- Keep `strategy_dispatch.c` as the central selection point.

## Deferred evidence and decisions

- Method chosen: forward-only rank-chunk scanning (`pb` for a member, otherwise
  `ra`), followed by highest-rank-first restoration using `rb`/`rrb` and `pa`.
  The full bound remains open.
- Milestone 5's focused simple-strategy harness remains learner-deferred.
- Milestone 6's focused medium correctness harness is also learner-deferred.
- Milestone 4 analysis/resolver/sortedness tests and earlier operation/rank tests also
  remain deferred.
