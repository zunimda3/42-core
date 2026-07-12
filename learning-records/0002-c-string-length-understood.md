# C string length and the NUL terminator

The learner correctly explained that `ft_strlen` counts characters up to the terminating `\0`, and does not count the `\0` itself. They implemented and compiled `ft_strlen` with the required `size_t` return type, `const char *` input, and `size_t` counter, passing empty, ordinary, and spaced-string tests.

**Evidence:** Completed implementation and accurate explanation of why `"cat"` has length 3 despite requiring four bytes of storage.

**Implications:** The next lesson can introduce a small character-classification function without reteaching NUL-terminated string length.
