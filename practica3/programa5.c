#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    float area;
} Estado;

typedef struct {
    char nombre[50];
    char moneda[50];
    float habitantes;
    Estado estados[60];
    int numEstados;
} Pais;

int main() {
    Pais miPais;
    char respuesta;
    
    miPais.numEstados = 0;
    
    printf("Ingrese el nombre del país: ");
    scanf("%49s", miPais.nombre);
    
    printf("Ingrese la moneda oficial: ");
    scanf("%49s", miPais.moneda);
    
    printf("Ingrese el número de habitantes (en millones): ");
    scanf("%f", &miPais.habitantes);
    
    do {
        if (miPais.numEstados < 60) {
            printf("\nDatos del estado %d:\n", miPais.numEstados + 1);
            
            printf("Ingrese el nombre del estado: ");
            scanf("%49s", miPais.estados[miPais.numEstados].nombre);
            
            printf("Ingrese el área en Km² del estado: ");
            scanf("%f", &miPais.estados[miPais.numEstados].area);
            
            miPais.numEstados++;
            
            printf("\n¿Desea registrar otro estado? (s/n): ");
            scanf(" %c", &respuesta);
        } else {
            printf("\nSe ha alcanzado el límite máximo de 60 estados.\n");
            break;
        }
    } while (respuesta == 's' || respuesta == 'S');
    
    printf("\n----- INFORMACIÓN DEL PAÍS -----\n");
    printf("Nombre: %s\n", miPais.nombre);
    printf("Moneda oficial: %s\n", miPais.moneda);
    printf("Población: %.2f millones de habitantes\n", miPais.habitantes);
    printf("Número de estados registrados: %d\n", miPais.numEstados);
    
    printf("\n----- ESTADOS REGISTRADOS -----\n");
    for (int i = 0; i < miPais.numEstados; i++) {
        printf("\nEstado %d: %s\n", i + 1, miPais.estados[i].nombre);
        printf("Área: %.2f Km²\n", miPais.estados[i].area);
    }
    
    return 0;
}