#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/archivos.h"
#include "../include/lista.h"
#include "../include/cola.h"
#include "../include/lista.h"

using namespace std;

void cargarCanciones(NodoLista*& lista, const char* nombreArchivo) {

    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    string linea;

    while (getline(archivo, linea)) {

        if (linea.empty()) continue;
        stringstream ss(linea);
        string token;
        Cancion c;
        getline(ss, token, ',');
        c.id = stoi(token);
        getline(ss, c.nombre, ',');
        getline(ss, c.artista, ',');
        getline(ss, c.album, ',');
        getline(ss, token, ',');
        c.anio = stoi(token);
        getline(ss, token, ',');
        c.duracion = stoi(token);
        getline(ss, c.ruta);
        insertarCancion(lista, c);
    }

    archivo.close();
}

void guardarCanciones(NodoLista* lista, const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para escritura.\n";
        return;
    }
    NodoLista* aux = lista;

    while (aux != NULL) {
        archivo << aux->data.id << ","
                << aux->data.nombre << ","
                << aux->data.artista << ","
                << aux->data.album << ","
                << aux->data.anio << ","
                << aux->data.duracion << ","
                << aux->data.ruta << "\n";
        aux = aux->next;
    }
    archivo.close();
}

void guardarEstado(Reproductor& r, const char* nombreArchivo) {

    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al guardar estado en: " << nombreArchivo << endl;
        return;
    }

    archivo << "CURRENT=";

    if (r.actual != NULL) {
        archivo << r.actual->id;
    } else {
        archivo << -1;
    }

    archivo << "\n";
    archivo << "STATE=" << r.estado << "\n";
    archivo << "RANDOM=" << r.modoRandom << "\n";
    archivo << "REPEAT=" << r.modoRepeat << "\n";
    archivo << "COUNTER=" << r.contadorIDs << "\n";
    archivo << "QUEUE=";

    NodoCola* aux = r.frente;

    while (aux != NULL) {
        archivo << aux->data->id;

        if (aux->next != NULL) {
            archivo << ",";
        }

        aux = aux->next;
    }

    archivo << "\n";

    archivo.close();

    cout << "Estado guardado correctamente.\n";
}

void cargarEstado(Reproductor& r, const char* nombreArchivo) {

    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        return;
    }

    string linea;

    int currentID = -1;

    while (getline(archivo, linea)) {

        if (linea.find("CURRENT=") == 0) {

            currentID = stoi(linea.substr(8));
        }

        else if (linea.find("STATE=") == 0) {

            r.estado = stoi(linea.substr(6));
        }

        else if (linea.find("RANDOM=") == 0) {

            r.modoRandom = stoi(linea.substr(7));
        }

        else if (linea.find("REPEAT=") == 0) {

            r.modoRepeat = stoi(linea.substr(7));
        }

        else if (linea.find("COUNTER=") == 0) {

            r.contadorIDs = stoi(linea.substr(8));
        }

        else if (linea.find("QUEUE=") == 0) {

            string colaIDs = linea.substr(6);

            stringstream ss(colaIDs);

            string token;

            while (getline(ss, token, ',')) {

                if (token.empty()) continue;

                int id = stoi(token);

                Cancion* c = buscarCancionPorID(r.listaCanciones, id);

                if (c != NULL) {
                    encolar(r.frente, r.final, c);
                }
            }
        }
    }

    if (currentID != -1) {

        r.actual = buscarCancionPorID(r.listaCanciones, currentID);
    }

    archivo.close();
}