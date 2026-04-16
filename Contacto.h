#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>

class Contacto {
private:
    std::string nombre;
    std::string telefono;

public:
    // Usamos const & para mayor eficiencia en memoria
    Contacto(const std::string& _nombre, const std::string& _telefono);

    std::string getNombre() const;
    std::string getTelefono() const;
    void imprimir() const;
};

#endif