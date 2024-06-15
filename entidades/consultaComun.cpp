#include "consultaComun.h"
#include "usuario.h"

ConsultaComun::ConsultaComun(Usuario* paciente,Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva){
    this->paciente = paciente;
    this->medico = medico;
    this->asistio = false;
    this->fechaConsulta = fechaConsulta;
    this->fechaReserva = fechaReserva;

}

