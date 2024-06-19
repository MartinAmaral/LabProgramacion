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
        ConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo);
        string getMotivo();
        bool esEmergencia();
        ~ConsultaEmergencia();

};

#endif
