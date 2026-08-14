# `ft_strchr` completed — mastery checklist

The learner corrected, tested, and explained the `ft_strchr` implementation.

## The problem

- [x] Explain what `ft_strchr` searches for and what it returns.
- [x] Explain why the terminating `\0` must be searchable.
- [x] Explain why the current loop stops too early.

## The solution

- [x] Explain the order in which one loop iteration should check the current byte.
- [x] Correct the missing `NULL` definition and `const` return warning.
- [x] Handle found, not-found, empty-string, and `\0` searches.
- [x] Compile the final simplified loop with `-Wall -Wextra -Werror` and pass the test cases.

## Broader context

- [x] Explain the difference between returning a pointer into the string and returning a character or index.
- [x] Explain what callers may do with the returned pointer and when `NULL` must be checked.

**Evidence:** The final implementation compiled with `-Wall -Wextra -Werror` and passed first-character, middle-character, absent-character, terminator, empty-string terminator, and empty-string absent tests. The learner explained the premature return, searchable terminator, match-before-stop ordering, pointer-to-suffix behavior, and required `NULL` check.
