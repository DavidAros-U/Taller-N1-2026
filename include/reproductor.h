#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include "estructuras.h"

void inicializarReproductor(Reproductor& r);
void cargarColaInicial(Reproductor& r);
void siguiente(Reproductor& r);
void anterior(Reproductor& r);
void mezclarCola(Reproductor& r);
void reproducirPausar(Reproductor& r);
void cambiarModoRandom(Reproductor& r);
void cambiarModoRepeat(Reproductor& r);
void mostrarEstado(Reproductor& r);

#endif