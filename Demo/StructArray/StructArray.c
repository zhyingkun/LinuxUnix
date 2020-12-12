#include <stdio.h>

typedef struct {
  char* name;
  int age;
} Person;

typedef struct {
  char* name;
  int age;
} PersonA[1];

void print_person(Person a) { // argument passed by value
  printf("Person: %s, %d\n", a.name, a.age);
}

void print_person_p(Person* p) { // argument passed by pointer
  printf("Person: %s, %d\n", p->name, p->age);
}

void print_person_array(PersonA pa) { // argument passed by pointer
  printf("PersonA: %s, %d\n", pa->name, pa->age);
}

int main(int argc, const char* argv[]) {
  Person per;
  per.name = "tony";
  per.age = 18;

  Person _per;
  Person* p = &_per;
  p->name = "john";
  p->age = 23;

  PersonA perA;
  perA->name = "alias";
  perA->age = 27;

  print_person(per);
  print_person_p(p);
  print_person_array(perA);
  return 0;
}
