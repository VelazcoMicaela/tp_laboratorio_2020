#include <stdio.h>
#include "calculosAlgebraicos.h"


int TomarDatos (void )
{
    int datoIngresado;
    scanf("%d",&datoIngresado);

    return datoIngresado;
}

void MostrarOperaciones (char* operadoresLetras, int num1,char operadores,int num2)
{
    printf("\n Calcular la %s de ( %d %c %d )",operadoresLetras,num1,operadores,num2);
}

void MostrarOperacionesFactoreo (char* operadoresLetras, int num1)
{
    printf("\n Calcular el %s de ( %d )",operadoresLetras,num1);
}

void ResultadoOperaciones (char* operadoresLetras, int num1, char operadores, int num2, int resultado)
{
    printf("\n Resultado de la %s de %d %c %d = %d",operadoresLetras,num1,operadores,num2,resultado);
}

void ResultadoOperacionesFlotante (char* operadoresLetras , int num1, char operadores, int num2, float resultado)
{
    printf("\n Resultado de la %s de %d %c %d = %f",operadoresLetras,num1,operadores,num2,resultado);
}

void ResultadoOperacionesError (char* operadoresLetras , int num1, char operadores, int num2, char* resultado)
{
    printf("\n Resultado de la %s de %d %c %d = %s",operadoresLetras,num1,operadores,num2,resultado);
}


void ResultadoOperacionesFactoreo (char* operadoresLetras, int num1, long int resultado)
{
    printf("\n Resultado del %s de %d = %li",operadoresLetras,num1,resultado);
}

int OperacionSumar (int num1, int num2)
{
    int resultadoSuma;
    resultadoSuma=num1+num2;
    return resultadoSuma;
}

int OperacionRestar (int num1, int num2)
{
    int resultadoResta;
    resultadoResta=num1-num2;
    return resultadoResta;
}

float OperacionDividir (int num1, int num2)
{
    float resultadoDivide;
    char errorDivision;

    if(num2==0){
       resultadoDivide= 0;
    }
    else
    {
        resultadoDivide=(float)num1/num2;
        return resultadoDivide;
    }
}

int OperacionMultiplicar (int num1, int num2)
{
    int resultadoMultiplica;
    resultadoMultiplica=num1*num2;
    return resultadoMultiplica;
}

long int FactorearNumero(int num1)
{
    long int factoreoNumeroFinal;
    int numeroAfactorear;

    factoreoNumeroFinal=1;
    for(numeroAfactorear=num1; numeroAfactorear>0; numeroAfactorear--)
    {
        factoreoNumeroFinal=factoreoNumeroFinal*numeroAfactorear;
    }
   return factoreoNumeroFinal;
}
