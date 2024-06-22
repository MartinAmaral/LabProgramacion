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
#include "../entidades/diagnostico.h"
#include "../Interfaces/ICConsulta.h"

using namespace std;

class CConsulta: public ICConsulta{
    private:
        static CConsulta* instance;
        map<string,Consulta*> consultas;
        string generarClave(int ciMedico, int ciPaciente, const Fecha& fechaConsulta) const;
    public:
        static CConsulta* getInstanceConsulta();
        void ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, Fecha* fechaReserva, bool asistio);
        void ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, const std::string& motivo);
        bool consultaExistente(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const;
        void darAltaDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico);
        map<string,Consulta*> obtenerConsultasDelDia(const string& ciMedico, const Fecha& fechaConsulta);
        //virtual void agregarDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico);
};

#endif
