#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "fecha.h"
#include "auto.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"
#include "cliente.h"

void inicializarTrabajos(eTrabajo vec[], int tamt)
{

    for(int i=0; i < tamt; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int altaTrabajo(int idx, eTrabajo vec[], int tamt, eAuto autos[], int tamauto, eServicio servicios[], int tamser, eMarca marcas[],int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    int todoOk = 0;
    int patenteValida;
    int indice = buscarLibreTrabajo(vec, tamt);
    eTrabajo auxTrabajo;

    system("cls");
    printf("***Alta Trabajo***\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        listarAutos(tamauto, autos, marcas, tammarca, colores, tamcolor, clientes, tamcli);
        utn_getNombre(auxTrabajo.patente, 10, "Ingrese la patente: \n", "Patente erronea. Reingrese: \n", 50);

        patenteValida = buscarAuto(auxTrabajo.patente, autos, tamauto);

        if(patenteValida == -1)
        {
            printf("La patente ingresada no existe\n");
            system("pause");
        }
        else
        {
            auxTrabajo.id = idx;

            listarServicios(servicios, tamser);
            utn_getNumero(&auxTrabajo.idServicio, "Ingrese el Id de un servicio: ", "\nId de Servicio invalido, reingrese: ", 20000, 20999, 50);

            auxTrabajo.fecha = utn_getFecha();
            auxTrabajo.isEmpty = 0;
            vec[indice] = auxTrabajo;
            todoOk = 1;
        }
    }
    return todoOk;
}
int buscarLibreTrabajo(eTrabajo vec[], int tamt)
{

    int indice = -1;

    for(int i=0; i < tamt; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajo vec, eServicio servicios[], int tamser)
{
    char descripcionServicio[20];

    cargarDescripcionServicio(descripcionServicio, servicios, tamser, vec.idServicio);
    printf("\n   %d      %10s      %10s      %2d/%2d/%4d\n", vec.id, vec.patente, descripcionServicio, vec.fecha.dia, vec.fecha.mes, vec.fecha.anio);

}
void listarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tamser, int tamt)
{

    system("cls");
    printf("\n****Listado de Trabajos****\n");
    printf("    Id        Patente        Id Servicio        Fecha\n\n");

    for(int i=0; i < tamt; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamser);
        }
    }
    printf("\n\n");
}
