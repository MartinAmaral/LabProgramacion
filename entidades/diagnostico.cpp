#include "Diagnostico.h"

// Constructor
Diagnostico::Diagnostico(representacionE* rep, string desc)
    : representacion(rep), descripcion(desc) {}

// Métodos de acceso
representacionE* Diagnostico::getRepresentacion() {
    return representacion;
}

void Diagnostico::setRepresentacion(representacionE* rep) {
    representacion = rep;
}

string Diagnostico::getDescripcion() {
    return descripcion;
}

void Diagnostico::setDescripcion(string desc) {
    descripcion = desc;
}

