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
    char errorDivision []="No es posible dividir por cero";
    int num1;
    int num2;
    char oparadorSuma='+';
    char oparadorResta='-';
    char oparadorDivision='/';
    char oparadorMultiplicacion='*';
    int respuestaOperacion;
    long respuestaOperacionFactoreoNum1;
    long respuestaOperacionFactoreoNum2;
    float respuestaOperacionFlotante;
    int contadorMenu;


   do{
        printf("\n MENU NUMERICO \n 1. Ingresar 1er operando \n 2. Ingresar 2do operando \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir");
        opcionesMenu=TomarDatos();

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
                    respuestaOperacion=OperacionSumar(num1,num2);

                    MostrarOperaciones(resta,num1,oparadorResta,num2);
                    respuestaOperacion=OperacionRestar(num1,num2);

                    MostrarOperaciones(division,num1,oparadorDivision,num2);
                    respuestaOperacionFlotante=OperacionDividir(num1,num2);
                    respuestaOperacionFlotante=OperacionDividir(num1,num2);

                    MostrarOperaciones(multiplicacion,num1,oparadorMultiplicacion,num2);
                    respuestaOperacion=OperacionMultiplicar(num1,num2);

                    MostrarOperacionesFactoreo(factoreo,num1);
                    respuestaOperacionFactoreoNum1=FactorearNumero(num1);

                    MostrarOperacionesFactoreo(factoreo,num2);
                    respuestaOperacionFactoreoNum2=FactorearNumero(num2);

                    contadorMenu=3;
                }else
                {
                    printf("\n Debe ingresar numeros primero");
                 }
            break;

            case 4:
                if(contadorMenu==3){

                    ResultadoOperaciones(suma,num1,oparadorSuma,num2,respuestaOperacion);

                    ResultadoOperaciones(resta,num1,oparadorResta,num2,respuestaOperacion);

                    if(num2==0)
                    {

                        ResultadoOperacionesError(division,num1,oparadorDivision,num2,errorDivision);
                    }
                    else
                    {

                        ResultadoOperacionesFlotante(division,num1,oparadorDivision,num2,respuestaOperacionFlotante);
                    }


                    ResultadoOperaciones(multiplicacion,num1,oparadorMultiplicacion,num2,respuestaOperacion);


                    ResultadoOperacionesFactoreo(factoreo,num1,respuestaOperacionFactoreoNum1);


                    ResultadoOperacionesFactoreo(factoreo,num2,respuestaOperacionFactoreoNum2);
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
