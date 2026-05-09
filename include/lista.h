#ifndef LISTA_H
#define LISTA_H
#include "estructuras.h"

void inicializarLista(NodoLista*& lista);
NodoLista* crearNodo(Cancion c);
void insertarCancion(NodoLista*& lista, Cancion c);
void mostrarCanciones(NodoLista* lista);
Cancion* buscarCancionPorID(NodoLista* lista, int id);
bool eliminarCancion(NodoLista*& lista, int id);
Cancion* buscarCancionPorPosicion(NodoLista* lista, int posicion);

#endif