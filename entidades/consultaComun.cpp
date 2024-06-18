#include "consultaComun.h"
#include "usuario.h"

ConsultaComun::ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva)
    : Consulta(fechaConsulta, "", paciente, medico), fechaReserva(fechaReserva), asistio(false) {}

ConsultaComun::~ConsultaComun(){
    delete fechaReserva;
}
