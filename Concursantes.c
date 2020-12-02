#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Concursantes.h"

int loadFromText(char* fileName, LinkedList* pArrayConcursantes)
{
    int state=-1;
    FILE* pFile=NULL;
    pFile =fopen(fileName,"r");
    if(pFile!=NULL)
    {
        state= parser_ConcursanteFromText(pFile,pArrayConcursantes);
    }
    fclose(pFile);
    pFile= NULL;
    return state;

}
int parser_ConcursanteFromText(FILE* pFile , LinkedList* pArrayConcursantes)
{
    int state = -1;
    Econcursante* this= NULL;
    char numeroConcursante[10];
    char anioDeNacimiento[30];
    char nombre[50];
    char DNI[20];
    char fechaPresentacion[20];
    char temaPresentacion[100];
    char puntajePrimeraRonda[20];

    if (pArrayConcursantes!=NULL)
    {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion, puntajePrimeraRonda);

        while(!(feof(pFile)))
        {
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion, puntajePrimeraRonda);
            this = concursante_newParameters(numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion, puntajePrimeraRonda);
            ll_add(pArrayConcursantes, this);
        }
    }

    if (feof(pFile))
    {
        state = 1;
    }

    fclose(pFile);
    pFile = NULL;
    return state;
}

Econcursante* concursante_new()
{
    Econcursante* nuevoconcursante;
    nuevoconcursante=(Econcursante*) malloc (sizeof(Econcursante));
    return nuevoconcursante;
}

Econcursante* concursante_newParameters(char* numeroConcursante,char* anioDeNacimiento,char* nombre,char* DNI,char* fechaPresentacion,char* temaPresentacion,char* puntajePrimeraRonda)
{
    Econcursante* this = concursante_new();
    if (this != NULL)
    {
        set_concursante_NumeroConcursante(this, atoi(numeroConcursante));
        set_concursante_AnioDeNacimiento(this, atoi(anioDeNacimiento));
        set_concursante_NombreConcursante(this, nombre);
        set_concursante_DNI(this, atoi(DNI));
        set_concursante_fechaPresentacion(this, fechaPresentacion);
        set_concursante_TemaDePresentacion(this, temaPresentacion);
        set_concursante_puntajePrimeraRonda(this, atoi(puntajePrimeraRonda));
    }
    else
    {
        printf("\nNO HAY ESPACIO EN LA MEMORIA RAM\n");
    }
    return this;
}

int set_concursante_NumeroConcursante(Econcursante* this,int numeroConcursante)
{
    int state = -1;
    if (this != NULL)
    {
        this->numeroConcursante = numeroConcursante;
        state = 1;
    }
    return state;
}

int set_concursante_AnioDeNacimiento(Econcursante* this,int anioDeNacimiento)
{
    int state = -1;
    if (this != NULL)
    {
        this->anioDeNacimiento = anioDeNacimiento;
        state = 1;
    }
    return state;
}

int set_concursante_NombreConcursante(Econcursante* this,char* nombre)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(this->nombre, nombre);
        state = 1;
    }
    return state;

}

int set_concursante_DNI(Econcursante* this,int DNI)
{
    int state = -1;
    if (this != NULL)
    {
        this->DNI = DNI;
        state = 1;
    }
    return state;
}

int set_concursante_fechaPresentacion(Econcursante* this,char* fecha)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(this->fechaPresentacion, fecha);
        state = 1;
    }
    return state;
}

int set_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(this->temaPresentacion, temaPresentacion);
        state = 1;
    }
    return state;

}

int set_concursante_puntajePrimeraRonda(Econcursante* this,int puntajePrimeraRonda)
{
    int state = -1;
    if (this != NULL)
    {
        this->puntajePrimeraRonda = puntajePrimeraRonda;
        state = 1;
    }
    return state;
}

int GET_concursante_numeroConcursante(Econcursante* this,int* numeroConcursante)
{
    int state = -1;
    if (this!=NULL)
    {
        *numeroConcursante = this->numeroConcursante;
        state = 1;
    }
    return state;
}

int GET_concursante_anioDeNacimiento(Econcursante* this,int* anioDeNacimiento)
{
    int state = -1;
    if (this!=NULL)
    {
        *anioDeNacimiento = this->anioDeNacimiento;
        state = 1;
    }
    return state;
}

int GET_concursante_nombre(Econcursante* this,char* nombre)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(nombre,this->nombre);
        state = 1;
    }
    return state;

}

int GET_concursante_DNI(Econcursante* this,int* DNI)
{
    int state = -1;
    if (this!=NULL)
    {
        *DNI = this->DNI;
        state = 1;
    }
    return state;
}
int GET_concursante_fechaPresentacion(Econcursante* this,char* fechaPresentacion)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(fechaPresentacion,this->fechaPresentacion);
        state = 1;
    }
    return state;

}


int GET_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(temaPresentacion,this->temaPresentacion);
        state = 1;
    }
    return state;

}

int GET_concursante_puntajePrimeraRonda(Econcursante* this,int* puntajePrimeraRonda)
{
    int state = -1;
    if (this!=NULL)
    {
        *puntajePrimeraRonda = this->puntajePrimeraRonda;
        state = 1;
    }
    return state;
}

void MostrarUnConcursante(Econcursante* this)
{
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    int DNI;
    char fechaPresentacion[50];
    char temaPresentacion[100];
    int puntajePrimeraRonda;

    GET_concursante_numeroConcursante(this, &numeroConcursante);
    GET_concursante_anioDeNacimiento(this, &anioDeNacimiento);
    GET_concursante_nombre(this, nombre);
    GET_concursante_DNI(this, &DNI);
    GET_concursante_fechaPresentacion(this, fechaPresentacion);
    GET_concursante_TemaDePresentacion(this, temaPresentacion);
    GET_concursante_puntajePrimeraRonda(this, &puntajePrimeraRonda);
    printf("\n%d %5d %5s %5d %5s %5s %5d\n\n",numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
}

int ListConcursantes(LinkedList* pArrayConcursantes)
{
    int i;
    int state = -1;
    Econcursante* this;
    if (pArrayConcursantes != NULL)
    {
        printf("\n%s %5s %5s %5s %5s %5s %5s\n\n","Numero de Concursante", "Anio De Nacimiento","Nombre","DNI","Fecha Presentacion","Tema Presentacion", "Puntaje Primera Ronda");
        for (i = 0; i < ll_len(pArrayConcursantes); i++)
        {

            this = ll_get(pArrayConcursantes, i);
            MostrarUnConcursante(this);
        }
        state = 1;
    }
    return state;
}

int set_concursante_puntajeSegundaRonda(Econcursante* this,int puntajeSegundaRonda)
{
    int state = -1;
    if (this != NULL)
    {
        this->puntajeSegundaRonda = puntajeSegundaRonda;
        state = 1;
    }
    return state;
}

int set_concursante_promedioPuntaje(Econcursante* this,float promedioPuntaje)
{
    int state = -1;
    if (this != NULL)
    {
        this->promedioPuntaje = promedioPuntaje;
        state = 1;
    }
    return state;
}

int GET_concursante_puntajeSegundaRonda(Econcursante* this,int* puntajeSegundaRonda)
{
    int state = -1;
    if (this!=NULL)
    {
        *puntajeSegundaRonda = this->puntajeSegundaRonda;
        state = 1;
    }
    return state;
}

int GET_concursante_promedioPuntaje(Econcursante* this,float* promedioPuntaje)
{
    int state = -1;
    if (this!=NULL)
    {
        *promedioPuntaje = this->promedioPuntaje;
        state = 1;
    }
    return state;
}

int EvaluacionJurado(void* element)
{
    int state = 0;
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;

    if(element != NULL)
    {
        Econcursante* pElement = (Econcursante*)element;
        GET_concursante_puntajePrimeraRonda(pElement, &puntajePrimeraRonda);
        puntajeSegundaRonda= rand() % 101;
        set_concursante_puntajeSegundaRonda(pElement,puntajeSegundaRonda);
        promedio = (float)(puntajePrimeraRonda+puntajeSegundaRonda)/2;
        set_concursante_promedioPuntaje(pElement, promedio);
        state = 1;
    }

    return state;
}

void MostrarUnConcursante_ConPuntajesActualizados(Econcursante* this)
{
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    int DNI;
    char fechaPresentacion[50];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;

    GET_concursante_numeroConcursante(this, &numeroConcursante);
    GET_concursante_anioDeNacimiento(this, &anioDeNacimiento);
    GET_concursante_nombre(this, nombre);
    GET_concursante_DNI(this, &DNI);
    GET_concursante_fechaPresentacion(this, fechaPresentacion);
    GET_concursante_TemaDePresentacion(this, temaPresentacion);
    GET_concursante_puntajePrimeraRonda(this, &puntajePrimeraRonda);
    GET_concursante_puntajeSegundaRonda(this, &puntajeSegundaRonda);
    GET_concursante_promedioPuntaje(this, &promedio);
    printf("\n%d %5d %5s %5d %5s %5s %5d %5d %5f\n\n",numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,promedio);
}

int ListConcursantes_ConPuntajesActualizados(LinkedList* pArrayConcursantes)
{
    int i;
    int state = -1;
    Econcursante* this;
    if (pArrayConcursantes != NULL)
    {
        printf("\n%s %5s %5s %5s %5s %5s %5s %5s %5s\n\n","Numero de Concursante", "Anio De Nacimiento","Nombre","DNI","Fecha Presentacion","Tema Presentacion", "Puntaje Primera Ronda"," Puntaje Segunda Ronda","Promedio");
        for (i = 0; i < ll_len(pArrayConcursantes); i++)
        {

            this = ll_get(pArrayConcursantes, i);
            MostrarUnConcursante_ConPuntajesActualizados(this);
        }
        state = 1;
    }
    return state;
}

int saveAsText(char* fileName, LinkedList* pArrayConcursantes)
{
    int i;
    int state = -1;
    Econcursante* this = NULL;
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    int DNI;
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    int promedio;
    FILE* pFile = NULL;
    pFile = fopen(fileName, "w");

    if (pFile != NULL)
    {
        fprintf(pFile, "Numero del Concursante,Año de nacimiento,Nombre,DNI,Fecha de Presentacion, Tema, Puntaje 1ra Ronda,Puntaje 2da Ronda, Puntaje final(promedio)\n");

        for (i = 0; i < ll_len(pArrayConcursantes); i++)
        {
            this = ll_get(pArrayConcursantes, i);
            GET_concursante_numeroConcursante(this, &numeroConcursante);
            GET_concursante_anioDeNacimiento(this, &anioDeNacimiento);
            GET_concursante_nombre(this, nombre);
            GET_concursante_DNI(this, &DNI);
            GET_concursante_fechaPresentacion(this, fechaPresentacion);
            GET_concursante_TemaDePresentacion(this, temaPresentacion);
            GET_concursante_puntajePrimeraRonda(this, &puntajePrimeraRonda);
            GET_concursante_puntajeSegundaRonda(this, &puntajeSegundaRonda);
            GET_concursante_promedioPuntaje(this, &promedio);
            fprintf(pFile, "%d,%d,%s,%d,%s,%s,%d,%d,%d\n",numeroConcursante,anioDeNacimiento,nombre,DNI,fechaPresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,promedio);
            state = 1;
        }
    }

    fclose(pFile);
    this = NULL;
    return state;
}
