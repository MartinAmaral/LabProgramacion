#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "usuario.h"

class Administrativo: public Usuario{
    public:
    Administrativo(bool activo , int CI,Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena);
    int getCI();
    bool comprobarPass(string pass);
    string getContrasena();
    int getEdad();
};
#endif
