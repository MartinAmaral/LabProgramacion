#include "empleadojornalero.h"
#include "cambio.h"

void EmpleadoJornalero::setHoras(int horas){
    this->horas = horas;
}
int EmpleadoJornalero::getHoras(){
    this->horas;
}

float EmpleadoJornalero::getSueldoPesos() {
    return getValorHora()->a_peso()->getMonto() * horas; 
}

float EmpleadoJornalero::getSueldoDolar() {
return getValorHora()->a_dolar()->getMonto() * horas; 
}

