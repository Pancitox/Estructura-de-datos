#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <iostream>
using namespace std;

class materialBibliografico {
protected:
    string _nombre;
    string _isbn;
    string _autor;
    bool _prestado;

public:
    materialBibliografico(string nombre, string isbn, string autor);
    virtual ~materialBibliografico() = default;

    bool estaPrestado();        
    void setPrestado(bool estado);       
    void prestar();       
    void devolver();       
    string getNombre();     
    string getAutor();      
    void mostrarInformacion();  
    string getISBN();
};

#endif 
