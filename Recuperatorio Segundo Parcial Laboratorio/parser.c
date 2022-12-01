#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"
#include "LinkedList.h"


int parser_LibroFromText(FILE* pFile , LinkedList* pArrayList)
{
	int state = -1;
	eLibro* this = NULL;
	char id[100];
	char titulo[100];
	char importe[100];
	char idTipo[100];

	if (pArrayList!=NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, titulo, importe, idTipo);

		while(!(feof(pFile)))
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, titulo, importe, idTipo);
			this = libro_newParametros(id, titulo, importe, idTipo);
			ll_add(pArrayList, this);
		}
	}

	if (feof(pFile))
	{
		state = 1;
	}
	return state;
}
