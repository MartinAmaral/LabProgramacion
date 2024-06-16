#ifndef CONSULTA_EMERGENCIA_H
#define CONSULTA_EMERGENCIA_H

#include "consulta.h"
#include <string>
#include "consulta.h"


class ConsultaEmergencia : public Consulta {
private:
    string motivo;
public:
    ConsultaEmergencia(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico, string motivo);
    
    ~ConsultaEmergencia();

};

#endif