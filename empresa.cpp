#include <string>
#include "empresa.h"
using namespace std;


Empresa::Empresa(string nombre, string nombre_legal,int rut, Empleado* emp ){
this->nombre = nombre;
this->nombre_legal = nombre_legal;
this->rut = rut;
this->empleados[0] = emp;

}

float Empresa::total_sueldo_peso(){
float total = 0;
for ( int i = 0; i < 50; i++)
{
    total += empleados[i]->getSueldoPesos();
}
return total;
}

float Empresa::total_sueldo_dolar(){
float total = 0;
for ( int i = 0; i < 50; i++)
{
    total += empleados[i]->getSueldoDolar();
}
return total;

}

    string Empresa::getNombre() {
        return nombre;
    }

    void Empresa::setNombre(string nombre) {
        this->nombre = nombre;
    }

    string Empresa::getNombreLegal() {
        return nombre_legal;
    }

    void Empresa::setNombreLegal(string nombre_legal) {
        this->nombre_legal = nombre_legal;
    }

    int Empresa::getRut()  {
        return rut;
    }

    void Empresa::setRut(int rut) {
        this->rut = rut;
    }

    Empleado* Empresa::getEmpleado()  {
        return empleados[0]; // Retorna el primer empleado del array
    }

    void Empresa::setEmpleado(Empleado* emp) {
        empleados[0] = emp; // Establece el primer empleado del array
    }

    Empresa::~Empresa(){
        delete(this); // hay que borrar los empleados
    }