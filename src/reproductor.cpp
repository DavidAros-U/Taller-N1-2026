#include <iostream>
#include "../include/reproductor.h"
#include "../include/cola.h"
#include "../include/pila.h"

using namespace std;

void inicializarReproductor(Reproductor& r) {
    r.listaCanciones = NULL;
    r.frente = NULL;
    r.final = NULL;
    r.tope = NULL;
    r.actual = NULL;
}

void cargarColaInicial(Reproductor& r) {
    NodoLista* aux = r.listaCanciones;

    while (aux != NULL) {
        encolar(r.frente, r.final, &(aux->data));
        aux = aux->next;
    }
}

void siguiente(Reproductor& r) {

    if (r.actual != NULL) {
        push(r.tope, r.actual);
    }
    r.actual = desencolar(r.frente, r.final);

    if (r.actual != NULL) {
        cout << "Reproduciendo: "
             << r.actual->nombre << " - "
             << r.actual->artista << endl;
    } else {
        cout << "No hay más canciones.\n";
    }
}

void anterior(Reproductor& r) {

    if (pilaVacia(r.tope)) {
        cout << "No hay historial.\n";
        return;
    }

    if (r.actual != NULL) {
        insertarAlFrente(r.frente, r.final, r.actual);
    }

    r.actual = pop(r.tope);
    cout << "Reproduciendo: "
         << r.actual->nombre << " - "
         << r.actual->artista << endl;
}