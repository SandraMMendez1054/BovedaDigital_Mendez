#include "Contacto.h"
#include <iostream>

Contacto::Contacto(const std::string& _nombre, const std::string& _telefono) {
    this->nombre = _nombre;
    this->telefono = _telefono;
}

std::string Contacto::getNombre() const { return nombre; }
std::string Contacto::getTelefono() const { return telefono; }

void Contacto::imprimir() const {
    std::cout << " > " << nombre << " | Tel: " << telefono << std::endl;
}