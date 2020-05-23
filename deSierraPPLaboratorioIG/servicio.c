#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"

void listarServicios(eServicio servicios[], int tamser)
{

    system("cls");
    printf("\n****Listado de Servicios****\n");
    printf("    Id          Tipo        Precio\n\n");

    for(int i=0; i < tamser; i++)
    {
        printf("    %d    %10s    %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}

void mostrarServicios(eServicio vec, int tamser, eServicio servicios[])
{
    char descripcionServicio[20];
    cargarDescripcionServicio(descripcionServicio, servicios, tamser, vec.id);
    printf("\n   %d   %10s   %.2f\n", vec.id, descripcionServicio, vec.precio);

}
int cargarDescripcionServicio(char descripcionServicio[], eServicio servicios[], int tamser, int idServicio)
{

    int todoOk = 0;
    for(int i=0; i < tamser; i++)
    {
        if(servicios[i].id == idServicio)
        {
            strcpy(descripcionServicio, servicios[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}
