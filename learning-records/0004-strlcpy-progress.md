# `ft_strlcpy` covered

The learner has now covered `ft_strlcpy`, including its bounded-copy contract:

- copy at most `dstsize - 1` characters;
- NUL-terminate when `dstsize > 0`;
- copy nothing when `dstsize == 0`;
- return the full source length.

The mandatory Libft progress is now 9 of 24 functions covered, with 15 remaining. The next function is `ft_strlcat`.

**Evidence:** The learner corrected the `size_t` types and source-termination condition, and the implementation compiled successfully with strict warning flags.
