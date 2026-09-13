# Current Milestone Implementation Map

## Milestone 8 — Adaptive strategy

Gate: initial disorder selects the required internal method at the exact boundaries;
forced modes remain unchanged, benchmark reporting is truthful, and focused regime
tests pass.

## Dependency order

- [x] Compute and save disorder before rank assignment or generated moves.
- [x] Preserve forced selectors through a pure resolver.
- [x] Map adaptive `< 0.2` to simple, `< 0.5` to medium, and the rest to complex.
- [x] Explain that exact `0.20` selects medium and exact `0.50` selects complex.
- [x] Explain forced pass-through versus adaptive resolution at the same disorder.
- [x] Explain why the requested strategy must not be overwritten by the effective
  method.
- [x] Dispatch the existing simple and medium methods.
- [x] Place conditional benchmark reporting inside `prepare_and_sort` after
  successful strategy execution.
- [x] Choose `void print_benchmark(const t_context *ctx)` as the reporter interface.
- [x] Explain direct-field protection through the `const t_context *` parameter.
- [x] Choose narrow benchmark-local numeric helpers over adapting `ft_printf`.
- [x] Begin `bench.c` with the private recursive writer and public total reporter;
  standalone strict compilation and Norm pass.
- [x] Correct the emitted digit storage to one `char`; strict standalone compilation
  and Norm pass.
- [x] Explain the one-byte `write` contract; focused full-width/stderr harness
  explicitly deferred.
- [x] Draft scaled disorder output with whole/fractional separation and zero padding.
- [x] Extract `print_disorder`, round with `+ 0.5`, and emit the `%` suffix.
- [x] Move the scaled calculation before its first read; strict standalone
  compilation and Norm pass.
- [x] Draft requested-strategy name and effective-complexity reporting.
- [x] Call the strategy helper, branch on the resolved enum, and correct separator
  spacing; strict standalone compilation and Norm pass.
- [x] Draft the correct label-to-enum mapping for all 11 operation counts.
- [x] Complete the fifth/final helper's enum-indexed two-line output loop, keep it
  private, and call it after `total_ops`; strict standalone compilation and Norm pass.
- [ ] Learner explains the enum/label mapping and two-line boundary invariant.
- [ ] Declare, build, and conditionally call the completed reporter.
- [ ] Integrate the second learner's complex method into the high-disorder branch.
- [ ] Report the requested/effective adaptive strategy truthfully in benchmark mode.
- [ ] Run exact-boundary, forced-mode, stream, and regime correctness tests.
- [ ] Document the threshold rationale and internal complexity/space bounds.

## Expected interface and grouping

- Existing `resolve_strategy(t_strategy, double)` is pure and returns the effective
  method without mutating the requested strategy.
- Existing `run_strategy(t_context *)` resolves after disorder capture and dispatches
  simple/medium; complex currently follows the failure return.
- Benchmark reporter uses one read-only context and resolves the effective method
  from its retained requested strategy plus initial disorder.
- Active `bench.c` grouping: a full-width `size_t` writer, disorder formatter,
  strategy/class formatter, metric-loop formatter, and public reporter (five
  functions). The first writer/reporter slice exists but is not integrated.
- The learner's external `ft_printf` is allowed but currently writes only to fd 1
  and lacks `%f`/`%zu`; unchanged reuse is incompatible with benchmark requirements.
- Confirmed: retain narrow local stderr formatting helpers; do not import or expand
  the earlier formatter.
- The previously observed untracked `ft_printf/` copy is no longer present; the
  assistant did not remove it.
- Keep resolution and dispatch cohesive in `strategy_dispatch.c`; no new adaptive
  source file is currently justified.

## Deferred evidence and paused work

- Complex implementation is provisionally assigned to the second learner, whose
  identity and contribution remain unconfirmed; Milestone 7 stays `LEARNING`.
- Simple and medium correctness/scaling harnesses remain learner-deferred; Milestones
  5 and 6 stay `VERIFYING`.
- Benchmark full-width counter and stderr-output evidence is learner-deferred.
- Milestone 4 analysis/resolver/sortedness tests and earlier operation/rank tests also
  remain deferred.
