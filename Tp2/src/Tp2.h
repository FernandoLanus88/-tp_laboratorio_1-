#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
} eEmpleado;

int menu();



int inicializarEmpleados(eEmpleado* lista, int len);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */


int agregarEmpleado(eEmpleado* lista, int len, int* pId);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *




int buscarEmpleadoId(eEmpleado lista[], int len, int id);
** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */




int bajaEmpleado(eEmpleado lista[], int len );
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */



void mostrarEmpleado(eEmpleado x);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */






int imprimirEmpleados(eEmpleado lista[],int len);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */




int clasificarEmpleados(eEmpleado lista[], int len, int orden);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */




int menuModificacion();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */






int modificarEmpleado(eEmpleado lista[], int len );
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */





int validarNombreApellido(char nombre[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */





int validarEntero(int numero);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */





float validarFloat(float numero);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */





float calcularPromedio(eEmpleado lista [], int len, float* p, float* salario, int* sobrePromedio);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */




#endif // TP2_H_INCLUDED
