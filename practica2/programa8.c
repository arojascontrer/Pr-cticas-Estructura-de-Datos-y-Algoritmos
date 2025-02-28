#include <stdio.h>
#include <string.h>

void convertirAMayusculas(char *frase);

int main() {
    char frase[100];
    
    printf("Ingrese una frase célebre en minúsculas: ");
    fgets(frase, sizeof(frase), stdin);
    
    convertirAMayusculas(frase);
    
    printf("La frase en mayúsculas es: %s", frase);
    
    return 0;
}

void convertirAMayusculas(char *frase) {
    while(*frase != '\0') {
        if(*frase >= 'a' && *frase <= 'z') {
            *frase = *frase - 32;
        }
        frase++;
    }
}
