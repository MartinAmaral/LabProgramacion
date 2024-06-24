#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "representacionE.h"
#include "tratamiento.h"
#include <iostream>
#include <string>

using namespace std;

class Diagnostico {
    private:
        RepresentacionE* representacion = NULL;
        Tratamiento* tratamiento = NULL;
        string descripcion;
    public:
    // Constructor
        Diagnostico(RepresentacionE* rep, string descLibre);

    // Métodos de acceso
        RepresentacionE* getRepresentacion();
        void setRepresentacion(RepresentacionE* rep);
        void setTratamiento(Tratamiento* trat);
        string getDescripcion();
        void setDescripcion(string desc);
        ~Diagnostico();
};

#endif
