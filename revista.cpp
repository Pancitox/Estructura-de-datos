#include "Revista.h"
using namespace std;

Revista::Revista(string nombre,string isbn,string autor, string numeroEdicion,string mesPublicacion)
    : materialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

void Revista::mostrarInformacion() {
    cout << "Revista: " << getNombre() << "\n" 
              << "ISBN: " << getISBN() << "\n"   
              << "Autor: " << getAutor() << "\n"   
              << "Numero de Edicion: " << numeroEdicion << "\n"
              << "Mes de Publicacion: " << mesPublicacion << "\n"
              << "Prestado: " << (estaPrestado() ? "Si" : "No") <<endl; 
}

string Revista::getNumeroEdicion() const {
    return numeroEdicion;
}

string Revista::getMesPublicacion() const {
    return mesPublicacion;
}
