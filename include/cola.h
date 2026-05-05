#ifndef COLA_H
#define COLA_H
#include "estructuras.h"

void inicializarCola(NodoCola*& frente, NodoCola*& final);
void encolar(NodoCola*& frente, NodoCola*& final, Cancion* c);
Cancion* desencolar(NodoCola*& frente, NodoCola*& final);
void insertarAlFrente(NodoCola*& frente, NodoCola*& final, Cancion* c);
bool colaVacia(NodoCola* frente);
void vaciarCola(NodoCola*& frente, NodoCola*& final);
void mostrarCola(NodoCola* frente);

#endif