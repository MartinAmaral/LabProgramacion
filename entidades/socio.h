#ifndef SOCIO_H
#define SOCIO_H
#include "usuario.h"

class Socio: public Usuario{
    public:
    Socio(int CI,Sexo sexo, string nombre, string apellido, string contrasena,bool activo=true, Fecha* fechaNacimiento = NULL);

    ~Socio();    
};
#endif
