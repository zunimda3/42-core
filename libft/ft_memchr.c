#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n) {
  const unsigned char *src;
  size_t i;
  i = 0;
  src = s;

  while (i < n) {
    if (src[i] == (unsigned char)c) {
      return (void *)(src + i);
    }
    i++;
  }

  return NULL;
}
