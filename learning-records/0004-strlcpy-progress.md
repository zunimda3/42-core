# `ft_strlcpy` covered

The learner has now covered `ft_strlcpy`, including its bounded-copy contract:

- copy at most `dstsize - 1` characters;
- NUL-terminate when `dstsize > 0`;
- copy nothing when `dstsize == 0`;
- return the full source length.

The mandatory Libft progress is now 9 of 24 functions covered, with 15 remaining. `ft_strlcat` was selected next, but the learner chose to defer it. The next active exercise is `ft_strchr`; `ft_strlcat` remains incomplete and must be revisited later.

**Evidence:** The learner corrected the `size_t` types and source-termination condition, and the implementation compiled successfully with strict warning flags.
