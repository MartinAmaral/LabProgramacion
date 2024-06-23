#ifndef INFOUSUARIODT_H
#define INFOUSUARIODT_H

#include "../entidades/sexo.h"
#include <string>
#include "../entidades/tipoUsuario.h"
#include "fecha.h"

using namespace std;

class InfoUsuarioDT {
    private:
        string nombre;
        string apellido;
        Sexo sexo;
        Fecha* fechaNacimiento;
        TipoUsuario tipo;
    public:
        InfoUsuarioDT(string nombre,string apellido,Sexo sexo,Fecha* fechaN,TipoUsuario tipo);
        string getNombre();
        string getApellido();
        Sexo getSexo();
        Fecha* getFechaNacimiento();
        TipoUsuario getTipo();
        ~InfoUsuarioDT();
};
#endif
