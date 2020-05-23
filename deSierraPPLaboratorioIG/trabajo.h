#include "fecha.h"
#include "auto.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "cliente.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{

    int id;
    char patente[10];
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa las posiciones del Vector de Trabajos como vacias
 *
 * \param vec[]
 * \param tamt
 * \return Las posiciones listas para la carga de datos.
 *
 */
void inicializarTrabajos(eTrabajo vec[], int tamt);

/** \brief Ingresa los datos del Trabajo
 *
 * \param idx
 * \param vec[]
 * \param tamt
 * \param autos[]
 * \param tamauto
 * \param servicios[]
 * \param tamser
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Si la carga se hizo sin errores)
 *
 */
int altaTrabajo(int idx, eTrabajo vec[], int tamt, eAuto autos[], int tamauto, eServicio servicios[], int tamser, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Busca posiciones libres donde cargar los datos del Auto
 *
 * \param vec[]
 * \param tamt
 * \return indice = i (posicion vacia) o indice = -1 (todas las posiciones completas)
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tamt);

/** \brief Muestra un trabajo
 *
 * \param vec
 * \param servicios[]
 * \param tamser
 * \return Muestra un trabajo cargado en el sistema
 *
 */
void mostrarTrabajo(eTrabajo vec, eServicio servicios[], int tamser);

/** \brief Muestra una lista de los Trabajos cargados
 *
 * \param trabajos[]
 * \param servicios[]
 * \param tamser
 * \param tamt
 * \return Los trabajos en una lista
 *
 */
void listarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tamser, int tamt);
