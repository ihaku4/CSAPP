#include <stdio.h>
#include <stdlib.h>

int tadd_ok(int x, int y)
{
  return !(
    (x > 0 && y > 0 && x + y <= 0) ||
    (x < 0 && y < 0 && x + y >= 0)
  );
}

int buggy_tsub_ok(int x, int y)
{
  return tadd_ok(x, -y);
}

int main(void)
{
  int n = -1;

  printf("%d %d\n", n , -n);
  printf("%x %x\n", n , -n);
  printf("%u %u\n", n , -n);

  return 0;
}
