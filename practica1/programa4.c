#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 10
#define MAX_NOMBRE 100
#define MAX_NICKNAME 30
#define MAX_PASSWORD 20

int main() {
    int numUsuarios, i, opcion;
    
    char nombres[MAX_USUARIOS][MAX_NOMBRE];
    char nicknames[MAX_USUARIOS][MAX_NICKNAME];
    char passwords[MAX_USUARIOS][MAX_PASSWORD];
    int edades[MAX_USUARIOS];
    float estaturas[MAX_USUARIOS];
    char letras[MAX_USUARIOS];
    
    printf("¿Cuántas personas desea registrar? (máximo %d): ", MAX_USUARIOS);
    scanf("%d", &numUsuarios);
    getchar(); 
    
    if (numUsuarios > MAX_USUARIOS) {
        printf("Error: No se pueden registrar más de %d personas.\n", MAX_USUARIOS);
        return 1;
    }
    
    for (i = 0; i < numUsuarios; i++) {
        printf("\n--- Registro del usuario %d ---\n", i+1);
        
        printf("Nombre completo (incluya apellidos): ");
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0; 
        
        printf("Nickname: ");
        fgets(nicknames[i], MAX_NICKNAME, stdin);
        nicknames[i][strcspn(nicknames[i], "\n")] = 0;
        
        printf("Contraseña: ");
        fgets(passwords[i], MAX_PASSWORD, stdin);
        passwords[i][strcspn(passwords[i], "\n")] = 0;
        
        printf("Edad: ");
        scanf("%d", &edades[i]);
        getchar();
        
        printf("Estatura (en metros): ");
        scanf("%f", &estaturas[i]);
        getchar(); 
        
        printf("Letra favorita: ");
        scanf("%c", &letras[i]);
        getchar();
    }
    
    printf("\n--- Lista de usuarios registrados ---\n");
    for (i = 0; i < numUsuarios; i++) {
        printf("%d. %s\n", i+1, nicknames[i]);
    }
    
    do {
        printf("\nIngrese el número del usuario del cual desea ver sus datos (1-%d, 0 para salir): ", numUsuarios);
        scanf("%d", &opcion);
        
        if (opcion > 0 && opcion <= numUsuarios) {
            i = opcion - 1;
            printf("\n--- Datos completos del usuario %d ---\n", opcion);
            printf("Nombre completo: %s\n", nombres[i]);
            printf("Nickname: %s\n", nicknames[i]);
            printf("Contraseña: %s\n", passwords[i]);
            printf("Edad: %d años\n", edades[i]);
            printf("Estatura: %.2f metros\n", estaturas[i]);
            printf("Letra favorita: %c\n", letras[i]);
        } else if (opcion != 0) {
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 0);
    
    printf("Programa finalizado.\n");
    return 0;
}