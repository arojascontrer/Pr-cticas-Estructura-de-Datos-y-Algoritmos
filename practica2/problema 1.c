#include <stdio.h>

int main() {
    int edad;
    float estatura;
    char letra;

  int *P_edad = &edad;
  float *P_estatura = &estatura;
  char *P_letra = &letra;

  printf("ingrese su edad: ");
    scanf("%d", &edad);

   printf("ingrese su estatura: ");
   scanf("%f", &estatura);

   while (getchar() != '\n'); //profe esto fue porque saltaba lo de letra

   printf("ingrese su letra favorita: ");
    scanf("%c", &letra);

  printf("\nDirecciones de memoria:\n");
  printf("edad: %p\n", (void*)P_edad);
  printf("estatura: %p\n", (void*)P_estatura);
  printf("letra: %p\n", (void*)P_letra);

  printf("\nValores utilizando apuntadores:\n");
  printf("edad:  %d\n", *P_edad);
  printf("estatura:  %2f\n", *P_estatura);
  printf("letra:  %c\n", *P_letra);

 return 0;

}
