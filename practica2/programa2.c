#include <stdio.h>

int main() {
    char nombre[101];
    char *P_nombre = nombre;

   printf("ingrese su nombre completo: ");
   fgets(nombre, sizeof(nombre), stdin);

   printf("\nDireccion de memoria donde se almaceno el nombre: %p\n", (void*)P_nombre);
   printf("nombre usando el apuntador: %s", P_nombre);

 return 0;
}
