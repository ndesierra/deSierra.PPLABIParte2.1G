#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "menu.h"
#include "informes.h"
#include "cliente.h"

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMAUTO 50
#define TAMSER 4
#define TAMT 50
#define TAMCLI 5
#define TAMM 10
#define HARD_TAM 5

int main()
{
    char seguir = 's';
    int idAuto = 1;
    int proximoidTrabajo = 1;
    int flagAlta = 0;
    eMarca marcas [TAMMARCA] = {{1000,"Renault" },{1001, "Fiat"},{1002, "Ford"},{1003, "Chevrolet"},{1004,"Peugeot" }};
    eColor colores [TAMCOLOR]= {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};
    eAuto autos [TAMAUTO];
    eServicio servicios [TAMSER] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eTrabajo trabajos [TAMT];
    eCliente clientes[TAMCLI] = {{8001,"Juan",'m'},{8003,"Lucia",'f'},{8004,"Miguel",'m'},{8005,"Daniela",'f'},{8006,"Sofia",'f'}};

    inicializarAutos(autos, TAMAUTO);
    inicializarTrabajos(trabajos, TAMT);

    hardcodearAutos(autos, HARD_TAM);
    idAuto+= HARD_TAM;


    do
    {
        switch(menu())
        {
        case 'A':
            if ((altaAuto(idAuto, autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLI))== 1)
            {
                idAuto++;
                flagAlta = 1;
            }
            break;
        case 'B':
            if( flagAlta == 1)
            {
                modificarAuto(autos, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA, clientes, TAMCLI);
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'C':
            if( flagAlta == 1)
            {
                bajaAuto(autos,TAMAUTO, marcas, TAMMARCA, colores,TAMCOLOR, clientes, TAMCLI);
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'D':
            if( flagAlta == 1)
            {
                ordenarAutos(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLI);
                system("pause");
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'E':
            listarMarcas(marcas, TAMMARCA);
            system("pause");
            break;
        case 'F':
            listarColores(colores, TAMCOLOR);
            system("pause");
            break;
        case 'G':
            listarServicios(servicios, TAMSER);
            system("pause");
            break;
        case 'H':
            if( flagAlta == 1)
            {
                if(altaTrabajo(proximoidTrabajo, trabajos,TAMT, autos, TAMAUTO, servicios, TAMSER, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLI)== 1)
                {
                    proximoidTrabajo++;
                }
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'I':
            if( flagAlta == 1)
            {
                listarTrabajos(trabajos, servicios, TAMSER, TAMT);
                system("pause");
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'J':
            if( flagAlta == 1)
            {
                informesLavadero(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLI);
                system("pause");
            }
            else
            {
                printf("Primero debe efectuar el Alta de un Auto\n\n");
                system("pause");
            }
            break;
        case 'K':
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida. Reingrese: \n");
            system("pause");
            break;
        }
    }
    while (seguir == 's');
    return 0;
}
