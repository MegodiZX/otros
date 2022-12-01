#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char nombreArchivo[50];
    int variableControl=0;
	LinkedList* listaLibros = ll_newLinkedList();

    do{

		printf("1.Cargar archivos\n");
		printf("2.Mostrar todos los Libros\n");
		printf("3.Ordenar Libros por importe de manera descendente\n");
		printf("4.Guardar archivo (como ordenado.csv)\n");
		printf("5.Agregar aumento del 10 porciento (eBOOK) o 20 porciento (Fisico)\n");
		printf("6.Guardar archivo (como mapeado.csv)\n");
		printf("7.Salir del programa\n");
		getValidInt(&option, "Opcion", 1, 7);

		switch(option)
		{

			case 1:
				if((ll_isEmpty(listaLibros))==1)
				{
					getString("archivo",nombreArchivo);
					if(controller_cargarLibrosDesdeTexto(nombreArchivo, listaLibros)==1)
					{
						printf("\nLos datos se cargaron con exito\n\n");

					}else
					{
						printf("\nNombre de archivo inexistente o archivo vacio\n\n");
					}

				}
				else
				{
					printf("\nError, los datos ya fueron cargados al sistema\n\n");
				}
				break;
			case 2:
				if((ll_isEmpty(listaLibros))==0)
				{
					controller_listarLibros(listaLibros);
				}
				else
				{
					printf("\nError. Se debe cargar el archivo primero.\n\n");
				}
				break;
			case 3:
				if((ll_isEmpty(listaLibros))==0)
				{
					controller_ordenarLibrosSegunImporteDescendente(listaLibros);
					variableControl=1;
				}
				else
				{
					printf("\nError. Se debe cargar el archivo primero.\n\n");
				}
				break;
			case 4:
				if(variableControl==1&&(ll_isEmpty(listaLibros))==0)
				{
					controller_guardarLibrosModoTexto("ordenado.csv",listaLibros);
					variableControl=0;
				}
				else
				{
					printf("\nError. Se debe cargar el archivo y ordenar los libros antes de guardar.\n\n");
				}
				break;
			case 5:
				if((ll_isEmpty(listaLibros))==0)
				{
					controller_AgregarAumento(listaLibros);
					variableControl=2;
				}
				else
				{
					printf("\nError. Se debe cargar el archivo primero\n\n");
				}
				break;
			case 6:
				if(variableControl==2 &&(ll_isEmpty(listaLibros))==0)
				{
					controller_guardarLibrosModoTexto("mapeado.csv",listaLibros);
					variableControl=0;
				}
				else
				{
					printf("\nError. Se debe cargar el archivo y mapear los libros antes de guardar.\n\n");
				}
				break;
			case 7:
				if(variableControl!=0)
				{
					printf("\nAVISO: Los cambios no fueron guardados.\n\n");
				}
				if(verifyConformity("Salir del programa","realizado")==1)
				{
					ll_deleteLinkedList(listaLibros);
				}else
				{
					option=0;
				}
				break;

		}
	}while(option != 7);

	return 0;
}


