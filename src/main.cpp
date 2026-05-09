#include <iostream>
#include "../include/reproductor.h"
#include "../include/archivos.h"
#include "../include/consola.h"

using namespace std;

int main() {

    Reproductor r;
    inicializarReproductor(r);

    cargarCanciones(r.listaCanciones, "data/music_source.txt");
    cargarColaInicial(r);

    char opcion;

    do {
        limpiarPantalla();
        mostrarMenu(r);

        opcion = leerOpcion();

        limpiarPantalla();

        switch(opcion) {

            case 'W':
                reproducirPausar(r);
                break;

            case 'Q':
                anterior(r);
                break;

            case 'E':
                siguiente(r);
                break;

            case 'S':
                cambiarModoRandom(r);
                break;

            case 'R':
                cambiarModoRepeat(r);
                break;

            case 'A':
                submenuPlaylist(r);
                break;

            case 'L':
                cout << "Submenu listado de canciones pendiente.\n";
                break;

            case 'X':
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

        if (opcion != 'X') {
            pausarPantalla();
        }

    } while(opcion != 'X');

    return 0;
}