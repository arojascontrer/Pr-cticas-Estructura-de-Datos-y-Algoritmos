#include <stdio.h>

float Suma(float a, float b) {
    return a + b;
}

int main() {
    float num1, num2, resultado;

    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    resultado = Suma(num1, num2);

    printf("La suma de %.2f y %.2f es: %.2f\n", num1, num2, resultado);

    return 0;
}
