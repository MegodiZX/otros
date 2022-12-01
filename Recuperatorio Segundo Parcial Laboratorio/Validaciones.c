/*
 * Validaciones.c
 *
 *  Created on: 13 nov. 2022
 *      Author: 54112
 */


#include "Validaciones.h"

int itsFloatNumber(char str[])
{
    int i; //indice que permite revisar el string de floats
    int state=1; //bandera que permite saber si tiene solo numeros y puntos
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'0'||str[i]>'9') && str[i]!='.')
        {
            state=-1;
        }
        i++;
    }
    return state;
}

int itsNumber(char str[])
{
    int i; //indice para revisar el string
    int state=1; //bandera que permite saber si solo posee numeros
    i=0;
    while (str[i]!='\0')
    {
        if (str[i]<'0'||str[i]>'9')
        {
            state=-1;
        }
        i++;
    }
    return state;
}

int itsStringJustLetters(char str[])
{
    int i; //indice para revisar el string
    int state=1; //bandera que permite saber si solo posee letras y espacios
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]<'a' || str[i]>'z') && (str[i]<'A'||str[i]>'Z') && str[i]!=' ')
        {
            state=-1;
        }
        i++;
    }
    return state;
}

int itsPhoneNumber(char str[])
{
    int i; //indice para revisar el string
    int hyphenCounter; //contador de guiones
    int state=0; // bandera que permite saber si solo posee numeros y guiones
    hyphenCounter=0;
    i=0;
    while (str[i]!='\0')
    {
        if ((str[i]!=' ') && str[i]!='-' && (str[i]<'0' || str[i]>'9'))
        {
            state=-1;
        }
        if (str[i]=='-')
        {
            hyphenCounter++;
        }
    }
	if (state==0 && hyphenCounter!=0)
	{
		state=1;
	}
	return state;
}


void firstToUpper(char name[])
{
	strlwr(name);
	name[0] = toupper(name[0]);
	int j=0;

	while(name[j]!='\0')
	{

	   if(name[j]==' ')
	   {
		   name[j+1]= toupper (name[j+1]);

	   }
	   j++;
	}
}

void stringToUpper(char letters[])
{
    int i;

    for (i=0; letters[i] != '\0'; i++)
    {
    letters[i] = toupper(letters[i]);
    }
}

void stringToLower(char letters[])
{
    int i;

    for (i=0; letters[i] != '\0'; i++)
    {
    letters[i] = tolower(letters[i]);
    }
}
