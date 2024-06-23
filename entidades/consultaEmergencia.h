#ifndef CONSULTAEMERGENCIA_H
#define CONSULTAEMERGENCIA_H

#include "consulta.h"
#include <string>
#include "usuario.h"
#include "../dts/fecha.h"

class ConsultaEmergencia : public Consulta{
    private:
        string motivo;
    public:
        ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, string motivo);
        void setMotivo(string motivo);
        string getMotivo();
        ~ConsultaEmergencia();
};

#endif
