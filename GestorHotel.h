#ifndef GESTOR_HOTEL_H
#define GESTOR_HOTEL_H

#include "ListaDoblementeEnlazada.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Clase GestorHotel
 * Maneja la lógica del sistema de gestión del hotel
 */
class GestorHotel {
private:
    ListaDoblementeEnlazada* listaHuespedes;
    string nombreArchivo;

    // Métodos privados
    void cargarDesdeArchivo();
    void guardarEnArchivo();
    void mostrarMenu();
    int sugerirHabitacionAlternativa(int habitacionDeseada);

public:
    // Constructor
    GestorHotel(const string& archivo = "hotel.txt");

    // Destructor
    ~GestorHotel();

    // Método principal
    void ejecutar();

    // Métodos del menú
    void ingresarNuevoHuesped();
    void buscarHuesped();
    void mostrarListaAlfabetica();
    void mostrarListaPorLlegada();
    void consultarVecinos();
};

#endif


