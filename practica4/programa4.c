#include <stdio.h>
#include <stdlib.h>

int main() {
    float *tiempos = NULL;
    int capacidad = 0, contador = 0;
    char respuesta;
    
    do {
        // Aumentar el tamaño del arreglo en bloques de 5
        capacidad += 5;
        float *temp = realloc(tiempos, capacidad * sizeof(float));
        
        if (temp == NULL) {
            printf("Error: No se pudo asignar memoria.\n");
            free(tiempos);
            return 1;
        }
        
        tiempos = temp;
        
        // Registrar los tiempos de 5 participantes
        for (int i = 0; i < 5; i++) {
            printf("Ingrese el tiempo en horas del participante %d: ", contador + 1);
            scanf("%f", &tiempos[contador]);
            contador++;
        }
        
        // Preguntar si desea registrar más tiempos
        printf("Desea registrar otros 5 tiempos? (s/n): ");
        scanf(" %c", &respuesta);
        
    } while (respuesta == 's' || respuesta == 'S');
    
    // Calcular el promedio
    float suma = 0;
    for (int i = 0; i < contador; i++) {
        suma += tiempos[i];
    }
    float promedio = (contador > 0) ? suma / contador : 0;
    
    // Mostrar resultados
    printf("\nTiempos registrados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Participante %d: %.2f horas\n", i + 1, tiempos[i]);
    }
    printf("Total de tiempos registrados: %d\n", contador);
    printf("Tiempo promedio: %.2f horas\n", promedio);
    
    // Liberar memoria
    free(tiempos);
    
    return 0;
}
