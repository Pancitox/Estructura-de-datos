#include "materialBibliografico.h"
#include <iostream>
using namespace std;

materialBibliografico::materialBibliografico(string nombre, string isbn,string autor){
    this -> _nombre = nombre;
    this -> _isbn = isbn;
    this -> _autor = autor;
    this -> _prestado = false;
};

bool materialBibliografico::estaPrestado(){return true;}
bool materialBibliografico::setPrestado(){
    if(_prestado){
        _prestado = false;
    }else{
        _prestado = true;
    }
    return _prestado;
};
string materialBibliografico::getNombre(){return _nombre;}
string materialBibliografico::getAutor(){return _autor;}
void materialBibliografico::mostrarInformacion(){
    cout<<"Nombre: "<<_nombre<<"Isbn: "<<_isbn<<"Autor: "<<_autor<<"Esta prestado?: "<<(_prestado ? "Si" : "No")<<endl;
};