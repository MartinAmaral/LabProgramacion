#ifndef REPRESENTACIONE_H
#define REPRESENTACIONE_H

#include <iostream>
#include <string>
using namespace std;

class representacionE {
private:
    string descripcion;
    string codigo;
   

public:
    // Constructor
    representacionE(string descripcion, string codigo);

    representacionE(string desc, string cod);

// Destructor
    ~representacionE();

    // Métodos de acceso
    string getDescripcion();
    void setDescripcion(string desc);

    string getCodigo();
    void setCodigo(string cod);

    // Método para mostrar la representación
    void mostrar();
};

// Implementación de métodos

representacionE::representacionE(string desc, string cod)
    : descripcion(desc), codigo(cod) {}

representacionE::~representacionE() {}

std::string representacionE::getDescripcion()  {
    return descripcion;
}

void representacionE::setDescripcion(string desc) {
    descripcion = desc;
}

string representacionE::getCodigo() {
    return codigo;
}

void representacionE::setCodigo(string cod) {
    codigo = cod;
}

#endif // REPRESENTACIONE_H