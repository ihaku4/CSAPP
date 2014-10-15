#include <stdio.h>
#include <stdlib.h>

int div16(int x)
{
  int k = 4;
  return (x<0 ? x+(1<<k)-1 : x) >> k;
}

int main(void)
{
  printf("%d\n", div16(-12345600));
  printf("%d\n", (-12345600/16));
  printf("%d\n", div16(-12340));
  printf("%d\n", (-12340/16));
  printf("%d\n", div16(17));
  printf("%d\n", (17/16));

  return 0;
}
