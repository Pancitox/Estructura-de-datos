#include "Revista.h"
#include <iostream>

revista::revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion)
    : materialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

void revista::mostrarInformacion() const {
    cout << "Revista: " << _nombre << "\nISBN: " << _isbn << "\nAutor: " << _autor 
         << "\nNumero de Edicion: " << numeroEdicion << "\nMes de Publicacion: " << mesPublicacion
         << "\nPrestado: " << (_prestado ? "Si" : "No") << endl;
}
