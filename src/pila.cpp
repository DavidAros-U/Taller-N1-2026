#include <iostream>
#include "../include/pila.h"

using namespace std;

void inicializarPila(NodoPila*& tope) {
    tope = NULL;
}

void push(NodoPila*& tope, Cancion* c) {
    NodoPila* nuevo = new NodoPila;
    nuevo->data = c;
    nuevo->next = tope;
    tope = nuevo;
}

Cancion* pop(NodoPila*& tope) {
    if (tope == NULL) return NULL;
    NodoPila* temp = tope;
    Cancion* c = temp->data;
    tope = tope->next;
    delete temp;

    return c;
}

bool pilaVacia(NodoPila* tope) {
    return tope == NULL;
}

void vaciarPila(NodoPila*& tope) {
    while (tope != NULL) {
        NodoPila* temp = tope;
        tope = tope->next;
        delete temp;
    }
}