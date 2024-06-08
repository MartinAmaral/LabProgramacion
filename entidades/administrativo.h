#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "usuario.h"

class Administrativo: public Usuario{
    public:
    Administrativo(
        bool activo = true, int CI,Sexo sexo, Fecha* fechaNacimiento = NULL, string nombre, string apellido, string contrasena);
    };
    int getCI();
    bool comprobarPass(string pass);
    string getContrasena();
    int getEdad();

#endif
