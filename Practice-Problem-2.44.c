#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int (*calculate_t)(int);
typedef int (*calculate_2_t)(int, int);

int test_A(int x) {
  return (x > 0) || (x-1 < 0);
}

int test_B(int x) {
  return (x & 7) != 7 || (x<<29 < 0);
}

int test_C(int x) {
  return (x * x ) >= 0;
}

int test_D(int x) {
  return x < 0 || -x <= 0;
}

int test_E(int x) {
  return x > 0 || -x >= 0;
}

int test_F(int x, int y) {
  unsigned ux = x;
  unsigned uy = y;

  return x+y == uy+ux;
}

int test_G(int x, int y) {
  unsigned ux = x;
  unsigned uy = y;

  return x*~y + ux*uy == -x;
}

int test_limit_2(calculate_2_t calculate)
{
  int x, y;
  int test_pass = 1;
  int step = 1000000; // TODO need to shrink step for precise result.

  for (y = 0; y >= 0; y+=step) {
    for (x = 0; x >= 0; x+=step) {
      if (!calculate(x, y)) {
        printf("x: %d %x\n", x, x);
        printf("y: %d %x\n", y, y);
        test_pass = 0;
        break;
      }
//      printf("x = %d %x, y = %d %x\n", x, x, y, y);
//      printf("of  %d %x,     %d %x\n", INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    }
    for (x = 0; x <= 0; x-=step) {
      if (!calculate(x, y)) {
        printf("x: %d %x\n", x, x);
        printf("y: %d %x\n", y, y);
        test_pass = 0;
        break;
      }
//      printf("x = %d %x, y = %d %x\n", x, x, y, y);
//      printf("of  %d %x,     %d %x\n", INT_MIN, INT_MIN, INT_MAX, INT_MAX);
    }
//    printf("y = %d %x\n", y, y);
//    printf("    %d %x\n", INT_MAX, INT_MAX);
    if (!test_pass) break;
  }

  for (y = 0; y <= 0; y-=step) {
    for (x = 0; x >= 0; x+=step) {
      if (!calculate(x, y)) {
        printf("x: %d %x\n", x, x);
        printf("y: %d %x\n", y, y);
        test_pass = 0;
        break;
      }
//      printf("x = %d %x, y = %d %x\n", x, x, y, y);
//      printf("of  %d %x,     %d %x\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN);
    }
    for (x = 0; x <= 0; x-=step) {
      if (!calculate(x, y)) {
        printf("x: %d %x\n", x, x);
        printf("y: %d %x\n", y, y);
        test_pass = 0;
        break;
      }
//      printf("x = %d %x, y = %d %x\n", x, x, y, y);
//      printf("of  %d %x,     %d %x\n", INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    }
//    printf("y = %d %x\n", y, y);
//    printf("    %d %x\n", INT_MIN, INT_MIN);
    if (!test_pass) break;
  }
  return test_pass;
}

int test_limit(calculate_t calculate)
{
  int i;
  int test_pass = 1;

  for (i = 0; i >= 0; i++) {
    if (!calculate(i)) {
      printf("%d %x\n", i, i);
      test_pass = 0;
      break;
    }
  }
  for (i = 0; i <= 0; i--) {
    if (!calculate(i)) {
      printf("%d %x\n", i, i);
      test_pass = 0;
      break;
    }
  }
  return test_pass;
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
  puts(test_limit(test_A) ? "\n" : "fail!\n");
  puts("-- start test B ---\n");
  puts(test_limit(test_B) ? "\n" : "fail!\n");
  puts("-- start test C ---\n");
  puts(test_limit(test_C) ? "\n" : "fail!\n");
  puts("-- start test D ---\n");
  puts(test_limit(test_D) ? "\n" : "fail!\n");
  puts("-- start test E ---\n");
  puts(test_limit(test_E) ? "\n" : "fail!\n");
  puts("-- start test F ---\n");
  puts(test_limit_2(test_F) ? "\n" : "fail!\n");
  puts("-- start test G ---\n");
  puts(test_limit_2(test_G) ? "\n" : "fail!\n");

  return 0;
}
