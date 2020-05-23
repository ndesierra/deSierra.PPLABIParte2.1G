#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{

    int id;
    char descripcion[25];
    float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED


/** \brief Muestra una lista de los Servicios cargados
 *
 * \param servicios[]
 * \param tamser
 * \return Los servicios en una lista
 *
 */
void listarServicios(eServicio servicios[], int tamser);

/** \brief Muestra un servicio
 *
 * \param vec
 * \param tamser
 * \return Muestra un servicio cargado en el sistema
 *
 */
void mostrarServicios(eServicio vec, int tamser, eServicio servicios[]);

/** \brief Muestra la descripcion del servicio, en lugar del ID
 *
 * \param descripcionServicio[]
 * \param servicios[]
 * \param tamser
 * \param idServicio
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Ok)
 *
 */
int cargarDescripcionServicio(char descripcionServicio[], eServicio servicios[], int tamser, int idServicio);
