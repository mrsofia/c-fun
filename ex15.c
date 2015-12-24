#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for(i = 0; i < count; i++) {
    printf("%s has %d years alive.\n",
            *(names+i), *(ages+i));
  }

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names;

  // second way using pointers
  for(i = 0; i < count; i++) {
    printf("%s if %d years old.\n",
            *(cur_name+i), *(cur_age+i));
  }

  printf("---\n");

  // third way, pointers are just arrays
  for(i = 0; i < count; i++) {
    printf("%s is %d years old again.\n",
            cur_name[i], cur_age[i]);
  }

  printf("---\n");

  for(cur_name = names, cur_age = ages;
        (cur_age - ages) < count;
        cur_name++, cur_age++)
  {
    printf("%s lived %d years so far.\n",
            *cur_name, *cur_age);
  }

  for (i = 0; i < count; i++) {
    // prints 4 because int is 4 bytes on my system
    printf("*(ages+i)is %d, address of *(ages+i) is %p.\n", *(ages+i), (ages+i));
  }
  for (i = 0; i < count; i++) {
    // prints 8 because names[i] is an 64-bit (8 byte) pointer
    printf("sizeof names is %lu.\n", sizeof(names[i]));
    printf("*(names+i) is %s, address of *(names+i) is %p.\n", *(names+i), (names+i));
  }
}
