#include "medico.h"
#include <iostream>

#include "medico.h"

// Constructor de Medico que inicializa los atributos de Usuario
Medico::Medico(bool activo, int CI, Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento) {
    this->setActivo(activo);
    this->setContrasena(contrasena);
}

// Implementación de métodos específicos de Medico que pueden diferir de Usuario
int Medico::getCI() {
    return Usuario::getCI(); 
}

bool Medico::comprobarPass(string pass) {
    return Usuario::comprobarPass(pass); 
}

string Medico::getContrasena() {
    return Usuario::getContrasena(); 
}

int Medico::getEdad() {
    return Usuario::getEdad(); 
}

