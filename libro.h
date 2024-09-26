#pragma once
#include <iostream>
#include "materialBibliografico.h"

class Libro : public materialBibliografico {
private:
    string fechaPublicacion;
    string resumen;

public:
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
    void mostrarInformacion();
};
