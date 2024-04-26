#include "empleadojornalero.h"
#include "cambio.h"

void EmpleadoJornalero::setHoras(int horas){
    this->horas = horas;
}
int EmpleadoJornalero::getHoras(){
    return this->horas;
}

float EmpleadoJornalero::getSueldoPesos() {
    float result = getValorHora()->a_peso()->getMonto() * horas; 
    return result; 
}

float EmpleadoJornalero::getSueldoDolar() {
    float result = getValorHora()->a_dolar()->getMonto() * horas;
    return result; 
}

