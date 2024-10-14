#pragma once
#include <iostream>
#include <string>
#include "materialBibliografico.h"

using namespace std;

class Libro : public materialBibliografico {
private:
    string isbn;               
    string autor;              
    string fechaPublicacion;    
    string resumen;             

public:
    
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);

   
    string getISBN() const;         
    string getFechaPublicacion() const;  
    string getResumen() const;      

    
    void mostrarInformacion();
};
