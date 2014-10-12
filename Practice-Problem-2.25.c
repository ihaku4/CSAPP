#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  signed int n = 0xffffff7f;

  printf("%d\n", 0U -1);
  printf("%x\n", 0U -1);
  printf("%x\n", 0 -1);

  // XXX When either operand of a comparison is unsigned, the other operand is implicitly cast to unsigned.
  printf(" %x : 0 <= 0U -1\n", 0 <= 0U -1);
  printf(" %x : 0 <= 0 -1\n", 0 <= 0 -1);
  printf(" %x : 1U - 2U > 0\n", 1U - 2U > 0);
  printf(" %x : 2U - 1U > 0\n", 2U - 1U > 0);
  printf(" %x : (int) (1U - 2U) > 0\n", (int) (1U - 2U) > 0);
  printf(" %x : (int) (2U - 1U) > 0\n", (int) (2U - 1U) > 0);

  return 0;
}
