#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "usuario.h"

//de redes
class Administrativo: public Usuario{
    public:
        Administrativo(string nombre,string apellido,Sexo sexo,int CI,Fecha* FechaNacimiento,TipoUsuario tipo);
        ~Administrativo();
};
#endif
