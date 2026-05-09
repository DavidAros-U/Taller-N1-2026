#ifndef PILA_H
#define PILA_H
#include "estructuras.h"

void inicializarPila(NodoPila*& tope);
void push(NodoPila*& tope, Cancion* c);
Cancion* pop(NodoPila*& tope);
bool pilaVacia(NodoPila* tope);
void vaciarPila(NodoPila*& tope);
void eliminarDePilaPorID(NodoPila*& tope, int id);

#endif