#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

char menu()
{
    char opcion;

    system("cls");
    printf("***Gestion de Lavadero***\n\n");
    printf("A.	ALTA AUTO\n");
    printf("B.	MODIFICAR AUTO\n");
    printf("C.	BAJA AUTO\n");
    printf("D.	LISTAR AUTOS\n");
    printf("E.	LISTAR  MARCAS \n");
    printf("F.	LISTAR COLORES\n");
    printf("G.	LISTAR SERVICIOS\n");
    printf("H.	ALTA TRABAJO\n");
    printf("I.	LISTAR TRABAJOS\n");
    printf("J.	INFORMES\n");
    printf("K.      SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;

}

int submenuAuto()
{
    int opcion;

    system("cls");
    printf("***Parametros***\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Cliente\n");
    printf("4. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informes()
{
    int opcion;

    system("cls");
    printf("***Informes de Lavadero***\n\n");
    printf("1. Autos de un color\n");
    printf("2. Autos de una marca\n");
    printf("3. Autos mas viejos\n");
    printf("4. Autos separados por marca\n");
    printf("5. Autos de una marca y color\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
