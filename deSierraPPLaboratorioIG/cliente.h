#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

int id;
char nombre[20];
char sexo;

}eCliente;


#endif // CLIENTE_H_INCLUDED


/** \brief Muestra una lista de los clientes cargadas
 *
 * \param clientes[]
 * \param tamcli
 * \return Los clientes en una lista
 *
 */
void listarClientes(int tamcli, eCliente clientes[]);

/** \brief Muestra el nombre del cliente, en lugar del ID
 *
 * \param nombreCliente[]
 * \param idCliente
 * \param clientes[]
 * \param tamcli
 * \return todoOk = 0 (ERROR) o todoOk = 1 (Ok)
 *
 */
int cargarNombreCliente(char nombreCliente[], eCliente clientes[], int tamcli, int idCliente);
