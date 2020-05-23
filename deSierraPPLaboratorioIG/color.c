#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"


int cargarDescripcionColor(char descripcionColor[], int idColor, eColor colores[], int tamcolor)
{

    int todoOk = 0;
    for(int i=0; i < tamcolor; i++)
    {
        if(colores[i].id == idColor)
        {
            strcpy(descripcionColor, colores[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}


void listarColores(eColor colores[], int tamcolor)
{

    system("cls");
    printf("\n****Listado de Colores****\n");
    printf("    Id          Color\n\n");

    for(int i=0; i < tamcolor; i++)
    {
        printf("    %d    %10s\n", colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");
}
