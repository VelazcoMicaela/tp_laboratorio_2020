#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;


int initEmployees(eEmployee list[], int len);
void printAnEmploye(eEmployee anEmploye);
int printEmployees(eEmployee list[], int len);
int SearchFree(eEmployee list[], int len);
int addEmployees(eEmployee list[], int len, int id);
eEmployee AddAnEmployeed(int id);
void addSalary(eEmployee list[],int len);

int FindEmployeeById(eEmployee list[], int len,int id);
int FindEmployeeById(eEmployee list[], int len,int id);
int ModifyEmployeeById(eEmployee list[], int len);
int RemoveEmployee(eEmployee list[],int len);
int sortEmployees(eEmployee listEmployee[], int len, int order);
void SortAscending(eEmployee listEmployee[], int len,int i, int j, int order);
void SortDescending(eEmployee listEmployee[], int len,int i, int j, int order);


void VerificationFunctionRemove(eEmployee listEmployee[],int len);
void VerificationFunctionModify(eEmployee listEmployee[],int len);
void VerificationFunctionInit(eEmployee listEmployee[],int len);
void VerificationFunctionSort(eEmployee listEmployee[],int len);


void GetString(char dato[], char msg[],char msgError[], int len);
float GetFloat(char msg[],char msgError[]);
int GetInt(char msg[],char msgError[]);
int ValidarRepuestaInt(char msg[],char errorMsg[]);

#endif // ARRAYEMPLOYEES_H_INCLUDED
