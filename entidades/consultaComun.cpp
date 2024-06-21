#include "consultaComun.h"
#include "fecha.h"
#include "usuario.h"

ConsultaComun::ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva,bool asistio){
    this->paciente = paciente;
    this->medico = medico;
    this->fechaConsulta = fechaConsulta;
    this->fechaReserva = fechaReserva;
    this->asistio = asistio;
}

bool ConsultaComun::getAsistio(){
    return this->asistio;
}

Fecha* ConsultaComun::getFechaReserva(){
    return this->fechaReserva;
}

void ConsultaComun::setAsistio(bool asistio){
    this->asistio = asistio;
}

void ConsultaComun::setFechaReserva(Fecha* fecha){
    delete this->fechaReserva;
    this->fechaReserva = fecha;
}

ConsultaComun::~ConsultaComun(){
    delete fechaReserva;
}
