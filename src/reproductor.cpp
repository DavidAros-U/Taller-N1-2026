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
    r.modoRandom = false;
    r.modoRepeat = 0;
    r.estado = 0;
    r.contadorIDs = 0;
}

void cargarColaInicial(Reproductor& r) {
    NodoLista* aux = r.listaCanciones;
    while (aux != NULL) {
        encolar(r.frente, r.final, &(aux->data));
        aux = aux->next;
    }
}

void siguiente(Reproductor& r) {
    if (r.modoRepeat == 1 && r.actual != NULL) {
        cout << "Reproduciendo: " << r.actual->nombre << " - " << r.actual->artista << endl;
        return;
    }

    if (r.actual != NULL) {
        push(r.tope, r.actual);
    }

    r.actual = desencolar(r.frente, r.final);

    if (r.actual != NULL) {
        r.estado = 1;
        cout << "Reproduciendo: " << r.actual->nombre << " - " << r.actual->artista << endl;
    } else {
        r.estado = 0;
        cout << "No hay más canciones.\n";
    }
}

void anterior(Reproductor& r) {
    if (pilaVacia(r.tope)) {
        cout << "No hay historial.\n";
        return;
    }

    if (r.modoRepeat == 1 && r.actual != NULL) {
        cout << "Reproduciendo: " << r.actual->nombre << " - " << r.actual->artista << endl;
        return;
    }

    if (r.actual != NULL) {
        insertarAlFrente(r.frente, r.final, r.actual);
    }
    r.actual = pop(r.tope);
    r.estado = 1;

    cout << "Reproduciendo: " << r.actual->nombre << " - " << r.actual->artista << endl;
}

void reproducirPausar(Reproductor& r) {
    if (r.actual == NULL) return;

    if (r.estado == 1) {
        r.estado = 2;
        cout << "En pausa\n";
    } else if (r.estado == 2) {
        r.estado = 1;
        cout << "Reproduciendo\n";
    }
}

void cambiarModoRandom(Reproductor& r) {
    r.modoRandom = !r.modoRandom;

    if (r.modoRandom) {
        cout << "Modo aleatorio activado\n";
    } else {
        cout << "Modo aleatorio desactivado\n";
    }
}

void cambiarModoRepeat(Reproductor& r) {
    r.modoRepeat = (r.modoRepeat + 1) % 3;

    if (r.modoRepeat == 0) {
        cout << "Repeticion desactivada\n";
    } else if (r.modoRepeat == 1) {
        cout << "Repetir una\n";
    } else {
        cout << "Repetir todas\n";
    }
}

void mostrarEstado(Reproductor& r) {
    if (r.actual == NULL) {
        cout << "Reproduccion detenida\n";
        return;
    }
    cout << (r.estado == 1 ? "Reproduciendo" : "En pausa");
    bool tieneModo = r.modoRandom || r.modoRepeat != 0;

    if (tieneModo) {
        cout << " (";
        if (r.modoRandom) {
            cout << "S";
        }
        if (r.modoRepeat == 1) {
            if (r.modoRandom) cout << "-";
            cout << "R1";
        } else if (r.modoRepeat == 2) {
            if (r.modoRandom) cout << "-";
            cout << "RA";
        }
        cout << ")";
    }
    cout << ": " << r.actual->nombre << endl;
}