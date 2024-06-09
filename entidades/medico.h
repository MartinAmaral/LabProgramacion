#ifndef MEDICO_H
#define MEDICO_H
#include "usuario.h"

class Medico: public Usuario{
    public:
    Medico(bool activo, int CI,Sexo sexo, Fecha* fechaNacimiento, string nombre, string apellido, string contrasena);
    int getCI();
    bool comprobarPass(string pass);
    string getContrasena();
    int getEdad();
};
#endif