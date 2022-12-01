#include "Libro.h"
#define LIBRE 0
#define OCUPADO 1


int HarcodearEditoriales(eEditorial lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int codigoEditorial[5]={1000,1001,1002,1003,1004};
        char descripcion[5][51]={"PenguEditorial","Editoriales.G","Edit.Co&Ce","Editorial.M","Editorial.E"};
        for(int i=0;i<5;i++)
        {
            
            lista[i].codigoEditorial=codigoEditorial[i];
            strcpy(lista[i].descripcion,descripcion[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

void MostarUnaEditorial(eEditorial lista)
{
    printf("\n%d \t\t%s \n",lista.codigoEditorial,lista.descripcion);
}

void MostrarListaDeEditoriales(eEditorial lista[], int tam)
{
    printf("\nIdEditorial \tDescripcion \n");
    for(int i=0;i<tam;i++)
    {
        MostarUnaEditorial(lista[i]);
    }
    
}

int HarcodearPaises(ePais lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int codigoPais[5]={100,101,102,103,104};
        char descripcion[5][51]={"Argentina","Brasil","EEUU","Mexico","Canada"};
        for(int i=0;i<5;i++)
        {
            
            lista[i].codigoPais=codigoPais[i];
            strcpy(lista[i].descripcion,descripcion[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

void MostrarUnPais(ePais lista)
{
    printf("\n%d \t%s \n",lista.codigoPais,lista.descripcion);
}

void MostrarListaDePaises(ePais lista[], int tam)
{
    printf("\nIdPais \tDescripcion \n");
    for(int i=0;i<tam;i++)
    {
        MostrarUnPais(lista[i]);
    }
    
}

int HarcodearAutores(eAutor lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int codigoAutor[10]={10,11,12,13,14,15,16,17,18,19};
        char nombre[10][51]={"Autor01","Autor02","Autor03","Autor04","Autor05","Autor06","Autor07","Autor08","Autor09","Autor10"};
        int codigoPais[10]={100,101,102,103,100,100,101,103,104,101};
        for(int i=0;i<10;i++)
        {
            
            lista[i].codigoAutor=codigoAutor[i];
            strcpy(lista[i].nombre,nombre[i]);
            lista[i].codigoPais=codigoPais[i];
        }
        todoOk=1;
    }
    return todoOk;
}

void MostrarUnAutor(eAutor lista,ePais listaPaises[], int tamP)
{
    printf("\n%d \t%s  ",lista.codigoAutor,lista.nombre);
    MostrarPaisSegunCodigo(listaPaises,tamP,lista.codigoPais);
}

void MostrarPaisSegunCodigo(ePais lista[], int tam, int codigoPais)
{
    int i=0;
    
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigoPais==codigoPais)
        {
            printf("\t%s\n",lista[i].descripcion);
        }
    }
}

void MostrarListaDeAutores(eAutor lista[], int tam,ePais listaPaises[], int tamP)
{
    printf("\nIdAutor \tNombre \t\tPais \n");
    for(int i=0;i<tam;i++)
    {
        MostrarUnAutor(lista[i],listaPaises,tamP);
    }
    
}

void InicializarLibros(eLibro lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

int BuscarLibre(eLibro lista[],int tam)
{
    int indice=-1;
    if(lista!=NULL && tam >0)
    {
       for(int i=0;i<tam;i++)
       {
           if(lista[i].estado==LIBRE)
           {
               
               indice=i;
               break;
           }
       }
    }else
    {
        printf("Error al buscar libre, array vacio o tamaño menor a 0");
    }
    return indice;
}

int AltaLibro(eLibro lista[],int tam,int* pId, eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,ePais listaPaises[], int tamP,eGenero listaGenero[], int tamG)
{
    int todoOk=0;
    int indice;
    eLibro auxLibro;
    if(lista!=NULL && tam >0 && pId!=NULL)
    {
        printf("\n          Alta Libro        \n");
        indice=BuscarLibre(lista, tam);
        if(indice==-1)
        {
            printf("\nno hay lugar en el sistema \n");
        }else
        {
            auxLibro.codigoLibro=*pId;//CODIGO LIBRO 
            (*pId)++;
            
            PedirCadena(auxLibro.titulo,"Ingrese titulo del libro: ");
            
            stringToLower(auxLibro.titulo);//paso el titulo entero a minuscula
            firstToUpper(auxLibro.titulo);//paso el primer caracter a mayuscula si hay espacio paso tambien ese
            
            auxLibro.fechaPublicacion.dia=PedirEnteroConRango(1,31,"Ingrese fecha de publicacion (solo dia): ");
            auxLibro.fechaPublicacion.mes=PedirEnteroConRango(1,12,"Ingrese fecha de publicacion (solo mes): ");
            auxLibro.fechaPublicacion.anio=PedirEnteroConRango(1000,2022,"Ingrese fecha de publicacion (solo anio): ");
            
            auxLibro.importe=PedirEnteroConRango(1,999999,"Ingrese el importe del libro: ");
            
            MostrarListaDeAutores(listaAutores,tamA,listaPaises,tamP);
            auxLibro.codigoAutor=PedirEnteroConRango(10,19,"Ingrese codigo del Autor (10 al 19) ");
            
            MostrarListaDeEditoriales(listaEditoriales,tamEdit);
            auxLibro.codigoEditorial=PedirEnteroConRango(1000,1004,"Ingrese codigo de la Editorial (1000 al 1004) ");
            
            MostrarListaDeGeneros(listaGenero,tamG);
            auxLibro.codigoGenero=PedirEnteroConRango(20,24,"Ingrese codigo del genero (20 al 24) ");
            
            auxLibro.estado=OCUPADO;//ESTADO
            
            lista[indice]=auxLibro;
            todoOk=1;
        }
        
    }
    return todoOk;
}

void MostarUnLibro(eLibro lista,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[],int tamEdit,eGenero listaGeneros[], int tamG)
{
    if(lista.estado==OCUPADO)
    {
        
        printf("\n%d %25s  \t%d.%d.%d  \t%d \t",lista.codigoLibro,lista.titulo,lista.fechaPublicacion.dia,lista.fechaPublicacion.mes,lista.fechaPublicacion.anio,lista.importe);
        MostrarAutorSegunCodigo(listaAutores,tamA,lista.codigoAutor);
        printf("\t");
        MostrarEditorialSegunCodigo(listaEditoriales,tamEdit,lista.codigoEditorial);
        printf("\t");
        MostrarGeneroSegunCodigo(listaGeneros,tamG,lista.codigoGenero);
        printf("\n");
    }
}

void MostrarAutorSegunCodigo(eAutor lista[], int tam, int codigoAutor)
{
    int i=0;
    
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigoAutor==codigoAutor)
        {
            printf("\t%s",lista[i].nombre);
            break;
        }
    }
}

void MostrarEditorialSegunCodigo(eEditorial lista[], int tam, int codigoEditorial)
{
    int i=0;
    
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigoEditorial==codigoEditorial)
        {
            printf("\t%s",lista[i].descripcion);
        }
    }
}

void MostrarListaDeLibros(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG)
{
    printf("\nIdLibro \t Titulo \tFecha(d/m/a)  \tImporte   \tAutor\t \tEditorial\t  \tGenero\n");
    for(int i=0;i<tam;i++)
    {
        MostarUnLibro(lista[i],listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
    }
    
}

void BajaLibro(eLibro listado[], int tam, eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit)
{
    int codigo;
    codigo=PedirEntero("\nIngrese codigo del libro a eliminar (cancela con poner uno que no sea un codigo de libro valido) ");
    
    for(int i=0;i<tam;i++)
    {
        if(codigo==listado[i].codigoLibro)
        {
            printf("\nELIMINO\n");
            listado[i].estado=LIBRE;
            break;
        }else
        {
            printf("\nSe cancelo la eliminacion\n");
        }
        
    }
}

void OrdenarLibrosPorImporteYTitulo(eLibro listado[], int tam)
{
    int i;
    int j;
    eLibro auxLibro;
    
	for( i=0; i<tam-1; i++)
	{
		for( j=i+1; j<tam; j++ )
		{
			if(listado[i].importe<listado[j].importe)
			{
				auxLibro = listado[i];
				listado[i] = listado[j];
				listado[j] = auxLibro;
			}else
			{
				if(listado[i].importe==listado[j].importe)
				{
					if(strcmp(listado[i].titulo, listado[j].titulo)>0)
					{
						auxLibro = listado[i];
						listado[i] = listado[j];
						listado[j] = auxLibro;
				    }
			    }
		    }	
	    }
    }
}

void ModificarLibro(eLibro listado[], int tam,int parametroAModificar)
{
    int codigoIngresado;
    int i;
    
    codigoIngresado=PedirEntero("\nIngrese codigo del libro a Modificar (cancela con poner uno que no sea un codigo de libro valido) ");
    for(i=0; i<tam;i++)
    {
        if(codigoIngresado==listado[i].codigoLibro&&listado[i].estado==OCUPADO)
        {
	        switch(parametroAModificar)
	        {
	            case 1:
	            PedirCadena(listado[i].titulo,"Ingrese nuevo titulo: ");
	            break;
	            case 2:
	            listado[i].fechaPublicacion.dia=PedirEnteroConRango(1,31,"Ingrese nueva fecha de publicacion (solo dia): ");
                listado[i].fechaPublicacion.mes=PedirEnteroConRango(1,12,"Ingrese nueva fecha de publicacion (solo mes): ");
                listado[i].fechaPublicacion.anio=PedirEnteroConRango(1000,2022,"Ingrese nueva fecha de publicacion (solo anio): ");
	            break;
	            case 3:
	            listado[i].importe=PedirEnteroConRango(1,999999,"Ingrese nuevo importe: ");
	            break;
	            case 4:
	            listado[i].codigoAutor=PedirEnteroConRango(10,19,"Ingrese nuevo codigo del autor (10 al 19) ");
	            break;
	            case 5:
	            listado[i].codigoEditorial=PedirEnteroConRango(1000,1004,"Ingrese nuevo codigo de editorial (1000 al 1004) ");
	            break;
	            case 6:
	            listado[i].codigoGenero=PedirEnteroConRango(20,24,"Ingrese nuevo codigo de genero (20 al 24) ");
	            break;
	        }
        }
    }
}

int CalcularTotal(eLibro listado[],int tam)
{
    int resultado=0;
    int i;
    
    for(i=0; i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            resultado=resultado+listado[i].importe;
        }
    }
    return resultado;
}

float CalcularPromedio(eLibro listado[],int tam)
{
    int cont=0;
    int i;
    int resultado;
    int total;
    
    total=CalcularTotal(listado,tam);
    for(i=0; i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            cont++;
        }
    }
    
    resultado=((float)total/cont);
    return resultado;
}

void MostrarTotalImportesYPromedio(eLibro listado[],int tam)
{
    int total;
    float promedio;
    
    total=CalcularTotal(listado,tam);
    promedio=CalcularPromedio(listado,tam);
    
    printf("\nEl importe total de todos los libros es: $%d",total);
    printf("\nEl importe promedio es: $%.2f",promedio);
}

void MostrarLibrosConImportesSuperioresAlPromedio(eLibro listado[],int tam,eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG)
{
    int i;
    int promedio;
    
    promedio=CalcularPromedio(listado,tam);
    
    printf("\nLos libros con un importe superior al promedio son: \n");
    for(i=0; i<tam;i++)
    {
        if(listado[i].importe>promedio&&listado[i].estado==OCUPADO)
        {
            MostarUnLibro(listado[i],listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
        }
    }
}

void MostrarLibrosFechaAnteriorAl2000(eLibro listado[],int tam,eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG)
{
    int i;
    printf("\nLos libros con fecha anterior al 01/01/2000 son: \n");
    printf("\nIdLibro  Titulo \tFecha(d/m/a)  \tImporte    Autor  \tEditorial  \tGenero\n");
    for(i=0; i<tam;i++)
    {
        if(listado[i].fechaPublicacion.anio<2000&&listado[i].estado==OCUPADO)
        {
            MostarUnLibro(listado[i],listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
        }
    }
}
//PARTE 2

int HarcodearGeneros(eGenero lista[])
{
    int todoOk=0;
    if(lista!=NULL)
    {
        int codigoGenero[5]={20,21,22,23,24};
        char descripcion[5][51]={"Narrativo","Lirico","Dramatico","Didactico","Novela"};
        for(int i=0;i<5;i++)
        {
            
            lista[i].codigoGenero=codigoGenero[i];
            strcpy(lista[i].descripcion,descripcion[i]);
        }
        todoOk=1;
    }
    return todoOk;
}

void MostrarUnGenero(eGenero lista)
{
    printf("\n%d \t%s \n",lista.codigoGenero,lista.descripcion);
}

void MostrarListaDeGeneros(eGenero lista[], int tam)
{
    printf("\nIdGenero \tDescripcion \n");
    for(int i=0;i<tam;i++)
    {
        MostrarUnGenero(lista[i]);
    }
    
}

void MostrarLibrosConGenerosDistintosANovela(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG)
{
    int i;
    printf("\nLos libros con genero distinto de Novela son: \n");
    printf("\nIdLibro  Titulo \tFecha(d/m/a)  \tImporte    Autor  \tEditorial  \tGenero\n");
    for(i=0; i<tam;i++)
    {
        if(lista[i].codigoGenero!=24&&lista[i].estado==OCUPADO)
        {
            MostarUnLibro(lista[i],listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
        }
    }
}

void MostrarGeneroSegunCodigo(eGenero lista[], int tam, int codigoGenero)
{
    int i=0;
    for(i=0;i<tam;i++)
    {
        if(lista[i].codigoGenero==codigoGenero)
        {
            printf("\t%s",lista[i].descripcion);
        }
    }

}

void ListarTodosLosLibrosDeAutoresArgentinosSegunEditorial(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG)
{
    int i;
    int opcion;
    int j;
    
    MostrarListaDeEditoriales(listaEditoriales,tamEdit);
    opcion=PedirEnteroConRango(1000,1004,"Ingrese la editorial a mostrar: ");
    printf("\nIdLibro  Titulo \tFecha(d/m/a)  \tImporte    Autor  \tEditorial  \tGenero\n");
    for(i=0; i<tam;i++)
    {
        for(j=0;j<tamA;j++)
        {
            if(lista[i].codigoEditorial==opcion&&lista[i].estado==OCUPADO&&listaAutores[j].codigoPais==100)//un solo if
            {
                MostarUnLibro(lista[i],listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
                break;
                
            }
        }
        
    }
}

int Listar(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP,int opcion)
{
    int state = 1;
    if(opcion>0&&opcion<5&&lista!=NULL&&listaAutores!=NULL&&listaEditoriales!=NULL&&listaGeneros!=NULL&&listaPaises!=NULL)
    {
        state = 0;
        switch(opcion)
        {
            case 1:
                MostrarListaDeEditoriales(listaEditoriales,tamEdit);
            break;
            case 2:
                MostrarListaDePaises(listaPaises,tamP);
            break;
            case 3:
                MostrarListaDeAutores(listaAutores,tamA,listaPaises,tamP);
            break;
            case 4:
                MostrarListaDeLibros(lista,tam,listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
            break;
            case 5:
                ListarTodosLosLibrosDeAutoresArgentinosSegunEditorial(lista,tam,listaAutores,tamA,listaEditoriales,tamEdit,listaGeneros,tamG);
            break;
        }
        
    }
    return state;
    
}

void Controller_Listar(eLibro listaLibros[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP)
{
    int Opcion;
    printf("\nLISTAR:");
    printf("\n1.Todas las editoriales");
    printf("\n2.Todos los paises");
    printf("\n3.Todos los autores");
    printf("\n4.Todos los libros");
    printf("\n5.Todos los libros ordenados por importe y titulo");
    printf("\nPrecione cualquier otro numero para cancelar");
    scanf("%d",&Opcion);
    switch(Opcion)
    {
        case 1:
            if(Listar(listaLibros,tam,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5,1)!=0)
            {
                printf("Hubo un error al mostrar");
            }
        break;
        case 2:
            if(Listar(listaLibros,tam,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5,2)!=0)
            {
                printf("Hubo un error al mostrar");
            }
        break;
        case 3:
            if(Listar(listaLibros,tam,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5,3)!=0)
            {
                printf("Hubo un error al mostrar");
            }
        break;
        case 4:
            if(Listar(listaLibros,tam,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5,4)!=0)
            {
                printf("Hubo un error al mostrar");
            }
        break;
        case 5:
            OrdenarLibrosPorImporteYTitulo(listaLibros,tam);
            if(Listar(listaLibros,tam,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5,4)!=0)
            {
                printf("Hubo un error al mostrar");
            }
        break;
        default:
        printf("\nSalio de mostrar...\n");
        break;
    }
    
}

void Controller_Modificar(eLibro listaLibros[], int TAML,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP)
{
    int Opcion;
    
    printf("\nMODOFICAR:\n");
    printf("\n1.Titulo");
    printf("\n2.Fecha de publicacion");
    printf("\n3.Importe");
    printf("\n4.Autor");
    printf("\n5.Editorial");
    printf("\n6.Genero");
    printf("\nPrecione cualquier otro numero para cancelar ");
    scanf("%d",&Opcion);
    MostrarListaDeLibros(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
    switch(Opcion)
    {
        case 1:
        ModificarLibro(listaLibros,TAML,1);// esto deberia haber sido un solo switch
        break;
        case 2:
        ModificarLibro(listaLibros,TAML,2);
        break;
        case 3:
        ModificarLibro(listaLibros,TAML,3);
        break;
        case 4:
        MostrarListaDeAutores(listaAutores, 10, listaPaises, 5);
        ModificarLibro(listaLibros,TAML,4);
        break;
        case 5:
        MostrarListaDeEditoriales(listaEditoriales, 5);
        ModificarLibro(listaLibros,TAML,5);
        break;
        case 6:
        MostrarListaDeGeneros(listaGeneros, 5);
        ModificarLibro(listaLibros,TAML,6);
        break;
        default:
        printf("\nSe cancelo la modificacion...\n");
        break;
    }
}

void Controller_Menu(int TAML)
{
    int opcion;
    int codigoL=10;
    int variableControl=0;
    
    eEditorial listaEditoriales[5];
    ePais listaPaises[5];
    eAutor listaAutores[10];
    eGenero listaGeneros[5];
    eLibro listaLibros[TAML];
    
    HarcodearEditoriales(listaEditoriales);
    HarcodearPaises(listaPaises);
    HarcodearAutores(listaAutores);
    HarcodearGeneros(listaGeneros);
    InicializarLibros(listaLibros, TAML);// esto iria harcodeado en main
    
    do
    {
        printf("\n1.Alta");
        printf("\n2.Modificar");
        printf("\n3.Baja");
        printf("\n4.Informar");
        printf("\n5.Listar");
        printf("\n6.Segunda Parte");
        printf("\n7.Salir");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        
        switch(opcion)
        {
            case 1:
            AltaLibro(listaLibros,TAML,&codigoL,listaAutores,10,listaEditoriales,5,listaPaises,5,listaGeneros,5);
            variableControl=1;
            break;
            case 2:
            if(variableControl==1)
            {
               Controller_Modificar(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5);
            }else
            {
                printf("\nPrimero se debe ingresar al menos un libro\n");
            }
            break;
            case 3:
            if(variableControl==1)
            {
                MostrarListaDeLibros(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
                BajaLibro(listaLibros,TAML,listaAutores,10,listaEditoriales,5);
            }else
            {
                printf("\nPrimero se debe ingresar al menos un libro\n");
            }
            break;
            case 4:
            if(variableControl==1)
            {
                MostrarTotalImportesYPromedio(listaLibros,TAML);
                MostrarLibrosConImportesSuperioresAlPromedio(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
                MostrarLibrosFechaAnteriorAl2000(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
                break;
            }else
            {
                printf("\nPrimero se debe ingresar al menos un libro\n");
            }
            break;
            case 5:
            if(variableControl==1)
            {
                Controller_Listar(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5,listaPaises, 5);
            }else
            {
                printf("\nPrimero se debe ingresar al menos un libro\n");
            }
            break;
            case 6:
            printf("\n SEGUNDA PARTE \n");
            MostrarListaDeGeneros(listaGeneros, 5);
            MostrarLibrosConGenerosDistintosANovela(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
            ListarTodosLosLibrosDeAutoresArgentinosSegunEditorial(listaLibros,TAML,listaAutores,10,listaEditoriales,5,listaGeneros,5);
            break;
            case 7:
            printf("\nSalio del programa...\n");
            break;
            default: 
            printf("\nOpcion invalida\n");
            break;
        }
        
    }while(opcion!=7);
}
