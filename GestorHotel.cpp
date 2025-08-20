#include "GestorHotel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;


GestorHotel::GestorHotel(const string& archivo) {
    nombreArchivo = archivo;
    listaHuespedes = new ListaDoblementeEnlazada();
    cargarDesdeArchivo();
}

/**
 * Destructor del gestor del hotel
 */
GestorHotel::~GestorHotel() {
    delete listaHuespedes;
}

/**
 * Carga los datos desde el archivo de texto
 */
void GestorHotel::cargarDesdeArchivo() {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << ". Se creara uno nuevo." << endl;
        return;
    }

    string nombre;
    int numeroHabitacion;

    while (getline(archivo, nombre) && archivo >> numeroHabitacion) {
        archivo.ignore(); // Ignorar el salto de línea después del número
        listaHuespedes->agregarHuesped(nombre, numeroHabitacion);
    }

    archivo.close();
    cout << "Datos cargados exitosamente desde " << nombreArchivo << endl;
}

/**
 * Guarda los datos en el archivo de texto
 */
void GestorHotel::guardarEnArchivo() {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    vector<Nodo*> lista = listaHuespedes->obtenerListaPorLlegada();
    for (Nodo* nodo : lista) {
        archivo << nodo->nombre << endl;
        archivo << nodo->numeroHabitacion << endl;
    }

    archivo.close();
}

/**
 * Muestra el menú principal del sistema
 */
void GestorHotel::mostrarMenu() {
    cout << "\n========== SISTEMA DE GESTION HOTELERA ==========" << endl;
    cout << "1. Ingresar nuevo huesped" << endl;
    cout << "2. Buscar huesped" << endl;
    cout << "3. Mostrar lista alfabetica" << endl;
    cout << "4. Mostrar lista por orden de llegada" << endl;
    cout << "5. Consultar vecinos de habitacion" << endl;
    cout << "6. Salir" << endl;
    cout << "=================================================" << endl;
    cout << "Seleccione una opcion: ";
}

/**
 * Sugiere una habitación alternativa cuando la deseada está ocupada
 * @param habitacionDeseada Número de habitación que se quería
 * @return Número de habitación alternativa disponible, o -1 si no hay
 */
int GestorHotel::sugerirHabitacionAlternativa(int habitacionDeseada) {
    // Verificar habitación anterior
    if (habitacionDeseada > 1) {
        if (listaHuespedes->buscarPorHabitacion(habitacionDeseada - 1) == nullptr) {
            return habitacionDeseada - 1;
        }
    }

    // Verificar habitación siguiente
    if (listaHuespedes->buscarPorHabitacion(habitacionDeseada + 1) == nullptr) {
        return habitacionDeseada + 1;
    }

    // Buscar cualquier habitación disponible (del 1 al 100)
    for (int i = 1; i <= 100; i++) {
        if (listaHuespedes->buscarPorHabitacion(i) == nullptr) {
            return i;
        }
    }

    return -1; // No hay habitaciones disponibles
}

/**
 * Método principal que ejecuta el sistema
 */
void GestorHotel::ejecutar() {
    int opcion;

    cout << "¡Bienvenido al Sistema de Gestion Hotelera!" << endl;

    do {
        mostrarMenu();
        cin >> opcion;

        // Limpiar buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                ingresarNuevoHuesped();
                break;
            case 2:
                buscarHuesped();
                break;
            case 3:
                mostrarListaAlfabetica();
                break;
            case 4:
                mostrarListaPorLlegada();
                break;
            case 5:
                consultarVecinos();
                break;
            case 6:
                cout << "¡Gracias por usar el Sistema de Gestion Hotelera!" << endl;
                guardarEnArchivo();
                break;
            default:
                cout << "Opción invalida. Por favor, seleccione una opcion del 1 al 6." << endl;
        }
    } while (opcion != 6);
}

/**
 * Permite ingresar un nuevo huésped al sistema
 */
void GestorHotel::ingresarNuevoHuesped() {
    string nombre;
    int numeroHabitacion;

    cout << "\n--- INGRESAR NUEVO HUESPED ---" << endl;
    cout << "Ingrese el nombre del huesped: ";
    getline(cin, nombre);

    cout << "Ingrese el numero de habitacion deseado: ";
    cin >> numeroHabitacion;
    cin.ignore();

    // Verificar si la habitación está ocupada
    if (listaHuespedes->buscarPorHabitacion(numeroHabitacion) != nullptr) {
        cout << "La habitacion " << numeroHabitacion << " ya esta ocupada." << endl;

        int habitacionAlternativa = sugerirHabitacionAlternativa(numeroHabitacion);

        if (habitacionAlternativa != -1) {
            char respuesta;
            cout << "¿Desea la habitacion " << habitacionAlternativa << " en su lugar? (s/n): ";
            cin >> respuesta;
            cin.ignore();

            if (respuesta == 's' || respuesta == 'S') {
                numeroHabitacion = habitacionAlternativa;
            } else {
                cout << "Por favor, elija un número de habitación diferente: ";
                cin >> numeroHabitacion;
                cin.ignore();

                // Verificar nuevamente
                if (listaHuespedes->buscarPorHabitacion(numeroHabitacion) != nullptr) {
                    cout << "La habitacion sigue ocupada. Operacion cancelada." << endl;
                    return;
                }
            }
        } else {
            cout << "No hay habitaciones disponibles en este momento." << endl;
            return;
        }
    }

    listaHuespedes->agregarHuesped(nombre, numeroHabitacion);
    guardarEnArchivo();
    cout << "Huesped " << nombre << " registrado exitosamente en la habitacion " << numeroHabitacion << "." << endl;
}

/**
 * Permite buscar un huésped por nombre o número de habitación
 */
void GestorHotel::buscarHuesped() {
    int tipoBusqueda;

    cout << "\n--- BUSCAR HUESPED ---" << endl;
    cout << "1. Buscar por nombre" << endl;
    cout << "2. Buscar por numero de habitacion" << endl;
    cout << "Seleccione el tipo de busqueda: ";
    cin >> tipoBusqueda;
    cin.ignore();

    if (tipoBusqueda == 1) {
        string nombre;
        cout << "Ingrese el nombre del huesped: ";
        getline(cin, nombre);

        Nodo* nodo = listaHuespedes->buscarPorNombre(nombre);
        if (nodo != nullptr) {
            cout << "Huesped encontrado: " << nodo->nombre << " esta en la habitacion " << nodo->numeroHabitacion << "." << endl;
        } else {
            cout << "Ese huesped no fue encontrado." << endl;
        }
    } else if (tipoBusqueda == 2) {
        int numeroHabitacion;
        cout << "Ingrese el numero de habitacion: ";
        cin >> numeroHabitacion;

        Nodo* nodo = listaHuespedes->buscarPorHabitacion(numeroHabitacion);
        if (nodo != nullptr) {
            cout << "En la habitacion " << numeroHabitacion << " se encuentra: " << nodo->nombre << "." << endl;
        } else {
            cout << "Esa habitacion no esta ocupada." << endl;
        }
    } else {
        cout << "Opcion invalida." << endl;
    }
}

/**
 * Muestra la lista de huéspedes en orden alfabético
 */
void GestorHotel::mostrarListaAlfabetica() {
    cout << "\n--- LISTA ALFABETICA DE HUESPEDES ---" << endl;

    if (listaHuespedes->estaVacia()) {
        cout << "No hay huespedes registrados." << endl;
        return;
    }

    vector<Nodo*> lista = listaHuespedes->obtenerListaAlfabetica();

    for (size_t i = 0; i < lista.size(); i++) {
        cout << (i + 1) << ". " << lista[i]->nombre << " - Habitacion " << lista[i]->numeroHabitacion << endl;
    }
}

/**
 * Muestra la lista de huéspedes por orden de llegada
 */
void GestorHotel::mostrarListaPorLlegada() {
    cout << "\n--- LISTA POR ORDEN DE LLEGADA ---" << endl;

    if (listaHuespedes->estaVacia()) {
        cout << "No hay huespedes registrados." << endl;
        return;
    }

    vector<Nodo*> lista = listaHuespedes->obtenerListaPorLlegada();

    for (size_t i = 0; i < lista.size(); i++) {
        cout << (i + 1) << ". " << lista[i]->nombre << " - Habitacion " << lista[i]->numeroHabitacion << endl;
    }
}

/**
 * Consulta los vecinos de una habitación específica
 */
void GestorHotel::consultarVecinos() {
    int numeroHabitacion;

    cout << "\n--- CONSULTAR VECINOS ---" << endl;
    cout << "Ingrese el número de habitacion: ";
    cin >> numeroHabitacion;

    pair<string, string> vecinos = listaHuespedes->obtenerVecinos(numeroHabitacion);

    cout << "Vecinos de la habitacion " << numeroHabitacion << ":" << endl;
    cout << "Habitacion " << (numeroHabitacion - 1) << ": " << vecinos.first << endl;
    cout << "Habitacion " << (numeroHabitacion + 1) << ": " << vecinos.second << endl;
}