
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
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    int DNI;
    char fechaPresentacion[10];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    int puntajeTerceraRonda;
    float promedioPuntaje;
}Econcursante;


#endif
//primera parte
int parser_ConcursanteFromText(FILE* pFile , LinkedList* pArrayConcursantes);
Econcursante* concursante_new(void);
Econcursante* concursante_newParameters(char* numeroConcursante,char* anioDeNacimiento,char* nombre,char* DNI,char* fechaPresentacion,char* temaPresentacion,char* puntajePrimeraRonda);
int loadFromText(char* fileName, LinkedList* pArrayConcursantes);
int set_concursante_NumeroConcursante(Econcursante* this,int numeroConcursante);
int set_concursante_AnioDeNacimiento(Econcursante* this,int anioDeNacimiento);
int set_concursante_NombreConcursante(Econcursante* this,char* nombre);
int set_concursante_DNI(Econcursante* this,int DNI);
int set_concursante_fechaPresentacion(Econcursante* this,char* fecha);
int set_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion);
int set_concursante_puntajePrimeraRonda(Econcursante* this,int puntajePrimeraRonda);
int GET_concursante_numeroConcursante(Econcursante* this,int* numeroConcursante);
int GET_concursante_anioDeNacimiento(Econcursante* this,int* anioDeNacimiento);
int GET_concursante_nombre(Econcursante* this,char* nombre);
int GET_concursante_DNI(Econcursante* this,int* DNI);
int GET_concursante_fechaPresentacion(Econcursante* this,char* fechaPresentacion);
int GET_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion);
int GET_concursante_puntajePrimeraRonda(Econcursante* this,int* puntajePrimeraRonda);
void MostrarUnConcursante(Econcursante* this);
int ListConcursantes(LinkedList* pArrayConcursantes);
//segunda parte
int set_concursante_puntajeSegundaRonda(Econcursante* this,int puntajeSegundaRonda);
int set_concursante_promedioPuntaje(Econcursante* this,float promedioPuntaje);
int GET_concursante_puntajeSegundaRonda(Econcursante* this,int* puntajeSegundaRonda);
int GET_concursante_promedioPuntaje(Econcursante* this,float* promedioPuntaje);
int EvaluacionJurado(void* element);
void MostrarUnConcursante_ConPuntajesActualizados(Econcursante* this);
int ListConcursantes_ConPuntajesActualizados(LinkedList* pArrayConcursantes);
int saveAsText(char* fileName, LinkedList* pArrayConcursantes);
//tercera parte
int MenosDe10PrimeraRonda(void* element);
int saveAsText_PuntajeIndividualPrimeraRonda(LinkedList* pArrayConcursantes);
int filtrarFinalistas(void* element, int puntajePrimerLugar, int puntajeSegundoLugar, int puntajeTercerLugar, int ronda);
//cuarta parte
int GET_concursante_puntajeTerceraRonda(Econcursante* this,int* puntajeTerceraRonda);
