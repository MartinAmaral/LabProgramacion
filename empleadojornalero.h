#ifndef EMPLEADOJORNALERO_H
#define EMPLEADOJORNALERO_H
#include "empleado.h"

class EmpleadoJornalero : public Empleado {
    private:
        int horas;

    public:
        EmpleadoJornalero(string nombre, string id, int edad, Paga* valorHora, Empresa* emp)
        : Empleado(nombre, id, edad, valorHora, emp) {}
        int getHoras();
        void setHoras(int horas);
        float getSueldoPesos();
        float getSueldoDolar();
};

#endif