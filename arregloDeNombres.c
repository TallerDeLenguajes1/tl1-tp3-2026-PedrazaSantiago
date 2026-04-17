#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char *nombres[]);
int main(){
    char *nombres[5];
    char buff[120];
    for(int i=0;i<5;i++){
        printf("Ingrese Nombre:");
        gets(buff);
        int cantLetras = strlen(buff);   
        nombres[i] = (char *) malloc (sizeof(char) * cantLetras + 1);  
        strcpy(nombres[i], buff); 
    }
    mostrarPersonas(nombres);
    for(int i=0;i<5;i++){
        free(nombres[i]);
    }

    return 0;
}

void mostrarPersonas(char *nombres[]){
    for(int i=0;i<5;i++){
        printf("%s\n",nombres[i]);
    }
}