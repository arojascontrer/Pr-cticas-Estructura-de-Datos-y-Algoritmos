#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEDIDOS 12
#define LONG_NOMBRE 50

// Estructura del pedido
typedef struct Pedido {
    char nombre[LONG_NOMBRE];
    int mesa;
    char platillo[LONG_NOMBRE];
    struct Pedido* siguiente;
} Pedido;

// Estructura de la cola
typedef struct {
    Pedido* frente;
    Pedido* final;
    int tamaño;
} Cola;

// Inicializar la cola
void inicializarCola(Cola* cola) {
    cola->frente = cola->final = NULL;
    cola->tamaño = 0;
}

// Verificar si la cola está vacía
int estaVacia(Cola* cola) {
    return cola->frente == NULL;
}

// Añadir un pedido a la cola
void agregarPedido(Cola* cola, char nombre[], int mesa, char platillo[]) {
    if (cola->tamaño >= MAX_PEDIDOS) {
        printf("La cola está llena. No se pueden agregar más pedidos.\n");
        return;
    }
    
    Pedido* nuevo = (Pedido*)malloc(sizeof(Pedido));
    strcpy(nuevo->nombre, nombre);
    nuevo->mesa = mesa;
    strcpy(nuevo->platillo, platillo);
    nuevo->siguiente = NULL;

    if (estaVacia(cola)) {
        cola->frente = cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    cola->tamaño++;
    printf("Pedido agregado: %s, Mesa: %d, Platillo: %s\n", nombre, mesa, platillo);
}

// Retirar un pedido de la cola
void recogerPedido(Cola* cola) {
    if (estaVacia(cola)) {
        printf("No hay pedidos para recoger.\n");
        return;
    }

    Pedido* temp = cola->frente;
    printf("Recogiendo pedido: %s, Mesa: %d, Platillo: %s\n", temp->nombre, temp->mesa, temp->platillo);
    
    cola->frente = cola->frente->siguiente;
    free(temp);
    cola->tamaño--;

    if (cola->frente == NULL) {
        cola->final = NULL;
    }
}

// Vaciar la cola para despachar los pedidos pendientes
void vaciarCola(Cola* cola) {
    while (!estaVacia(cola)) {
        recogerPedido(cola);
    }
}

// Menú principal
int main() {
    Cola colaPedidos;
    inicializarCola(&colaPedidos);

    int opcion, mesa;
    char nombre[LONG_NOMBRE], platillo[LONG_NOMBRE];

    do {
        printf("\nMenú:\n");
        printf("1. Indicar un platillo a preparar\n");
        printf("2. Recoger un platillo\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                if (colaPedidos.tamaño < MAX_PEDIDOS) {
                    printf("Nombre del cliente: ");
                    fgets(nombre, LONG_NOMBRE, stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Número de mesa: ");
                    scanf("%d", &mesa);
                    getchar();

                    printf("Nombre del platillo: ");
                    fgets(platillo, LONG_NOMBRE, stdin);
                    platillo[strcspn(platillo, "\n")] = 0;

                    agregarPedido(&colaPedidos, nombre, mesa, platillo);
                } else {
                    printf("La cola está llena. No se pueden añadir más pedidos.\n");
                }
                break;

            case 2:
                recogerPedido(&colaPedidos);
                break;

            case 3:
                printf("Vaciando cola antes de salir...\n");
                vaciarCola(&colaPedidos);
                printf("Todos los pedidos fueron despachados.\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}
