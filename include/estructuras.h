#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

struct Cancion {
    int id;
    string nombre;
    string artista;
    string album;
    int anio;
    int duracion;
    string ruta;
};

struct NodoLista {
    Cancion data;
    NodoLista* next;
};

struct NodoCola {
    Cancion* data;
    NodoCola* next;
};

struct NodoPila {
    Cancion* data;
    NodoPila* next;
};

struct Reproductor {
    NodoLista* listaCanciones;
    NodoCola* frente;
    NodoCola* final;
    NodoPila* tope;
    Cancion* actual;

    bool modoRandom;
    int modoRepeat;
    int estado;
    int contadorIDs;
};

#endif