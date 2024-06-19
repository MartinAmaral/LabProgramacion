#include "diagnostico.h"

// Constructor
Diagnostico::Diagnostico(RepresentacionE* rep, string descLibre)
    : representacion(rep), descripcion(descLibre) {}

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
void Diagnostico::mostrar() const {
    cout << "Representación: " << representacion->getDescripcion() << endl;
    cout << "Descripción: " << descripcion << endl;
}
