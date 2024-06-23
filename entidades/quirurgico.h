#ifndef QUIRURGICO_H
#define QUIRURGICO_H

#include <string>
#include "tratamiento.h"
#include "fecha.h"
using namespace std;


class Quirurgico : public Tratamiento {
    private:
        Fecha* fecha= NULL;
    public:
        Quirurgico(string descripcion, Fecha* fecha);
        ~Quirurgico();
};

#endif
