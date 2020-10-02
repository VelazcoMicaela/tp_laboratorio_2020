#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "ArrayEmployees.h"
#define TAMNOMAPE 51
#define LEN 1000


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
    printf("%5d %50s %50s    %.2f %2d \n", anEmploye.id,anEmploye.name,anEmploye.lastName,anEmploye.salary,anEmploye.sector);
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
        printf("   ID                                           Nombre                                            Apellido     Sueldo     Sector  \n");
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
           printf("No hay Empleados para mostrar \n");
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
    dato=IngresarDatoEntero();

   while(dato<0)//
   {
       printf("%s",msgError);
       dato=IngresarDatoEntero();
   }

   return dato;
}
int ValidarRepuestaInt(char msg[],char errorMsg[])
{
    int salida;

    printf("%s",msg);
    salida=IngresarDatoEntero();
    while(salida!=1&&salida!=2)
    {
        printf("%s",errorMsg);
        salida=IngresarDatoEntero();
    }
    return salida;
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
    int alpha;

   /* printf("%s",msg);
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

        if(!isalpha(buffer[i]))
        {
            printf("ERROR Ingrese solo letras \n");
            break;
        }
    }*/


   do
   {
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
           /* if(!isalpha(buffer[i]))
            {
                printf("ERROR Ingrese solo letras \n");
                break;
            }*/
        }
   }while(strlen(buffer)>len-1);
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

void MenuChangeSwitch(eEmployee list[], int len, int i)
{
    char changeName[51];
    char changeLastName[51];
    float changeSalary;
    int changeSector;
    char salida;

    do{
        switch(MenuChange())
        {
            case 1:
                system("cls");
                GetString(changeName,"Ingrese el nombre: ","ERROR nombre muy largo ",51);
                strcpy(list[i].name,changeName);
                printEmployees(list, len);
                break;

            case 2:
                system("cls");
                GetString(changeLastName,"Ingrese el apellido: ","ERROR apellido muy largo ",51);
                strcpy(list[i].lastName,changeLastName);
                printEmployees(list, len);
                break;

            case 3:
                system("cls");
                changeSalary=GetFloat("Ingrese el salario: ","ERROR salario no puede ser negativo ");
                list[i].salary=changeSalary;
                printEmployees(list, len);
                break;

            case 4:
                system("cls");
                changeSector=GetInt("Ingrese el sector: ","ERROR sector no puede ser negativo ");
                list[i].sector=changeSector;
                printEmployees(list, len);
                break;

            case 5:
                system("cls");
                salida=ValidarRepuesta("Seguro que desea salir?S-N ","ERROR Ingrese S para salir o N para volver al menu ");
                break;

            default:
                printf("No es un num valido \n");
                break;
        }
    }while(salida!='s');
}

int ModifyEmployeeById(eEmployee list[], int len)
{
    int error=-1;
    int index;
    int id;

    if(list!=NULL&&len>0)
    {
        printEmployees(list, len);
        id=GetInt("Ingrese Id a modificar: ","ERROR Id no puede ser un numero negativo  \n");
        index=FindEmployeeById(list,len,id);

        if(index==-1)
        {
            printf("No hay ningun id con ese numero \n");
            system("cls");
        }
        else
        {
            MenuChangeSwitch(list, len,index);
            error=0;
        }
    }
    return error;
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


void VerificationFunctionSort(eEmployee listEmployee[],int len)
{
    int order;

    order=ValidarRepuestaInt(" Ingrese: 1- Ordenamiento ascendente, 2-Ordenamiento descendente "," ERROR Ingrese: 1- Ordenamiento ascendente, 2-Ordenamiento descendente ");

    if(sortEmployees(listEmployee,LEN,order)==0)
    {
        printf("Ordenamiento Realizado \n");
    }
    else
    {
        printf("Fallo \n");
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

int sortEmployees(eEmployee listEmployee[], int len, int order)
{
    int i;
    int j;
    int error=-1;

        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
               SortAscending(listEmployee, len, i, j, order);
               SortDescending(listEmployee, len, i, j, order);
            }
        }
      error=0;

     return error;
}

void SortAscending(eEmployee listEmployee[], int len,int i, int j, int order)
{
    eEmployee auxEmployee;
    if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)>0 &&order==1)
    {
        auxEmployee=listEmployee[i];
        listEmployee[i]=listEmployee[j];
        listEmployee[j]=auxEmployee;
    }
    else
    {
        if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)==0 &&order==1)
        {
            if(listEmployee[i].sector>listEmployee[j].sector)
            {
                auxEmployee=listEmployee[i];
                listEmployee[i]=listEmployee[j];
                listEmployee[j]=auxEmployee;
            }
        }
    }
}

void SortDescending(eEmployee listEmployee[], int len,int i, int j, int order)
{
    eEmployee auxEmployee;

    if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)<0 &&order==2)
    {
        auxEmployee=listEmployee[i];
        listEmployee[i]=listEmployee[j];
        listEmployee[j]=auxEmployee;
    }
    else
    {
        if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName)==0 &&order==2)
        {
            if(listEmployee[i].sector<listEmployee[j].sector)
            {
                auxEmployee=listEmployee[i];
                listEmployee[i]=listEmployee[j];
                listEmployee[j]=auxEmployee;
            }
        }
    }
}

void addSalary(eEmployee list[],int len)
{
    float promedio;
    float accumulatorSalary=0;
    int contadorEmpleados=0;
    int contadorEmpleadosSupera=0;
    int i;

    for(i=0;i<len;i++)
    {
        accumulatorSalary=accumulatorSalary+list[i].salary;
        if(list[i].isEmpty==0)
        {
            contadorEmpleados++;
        }
    }

    promedio=accumulatorSalary/contadorEmpleados;

    for(i=0;i<len;i++)
    {
        if(list[i].salary>promedio)
        {
            contadorEmpleadosSupera++;
        }
    }

    printf("%.2f \n",promedio);
    printf("%d Superan el promedio de %.2f \n",contadorEmpleadosSupera,promedio);
}
