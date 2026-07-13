#include <stddef.h>
#include <stdio.h>

void *ft_memcpy(void *dst, const void *src, size_t n) {
  unsigned char *dest;
  const char *source;
  size_t i;

  dest = dst;
  source = src;
  i = 0;

  while (i < n) {
    dest[i] = source[i];
    i++;
  }

  return dst;
}

int main(void) {
  char dst[] = "xxxxx";
  char src[] = "hello";

  printf("Before: %s\n", dst);
  ft_memcpy(dst, src, 3);
  printf("After:  %s\n", dst);
  return (0);
}
