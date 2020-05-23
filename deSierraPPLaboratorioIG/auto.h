#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "cliente.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{

    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int idCliente;
    eFecha modelo;
    int isEmpty;

} eAuto;

#endif // AUTO_H_INCLUDED

/** \brief Permite testear el funcionamiento del programa cargando datos de Autos
 *
 * \param vec[]
 * \param cant
 * \return Los datos cargados para el testeo.
 *
 */
void hardcodearAutos(eAuto vec[], int cant);

/** \brief Inicializa las posiciones del Vector de Autos como vacias
 *
 * \param vec[]
 * \param tamauto
 * \return Las posiciones listas para la carga de datos.
 *
 */
void inicializarAutos(eAuto vec[], int tamauto);

/** \brief Ingresa los datos del Auto
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Si la carga se hizo sin errores)
 *
 */
int altaAuto(int idx, eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Busca posiciones libres donde cargar los datos del Auto
 *
 * \param vec[]
 * \param tamauto
 * \return indice = i (posicion vacia) o indice = -1 (todas las posiciones completas)
 *
 */
int buscarLibreAuto(eAuto vec[], int tamauto);

/** \brief Modifica los datos del Auto
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return exit = 0 (ERROR) o exit = 1 (Si la modificacion se hizo sin errores)
 *
 */
int modificarAuto(eAuto vec[], int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca, eCliente clientes[], int tamcli);

/** \brief Busca un Auto por la patente
 *
 * \param patente
 * \param vec[]
 * \param tamauto
 * \return indice = i (Si lo encontro) o indice = -1 (no lo encontro)
 *
 */
int buscarAuto(char* patente, eAuto vec[], int tamauto);

/** \brief Baja del Auto
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return Si el auto esta registrado, lo borra y libera la posicion para que se pueda cargar un nuevo auto
 *
 */
void bajaAuto(eAuto vec[], int tamauto, eMarca marcas[], int tammarca,eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Muestra un Auto
 *
 * \param vec
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return Muestra un auto cargado en el sistema
 *
 */
void mostrarAuto(eAuto vec, eMarca marcas[], int tammarca,eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Ordena los Autos por marca y patente
 *
 * \param autos[]
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return retorno = o (si habia autos que ordenar) o retorno = -1 (si no habia autos que ordenar)
 *
 */
int ordenarAutos(eAuto* autos, int tamauto, eMarca* marcas, int tammarca, eColor* colores, int tamcolor, eCliente clientes[], int tamcli);

/** \brief Muestra una lista de los Autos cargados
 *
 * \param tamauto
 * \param autos[]
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \return Los autos en una lista
 *
 */
void listarAutos(int tamauto, eAuto autos[], eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);
