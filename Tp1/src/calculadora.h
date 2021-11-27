/*
 * calculadora.h
 *
 *  Created on: 22 sep. 2021
 *      Author: PePo
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_





/** \brief Despliega el menu de opciones
 *
 * \param Utliza puntero a num1 para modificar el valor en pantalla
 * \param Utliza puntero a num2 para modificar el valor en pantalla
 * \return Retorna la opcion del menu seleccionada
 *
 */
int menuOpcion(float* num1,float* num2);



/** \brief Realiza la suma de los numeros
 *
 * \param primer operando a sumar
 * \param segundo operando a sumar
 * \param resultado
 * \return Retorna 0 o 1 que sera usado en funcionResultadoSuma para validar
 *
 */
int sumar(float, float, float*, int*);



/** \brief Realiza la resta de los numeros
 *
 * \param primer operando a restar
 * \param segundo operando a restar
 * \param resultado
 * \return Retorna 0 o 1 que sera usado en funcionResultadoResta para validar
 *
 */
int restar(float, float, float*, int*);



/** \brief Realiza la division de los numeros
 *
 * \param primer operando a dividir
 * \param segundo operando a dividir
 * \param resultado
 * \return Retorna 0 o 1 que sera usado en funcionResultadoDividir para validar
 *
 */
int dividir(float, float, float*, int*);



/** \brief Realiza la multiplicacion de los numeros
 *
 * \param primer operando a multiplicar
 * \param segundo operando a multiplicar
 * \param resultado
 * \return Retorna 0 o 1 que sera usado en funcionResultadoMultilplicacion para validar
 *
 */
 int multiplicar(float, float, float*, int*);



/** \brief Calcula el factorial del operando 1
 *
 * \param operando a utilizar
 * \param resultado de la operacion
 * \return Retorna 0 o 1 que sera usado en funcionResultadoFactoriales para validar
 *
 */
int factorial(float, int*, int*);




/** \brief Calcula el factorial del operando 2
 *
 * \param operando a utilizar
 * \param resultado de la operacion
 * \return Retorna 0 o 1 que sera usado en funcionResultadoFactoriales para validar
 *
 */
int factorial2(float, int*, int*);




/** \brief Recibe el primer operando ingresado por el usuario

 * \return Retorna 0 o 1 que sera usado en funcionValidarPrimerNumero para validar
 *
 */
float numerosPantalla(float*, float*);




/** \brief  Recibe el segundo operando ingresado por el usuario

 * \return Retorna 0 o 1 que sera usado en funcionValidarSegundoNumero para validar
 *
 */
float numerosPantalla2(float*, float*);




/** \brief Recibe el retorno de la funcion numerosPantalla y verificar que sea un valor numerico
 *
 * \param Setea la bandera en 1 dando paso al siguiente nivel del menu
 * \return Retorna 0
 *
 */
int validarPrimerNumero(float*, int*);




/** \brief Recibe el retorno de la funcion numerosPantalla2 y verificar que sea un valor numerico
 *
 * \param
 * \param Setea la bandera en 1 dando paso al siguiente nivel del menu
 * \return Retorna 0
 *
 */
int validarSegundoNumero(float*, int*);




/** \brief Recibe el retorno de la funcion sumar y verificar que no se presenten errores
 *
 * \param Muestra el resultado de la suma en pantalla
 * \return Retorna 0
 */
int funcionResultadoSuma(int, float*);



/** \brief Recibe el retorno de la funcion restar y verificar que no se presenten errores
 *
 * \param Muestra el resultado de la suma en pantalla
 * \return Retorna 0
 *
 */
int funcionResultadoResta(int, float*);




/** \brief Recibe el retorno de la funcion multiplicar y verificar que no se presenten errores
 *
 * \param Muestra el resultado de la suma en pantalla
 * \return Retorna 0
 *
 */
int funcionResultadoMultiplicacion(int, float*);




/** \brief Recibe el retorno de la funcion dividir y verificar que no se presenten errores
 *
 * \param Muestra el resultado de la suma en pantalla
 * \return Retorna 0
 *
 */
int funcionResultadoDivision(int, float*);




/** \brief Recibe el retorno de las funciones factorial y Factorial2 y verifica que resultado mostrar
 *
 * \param Verifica el retorno de factorial
 * \param Verifica el retorno de factorial2
 * \param Muestra en patalla el resultado de factorial
 * \param Muestra en patalla el resultado de factorial2
 * \return Retorna 0
 *
 */
int funcionResultadoFactoriales(int, int, int*, int*);




/** \brief Recibe la confirmacion por parte del usuario para finalizar el programa
 *
 * \param Verifica que se ingrese el caracter s para dar fin al programa
 * \return Retorna s
 *
 */
int funcionCierre(char*);

#endif /* CALCULADORA_H_ */
