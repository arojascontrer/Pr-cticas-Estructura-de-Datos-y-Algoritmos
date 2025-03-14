#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[8]; 
    char *add_string = NULL;
    char *final_string = NULL;
    
    printf("Introduce una cadena de caracteres (MAX 7): ");
    fgets(string, 8, stdin);
    
    char ans[3];
    printf("¿Quiere almacenar más caracteres? (SI/NO): ");
    scanf("%s", ans);
    
    if (strcmp(ans, "SI") == 0 || strcmp(ans, "si") == 0 || strcmp(ans, "Si") == 0) {
        int add;
        printf("¿Cuántos caracteres adicionales quiere agregar?: ");
        scanf("%d", &add);
        
        if (add <= 0) {
            printf("Error: No se puede almacenar espacios menores o iguales a 0\n");
            return 1;
        }
        
        while (getchar() != '\n');
        
        add_string = (char*)malloc((add + 1) * sizeof(char));
        
        if (add_string == NULL) {
            printf("Error: No se pudo reservar memoria.\n");
            return 1;
        }
        
        printf("Ingrese caracteres adicionales: ");
        fgets(add_string, add + 1, stdin);
        
        final_string = (char*)malloc((strlen(string) + strlen(add_string) + 1) * sizeof(char));
        
        if (final_string == NULL) {
            printf("Error: No se pudo reservar memoria para la cadena final.\n");
            free(add_string);
            return 1;
        }
        
        strcpy(final_string, string);
        strcat(final_string, add_string);
        
        printf("Cadena modificada:\n%s", final_string);
        
        free(add_string);
        free(final_string);
    } else {
        printf("Cadena ingresada:\n%s", string);
    }
    
    return 0;
}