#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *ft_memccpy(void *dst, const void *src, int c, size_t n) {
  unsigned char *d;
  const unsigned char *s;
  size_t i;
  int match;

  d = dst;
  s = src;
  i = 0;
  match = 0;

  while (i < n) {
    d[i] = s[i];
    if (s[i] == (unsigned char)c)
      return (d + i + 1);
    i++;
  }
  return NULL;
}

int main(void) {
  char dst[] = "xxxxx";
  char src[] = "hello";

  printf("Before: %s\n", dst);
  ft_memccpy(dst, src, 'l', 5);
  printf("After:  %s\n", dst);
  memccpy(dst, src, 'l', 5);
  printf("After using ORG:  %s\n", dst);
  return (0);
}
