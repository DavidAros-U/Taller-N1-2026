#include <iostream>
#include "../include/reproductor.h"
#include "../include/cola.h"
#include "../include/pila.h"
#include "../include/consola.h"
#include <cstdlib>
#include <ctime>
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
    if (r.listaCanciones == NULL) return;

    if (r.modoRepeat == 1 && r.actual != NULL) {
        r.estado = 1;
        cout << "Reproduciendo: " << r.actual->nombre << " - " << r.actual->artista << endl;
        return;
    }

    if (r.frente == NULL) {
        if (r.modoRepeat == 2) {
            reconstruirCola(r);
        } else if (r.actual == NULL) {
            reconstruirCola(r);
        } else {
            r.estado = 0;
            cout << "No hay más canciones.\n";
            return;
        }
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
        mezclarCola(r);
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

void mezclarCola(Reproductor& r) {

    if (r.frente == NULL) return;
    int n = 0;
    NodoCola* aux = r.frente;

    while (aux != NULL) {
        n++;
        aux = aux->next;
    }
    Cancion** arr = new Cancion*[n];

    aux = r.frente;
    for (int i = 0; i < n; i++) {
        arr[i] = aux->data;
        aux = aux->next;
    }
    srand(time(NULL));

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Cancion* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    vaciarCola(r.frente, r.final);

    for (int i = 0; i < n; i++) {
        encolar(r.frente, r.final, arr[i]);
    }

    delete[] arr;
}

void reconstruirCola(Reproductor& r) {
    vaciarCola(r.frente, r.final);
    NodoLista* aux = r.listaCanciones;

    while (aux != NULL) {
        if (r.actual == NULL || aux->data.id != r.actual->id) {
            encolar(r.frente, r.final, &(aux->data));
        }
        aux = aux->next;
    }

    if (r.modoRandom) {
        mezclarCola(r);
    }
}

void mostrarMenu(Reproductor& r) {

    cout << "\n";

    if (r.actual != NULL) {

        cout << (r.estado == 1 ? "Reproduciendo" :
                 r.estado == 2 ? "En pausa" :
                 "Detenido");

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
        cout << "Artista: " << r.actual->artista << endl;
        cout << "Album: " << r.actual->album
             << " [" << r.actual->anio << "]" << endl;

    } else {

        cout << "Reproduccion detenida\n";
    }

    cout << "\nOpciones:\n";
    cout << "W - Reproducir/Pausar\n";
    cout << "Q - Pista Anterior\n";
    cout << "E - Pista Siguiente\n";
    cout << "S - Activar/Desactivar modo aleatorio\n";
    cout << "R - Cambiar repeticion\n";
    cout << "A - Ver lista de reproduccion actual\n";
    cout << "L - Listado de canciones\n";
    cout << "X - Salir\n";

    cout << "\nIngrese opcion: ";
}

void saltarCancion(Reproductor& r, int posicion) {

    if (r.frente == NULL || posicion <= 0) {
        return;
    }

    NodoCola* actualNodo = r.frente;
    NodoCola* anterior = NULL;

    int contador = 1;

    while (actualNodo != NULL && contador < posicion) {

        NodoCola* temp = actualNodo;

        actualNodo = actualNodo->next;

        delete temp;

        contador++;
    }

    if (actualNodo == NULL) {
        return;
    }

    if (r.actual != NULL) {
        push(r.tope, r.actual);
    }

    r.frente = actualNodo->next;

    if (r.frente == NULL) {
        r.final = NULL;
    }

    r.actual = actualNodo->data;

    delete actualNodo;

    r.estado = 1;

    cout << "Reproduciendo: "
         << r.actual->nombre
         << " - "
         << r.actual->artista
         << endl;
}

void submenuPlaylist(Reproductor& r) {

    char opcion;

    do {

        limpiarPantalla();

        if (r.actual != NULL) {

            cout << "Actual: "
                 << r.actual->nombre
                 << " - "
                 << r.actual->artista
                 << endl;

        } else {

            cout << "Actual: Ninguna\n";
        }

        cout << "\nLista de reproduccion actual:\n";

        if (r.frente == NULL) {

            cout << "Vacia\n";

        } else {

            mostrarCola(r.frente);
        }

        cout << "\nOpciones:\n";

        if (r.frente != NULL) {
            cout << "S<num> - Saltar a cancion\n";
        }

        cout << "V - Volver\n";

        cout << "\nIngrese opcion: ";

        string entrada;
        getline(cin, entrada);

        if (entrada.length() == 0) {
            continue;
        }

        opcion = toupper(entrada[0]);

        if (opcion == 'S' && entrada.length() > 1) {

            int posicion = stoi(entrada.substr(1));

            saltarCancion(r, posicion);

            pausarPantalla();

            return;
        }

    } while(opcion != 'V');
}