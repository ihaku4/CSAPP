#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x = -1;
  unsigned u = 2147483648;
  unsigned u2 = 4294967295;
  
  printf("x = %u = %d = 0x%x\n", x, x, x);
  printf("x = %u = %d = 0x%x\n", u, u, u);
  printf("x = %u = %d = 0x%x\n", u2, u2, u2);

  return 0;
}
