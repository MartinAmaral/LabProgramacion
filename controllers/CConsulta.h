#ifndef CCONSULTA_H
#define CCONSULTA_H

#include <unordered_map>
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

class CConsulta  //: public ICConsulta
{
    private:
    static CConsulta* InstanceConsulta();
    unordered_map<string, shared_ptr<Consulta>> consultas;

    CConsulta() {}
    string generarClave(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const;
    public:
        static CConsulta* getInstanceConsulta();
        //Ingresa los datos de consulta
    void ingresarDatosConsultaComun(string ciMedico, string ciPaciente, const Fecha& fechaConsulta);
    void ingresarDatosConsultaEmergencia(string ciMedico, string ciPaciente, const Fecha& fechaConsulta, string motivo);
    bool consultaExistente(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const;
};
#endif