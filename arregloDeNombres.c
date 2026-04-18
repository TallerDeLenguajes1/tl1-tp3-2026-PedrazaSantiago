#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *nombres[]);
void BuscarNombrePorId(int id,char *nombres[]);
int BuscarNombrePorPalabra(char *palabra,char *nombres[]);
int main(){
    int opcion;
    char palabra[20];
    int id;
    char *nombres[5];
    char buff[120];
    for(int i=0;i<5;i++){
        printf("Ingrese Nombre:");
        gets(buff);
        int cantLetras = strlen(buff);   
        nombres[i] = (char *) malloc (sizeof(char) * cantLetras + 1);  
        strcpy(nombres[i], buff); 
    }
    MostrarPersonas(nombres);
    printf("Elija una opcion:\n");
    scanf("%d",&opcion);
    switch (opcion)
    {
    case 1:
        printf("Escriba la posicion a buscar:\n");
        scanf("%d", &id);
        BuscarNombrePorId(id,nombres);
        break;
    case 2:
        printf("Escriba la palabra a buscar:\n");
        fflush(stdin);
        gets(palabra);
        int indice = BuscarNombrePorPalabra(palabra,nombres);
        if(indice !=-1){
            printf("%s",nombres[indice]);
        }else{
            printf("Palabra no encontrada");
        }
        break;
    default:
        break;
    }
    for(int i=0;i<5;i++){
        free(nombres[i]);
    }
    return 0;
}

void MostrarPersonas(char *nombres[]){
    for(int i=0;i<5;i++){
        printf("%s\n",nombres[i]);
    }
}
void BuscarNombrePorId(int id, char *nombres[]){
    if(id<0 || id>=5){
        printf("No se encontro el valor buscado");
    }{
        printf("%s\n", nombres[id]);
    }
}

int BuscarNombrePorPalabra(char *palabra,char *nombres[]){
    char resultado[20];
    for(int i=0;i<5;i++){
        if(strstr(nombres[i], palabra)!=NULL){
            return i;
        }
    }
    return -1;
}



