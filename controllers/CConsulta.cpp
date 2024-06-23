#include <string>
#include "../entidades/usuario.h"
#include "../entidades/medico.h"
#include "../entidades/fecha.h"
#include "CConsulta.h"
#include "../fabricas/fabricaCUsuario.h"
using namespace std;

CConsulta* CConsulta::instance = NULL;

CConsulta* CConsulta::getInstanceConsulta() {
    if (instance == NULL) {
        instance = new CConsulta();
    }
    return instance;
}

void CConsulta::altaConsultaComun(int ciMedico,int ciPaciente,Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio){
    Usuario* medico = FabricaCUsuario::getCUsuario()->getUsuario(ciMedico); 
    Usuario* paciente = FabricaCUsuario::getCUsuario()->getUsuario(ciPaciente); 
    ConsultaComun* consulta = new ConsultaComun(medico,paciente,fechaConsulta,fechaReserva,asistio);
    this->consultas.push_front(consulta);
}
        
void CConsulta::altaConsultaEmergencia(int ciMedico, int ciPaciente,Fecha* fechaConsulta,string motivo){
    Usuario* medico = FabricaCUsuario::getCUsuario()->getUsuario(ciMedico); 
    Usuario* paciente = FabricaCUsuario::getCUsuario()->getUsuario(ciPaciente); 
    ConsultaEmergencia* consulta = new ConsultaEmergencia(medico,paciente,fechaConsulta,motivo);
    this->consultas.push_front(consulta);
}
        
bool CConsulta::consultaExistente(int ciMedico,int ciPaciente,Fecha* fechaConsulta,Fecha* fechaReserva){
    for (Consulta* cons : this->consultas) {
        ConsultaComun* consultaCheck = dynamic_cast<ConsultaComun*>(cons);
        if(!consultaCheck) continue;
        
        if(consultaCheck->getMedico()->getCI() == ciMedico && consultaCheck->getPaciente()->getCI() == ciMedico){
            Fecha* fecha = consultaCheck->getFechaConsulta(); 
            if(fecha->getDia() == fechaConsulta->getDia() && fecha->getMes() == fechaConsulta->getMes() 
                && fecha->getAno() == fechaConsulta->getAno()){
                return true;
            }
            fecha = consultaCheck->getFechaConsulta(); 
            if(fecha->getDia() == fechaReserva->getDia() && fecha->getMes() == fechaReserva->getMes() 
                && fecha->getAno() == fechaReserva->getAno()){
                return true;
            }
        }
    }
    return false;
}
/*
void CConsulta::darAltaDiagnostico(string ciMedico, string ciPaciente,  Fecha* fechaConsulta, Diagnostico* diagnostico) {
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
/*
map<string, shared_ptr<Consulta>> CConsulta::obtenerConsultasDelDia(string ciMedico,Fecha* fechaConsulta) {
    map<string, shared_ptr<Consulta>> consultasDelDia;
    for (auto entry : consultas) {
        if (to_string(entry.second->getMedico()->getCI()) == ciMedico &&
            entry.second->getFechaConsulta()->dia == fechaConsulta->dia &&
            entry.second->getFechaConsulta()->mes == fechaConsulta->mes &&
            entry.second->getFechaConsulta()->ano == fechaConsulta->ano) {
            string pacienteCI = to_string(entry.second->getPaciente()->getCI());
            consultasDelDia[pacienteCI] = entry.second;
        }
    }
   return consultasDelDia;
}*/
