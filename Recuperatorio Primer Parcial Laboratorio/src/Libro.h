#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

typedef struct
{
    int codigoEditorial;
    char descripcion[51];
}eEditorial;

typedef struct
{
    int codigoPais;
    char descripcion[51];
}ePais;

typedef struct
{
    int codigoAutor;
    char nombre[51];
    int codigoPais;
}eAutor;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoGenero;
    char descripcion[51];;
}eGenero;


typedef struct
{
    int codigoLibro;
    char titulo[51];
    eFecha fechaPublicacion;
    int importe;
    int codigoAutor;
    int codigoEditorial;
    int codigoGenero;
    int estado;
}eLibro;


int HarcodearEditoriales(eEditorial lista[]);
void MostarUnaEditorial(eEditorial lista);
void MostrarListaDeEditoriales(eEditorial lista[], int tam);
int HarcodearPaises(ePais lista[]);
void MostrarUnPais(ePais lista);
void MostrarPaisSegunCodigo(ePais lista[], int tam, int codigoPais);
void MostrarListaDePaises(ePais lista[], int tam);
int HarcodearAutores(eAutor lista[]);
void MostrarUnAutor(eAutor lista,ePais listaPaises[], int tamP);
void MostrarListaDeAutores(eAutor lista[], int tam,ePais listaPaises[], int tamP);
void InicializarLibros(eLibro lista[], int tam);
int BuscarLibre(eLibro lista[],int tam);
int AltaLibro(eLibro lista[],int tam,int* pId, eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,ePais listaPaises[], int tamP,eGenero listaGeneros[], int tamG);
void MostarUnLibro(eLibro lista,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[],int tamEdit,eGenero listaGeneros[],int tamG);
void MostrarAutorSegunCodigo(eAutor lista[], int tam, int codigoAutor);
void MostrarEditorialSegunCodigo(eEditorial lista[], int tam, int codigoEditorial);
void MostrarListaDeLibros(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[],int tamG);
void BajaLibro(eLibro listado[], int tam, eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit);
void OrdenarLibrosPorImporteYTitulo(eLibro listado[], int tam);
void ModificarLibro(eLibro listado[], int tam,int parametroAModificar);
//Modifica el parametro ingresado, le pide el codigoLibro al usuario despues de mostrarlo 
//parametroa modificar 1 titulo 2 fecha 3 importe 4 autor 5 editorial 6 genero
int CalcularTotal(eLibro listado[],int tam);
float CalcularPromedio(eLibro listado[],int tam);
void MostrarTotalImportesYPromedio(eLibro listado[],int tam);
void MostrarLibrosConImportesSuperioresAlPromedio(eLibro listado[],int tam,eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG);
void MostrarLibrosFechaAnteriorAl2000(eLibro listado[],int tam,eAutor listaAutores[], int tamA, eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG);
//PARTE 2
int HarcodearGeneros(eGenero lista[]);
//carga 5 generos para usar le programa
void MostrarUnGenero(eGenero lista);
//muestra una estructura genero
void MostrarListaDeGeneros(eGenero lista[], int tam);
//muestra todos los generos cargados
void MostrarLibrosConGenerosDistintosANovela(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG);
//Muestras todos los libros con genero distinto a "Novela"
void MostrarGeneroSegunCodigo(eGenero lista[], int tam, int codigoGenero);
//Se usa para que en mostrar libro se vea el la "descripcion" de genero y no el "codigo genero"
void ListarTodosLosLibrosDeAutoresArgentinosSegunEditorial(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG);
//Muestra todos los libros de autores argentino de la editorial ingresada por el usuario

int Listar(eLibro lista[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP, int opcion);
//llama a los "listar" segun que numero le pases: 1 editoriales 2 paises 3 auteroes 4 libros 5 libros Arg segun editorial
//devuelve 0 si salio todo bien 1 si fallo algo
void Controller_Listar(eLibro listaLibros[], int tam,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP);

void Controller_Modificar(eLibro listaLibros[], int TAML,eAutor listaAutores[],int tamA,eEditorial listaEditoriales[], int tamEdit,eGenero listaGeneros[], int tamG,ePais listaPaises[],int tamP);

void Controller_Menu(int TAML);
#endif /* FUNCIONES_H_ */
