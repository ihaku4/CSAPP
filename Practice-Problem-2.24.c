#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  signed int n = 0xffffff7f;
  signed int n2 = 0xffffff8f;
  char c;

  printf("n = %d, n2 = %d\n", n, n2);
  c = (char) n;
  printf("n = %d, after truncate to 1 byte\n", c);
  c = (char) n2;
  printf("n2 = %d, after truncate to 1 byte\n", c);

  return 0;
}
