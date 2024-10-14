#include "libro.h"
#include "materialBibliografico.h"
#include <iostream>
using namespace std;

Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : materialBibliografico(nombre, isbn, autor), 
      isbn(isbn), 
      fechaPublicacion(fechaPublicacion), 
      resumen(resumen) {}


string Libro::getISBN() const{
    return isbn;
}

string Libro::getFechaPublicacion() const {
    return fechaPublicacion;
}

string Libro::getResumen() const {
    return resumen;
}

void Libro::mostrarInformacion(){
    cout << "Libro: " << getNombre() << "\nISBN: " << _isbn << "\nAutor: " << getAutor() 
         << "\nFecha de Publicación: " << fechaPublicacion << "\nResumen: " << resumen
         << "\nPrestado: " << (estaPrestado() ? "Sí" : "No") << endl;
}