#include <stdio.h>

int main(void)
{
  const unsigned char mask = 0x7;

  unsigned char red = 0x4;
  unsigned char green = 0x2;
  unsigned char blue = 0x1;

  unsigned char black =      0   |  0     |  0;
  unsigned char cyan =       0   |  green |  blue;
  unsigned char magenta =    red |  0     |  blue;
  unsigned char yellow =     red |  green |  0;
  unsigned char white =      red |  green |  blue;

  unsigned char color = ~cyan & mask;
  printf("%x\n", color);
  printf("%x\n", yellow);
  printf("%x\n", cyan);
  printf("%x\n", blue | green);
  printf("%x\n", yellow & cyan);
  printf("%x\n", red ^ magenta);

  printf("%x\n", ~0xff);

  int i = 0x12345678;
  unsigned char c = 0xff;
  unsigned char *p = &i;
  //unsigned int *p = &i;
  printf("%x\n", (int) *p);
  /* 
  switch (color) {
    case black:
      printf("black");
      break;
    case cyan:
      printf("cyan");
      break;
    case magenta:
      printf("magenta");
      break;
    case yellow:
      printf("yellow");
      break;
    case white:
      printf("white");
      break;
  }
  */

  return 0;
}
