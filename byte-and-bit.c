#include <stdio.h>
#include "byte-and-bit.h"

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
  int i;

  for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
  printf("\n");
}

void show_bytes_r(byte_pointer start, int len)
{
  int i;

  for (i = len-1; i >= 0; i--)
    printf("      %.2x", start[i]);
  printf("\n");
}

void s_show_bits(byte_pointer start, int len, unsigned char *s)
{
  int i;

  for (i = len-1; i >= 0; i--) {
    s_show_bit(start[i], s + (len-1-i)*8);
  }
}

void show_bits(byte_pointer start, int len)
{
  int i;

  for (i = len-1; i >= 0; i--) {
    //putchar(' ');
    show_bit(start[i]);
  }
  printf("\n");
}

void show_int(int x)
{
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
  int ival = val;
  float fval = (float) ival;
  int *pval = &ival;

  unsigned char s_bit_int[32];
  unsigned char s_bit_float[32];

  show_int(ival);
  show_float(fval);
  show_pointer(pval);

  show_bits((byte_pointer) &ival, sizeof(int));
  show_bytes_r((byte_pointer) &ival, sizeof(int));
  show_bits((byte_pointer) &fval, sizeof(float));
  show_bytes_r((byte_pointer) &fval, sizeof(float));
  show_bits((byte_pointer) &pval, sizeof(void *));
  show_bytes_r((byte_pointer) &pval, sizeof(void *));

  s_show_bits((byte_pointer) &ival, sizeof(int), s_bit_int);
  s_show_bits((byte_pointer) &fval, sizeof(float), s_bit_float);
//  printf("%s\n", s_bit_int);
//  printf("%s\n", s_bit_float);

  int max_shift;
  int max_match;
  int shift, int_i, float_i;
  int match;

  max_shift = 0;
  max_match = 0;
  for (shift = 0; shift < 32; shift++) {
    match = 0;
    if (shift >= 0) {
      int_i = shift;
      float_i = 0;
    } else {
      int_i = 0;
      float_i = -shift;
    }
    for (; int_i < 32 && float_i < 32; int_i++, float_i++) {
      if (s_bit_int[int_i] == s_bit_float[float_i]) {
        match++;
        if (match > max_match) {
          max_match = match;
          max_shift = shift;
        }
      } else {
        match = 0;
      }
    }
  }

  printf("max_shift = %d\n", max_shift);

  if (max_shift < 0) print_space(max_shift);
  print_bits(s_bit_int, 32);
  if (max_shift >= 0) print_space(max_shift);
  print_bits(s_bit_float, 32);
  print_space(32-max_match);
  printf("^\n");
}

void print_space(int n)
{
  while (n--)
    printf(" ");
}

void print_bits(unsigned char *p, int len)
{
  int i;

  for (i = 0; i < len; i++)
    if (p[i])
      printf("1");
    else
      printf("0");
  printf("\n");
}

void s_show_bit(unsigned char x, unsigned char *s)
{
  int i = 8;

  while (i--)
    s[7-i] = x>>i & 0x1;
}

void show_bit(unsigned char x)
{
  int i = 8;

  while (i--)
    printf("%d", x>>i & 0x1);
}
