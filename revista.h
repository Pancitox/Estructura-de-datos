#pragma once
#include <iostream>
#include "materialBibliografico.h"
using namespace std;

class Revista : public materialBibliografico { 
private:
    string numeroEdicion;
    string mesPublicacion;

public:
    Revista(string nombre, string isbn, string autor, string numeroEdicion, string mesPublicacion);
    void mostrarInformacion(); 
    string getNumeroEdicion() const;             
    string getMesPublicacion() const;   
};
