#include "Usuario.h"
#include "materialBibliografico.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Usuario::Usuario(std::string _nombre, int _id, std::string _contrasena, int _numPrestamos) 
    : nombre(_nombre), id(_id), contrasena(_contrasena), numPrestamos(_numPrestamos) {
    if (_contrasena.empty()) {
        throw std::logic_error("La contraseña no puede estar vacía.");
    }
    for (int i = 0; i < 5; ++i) {
        materialesPrestados[i] = nullptr;
    }
}

string Usuario::getContrasena() {
    return contrasena;
}

bool Usuario::prestarMaterial(materialBibliografico* material) {
    if (numPrestamos < 5 && !material->estaPrestado()) {
        materialesPrestados[numPrestamos++] = material;
        material->setPrestado(false);
        return true;
    }
    return false;
}

void Usuario::mostrarMaterialesPrestados() const {
    std::cout << "Materiales prestados por " << nombre << ":\n";
    if (numPrestamos == 0) {
        std::cout << "No hay materiales prestados.\n";
    } else {
        for (int i = 0; i < numPrestamos; i++) {
            materialesPrestados[i]->mostrarInformacion();
        }
    }
}

bool Usuario::devolverMaterial(materialBibliografico* material) {
    for (int i = 0; i < numPrestamos; i++) {
        if (materialesPrestados[i] == material) {
            material->setPrestado(false); 
            materialesPrestados[i] = materialesPrestados[--numPrestamos];
            return true;
        }
    }
    return false;
}

int Usuario::getNumPrestamos() {
    return numPrestamos;
}

int Usuario::getId() {
    return id;
}

std::string Usuario::getNombre() {
    return nombre;
}

materialBibliografico* Usuario::getMaterialPrestado(int index) const {
    if (index < 0 || index >= numPrestamos) return nullptr; 
    return materialesPrestados[index];
}
