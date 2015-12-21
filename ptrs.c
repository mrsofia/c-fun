#include <stdio.h>

int main(int argc, char *argv[]) {
  int *p;
  int i = 69;
  p = &i;
  int z = *p;

  printf("value i should be 69, it is:\t %d\n", i);
  printf("p, our pointer, should equal the address of variable i. p is: \t%d\n", p);
  printf("p points to: %d\n", *p);
  printf("z should equal the VALUE stored at pointer p, which is the value at the address p. \nz should equal 69. z is: \t%d\n", z);

  return 0;
}
