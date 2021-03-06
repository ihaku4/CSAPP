#include <stdio.h>
#include <stdlib.h>

typedef int (*calculate_t)(int);

int test_G(int x, int y) {
  unsigned ux = x;
  unsigned uy = y;

  return x*~y + ux*uy == -x;
}

int test_A(int x) {
  return (x > 0) || (x-1 < 0);
}

void test_limit(calculate_t calculate)
{
  int i;

  for (i = 0; i <= 0x7fffffff; i++) {
    if (!calculate(i)) {
      printf("%d %x\n", i, i);
      break;
    }
  }
  for (i = 0; i >= 0x80000000; i--) {
    if (!calculate(i)) {
      printf("%d %x\n", i, i);
      break;
    }
  }
}

int main(void)
{
  int x = 12344;
  int y = -232434;
  unsigned ux = x;
  unsigned uy = y;
  int i;

  printf("%d : 0x80000000\n", 0x80000000);
  printf("%d : -0x80000000\n", -0x80000000);
  printf("%d : 0x80000001\n", 0x80000001);
  printf("%d : -0x80000001\n", -0x80000001);
  printf("%d : -0x80000001\n", -0x80000001);
  printf("%d : ~0x80000000\n", ~0x80000000);
  printf("%d : ~3\n", ~3);
  printf("%d : ~-3\n", ~-3);
  printf("%d : x+y == ux+uy\n", x+y == ux+uy);
  printf("%d : x*~y + ux*uy == -x\n", x*~y + ux*uy == -x); // because of two's complement.? ~y => -y-1

  for (i = 1; 1; i++)
    if (i*i < 0) {
      printf("%d %x ; %d %x\n", i, i, i*i, i*i);
      printf("%d %x ; %d %x\n", i-1, i-1, (i-1)*(i-1), (i-1)*(i-1));
      break;
    }

  puts("-- start test A ---\n");
  test_limit(test_A);

  return 0;
}
