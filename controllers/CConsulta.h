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
        string generarClave(int ciMedico, int ciPaciente,Fecha* fechaConsulta);
    public:
        static CConsulta* getInstanceConsulta();
        void ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio);
        void ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente,Fecha* fechaConsulta,string* motivo);
        bool consultaExistente(string* ciMedico,string* ciPaciente,Fecha* fechaConsulta);
        void darAltaDiagnostico(string* ciMedico,string* ciPaciente,Fecha* fechaConsulta, Diagnostico* diagnostico);
        map<string,Consulta*> obtenerConsultasDelDia(string* ciMedico,Fecha* fechaConsulta);
        //virtual void agregarDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico);
};

#endif
