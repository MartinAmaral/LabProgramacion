#ifndef CCONSULTA_H
#define CCONSULTA_H

#include <map>
#include <string>
#include "../entidades/usuario.h"
#include "../entidades/medico.h"
#include "../entidades/fecha.h"
#include "../entidades/consulta.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include <memory>

using namespace std;

// Este controllador se encarga de los siguientes casos de uso:
// Registro de Consulta
// Alta de Diagnostico de Una Consulta

class CConsulta  : public ICConsulta
{
    private:
        static CConsulta* InstanceConsulta();
        map<string, shared_ptr<Consulta>> consultas;

        CConsulta() {}
        string generarClave(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const;
    public:
        static CConsulta* getInstanceConsulta();
        void ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, Fecha* fechaReserva, bool asistio);
        void ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo);
        bool consultaExistente(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const;
        void darAltaDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico);
        map<string, shared_ptr<Consulta>> obtenerConsultasDelDia(const string& ciMedico, const Fecha& fechaConsulta);
};
#endif