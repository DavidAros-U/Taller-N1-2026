#include <iostream>
#include "../include/lista.h"
using namespace std;

void inicializarLista(NodoLista*& lista) {
    lista = NULL;
}

NodoLista* crearNodo(Cancion c) {
    NodoLista* nuevo = new NodoLista;
    nuevo->data = c;
    nuevo->next = NULL;
    return nuevo;
}

void insertarCancion(NodoLista*& lista, Cancion c) {
    NodoLista* nuevo = crearNodo(c);

    if (lista == NULL) {
        lista = nuevo;
        return;
    }

    NodoLista* aux = lista;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = nuevo;
}

void mostrarCanciones(NodoLista* lista) {
    if (lista == NULL) {
        cout << "No hay canciones registradas.\n";
        return;
    }
    NodoLista* aux = lista;
    int i = 1;

    while (aux != NULL) {
        cout << i << ". "
             << aux->data.nombre << " - "
             << aux->data.artista << endl;
        aux = aux->next;
        i++;
    }
}

Cancion* buscarCancionPorID(NodoLista* lista, int id) {
    NodoLista* aux = lista;

    while (aux != NULL) {
        if (aux->data.id == id) {
            return &(aux->data);
        }
        aux = aux->next;
    }

    return NULL;
}

bool eliminarCancion(NodoLista*& lista, int id) {
    if (lista == NULL) return false;

    NodoLista* actual = lista;
    NodoLista* anterior = NULL;

    while (actual != NULL) {
        if (actual->data.id == id) {
            if (anterior == NULL) {
                lista = actual->next;
            } else {
                anterior->next = actual->next;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->next;
    }
    return false;
}