#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Concursantes.h"
int main()
{
    LinkedList* pArrayConcursantes = ll_newLinkedList();
    char archivo[40];
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
                printf("Ingrese archivo a abrir");
                scanf("%s", archivo);
                loadFromText(archivo, pArrayConcursantes);

            }break;
            case 2:
            {
                ListConcursantes(pArrayConcursantes);
            }break;
        }
    }while(opcion!=0);

    return 0;
}
