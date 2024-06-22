#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <iostream>
#include "sexo.h"
#include "fecha.h"
#include <ctime>
#include "tipoUsuario.h"

using namespace std;

class Usuario{

    protected:
        bool activo = true;
        int CI;
        Sexo sexo;
        Fecha* fechaNacimiento = NULL;
        string nombre;
        string apellido;
        string contrasena;
        TipoUsuario tipoUsuario;
    public:
        Usuario(string nombre,string apellido,Sexo sexo,int CI,Fecha* fechaNacimiento,TipoUsuario tipo);
        bool getActivo();    
        int getCI();
        Sexo getSexo();
        Fecha* getFechaNacimiento();
        string getNombre();
        string getApellido();
        string getContrasena();
        TipoUsuario getTipoUsuario();

        int getEdad();

        void setActivo(bool estado);
        void setCI(int ci);
        void setSexo(Sexo sexo);    
        void setFechaNacimiento(Fecha* fecha);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setContrasena(string contra);
        //Usuario* setTipoUsario(); habria que crear un usuario nuevo con ese tipo si el nuevo tipo es admin y antes no

        virtual bool comprobarPass(string pass);
        virtual ~Usuario()=0;
};

#endif
