/*
 * calculadora.c
 *
 *  Created on: 22 sep. 2021
 *      Author: PePo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"


float numerosPantalla(float*a, float* cant)
{

         *cant=0;
         printf("Ingrese el primer operando: \n");
         *cant = scanf("%f",a);

        if(*cant==1 && a != NULL)
        {
            *cant=1;
        }
         return *cant;
}



float numerosPantalla2(float*a, float* cant)
{
         *cant=0;
         printf("Ingrese el segundo operando: \n");
         *cant = scanf("%f",a);

        if(*cant==1 )
        {
            *cant=1;
        }
         return *cant;

}



int validarPrimerNumero(float* cant, int* flag)
{
    if(cant != NULL)
    {
          if(cant)
         {
           *flag=1;
         }
         else
         {
             printf("Operando invalido\n");
         }
    }
    return 0;
}



int validarSegundoNumero(float* cant2, int* flag2)
{
    if(cant2 != NULL)
    {
      if(cant2)
         {
            *flag2=2;
         }
         else
         {
             printf("Operando invalido\n");
         }
    }
    return 0;
}



int menuOpcion(float* num1,float* num2)
{
    int opcion;

     system("cls");
     printf("Menu de opciones \n\n");
     printf("1. Ingrese 1er operando A = %.2f\n",*num1);
     printf("2. Ingrese 2do operando B = %.2f\n",*num2);
     printf("3. Calcular operaciones\n");
     printf("4. Informar resultados\n");
     printf("5. Salir del programa\n\n"),
     printf("Ingrese opcion: ");
     fflush(stdin);
     scanf("%d",&opcion);
     return opcion;
}


int sumar(float a, float b, float*c, int* control)
    {
   *control=0;
    if(c != NULL)
    {
        *c = a+b;
        *control=1;
    }
    return *control;
}



int restar(float a, float b, float*c, int* control)
    {
   *control=0;
    if(c != NULL)
    {
        *c = a-b;
        *control=1;
    }
    return *control;
}



int dividir (float dividendo, float divisor, float* cociente, int* control)
{
    *control=0;
    if(cociente != NULL && divisor !=0 )
    {
        *cociente =  dividendo/divisor;
         *control=1;
    }
    return *control;
}


int multiplicar (float a, float b, float* c, int* control)
{
   *control=0;
    if(c != NULL )
    {
        *c =  a*b;
        *control=1;
    }
    return *control;
}



int factorial(float num, int* resultado, int*control)
{
    *control=0;
    int fact=1;

    if(resultado != NULL && control !=NULL)
    {
          if(num>=0 && num<13)
        {
        *control=1;
         for(int i =2; i<=num; i++)
           {

             fact = fact * i;
            *resultado = fact;
           }
         *resultado=fact;
        }
    }

    return *control;
}


int factorial2(float num, int* resultado, int*control)
{
    *control=0;
    int fact=1;
    if(resultado != NULL && control !=NULL)
    {
        if(num>=0 && num <13)
        {
        *control=1;

         for(int i =2; i<=num; i++)
           {

               fact = fact * i;
              *resultado = fact;
           }
         *resultado=fact;
        }
    }

    return *control;
}



int funcionResultadoSuma(int control, float* suma)
{
    if(control && suma != NULL)
    {
        printf("El resultado de la suma es: %.2f\n",*suma);
    }
    else
    {
        printf("Error en la Suma");
    }
    return 0;
}



int funcionResultadoResta(int control, float* resta)
{
    if(control && resta != NULL)
    {
        printf("El resultado de la resta es: %.2f\n",*resta);
    }
    else
    {
        printf("Error en la Resta");
    }
    return 0;
}



  int funcionResultadoMultiplicacion(int control, float*multiplicacion)
{

    if(control && multiplicacion != NULL)
    {
         printf("El resultado de la multiplicacion es: %.2f\n",*multiplicacion);
    }
    else
    {
        printf("Error en la Multiplicacion");
    }
    return 0;
}



 int funcionResultadoDivision(int control, float* division)
 {

        if(control && division != NULL)
            {
              printf("El resultado de la division es: %.2f\n",*division);
            }
            else
            {
              printf("No es posible dividir por 0\n");
            }

        return 0;
}



 int funcionResultadoFactoriales(int control, int control2, int* factorial, int* factorial2)
{

    if(factorial != NULL && factorial2 != NULL)
    {
        if(control && control2)
       {
         printf("El resultado de los Factoriales es operando 1: %d  operando 2: %d\n",*factorial,*factorial2);

       }
       else if(control)
       {
         printf("El resultado del Factorial 1 es: %d . Factorial 2 no puede ser calculado por ser negativo o exceder la memoria\n",*factorial);
       }
       else if(control2)
       {
         printf("El resultado del Factorial 2 es: %d . Factorial 1 no puede ser calculado por ser negativo o exceder la memoria\n",*factorial2);
       }
       else
       {
           printf("No se puede calcular ninguno de los Factoriales por ser negativos o exceder la memoria\n");
       }
    }

        return 0;
}



int funcionCierre(char*s)
{
        printf("Realmente desea salir? pulse s para confirmar cualquier otra tecla para volver\n");
        fflush(stdin);
        scanf("%c",s);
        *s=tolower(*s);
    return *s;
}



