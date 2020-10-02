#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief ask for a number to enter the menu
 *
 * \return int
 *
 */
int Menu();


/** \brief request and validate int
 *
 * \return int
 *
 */
int IngresarDatoEntero();


/** \brief request and validate the number char
 *
 * \return char
 *
 */
char IngresarDatoChar();


/** \brief shows the menu options and contains the logic of the same
 *
 * \return void
 *
 */
void MostrarMenu();


/** \brief shows the menu options for Sort and average
 *
 * \return char
 *
 */
char MenuCuatro();


/** \brief validate response for character output
 *
 * \param msg[] char
 * \param errorMsg[] char
 * \return char answer
 *
 */
char ValidarRepuesta(char msg[],char errorMsg[]);

/** \brief
 *
 * \return int of the chosen option
 *
 */
int MenuChange();

#endif // MENU_H_INCLUDED
