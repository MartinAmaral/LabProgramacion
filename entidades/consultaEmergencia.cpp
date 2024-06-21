#include "consultaEmergencia.h"
#include "fecha.h"
#include "usuario.h"

ConsultaEmergencia::ConsultaEmergencia(Usuario* medico, Usuario* paciente,string hora ,Fecha* fechaConsulta, string motivo){
    this->medico = medico;
    this->paciente = paciente;
    this->hora = hora;
    this->fechaConsulta = fechaConsulta;
    this->motivo = motivo;
}

string ConsultaEmergencia::getMotivo(){
    return motivo;
}

void ConsultaEmergencia::setMotivo(string motivo){
    this->motivo = motivo;
}

ConsultaEmergencia::~ConsultaEmergencia() {
    delete this->fechaConsulta;
}
void ConsultaEmergencia::agregarDiagnostico(Diagnostico* diagnostico) {
    this->diagnosticos.push_back(diagnostico);
}
