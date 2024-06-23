#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "ratio"
#include "representacionE.h"
#include <iostream>
#include <string>

using namespace std;

class Diagnostico {
    private:
        RepresentacionE* representacion = NULL;
        string descripcion;
    public:
    // Constructor
        Diagnostico(RepresentacionE* rep, string descLibre);

    // Métodos de acceso
        RepresentacionE* getRepresentacion();
        void setRepresentacion(RepresentacionE* rep);

        string getDescripcion();
        void setDescripcion(string desc);
        ~Diagnostico();
};

#endif
