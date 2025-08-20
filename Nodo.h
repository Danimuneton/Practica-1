#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;
class Nodo {
public:
    string nombre;           // Nombre del huésped
    int numeroHabitacion;        // Número de habitación
    Nodo* anterior;              // Puntero al nodo anterior
    Nodo* siguiente;             // Puntero al nodo siguiente

    // Constructor
    Nodo(const string& nom, int numHab);

    // Destructor
    ~Nodo();
};

#endif
