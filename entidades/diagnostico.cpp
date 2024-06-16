#include "diagnostico.h"

// Constructor
Diagnostico::Diagnostico(RepresentacionE* rep, string desc)
    : representacion(rep), descripcion(desc) {}

// Métodos de acceso
RepresentacionE* Diagnostico::getRepresentacion() {
    return representacion;
}

void Diagnostico::setRepresentacion(RepresentacionE* rep) {
    representacion = rep;
}

string Diagnostico::getDescripcion() {
    return descripcion;
}

void Diagnostico::setDescripcion(string desc) {
    descripcion = desc;
}

