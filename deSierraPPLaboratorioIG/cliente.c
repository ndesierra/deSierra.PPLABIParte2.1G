#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

void listarClientes(int tamcli, eCliente clientes[])
{
    int flag = 0;
    system("cls");
    printf("\n****Listado de Clientes****\n");
    printf("  ID      Nombre        Sexo\n\n");


    for(int i=0; i < tamcli; i++)
    {
           printf("    %d    %10s    %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
           flag = 1;
    }
    if( flag == 0)
    {
        printf("\n\nNo hay clientes que listar");
    }
    printf("\n\n");
}
int cargarNombreCliente(char nombreCliente[], eCliente clientes[], int tamcli, int idCliente)
{

    int todoOk = 0;
    for(int i=0; i < tamcli; i++)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(nombreCliente, clientes[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}
