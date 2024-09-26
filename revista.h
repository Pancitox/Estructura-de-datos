#pragma once
#include <iostream>
#include "materialBibliografico.h"

class revista : public materialBibliografico{
    private:
        int numeroEdicion;
        string mesPublicacion;
    public:
        revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion);
        void mostrarInformacion() const;
};