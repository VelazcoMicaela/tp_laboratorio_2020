#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "ArrayEmployees.h"
#define TAMNOMAPE 51
#define LEN 5


int initEmployees(eEmployee list[], int len)
{
     int error;
    int i;
    error=1;

    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }

       error=0;
    }

    return error;
}

void printAnEmploye(eEmployee anEmploye)
{
    printf("%5d %50s %50s %6.2f %4d \n", anEmploye.id,anEmploye.name,anEmploye.lastName,anEmploye.salary,anEmploye.sector);
}

int printEmployees(eEmployee list[], int len)
{
    int error=1;
    int i;
    int flag;
    flag=0;

    error=1;

    if(list!=NULL&&len>0)
    {
        printf("   ID                                           Nombre                                            Apellido      Sueldo    Sector  \n");
        for(i=0;i<len;i++)
       {
           if(list[i].isEmpty==0)
            {
                printAnEmploye(list[i]);
                flag=1;
            }
        }

        if(flag==0)
        {
           printf("No hay lugar \n");
        }

       error=0;
    }

    return error;
}

int addEmployees(eEmployee list[], int len, int id)
{
    int error=-1;
    int index;

    if(list!=NULL&&len>0&&id>0)
    {
        index=SearchFree(list,len);

        if(index==-1)
       {
            printf("No hay lugar \n");
        }
        else
        {
           list[index]=AddAnEmployeed(id);

           error=0;
        }
    }

    return error;
}

int SearchFree(eEmployee list[], int len)
{
    int indice=-1;

    for(int i=0; i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

eEmployee AddAnEmployeed(int id)
{
    eEmployee anEmployee;
    char nombre[TAMNOMAPE];
    char apellido[TAMNOMAPE];

    anEmployee.id=id;
    anEmployee.isEmpty=0;

    GetString(nombre,"Ingrese el nombre: ","ERROR nombre muy largo ",TAMNOMAPE);
    strcpy (anEmployee.name, nombre);

    GetString(apellido,"Ingrese el apellido: ","ERROR apellido muy largo ",TAMNOMAPE);
    strcpy (anEmployee.lastName, apellido);

    anEmployee.salary=GetFloat("Ingrese su salario: ","ERROR salario no puede ser un numero negativo ");
    anEmployee.sector=GetInt("Ingrese su sector: ","ERROR sector no puede ser un numero negativo ");

    system("cls");

    return anEmployee;
}

int GetInt(char msg[],char msgError[])
{
   int dato;
    printf("%s",msg);
    fflush(stdin);
    scanf("%d",&dato);

   while(dato<0)//
   {
       printf("%s",msgError);
       fflush(stdin);
       scanf("%d",&dato);
   }

   return dato;
}

float GetFloat(char msg[],char msgError[])
{
    float numIngresado;

    printf("%s",msg);
    fflush(stdin);
    scanf("%f",&numIngresado);

   while(numIngresado<0)
   {
       printf("%s",msgError);
       fflush(stdin);
       scanf("%f",&numIngresado);
   }

   return numIngresado;
}

void GetString(char dato[], char msg[],char msgError[], int len)
{
    char buffer[len];
    int i;
    int tam;

    printf("%s",msg);
    fflush(stdin);
    scanf("%[^\n]",buffer);
    strlwr(buffer);

    tam=strlen(buffer);

    buffer[0]=toupper(buffer[0]);

    for(i=0;i<tam;i++)
    {
        if(isspace(buffer[i]))
        {
            buffer[i+1]=toupper(buffer[i+1]);
        }
    }

   while(strlen(buffer)>len-1)//mide el largo de la cadena
   {
        printf("%s",msgError);
        fflush(stdin);
        scanf("%[^\n]",buffer);
        strlwr(buffer);

        tam=strlen(buffer);

        buffer[0]=toupper(buffer[0]);

        for(i=0;i<tam;i++)
        {
            if(isspace(buffer[i]))
            {
                buffer[i+1]=toupper(buffer[i+1]);
            }
        }
   }
   strcpy (dato, buffer);
}

void VerificationFunctionInit(eEmployee listEmployee[],int len)
{
    if(initEmployees(listEmployee,LEN)==0)
    {
        printf("Inicializo \n");
    }
    else
    {
        printf("Fallo \n");
    }
}

void VerificationFunctionModify(eEmployee listEmployee[],int len)
{
    int modificacion;

    modificacion=ModifyEmployeeById(listEmployee,LEN);

    if(modificacion==0)
    {
        printf("----- Se realizo la modificacion con exito----- \n");
    }
    else
    {
       if (modificacion==-1)
       {
            printf("----- Problemas con la modificacion ----- \n");
       }
       else
        {
            printf("----- Modificacion cancelada por el usuario----- \n");
        }

    }
    printEmployees(listEmployee, LEN);
}

void VerificationFunctionRemove(eEmployee listEmployee[],int len)
{
    int remove;

    remove=RemoveEmployee(listEmployee,LEN);

    if(remove==0)
    {
        printf("----- Se realizo la modificacion con exito----- \n");
    }
    else
    {
       if (remove==-1)
       {
            printf("----- Problemas con la modificacion ----- \n");
       }
       else
        {
            printf("----- Modificacion cancelada por el usuario----- \n");
        }

    }
    printEmployees(listEmployee, LEN);
}



int FindEmployeeById(eEmployee list[], int len,int id)
{
    int index=-1;

    for(int i=0; i<len;i++)
    {
        if(list[i].id==id&&list[i].isEmpty==0)
        {
           index=i;
            break;
        }
    }
    return index;
}

int ModifyEmployeeById(eEmployee list[], int len)
{
    int error=-1;
    int indice;
    int id;
    char confirm;

    if(list!=NULL&&len>0)
    {
        printEmployees(list, len);
        id=GetInt("Ingrese Id a modificar: ","ERROR Id no puede ser un numero negativo ");
        indice=FindEmployeeById(list,len,id);

        if(indice==-1)
        {
            printf("No hay ningun id con ese numero \n");
            system("cls");
        }
        else
        {
            printAnEmploye(list[indice]);
            confirm=ValidarRepuesta("Desea modificar este empleado?S-N ","ERROR Ingrese S para modificar o N para volver \n ");
            system("cls");

            if(confirm=='s')
            {
                list[indice]=AddAnEmployeed(id);

                error=0;
            }
            else
            {
                error=2;
            }
        }
    }
    return error;
}

int RemoveEmployee(eEmployee list[],int len)
{
    int error=-1;
    int indice;
    int id;
    char confirm;

    if(list!=NULL&&len>0)
    {
        printEmployees(list, len);
        id=GetInt("Ingrese Id a borrar: ","ERROR Id no puede ser un numero negativo ");
        indice=FindEmployeeById(list,len,id);

        if(indice==-1)
        {
            printf("No hay ningun id con ese numero \n");
            system("cls");
        }
        else
        {
            printAnEmploye(list[indice]);
            confirm=ValidarRepuesta("Desea eliminar este empleado?S-N ","ERROR Ingrese S para eliminar o N para volver \n ");
            system("cls");

            if(confirm=='s')
            {
                list[indice].isEmpty=1;

                error=0;
            }
            else
            {
                error=2;
            }
        }
    }
    return error;
}