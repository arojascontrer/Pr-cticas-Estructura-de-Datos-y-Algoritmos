#include <stdio.h>

float funcionSecundaria(float arreglo[], int tamano);

int main() {
    float numeros[5];
    float suma;
    int i;
    
    for (i = 0; i < 5; i++) {
        printf("Ingrese el número real %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }
    
    suma = funcionSecundaria(numeros, 5);
    
    printf("\nElementos del arreglo después de incrementar:\n");
    for (i = 0; i < 5; i++) {
        printf("Elemento %d: %.2f\n", i + 1, numeros[i]);
    }
    
    printf("\nLa suma de los elementos incrementados es: %.2f\n", suma);
    
    return 0;
}

float funcionSecundaria(float arreglo[], int tamano) {
    float suma = 0;
    int i;
    
    for (i = 0; i < tamano; i++) {
        arreglo[i] += 10;
        suma += arreglo[i];
    }
    
    return suma;
}