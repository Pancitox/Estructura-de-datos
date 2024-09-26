#pragma once
#include <iostream>
#include "materialBibliografico.h"

class Usuario {
    private:
        string nombre;
        int id;
        materialBibliografico* materialesPrestados[5];
        int numPrestamos;

    public:
        Usuario(string _nombre, int _id,int _numPrestamos);
        bool prestarMaterial(materialBibliografico* material);
        bool devolverMaterial(materialBibliografico* material);
        void mostrarMaterialesPrestados()const;
        int getId();
};
