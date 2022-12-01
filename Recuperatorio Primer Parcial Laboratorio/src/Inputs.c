#include "Inputs.h"

int PedirEntero(char mensaje[])
{
    int valor;
    printf("%s",mensaje);
    scanf("%d",&valor);
    return valor;
}

int PedirEnteroConRango(int minimo, int maximo,char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    while(numero<minimo||numero>maximo)
    {
        printf("Error Debe ser un numero entre %d y %d: ",minimo,maximo);
        scanf("%d",&numero);
    }
    return numero;
}

void PedirCadena(char cadena[],char mensaje[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);
}

void firstToUpper(char name[])
{
	stringToLower(name);
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

void stringToLower(char letters[])
{
    int i;

    for (i=0; letters[i] != '\0'; i++)
    {
        letters[i] = tolower(letters[i]);
    }
}
