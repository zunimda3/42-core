#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
  size_t i;
  size_t len;
  i = 0;
  len = 0;

  while (dst[len] && len < dstsize) {
    len++;
  }

  while (len + i + 1 < dstsize && src[i]) {
    dst[len + i] = src[i];
    i++;
  }

  if (len + i < dstsize) {
    dst[len + i] = '\0';
    return (dstsize + i);
  }

  return (dstsize + i);
}
