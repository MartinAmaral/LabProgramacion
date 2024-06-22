#include "medico.h"

Medico::Medico(string nombre,string apellido,Sexo sexo,int CI,Fecha* fechaNacimiento,TipoUsuario tipo)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento,tipo) {
    this->setActivo(false);
    this->setContrasena("");
}


