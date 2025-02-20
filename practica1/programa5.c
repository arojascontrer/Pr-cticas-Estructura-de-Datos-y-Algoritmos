#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILAS 10
#define COLUMNAS 8

// Función para imprimir el estado de la sala
void imprimirSala(int sala[FILAS][COLUMNAS]) {
    printf("Hola. Estos son los asientos disponibles para la película Flow\n");
    printf("  0 1 2 3 4 5 6 7\n");
    
    char fila = 'A';
    for (int i = 0; i < FILAS; i++) {
        printf("%c ", fila);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", sala[i][j]);
        }
        printf("\n");
        fila++;
    }
}

int main() {
    // Inicializar la sala con todos los asientos disponibles (0)
    int sala[FILAS][COLUMNAS] = {0};
    int numUsuarios = 4;
    char filaLetra;
    int columna, filaIndice;
    char entrada[10];
    
    for (int usuario = 1; usuario <= numUsuarios; usuario++) {
        printf("\n==================================================\n");
        printf("Usuario %d\n", usuario);
        imprimirSala(sala);
        
        int asientoValido = 0;
        while (!asientoValido) {
            printf("\nIngrese la fila (letra A-J) y el número de asiento (0-7) separados por un espacio: ");
            
            // Leer la entrada del usuario
            if (scanf(" %c %d", &filaLetra, &columna) != 2) {
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                printf("Formato incorrecto. Ingrese la letra de la fila y el número de asiento separados por un espacio.\n");
                continue;
            }
            
            // Convertir a mayúscula si es necesario
            filaLetra = toupper(filaLetra);
            
            // Convertir letra a índice
            filaIndice = filaLetra - 'A';
            
            // Verificar que el asiento existe
            if (filaIndice < 0 || filaIndice >= FILAS || columna < 0 || columna >= COLUMNAS) {
                printf("¡Asiento inválido! Por favor, ingrese una fila válida (A-J) y columna válida (0-7).\n");
                continue;
            }
            
            // Verificar si el asiento está disponible
            if (sala[filaIndice][columna] == 1) {
                printf("El asiento %c%d está ocupado. Por favor elija otro asiento.\n", filaLetra, columna);
                continue;
            }
            
            // Reservar el asiento
            sala[filaIndice][columna] = 1;
            printf("¡Su asiento %c%d ha sido reservado con éxito!\n", filaLetra, columna);
            asientoValido = 1;
        }
    }
    
    // Mostrar estado final de la sala
    printf("\n==================================================\n");
    printf("Estado final de la sala:\n");
    imprimirSala(sala);
    
    return 0;
}