#include "Nodo.h"
using namespace std;

Nodo::Nodo(const string& nom, int numHab) {
    nombre = nom;
    numeroHabitacion = numHab;
    anterior = nullptr;
    siguiente = nullptr;
}

/**
 * Destructor de la clase Nodo
 */
Nodo::~Nodo() {
    // No necesita implementación específica
}
