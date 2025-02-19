#include <stdio.h>
 
int main(){
    
    int arreglo[4][3];
    int i, j;
    //obtener arreglo
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("[%d][%d]:", i, j);
            scanf("%d",&arreglo[i][j]);
        }
    }
    printf("\n");
    
    // Forma 1
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", arreglo[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");
    
    // Forma 2
    for (i = 3; i >= 0; i--) {
        for (j = 2; j >= 0; j--) {
            printf("%d\t", arreglo[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // Forma 3
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            printf("%d\t", arreglo[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");

    // forma 4
    for (j = 2; j >= 0; j--) {
        for (i = 3; i >= 0; i--) {
            printf("%d\t", arreglo[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}