#include <stdio.h>
#include <stdlib.h>

int tadd_ok(int x, int y)
{
  return !(
    (x > 0 && y > 0 && x + y <= 0) ||
    (x < 0 && y < 0 && x + y >= 0)
  );
}

int buggy_tadd_ok(int x, int y)
{
  int sum = x+y;
  return (sum-x == y) && (sum-y == x);
}

int main(void)
{
  printf("%d : 1, 2\n", tadd_ok(1, 2));
  printf("%d : 0x7fffffff, 0x7fffffff\n", tadd_ok(0x7fffffff, 0x7fffffff));
  printf("%d : 0x40000000, 0x40000000\n", tadd_ok(0x40000000, 0x40000000));
  printf("%d : 0x40000000, 0x3fffffff\n", tadd_ok(0x40000000, 0x3fffffff));
  printf("%d : 0x40000000, 0x3ffffffe\n", tadd_ok(0x40000000, 0x3ffffffe));

  printf("%d : -1, -2\n", tadd_ok(-1, -2));
  printf("%d : 0x80000000, 0x80000000\n", tadd_ok(0x80000000, 0x80000000));
  printf("%d : 0xc0000000, 0xc0000000\n", tadd_ok(0xc0000000, 0xc0000000));
  printf("%d : 0xc0000000, 0xc0000001\n", tadd_ok(0xc0000000, 0xc0000001));
  printf("%d : 0xc0000000, 0xbfffffff\n", tadd_ok(0xc0000000, 0xbfffffff));

  printf("%d : 0xc0000000, 0\n", tadd_ok(0xc0000000, 0));
  printf("%d : 0x7fffffff, 0xc0000000\n", tadd_ok(0x7fffffff, 0xc0000000));

  printf("----------- buggy function test\n");
  printf("%d : 1, 2\n", buggy_tadd_ok(1, 2));
  printf("%d : 0x7fffffff, 0x7fffffff\n", buggy_tadd_ok(0x7fffffff, 0x7fffffff));
  printf("%d : 0x40000000, 0x40000000\n", buggy_tadd_ok(0x40000000, 0x40000000));
  printf("%d : 0x40000000, 0x3fffffff\n", buggy_tadd_ok(0x40000000, 0x3fffffff));
  printf("%d : 0x40000000, 0x3ffffffe\n", buggy_tadd_ok(0x40000000, 0x3ffffffe));

  printf("%d : -1, -2\n", buggy_tadd_ok(-1, -2));
  printf("%d : 0x80000000, 0x80000000\n", buggy_tadd_ok(0x80000000, 0x80000000));
  printf("%d : 0xc0000000, 0xc0000000\n", buggy_tadd_ok(0xc0000000, 0xc0000000));
  printf("%d : 0xc0000000, 0xc0000001\n", buggy_tadd_ok(0xc0000000, 0xc0000001));
  printf("%d : 0xc0000000, 0xbfffffff\n", buggy_tadd_ok(0xc0000000, 0xbfffffff));

  printf("%d : 0xc0000000, 0\n", buggy_tadd_ok(0xc0000000, 0));
  printf("%d : 0x7fffffff, 0xc0000000\n", buggy_tadd_ok(0x7fffffff, 0xc0000000));

  return 0;
}
