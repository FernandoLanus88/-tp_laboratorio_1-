#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ASC 1
#define DESC 0
#define LEN 1000
#include "Tp2.h"



int menu()
{
    int opcion;
    system("cls");
    printf("     ***    EMPLEADOS   ***   \n\n");
    printf("1- Alta Empleado\n");
    printf("2- Modificar Empleado\n");
    printf("3- Baja Empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int inicializarEmpleados(eEmpleado* lista, int len)
{
    int todoOk=-1;
    if(lista !=NULL && len>0)
    {
        for(int i =0; i<len ; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk=0;
    }
    return todoOk;
}



int agregarEmpleado(eEmpleado* lista, int len, int* pId)
{
    int todoOk =-1;
    int indice=-1;
    eEmpleado auxEmpleado;


    if(lista !=NULL && len>0 && pId != NULL)
    {
        system("cls");
        printf("     ***ALTA EMPLEADO***   \n");

        for(int i =0; i<len ; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }

        if(indice == -1)
        {
            printf("Limite alcanzado, borre algun registro si desea ingresar uno nuevo\n");
        }
        else
        {
            auxEmpleado.id = *pId;
            (*pId)++;


            printf("Ingrese nombre:  ");
            fflush(stdin);
            gets(auxEmpleado.nombre);
            while(validarNombreApellido(auxEmpleado.nombre))
            {
                printf("Reingrese nombre:  ");
                fflush(stdin);
                gets(auxEmpleado.nombre);
            }



            printf("Ingrese Apellido:  ");
            fflush(stdin);
            gets(auxEmpleado.apellido);

            while(validarNombreApellido(auxEmpleado.apellido))
            {
                printf("Reingrese Apellido:  ");
                fflush(stdin);
                gets(auxEmpleado.apellido);

            }



            printf("Ingrese Salario:  ");
            fflush(stdin);
            scanf("%f", &auxEmpleado.salario);
            while( validarFloat(auxEmpleado.salario))
            {
                printf("Reingrese Salario:  ");
                fflush(stdin);
                scanf("%f", &auxEmpleado.salario);

            }




            printf("Ingrese Sector:  ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.sector);

            while( validarEntero(auxEmpleado.sector))
            {
                printf("Reingrese Sector:  ");
                fflush(stdin);
                scanf("%d", &auxEmpleado.sector);

            }

            auxEmpleado.isEmpty = 0;

            lista[indice] = auxEmpleado;
            todoOk=0;
        }

    }
    return todoOk;
}



int buscarEmpleadoId(eEmpleado lista[], int len, int id)
{
    int empleado =-1;
    if(lista !=NULL && len>0)
    {
        for(int i =0; i<len ; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                empleado = i;
                break;
            }
        }
    }
    return empleado;
}



void mostrarEmpleado(eEmpleado x)
{

    printf("%d      %-10s    %-10s     %8.2f         %d\n\n\n",
           x.id,
           x.nombre,
           x.apellido,
           x.salario,
           x.sector
          );
}



int bajaEmpleado(eEmpleado lista[], int len )
{
    int todoOk =0;
    int indice;
    int id;
    char confirma;



    if(lista != NULL && len>0)
    {
        system("cls");
        printf("   *** BAJA EMPLEADO ***  \n\n");

        printf("-------------------------------------------------------------\n");
        printf("Id     Nombre        Apellido        Salario       Sector \n");
        printf("-------------------------------------------------------------\n");

        for(int i =0; i<len; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarEmpleado(lista[i]);

            }
        }


        printf("Ingrese Id del empleado a remover: ");
        scanf("%d", &id);

        indice = buscarEmpleadoId(lista, len, id);

        if(indice == -1)
        {
            printf("No hay ningun empleado registrado en sistema con ese ID\n");
        }
        else
        {
            printf("-------------------------------------------------------------\n");
            printf("Id     Nombre        Apellido        Salario        Sector  \n");
            printf("-------------------------------------------------------------\n");
            mostrarEmpleado(lista[indice]) ;

            printf("Confirma baja? ingrese s para confirmar, cualquier otra tecla para cancelar: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("Baja Exitosa\n");
                lista[indice].isEmpty = 1;

                todoOk=1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}



int imprimirEmpleados(eEmpleado lista[],int len)
{
    int todoOk=0;
    int flag =1;
    if(lista !=NULL && len>0)
    {
        system("cls");
        printf("             ***Lista de Empleados***                        \n");
        printf("-------------------------------------------------------------\n");
        printf("Id     Nombre        Apellido        Salario        Sector   \n");
        printf("-------------------------------------------------------------\n");
        for(int i =0; i<len; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarEmpleado(lista[i]);

                flag=0;
            }
        }

        if(flag)
        {
            printf("No hay personas para mostrar\n\n");
        }
        todoOk=1;
    }
    return todoOk;
}





int clasificarEmpleados(eEmpleado lista[], int len, int orden)
{

    int todoOk=-1;
    eEmpleado auxEmpleado;


    if(lista != NULL && len>0 && orden >=0 && orden <=1)
    {

        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {

                if(orden &&((strcmp(lista[i].apellido, lista[j].apellido)>0)
                            ||(lista[i].apellido==lista[j].apellido &&  (lista[i].sector > lista[j].sector))))

                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
                if(!orden && ((strcmp(lista[i].apellido, lista[j].apellido)<0)
                              ||(lista[i].apellido==lista[j].apellido &&  (lista[i].sector < lista[j].sector))))
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }
            }
        }
        todoOk=0;
    }
    return todoOk;
}

int modificarEmpleado(eEmpleado lista[], int len )
{
    int todoOk =0;
    int indice;
    int id;
    char confirma;

    char seguir = 's';


    if(lista != NULL && len>0)
    {
        system("cls");
        printf("   *** MODIFICACION EMPLEADO ***  \n\n");

        printf("-------------------------------------------------------------\n");
        printf("Id     Nombre        Apellido        Salario       Sector \n");
        printf("-------------------------------------------------------------\n");

        for(int i =0; i<len; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarEmpleado(lista[i]);

            }
        }


        printf("Ingrese Id del empleado a editar: ");
        scanf("%d", &id);


        indice = buscarEmpleadoId(lista, len, id);

        if(indice == -1)
        {
            printf("No hay ningun empleado registrado en sistema con ese ID\n");
        }
        else
        {
            printf("-------------------------------------------------------------\n");
            printf("Id     Nombre        Apellido        Salario       Sector \n");
            printf("-------------------------------------------------------------\n");
            mostrarEmpleado(lista[indice]) ;

            printf("Va a modificar este registro? ingrese s para desplegar el submenu, cualquier otra tecla para cancelar: \n\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                system("cls");
                mostrarEmpleado(lista[indice]) ;
                do
                {
                    switch(menuModificacion())
                    {

                    case 1:

                        printf("Ingrese nombre:  ");
                        fflush(stdin);
                        gets(lista[indice].nombre);

                        while(validarNombreApellido(lista[indice].nombre))
                        {
                            printf("Reingrese nombre:  ");
                            fflush(stdin);
                            gets(lista[indice].nombre);

                        }
                        printf("Modifacion Exitosa.\n");
                        system("pause");
                        break;



                    case 2:

                        printf("Ingrese Apellido:  ");
                        fflush(stdin);
                        gets(lista[indice].apellido);

                        while(validarNombreApellido(lista[indice].apellido))
                        {
                            printf("Reingrese Apellido:  ");
                            fflush(stdin);
                            gets(lista[indice].apellido);

                        }
                        printf("Modifacion Exitosa.\n");
                        system("pause");
                        break;


                    case 3:


                        printf("Ingrese Salario:  ");
                        scanf("%f", &lista[indice].salario);
                        printf("%f",lista[indice].salario);

                        while( validarFloat(lista[indice].salario))
                        {
                            printf("Reingrese Salario:  ");
                            scanf("%f", &lista[indice].salario);
                        }

                        printf("Modifacion Exitosa.\n");
                        system("pause");
                        break;

                    case 4:

                        printf("Ingrese Sector:  ");
                        scanf("%d", &lista[indice].sector);

                        while( validarEntero(lista[indice].sector))
                        {
                            printf("Reingrese Sector:  ");

                            scanf("%d", &lista[indice].sector);

                        }

                        printf("Modifacion Exitosa.\n");
                        system("pause");
                        break;


                    case 5:
                        printf("Ha seleccionado salir\n");
                        seguir = 'n';
                        break;

                    default:
                        printf("Opcion Invalida\n");
                        fflush(stdin);
                        system("pause");
                    }

                }
                while(seguir == 's');

                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}




int menuModificacion()
{
    int opcion;
    system("cls");

    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar Sector\n");
    printf("5- Salir\n\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}




float calcularPromedio(eEmpleado lista[], int len, float* promedio, float* salario, int* sobrePromedio)
{

    *sobrePromedio=0;
    *promedio =0;
    int todoOk=1;
    *salario=0;
    int contador=0;

    if(lista !=NULL && len>0)
    {
        for(int i =0; i<len ; i++)
        {
            if(!lista[i].isEmpty)
            {
                *salario = *salario + lista[i].salario;
                contador++;
            }
        }
        *promedio = (float) *salario / contador;

        for(int i =0; i<len; i++)
        {
            if(lista[i].salario > *promedio)
            {
                (*sobrePromedio)++;
            }
        }
        if(contador)
        {
            printf("                  ***SALARIOS***                  \n");
            printf("-------------------------------------------------------------\n");
            printf("       Total          Promedio       Sobre la media     \n");
            printf("-------------------------------------------------------------\n");
            printf("    %10.2f       %10.2f             %d\n\n",*promedio, *salario, (*sobrePromedio));
            todoOk=0;
        }
    }

    return todoOk;
}

int validarNombreApellido(char nombre[])
{

    int todoOk=-1;
    int espacios=0;
    strlwr(nombre);
    nombre[0] = toupper(nombre[0]);


    if(nombre != NULL && (strlen(nombre)<51) && (strlen(nombre)>0))
    {
        todoOk=0;



        for(int i =0; i<strlen(nombre); i++)
        {
            if(nombre[i]==' ')
            {
                espacios++;
                nombre[i+1] = toupper(nombre[i+1]);
            }

            if((isdigit(nombre[i]))|| espacios>1 )
            {
                printf("Error. No ingrese mas de 2 nombres ni numeros.\n");
                todoOk=1;
                break;
            }
            if((isspace(nombre[0])))
            {
                printf("Error. No puede dejar el primer espacio vacio.\n");
                todoOk=1;
                break;
            }
        }
    }
    else
    {
        printf("Error. Nombre nulo o demasiado largo.\n");
    }

    return todoOk;
}





int validarEntero(int numero)
{
    int todoOk=0;

    if(numero <0 || numero ==isalpha(numero))
    {
        printf("Error. Ingrese solo numeros");
        todoOk=1;
    }

    return todoOk;
}





float validarFloat(float numero)
{
    int todoOk=0;

    if(numero <0 || numero ==isalpha(numero))
    {
        printf("Error. Ingrese solo numeros\n");
        todoOk=1;
    }

    return todoOk;
}
