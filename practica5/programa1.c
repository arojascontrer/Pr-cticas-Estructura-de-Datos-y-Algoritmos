#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura Contenedor (en lugar de usar simplemente un entero como valor)
struct Contenedor {
    int numeroIdentificacion;
    char tipoProducto[50];
    char paisOrigen[50];
    float pesoKg;
};

// Estructura Nodo
struct Nodo {
    struct Contenedor contenedor;
    struct Nodo* aptSigNodo;
};

// Estructura Pila
struct Pila {
    struct Nodo* aptNodoSuperior;
    int tamanioMaximo;
    int tamanioActual;
};

// Prototipos de las funciones de la pila
void inicializarPila(struct Pila* laPila, int capacidadMaxima);
void push(struct Pila* laPila, struct Contenedor contenedorAIngresar);
struct Contenedor pop(struct Pila* laPila);
int estaVacia(struct Pila* laPila);   
int estaLlena(struct Pila* laPila);	  
void vaciarPila(struct Pila* laPila); 
void mostrarMenuOpciones(void);
void obtenerDatosContenedor(struct Contenedor* nuevoContenedor);
void mostrarDatosContenedor(struct Contenedor contenedor);

// Función principal
int main() {
    struct Pila pilaContenedores;
    struct Contenedor contenedorTemporal;
    int opcion;
    char respuesta;
    
    // Inicializar la pila con capacidad máxima de 10
    inicializarPila(&pilaContenedores, 10);
    
    do {
        mostrarMenuOpciones();
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer

        switch(opcion) {
            case 1: // Apilar contenedor
                obtenerDatosContenedor(&contenedorTemporal);
                push(&pilaContenedores, contenedorTemporal);
                break;
                
            case 2: // Desapilar contenedor
                if (!estaVacia(&pilaContenedores)) {
                    contenedorTemporal = pop(&pilaContenedores);
                    printf("\n--- Datos del contenedor desapilado ---\n");
                    mostrarDatosContenedor(contenedorTemporal);
                }
                break;
                
            default:
                printf("Opción no válida. Por favor intente nuevamente.\n");
        }
        
        printf("\n¿Desea realizar otra operación? (s/n): ");
        scanf(" %c", &respuesta);
        getchar(); // Limpiar el buffer
        
    } while (respuesta == 's' || respuesta == 'S');
    
    // Vaciar la pila al finalizar
    printf("\nVaciando la pila para despachar todos los contenedores restantes...\n");
    vaciarPila(&pilaContenedores);
    
    return 0;
}

void mostrarMenuOpciones() {
    printf("\n--- CONTROL DE BODEGA DE CONTENEDORES ---\n");
    printf("1. Apilar un contenedor\n");
    printf("2. Desapilar un contenedor\n");
    printf("Seleccione una opción: ");
}

void obtenerDatosContenedor(struct Contenedor* nuevoContenedor) {
    printf("\n--- Ingreso de nuevo contenedor ---\n");
    
    printf("Número de identificación: ");
    scanf("%d", &nuevoContenedor->numeroIdentificacion);
    getchar(); // Limpiar el buffer
    
    printf("Tipo de producto: ");
    fgets(nuevoContenedor->tipoProducto, 50, stdin);
    nuevoContenedor->tipoProducto[strcspn(nuevoContenedor->tipoProducto, "\n")] = 0; // Eliminar salto de línea
    
    printf("País de origen: ");
    fgets(nuevoContenedor->paisOrigen, 50, stdin);
    nuevoContenedor->paisOrigen[strcspn(nuevoContenedor->paisOrigen, "\n")] = 0; // Eliminar salto de línea
    
    printf("Peso en kilogramos: ");
    scanf("%f", &nuevoContenedor->pesoKg);
    getchar(); // Limpiar el buffer
}

void mostrarDatosContenedor(struct Contenedor contenedor) {
    printf("Número de identificación: %d\n", contenedor.numeroIdentificacion);
    printf("Tipo de producto: %s\n", contenedor.tipoProducto);
    printf("País de origen: %s\n", contenedor.paisOrigen);
    printf("Peso en kilogramos: %.2f kg\n", contenedor.pesoKg);
}

void inicializarPila(struct Pila* laPila, int capacidadMaxima) {
    laPila->aptNodoSuperior = NULL;
    laPila->tamanioMaximo = capacidadMaxima;
    laPila->tamanioActual = 0;
}

void push(struct Pila* laPila, struct Contenedor contenedorAIngresar) {
    if (estaLlena(laPila) == 1) {
        printf("\nAviso: La pila está llena. No se puede apilar más contenedores (máximo 10).\n");
    }
    else {
        struct Nodo* aptNuevoNodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
        if (aptNuevoNodo != NULL) {
            aptNuevoNodo->contenedor = contenedorAIngresar;
            aptNuevoNodo->aptSigNodo = laPila->aptNodoSuperior;
            laPila->aptNodoSuperior = aptNuevoNodo;
            laPila->tamanioActual = (laPila->tamanioActual) + 1;
            printf("\nContenedor #%d apilado exitosamente. Tamaño actual de la pila: %d\n", 
                   contenedorAIngresar.numeroIdentificacion, laPila->tamanioActual);
        }
        else {
            printf("\nAviso: No se pudo reservar memoria para el nuevo contenedor\n");
        }
    }
}

struct Contenedor pop(struct Pila* laPila) {
    struct Contenedor contenedorVacio = {0, "", "", 0.0}; // Contenedor vacío para retornar en caso de error
    
    if (estaVacia(laPila) == 1) {
        printf("\nAviso: No se puede desapilar porque la pila está vacía\n");
        return contenedorVacio;
    }
    else {
        struct Nodo* aptAlNodoAEliminar = laPila->aptNodoSuperior;
        struct Contenedor contenedorDesapilado = aptAlNodoAEliminar->contenedor;
        laPila->aptNodoSuperior = aptAlNodoAEliminar->aptSigNodo;
        free(aptAlNodoAEliminar);
        laPila->tamanioActual = laPila->tamanioActual - 1;
        printf("\nContenedor desapilado exitosamente. Tamaño actual de la pila: %d\n", laPila->tamanioActual);
        return contenedorDesapilado;
    }
}

void vaciarPila(struct Pila* laPila) {
    int contadorContenedores = 0;
    
    while (estaVacia(laPila) != 1) {
        struct Contenedor contenedorDesapilado = pop(laPila);
        printf("\n--- Despachando contenedor #%d ---\n", contenedorDesapilado.numeroIdentificacion);
        mostrarDatosContenedor(contenedorDesapilado);
        contadorContenedores++;
    }
    
    printf("\nSe han despachado %d contenedores. La bodega está vacía.\n", contadorContenedores);
}

int estaLlena(struct Pila* laPila) {
    int bandera = 0;
    if (laPila->tamanioActual == laPila->tamanioMaximo) {
        bandera = 1;
    }
    else {
        bandera = 0;
    }
    return bandera;
}

int estaVacia(struct Pila* laPila) {
    int bandera = 0;
    if (laPila->aptNodoSuperior == NULL) {
        bandera = 1;
    }
    else {
        bandera = 0;
    }
    return bandera;
}
