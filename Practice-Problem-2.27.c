#include <stdio.h>
#include <stdlib.h>

int uadd_ok(unsigned x, unsigned y)
{
  return x < x + y;
}

int main(void)
{
  printf("%d\n", uadd_ok(0x1, 0x2));
  printf("%d\n", uadd_ok(0xfffffff1, 0xfffffff2));
  printf("%d\n", uadd_ok(0xfffffff1, 0x2));
  printf("%d\n", uadd_ok(0xfffffff1, 0xe));
  printf("%d\n", uadd_ok(0xfffffff1, 0xf));

  return 0;
}
