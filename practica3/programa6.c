#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int suadero;
    int pastor;
    int bistec;
    int carnitas;
    int bebida;
    char postre;
} Orden;

float calcularPrecio(Orden *orden) {
    float total = 0;
    
    total += orden->suadero * 15;
    total += orden->pastor * 12;
    total += orden->bistec * 18;
    total += orden->carnitas * 25;
    
    switch (orden->bebida) {
        case 1:
            total += 15;
            break;
        case 2:
            total += 15;
            break;
        case 3:
            total += 22;
            break;
        case 4:
            total += 20;
            break;
    }
    
    switch (orden->postre) {
        case 'A':
        case 'a':
            total += 30;
            break;
        case 'B':
        case 'b':
            total += 25;
            break;
        case 'C':
        case 'c':
            total += 27;
            break;
    }
    
    return total;
}

int main() {
    Orden miOrden = {0};
    char respuesta[5];
    
    printf("Bienvenido a su taquería\n\n");
    
    printf("Taquitos de suadero: $15\n");
    printf("Ingrese la cantidad: ");
    scanf("%d", &miOrden.suadero);
    
    printf("Taquitos de pastor: $12\n");
    printf("Ingrese la cantidad: ");
    scanf("%d", &miOrden.pastor);
    
    printf("Taquitos de bistec: $18\n");
    printf("Ingrese la cantidad: ");
    scanf("%d", &miOrden.bistec);
    
    printf("Taquitos de carnitas: $25\n");
    printf("Ingrese la cantidad: ");
    scanf("%d", &miOrden.carnitas);
    
    printf("\n¿Quiere alguna bebida? (SI/NO): ");
    scanf("%s", respuesta);
    
    for (int i = 0; respuesta[i]; i++) {
        respuesta[i] = tolower(respuesta[i]);
    }
    
    if (strcmp(respuesta, "si") == 0) {
        printf("1. Agua de Jamaica: $15\n");
        printf("2. Agua de limón con chía: $15\n");
        printf("3. Refresco sabor cola: $22\n");
        printf("4. Refresco de guayaba: $20\n");
        printf("Seleccione una opción (1-4): ");
        scanf("%d", &miOrden.bebida);
    }
    
    printf("\n¿Quiere postre? (SI/NO): ");
    scanf("%s", respuesta);
    
    for (int i = 0; respuesta[i]; i++) {
        respuesta[i] = tolower(respuesta[i]);
    }
    
    if (strcmp(respuesta, "si") == 0) {
        printf("A. Flan napolitano: $30\n");
        printf("B. Arroz con leche: $25\n");
        printf("C. Helado de limón: $27\n");
        printf("Seleccione una opción (A-C): ");
        scanf(" %c", &miOrden.postre);
    }
    
    printf("\n----- RESUMEN DE SU ORDEN -----\n");
    printf("Tacos de suadero: %d\n", miOrden.suadero);
    printf("Tacos de pastor: %d\n", miOrden.pastor);
    printf("Tacos de bistec: %d\n", miOrden.bistec);
    printf("Tacos de carnitas: %d\n", miOrden.carnitas);
    
    if (miOrden.bebida > 0) {
        printf("Bebida seleccionada: ");
        switch (miOrden.bebida) {
            case 1: printf("Agua de Jamaica\n"); break;
            case 2: printf("Agua de limón con chía\n"); break;
            case 3: printf("Refresco sabor cola\n"); break;
            case 4: printf("Refresco de guayaba\n"); break;
        }
    } else {
        printf("No ordenó bebida\n");
    }
    
    if (miOrden.postre) {
        printf("Postre seleccionado: ");
        switch (miOrden.postre) {
            case 'A': 
            case 'a': printf("Flan napolitano\n"); break;
            case 'B': 
            case 'b': printf("Arroz con leche\n"); break;
            case 'C': 
            case 'c': printf("Helado de limón\n"); break;
        }
    } else {
        printf("No ordenó postre\n");
    }
    
    float precioTotal = calcularPrecio(&miOrden);
    printf("\nEl precio total de su orden es: $%.2f\n", precioTotal);
    printf("Gracias por su compra =)\n");
    
    return 0;
}