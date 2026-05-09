#include <iostream>
#include <limits>
#include <cstdlib>
#include "../include/consola.h"
using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarPantalla() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

char leerOpcion() {
    string entrada;
    getline(cin, entrada);

    if (entrada.length() == 0) {
        return '\0';
    }

    return toupper(entrada[0]);
}

int leerEntero(string mensaje) {
    string entrada;
    int numero;
    bool valido = false;

    while (!valido) {
        cout << mensaje;
        getline(cin, entrada);

        try {
            size_t pos;
            numero = stoi(entrada, &pos);

            if (pos == entrada.length()) {
                valido = true;
            } else {
                cout << "Entrada invalida. Intente nuevamente.\n";
            }
        } catch (...) {
            cout << "Entrada invalida. Intente nuevamente.\n";
        }
    }

    return numero;
}