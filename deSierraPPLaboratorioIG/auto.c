#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "datawarehouse.h"
#include "auto.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"
#include "menu.h"
#include "cliente.h"

void hardcodearAutos(eAuto vec[], int cant)
{

    for(int i=0; i < cant; i++)
    {
        vec[i].id = idsAuto[i];
        strcpy( vec[i].patente, patentes[i]);
        vec[i].idMarca = idMarcas[i];
        vec[i].idColor = idColors[i];
        vec[i].modelo.anio = modelos[i];
        vec[i].idCliente = idClientes[i];
        vec[i].isEmpty = 0;
    }
}

void inicializarAutos(eAuto vec[], int tamauto)
{

    for(int i=0; i < tamauto; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int altaAuto(int idx, eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    int todoOk = 0;
    int indice = buscarLibreAuto(vec, tamauto);
    eAuto auxAuto;

    system("cls");
    printf("***Alta Auto***\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxAuto.id = idx;

        utn_getNombre(auxAuto.patente, 10, "Ingrese la patente del vehiculo: \n", "Ingreso un caracter invalido, reingrese: \n",50);
        auxAuto.patente[10] = toupper(auxAuto.patente[10]);

        listarMarcas(marcas, tammarca);
        utn_getNumero(&auxAuto.idMarca, "Ingrese el Id de la Marca: \n", "Id de la marca invalido. Reingrese: \n", 1000, 1004, 50);

        listarColores(colores, tamcolor);
        utn_getNumero(&auxAuto.idColor, "Ingrese el Id del color: \n", "Id color invalido. Reingrese: \n", 5000, 5004, 50);

        system("cls");
        utn_getNumero(&auxAuto.modelo.anio, "\nIngrese el modelo (anio de fabricacion): \n", "No es un año valido. Reingrese: \n", 1950, 2020, 50);

        listarClientes(tamcli, clientes);
        utn_getNumero(&auxAuto.idCliente, "Ingrese el id del cliente: \n", "Id erroneo. Reintente: \n",8001,8999,50);

        auxAuto.isEmpty = 0;
        vec[indice] = auxAuto;
        todoOk = 1;
        printf("Auto ingresado correctamente\n\n");
    }

    return todoOk;
}
int buscarLibreAuto(eAuto vec[], int tamauto)
{

    int indice = -1;

    for(int i=0; i < tamauto; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    printf("No hay espacio para ingresar mas autos\n\n");
    return indice;
}

int modificarAuto(eAuto vec[], int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca, eCliente clientes[], int tamcli)
{
    int exit = 0;
    char patente[10];
    int indice;
    char confirma;
    int nuevoColor;
    int nuevoCliente;
    eFecha nuevoModelo;

    system("cls");

    printf("***Modificar Auto***\n\n");
    listarAutos(tamauto, vec, marcas, tammarca, colores, tamcolor, clientes, tamcli);
    utn_getNombre(patente, 10, "Ingrese la patente a modificar: \n", "Patente erronea. Reingrese: \n", 50);

    indice = buscarAuto(patente, vec, tamauto);

    if(   indice == -1   )
    {

        printf("No hay registro de un auto con la patente: %s\n", patente);
    }
    else
    {
        mostrarAuto(vec[indice], marcas, tammarca, colores, tamcolor, clientes, tamcli);

        printf("Ingrese el tipo de dato que desea modificar: ");
        switch(submenuAuto())
        {
        case 1:
            printf("\nModifica el color?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                listarColores(colores, tamcolor);
                utn_getNumero(&nuevoColor,"Ingrese el nuevo ID de color: ", "\nId de Color Invalido. Reingrese: ", 5000, 5004, 50);
                vec[indice].idColor = nuevoColor;
                printf("Se ha actualizado el color con éxito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 2:
            printf("\nModifica el modelo?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                utn_getNumero(&nuevoModelo.anio, "Ingrese el nuevo modelo (anio de fabricacion): \n", "No es un anio valido. Reingrese: \n", 1950, 2020, 50);
                vec[indice].modelo.anio = nuevoModelo.anio;
                printf("Se ha actualizado el modelo con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 3:
            printf("\nModifica el cliente?: (s/n)\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if( confirma == 's')
            {
                listarClientes(tamcli, clientes);
                utn_getNumero(&nuevoCliente, "Ingrese el nuevo id del cliente: \n", "Id erroneo. Reintente: \n",8001,8999,50);
                vec[indice].idCliente = nuevoCliente;
                printf("Se ha actualizado el cliente con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 4:
            printf("Salir\n");
            exit = 1;
            break;
        default:
            printf("No es un parametro valido");
            break;
        }
    }
    return exit;
}
int buscarAuto(char* patente, eAuto vec[], int tamauto)
{
    int indice = -1;

    for(int i=0; i < tamauto; i++)
    {
        if((strcmp(vec[i].patente, patente)== 0) && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaAuto(eAuto vec[], int tamauto, eMarca marcas[], int tammarca,eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{

    char patente[10];
    int indice;
    char confirma;

    system("cls");
    printf("***Baja Auto***\n\n");
    listarAutos(tamauto,vec, marcas, tammarca, colores, tamcolor, clientes, tamcli);
    utn_getNombre(patente, 10, "Ingrese la patente: \n", "Patente erronea. Reingrese: \n", 50);

    indice = buscarAuto(patente, vec, tamauto);

    if(   indice == -1   )
    {

        printf("No hay registro de un auto con la patente: %s\n", patente);
    }
    else
    {
        printf("\nConfirma BAJA?: (s/n)\n");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n");
        }
    }
}

void mostrarAuto(eAuto vec, eMarca marcas[], int tammarca,eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    char descripcionMarca[20];
    char descripcionColor[20];
    char nombreCliente[20];

    cargarDescripcionMarca(descripcionMarca, vec.idMarca, marcas, tammarca);
    cargarDescripcionColor(descripcionColor, vec.idColor, colores, tamcolor);
    cargarNombreCliente(nombreCliente, clientes, tamcli, vec.idCliente);
    printf("\n   %d   %10s   %10s   %10s      %4d         %10s\n", vec.id, vec.patente, descripcionMarca, descripcionColor, vec.modelo.anio, nombreCliente);

}
int ordenarAutos(eAuto* autos, int tamauto, eMarca* marcas, int tammarca, eColor* colores, int tamcolor, eCliente clientes[], int tamcli)
{
    int retorno = -1;
    eAuto auxAuto;

    for(int i=0; i < tamauto -1; i++)
    {
        for(int j=i+1; j < tamauto; j++)
        {
            if( (autos[i].idMarca < autos[j].idMarca) ||
                    (autos[i].idMarca == autos[j].idMarca && strcmp(autos[i].patente, autos[j].patente)<0))
            {
                auxAuto = autos[i];
                autos[i] = autos[j];
                autos[j] = auxAuto;
            }
        }
    }
    listarAutos(tamauto,autos, marcas,tammarca,colores,tamcolor, clientes, tamcli);
    retorno = 0;
    return retorno;
}

void listarAutos(int tamauto, eAuto autos[], eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli)
{
    int flag = 0;
    system("cls");
    printf("\n****Listado de Autos****\n");
    printf("  ID      Patente        Marca        Color        Modelo        Cliente\n\n");


    for(int i=0; i < tamauto; i++)
    {
        if(autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], marcas, tammarca, colores, tamcolor, clientes, tamcli);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("\n\nNo hay autos que listar");
    }
    printf("\n\n");
}
