#include <stdio.h>
#include <string.h>

void convertirAMayusculas(char frase[]);

int main() {
    char frase[100];
    
    printf("Ingrese una frase célebre en minúsculas: ");
    fgets(frase, sizeof(frase), stdin);
    
    convertirAMayusculas(frase);
    
    printf("La frase en mayúsculas es: %s", frase);
    
    return 0;
}

void convertirAMayusculas(char frase[]) {
    int i = 0;
    
    while(frase[i] != '\0') {
        if(frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i] - 32;
        }
        i++;
    }
}