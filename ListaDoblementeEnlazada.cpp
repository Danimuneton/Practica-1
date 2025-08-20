#include "ListaDoblementeEnlazada.h"
#include <algorithm>   // Para usar std::sort en ordenamiento alfabético
#include <iostream>    // Entrada y salida estándar (opcional en este archivo)
using namespace std;

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
    cabeza = nullptr;   // No hay primer nodo
    cola = nullptr;     // No hay último nodo
    tamaño = 0;         // Contador de elementos en cero
}

/**
 * Destructor de la lista doblemente enlazada
 * Llama a limpiarLista() para liberar todos los nodos y evitar fugas de memoria.
 */
ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    limpiarLista();
}

void ListaDoblementeEnlazada::agregarHuesped(const string& nombre, int numeroHabitacion) {
    Nodo* nuevoNodo = new Nodo(nombre, numeroHabitacion); // Crear nodo en memoria dinámica

    if (estaVacia()) { // Caso: la lista está vacía
        cabeza = cola = nuevoNodo; // El nodo nuevo es tanto cabeza como cola
    } else { // Caso: la lista ya tiene elementos
        cola->siguiente = nuevoNodo;    // El último nodo apunta al nuevo
        nuevoNodo->anterior = cola;     // El nuevo apunta hacia atrás al que era la cola
        cola = nuevoNodo;               // Ahora el nuevo es la nueva cola
    }
    tamaño++; // Incrementamos el contador de elementos
}

bool ListaDoblementeEnlazada::eliminarHuesped(const string& nombre) {
    Nodo* nodo = buscarPorNombre(nombre); // Buscar nodo por nombre
    if (nodo == nullptr) { // No se encontró
        return false;
    }

    // Caso: único nodo en la lista
    if (nodo == cabeza && nodo == cola) {
        cabeza = cola = nullptr;
    }
    // Caso: primer nodo
    else if (nodo == cabeza) {
        cabeza = nodo->siguiente; // La cabeza avanza
        cabeza->anterior = nullptr; // El nuevo primero no tiene anterior
    }
    // Caso: último nodo
    else if (nodo == cola) {
        cola = nodo->anterior; // La cola retrocede
        cola->siguiente = nullptr; // El nuevo último no tiene siguiente
    }
    // Caso: nodo intermedio
    else {
        nodo->anterior->siguiente = nodo->siguiente; // Saltar el nodo hacia adelante
        nodo->siguiente->anterior = nodo->anterior; // Saltar el nodo hacia atrás
    }

    delete nodo; // Liberar la memoria del nodo eliminado
    tamaño--;    // Reducir el contador
    return true; // Eliminación exitosa
}

Nodo* ListaDoblementeEnlazada::buscarPorNombre(const string& nombre) {
    Nodo* actual = cabeza; // Comenzamos en la cabeza
    while (actual != nullptr) { // Recorremos mientras haya nodos
        if (actual->nombre == nombre) { // Coincidencia
            return actual;
        }
        actual = actual->siguiente; // Avanzamos al siguiente nodo
    }
    return nullptr; // No se encontró
}

Nodo* ListaDoblementeEnlazada::buscarPorHabitacion(int numeroHabitacion) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->numeroHabitacion == numeroHabitacion) {
            return actual; // Encontrado
        }
        actual = actual->siguiente; // Avanzamos
    }
    return nullptr; // No existe
}

vector<Nodo*> ListaDoblementeEnlazada::obtenerListaAlfabetica() {
    vector<Nodo*> lista;   // Vector auxiliar
    Nodo* actual = cabeza; // Empezamos en cabeza

    // Llenar el vector con todos los nodos en orden de llegada
    while (actual != nullptr) {
        lista.push_back(actual);
        actual = actual->siguiente;
    }

    // Ordenar el vector usando sort y lambda
    sort(lista.begin(), lista.end(), [](Nodo* a, Nodo* b) {
        return a->nombre < b->nombre; // Comparación lexicográfica
    });

    return lista; // Devolver la lista ordenada
}

/**
 * Obtiene un vector con los huéspedes en orden de llegada (cabeza a cola).
 */
vector<Nodo*> ListaDoblementeEnlazada::obtenerListaPorLlegada() {
    vector<Nodo*> lista;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        lista.push_back(actual); // Agregamos el nodo actual
        actual = actual->siguiente; // Avanzamos
    }

    return lista; // Retornar el vector con el orden original
}

bool ListaDoblementeEnlazada::estaVacia() {
    return cabeza == nullptr;
}

int ListaDoblementeEnlazada::obtenerTamaño() {
    return tamaño;
}

void ListaDoblementeEnlazada::limpiarLista() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;      // Guardar nodo actual
        cabeza = cabeza->siguiente; // Avanzar cabeza al siguiente
        delete temp;              // Borrar el nodo anterior
    }
    cola = nullptr;  // Lista vacía: cola en nullptr
    tamaño = 0;      // Contador en cero
}

/**
 * Devuelve los nombres de los huéspedes en las habitaciones vecinas
 * de un número de habitación dado.
 * Si la habitación vecina no está ocupada, retorna "No ocupada".
 */
pair<string, string> ListaDoblementeEnlazada::obtenerVecinos(int numeroHabitacion) {
    string vecinoAnterior = "No ocupada";
    string vecinoSiguiente = "No ocupada";

    // Buscar habitación anterior (h-1)
    Nodo* nodoAnterior = buscarPorHabitacion(numeroHabitacion - 1);
    if (nodoAnterior != nullptr) {
        vecinoAnterior = nodoAnterior->nombre;
    }

    // Buscar habitación siguiente (h+1)
    Nodo* nodoSiguiente = buscarPorHabitacion(numeroHabitacion + 1);
    if (nodoSiguiente != nullptr) {
        vecinoSiguiente = nodoSiguiente->nombre;
    }

    return make_pair(vecinoAnterior, vecinoSiguiente); // Retornar resultado
}


