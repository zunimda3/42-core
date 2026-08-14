#include <stddef.h>

void *ft_memset(void *b, int c, size_t len) {
  unsigned char *ptr;
  size_t i;

  ptr = (unsigned char *)b;
  i = 0;

  while (i < len) {
    ptr[i] = (unsigned char)c;
    i++;
  }

  return ptr;
}

#ifdef TEST
#include <stdio.h>

int main(void) {
  char buffer[] = "hello";

  ft_memset(buffer, 'X', 3);
  printf("Result: %s\n", buffer);
  return 0;
}
#endif
