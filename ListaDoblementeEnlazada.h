#ifndef LISTA_DOBLEMENTE_ENLAZADA_H
#define LISTA_DOBLEMENTE_ENLAZADA_H

#include "Nodo.h"
#include <vector>
using namespace std;

/**
 * Clase ListaDoblementeEnlazada
 * Implementa una lista doblemente enlazada para gestionar huéspedes del hotel
 */
class ListaDoblementeEnlazada {
private:
    Nodo* cabeza;               // Puntero al primer nodo
    Nodo* cola;                 // Puntero al último nodo
    int tamaño;                 // Número de elementos en la lista

public:
    // Constructor
    ListaDoblementeEnlazada();

    // Destructor
    ~ListaDoblementeEnlazada();

    // Métodos principales
    void agregarHuesped(const string& nombre, int numeroHabitacion);
    bool eliminarHuesped(const string& nombre);
    Nodo* buscarPorNombre(const string& nombre);
    Nodo* buscarPorHabitacion(int numeroHabitacion);

    // Métodos de visualización
    vector<Nodo*> obtenerListaAlfabetica();
    vector<Nodo*> obtenerListaPorLlegada();

    // Métodos auxiliares
    bool estaVacia();
    int obtenerTamaño();
    void limpiarLista();

    // Método para obtener vecinos de una habitación
    pair<string, string> obtenerVecinos(int numeroHabitacion);
};

#endif
