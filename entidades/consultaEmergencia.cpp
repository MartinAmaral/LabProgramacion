#include "consultaEmergencia.h"
#include "fecha.h"
#include "usuario.h"
#include "consulta.h"

ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, string motivo)
    : Consulta(paciente, medico, fechaConsulta), motivo(motivo) {}

string ConsultaEmergencia::getMotivo(){
    return motivo;
}

void ConsultaEmergencia::setMotivo(string motivo){
    this->motivo = motivo;
}

ConsultaEmergencia::~ConsultaEmergencia() {
    for (auto item = diagnosticos.begin(); item != diagnosticos.end();) {
        delete *item;
        item = diagnosticos.erase(item);
    }
}
