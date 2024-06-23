

#include "socio.h"
#include "usuario.h"

Socio::Socio(string nombre, string apellido, Sexo sexo, int CI, Fecha* fechaNacimiento, TipoUsuario tipo)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento, tipo) {
    this->setActivo(false);
    this->setContrasena("");
}
bool Usuario::comprobarPass(string pass){
    return pass == this->contrasena;
}
