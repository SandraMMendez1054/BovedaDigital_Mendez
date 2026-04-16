#include <iostream>
#include "Agenda.h"

int main() {
    Agenda miBoveda;
    int opcion = 0;
    std::string n, t;

    while (opcion != 4) {
        std::cout << "\n******* BOVEDA DIGITAL *******" << std::endl;
        std::cout << "1. Agregar amigo\n2. Ver lista\n3. Buscar por nombre\n4. Salir y Guardar\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // Importante para limpiar el buffer antes de getline

        switch (opcion) {
            case 1:
                std::cout << "Nombre: "; std::getline(std::cin, n);
                std::cout << "Telefono: "; std::getline(std::cin, t);
                miBoveda.agregarContacto(n, t);
                break;
            case 2:
                miBoveda.mostrarTodos();
                break;
            case 3:
                std::cout << "Nombre a buscar: "; std::getline(std::cin, n);
                miBoveda.buscarContacto(n);
                break;
            case 4:
                miBoveda.guardarYSalir();
                break;
            default:
                std::cout << "Opcion no valida, intenta de nuevo." << std::endl;
        }
    }

    return 0;
}