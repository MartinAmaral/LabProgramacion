#include "representacionE.h"

// Constructor
RepresentacionE::RepresentacionE(string codigo, string descripcion){
    this->codigo;
    this->descripcion;
}

// Destructor
RepresentacionE::~RepresentacionE() {}

// Métodos de acceso
string RepresentacionE::getDescripcion() {
    return descripcion;
}

void RepresentacionE::setDescripcion(string desc) {
    descripcion = desc;
}

string RepresentacionE::getCodigo() {
    return codigo;
}

void RepresentacionE::setCodigo(string cod) {
    codigo = cod;
}
