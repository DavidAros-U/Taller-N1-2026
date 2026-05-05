#include <iostream>
#include "../include/reproductor.h"
#include "../include/archivos.h"

using namespace std;

int main() {

    Reproductor r;
    inicializarReproductor(r);
    cargarCanciones(r.listaCanciones, "data/music_source.txt");
    cargarColaInicial(r);

    cout << "\n>>> Primera canción\n";
    siguiente(r);

    cout << "\n>>> Siguiente (E)\n";
    siguiente(r);

    cout << "\n>>> Anterior (Q)\n";
    anterior(r);

    return 0;
}