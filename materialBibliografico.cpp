#include "materialBibliografico.h"
#include <iostream>
using namespace std;

materialBibliografico::materialBibliografico(string nombre, string isbn, string autor) {
    this->_nombre = nombre;
    this->_isbn = isbn;
    this->_autor = autor;
    this->_prestado = false;  
}

bool materialBibliografico::estaPrestado() {
    return _prestado;  
}

void materialBibliografico::setPrestado(bool estado) {
    _prestado = estado;
}

void materialBibliografico::prestar() {
    _prestado = true;  
}

void materialBibliografico::devolver() {
    _prestado = false;  
}

string materialBibliografico::getNombre() {
    return _nombre; 
}

string materialBibliografico::getAutor() {
    return _autor; 
}

string materialBibliografico::getISBN(){
    return _isbn;
}
void materialBibliografico::mostrarInformacion() {
    cout << "Nombre: " << _nombre
         << " Isbn: " << _isbn
         << " Autor: " << _autor
         << " Esta prestado ?: " << (_prestado ? "Si" : "No") << endl;
}
