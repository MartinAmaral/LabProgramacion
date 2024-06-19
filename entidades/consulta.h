#ifndef CONSULTA_H
#define CONSULTA_H

#include "fecha.h"
#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

class Consulta {
protected:
    Fecha* fechaConsulta;
    string hora;
    Usuario* paciente;
    Usuario* medico;
public:
    Consulta(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico);
    virtual ~Consulta() = 0;
};

#endif
