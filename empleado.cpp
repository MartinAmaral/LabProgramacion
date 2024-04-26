#include "empleado.h"

using namespace std;

Empleado::Empleado(string nombre, string id,int edad, Paga* valorHora, Empresa* emp){
    this->nombre = nombre;
    this->id = id;
    this->edad = edad;
    this->valor_hora = valorHora;
    this->empresa = emp;
}

string Empleado::getNombre() {
    return nombre;
}

void Empleado::setNombre(string nombre) {   
    this->nombre = nombre;
}

string Empleado::getCI() {
    return id;
}

void Empleado::setCI(string ci) {
    id = ci;
}

int Empleado::getEdad() {
    return edad;
}

void Empleado::setEdad(int edad) {
    this->edad = edad;
}

Paga* Empleado::getValorHora() {
    return valor_hora;
}

void Empleado::setValorHora(Paga* valorHora) {
    this->valor_hora = valorHora;
}

Empleado::~Empleado() {
    delete(valor_hora);
}