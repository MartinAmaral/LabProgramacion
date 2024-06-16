#include "consulta.h"
#include "../entidades/consultaComun.h"
#include "../entidades/consultaEmergencia.h"
#include "fecha.h"
#include "usuario.h"
#include <iostream>
#include <string>
using namespace std;

// Implementación de la clase Consulta
Consulta::Consulta(Fecha* fecha, string hora, Usuario* paciente, Usuario* medico)
    : fechaConsulta(fecha), hora(hora), paciente(paciente), medico(medico) {}

Consulta::~Consulta() {
    // Aquí puedes agregar cualquier limpieza necesaria, si aplica
    delete fechaConsulta;
}

ConsultaComun::ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva)
    : Consulta(fechaConsulta, "", paciente, medico), fechaReserva(fechaReserva), asistio(false) {}


ConsultaComun::~ConsultaComun() {
    // Aquí puedes agregar cualquier limpieza necesaria, si aplica
    delete fechaReserva;
}

ConsultaEmergencia::ConsultaEmergencia(Fecha* fecha, std::string hora, Usuario* paciente, Usuario* medico, std::string motivo)
    : Consulta(fecha, hora, paciente, medico), motivo(motivo) {}

ConsultaEmergencia::~ConsultaEmergencia() {
    // Aquí puedes agregar cualquier limpieza necesaria, si aplica
}
