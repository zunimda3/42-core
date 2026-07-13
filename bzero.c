#include <stddef.h>
#include <stdio.h>
#include <string.h>

void ft_bzero(void *s, size_t n);

void ft_bzero(void *s, size_t n) {
  if (n != 0) {
    unsigned char *ptr;
    size_t i;
    ptr = s;
    i = 1;
    while (i < n) {
      ptr[i] = (unsigned char)0;
      i++;
    }
  }
}

int main(void) {
  char str[] = "naim";
  printf("%s\n", str);
  ft_bzero(str, 2);
  printf("%s\n", str);
}

#ifdef TEST
#include <stdio.h>

static void print_bytes(const unsigned char *buffer, size_t len) {
  size_t i = 0;

  while (i < len) {
    printf("%02x ", buffer[i]);
    i++;
  }
  printf("\n");
}

int main(void) {
  char buffer[] = "hello";

  printf("Before: ");
  print_bytes((unsigned char *)buffer, sizeof(buffer) - 1);
  ft_bzero(buffer, 3);
  printf("After:  ");
  print_bytes((unsigned char *)buffer, sizeof(buffer) - 1);
  return 0;
}
#endif
