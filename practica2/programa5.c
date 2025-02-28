#include <stdio.h>

void SumaMejorada(float *num1, float *num2, float *resultado);

int main() {
    float numero1, numero2, resultado;
    
    printf("Ingrese el primer número real: ");
    scanf("%f", &numero1);
    
    printf("Ingrese el segundo número real: ");
    scanf("%f", &numero2);
    
    SumaMejorada(&numero1, &numero2, &resultado);
    
    printf("El resultado de la suma es: %.2f\n", resultado);
    
    return 0;
}

void SumaMejorada(float *num1, float *num2, float *resultado) {
    *resultado = *num1 + *num2;
}