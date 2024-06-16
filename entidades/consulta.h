#ifndef CONSULTA_H
#define CONSULTA_H

#include "fecha.h"
#include <iostream>
#include <string>
#include "usuario.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"

using namespace std;

class Consulta {
protected:
    Fecha* fechaConsulta;
    string hora;
    Usuario* paciente;
    Usuario* medico;
public:
    Consulta(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico);
    
    ~Consulta();
};

#endif