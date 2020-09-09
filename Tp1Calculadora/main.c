#include <stdio.h>
#include <stdlib.h>
#include "calculosAlgebraicos.h"

int main()
{
    int opcionesMenu;
    char suma []="suma";
    char resta []="resta";
    char division []="division";
    char multiplicacion []="multiplicacion";
    char factoreo []="factoreo";
    char errorDivision []="No es posible dividir por cero”";
    int num1;
    int num2;
    char oparadorSuma='+';
    char oparadorResta='-';
    char oparadorDivision='/';
    char oparadorMultiplicacion='*';
    int respuestaOperacion;
    long int respuestaOperacionFactoreo;
    float respuestaOperacionFlotante;
    int contadorMenu;


   do{
        printf("\n MENU NUMERICO \n 1. Ingresar 1er operando \n 2. Ingresar 2do operando \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir");
        opcionesMenu=TomarDatos();
        //printf("\n calcular la %s de ( %d %c %d )",suma,num1,oparadorSuma,num2);
        //printf("\n calcular la %s",resta);


       switch(opcionesMenu)
        {
            case 1:
                printf("\n Ingrese numero: ");
                num1=TomarDatos();
                contadorMenu=1;
            break;

            case 2:
               if(contadorMenu==1)
                {
                    printf("\n Ingrese numero: ");
                    num2=TomarDatos();
                    contadorMenu=2;
                }else
                {
                    printf("\n Debe ingresar el primer 1 numero");
                }
            break;

            case 3:
                if(contadorMenu==2){
                    MostrarOperaciones(suma,num1,oparadorSuma,num2);
                    MostrarOperaciones(resta,num1,oparadorResta,num2);
                    MostrarOperaciones(division,num1,oparadorDivision,num2);
                    MostrarOperaciones(multiplicacion,num1,oparadorMultiplicacion,num2);
                    MostrarOperacionesFactoreo(factoreo,num1);
                    MostrarOperacionesFactoreo(factoreo,num2);
                    contadorMenu=3;
                }else
                {
                    printf("\n Debe ingresar numeros primero");
                 }
            break;

            case 4:
                if(contadorMenu==3){
                    respuestaOperacion=OperacionSumar(num1,num2);
                    ResultadoOperaciones(suma,num1,oparadorSuma,num2,respuestaOperacion);

                    respuestaOperacion=OperacionRestar(num1,num2);
                    ResultadoOperaciones(resta,num1,oparadorResta,num2,respuestaOperacion);

                    if(num2==0)
                    {
                        respuestaOperacionFlotante=OperacionDividir(num1,num2);
                        ResultadoOperacionesError(division,num1,oparadorDivision,num2,errorDivision);
                    }
                    else
                    {
                        respuestaOperacionFlotante=OperacionDividir(num1,num2);
                        ResultadoOperacionesFlotante(division,num1,oparadorDivision,num2,respuestaOperacionFlotante);
                    }

                    respuestaOperacion=OperacionMultiplicar(num1,num2);
                    ResultadoOperaciones(multiplicacion,num1,oparadorMultiplicacion,num2,respuestaOperacion);

                    respuestaOperacionFactoreo=FactorearNumero(num1);
                    ResultadoOperacionesFactoreo(factoreo,num1,respuestaOperacionFactoreo);

                    respuestaOperacionFactoreo=FactorearNumero(num2);
                    ResultadoOperacionesFactoreo(factoreo,num2,respuestaOperacionFactoreo);
                }else
                {
                    printf("\n Debe ingresar numeros primero");
                }

            break;

            case 5:
                printf("\n Gracias por utilizarlo\n");
            break;
        }

    }while(opcionesMenu!=5);

}
