#include "representacionE.h"

// Constructor
representacionE::representacionE(string desc, string cod)
    : descripcion(desc), codigo(cod) {}

// Destructor
representacionE::~representacionE() {}

// Métodos de acceso
string representacionE::getDescripcion() {
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