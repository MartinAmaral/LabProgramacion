#include "empleadofijo.h"
#include "cambio.h"
#define HORAS_SEM 40;

#include <iostream>
float EmpleadoFijo::getSueldoPesos() {
    float resultado = getValorHora()->a_peso()->getMonto() * HORAS_SEM
    return resultado; 
}

float EmpleadoFijo::getSueldoDolar() {
    float resultado = getValorHora()->a_dolar()->getMonto() * HORAS_SEM
    return resultado; 
}


