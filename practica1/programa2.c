#include <stdio.h>

int main() {
    int calificacion[6];
    int index, promedio;
    
    for (index = 0; index < 5; index++) {
        printf("Introduzca calificación: ");
        scanf("%i", &calificacion[index]);
    }
    
    promedio = 0;
    for (index = 0; index < 5; index++) {
        promedio = promedio + calificacion[index];
    }
    
    promedio = promedio / 5;
    calificacion[5] = promedio;
    
    printf("El promedio es: %i\n", calificacion[5]);
    
    return 0;
}