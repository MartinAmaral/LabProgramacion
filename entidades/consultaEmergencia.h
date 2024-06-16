#ifndef CONSULTA_EMERGENCIA_H
#define CONSULTA_EMERGENCIA_H

#include "consulta.h"
#include <string>
#include "consulta.h"

<<<<<<< HEAD
class ConsultaEmergencia : public Consulta {
private:
    std::string motivo;
public:
    ConsultaEmergencia(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico, string motivo);
    
    ~ConsultaEmergencia();
=======
class ConsultaEmergencia : public Consulta{
    private:
        string motivo;
    public:
        ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fecha , string motivo);
        ~ConsultaEmergencia();
>>>>>>> a14b9799bc9eb2ddd05788a0759a2c06cda1167e
};

#endif