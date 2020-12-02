#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Concursantes.h"
int main()
{
    LinkedList* pArrayConcursantes = ll_newLinkedList();
    char archivo[40];
    char archivoAGuardar[100]="resultado";
    int opcion;
    int Condicion;
    Condicion=0;
    do
    {
        printf("\n1.Cargar archivos \n");
        printf("2.Imprimir datos \n");
        printf("3.Mostrar nuevos puntajes \n");
        printf("4.Ingresar notas del jurado \n");
        printf("5.Guardar en archivo \n");
        printf("6.Listar Concursantes con cierta condicion \n");
        printf("0.Salir \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("Ingrese archivo a abrir ");
                fflush(stdin);
                scanf("%[^\n]",archivo);
                strcat(archivo, ".csv");
                loadFromText(archivo, pArrayConcursantes);
                Condicion=1;

            }break;
            case 2:
            {
                if(Condicion>0)
                {
                    ListConcursantes(pArrayConcursantes);
                }else
                {
                    printf("\nPrimero se debe cargar un archivo (1.Cargar archivos)\n");
                }

            }break;
            case 3:
            {
                if(Condicion>1)
                {
                    ListConcursantes_ConPuntajesActualizados(pArrayConcursantes);
                }else
                {
                    printf("\nPrimero se debe cargar un archivo(1.Cargar archivos) y ser evaluados por el jurado (4.Ingresar notas del jurado)\n");
                }


            }break;
            case 4:
            {
                if(Condicion>0)
                {
                    if(ll_map(pArrayConcursantes, EvaluacionJurado) == 1)
                    {
                        Condicion=2;
                    }

                }else
                {
                    printf("\nPrimero se debe cargar un archivo (1.Cargar archivos)\n");
                }

            }break;
            case 5:
            {
                if(Condicion>0)
                {
                    printf("Ingrese archivo a abrir ");
                    fflush(stdin);
                    scanf("%[^\n]",archivo);
                    strcat(archivoAGuardar, archivo);
                    strcat(archivoAGuardar, ".csv");
                    printf("%s",archivoAGuardar);
                    saveAsText(archivoAGuardar, pArrayConcursantes);
                }else
                {
                    printf("\nPrimero se debe cargar un archivo (1.Cargar archivos)\n");
                }

            }break;
            case 6:
            {
                if(Condicion>0)
                {
                    /*Listar con condicion */
                }else
                {
                    printf("\nPrimero se debe cargar un archivo (1.Cargar archivos)\n");
                }

            }break;
            case 0:
            {
                printf("\nFinalizo el programa\n");
            }break;
        }
    }while(opcion!=0);

    return 0;
}
