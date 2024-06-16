#ifndef CONSULTA_EMERGENCIA_H
#define CONSULTA_EMERGENCIA_H

#include "consulta.h"
#include <string>

class ConsultaEmergencia : public Consulta {
private:
    std::string motivo;
public:
    ConsultaEmergencia(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico, string motivo);
    
    ~ConsultaEmergencia();
};

#endif