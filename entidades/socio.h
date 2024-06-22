#ifndef SOCIO_H
#define SOCIO_H
#include "usuario.h"

class Socio: public Usuario{
    public:
        Socio(string nombre,string apellido,Sexo sexo,int CI,Fecha* FechaNacimiento,TipoUsuario tipo);

        virtual ~Socio();
};
#endif
