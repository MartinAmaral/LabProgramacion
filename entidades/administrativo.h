#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "usuario.h"
#include <list>

using namespace std;
class Administrativo: public Usuario{
    private:
        list<Usuario*> usuariosDadosAlta;
    public:
        Administrativo(string nombre,string apellido,Sexo sexo,int CI,Fecha* FechaNacimiento,TipoUsuario tipo);
        void agregarUsuarioDadoAlta(Usuario* usuario);
        ~Administrativo();
};
#endif
