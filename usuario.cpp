#include "Usuario.h"
#include "materialBibliografico.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string _nombre,int _id,int _numPrestamos){
    this-> nombre = _nombre;
    this-> id = _id;
    this-> numPrestamos = _numPrestamos;
}

bool Usuario::prestarMaterial(materialBibliografico* material) {
    if (numPrestamos < 5 && !material->estaPrestado()) {
        materialesPrestados[numPrestamos++] = material;
        material->setPrestado();
        return true;
    }
    return false;
};

bool Usuario::devolverMaterial(materialBibliografico* material) {
    for (int i = 0; i < numPrestamos; i++) {
        if (materialesPrestados[i] == material) {
            material->setPrestado();
            materialesPrestados[i] = materialesPrestados[--numPrestamos];
            return true;
        }
    }
    return false;
};

void Usuario::mostrarMaterialesPrestados() const {
    std::cout << "Materiales prestados por " << nombre << ":\n";
    for (int i = 0; i < numPrestamos; i++) {
        materialesPrestados[i]->mostrarInformacion();
    }
}
int Usuario::getId(){return id;}
