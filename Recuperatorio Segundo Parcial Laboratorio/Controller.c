#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Input.h"
#include "Libro.h"



int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayList)
{
	int state = -1;
	FILE* pFile = NULL;
	pFile = fopen (path, "r");
	if(pFile!=NULL)
	{
		state = parser_LibroFromText(pFile, pArrayList);
	}
	fclose(pFile);
	return state;
}

int controller_listarLibros(LinkedList* pArrayList)
{
	int i;
	int state = -1;
	eLibro* this;

	if (pArrayList != NULL)
	{
		printf("\n%5s %30s %10s %20s\n\n", "ID", "Titulo", "Importe", "IdTipo");
		for (i = 0; i < ll_len(pArrayList); i++)
		{
			this = ll_get(pArrayList, i);
			libro_printOne(this);
		}
		state = 1;

	}
	return state;
}

int controller_ordenarLibrosSegunImporteDescendente(LinkedList* pArrayList)
{
	int (*pFunc)(void*, void*);
	int state =-1;

	pFunc = libro_ComparadoPorImporte;

	if((ll_sort(pArrayList, pFunc, 0))==0)//1 ascendente 0 descendiente
	{
		printf("\nLos jugadores han sido ordenados.\n\n");
		state = 1;
	}else
	{
		printf("\nHubo un error en el ordenamiento.\n\n");
	}
	return state;
}

int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayList)
{
	int i;
	int state = -1;
	eLibro* this = NULL;
	int auxId;
	char auxTitulo[100];
	int auxImporte;
	int auxIdTipo;

	FILE* pFile = NULL;
	pFile = fopen (path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "id,titulo,importe,idTipo\n");

		for (i = 0; i < ll_len(pArrayList); i++)
		{
			this = ll_get(pArrayList, i);
			libro_getId(this, &auxId);
			libro_getTitulo(this, auxTitulo);
			libro_getImporte(this, &auxImporte);
			libro_getIdTipo(this, &auxIdTipo);
			fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxTitulo, auxImporte, auxIdTipo);
			state = 1;
		}
	}

	fclose(pFile);
	this = NULL;
	return state;
}


int controller_AgregarAumento(LinkedList* pArrayList)
{
	int (*pFunc)();
	int state = -1;

	pFunc = libro_mapeoAumento;
	if((ll_map(pArrayList, pFunc))==0)
	{
		printf("\nLos jugadores han sido mapeados.\n\n");
		state = 1;
	}
	else
	{
		printf("\nHubo un error en el mapeo.\n\n");
	}
	return state;
}

