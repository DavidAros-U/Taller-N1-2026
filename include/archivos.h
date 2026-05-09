#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "estructuras.h"

void cargarCanciones(NodoLista*& lista, const char* nombreArchivo);
void guardarCanciones(NodoLista* lista, const char* nombreArchivo);
void guardarEstado(Reproductor& r, const char* nombreArchivo);
void cargarEstado(Reproductor& r, const char* nombreArchivo);

#endif