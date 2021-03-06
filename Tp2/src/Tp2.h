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




/** \brief Inicializa todas las posiciones del array en empty
 * \param eEmpleado* lista Puntero al array de empleados
 * \param int len Largo del array
 * \return int Return (-1) Si hay error [Largo invalido o puntero NULL] - (0) si esta Ok
 *
 */
int inicializarEmpleados(eEmpleado* lista, int len);



/** \brief Agrega un nuevo empleado en la primer posicion vacia disponible, otorga id autoincremental y valida cada uno de los campos
 * \param eEmpleado* lista
 * \param int len
 * \param int* pId
 * \param char nombre[]
 * \param char apellido[]
 * \param float salario
 * \param int sector
 * \return int Return (-1) Si hay error [Largo invalido, puntero NULL o sin espacio disponible] - (0) si esta Ok
 */
int agregarEmpleado(eEmpleado* lista, int len, int* pId, char nombre[], char apellido[], float salario, int sector);





/**\brief Encuentra un empleado por ID y retorna la posicion del array en la que se ubica
 * \param eEmpleado* lista
 * \param int len
 * \param int id
 * \return Return el indice del empleado o (-1) si [Largo invalido, puntero NULL o si el empleado no existe]
 *
 */
int buscarEmpleadoId(eEmpleado lista[], int len, int id);




/** \brief Remueve un empleado en base al ID (coloca el valoe isEmpty en 1)
 *
 * \param eEmpleado* lista
 * \param int len
 * \param int id
 * \return int Return (0) Si hay Error [Largo invalido, puntero NULL o si el empleado no existe] - (1) si esta Ok
 *
 */
int bajaEmpleado(eEmpleado lista[], int len );



/** \brief Obtiene los empleados correspondientes al indice y se los entrega a imprimir empleados
 *
 * \param empleado correspondiente al indice que se le pase

 * \return void
 *
 */
void mostrarEmpleado(eEmpleado x);






/** \brief Imprime el contenido del array de empleados
 *
 * \param eEmpleado* lista
 * \param int len
 * \return int Return (0) Si hay Error [Largo invalido, puntero NULL] - (1) si esta Ok
 *
 */
int imprimirEmpleados(eEmpleado lista[],int len);




/** \brief Acomoda los elementos del array empleados. Se puede seleccionar orden ascendente o descendente
 *
 * \param eEmpleado* lista
 * \param int len
 * \param orden int [1] ASC - [0] DESC
 * \return int Return (-1) Si hay Error [Invalid length or NULL pointer] - (0) si esta Ok
 *
 */
int clasificarEmpleados(eEmpleado lista[], int len, int orden);




/** \brief Depliega el menu de modificacion

 * \return retorna la opcion seleccionada
 *
 */
int menuModificacion();






/** \brief Permite seleccionar un empleado dado de alta y modificar su nombre, apellido, salario o sector. Vuelve a validar todos los campos ingresados
 *
 * \param eEmpleado* lista
 * \param int len
 * \return  int Return (0) Si hay error [Largo invalido, puntero NULL o si el ID de empleado no existe] - (0) si esta Ok
 *
 */
int modificarEmpleado(eEmpleado lista[], int len );





/** \brief Valida si el nombre/apellido ingresado es correcto( sin espacios de mas o numeros)
 *
 * \param Recibe el nombre/apellido a validar
 * \return int Return (-1) Si hay error [Largo invalido, puntero NULL] - (1) si hay mas de 2 nombres, numeros o espacios invalidos  -(0) si esta Ok
 *
 */
int validarNombreApellido(char nombre[]);





/** \brief Valida que se ingresen solo numeros
 *
 * \param Recibe el numero a validar
 * \return int Return (1) Si hay error [Numero <= 0 / char / espacio vacio]  -(0) si esta Ok
 *
 */
int validarEntero(char numero[]);




/** \brief
 *
 * \param Recibe el numero a validar
 * \return int Return (1) Si hay error [Numero <= 0 / char / espacio vacio]  -(0) si esta Ok
 *
 */
float validarFloat(char numero[]);






/** \brief Calcula promedio de salario, total de salarios y cantidad de empleados que ganan sobre la media
 *
 * \param eEmpleado* lista
 * \param int len
 * \param float* p
 * \param float* salario
 * \param int* sobrePromedio
 * \return int Return (1) Si hay error  [Largo invalido, puntero NULL] -(0) si esta Ok
 *
 */
float calcularPromedio(eEmpleado lista [], int len, float* p, float* salario, int* sobrePromedio);

#endif // TP2_H_INCLUDED
