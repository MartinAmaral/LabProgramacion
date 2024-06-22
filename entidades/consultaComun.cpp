#include "consultaComun.h"

ConsultaComun::ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio)
    : Consulta(paciente, medico, fechaConsulta), fechaReserva(fechaReserva), asistio(asistio) {}

bool ConsultaComun::getAsistio() {
    return this->asistio;
}

Fecha* ConsultaComun::getFechaReserva() {
    return this->fechaReserva;
}

void ConsultaComun::setAsistio(bool asistio) {
    this->asistio = asistio;
}

void ConsultaComun::setFechaReserva(Fecha* fecha) {
    if (this->fechaReserva != nullptr) {
        delete this->fechaReserva;
    }
    this->fechaReserva = fecha;
}

ConsultaComun::~ConsultaComun() {
    if (fechaReserva != nullptr) {
        delete fechaReserva;
    }
}
