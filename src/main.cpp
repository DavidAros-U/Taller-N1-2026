#include <iostream>
#include "../include/reproductor.h"
#include "../include/archivos.h"
#include "../include/cola.h"

using namespace std;

int main() {

    Reproductor r;
    inicializarReproductor(r);

    cargarCanciones(r.listaCanciones, "data/music_source.txt");
    cargarColaInicial(r);

    cout << "\nCOLA ORIGINAL:\n";
    mostrarCola(r.frente);

    siguiente(r);
    mostrarEstado(r);

    cout << "\n>>> Activando RANDOM\n";
    cambiarModoRandom(r);

    cout << "\nCOLA MEZCLADA:\n";
    mostrarCola(r.frente);

    cout << "\n>>> Siguiente (E)\n";
    siguiente(r);

    cout << "\n>>> Anterior (Q)\n";
    anterior(r);

    return 0;
}