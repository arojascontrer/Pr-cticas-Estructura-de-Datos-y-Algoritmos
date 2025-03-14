#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Mascota
typedef struct {
    char nombre[30];
    char tipo[20];
    int edad;
    char descripcion[100];
    char propietario[50];
    char celular[15];
} Mascota;

int main() {
    Mascota *mascotas = NULL;
    int contador = 0;
    char respuesta;
    
    printf("Guardería Cat y Perry\n");
    
    do {
        // Reservar memoria para una nueva mascota
        Mascota *temp = realloc(mascotas, (contador + 1) * sizeof(Mascota));
        if (temp == NULL) {
            printf("Error: No se pudo asignar memoria.\n");
            free(mascotas);
            return 1;
        }
        mascotas = temp;
        
        // Ingreso de datos
        printf("Ingrese el nombre de la mascota (una palabra): ");
        scanf("%s", mascotas[contador].nombre);
        printf("Ingrese el tipo de animal: ");
        scanf("%s", mascotas[contador].tipo);
        printf("Ingrese la edad de la mascota: ");
        scanf("%d", &mascotas[contador].edad);
        getchar(); // Limpiar el buffer
        printf("Ingrese la descripción de color y tamaño: ");
        fgets(mascotas[contador].descripcion, sizeof(mascotas[contador].descripcion), stdin);
        strtok(mascotas[contador].descripcion, "\n"); // Eliminar el salto de línea
        printf("Ingrese el nombre del propietario: ");
        fgets(mascotas[contador].propietario, sizeof(mascotas[contador].propietario), stdin);
        strtok(mascotas[contador].propietario, "\n");
        printf("Ingrese el celular del propietario: ");
        scanf("%s", mascotas[contador].celular);
        
        contador++;
        
        // Preguntar si se desea registrar otra mascota
        printf("¿Desea registrar otra mascota? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');
    
    // Mostrar las mascotas registradas
    printf("\nMascotas registradas:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. %s\n", i + 1, mascotas[i].nombre);
    }
    
    // Seleccionar mascota para ver detalles
    int seleccion;
    printf("\nIngrese el número de la mascota para ver detalles: ");
    scanf("%d", &seleccion);
    
    if (seleccion > 0 && seleccion <= contador) {
        seleccion--; // Ajustar al índice
        printf("\nDetalles de la mascota:\n");
        printf("Nombre: %s\n", mascotas[seleccion].nombre);
        printf("Tipo: %s\n", mascotas[seleccion].tipo);
        printf("Edad: %d años\n", mascotas[seleccion].edad);
        printf("Descripción: %s\n", mascotas[seleccion].descripcion);
        printf("Propietario: %s\n", mascotas[seleccion].propietario);
        printf("Celular: %s\n", mascotas[seleccion].celular);
    } else {
        printf("Número de mascota inválido.\n");
    }
    
    // Liberar memoria
    free(mascotas);
    
    return 0;
}
