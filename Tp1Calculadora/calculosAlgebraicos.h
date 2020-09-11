#ifndef CALCULOSALGEBRAICOS_H_INCLUDED
#define CALCULOSALGEBRAICOS_H_INCLUDED

#endif // CALCULOSALGEBRAICOS_H_INCLUDED

/** \brief toma datos
 *
 * \param nada
 * \return entero ingresado por el usuario
 *
 */
int TomarDatos (void);


/** \brief Imprime en pantalla las operaciones a realizar
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \param char operador a realizar
 * \param int numero a operar
 * \return printf de la operacion a realizar
 *
 */
void MostrarOperaciones (char*, int,char,int);


/** \brief Imprime en pantalla las operaciones a realizar de fatoreo
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \return printf de la operacion a realizar
 *
 */
void MostrarOperacionesFactoreo (char*, int);


/** \brief Imprime en pantalla los resultados de las operaciones
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \param char operador a realizar
 * \param int numero a operar
 * \param int resultado devuelto
 * \return printf de la operacion realizada
 *
 */
void ResultadoOperaciones (char* , int , char , int , int );


/** \brief Imprime en pantalla los resultados de la operacion con flotante
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \param char operador a realizar
 * \param int numero a operar
 * \param float resultado devuelto flotante
 * \return printf de la operacion realizada
 *
 */
void ResultadoOperacionesFlotante (char* , int , char , int , float );



/** \brief Imprime en pantalla los resultados de la operacion dividir con el error
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \param char operador a realizar
 * \param int numero a operar
 * \param resultado es array de error
 * \return printf de la funcion con error
 *
 */
void ResultadoOperacionesError (char* , int , char , int , char* );


/** \brief Imprime en pantalla los resultados de las operaciones factoreo con long
 *
 * \param array con la operacion a realizar
 * \param int numero a operar
 * \param long numero a resultado
 * \return printf de la operacion realizada
 *
 */
void ResultadoOperacionesFactoreo (char* , int , long );


/** \brief suma dos numeros
 *
 * \param int numero
 * \param int numero
 * \return int suma de dos numeros
 *
 */
int OperacionSumar (int, int);


/** \brief Resta dos numeros
 *
 * \param int numero
 * \param int numero
 * \return int Resta de dos numeros
 *
 */
int OperacionRestar (int, int);


/** \brief division dos numeros
 *
 * \param int numero
 * \param int numero
 * \return float division de dos numeros
 *
 */
float OperacionDividir (int, int);


/** \brief multiplica dos numeros
 *
 * \param int numero
 * \param int numero
 * \return int multiplica de dos numeros
 *
 */
int OperacionMultiplicar (int, int);


/** \brief Factorea un numero
 *
 * \param int numero
 * \return long Factoreo de un numero
 *
 */
long FactorearNumero(int);

