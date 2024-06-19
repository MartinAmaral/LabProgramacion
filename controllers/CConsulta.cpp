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
    return ciMedico + ciPaciente + to_string(fechaConsulta.dia) + to_string(fechaConsulta.mes) + to_string(fechaConsulta.ano);
}

void CConsulta::ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, Fecha* fechaReserva, bool asistio) {
    string clave = generarClave(medico->getCI(), paciente->getCI(), fechaConsulta);
    if (consultas.find(clave) == consultas.end()) {
        shared_ptr<Consulta> consulta = make_shared<ConsultaComun>(paciente, medico, new Fecha(fechaConsulta), new Fecha(*fechaReserva));
        dynamic_cast<ConsultaComun*>(consulta.get())->setAsistio(asistio);
        consultas[clave] = consulta;
    } else {
        throw runtime_error("Ya existe una consulta o reserva para ese medico y paciente en esa fecha.");
    }
}

void CConsulta::ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo) {
    string clave = generarClave(medico->getCI(), paciente->getCI(), fechaConsulta);
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

void CConsulta::darAltaDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico) {
    string clave = generarClave(ciMedico, ciPaciente, fechaConsulta);
    if (consultas.find(clave) != consultas.end()) {
        consultas[clave]->agregarDiagnostico(diagnostico);
    } else {
        throw runtime_error("Consulta no encontrada para esa fecha.");
    }
}

map<string, shared_ptr<Consulta>> CConsulta::obtenerConsultasDelDia(const string& ciMedico, const Fecha& fechaConsulta) {
    map<string, shared_ptr<Consulta>> consultasDelDia;
    for (const auto& entry : consultas) {
        if (entry.second->getMedico()->getCI() == ciMedico && entry.second->getFechaConsulta()->dia == fechaConsulta.dia && 
            entry.second->getFechaConsulta()->mes == fechaConsulta.mes && entry.second->getFechaConsulta()->ano == fechaConsulta.ano) {
            consultasDelDia[entry.second->getPaciente()->getCI()] = entry.second;
        }
    }
   return consultasDelDia;
}
