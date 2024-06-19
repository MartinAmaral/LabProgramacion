#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>
#include "fecha.h"
using namespace std;

class Tratamiento {
protected:
    string descripcion;
public:
    Tratamiento(string descripcion);
    virtual ~Tratamiento() = 0; // Clase abstracta
};

#endif // TRATAMIENTO_H