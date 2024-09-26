#ifndef materialBibliografico_H
#define materialBibliografico_H
#pragma once
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
    bool setPrestado();
    void mostrarInformacion(); 
    string getNombre();
    string getAutor();
};
#endif