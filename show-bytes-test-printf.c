#include <stdio.h>

// ? XXX why unsigned char matters
//typedef char *byte_pointer;
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
  int i;

  for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
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

int main(void)
{
  char *p = 432432;
  int i = 32432;
  p = &i;

  show_int(124);
  show_float(12.4);
  show_pointer(&i);

  char c = 0xff;
  //char c = 0x7f;
  unsigned char uc = 0xff;
  unsigned int un = 0xff;
  int n = 0xff;

  // ? XXX why unsigned char matters
  printf("%x  <------- char \n", c);
  printf("%x  <------- unsigned char \n", uc);
  printf("%d  <------- char \n", c);
  printf("%d  <------- unsigned char \n", uc);

  printf("%x\n", n);
  printf("%x\n", un);
}
