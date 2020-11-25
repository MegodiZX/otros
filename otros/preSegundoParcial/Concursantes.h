
/*
Concursante

● numeroConcursante (int)
● año de nacimiento
● nombre (string, 50)
● dni (string, 8, valor entre 9.000.000 y 45.000.000)
● fechaPresentacion (Date)
● temaPresentacion (string, 30)
● puntajePrimeraRonda(int)
Los datos van a estar cargados en un archivo .CSV

El programa contará con el siguiente menú:
1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un LinkedList los
elementos del mismo.
2) Imprimir Datos: Se imprimirá por pantalla la tabla con los datos
*/
#ifndef CONCURSANTES_H_INCLUDED
#define CONCURSANTES_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}Edata;

typedef struct
{
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    int DNI;
    Edata* fechaPresentacion;
    char temaPresentacion[100];
    int puntajePrimeraRonda;
}Econcursante;


#endif

int parser_ConcursanteFromText(FILE* pFile , LinkedList* pArrayConcursantes);
Econcursante* concursante_new(void);
Econcursante* concursante_newParameters(char* numeroConcursante/*char* anioDeNacimiento*/,char* nombre,char* DNI,char* fechaPresentacion,char* temaPresentacion,char* puntajePrimeraRonda);
int set_concursante_NumeroConcursante(Econcursante* this,int numeroConcursante);
int set_concursante_AnioDeNacimiento(Econcursante* this,int anioDeNacimiento);
int set_concursante_NombreConcursante(Econcursante* this,char* nombre);
int set_concursante_DNI(Econcursante* this,int DNI);
int set_concursante_fechaPresentacion(Econcursante* this,int fecha);
int set_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion);
int set_concursante_puntajePrimeraRonda(Econcursante* this,int puntajePrimeraRonda);
