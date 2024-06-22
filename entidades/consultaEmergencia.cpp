#include "consultaEmergencia.h"
#include "fecha.h"
#include "usuario.h"

ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, const Fecha& fechaConsulta, const std::string& motivo) {
    this->setPaciente(paciente);
    this->setMedico(medico);
    this->setFechaConsulta(new Fecha(fechaConsulta));
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
