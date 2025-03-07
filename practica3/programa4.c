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
    Estado capital;
} Pais;

int main() {
    Pais miPais;
    
    printf("Ingrese el nombre del país: ");
    scanf("%49s", miPais.nombre);
    getchar();

    printf("Ingrese la moneda oficial: ");
    scanf("%49s", miPais.moneda);
    getchar();

    printf("Ingrese el número de habitantes (en millones): ");
    scanf("%f", &miPais.habitantes);
    getchar();
    
    printf("\nDatos del estado capital:\n");
    printf("Ingrese el nombre del estado capital: ");
    scanf("%49s", miPais.capital.nombre);
    getchar();

    printf("Ingrese el área en Km² del estado capital: ");
    scanf("%f", &miPais.capital.area);
    getchar();

    printf("\n----- INFORMACIÓN DEL PAÍS -----\n");
    printf("Nombre: %s\n", miPais.nombre);
    printf("Moneda oficial: %s\n", miPais.moneda);
    printf("Población: %.2f millones de habitantes\n", miPais.habitantes);
    printf("\nCapital: %s\n", miPais.capital.nombre);
    printf("Área de la capital: %.2f Km²\n", miPais.capital.area);
    
    return 0;
}