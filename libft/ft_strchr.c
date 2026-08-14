#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
  int i;
  i = 0;
  while (1)
  {
    if (s[i] == (char)c)
      return (char *)(s + i);
    else if (s[i] == '\0')
      return NULL;
    i++;
  }
}
