#ifndef MEDICO_H
#define MEDICO_H
#include "usuario.h"

class Medico: public Usuario{
    public:
        Medico(string nombre,string apellido,Sexo sexo,int CI,Fecha* FechaNacimiento,TipoUsuario tipo);
        ~Medico();
};
#endif
