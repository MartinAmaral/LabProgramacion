#include "consultaDia.h"

ConsultaDia::ConsultaDia(int ciPaciente,Consulta* consulta){
    this->ciPaciente = ciPaciente;
    this->consulta = consulta;
}
        
int ConsultaDia::getCiPaciente(){
    return ciPaciente;
}
          
Consulta* ConsultaDia::getConsulta(){
    return this->consulta;
}

ConsultaDia::~ConsultaDia(){}
