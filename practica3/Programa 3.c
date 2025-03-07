#include <stdio.h>
#include <string.h>

typedef struct {
    char tipo_taco[20];
    char tipo_tortilla[10];
    int mitades_limon;
    char quiere_salsa[3];
    char tipo_salsa[15];
    char acompanamiento[10];
} OrdenTacos;

void mostrarOrdenes(OrdenTacos ordenes[], int total) {
    printf("\nResumen de sus ordenes:\n");
    for (int i = 0; i < total; i++) {
        printf("\nOrden %d:\n", i + 1);
        printf("5 tacos de %s en tortilla de %s\n", ordenes[i].tipo_taco, ordenes[i].tipo_tortilla);
        printf("%d mitades de limon\n", ordenes[i].mitades_limon);
        if (strcmp(ordenes[i].quiere_salsa, "SI") == 0) {
            printf("Salsa: %s\n", ordenes[i].tipo_salsa);
        } else {
            printf("Sin salsa\n");
        }
        printf("Acompañamiento: %s\n", ordenes[i].acompanamiento);
    }
}

int main() {
    OrdenTacos ordenes[100];
    int total_ordenes = 0;
    char otra_orden[3];
    
    printf("Bienvenido a su taquería\n");
    do {
        printf("Cada orden es de cinco tacos de un solo tipo: suadero, pastor, bistec o cochinita.\n");
        printf("Ingrese el tipo de taco: ");
        scanf("%s", ordenes[total_ordenes].tipo_taco);
        printf("Los quiere en tortilla de maiz o harina? ");
        scanf("%s", ordenes[total_ordenes].tipo_tortilla);
        printf("Cuantas mitades de limon quiere? ");
        scanf("%d", &ordenes[total_ordenes].mitades_limon);
        printf("Quiere salsa? (SI/NO): ");
        scanf("%s", ordenes[total_ordenes].quiere_salsa);
        if (strcmp(ordenes[total_ordenes].quiere_salsa, "SI") == 0) {
            printf("De cual salsa? (roja, verde, guacamole): ");
            scanf("%s", ordenes[total_ordenes].tipo_salsa);
        }
        printf("Quiere frijoles o papas? ");
        scanf("%s", ordenes[total_ordenes].acompanamiento);
        total_ordenes++;
        printf("Desea otra orden? (SI/NO): ");
        scanf("%s", otra_orden);
    } while (strcmp(otra_orden, "SI") == 0);
    
    mostrarOrdenes(ordenes, total_ordenes);
    return 0;
}