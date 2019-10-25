#include <stdio.h>
#include <stdbool.h>

typedef enum Gravity {
  Nothing = 0,
  One,
  Ten,
  Hundred,
  Thousand,
} Gravity;

bool is_ordinary_number(char* number) {
  if (number == NULL || number[0] == '\0') {
    return false;
  }
  for (int i = 0; number[i] != '\0'; i++) {
    if (number[i] < '0' || number[i] > '9') {
      return false;
    }
  }
  return true;
}

Gravity get_rome_gravity(char rome) {
  switch (rome) {
    case 'M':
      return Thousand;
    case 'D':
    case 'C':
      return Hundred;
    case 'L':
    case 'X':
      return Ten;
    case 'V':
    case 'I':
      return One;
    default:
      return Nothing;
  }
}
bool is_rome_number(char* number) {
  if (number == NULL || number[0] == '\0') {
    return false;
  }
  Gravity g = Nothing;
  for (int i = 0; number[i] != '\0'; i++) {
    Gravity lg = get_rome_gravity(number[i]);
    if (lg == Nothing || (g != Nothing && lg > g)) {
      return false;
    }
    g = lg;
  }
  return true;
}

typedef struct RomeNumber {
  int num;
  Gravity grav;
} RomeNumber;

void usage(char* exec) {
  printf("%s <number>\n", exec);
  printf("\tnumber: Rome Number(IVXLCDM) or Ordinary Number(123)\n");
}
int main(int argc, char* argv[]) {
  if (argc != 2) {
    usage(argv[0]);
    return -1;
  }
  bool isNumber = is_ordinary_number(argv[1]);
  bool isRome = is_rome_number(argv[1]);
  if (!isNumber && !isRome) {
    usage(argv[0]);
    return -1;
  }
  if (isNumber) {
    printf("Ordinary Number!\n");
  } else if (isRome) {
    printf("Rome Number!\n");
  }
  return 0;
}