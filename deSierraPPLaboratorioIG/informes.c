#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "auto.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "menu.h"
#include "cliente.h"

void informesLavadero(eAuto autos[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    char seguir = 's';
    do
    {
        switch(informes())
        {
        case 1:
            informarAutosDeColor(autos, tamauto, marcas, tammarca,colores, tamcolor, clientes, tamcli);
            break;
        case 2:
            informarAutosDeMarca(autos, tamauto, marcas, tammarca, colores, tamcolor,clientes, tamcli);
            break;
        case 3:
            informarAutomasViejo(autos, tamauto, marcas,tammarca,colores, tamcolor,clientes,tamcli);
            break;
        case 4:
            informarAutosXMarca(autos, tamauto, marcas,tammarca,colores, tamcolor,clientes,tamcli);
            break;
        case 5:
            informarCantidadAutosXMarcayColor(autos, tamauto, marcas,tammarca,colores, tamcolor,clientes,tamcli);
            break;
        case 6:
            printf("Salir\n");
            seguir = 'n';
            break;
        }
    }
    while (seguir == 's');
}

void informarAutosDeColor(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{

    int idColor;
    int flag = 0;
    char descripcion[20];

    system("cls");
    printf("****Informe de Autos segun Color***\n\n");

    listarColores(colores, tamcolor);
    printf("Ingrese Color: \n");
    scanf("%d", &idColor);
    cargarDescripcionColor(descripcion, idColor, colores, tamcolor);

    printf("\nAutos de Color %s \n\n", descripcion);

    printf("  ID      Patente        Marca        Color        Modelo        Cliente\n\n");

    for(int i=0; i < tamauto; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idColor == idColor)
        {
            mostrarAuto(vec[i], marcas, tammarca, colores, tamcolor, clientes, tamcli);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay Autos de ese color\n");
    }
    system("pause");
}
void informarAutosDeMarca(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{

    int idMarca;
    int flag = 0;
    char descripcion[20];

    system("cls");
    printf("****Informe de Autos x Marca***\n\n");

    listarMarcas(marcas, tammarca);
    printf("Ingrese Marca: \n");
    scanf("%d", &idMarca);
    cargarDescripcionMarca(descripcion, idMarca, marcas, tammarca);

    printf("\nAutos de la marca %s \n\n", descripcion);

    printf("  ID      Patente        Marca        Color        Modelo        Cliente\n\n");

    for(int i=0; i < tamauto; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idMarca == idMarca)
        {
            mostrarAuto(vec[i], marcas, tammarca, colores, tamcolor, clientes, tamcli);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay Autos de esa marca\n");
    }
    system("pause");
}
void informarAutomasViejo(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    eFecha fecha;
    int flag = 0;

    system("cls");
    printf("****Informe de Autos mas antiguos****\n");

    for(int e=0; e < tamauto; e++)
    {

        if(vec[e].isEmpty == 0)
        {
            if(vec[e].modelo.anio < fecha.anio|| flag == 0)
            {
                fecha.anio = vec[e].modelo.anio;
                flag = 1;
            }
        }
    }
   for(int i=0; i < tamauto; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].modelo.anio == fecha.anio)
        {
            mostrarAuto(vec[i],marcas,tammarca,colores,tamcolor,clientes,tamcli);
        }
    }
    printf("\n\n");
    system("pause");
}

void informarAutosXMarca(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{

    int flag;
    system("cls");
    printf("****Listado de Autos de todas las Marcas****\n\n");

    for(int s=0; s < tammarca; s++)
    {

        flag = 0;
        printf("Marca: %s\n", marcas[s].descripcion);
        printf("  ID      Patente        Marca        Color        Modelo        Cliente\n\n");

        for(int e=0; e < tamauto; e++)
        {
            if(vec[e].isEmpty == 0 && vec[e].idMarca == marcas[s].id)
            {
                mostrarAuto(vec[e], marcas, tammarca,colores, tamcolor, clientes,tamcli);
                flag = 1;
            }
        }
        if (flag ==0)
        {

            printf("***Sin autos***\n");
        }
        printf("\n---------------------------------------------------------------------\n");
    }
    system("pause");
}
void informarCantidadAutosXMarcayColor(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    int flag = 0;
    int cantidad = 0;
    int idColor;
    int idMarca;
    char color[20];
    char marca[20];

    system("cls");
    printf("****Cantidad de Autos segun color y marca****\n\n");

    listarColores(colores, tamcolor);
    printf("Ingrese Color: \n");
    scanf("%d", &idColor);
    cargarDescripcionColor(color, idColor, colores, tamcolor);

    listarMarcas(marcas, tammarca);
    printf("Ingrese Marca: \n");
    scanf("%d", &idMarca);
    cargarDescripcionMarca(marca, idMarca, marcas, tammarca);


    printf("\nAutos de Color %s  y marca %s\n\n", color, marca);

    for(int i=0; i < tamauto; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idMarca == idMarca && vec[i].idColor == idColor)
        {
            cantidad++;
            flag = 1;
        }
    }
    printf("Cantidad: %d\n", cantidad);
    if(flag == 0)
    {
        printf("\nNo hay Autos de ese color y marca\n");
    }
    printf("\n___________________________________\n");
    system("pause");
}
