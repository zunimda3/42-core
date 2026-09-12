# Current Milestone Implementation Map

## Milestone 6 — Medium O(n√n) strategy

Gate: compare viable methods, choose and justify one, derive an O(n√n) generated-
operation bound, and eventually pass forced-medium correctness and scaling tests.

## Dependency order

- [ ] Compare rank chunks with block/bucket placement using legal operations.
- [ ] Trace a small example and explain the stack order being maintained.
- [ ] Derive the generated-operation bound and auxiliary-space cost.
- [ ] Record the learner's chosen method and rationale.
- [ ] Decide the public entry point and cohesive file grouping.
- [ ] Implement and connect the real medium dispatcher target.
- [ ] Choose whether to run or defer focused medium tests.

## Expected interfaces and grouping

- One public medium-strategy function taking `t_context *`; name and return type stay
  open until allocation/failure needs are known.
- Reuse fixed ranks and existing operation wrappers.
- Do not add a medium source file until the method and its helper needs are chosen.
- Keep `strategy_dispatch.c` as the central selection point.

## Deferred evidence and decisions

- Medium method, helpers, bounds, and extra storage are undecided.
- Milestone 5's focused simple-strategy harness remains learner-deferred.
- Milestone 4 analysis/resolver/sortedness tests and earlier operation/rank tests also
  remain deferred.
