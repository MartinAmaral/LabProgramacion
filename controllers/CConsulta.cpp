#include <string>
#include "../entidades/usuario.h"
#include "../entidades/medico.h"
#include "CConsulta.h"

using namespace std;

CConsulta* CConsulta::InstanceConsulta = nullptr;

CConsulta* CConsulta::getInstanceConsulta() {
    if (InstanceConsulta == nullptr) {
        InstanceConsulta = new CConsulta();
    }
    return InstanceConsulta;
}

string CConsulta::generarClave(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const {
    return ciMedico + ciPaciente + fechaConsulta.toString();
}

void CConsulta::ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, Fecha* fechaReserva, bool asistio) {
    string clave = generarClave(to_string(medico->getCI()), to_string(paciente->getCI()), fechaConsulta);
    if (consultas.find(clave) == consultas.end()) {
        shared_ptr<Consulta> consulta = make_shared<ConsultaComun>(paciente, medico, new Fecha(fechaConsulta), fechaReserva);
        consultas[clave] = consulta;
    } else {
        throw runtime_error("Ya existe una consulta o reserva para ese medico y paciente en esa fecha.");
    }
}

void CConsulta::ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo) {
    string clave = generarClave(to_string(medico->getCI()), to_string(paciente->getCI()), fechaConsulta);
    if (consultas.find(clave) == consultas.end()) {
        shared_ptr<Consulta> consulta = make_shared<ConsultaEmergencia>(medico, paciente, fechaConsulta, motivo);
        consultas[clave] = consulta;
    } else {
        throw runtime_error("Ya existe una consulta o reserva para ese medico y paciente en esa fecha.");
    }
}

bool CConsulta::consultaExistente(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const {
    string clave = generarClave(ciMedico, ciPaciente, fechaConsulta);
    return consultas.find(clave) != consultas.end();
}
