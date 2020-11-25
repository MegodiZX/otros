#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Concursantes.h"
#include "Controlador.h"
int main()
{
    LinkedList* pArrayConcursantes = ll_newLinkedList();
    int opcion;
    do
    {
        printf("1.Cargar archivos \n");
        printf("2.Imprimir datos \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            {
                if ((parser_ConcursanteFromText("buenosaires.csv", pArrayConcursantes))==1)
                    {

                        printf("\nLos empleados se cargaron con exito\n\n");
                    }
                    else
                    {
                        printf("\n\aError, los empleados ya fueron cargados al sistema\n\n");
                    }
            }break;
            case 2:
            {

            }break;
        }
    }while(opcion!=0);

    return 0;
}
