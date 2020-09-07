#ifndef CALCULOSALGEBRAICOS_H_INCLUDED
#define CALCULOSALGEBRAICOS_H_INCLUDED

#endif // CALCULOSALGEBRAICOS_H_INCLUDED

//hace:toma datos
//entra: nada
//devuelve: entero
int TomarDatos (void);

//hace:Imprime en pantalla las operaciones a realizar
//entra: array con la operacion a realizar, numero a operar, operador a realizar, numero a operar
//devuelve: nada
void MostrarOperaciones (char*, int,char,int);

//hace:Imprime en pantalla las operaciones a realizar de fatoreo
//entra: array con la operacion a realizar, numero a operar, operador a realizar, numero a operar
//devuelve: nada
void MostrarOperaciones (char*, int,char,int);

//hace:Imprime en pantalla los resultados de las operaciones
//entra: array con la operacion a realizar, numero a operar, operador a realizar, numero a operar y resultado devuelto
//devuelve: nada
void ResultadoOperaciones (char* , int , char , int , int );

//hace:Imprime en pantalla los resultados de la operacion dividir
//entra: array con la operacion a realizar, numero a operar, operador a realizar, numero a operar y resultado devuelto decimal
//devuelve: nada
void ResultadoOperacionesFlotante (char* , int , char , int , float );


//hace:Imprime en pantalla los resultados de la operacion dividir con el error
//entra: array con la operacion a realizar, numero a operar, operador a realizar, numero a operar y resultado es array de error
//devuelve: nada
void ResultadoOperacionesError (char* , int , char , int , char* );

//hace:Imprime en pantalla los resultados de las operaciones factoreo
//entra: array con la operacion a realizar, numero a operar, resultado
//devuelve: nada
void ResultadoOperacionesFactoreo (char* , int , long int );

//hace:Isuma dos numeros
//entra: dos numeros enteros
//devuelve: suma de dos numeros enteros
int OperacionSumar (int, int);

//hace:Resta dos numeros
//entra: dos numeros enteros
//devuelve: resta de dos numeros enteros
int OperacionRestar (int, int);

//hace:division dos numeros
//entra: dos numeros enteros
//devuelve: division de dos numeros decimales
float OperacionDividir (int, int);

//hace:multiplica dos numeros
//entra: dos numeros enteros
//devuelve: multiplicacion de dos numeros enteros
int OperacionMultiplicar (int, int);

//hace:Factorea un numero
//entra: un numero entero
//devuelve: factoreo de un numero entero
long int FactorearNumero(int);

