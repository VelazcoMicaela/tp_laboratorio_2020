#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "ArrayEmployees.h"
#define LEN 5



int IngresarDatoEntero()
{
    int opcion;
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

char IngresarDatoChar()
{
    char salida;

    fflush(stdin);
    scanf("%c",&salida);

    return salida;
}
char MenuCuatro()
{
    char opcion;

    printf("4- INFORMAR \n");
    printf("A- Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n");
    printf("B- Total y promedio de los salarios, y cuantos empleados superan el salario promedio.  \n");

    opcion=IngresarDatoChar();

    return opcion;
}

int Menu()
{
    int opcion;

    printf("Seleccione una opcion \n");
    printf("1- Altas de empleados \n");
    printf("2- Modificar empleado por Id \n");
    printf("3- Bajas de empleados\n");
    printf("4- Informar \n");
    printf("5- Salir \n");

    opcion=IngresarDatoEntero();

    return opcion;
}

void MostrarMenu()
{
    char salida;
    char respuestaMenuCuatro;
    char seguirCargando;
    eEmployee listEmployee[LEN];
    int idNext=1;
    int corroboracionMenu;


    VerificationFunctionInit(listEmployee,LEN);

    do
    {
        switch(Menu())
        {
            case 1:
                system("cls");
                do
                {
                    if(addEmployees(listEmployee, LEN,idNext)==0)
                    {
                        system("cls");
                        idNext++;
                        printf("\n ------ Alta exitosa ------- \n\n");
                        printEmployees(listEmployee, LEN);
                    }
                    else
                    {
                        printf("\n -- No se pudo  \n\n");
                    }

                    seguirCargando=ValidarRepuesta("Desea ingresar mas empleados?S-N ","ERROR Ingrese S para seguir cargando o N para volver al menu\n ");
                    system("cls");

                }while(seguirCargando!='n');
                corroboracionMenu=1;
            break;

            case 2:
                if(corroboracionMenu==1)
                {
                    system("cls");
                    VerificationFunctionModify(listEmployee, LEN);
                    corroboracionMenu=2;
                }
                else
                {
                    system("cls");
                    printf("------ Debe ingresar a la opcion 1 ------ \n");
                }
            break;

            case 3:
                if(corroboracionMenu==2)
                {
                    system("cls");
                    VerificationFunctionRemove(listEmployee, LEN);
                    corroboracionMenu=3;
                }
                else
                {
                    system("cls");
                    printf("------ Debe ingresar a la opcion 1 y 2 ------  \n");
                }


            break;

            case 4:

                if(corroboracionMenu==3)
                {
                    system("cls");
                    printf("opcion cuatro\n");

                    do
                    {
                        respuestaMenuCuatro=MenuCuatro();

                        switch(respuestaMenuCuatro)
                        {
                            case 'a':
                                system("cls");
                                VerificationFunctionSort(listEmployee, LEN);
                            break;

                            case 'b':
                                system("cls");
                                addSalary(listEmployee, LEN);
                            break;

                            default:
                                printf("ERROR Ingrese A o B \n");
                            break;
                        }
                        system("cls");
                    }while(respuestaMenuCuatro!='a'&&respuestaMenuCuatro!='b');
                    corroboracionMenu=4;
                }
                else
                {
                    system("cls");
                    printf("------ Debe ingresar a la opcion 1, 2 y 3 ------  \n");
                }

            break;

            case 5:
                system("cls");
                salida=ValidarRepuesta("Seguro que desea salir?S-N ","ERROR Ingrese S para salir o N para volver al menu ");
            break;

            default:
                printf("ERROR, ingrese una opcion \n");
            break;
        }
     }while(salida!='s');
}

char ValidarRepuesta(char msg[],char errorMsg[])
{
    char salida;

    printf("%s",msg);
    salida=IngresarDatoChar();
    salida=tolower(salida);
    while(salida!='n'&&salida!='s')
    {
        printf("%s",errorMsg);
        salida=IngresarDatoChar();
        salida=tolower(salida);
    }
    return salida;
}
