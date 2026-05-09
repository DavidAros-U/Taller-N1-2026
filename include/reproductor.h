#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include "estructuras.h"

void inicializarReproductor(Reproductor& r);
void cargarColaInicial(Reproductor& r);
void reconstruirCola(Reproductor& r);
void siguiente(Reproductor& r);
void anterior(Reproductor& r);
void mostrarMenu(Reproductor& r);
void reproducirPausar(Reproductor& r);
void cambiarModoRandom(Reproductor& r);
void cambiarModoRepeat(Reproductor& r);
void mostrarEstado(Reproductor& r);
void mezclarCola(Reproductor& r);
void submenuPlaylist(Reproductor& r);
void saltarCancion(Reproductor& r, int posicion);
void submenuCanciones(Reproductor& r);
void reproducirCancion(Reproductor& r, int posicion);
void agregarCancionACola(Reproductor& r, int posicion);
void agregarNuevaCancion(Reproductor& r);
void eliminarCancionReproductor(Reproductor& r, int posicion);
#endif