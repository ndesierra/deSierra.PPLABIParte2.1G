#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED


/** \brief Muestra la descripcion del color, en lugar del ID
 *
 * \param descripcionColor[]
 * \param idColor
 * \param colores[]
 * \param tamcolor
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Ok)
 *
 */
int cargarDescripcionColor(char descripcionColor[], int idColor, eColor colores[], int tamcolor);

/** \brief Muestra una lista de los Colores cargados
 *
 * \param colores[]
 * \param tamcolor
 * \return Los colores en una lista
 *
 */
void listarColores(eColor colores[], int tamcolor);
