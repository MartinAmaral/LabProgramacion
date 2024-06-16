#include "diagnostico.h"

// Constructor
Diagnostico::Diagnostico(RepresentacionE* rep, string desc)
    : representacion(rep), descripcion(desc) {}

// Métodos de acceso
<<<<<<< HEAD
representacionE* Diagnostico::getRepresentacion(){
    
=======
RepresentacionE* Diagnostico::getRepresentacion() {
>>>>>>> a14b9799bc9eb2ddd05788a0759a2c06cda1167e
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

