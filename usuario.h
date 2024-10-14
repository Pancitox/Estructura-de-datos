#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "materialBibliografico.h"
using namespace std;

class Usuario {
private:
    string nombre;
    int id;
    materialBibliografico* materialesPrestados[5];
    int numPrestamos;
    string contrasena;

public:
    Usuario(string _nombre, int _id, string _contrasena, int _numPrestamos = 0);
    bool prestarMaterial(materialBibliografico* material);
    bool devolverMaterial(materialBibliografico* material);
    void mostrarMaterialesPrestados() const;
    int getId();
    string getNombre();
    string getContrasena();
    int getNumPrestamos();
    materialBibliografico* getMaterialPrestado(int index) const;
};
