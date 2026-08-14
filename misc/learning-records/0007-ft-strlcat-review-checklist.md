# `ft_strlcat` — mastery checklist

## The problem

- [x] Explain what `ft_strlcat` appends and what `dstsize` measures.
- [x] Explain how the function behaves when `dst` is already as long as `dstsize`.
- [x] Predict how many source bytes fit while reserving space for `\0`.

## The solution

- [x] Find the destination length without reading beyond `dstsize`.
- [ ] Append only bytes that fit and NUL-terminate whenever space permits.
- [x] Return the length the combined string tried to have, independently of bytes copied.
- [ ] Handle zero size, no room, partial copy, full copy, and empty strings.
- [ ] Compile with `-Wall -Wextra -Werror` and pass runtime and sanitizer tests.

## Broader context

- [x] Explain how the return value reveals truncation.
- [ ] Explain the precondition that `dst` and `src` must be valid for the accesses made.
