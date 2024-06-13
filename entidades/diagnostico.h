#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "representacionE.h"
#include <iostream>
#include <string>

class Diagnostico {
private:
    representacionE* representacion;
    string descripcion;

public:
    // Constructor
    Diagnostico(representacionE* rep, string descLibre);

    // Métodos de acceso
    representacionE* getRepresentacion();
    void setRepresentacion(representacionE* rep);
    

    string getDescripcion();
    void setDescripcion(string desc);

    // Método para mostrar el diagnóstico
    void mostrar() const;
};

// Implementación de métodos

Diagnostico::Diagnostico(representacionE* rep,string desc)
    : representacion(rep), descripcion(desc) {}

representacionE* Diagnostico::getRepresentacion(){
    return representacion;
}

void Diagnostico::setRepresentacion(representacionE* rep) {
    representacion = rep;
}

std::string Diagnostico::getDescripcion(){
    return descripcion;
}

void Diagnostico::setDescripcion(string desc) {
    descripcion = desc;
}

#endif // DIAGNOSTICO_H