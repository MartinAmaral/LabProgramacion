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
        virtual int getCI();
        virtual bool comprobarPass(string pass);
        virtual string getContrasena();
        virtual int getEdad();
        ~Usuario();
};

#endif
