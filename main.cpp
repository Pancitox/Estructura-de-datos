#include <iostream>
#include <string>
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

void agregarLibro() {
    if (numMateriales >= MAX_MATERIALES) {
        cout << "Error: No se pueden agregar más materiales a la biblioteca.\n";
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
    cout << "Ingrese la fecha de publicación: ";
    getline(cin, fechaPublicacion);
    cout << "Ingrese el resumen: ";
    getline(cin, resumen);

    biblioteca[numMateriales++] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
    cout << "Libro agregado exitosamente.\n";
}

void agregarRevista() {
    if (numMateriales >= MAX_MATERIALES) {
        cout << "Error: No se pueden agregar más materiales a la biblioteca.\n";
        return;
    }
    string nombre, isbn, autor, mesPublicacion;
    int numeroEdicion;
    cout << "Ingrese el nombre de la revista: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ISBN: ";
    getline(cin, isbn);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el mes de publicación: ";
    getline(cin, mesPublicacion);
    cout << "Ingrese el número de edición: ";
    cin >> numeroEdicion;

    biblioteca[numMateriales++] = new revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
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
    cout << "Ingrese el título o autor a buscar: ";
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
    cout << "Seleccione el material a prestar: ";
    cin >> indice;
    if (indice < 1 || indice > numMateriales || biblioteca[indice - 1]->estaPrestado()) {
        cout << "Error: Material invalido o ya prestado.\n";
        return;
    }
    if (usuario->prestarMaterial(biblioteca[indice - 1])) {
        cout << "Material prestado exitosamente.\n";
    } else {
        cout << "Error: No se pudo prestar el material.\n";
    }
}

void devolverMaterial(Usuario* usuario) {
    usuario->mostrarMaterialesPrestados();
    int indice;
    cout << "Seleccione el material a devolver: ";
    cin >> indice;
    if (usuario->devolverMaterial(biblioteca[indice - 1])) {
        cout << "Material devuelto exitosamente.\n";
    } else {
        cout << "Error: No se pudo devolver el material.\n";
    }
}

Usuario* crearUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Error: No se pueden agregar más usuarios.\n";
        return nullptr;
    }
    string nombre;
    int id;
    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ID del usuario: ";
    cin >> id;

    usuarios[numUsuarios] = new Usuario(nombre, id,0);
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

void eliminarUsuario() {
    int id;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i]->getId() == id) {
            delete usuarios[i];
            usuarios[i] = usuarios[--numUsuarios];
            cout << "Usuario eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}

void mostrarMenu() {
    cout << "\nMenú de opciones:\n";
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

int main() {
    int opcion;
    Usuario* usuarioActual = nullptr;

    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
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
                if (usuarioActual) {
                    prestarMaterial(usuarioActual);
                } else {
                    cout << "Error: No hay usuario activo.\n";
                }
                break;
            case 6:
                if (usuarioActual) {
                    devolverMaterial(usuarioActual);
                } else {
                    cout << "Error: No hay usuario activo.\n";
                }
                break;
            case 7:
                usuarioActual = crearUsuario();
                break;
            case 8:
                eliminarUsuario();
                break;
            case 9:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 9);

    // Liberar memoria
    for (int i = 0; i < numMateriales; i++) {
        delete biblioteca[i];
    }
    for (int i = 0; i < numUsuarios; i++) {
        delete usuarios[i];
    }

    return 0;
}