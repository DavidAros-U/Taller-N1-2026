#include <iostream>
#include "../include/lista.h"
#include "../include/cola.h"
#include "../include/archivos.h"

using namespace std;

int main() {

    // =========================
    // 🔹 LISTA DE CANCIONES
    // =========================
    NodoLista* lista;
    inicializarLista(lista);

    cargarCanciones(lista, "data/music_source.txt");

    cout << "=============================\n";
    cout << "CANCIONES CARGADAS:\n";
    cout << "=============================\n";
    mostrarCanciones(lista);

    // =========================
    // 🔹 COLA DE REPRODUCCIÓN
    // =========================
    NodoCola* frente;
    NodoCola* final;

    inicializarCola(frente, final);

    // Buscar algunas canciones
    Cancion* c1 = buscarCancionPorID(lista, 1);
    Cancion* c2 = buscarCancionPorID(lista, 2);
    Cancion* c3 = buscarCancionPorID(lista, 3);

    // Encolar
    encolar(frente, final, c1);
    encolar(frente, final, c2);
    encolar(frente, final, c3);

    cout << "\n=============================\n";
    cout << "COLA INICIAL:\n";
    cout << "=============================\n";
    mostrarCola(frente);

    // =========================
    // 🔹 SIMULAR SIGUIENTE (E)
    // =========================
    Cancion* actual = desencolar(frente, final);

    cout << "\n=============================\n";
    cout << "REPRODUCIENDO:\n";
    cout << "=============================\n";

    if (actual != NULL) {
        cout << actual->nombre << " - " << actual->artista << endl;
    } else {
        cout << "No hay canciones.\n";
    }

    cout << "\nCOLA DESPUES DE 'E':\n";
    mostrarCola(frente);

    // =========================
    // 🔹 INSERTAR AL FRENTE (simulación Q futura)
    // =========================
    cout << "\n=============================\n";
    cout << "INSERTANDO ACTUAL AL FRENTE (simulando Q)\n";
    cout << "=============================\n";

    if (actual != NULL) {
        insertarAlFrente(frente, final, actual);
    }

    cout << "\nCOLA DESPUES DE INSERTAR AL FRENTE:\n";
    mostrarCola(frente);

    // =========================
    // 🔹 VACIAR COLA
    // =========================
    cout << "\n=============================\n";
    cout << "VACIANDO COLA...\n";
    cout << "=============================\n";

    vaciarCola(frente, final);

    cout << "\nCOLA FINAL:\n";
    mostrarCola(frente);

    return 0;
}