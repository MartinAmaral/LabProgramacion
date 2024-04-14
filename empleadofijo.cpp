#include "empleadofijo.h"
#include "cambio.h"
#define HORAS_SEM 40;


    float EmpleadoFijo::getSueldoPesos() {
        return getValorHora()->a_peso()->getMonto() * HORAS_SEM; 
    }

       float EmpleadoFijo::getSueldoDolar() {
        return getValorHora()->a_dolar()->getMonto() * HORAS_SEM; 
    }


