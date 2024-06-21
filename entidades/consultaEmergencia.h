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
        ConsultaEmergencia(Usuario* medico, Usuario* paciente,string hora ,Fecha* fechaConsulta, string motivo);
        void setMotivo(string motivo);
        string getMotivo();
        virtual void agregarDiagnostico(Diagnostico* diagnostico) override;
        ~ConsultaEmergencia();
};

#endif
