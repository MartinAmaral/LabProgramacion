#include "consultaEmergencia.h"


ConsultaEmergencia::ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fecha , string motivo){
    this->paciente = paciente;
    this->medico = medico;
    this->fechaConsulta = fecha;
    this->motivo = motivo;
}
