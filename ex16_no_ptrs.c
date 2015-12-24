#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assert imports assert statement
// stdlib imports free in this program
// string imports strdup in this program

struct Person {
  // name points to the first char in the name array
  char *name;
  int age;
  int height;
  int weight;
};

// returns a struct directly
struct Person Person_create(char *name, int age, int height, int weight)
{
  struct Person who;

  // returns a duplicate of string name
  who.name = strdup(name);
  // arrows fetch properties from pointers to structs
  // dots get properties from the structs themselves
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}

void Person_destroy(struct Person who)
{
  // must free the duplicated 'name' because it was created w/ strdup()
  // string.h strdup() calls malloc() - verified by man page
  free(who.name);
}

void Person_print(struct Person who)
{
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person joe = Person_create(
            "Joe Alex", 32, 64, 140);
  struct Person frank = Person_create(
            "Frank Blank", 20, 72, 180);

  // print the structs out and where they are in memory
  printf("Joe is at memory location %p:\n", &joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", &frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);

  frank.age += 20;
  frank.weight += 20;
  Person_print(frank);

  Person_destroy(joe);
  Person_destroy(frank);


  return 0;
}
