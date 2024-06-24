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
void Diagnostico::setTratamiento(Tratamiento* trat){
    tratamiento = trat;
}

string Diagnostico::getDescripcion() {
    return descripcion;
}

void Diagnostico::setDescripcion(string desc) {
    descripcion = desc;
}

Diagnostico::~Diagnostico(){
    if(this->representacion != NULL)
        delete representacion;
}
