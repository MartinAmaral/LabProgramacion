#include <string>
#include "../entidades/usuario.h"
#include "../entidades/medico.h"
#include "CConsulta.h"
#include <stdexcept>
#include <memory>
#include <map>
using namespace std;

CConsulta* CConsulta::instance = nullptr;

CConsulta* CConsulta::getInstanceConsulta() {
    if (instance == nullptr) {
        instance = new CConsulta();
    }
    return instance;
}

string CConsulta::generarClave(int ciMedico, int ciPaciente, const Fecha& fechaConsulta) const {
    return to_string(ciMedico) + to_string(ciPaciente) + to_string(fechaConsulta.dia) + to_string(fechaConsulta.mes) + to_string(fechaConsulta.ano);
}

void CConsulta::ingresarDatosConsultaComun(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, Fecha* fechaReserva, bool asistio) {
    int ciMedico = medico->getCI();
    int ciPaciente = paciente->getCI();

    string clave = generarClave(ciMedico, ciPaciente, fechaConsulta);
    if (consultas.find(clave) == consultas.end()) {
        shared_ptr<Consulta> consulta = make_shared<ConsultaComun>(paciente, medico, new Fecha(fechaConsulta), new Fecha(*fechaReserva), asistio);
        dynamic_cast<ConsultaComun*>(consulta.get())->setAsistio(asistio);
        consultas[clave] = consulta;
    } else {
        throw runtime_error("Ya existe una consulta o reserva para ese medico y paciente en esa fecha.");
    }
}


void CConsulta::ingresarDatosConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, const std::string& motivo) {
    string clave = generarClave(medico->getCI(), paciente->getCI(), fechaConsulta);
    if (consultas.find(clave) == consultas.end()) {
        shared_ptr<Consulta> consulta = make_shared<ConsultaEmergencia>(medico, paciente, fechaConsulta, motivo);
        consultas[clave] = consulta;
    } else {
        throw runtime_error("Ya existe una consulta o reserva para ese medico y paciente en esa fecha.");
    }
}

bool CConsulta::consultaExistente(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta) const {
    int intCiMedico = stoi(ciMedico);
    int intCiPaciente = stoi(ciPaciente); // Convertir string a int

    string clave = generarClave(intCiMedico, intCiPaciente, fechaConsulta);
    return consultas.find(clave) != consultas.end();
}

void CConsulta::darAltaDiagnostico(const string& ciMedico, const string& ciPaciente, const Fecha& fechaConsulta, Diagnostico* diagnostico) {
    int intCiMedico = stoi(ciMedico); // Convertir string a int
    int intCiPaciente = stoi(ciPaciente);
    string clave = generarClave(intCiMedico, intCiPaciente, fechaConsulta);

    auto it = consultas.find(clave);
    if (it != consultas.end()) {
        // Obtener el shared_ptr apuntando a la consulta
        shared_ptr<Consulta> consulta = it->second;

        // Intentar hacer un dynamic_pointer_cast a ConsultaComun o ConsultaEmergencia si es necesario
        shared_ptr<ConsultaComun> consultaComun = dynamic_pointer_cast<ConsultaComun>(consulta);
        shared_ptr<ConsultaEmergencia> consultaEmergencia = dynamic_pointer_cast<ConsultaEmergencia>(consulta);

        // Verificar qué tipo de consulta es
        if (consultaComun) {
            consultaComun->agregarDiagnostico(diagnostico);
        } else if (consultaEmergencia) {
            consultaEmergencia->agregarDiagnostico(diagnostico);
        } else {
            throw runtime_error("Tipo de consulta no soportado para agregar diagnóstico.");
        }
    } else {
        throw runtime_error("Consulta no encontrada para esa fecha.");
    }
}

map<string, shared_ptr<Consulta>> CConsulta::obtenerConsultasDelDia(const string& ciMedico, const Fecha& fechaConsulta) {
    map<string, shared_ptr<Consulta>> consultasDelDia;
    for (const auto& entry : consultas) {
        if (std::to_string(entry.second->getMedico()->getCI()) == ciMedico &&
            entry.second->getFechaConsulta()->dia == fechaConsulta.dia &&
            entry.second->getFechaConsulta()->mes == fechaConsulta.mes &&
            entry.second->getFechaConsulta()->ano == fechaConsulta.ano) {
            std::string pacienteCI = std::to_string(entry.second->getPaciente()->getCI());
            consultasDelDia[pacienteCI] = entry.second;
        }
    }
   return consultasDelDia;
}
