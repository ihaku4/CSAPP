#include <stdio.h>
#include "byte-and-bit.h"

#define LENGTH 4

int main(void)
{
  int i;
  unsigned char x[LENGTH] = {0xc3, 0x75, 0x87, 0x66};
  unsigned char x_cp;
  unsigned char bit_c[LENGTH][32];

  for (i = 0; i < LENGTH; i++) {
    printf("0x%x ", x[i]);
    show_bits(x+i, sizeof(unsigned char));

    x_cp = x[i] << 3;
    printf("0x%x ", x_cp);
    show_bits(&x_cp, sizeof(unsigned char));
    x_cp = x[i] >> 2;
    printf("0x%x ", x_cp);
    show_bits(&x_cp, sizeof(unsigned char));

    putchar('\n');
  }

  return 0;
}
