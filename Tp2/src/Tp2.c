/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tp2.h"
#define ASC 1
#define DESC 0
#define LEN 1000




int main()
{


	setbuf(stdout,NULL);

    char seguir = 's';
    int idEmpleado = 1;
    eEmpleado lista[LEN];
    float salario;
    float promedio;
    int sobrePromedio=0;
    int flag =1;
    char nombre[51];
    char apellido[51];
    int sector=0;



    if(inicializarEmpleados(lista,LEN)==-1)
    {
        printf("Problema al inicializar\n");
        system("pause");
    }


    do
    {
        switch(menu())
        {
        case 1:
            if(agregarEmpleado(lista, LEN, &idEmpleado, nombre, apellido, salario, sector )==-1)
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
                flag=0;
            }
            break;


        case 2:
            if(flag)
            {
                printf("No se pudo realizar la modificacion\n");
            }
            else
            {
                modificarEmpleado(lista, LEN);
                printf("Modifacion Terminada.\n");
            }
            break;


        case 3:
            if(flag)
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                bajaEmpleado(lista, LEN);
            }

            break;



        case 4:
            if(flag)
            {
                printf("No se pudo realizar el informe\n");
            }
            else
            {
                clasificarEmpleados(lista, LEN,  ASC);
                imprimirEmpleados(lista, LEN);
                calcularPromedio(lista, LEN, &promedio, &salario, &sobrePromedio);
            }

            break;

        case 5:
            printf("Ha seleccionado salir\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion Invalida\n");
            fflush(stdin);
        }
        system("pause");
    }
    while(seguir == 's');



    return 0;
}
