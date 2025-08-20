# Sistema de Gestión Hotelera - Práctica I

## Descripción del Proyecto
Este proyecto implementa un sistema de gestión hotelera basado en listas doblemente enlazadas para la materia de Algoritmos y Estructuras de Datos (SI2001-5) de la Universidad EAFIT. El sistema gestiona información de huéspedes del hotel incluyendo nombres y números de habitación.

## Integrantes del Equipo
- Mateo Gomez Giraldo
- Daniel Esteban Muñeton Navarro

## Características
- **Implementación de Lista Doblemente Enlazada**: Implementación personalizada con punteros anterior y siguiente
- **Operaciones de Archivos**: Cargar y guardar datos de huéspedes desde/hacia 'hotel.txt'
- **Gestión de Huéspedes**: Agregar nuevos huéspedes con asignación de habitación
- **Funcionalidad de Búsqueda**: Buscar por nombre de huésped o número de habitación
- **Opciones de Visualización**: 
  - Listado en orden alfabético
  - Listado en orden de llegada
- **Gestión de Habitaciones**: Manejar habitaciones ocupadas con sugerencias alternativas
- **Consulta de Vecinos**: Encontrar huéspedes en habitaciones adyacentes

## Opciones del Menú
1. **Ingresar Nuevo Huésped**: Registrar un nuevo huésped con asignación de habitación
2. **Buscar Huésped**: Encontrar huésped por nombre o número de habitación
3. **Mostrar Lista de Huéspedes (Alfabética)**: Mostrar todos los huéspedes ordenados alfabéticamente
4. **Mostrar Lista de Huéspedes (Orden de Llegada)**: Mostrar huéspedes en orden de llegada
5. **Consultar Vecinos de Habitación**: Encontrar huéspedes en habitaciones adyacentes
6. **Salir**: Guardar datos y salir del programa

## Estructura de Datos
Cada nodo en la lista doblemente enlazada contiene:
- `anterior`: Puntero al nodo anterior
- `nombre`: Nombre del huésped (string)
- `numeroHabitacion`: Número de habitación (entero)
- `siguiente`: Puntero al nodo siguiente

## Presentación en Video
https://youtu.be/Z_P8FwGuIOQ?feature=shared

## Funcionalidades Implementadas

### 1. Lista Doblemente Enlazada
- Implementación completa con punteros bidireccionales
- Operaciones de inserción, eliminación y búsqueda
- Gestión automática de memoria

### 2. Gestión de Archivos
- Carga automática de datos al iniciar el programa
- Guardado automático al salir o agregar nuevos huéspedes
- Formato de archivo: nombre en una línea, número de habitación en la siguiente

### 3. Búsqueda Inteligente
- Búsqueda por nombre exacto
- Búsqueda por número de habitación
- Mensajes informativos cuando no se encuentra el huésped

### 4. Gestión de Habitaciones Ocupadas
- Detección automática de habitaciones ocupadas
- Sugerencia de habitaciones alternativas (anterior o siguiente)
- Opción de seleccionar habitación diferente si las vecinas están ocupadas

### 5. Visualización de Datos
- Lista alfabética usando algoritmo de ordenamiento
- Lista por orden de llegada (orden original de inserción)
- Formato claro y numerado para fácil lectura

### 6. Consulta de Vecinos
- Identificación de huéspedes en habitaciones adyacentes
- Manejo de habitaciones no ocupadas
- Información clara sobre el estado de las habitaciones vecinas

## Ejemplo de Uso
\`\`\`
========== SISTEMA DE GESTIÓN HOTELERA ==========
1. Ingresar nuevo huésped
2. Buscar huésped
3. Mostrar lista alfabética
4. Mostrar lista por orden de llegada
5. Consultar vecinos de habitación
6. Salir
=================================================
Seleccione una opción: 1

--- INGRESAR NUEVO HUÉSPED ---
Ingrese el nombre del huésped: Pedro Ramirez
Ingrese el número de habitación deseado: 106
Huésped Pedro Ramirez registrado exitosamente en la habitación 106.
