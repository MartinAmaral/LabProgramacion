#include "consultaEmergencia.h"

#include "consulta.h"
#include "fecha.h"
#include "usuario.h"


// Implementación de la clase ConsultaEmergencia


ConsultaEmergencia::~ConsultaEmergencia() {

}

ConsultaEmergencia::ConsultaEmergencia(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico, string motivo)
    : Consulta(fecha, hora, paciente, medico), motivo(motivo) {}

