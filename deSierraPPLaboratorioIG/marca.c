#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marca.h"


int cargarDescripcionMarca(char descripcionMarca[], int idMarca, eMarca marcas[], int tammarca)
{

    int todoOk = 0;
    for(int i=0; i < tammarca; i++)
    {
        if(marcas[i].id == idMarca)
        {
            strcpy(descripcionMarca, marcas[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}
void listarMarcas(eMarca marcas[], int tammarca)
{

    system("cls");
    printf("\n****Listado de Marcas****\n");
    printf("    Id        Marca\n\n");

    for(int i=0; i < tammarca; i++)
    {
        printf("    %d    %10s\n", marcas[i].id, marcas[i].descripcion);
    }
    printf("\n\n");
}

void mostrarMarca(eMarca vec, int tammmarca, eMarca marcas[])
{
    char descripcionMarca[20];
    cargarDescripcionMarca(descripcionMarca, vec.id, marcas, tammmarca);
    printf("\n   %d   %10s\n", vec.id, descripcionMarca);

}
