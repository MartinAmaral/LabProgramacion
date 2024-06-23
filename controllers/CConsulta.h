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
#include <memory>

using namespace std;

class CConsulta
{
private:
    static CConsulta* instance;

    map<string, shared_ptr<Consulta>> consultas;

    

public:
    static CConsulta* getInstanceConsulta();
    string generarClave(int ciMedico, int ciPaciente, Fecha *fechaConsulta);
    void ingresarDatosConsultaComun(Usuario *medico, Usuario *paciente, Fecha* fechaConsulta, Fecha *fechaReserva, bool asistio);
    void ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente,Fecha* fechaConsulta,string motivo);
    bool consultaExistente( string ciMedico,  string ciPaciente,  Fecha* fechaConsulta) ;
    void darAltaDiagnostico( string ciMedico,  string ciPaciente,  Fecha* fechaConsulta, Diagnostico* diagnostico);
    map<string, shared_ptr<Consulta>> obtenerConsultasDelDia( string ciMedico,  Fecha* fechaConsulta);
    //virtual void agregarDiagnostico( string& ciMedico,  string& ciPaciente,  Fecha& fechaConsulta, Diagnostico* diagnostico);
};

#endif
