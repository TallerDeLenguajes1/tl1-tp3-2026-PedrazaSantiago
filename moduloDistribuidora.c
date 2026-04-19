#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
};

void MostrarClientes(struct Cliente *clientes, int n);
int costo(struct Producto Productos);
int main(){
    int n;
    char buff[100];
    do{
    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d",&n);
    }while(n<1||n>5);
    struct Cliente *clientes = (struct Cliente*) malloc(sizeof(struct Cliente)*n);
    for(int i=0;i<n;i++){
        clientes[i].ClienteID = i+1;
        printf("Ingrese el nombre del cliente:\n");
        fflush(stdin);
        gets(buff);
        clientes[i].NombreCliente = (char*) malloc(sizeof(strlen(buff))+1);
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = rand() % 5 +1;
        clientes[i].Productos = (struct Producto*) malloc(sizeof(struct Producto)*clientes[i].CantidadProductosAPedir);

        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10; 
        }
    }
    MostrarClientes(clientes,n);
    for(int i=0; i<n; i++){
        free(clientes[i].Productos);
        free(clientes[i].NombreCliente);
    }
    free(clientes);
    return 0;
}

void MostrarClientes(struct Cliente *clientes, int n){
    int total;
    for(int i=0; i<n; i++){
        printf("Cliente %d\n",clientes[i].ClienteID);
        printf("Nombre del cliente:%s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos del cliente:%d\n",clientes[i].CantidadProductosAPedir);
        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            printf("Id del producto:%d\n",clientes[i].Productos[j].ProductoID);
            printf("Nombre del producto:%s\n",clientes[i].Productos[j].TipoProducto);
            printf("Cantidad del producto:%d\n",clientes[i].Productos[j].Cantidad);
            printf("Precio unitario del producto:%.2f\n",clientes[i].Productos[j].PrecioUnitario);
            total=total + costo(clientes[i].Productos[j]);                               
        }
        printf("Total a pagar:%d\n",total);
    }
}

int costo(struct Producto Productos){
    return Productos.PrecioUnitario * Productos.Cantidad;
}
