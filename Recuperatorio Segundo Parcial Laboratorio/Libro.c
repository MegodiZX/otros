#include "Libro.h"


eLibro* libro_new()
{
	eLibro* plibro=NULL;

	plibro = (eLibro*) malloc(sizeof(eLibro));


    return plibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr)
{
	eLibro* plibro=NULL;

	plibro = libro_new();

	if(plibro != NULL)
	{
		libro_setId(plibro,atoi(idStr));
		libro_setTitulo(plibro,tituloStr);
		libro_setImporte(plibro,atoi(importeStr));
		libro_setIdTipo(plibro,atoi(idTipoStr));
	}

	return plibro;

}

int libro_setId(eLibro* this,int id)
{
    int retorno = -1;

    if(this !=  NULL && id > 0)
    {
    	this->id = id;
        retorno = 0;
    }

    return  retorno;
}

int libro_getId(eLibro* this,int* id)
{
    int retorno= -1;

    if(this !=  NULL && id !=NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo)
{
    int retorno = -1;

    if(this !=  NULL && titulo != NULL)
    {
    	strcpy(this->titulo,titulo);
        retorno = 0;
    }

    return  retorno;
}

int libro_getTitulo(eLibro* this,char* titulo)
{
    int retorno= -1;

    if(this !=  NULL && titulo !=NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = 0;
    }

    return retorno;
}

int libro_setImporte(eLibro* this,int importe)
{
    int retorno = -1;

    if(this !=  NULL && importe > 0)
    {
    	this->importe = importe;
        retorno = 0;
    }

    return  retorno;
}

int libro_getImporte(eLibro* this,int* importe)
{
    int retorno= -1;

    if(this !=  NULL && importe !=NULL)
    {
        *importe = this->importe;
        retorno = 0;
    }

    return retorno;
}

int libro_setIdTipo(eLibro* this,int idTipo)
{
    int retorno = -1;

    if(this !=  NULL && idTipo > 0)
    {
    	this->idTipo = idTipo;
        retorno = 0;
    }

    return  retorno;
}

int libro_getIdTipo(eLibro* this,int* idTipo)
{
    int retorno= -1;

    if(this !=  NULL && idTipo !=NULL)
    {
        *idTipo = this->idTipo;
        retorno = 0;
    }

    return retorno;
}

void libro_printOne(eLibro* this)
{
	if(this!=NULL)
	{
		int id;
		char titulo[100];
		int importe;
		int idTipo;

		libro_getId(this,&id);
		libro_getTitulo(this,titulo);
		libro_getImporte(this,&importe);
		libro_getIdTipo(this,&idTipo);
		if(idTipo==1)
		{
			printf("\n%5d %30s %10d PAPEL\n", id, titulo, importe);
		}else
		{
			if(idTipo==2)
			{
				printf("\n%5d %30s %10d EBOOK\n", id, titulo, importe);
			}
		}


	}

}

int libro_ComparadoPorImporte(void* libro1, void* libro2)
{
    int state=1;
    eLibro* aux1 = (eLibro*) libro1;
    eLibro* aux2 = (eLibro*) libro2;
    int importeA;
    int importeB;
	libro_getImporte(aux1,&importeA);
	libro_getImporte(aux2,&importeB);
    if (importeA < importeB)
	{
		state = -1;
	}
	else
	{
		if (importeA == importeB)
		{
			state = 0;
		}
	}
    return state;
}

int libro_mapeoAumento(void* libro)
{
    int state = -1;
    eLibro* auxLibro = (eLibro*) libro;
    int idTipo;
    int importe=0;
    libro_getIdTipo(auxLibro,&idTipo);
    libro_getImporte(auxLibro,&importe);
    if(idTipo == 1)
	{
    	importe= importe+(importe*20/100);
    	libro_setImporte(auxLibro,importe);
	}
    if(idTipo == 2)
	{
		importe= importe+(importe*10/100);
		libro_setImporte(auxLibro,importe);
	}


    return state;
}
