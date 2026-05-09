# Radio Pirata

## Integrante

- David Aros Urquieta

---

## Descripción

Radio Pirata es una aplicación de consola desarrollada en C++ que simula el funcionamiento de un reproductor de música. El sistema permite administrar canciones, listas de reproducción e historial utilizando estructuras de datos.

---

# Diagrama de Clases

```text
+------------------+
|     Cancion      |
+------------------+
| id               |
| nombre           |
| artista          |
| album            |
| anio             |
| duracion         |
| ruta             |
+------------------+

          ▲
          |
+------------------+
|    NodoLista     |
+------------------+
| data : Cancion   |
| next             |
+------------------+

          ▲
          |
+------------------+
|    NodoCola      |
+------------------+
| data : Cancion*  |
| next             |
+------------------+

          ▲
          |
+------------------+
|    NodoPila      |
+------------------+
| data : Cancion*  |
| next             |
+------------------+

+-----------------------------------+
|           Reproductor            |
+-----------------------------------+
| listaCanciones : NodoLista*      |
| frente : NodoCola*               |
| final : NodoCola*                |
| tope : NodoPila*                 |
| actual : Cancion*                |
| modoRandom : bool                |
| modoRepeat : int                 |
| estado : int                     |
| contadorIDs : int                |
+-----------------------------------+

+-----------------------------------+
|         lista.cpp / .h           |
+-----------------------------------+
| insertarCancion()                |
| eliminarCancion()                |
| mostrarCanciones()               |
| buscarCancionPorID()             |
| buscarCancionPorPosicion()       |
+-----------------------------------+

+-----------------------------------+
|          cola.cpp / .h           |
+-----------------------------------+
| encolar()                        |
| desencolar()                     |
| insertarAlFrente()               |
| vaciarCola()                     |
| eliminarDeColaPorID()            |
| mostrarCola()                    |
+-----------------------------------+

+-----------------------------------+
|          pila.cpp / .h           |
+-----------------------------------+
| push()                           |
| pop()                            |
| vaciarPila()                     |
| eliminarDePilaPorID()            |
+-----------------------------------+

+-----------------------------------+
|       reproductor.cpp / .h       |
+-----------------------------------+
| siguiente()                      |
| anterior()                       |
| reproducirPausar()               |
| cambiarModoRandom()              |
| cambiarModoRepeat()              |
| mezclarCola()                    |
| reconstruirCola()                |
| submenuPlaylist()                |
| submenuCanciones()               |
| agregarNuevaCancion()            |
| eliminarCancionReproductor()     |
+-----------------------------------+

+-----------------------------------+
|         archivos.cpp / .h        |
+-----------------------------------+
| cargarCanciones()                |
| guardarCanciones()               |
| cargarEstado()                   |
| guardarEstado()                  |
+-----------------------------------+

+-----------------------------------+
|         consola.cpp / .h         |
+-----------------------------------+
| limpiarPantalla()                |
| pausarPantalla()                 |
| leerOpcion()                     |
| leerEntero()                     |
+-----------------------------------+
```

---

# Estructura del Proyecto

```text
RadioPirata/
│
├── data/
│   ├── music_source.txt
│   ├── status.cfg
│
├── include/
│   ├── archivos.h
│   ├── cola.h
│   ├── consola.h
│   ├── estructuras.h
│   ├── lista.h
│   ├── pila.h
│   ├── reproductor.h
│
├── src/
│   ├── archivos.cpp
│   ├── cola.cpp
│   ├── consola.cpp
│   ├── lista.cpp
│   ├── main.cpp
│   ├── pila.cpp
│   ├── reproductor.cpp
│
└── README.md
```

---

# Funcionamiento de la Aplicación

La aplicación carga canciones desde el archivo `music_source.txt` y restaura el estado anterior utilizando `status.cfg`.

El menú principal permite:

- Reproducir o pausar canciones
- Avanzar a la siguiente pista
- Retroceder a la pista anterior
- Activar o desactivar el modo aleatorio
- Cambiar el modo de repetición
- Visualizar la lista de reproducción actual
- Visualizar y administrar canciones registradas
- Agregar canciones al sistema
- Eliminar canciones
- Guardar automáticamente el estado del reproductor

---

# Compilación

Para compilar el proyecto utilizando g++ en PowerShell:

```bash
g++ src\main.cpp src\lista.cpp src\cola.cpp src\pila.cpp src\reproductor.cpp src\archivos.cpp src\consola.cpp -Iinclude -o reproductor
```

---

# Ejecución

Ejecutar el programa con:

```bash
.\reproductor.exe
```

---
