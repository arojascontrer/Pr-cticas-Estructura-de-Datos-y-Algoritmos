#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaDobleMenteLigada {
    char nombre[50];
    float precio;
    struct ListaDobleMenteLigada *siguiente;
    struct ListaDobleMenteLigada *anterior;
} *APTSIGNODO;

APTSIGNODO inicio = NULL, fin = NULL;

int estaVacia() {
    return inicio == NULL;
}

void insertarAlFinal(char nombre[], float precio) {
    APTSIGNODO nuevo = (APTSIGNODO)malloc(sizeof(struct ListaDobleMenteLigada));
    strcpy(nuevo->nombre, nombre);
    nuevo->precio = precio;
    nuevo->siguiente = NULL;
    
    if (estaVacia()) {
        nuevo->anterior = NULL;
        inicio = fin = nuevo;
    } else {
        nuevo->anterior = fin;
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

void eliminarElemento(char nombre[]) {
    APTSIGNODO aptNodoAEliminar = inicio;
    APTSIGNODO aptNodoSig;

    while (aptNodoAEliminar != NULL) {
        if (strcmp(aptNodoAEliminar->nombre, nombre) == 0) {
            aptNodoSig = aptNodoAEliminar->siguiente;

            if (aptNodoAEliminar == inicio) {
                inicio = aptNodoSig;
                if (inicio) inicio->anterior = NULL;
            } else if (aptNodoAEliminar == fin) {
                fin = aptNodoAEliminar->anterior;
                if (fin) fin->siguiente = NULL;
            } else {
                aptNodoAEliminar->anterior->siguiente = aptNodoSig;
                if (aptNodoSig) aptNodoSig->anterior = aptNodoAEliminar->anterior;
            }

            free(aptNodoAEliminar);
            printf("Elemento eliminado correctamente.\n");
            return;
        }
        aptNodoAEliminar = aptNodoAEliminar->siguiente;
    }
    printf("Elemento no encontrado.\n");
}

void recorrerDesdeInicio() {
    APTSIGNODO actual = inicio;
    while (actual != NULL) {
        printf("Antojo/Postre: %s, Precio: $%.2f\n", actual->nombre, actual->precio);
        actual = actual->siguiente;
    }
}

void recorrerDesdeFin() {
    APTSIGNODO actual = fin;
    while (actual != NULL) {
        printf("Antojo/Postre: %s, Precio: $%.2f\n", actual->nombre, actual->precio);
        actual = actual->anterior;
    }
}

void mostrarMenu() {
    printf("\nMen\u00fa:\n");
    printf("a) Agregar antojo/postre\n");
    printf("b) Mostrar lista desde el inicio\n");
    printf("c) Mostrar lista desde el final\n");
    printf("d) Eliminar un antojo/postre\n");
    printf("e) Verificar si la lista est\u00e1 vac\u00eda\n");
    printf("f) Salir\n");
    printf("Seleccione una opci\u00f3n: ");
}

int main() {
    char opcion, nombre[50];
    float precio;
    
    do {
        mostrarMenu();
        scanf(" %c", &opcion);
        
        switch (opcion) {
            case 'a':
                printf("Ingrese el nombre del antojo/postre: ");
                scanf("%s", nombre);
                printf("Ingrese el precio: ");
                scanf("%f", &precio);
                insertarAlFinal(nombre, precio);
                break;
            case 'b':
                recorrerDesdeInicio();
                break;
            case 'c':
                recorrerDesdeFin();
                break;
            case 'd':
                printf("Ingrese el nombre del antojo/postre a eliminar: ");
                scanf("%s", nombre);
                eliminarElemento(nombre);
                break;
            case 'e':
                printf(estaVacia() ? "La lista est\u00e1 vac\u00eda.\n" : "La lista contiene elementos.\n");
                break;
            case 'f':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci\u00f3n no v\u00e1lida. Intente nuevamente.\n");
        }
    } while (opcion != 'f');

    return 0;
}
