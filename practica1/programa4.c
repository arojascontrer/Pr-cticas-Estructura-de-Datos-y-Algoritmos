#include <stdio.h>
#include <string.h>

int main(){
    int i,j;
    
    printf("Introduzca número de usuarios(máx 10):");
    scanf("%d",&j);
    
    
    char usuarios[j][30];
    char apodo[j][15];
    char contraseña[j][10];
    int edad[j];
    float estatura[j];
    char letra[j];
    
    if (j<=10){
        for(i = 0; i <= j; i++){
            printf("Introduzca el nombre del usuario[%d](máx 30)",i+1);
            fgets(usuarios[i],30,stdin);
            printf("Introduzca el apodo del usuario[%d](máx 15)",i+1);
            fgets(apodo[i],15,stdin);
            printf("Introduzca la contraseña del usuario[%d](máx 10)",i+1);
            fgets(contraseña[i],10,stdin);
            printf("Introduzca la edad del usuario[%d](máx 30)",i+1);
            fgets(edad[i],30,stdin);
            printf("Introduzca la estatura del usuario[%d](máx 15)",i+1);
            scanf("%f",estatura[i]);
            printf("Introduzca letra preferida del usuario[%d](máx 10)",i+1);
            fgets(letra[i],10,stdin);

        }    
    }
    else
    {
    printf("El número de usuarios es mayor al permitido");
    }
    
    return 0;
}