#include <stdio.h>
#include <stdlib.h>

int fun1(unsigned word)
{
  return (int) ((word << 24) >> 24);
}

int fun2(unsigned word)
{
  return ((int) word << 24) >> 24;
}

void print_result(unsigned word)
{
  printf("0x%.8x 0x%.8x 0x%.8x\n", word, fun1(word), fun2(word));
}

int main(void)
{
  int i;
  unsigned test_data[4] = {
    0x00000076,
    0x87654321,
    0x000000c9,
    0xedcba987,
  };

  for (i = 0; i < 4; i++)
    print_result(test_data[i]);

  return 0;
}
