#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "ArrayEmployees.h"
#define LEN 1000



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
    salida=tolower(salida);

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

int MenuChange()
{
    int opcion;

    printf("----- MODIFICAR -----\n");
    printf("1- Nombre del empleado. \n");
    printf("2- Apellido del empleado. \n");
    printf("3- Salario del empleado  \n");
    printf("4- Sector del empleado  \n");
    printf("5- Volver al menu  \n");

    opcion=GetInt("Ingrese una opcion: ","ERROR la opcion no puede ser un numero negativo ");

    return opcion;
}

int Menu()
{
    int opcion;

    printf("----- Seleccione una opcion -----\n");
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
            break;

            case 2:
                    system("cls");
                    VerificationFunctionModify(listEmployee, LEN);
            break;

            case 3:
                    system("cls");
                    VerificationFunctionRemove(listEmployee, LEN);

            break;

            case 4:

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

                    }while(respuestaMenuCuatro!='a'&&respuestaMenuCuatro!='b');

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

    while(salida!='n'&&salida!='s')
    {
        printf("%s",errorMsg);
        salida=IngresarDatoChar();

    }
    return salida;
}
