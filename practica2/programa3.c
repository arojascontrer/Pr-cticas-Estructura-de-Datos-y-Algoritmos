#include <stdio.h>

int main() {

  char arreglo[] = {'a', 'b', 'c'};
  char *P = arreglo;

  printf("A) %c %c %c\n", *P, *(P + 1), *(P + 2));

  printf("B) ");
  for (int i = 0; i< 3; i++) {
     printf("%c ", *(P + i));

  }
  printf("\n");

 return 0;

}
