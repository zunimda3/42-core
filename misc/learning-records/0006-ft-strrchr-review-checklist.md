# `ft_strrchr` completed — mastery checklist

The learner corrected, tested, and explained the `ft_strrchr` implementation.

## The problem

- [x] Explain how `ft_strrchr` differs from `ft_strchr`.
- [x] Explain why `\0` remains searchable.
- [x] Explain what value represents “no match found yet.”

## The solution

- [x] Explain why matches are recorded instead of returned immediately.
- [x] Ensure every local variable is initialized before it is read.
- [x] Handle repeated, first, absent, terminator, and empty-string cases.
- [x] Compile with `-Wall -Wextra -Werror` and pass the final runtime suite.

## Broader context

- [x] Explain why reading an uninitialized local variable is undefined behavior.
- [x] Explain what the returned pointer represents and when callers must check `NULL`.

**Evidence:** The final implementation compiled with optimization and `-Wall -Wextra -Werror`, passed repeated, first-only, absent, terminator, and empty-string cases, and passed AddressSanitizer and UndefinedBehaviorSanitizer. The learner explained last-match pointer replacement, terminator handling, uninitialized-local behavior, pointer-to-suffix output, and the caller's required `NULL` check.
