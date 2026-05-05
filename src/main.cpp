#include <iostream>
#include "../include/reproductor.h"
#include "../include/archivos.h"

using namespace std;

int main() {

    Reproductor r;
    inicializarReproductor(r);

    cargarCanciones(r.listaCanciones, "data/music_source.txt");
    cargarColaInicial(r);

    siguiente(r);
    mostrarEstado(r);

    reproducirPausar(r);
    mostrarEstado(r);

    reproducirPausar(r);
    mostrarEstado(r);

    cambiarModoRandom(r);
    cambiarModoRepeat(r);
    mostrarEstado(r);

    siguiente(r);
    anterior(r);

    return 0;
}