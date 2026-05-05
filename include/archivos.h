#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "estructuras.h"

void cargarCanciones(NodoLista*& lista, const char* nombreArchivo);
void guardarCanciones(NodoLista* lista, const char* nombreArchivo);

#endif