#include "consultaEmergencia.h"
#include "consulta.h"
#include "fecha.h"
#include "usuario.h"


ConsultaEmergencia::ConsultaEmergencia(Usuario* medico, Usuario* paciente, const Fecha& fechaConsulta, string motivo)
    : Consulta(&fechaConsulta, "", paciente, medico), motivo(motivo) {}

string ConsultaEmergencia::getMotivo(){
    return motivo;
}

ConsultaEmergencia::~ConsultaEmergencia() {

}
