#include "socio.h"
#include <iostream>

#include "socio.h"

// Constructor de la clase Socio
Socio::Socio(bool activo, int CI, Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento) {
    this->setActivo(activo);
    this->setContrasena(contrasena);
}

// Implementación de los métodos heredados

int Socio::getCI() {
    return Usuario::getCI();
}

bool Socio::comprobarPass(string pass) {
    return Usuario::comprobarPass(pass);
}

string Socio::getContrasena() {
    return Usuario::getContrasena();
}

int Socio::getEdad() {
    return Usuario::getEdad();
}

