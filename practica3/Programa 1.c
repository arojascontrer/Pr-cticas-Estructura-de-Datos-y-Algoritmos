#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo_taco[20];
    char tipo_tortilla[10];
    int mitades_limon;
    char quiere_salsa[3];
    char tipo_salsa[15];
    char complemento[10];
} OrdenTacos;

OrdenTacos tomarOrden() {
    OrdenTacos orden;
    printf("Bienvenido a su taquería\n");
    printf("Cada orden se compone de cinco tacos, todos de un solo tipo.\n");
    printf("Opciones: suadero, pastor, bistec, cochinita.\n");
    printf("¿De qué quiere su orden? ");
    scanf("%s", orden.tipo_taco);
    printf("¿Los quiere en tortilla de maíz o de harina? ");
    scanf("%s", orden.tipo_tortilla);
    printf("¿Cuántas mitades de limón quiere? ");
    scanf("%d", &orden.mitades_limon);
    printf("¿Quiere salsa? (SI/NO) ");
    scanf("%s", orden.quiere_salsa);
    if (strcmp(orden.quiere_salsa, "SI") == 0) {
        printf("¿De cuál salsa quiere? (roja, verde, guacamole) ");
        scanf("%s", orden.tipo_salsa);
    } else {
        strcpy(orden.tipo_salsa, "ninguna");
    }
    printf("¿Quiere frijoles o papas en su orden? ");
    scanf("%s", orden.complemento);
    return orden;
}

void mostrarOrden(OrdenTacos orden) {
    printf("\nResumen de su orden:\n");
    printf("- 5 tacos de %s en tortilla de %s\n", orden.tipo_taco, orden.tipo_tortilla);
    printf("- %d mitades de limón\n", orden.mitades_limon);
    printf("- Salsa: %s\n", orden.tipo_salsa);
    printf("- Complemento: %s\n", orden.complemento);
}

int main() {
    OrdenTacos miOrden = tomarOrden();
    mostrarOrden(miOrden);
    return 0;
}