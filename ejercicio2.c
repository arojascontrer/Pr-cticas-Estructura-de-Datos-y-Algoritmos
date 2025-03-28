#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct {
    char nombre[MAX_LENGTH];
    char genero[MAX_LENGTH];
    char cantante[MAX_LENGTH];
} Cancion;

typedef struct {
    Cancion *canciones;
    int frente, final, capacidad, tamaño;
} ColaCircular;

void inicializarCola(ColaCircular *cola, int capacidad) {
    cola->capacidad = capacidad;
    cola->frente = 0;
    cola->final = -1;
    cola->tamaño = 0;
    cola->canciones = (Cancion *)malloc(capacidad * sizeof(Cancion));
}

int estaLlena(ColaCircular *cola) {
    return cola->tamaño == cola->capacidad;
}

int estaVacia(ColaCircular *cola) {
    return cola->tamaño == 0;
}

void agregarCancion(ColaCircular *cola) {
    if (estaLlena(cola)) {
        printf("La playlist está llena. No se puede agregar más canciones.\n");
        return;
    }
    Cancion nuevaCancion;
    printf("Nombre de la canción: ");
    scanf(" %[^\n]", nuevaCancion.nombre);
    printf("Género de la canción: ");
    scanf(" %[^\n]", nuevaCancion.genero);
    printf("Nombre del o la cantante: ");
    scanf(" %[^\n]", nuevaCancion.cantante);

    cola->final = (cola->final + 1) % cola->capacidad;
    cola->canciones[cola->final] = nuevaCancion;
    cola->tamaño++;
    printf("Canción agregada: %s - %s (%s)\n", nuevaCancion.nombre, nuevaCancion.cantante, nuevaCancion.genero);
}

void quitarCancion(ColaCircular *cola) {
    if (estaVacia(cola)) {
        printf("La playlist está vacía. No hay canciones para quitar.\n");
        return;
    }
    Cancion cancionEliminada = cola->canciones[cola->frente];
    cola->frente = (cola->frente + 1) % cola->capacidad;
    cola->tamaño--;
    printf("Canción eliminada: %s - %s (%s)\n", cancionEliminada.nombre, cancionEliminada.cantante, cancionEliminada.genero);
}

void reproducirUnaVez(ColaCircular *cola) {
    if (estaVacia(cola)) {
        printf("La playlist está vacía. No hay canciones para reproducir.\n");
        return;
    }
    for (int i = 0; i < cola->tamaño; i++) {
        int indice = (cola->frente + i) % cola->capacidad;
        printf("Reproduciendo: %s - %s (%s)\n", cola->canciones[indice].nombre, cola->canciones[indice].cantante, cola->canciones[indice].genero);
    }
}

void reproducirVariasVeces(ColaCircular *cola, int veces) {
    if (estaVacia(cola)) {
        printf("La playlist está vacía. No hay canciones para reproducir.\n");
        return;
    }
    for (int v = 0; v < veces; v++) {
        printf("Reproducción #%d:\n", v + 1);
        reproducirUnaVez(cola);
    }
}

void vaciarPlaylist(ColaCircular *cola) {
    cola->frente = 0;
    cola->final = -1;
    cola->tamaño = 0;
    printf("La playlist ha sido vaciada.\n");
}

void mostrarMenu() {
    printf("\nMenú de opciones:\n");
    printf("1. Agregar una canción a la playlist\n");
    printf("2. Quitar una canción de la playlist\n");
    printf("3. Reproducir la playlist una vez\n");
    printf("4. Reproducir la playlist un determinado número de veces\n");
    printf("5. Vaciar la playlist\n");
    printf("6. Salir\n");
}

int main() {
    ColaCircular playlist;
    char nombrePlaylist[MAX_LENGTH];
    int capacidad, opcion, veces;

    printf("Nombre de la playlist: ");
    scanf(" %[^\n]", nombrePlaylist);
    printf("¿Cuántas canciones puede tener la playlist? ");
    scanf("%d", &capacidad);

    inicializarCola(&playlist, capacidad);

    do {
        mostrarMenu();
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarCancion(&playlist);
                break;
            case 2:
                quitarCancion(&playlist);
                break;
            case 3:
                reproducirUnaVez(&playlist);
                break;
            case 4:
                printf("¿Cuántas veces deseas reproducir la playlist? ");
                scanf("%d", &veces);
                reproducirVariasVeces(&playlist, veces);
                break;
            case 5:
                vaciarPlaylist(&playlist);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 6);

    free(playlist.canciones);
    return 0;
}
