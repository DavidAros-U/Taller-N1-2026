#include <iostream>
#include "../include/cola.h"

using namespace std;

void inicializarCola(NodoCola*& frente, NodoCola*& final) {
    frente = NULL;
    final = NULL;
}

void encolar(NodoCola*& frente, NodoCola*& final, Cancion* c) {
    NodoCola* nuevo = new NodoCola;
    nuevo->data = c;
    nuevo->next = NULL;

    if (final == NULL) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->next = nuevo;
        final = nuevo;
    }
}

Cancion* desencolar(NodoCola*& frente, NodoCola*& final) {
    if (frente == NULL) return NULL;

    NodoCola* temp = frente;
    Cancion* c = temp->data;
    frente = frente->next;

    if (frente == NULL) {
        final = NULL;
    }

    delete temp;
    return c;
}

void insertarAlFrente(NodoCola*& frente, NodoCola*& final, Cancion* c) {
    NodoCola* nuevo = new NodoCola;
    nuevo->data = c;
    nuevo->next = frente;
    frente = nuevo;

    if (final == NULL) {
        final = nuevo;
    }
}

bool colaVacia(NodoCola* frente) {
    return frente == NULL;
}

void vaciarCola(NodoCola*& frente, NodoCola*& final) {
    while (frente != NULL) {
        NodoCola* temp = frente;
        frente = frente->next;
        delete temp;
    }
    final = NULL;
}

void mostrarCola(NodoCola* frente) {
    if (frente == NULL) {
        cout << "Cola vacia.\n";
        return;
    }

    NodoCola* aux = frente;
    int i = 1;

    while (aux != NULL) {
        cout << i << ". "
             << aux->data->nombre << " - "
             << aux->data->artista << endl;
        aux = aux->next;
        i++;
    }
}

void eliminarDeColaPorID(NodoCola*& frente, NodoCola*& final, int id) {
    NodoCola* actual = frente;
    NodoCola* anterior = NULL;

    while (actual != NULL) {
        if (actual->data != NULL && actual->data->id == id) {
            NodoCola* eliminar = actual;

            if (anterior == NULL) {
                frente = actual->next;
                actual = frente;
            } else {
                anterior->next = actual->next;
                actual = anterior->next;
            }

            if (eliminar == final) {
                final = anterior;
            }

            delete eliminar;
        } else {
            anterior = actual;
            actual = actual->next;
        }
    }

    if (frente == NULL) {
        final = NULL;
    }
}