#include "consultaEmergencia.h"
#include "consulta.h"
#include "fecha.h"
#include "usuario.h"


ConsultaEmergencia::ConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo)
    : Consulta(medico, paciente, fechaConsulta), motivo(motivo) {}

string ConsultaEmergencia::getMotivo() const {
    return motivo;
}

ConsultaEmergencia::~ConsultaEmergencia() {

}