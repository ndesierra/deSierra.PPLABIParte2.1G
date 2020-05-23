#include "auto.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "menu.h"
#include "cliente.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Switch del menu de informes
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return la opcion elegida por el usuario
 *
 */
void informesLavadero(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Informe de auto de color
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return Muestra un listado de autos segun el color elegido por usuario
 *
 */
void informarAutosDeColor(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Informe de auto de marca
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return Muestra un listado de autos segun la marca elegido por usuario
 *
 */
void informarAutosDeMarca(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Informe de autos mas antiguos
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return Muestra un listado de autos mas antiguos
 *
 */
void informarAutomasViejo(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

/** \brief Informe de autos por marca
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return Muestra un listado de autos de cada marca
 *
 */
void informarAutosXMarca(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);


/** \brief Informe de autos por color y cantidad
 *
 * \param vec[]
 * \param tamauto
 * \param marcas[]
 * \param tammarca
 * \param colores[]
 * \param tamcolor
 * \param tamcli
 * \return muestra la cantidad de autos segun la marca y color elegida por el usuario
 *
 */
void informarCantidadAutosXMarcayColor(eAuto vec[], int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor, eCliente clientes[], int tamcli);

