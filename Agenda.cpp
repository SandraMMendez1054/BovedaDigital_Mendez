#include "Agenda.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Agenda::Agenda() {
    cargarDesdeArchivo();
}

// CORRECCIÓN 1: Agregamos 'const string&' y el 'const' al final
void Agenda::buscarContacto(const string& nombreBusqueda) const {
    bool encontrado = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getNombre() == nombreBusqueda) {
            cout << "\n[!] Contacto encontrado:" << endl;
            lista[i].imprimir();
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "\n[X] No se encontro a: " << nombreBusqueda << endl;
}

// CORRECCIÓN 2: Agregamos 'const string&' para que coincida con el .h
void Agenda::agregarContacto(const string& nombre, const string& telefono) {
    if (nombre.empty() || telefono.empty()) {
        cout << "[!] Error: No puedes dejar campos vacios." << endl;
        return;
    }
    lista.push_back(Contacto(nombre, telefono));
    cout << "[OK] Agregado a la memoria." << endl;
}

// CORRECCIÓN 3: Agregamos el 'const' al final
void Agenda::mostrarTodos() const {
    if (lista.empty()) {
        cout << "La boveda esta vacia actualmente." << std::endl;
        return;
    }
    cout << "\n--- LISTA DE CONTACTOS ---" << endl;
    for (const auto& c : lista) {
        c.imprimir();
    }
}

void Agenda::guardarYSalir() {
    ofstream archivo(nombreArchivo, ios::trunc);
    if (archivo.is_open()) {
        for (const auto& c : lista) {
            archivo << c.getNombre() << "," << c.getTelefono() << endl;
        }
        archivo.close();
        cout << "[V] Datos guardados. Boveda cerrada con exito." << endl;
    }
}

void Agenda::cargarDesdeArchivo() {
    ifstream archivo(nombreArchivo);
    string linea, n, t;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            if (getline(ss, n, ',') && getline(ss, t)) {
                lista.push_back(Contacto(n, t));
            }
        }
        archivo.close();
    }
}