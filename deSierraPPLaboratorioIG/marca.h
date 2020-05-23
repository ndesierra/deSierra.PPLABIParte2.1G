#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eMarca;

typedef struct
{
    int idMarca;
    int contador;
    char nombreMarca[20];

} eMarcaMasElegida;

#endif // MARCA_H_INCLUDED



/** \brief Muestra la descripcion de la marca, en lugar del ID
 *
 * \param descripcionMarca[]
 * \param idMarca
 * \param marcas[]
 * \param tammarca
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Ok)
 *
 */
int cargarDescripcionMarca(char descripcionMarca[], int idMarca, eMarca marcas[], int tammarca);

/** \brief Muestra una lista de las Marcas cargadas
 *
 * \param marcas[]
 * \param tammarca
 * \return Las marcas en una lista
 *
 */
void listarMarcas(eMarca marcas[], int tammarca);

void mostrarMarca(eMarca vec, int tammmarca, eMarca marcas[]);
