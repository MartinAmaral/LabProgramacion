#include "consultaEmergencia.h"
<<<<<<< HEAD
#include "consulta.h"
#include "fecha.h"
#include "usuario.h"


// Implementación de la clase ConsultaEmergencia
ConsultaEmergencia::ConsultaEmergencia(Fecha* fecha,string hora, Usuario* paciente, Usuario* medico, string motivo)
    : Consulta(fecha, hora, paciente, medico), motivo(motivo) {}

ConsultaEmergencia::~ConsultaEmergencia() {
    // Aquí puedes agregar cualquier limpieza necesaria, si aplica
}
=======


ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fecha , string motivo){
    this->paciente = paciente;
    this->medico = medico;
    this->fechaConsulta = fecha;
    this->motivo = motivo;
}
>>>>>>> a14b9799bc9eb2ddd05788a0759a2c06cda1167e
