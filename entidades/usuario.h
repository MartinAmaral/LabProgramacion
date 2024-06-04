#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <iostream>
#include "sexo.h"
#include "fecha.h"

using namespace std;

class Usuario{

    private:
        bool activo = true;
        int CI;
        Sexo sexo;
        Fecha* fechaNacimiento = NULL;
        string nombre;
        string apellido;
        string contrasena;
    public:
        Usuario(int ci,string contrasena);
        int getCI();
        bool comprobarPass(string pass);
        string getContrasena();
        int getEdad();
        ~Usuario();
};

#endif
