#include "consultaEmergencia.h"
#include "fecha.h"
#include "usuario.h"
#include "consulta.h"
/*
ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, string motivo) {
    this->setPaciente(paciente);
    this->setMedico(medico);
    this->setFechaConsulta(new Fecha(*fechaConsulta));
    this->motivo = motivo;
}
*/
ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, string motivo)
    : Consulta(paciente, medico, fechaConsulta), motivo(motivo) {}

string ConsultaEmergencia::getMotivo(){
    return motivo;
}

void ConsultaEmergencia::setMotivo(string motivo){
    this->motivo = motivo;
}

ConsultaEmergencia::~ConsultaEmergencia() {
    delete this->fechaConsulta;
}
