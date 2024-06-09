#ifndef SOCIO_H
#define SOCIO_H
#include "usuario.h"

class Socio: public Usuario{
    public:
    Socio(
        bool activo = true, int CI,Sexo sexo, Fecha* fechaNacimiento = NULL, string nombre, string apellido, string contrasena);
    };
    int getCI();
    bool comprobarPass(string pass);
    string getContrasena();
    int getEdad();

#endif
