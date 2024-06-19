#include "administrativo.h"

// Constructor de Administrativo
Administrativo::Administrativo(bool activo, int CI, Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento) {
    this->setActivo(activo);
    this->setContrasena(contrasena);
}

// Funciones heredadas de Usuario
int Administrativo::getCI() {
    return Usuario::getCI();
}

bool Administrativo::comprobarPass(string pass) {
    return Usuario::comprobarPass(pass);
}

string Administrativo::getContrasena() {
    return Usuario::getContrasena();
}

int Administrativo::getEdad() {
    return Usuario::getEdad();

}
/*
void Administrativo::setContrasena(string contra){
    this->contrasena = contra; 
}*/

