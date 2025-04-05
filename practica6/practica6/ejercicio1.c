#include<stdio.h>
#include<stdlib.h>

//Se diseña la estructura del nodo.
struct Nodo{
	int valor;
	struct Nodo* aptSigNodo;
};

//Se diseña la estructura de la cola.
struct ColaCircular{
	struct Nodo* aptFrente;
	struct Nodo* aptAtras;
	int tamanioMaximo;
	int tamanioActual;		
};


void inicializar(struct ColaCircular* laColaCircular, int capacidadMaxima); //Recibe un apuntador a la cola que se va a inicializar y su capacidad máxima.
void encolar(struct ColaCircular* laColaCircular, int valorAAgregar); //Recibe un apuntador a la cola y el valor para el nodo a agregar
int desencolar(struct ColaCircular* laColaCircular); //Recibe un apuntador a la cola circular de la que se extrae un nodo
int estaLlena(struct ColaCircular* laColaCircular); //Recibe un apuntador a la cola circular que se revisará si está llena
int estaVacia(struct ColaCircular* laColaCircular); //Recibe un apuntador a la cola circular que se revisará si está vacía
void vaciar(struct ColaCircular* laColaCircular); //Recibe un apuntador a la cola circular que se vaciará
void mostrarValores(struct ColaCircular* laColaCircular);

int main(){
	struct ColaCircular laColaCircular;
	inicializar(&laColaCircular, 5);
	encolar(&laColaCircular, 1);
	encolar(&laColaCircular, 2);
	encolar(&laColaCircular, 3);
	encolar(&laColaCircular, 4);
	desencolar(&laColaCircular);
	encolar(&laColaCircular, 5);
	encolar(&laColaCircular, 6);
	encolar(&laColaCircular, 7);
	encolar(&laColaCircular, 8);
	encolar(&laColaCircular, 9);
	mostrarValores(&laColaCircular);
	vaciar(&laColaCircular);
	mostrarValores(&laColaCircular);
	return 1;
}

//Recibe un apuntador a la cola que se va a inicializar y su capacidad máxima.
void inicializar(struct ColaCircular* laColaCircular, int capacidadMaxima)
{
	laColaCircular->aptFrente = NULL;
	laColaCircular->aptAtras = NULL;
	laColaCircular->tamanioMaximo = capacidadMaxima;
	laColaCircular->tamanioActual = 0;
}

//Recibe un apuntador a la cola que se revisará si está llena.
//Regresa un 1 si está llena y un 0 si no está llena.
int estaLlena(struct ColaCircular* laColaCircular)
{
	int bandera=0;
	if(laColaCircular->tamanioActual == laColaCircular->tamanioMaximo )
	{
		bandera=1;
	}
	else
	{
		bandera=0;
	}
	return bandera;
}


//Recibe un apuntador a la cola que se revisará si está vacía.
//Regresa un 1 si está vacía y un 0 si no está vacía.
int estaVacia(struct ColaCircular* laColaCircular)
{
	int bandera=0;
	if(laColaCircular->aptAtras == NULL && laColaCircular->aptFrente==NULL)
	{
		bandera=1;
	}
	else
	{
		bandera=0;
	}
	return bandera;
}

//Recibe un apuntador a la cola y el valor para el nodo a agregar.
void encolar(struct ColaCircular* laColaCircular, int valorAAgregar)
{
	if( estaLlena(laColaCircular) == 1   )
	{
		printf("\nLa cola esta llena. No se pueden agregar elementos\n");
	}
	else
	{
		struct Nodo* aptNuevoNodo= (struct Nodo*) calloc(1, sizeof(struct Nodo) ); //Se reserva memoria para el nuevo nodo a agregar
		if(aptNuevoNodo != NULL)	//Si se pudo reservar memoria dinámicamente para ese nodo, entonces:
		{
			aptNuevoNodo->valor = valorAAgregar;	//Se asigna el valor indicado al nodo que se agregará al final de la cola
			aptNuevoNodo->aptSigNodo = NULL;	//De inicio el nuevo nodo apunta a NULL
			
			if( estaVacia(laColaCircular) == 1  )	//Si la cola está vacía, significa que el nodo a agregar será el único de la cola
			{
				laColaCircular->aptFrente = aptNuevoNodo;	//Se hace que el aptFrente apunte al nuevo nodo
				laColaCircular->aptAtras = aptNuevoNodo;	//Se hace que el aptAtras apunte al nuevo nodo
			}
			else	//Si la cola NO está vacía,
			{	
				laColaCircular->aptAtras->aptSigNodo = aptNuevoNodo;	//Se hace que el nodo que actualmente está hasta 
																		//atrás apunte al nuevo nodo, que será el último.
				laColaCircular->aptAtras = aptNuevoNodo;				//Se hace que el aptAtras apunte al nuevo nodo.

				
			}


			/*La siguiente linea permite la circularidad*/
			//Se hace que el nodo de hasta atrás apunte al nodo que está hasta enfrente.
			//IMPORTANTE: Esto debe ser común a si se inserta un nuevo nodo o si ya había nodos
			laColaCircular->aptAtras->aptSigNodo = laColaCircular->aptFrente;			

			laColaCircular->tamanioActual++;	//Se incrementa el tamanio de la cola en uno
			printf("\nSe agregó el valor: %i\n", laColaCircular->aptAtras->valor);	//Se imprime el valor del nuevo nodo que está hasta atrás
		}
		else
		{
			printf("\nNo se pudo reservar memoria para el nuevo nodo\n");
		}
		
	}
}

//Recibe un apuntador a la cola circular de la que se extrae un nodo
//Regresa el valor del nodo desencolado
int desencolar(struct ColaCircular* laColaCircular)
{
    int valorExtraido = -1;  // Valor por defecto si la cola está vacía
    
    if(estaVacia(laColaCircular) == 1)
    {
        printf("\nLa cola está vacía. No se pueden extraer elementos\n");
    }
    else
    {
        struct Nodo* aptNodoAEliminar = laColaCircular->aptFrente;  // Se guarda una referencia al nodo a eliminar
        valorExtraido = aptNodoAEliminar->valor;  // Se guarda el valor del nodo a eliminar
        
        if(laColaCircular->aptFrente == laColaCircular->aptAtras)  // Si solo hay un nodo en la cola
        {
            laColaCircular->aptFrente = NULL;
            laColaCircular->aptAtras = NULL;
        }
        else
        {
            laColaCircular->aptFrente = aptNodoAEliminar->aptSigNodo;  // El frente apunta al siguiente nodo
            laColaCircular->aptAtras->aptSigNodo = laColaCircular->aptFrente;  // Se actualiza la referencia circular
        }
        
        free(aptNodoAEliminar);  // Se libera la memoria del nodo eliminado
        laColaCircular->tamanioActual--;  // Se decrementa el tamaño actual de la cola
        printf("\nSe extrajo el valor: %i\n", valorExtraido);
    }
    
    return valorExtraido;
}

//Muestra los valores de todos los nodos de la cola circular
void mostrarValores(struct ColaCircular* laColaCircular)
{
    if(estaVacia(laColaCircular) == 1)
    {
        printf("\nLa cola está vacía. No hay elementos que mostrar\n");
    }
    else
    {
        struct Nodo* aptNodoActual = laColaCircular->aptFrente;
        int contador = 0;
        
        printf("\nValores en la cola circular:\n");
        do
        {
            printf("Posición %d: %d\n", contador, aptNodoActual->valor);
            aptNodoActual = aptNodoActual->aptSigNodo;
            contador++;
        } while(aptNodoActual != laColaCircular->aptFrente);
        
        printf("Tamaño actual de la cola: %d\n", laColaCircular->tamanioActual);
        printf("Tamaño máximo de la cola: %d\n", laColaCircular->tamanioMaximo);
    }
}

//Vacia completamente la cola circular
void vaciar(struct ColaCircular* laColaCircular)
{
    if(estaVacia(laColaCircular) == 1)
    {
        printf("\nLa cola ya está vacía\n");
    }
    else
    {
        printf("\nVaciando la cola circular...\n");
        
        while(estaVacia(laColaCircular) != 1)
        {
            desencolar(laColaCircular);
        }
        
        printf("La cola ha sido vaciada completamente\n");
    }
}