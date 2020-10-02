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

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee()
 * \param len int Array length
 * \return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);

/** \brief print an employees
 *
 * \param eEmployee
 * \return void
 *
 */
void printAnEmploye(eEmployee anEmploye);

/** \brief print the content of employees array
 *
 * \param list Employee[]
 * \param length int
 * \return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(eEmployee list[], int len);


/** \brief Search Free space
 *
 * \param list[] eEmployee
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (!=-1) if Ok
 *
 */
int SearchFree(eEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee[]
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployees(eEmployee list[], int len, int id);

/** \brief add in a existing  employees
 * \param id int
 * \return eEmployee whit structure to copy
 *
 */
eEmployee AddAnEmployeed(int id);


/** \brief Sum and average the salaries of the employees entered
 *
 * \param list employee[]
 * \param len int
 * \return void
 *
 */
void addSalary(eEmployee list[],int len);

/** \brief Search Employee by id
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (!=-1) if Ok
 *
 */
int FindEmployeeById(eEmployee list[], int len,int id);

/** \brief modify Employee
 *
 * \param list[] eEmployee
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int ModifyEmployeeById(eEmployee list[], int len);

/** \brief f Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list[] eEmployee
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int RemoveEmployee(eEmployee list[],int len);

/** \brief sort employees in ascending or descending order depending on what the user decides
 *
 * \param list[] eEmployee
 * \param len int
  * \param order int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee listEmployee[], int len, int order);

/** \brief sort employees in ascending order
 *
 * \param list[] eEmployee
 * \param len int
 * \param i int
 * \param j int
 * \param order int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void SortAscending(eEmployee listEmployee[], int len,int i, int j, int order);

/** \brief sort employees in descending order
 *
 * \param list[] eEmployee
 * \param len int
 * \param i int
 * \param j int
 * \param order int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void SortDescending(eEmployee listEmployee[], int len,int i, int j, int order);

/** \brief Verification  return of Function Remove
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void VerificationFunctionRemove(eEmployee listEmployee[],int len);

/** \brief Verification  return of Function Modify
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void VerificationFunctionModify(eEmployee listEmployee[],int len);

/** \brief Verification  return of Function Init
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void VerificationFunctionInit(eEmployee listEmployee[],int len);

/** \brief Verification  return of Function Sort
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void VerificationFunctionSort(eEmployee listEmployee[],int len);


/** \brief Verification  and get string
 *
 * \param dato[] char
 * \param msg[] char
 * \param msgError[] char
 * \param len int
 * \return void
 *
 */
void GetString(char dato[], char msg[],char msgError[], int len);


/** \brief Verification  and get float
 *
 * \param msg[] char
 * \param msgError[] char
 * \return void
 *
 */
float GetFloat(char msg[],char msgError[]);

/** \brief Verification  and get float
 *
 * \param msg[] char
 * \param msgError[] char
 * \return void
 *
 */
int GetInt(char msg[],char msgError[]);

/** \brief Verification  and get float
 *
 * \param msg[] char
 * \param msgError[] char
 * \return void
 *
 */
int ValidarRepuestaInt(char msg[],char errorMsg[]);

void MenuChangeSwitch(eEmployee list[], int len, int i);

#endif // ARRAYEMPLOYEES_H_INCLUDED
