#include "infoUsuarioDT.h"

InfoUsuarioDT::InfoUsuarioDT(string nombre,string apellido,Sexo sexo,Fecha* fechaN,TipoUsuario tipo){
    this->nombre = nombre;
    this->apellido = apellido;
    this->sexo = sexo;
    this->fechaNacimiento = fechaN;
    this->tipo = tipo;
}

string InfoUsuarioDT::getNombre(){
    return nombre;
}
        
string InfoUsuarioDT::getApellido(){
    return apellido;
}
        
Sexo InfoUsuarioDT::getSexo(){
    return sexo;
}
    
Fecha* InfoUsuarioDT::getFechaNacimiento(){
    return fechaNacimiento;
}

TipoUsuario InfoUsuarioDT::getTipo(){
    return tipo;
}

InfoUsuarioDT::~InfoUsuarioDT(){
    if(this->fechaNacimiento != NULL)
        delete fechaNacimiento;
}
