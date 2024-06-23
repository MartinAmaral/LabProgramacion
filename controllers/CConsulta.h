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

<<<<<<< HEAD
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
=======
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
>>>>>>> 98bbad7da7441adc19381db244181b195e395456
};

#endif
