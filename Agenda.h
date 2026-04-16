#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>
#include "Contacto.h"

class Agenda {
private:
    std::vector<Contacto> lista;
    const std::string nombreArchivo = "datos_agenda.txt";

    void cargarDesdeArchivo(); // Se ejecuta al iniciar la agenda

public:
    Agenda();
    void agregarContacto(const std::string& nombre, const std::string& telefono);
    void mostrarTodos() const;
    void buscarContacto(const std::string& nombreBusqueda) const;
    void guardarYSalir();
};

#endif