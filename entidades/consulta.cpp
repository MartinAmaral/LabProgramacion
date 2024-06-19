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
    delete paciente;
    delete medico;
    delete &fechaConsulta;
}


