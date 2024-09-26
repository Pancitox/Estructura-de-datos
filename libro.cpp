#include "libro.h"
#include "materialBibliografico.h"
#include <iostream>
using namespace std;

// Constructor
Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : materialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

// Implementación del método mostrarInformacion
void Libro::mostrarInformacion(){
    cout << "Libro: " << getNombre() << "\nISBN: " << _isbn << "\nAutor: " << getAutor() 
         << "\nFecha de Publicación: " << fechaPublicacion << "\nResumen: " << resumen
         << "\nPrestado: " << (estaPrestado() ? "Sí" : "No") << endl;
}
