#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "fecha.h"

int esNumerica(char* cadena, int limite)
{
    int retorno = 1;
    int i;
    for(i=0; i<limite && cadena[i] != '\0'; i++)
    {
        if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
        {
            continue;
        }
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
            getString(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString) ;
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if(	getInt(&bufferInt) == 0 &&
                bufferInt >= minimo &&
                bufferInt <= maximo)
        {
            retorno = 0;
            *pResultado = bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }
    while(reintentos>=0);

    return retorno;
}
int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

int esFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,	float minimo, float maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if(	getString(buffer,sizeof(buffer))==0 &&
                esNombre(buffer,sizeof(buffer)) &&
                strlen(buffer)<longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

int esNombre(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
                    (cadena[i] < 'a' || cadena[i] > 'z') &&
                    (cadena[i] < '0' || cadena[i] > '9' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strlen(bufferString) < longitud )
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
eFecha utn_getFecha()
{
    eFecha fecha;

    printf("\n\nIngrese fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    fflush(stdin);


    if((fecha.anio > 1950 || fecha.anio < 2020) ||
            (fecha.mes  >0 || fecha.mes < 12) || (fecha.dia  >0 || fecha.dia < 31))
    {
        if(fecha.anio > 1900 && fecha.anio / 4 == 0 && fecha.anio / 100 == 0 && fecha.anio / 400 == 0 && fecha.mes == 2)
        {
            fecha.dia = utn_esFecha(fecha.dia, 1, 29);
        }
        else
        {
            fecha.mes = utn_esFecha(fecha.mes, 1, 12);
            switch(fecha.mes)
            {
            case 1:
                fecha.dia = utn_esFecha(fecha.dia, 1, 28);
                break;
            case 2:
                fecha.dia = utn_esFecha(fecha.dia, 1, 30);
                break;
            default:
                fecha.dia = utn_esFecha(fecha.dia, 1, 31);
                break;
            }
        }
    }
    else
    {
        printf("\n\nLa Fecha no es valida. Reingrese (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    return fecha;
}
int utn_esFecha(int fecha, int minimo, int maximo)
{
    if (fecha < minimo || fecha > maximo)
    {
        return -1;
    }
    else
    {
        return fecha;
    }
}
