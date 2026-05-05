#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/archivos.h"
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