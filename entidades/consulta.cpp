#include "consulta.h"
#include "fecha.h"
#include "usuario.h"

using namespace std;

void Consulta::setHora(string hora){
    this->hora = hora;
}

void Consulta::setMedico(Usuario* medico){
    this->medico = medico;
}

void Consulta::setPaciente(Usuario* paciente){
    this->paciente = paciente;
}

void Consulta::setFechaConsulta(Fecha* fecha){
    delete this->fechaConsulta;
    this->fechaConsulta =fecha;
}

string Consulta::getHora(){
    return this->hora;
}

Usuario* Consulta::getMedico(){
    return this->medico;
}

Usuario* Consulta::getPaciente(){
    return this->paciente;
}

Fecha* Consulta::getFechaConsulta(){
    return this->fechaConsulta;
}


Consulta::~Consulta() {
    delete fechaConsulta;
}

void agregarDiagnostico(Diagnostico* diagnostico){
    this->diagnosticos.push_back(diagnostico)
}


