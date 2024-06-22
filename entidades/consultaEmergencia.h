#ifndef CONSULTAEMERGENCIA_H
#define CONSULTAEMERGENCIA_H

#include "consulta.h"
#include <string>
#include "usuario.h"
#include "fecha.h"


class ConsultaEmergencia : public Consulta{
    private:
        string motivo;
    public:
        ConsultaEmergencia(Usuario* paciente, Usuario* medico, const Fecha& fechaConsulta, const std::string& motivo);
        void setMotivo(string motivo);
        string getMotivo();
        ~ConsultaEmergencia();
};

#endif
