#include <string>
#include <iostream>
#include "empresa.h"
using namespace std;

Empresa::Empresa(string nombre, string nombre_legal,int rut, Empleado* emp ){
    this->nombre = nombre;
    this->nombre_legal = nombre_legal;
    this->rut = rut;

    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        empleados[i] = NULL; 
    }
    empleados[0] = emp;
}

float Empresa::total_sueldo_peso(){
    float total = 0;
    for ( int i = 0; i < MAX_EMPLEADO; i++)
    {
        if(empleados[i] == NULL) break;
        total += empleados[i]->getSueldoPesos();
    }
    return total;
}

float Empresa::total_sueldo_dolar(){
    float total = 0;
    for ( int i = 0; i <MAX_EMPLEADO; i++)
    {
        if(empleados[i] == NULL) break;
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

Empleado** Empresa::getEmpleados()  {
    return empleados;
}

Empresa::~Empresa(){
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if(empleados[i] !=NULL){
            delete(empleados[i]);
            empleados[i] = NULL;
        }
        else{
            break;
        }
    }
}