#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n = -12340;
  
  printf("%d %d\n", -7/2, -7>>1);
  printf("%x %x\n", -7/2, -7>>1);
  printf("%d\n", -7);
  printf("%x\n", -7);

  printf("%x %d\n", n, n);
  printf("%x %d\n", n>>1, n>>1);
  printf("%x %d\n", n>>4, n>>4);
  printf("%x %d\n", n>>8, n>>8);

  return 0;
}
