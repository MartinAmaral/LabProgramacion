#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "usuario.h"

//de redes
class Administrativo: public Usuario{
    public:
    Administrativo(bool activo , int CI,Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena);
    ~Administrativo();
};
#endif
