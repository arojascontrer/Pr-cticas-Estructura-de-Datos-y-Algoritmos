#include <stdio.h>

typedef struct {
    char tipo_taco[20];
    char tipo_tortilla[10];
    int mitades_limon;
    char quiere_salsa[3];
    char tipo_salsa[15];
    char acompanamiento[10];
} OrdenTacos;

void mostrarOrden(OrdenTacos orden) {
    printf("\nResumen de su orden:\n");
    printf("5 tacos de %s en tortilla de %s\n", orden.tipo_taco, orden.tipo_tortilla);
    printf("%d mitades de limon\n", orden.mitades_limon);
    if (orden.quiere_salsa[0] == 'S' && orden.quiere_salsa[1] == 'I') {
        printf("Salsa: %s\n", orden.tipo_salsa);
    } else {
        printf("Sin salsa\n");
    }
    printf("Acompañamiento: %s\n", orden.acompanamiento);
}

int main() {
    OrdenTacos orden;
    printf("Bienvenido a su taquería\n");
    printf("Cada orden es de cinco tacos de un solo tipo: suadero, pastor, bistec o cochinita.\n");
    printf("Ingrese el tipo de taco: ");
    scanf("%s", orden.tipo_taco);
    printf("Los quiere en tortilla de maiz o harina? ");
    scanf("%s", orden.tipo_tortilla);
    printf("Cuantas mitades de limon quiere? ");
    scanf("%d", &orden.mitades_limon);
    printf("Quiere salsa? (SI/NO): ");
    scanf("%s", orden.quiere_salsa);
    if (orden.quiere_salsa[0] == 'S' && orden.quiere_salsa[1] == 'I') {
        printf("De cual salsa? (roja, verde, guacamole): ");
        scanf("%s", orden.tipo_salsa);
    }
    printf("Quiere frijoles o papas? ");
    scanf("%s", orden.acompanamiento);
    mostrarOrden(orden);
    return 0;
}