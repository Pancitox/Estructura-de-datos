#include <iostream>
#include <string>
#include <fstream>
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include "materialBibliografico.h"

using namespace std;

const int MAX_MATERIALES = 100;
const int MAX_USUARIOS = 10;

materialBibliografico* biblioteca[MAX_MATERIALES];
Usuario* usuarios[MAX_USUARIOS];
int numMateriales = 0;
int numUsuarios = 0;

void guardarBiblioteca() {
    ofstream archivo("biblioteca.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar la biblioteca.\n";
        return;
    }

    archivo << numMateriales << "\n"; 
    for (int i = 0; i < numMateriales; i++) {
        if (dynamic_cast<Libro*>(biblioteca[i])) {
            archivo << "LIBRO\n";
            Libro* libro = dynamic_cast<Libro*>(biblioteca[i]);
            archivo << libro->getNombre() << "\n"
                    << libro->getISBN() << "\n"
                    << libro->getAutor() << "\n"
                    << libro->getFechaPublicacion() << "\n"
                    << libro->getResumen() << "\n"
                    << (libro->estaPrestado() ? "1" : "0") << "\n";
        } else if (dynamic_cast<Revista*>(biblioteca[i])) {
            archivo << "REVISTA\n";
            Revista* revista = dynamic_cast<Revista*>(biblioteca[i]);
            archivo << revista->getNombre() << "\n"
                    << revista->getISBN() << "\n"
                    << revista->getAutor() << "\n"
                    << revista->getNumeroEdicion() << "\n"
                    << revista->getMesPublicacion() << "\n"
                    << (revista->estaPrestado() ? "si" : "no") << "\n";
        }
    }

    archivo.close();
    cout << "Biblioteca guardada exitosamente.\n";
}

void cargarBiblioteca() {
    ifstream archivo("biblioteca.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo para cargar la biblioteca.\n";
        return;
    }

    int numMaterialesLeidos;
    archivo >> numMaterialesLeidos;
    archivo.ignore();


    if (numMaterialesLeidos > MAX_MATERIALES) {
        cout << "Error: El número de materiales excede el máximo permitido.\n";
        return;
    }

    
    numMateriales = 0;

    for (int i = 0; i < numMaterialesLeidos; i++) {
        string tipo;
        getline(archivo, tipo); 
        if (tipo == "LIBRO") {
            string nombre, isbn, autor, fechaPublicacion, resumen;
            getline(archivo, nombre);
            getline(archivo, isbn);
            getline(archivo, autor);
            getline(archivo, fechaPublicacion);
            getline(archivo, resumen);

            Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);

          
            int estadoPrestado;
            archivo >> estadoPrestado;
            archivo.ignore();  

            libro->setPrestado(estadoPrestado == 1); 

        
            biblioteca[numMateriales++] = libro;

        } else if (tipo == "REVISTA") {
            string nombre, isbn, autor, numeroEdicion, mesPublicacion;
            getline(archivo, nombre);
            getline(archivo, isbn);
            getline(archivo, autor);
            getline(archivo, numeroEdicion);
            getline(archivo, mesPublicacion);

            Revista* revista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);

          
            int estadoPrestado;
            archivo >> estadoPrestado;
            archivo.ignore();  

            revista->setPrestado(estadoPrestado == 1);  

            
            biblioteca[numMateriales++] = revista;
        } else {
            cout << "Error: Tipo de material desconocido en la biblioteca.\n";
            break;
        }
    }

    archivo.close();
    cout << "Biblioteca cargada exitosamente.\n";
}

void guardarUsuarios() {
    ofstream archivo("usuarios.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar los usuarios.\n";
        return;
    }

    archivo << numUsuarios << "\n";  
    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i]->getNombre() << "\n"
                << usuarios[i]->getId() << "\n"
                << usuarios[i]->getContrasena() << "\n"; 
    }

    archivo.close();
    cout << "Usuarios guardados exitosamente.\n";
}

void cargarUsuarios() {
    ifstream archivo("usuarios.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de los usuarios.\n";
        return;
    }

    archivo >> numUsuarios;
    archivo.ignore(); 
    for (int i = 0; i < numUsuarios; i++) {
        string nombre;
        int id;
        string contrasena;
        getline(archivo, nombre);
        archivo >> id;
        archivo.ignore();  
        getline(archivo, contrasena); 

        usuarios[i] = new Usuario(nombre, id, contrasena);
    }

    archivo.close();
    cout << "Usuarios cargados exitosamente.\n";
}

void agregarLibro() {
    if (numMateriales >= MAX_MATERIALES) {
        cout << "Error: No se pueden agregar mas materiales a la biblioteca.\n";
        return;
    }
    string nombre, isbn, autor, fechaPublicacion, resumen;
    cout << "Ingrese el nombre del libro: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ISBN: ";
    getline(cin, isbn);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese la fecha de publicacion: ";
    getline(cin, fechaPublicacion);
    cout << "Ingrese el resumen: ";
    getline(cin, resumen);

    biblioteca[numMateriales++] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    cout << "Libro agregado exitosamente.\n";
}

void agregarRevista() {
    if (numMateriales >= MAX_MATERIALES) {
        cout << "Error: No se pueden agregar mas materiales a la biblioteca.\n";
        return;
    }
    string nombre, isbn, autor, mesPublicacion;
    string numeroEdicion;
    cout << "Ingrese el nombre de la revista: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ISBN: ";
    getline(cin, isbn);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el mes de publicacion: ";
    getline(cin, mesPublicacion);
    cout << "Ingrese el numero de edicion: ";
    cin >> numeroEdicion;

    biblioteca[numMateriales++] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
    cout << "Revista agregada exitosamente.\n";
}

void mostrarMateriales() {
    if (numMateriales == 0) {
        cout << "No hay materiales en la biblioteca.\n";
        return;
    }
    for (int i = 0; i < numMateriales; i++) {
        cout << i + 1 << ". ";
        biblioteca[i]->mostrarInformacion();
    }
}

void buscarMaterial() {
    string criterio;
    cout << "Ingrese el titulo o autor a buscar: ";
    cin.ignore();
    getline(cin, criterio);
    bool encontrado = false;
    for (int i = 0; i < numMateriales; i++) {
        if (biblioteca[i]->getNombre().find(criterio) != string::npos ||
            biblioteca[i]->getAutor().find(criterio) != string::npos) {
            biblioteca[i]->mostrarInformacion();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron materiales con ese criterio.\n";
    }
}

void prestarMaterial(Usuario* usuario) {
    mostrarMateriales();
    int indice;

    while (true) {
        cout << "Seleccione el material a prestar: ";
        cin >> indice;

        if (cin.fail() || indice < 1 || indice > numMateriales) {
            cout << "Error: Entrada inválida. Por favor, ingrese un número válido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    materialBibliografico* material = biblioteca[indice - 1];

    if (material->estaPrestado()) {
        cout << "Error: El material ya está prestado.\n";
        return;
    }

    if (usuario->prestarMaterial(material)) {
        material->setPrestado(true); 
        cout << "Material prestado exitosamente.\n";
    } else {
        cout << "Error: No se pudo prestar el material. Verifique si el usuario tiene un préstamo máximo.\n";
    }
}

void devolverMaterial(Usuario* usuario) {
    usuario->mostrarMaterialesPrestados();
    int indice;
    cout << "Seleccione el material a devolver: ";
    cin >> indice;

    if (indice < 1 || indice > usuario->getNumPrestamos()) {
        cout << "Error: Material invalido.\n";
        return;
    }

    if (usuario->devolverMaterial(usuario->getMaterialPrestado(indice - 1))) {
        cout << "Material devuelto exitosamente.\n";
    } else {
        cout << "Error: No se pudo devolver el material.\n";
    }
}

Usuario* crearUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Error: No se pueden agregar mas usuarios.\n";
        return nullptr;
    }
    string nombre;
    int id;
    string contrasena;
    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ID del usuario: ";
    cin >> id;
    cout << "Ingrese la contrasena del usuario: ";
    cin >> contrasena;

    usuarios[numUsuarios] = new Usuario(nombre, id, contrasena);
    cout<<"Usuario Creado Exitosamente...";
    cout<<"";
    return usuarios[numUsuarios++];
}

Usuario* buscarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario: ";
    cin >> id;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    cout << "Usuario no encontrado.\n";
    return nullptr;
}

void eliminarUsuario(Usuario* usuarioActual) {
    if (usuarioActual->getNombre() != "admin") {
        cout << "Error: Solo el usuario 'admin' puede eliminar usuarios.\n";
        return;
    }
    int id;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i]->getId() == id) {
            if (usuarios[i]->getNombre() == "admin") {
                cout << "Error: No se puede eliminar el usuario 'admin'.\n";
                return;
            }
            delete usuarios[i];
            usuarios[i] = usuarios[--numUsuarios];
            cout << "Usuario eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}

bool iniciarSesion(Usuario*& usuarioActual) {
    string nombre, contrasena;
    cout<<"Bienvenido a la Biblioteca";
    cout<<"";
    cout << "Ingrese su nombre de usuario (admin es el usuario y contrasena default): ";
    cin >> nombre;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i]->getNombre() == nombre && usuarios[i]->getContrasena() == contrasena) {
            usuarioActual = usuarios[i];
            cout << "Inicio de sesion exitoso.\n";
            return true;
        }
    }
    cout << "Error: Nombre de usuario o contrasena incorrectos.\n";
    return false;
}

void mostrarMenu() {
    cout << "\nMenu de opciones:\n";
    cout << "1. Agregar Libro\n";
    cout << "2. Agregar Revista\n";
    cout << "3. Listar Materiales\n";
    cout << "4. Buscar Material\n";
    cout << "5. Prestar Material\n";
    cout << "6. Devolver Material\n";
    cout << "7. Crear Usuario\n";
    cout << "8. Eliminar Usuario\n";
    cout << "9. Salir\n";
}

void mostrarMenuUsuarios(){
    cout << "\nMenu de opciones:\n";
    cout << "1. Listar Materiales\n";
    cout << "2. Buscar Material\n";
    cout << "3. Prestar Material\n";
    cout << "4. Devolver Material\n";
    cout << "5. Salir\n";
}
int main() {
    cargarUsuarios();
    cargarBiblioteca();

    bool adminExists = false;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i]->getNombre() == "admin") {
            adminExists = true;
            break;
        }
    }

    if (!adminExists) {
        string contrasena = "admin";
        usuarios[numUsuarios++] = new Usuario("admin", 1, contrasena);
    }

    int opcion;
    Usuario* usuarioActual = nullptr;

    while (!iniciarSesion(usuarioActual));

    do {
        if (usuarioActual->getNombre() != "admin") {
            mostrarMenuUsuarios();
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    mostrarMateriales();
                    break;
                case 2:
                    buscarMaterial();
                    break;
                case 3:
                    prestarMaterial(usuarioActual);
                    break;
                case 4:
                    devolverMaterial(usuarioActual);
                    break;
                case 5:
                    cout << "Saliendo del sistema de usuario...\n";
                    break;
                default:
                    cout << "Opcion invalida.\n";
                    break;
            }
        } else {
            mostrarMenu();
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    agregarLibro();
                    break;
                case 2:
                    agregarRevista();
                    break;
                case 3:
                    mostrarMateriales();
                    break;
                case 4:
                    buscarMaterial();
                    break;
                case 5:
                    prestarMaterial(usuarioActual);
                    break;
                case 6:
                    devolverMaterial(usuarioActual);
                    break;
                case 7:
                    crearUsuario();
                    break;
                case 8:
                    eliminarUsuario(usuarioActual);
                    break;
                case 9:
                    cout << "Saliendo del sistema de administrador...\n";
                    break;
                default:
                    cout << "Opcion invalida.\n";
                    break;
            }
        }

    } while (opcion != 9);

    guardarUsuarios();
    guardarBiblioteca();

    for (int i = 0; i < numMateriales; i++) {
        delete biblioteca[i];
    }
    for (int i = 0; i < numUsuarios; i++) {
        delete usuarios[i];
    }

    return 0;
}