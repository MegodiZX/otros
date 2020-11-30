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
    char numeroConcursante[3];
    char anioDeNacimiento[4];
    char nombre[50];
    char DNI[8];
    char fechaPresentacion[8];
    char temaPresentacion[100];
    char puntajePrimeraRonda[3];

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
        set_concursante_fechaPresentacion(this, (fechaPresentacion));
        set_concursante_TemaDePresentacion(this, (temaPresentacion));
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

int GET_concursante_TemaDePresentacion(Econcursante* this,char* temaPresentacion)
{
    int state = -1;
    if (this != NULL)
    {
        strcpy(this->temaPresentacion, temaPresentacion);
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
    char fechaPresentacion;
    char temaPresentacion;
    int puntajePrimeraRonda;



    GET_concursante_TemaDePresentacion(this, temaPresentacion);
    GET_concursante_puntajePrimeraRonda(this, &puntajePrimeraRonda);
    printf("\n%5d %10d %10s %10d %10s %10s %10d\n\n",this->numeroConcursante,this->anioDeNacimiento,this->nombre,this->DNI,this->fechaPresentacion,temaPresentacion,puntajePrimeraRonda);
}

int ListConcursantes(LinkedList* pArrayConcursantes)
{
    int i;
    int state = -1;
    Econcursante* this;
    if (pArrayConcursantes != NULL)
    {
        printf("\n%5s %10s %10s %10s %10s %10s %10s\n\n","Numero de Concursante", "Anio De Nacimiento","Nombre","DNI","Fecha Presentacion","Tema Presentacion", "Puntaje Primera Ronda");
        for (i = 0; i < ll_len(pArrayConcursantes); i++)
        {

            this = ll_get(pArrayConcursantes, i);
            MostrarUnConcursante(this);
        }
        state = 1;
    }
    return state;
}
