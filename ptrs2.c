#include <stdio.h>

int main(int argc, char *argv[]) {
  // local variables are not initialized, they can be ANYTHING
  // technically they will be whatever was last in that memory
  // think of it like malloc() - just gives you memory, doesn't
  // set the existing space to zero, depends on you to initialize
  // the variable before doing anything with it.
  int *ptr, a;
  a = 5;
  // the value in pointer up till now has just been equal to
  // whatever bits were there before.
  ptr = &a;
  *ptr = 69;
  // now the bits in pointer will equal the address of a.
  // now we can do other things - whatever we want - with *ptr,
  // as we now know what it is.

  // if you're not careful, you will override data in bad places.
  // like the following (assumes no initialization):
  // *ptr = 5;
  // since ptr wasn't initialized, ptr was holding some bits.
  // we don't know what the bits were or why there were there,
  // all we know is that there is a number there, C will read
  // it as an address, and C will find that address, and write
  // 5 at wherever the address points to.

  printf("a equals %d\n", a);
  printf("ptr points to %d\n", *ptr);

  return 0;
}
