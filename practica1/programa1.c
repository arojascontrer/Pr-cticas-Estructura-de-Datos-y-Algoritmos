
#include <stdio.h>
#include <string.h>
#define MAX 51
int main() {
char frase[MAX], inverso[MAX], modificada[MAX];
int i, j = 0;
printf("Ingrese una frase (máx %d caracteres): ", MAX - 1);
fgets(frase, MAX, stdin);
frase[strcspn(frase, "\n")] = 0;
int len = strlen(frase);
printf("\n1. Letras separadas por guiones:\n");
for (i = 0; i < len; i++) {
printf("%c", frase[i]);
if (i < len - 1) printf("-");
}
printf("\n");
printf("\n2. Letras en índices impares:\n");
for (i = 1; i < len; i += 2) {
printf("%c", frase[i]);
if (i + 2 < len) printf("-");
}
printf("\n");
printf("\n3. Letras en orden inverso:\n");
for (i = len - 1; i >= 0; i--) {
printf("%c", frase[i]);
if (i > 0) printf("-");
}
printf("\n");
printf("\n4. Vocales de la palabra:\n");
for (i = 0; i < len; i++) {
if (strchr("AEIOUaeiou", frase[i])) {
printf("%c", frase[i]);
if (i < len - 1) printf("-");
}
}
printf("\n");
for (i = 0; i < len; i++) {
inverso[i] = frase[len - 1 - i];
}
inverso[len] = '\0';
printf("\n5. Frase al revés: %s\n", inverso);
strcpy(modificada, frase);
for (i = 0; i < len; i++) {
switch (modificada[i]) {
case 'A': case 'a': modificada[i] = '4'; break;
case 'E': case 'e': modificada[i] = '3'; break;
case 'I': case 'i': modificada[i] = '1'; break;
case 'O': case 'o': modificada[i] = '0'; break;
}
}
printf("\n6. Frase con vocales reemplazadas: %s\n", modificada);
return 0;
}