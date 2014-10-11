#include <stdio.h>
#include <stdlib.h>
#include "byte-and-bit.h"

#define INT_MAX_1 2147483647
#define INT_MIN_1 -2147483648
#define INT_MIN_2 -2147483647-1
#define INT_MIN_4 (-2147483647-1)
#define INT_MIN_3 (-INT_MAX_1 - 1)

void cast_example()
{
  short sx = -12345; /* -12345 */
  unsigned short usx = sx;/* 53191 */
  int x = sx; /* -12345 */
  unsigned ux = usx; /* 53191 */

  printf("sx = %d:\t", sx);
  show_bytes((byte_pointer) &sx, sizeof(short));
  printf("usx = %u:\t", usx);
  show_bytes((byte_pointer) &usx, sizeof(unsigned short));
  printf("x = %d:\t", x);
  show_bytes((byte_pointer) &x, sizeof(int));
  printf("ux = %u:\t", ux);
  show_bytes((byte_pointer) &ux, sizeof(unsigned));
}

int main(void)
{
  printf("%x %x \n", -2147483647-1, 2147483648U);
  printf("%x %x \n", -2147483647-1, 2147483647);
  printf("%x %x \n", -2147483647-1U, 2147483647);
  printf("%x %x \n", -2147483647-1, -2147483647);
  printf("%x %x \n", -2147483647-1U, -2147483647);

  printf("%d \n", -2147483647-1 == 2147483648U);
  printf("%d \n", -2147483647-1 < 2147483647);
  printf("%d \n", -2147483647-1U < 2147483647);
  printf("%d \n", -2147483647-1 < -2147483647);
  printf("%d \n", -2147483647-1U < -2147483647);

  printf("%d \n", 2147483648);
  printf("%d \n", -2147483648);
  printf("%d \n\n", INT_MIN_1);
  printf("%d \n\n", INT_MIN_2);
  printf("%d \n\n", INT_MIN_3);
  printf("%d \n", 2147483647);
  printf("%d \n", -2147483647);
  printf("%d \n", 2147483647-1);
  printf("%d \n", -2147483647-1);

  printf("%d \n", sizeof(long));
  printf("%d \n", sizeof(int));
  printf("%d \n", sizeof(char));

  printf("\n");
  printf("%d \n", INT_MIN_1 > 0);
  printf("%d \n", INT_MIN_2 > 0);
  printf("%d \n", INT_MIN_3 > 0);
  printf("%d \n", INT_MIN_1 == -INT_MIN_1);
  printf("%d \n", INT_MIN_2 == -INT_MIN_2); // lack (): --123 -1  vs -(-123 -1)
  printf("%d \n", INT_MIN_3 == -INT_MIN_3);
  printf("%d \n", INT_MIN_4 == -INT_MIN_4);

  cast_example();

  return 0;
}
