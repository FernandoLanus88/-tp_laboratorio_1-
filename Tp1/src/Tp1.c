/*
 ============================================================================
 Name        : Tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"

int main(void) {

	setbuf(stdout,NULL);
	 char seguir;
	    float num1;
	    float num2;
	    float resultadoSuma;
	    float resultadoResta;
	    float resultadoDivision;
	    float resultadoMultiplicacion;
	    int resultadoFactorial;
	    int resultadoFactorial2;
	    int flag=0;
	    int controlDivision;
	    int controlSuma;
	    int controlResta;
	    int controlMultiplicacion;
	    int controlFactorial;
	    int controlFactorial2;
	    float cant;
	    float cant2;


	    do{

	      switch(menuOpcion(&num1,&num2))
	    {
	     case 1:

	         if(numerosPantalla(&num1, &cant) )
	         {
	             validarPrimerNumero(&cant, &flag);
	         }
	         else
	         {
	             printf("Operando invalido\n");
	         }
	        break;
	     case 2:

	         if (flag)
	         {
	            if( numerosPantalla2(&num2, &cant2))
	            {
	                validarSegundoNumero(&cant2, &flag);
	            }
	            else
	            {
	             printf("Operando invalido\n");
	            }
	         }
	         else
	         {
	             printf("Debe ingresar el primer operando\n");
	         }
	         break;

	     case 3:
	        if(flag==2)
	        {
	         sumar(num1,num2,&resultadoSuma,&controlSuma);
	         restar(num1,num2,&resultadoResta,&controlResta);
	         dividir(num1,num2,&resultadoDivision,&controlDivision);
	         multiplicar(num1,num2,&resultadoMultiplicacion,&controlMultiplicacion);
	         factorial(num1,&resultadoFactorial,&controlFactorial);
	         factorial2(num2,&resultadoFactorial2,&controlFactorial2);
	         printf("Operacion realizadas, seleccione opcion 4 para visualizar los resultados\n");
	         flag=3;
	        }
	        else
	        {
	           printf("Debe ingresar los operandos\n");
	        }

	        break;
	     case 4:
	          if(flag == 3)
	          {
	            funcionResultadoSuma(controlSuma,&resultadoSuma);
	            funcionResultadoResta(controlResta,&resultadoResta);
	            funcionResultadoMultiplicacion(controlMultiplicacion,&resultadoMultiplicacion);
	            funcionResultadoDivision(controlDivision,&resultadoDivision);
	            funcionResultadoFactoriales(controlFactorial,controlFactorial2,&resultadoFactorial,&resultadoFactorial2);
	        num1=0;
	        num2=0;
	        flag=0;
	        }
	        else
	        {
	              printf("Primero debe calcular las operaciones\n");
	        }
	        break;

	     case 5:
	         funcionCierre(&seguir);

	        break;

	     default:

	         printf("Opcion Invalida, reingrese\n\n");

	     break;
	    }
	     system("pause");

	    }while(seguir != 's');




	return EXIT_SUCCESS;
}
