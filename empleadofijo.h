#ifndef EMPLEADOFIJO_H
#define EMPLEADOFIJO_H
#include "empleado.h"

class EmpleadoFijo : public Empleado {
public:
    EmpleadoFijo(string nombre, string id, int edad, Paga* valorHora, Empresa* emp)
    : Empleado(nombre, id, edad, valorHora, emp) {}
    float getSueldoPesos();
    float getSueldoDolar();
};

#endif