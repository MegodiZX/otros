#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../inc/LinkedList.h"
#include "Input.h"
#include "Validaciones.h"


#ifndef Libro_H_INCLUDED
#define Libro_H_INCLUDED

typedef struct
{
	int id;
	char titulo[100];
	int importe;
	int idTipo;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr);

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setImporte(eLibro* this,int importe);
int libro_getImporte(eLibro* this,int* importe);

int libro_setIdTipo(eLibro* this,int idTipo);
int libro_getIdTipo(eLibro* this,int* idTipo);

void libro_printOne(eLibro* this);

int libro_ComparadoPorImporte(void* libro1, void* libro2);

int libro_mapeoAumento(void* libro);
#endif // Libro_H_INCLUDED
