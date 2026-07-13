#include <stddef.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize) {
  size_t i;
  size_t len;
  i = 0;
  len = 0;

  while (src[len]) {
    len++;
  }

  if (dstsize == 0) {
    return len;
  } else {
    while (i < dstsize - 1 && src[i] != '\0') {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
    return len;
  }
}
