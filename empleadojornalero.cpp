#include "empleadojornalero.h"
#include "cambio.h"

    float EmpleadoJornalero::getSueldoPesos() {
        return getValorHora()->a_peso()->getMonto() * horas; 
    }

       float EmpleadoJornalero::getSueldoDolar() {
        return getValorHora()->a_dolar()->getMonto() * horas; 
    }

