#include "administrativo.h"

Administrativo::Administrativo(string nombre,string apellido,Sexo sexo,int CI,Fecha* fechaNacimiento,TipoUsuario tipo)
    : Usuario(nombre, apellido, sexo, CI, fechaNacimiento,tipo) {
    this->setActivo(false);
    this->setContrasena("");
}

void Administrativo::agregarUsuarioDadoAlta(Usuario* usuario){
    usuariosDadosAlta.push_front(usuario);
}
