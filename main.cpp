#include "GestorHotel.h"
#include <iostream>
using namespace std; // Agregando using namespace std para evitar std::

int main() {
    cout << "¡Bienvenido al Sistema de Gestion Hotelera!" << endl; // Removiendo std:: prefijos
    cout << "Cargando datos de huespedes..." << endl << endl;

    GestorHotel hotel("hotel.txt");
    hotel.ejecutar();

    return 0;
}