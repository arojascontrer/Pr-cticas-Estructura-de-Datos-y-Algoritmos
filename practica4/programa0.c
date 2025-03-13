#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int i;
    char string [8];
    char *add_string = NULL;
    printf("ingrese caracter:\n");
    for ( i = 0; i < 7; i++)
    {
        printf("%d:", i + 1);
        scanf("%c", &string[i]);
        getchar();
    }

    char ans[3];
    printf("¿Quiere almacenar más caracteres?: ");
    scanf("%s", ans);
    int add;
    
    if (strcmp(ans, "SI") == 0 || strcmp(ans, "si") == 0 || strcmp(ans, "Si") == 0)
    {
    
        printf("¿Cuántos caracteres adicionales quiere agregar?:");
        scanf("%d", &add);
        if (add<=0)
        {
            printf("error:no se puede almacenar espacios menores o iguales a 0");
            return 1;
        }
        else
        add_string = (char*)calloc(add, sizeof(char));
        printf("ingrese caracter(es) adicional(es):\n");
        
        if (add_string == NULL) {
            printf("Error: No se pudo reservar memoria.\n");
            return 1;
        }
            else
        getchar();

        for ( i = 0; i < add; i++)
        {
            printf("%d:", i + 1);
            scanf("%c", &add_string[i]);
            getchar();
        }
        printf("Datos ingresados:\n");
        for (i = 0; i < 7; i++) {
            printf("%c", string[i]);
        }
        for ( i = 0; i < add; i++)
        {
            printf("%c", add_string[i]);
        }
        printf("\n");
        return 0;
    }
    else
    printf("Datos ingresados:\n");
    for (i = 0; i < 7; i++) {
        printf("%c", string[i]);
    }
    printf("\n");   
    return 0;
}